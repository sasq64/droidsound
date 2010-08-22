/* UADE2 plugin for XMMS
 *
 * Copyright (C) 2005  Heikki Orsila
 *                     heikki.orsila@iki.fi
 *                     http://zakalwe.virtuaalipalvelin.net/uade/
 *
 * This source code module is dual licensed under GPL and Public Domain.
 * Hence you may use _this_ module (not another code module) in any way you
 * want in your projects.
 */

#include <libgen.h>
#include <assert.h>
#include <stdint.h>

#include <netinet/in.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include <uadeipc.h>
#include <eagleplayer.h>
#include <uadeconfig.h>
#include <uadecontrol.h>
#include <uadeconstants.h>
#include <strlrep.h>
#include <uadeconf.h>
#include <effects.h>


#include "plugin.h"
#include "subsongseek.h"


#define PLUGIN_DEBUG 1

#if PLUGIN_DEBUG
#define plugindebug(fmt, args...) do { fprintf(stderr, "%s:%d: %s: " fmt, __FILE__, __LINE__, __func__, ## args); } while(0)
#else
#define plugindebug(fmt, args...) 
#endif


static int initialize_song(char *filename);
static int test_silence(void *buf, size_t size);
static void uade_cleanup(void);
static void uade_get_song_info(char *filename, char **title, int *length);
static int uade_get_time(void);
static void uade_init(void);
static int uade_is_our_file(char *filename);
static void uade_pause(short paused);
static void uade_play_file(char *filename);
static void uade_seek(int time);
static void uade_stop(void);


/* GLOBAL VARIABLE DECLARATIONS */

static InputPlugin uade_ip = {
  .description = "UADE2 " UADE_VERSION,
  .init = uade_init,
  .is_our_file = uade_is_our_file,
  .play_file = uade_play_file,
  .stop = uade_stop,
  .pause = uade_pause,
  .seek = uade_seek,
  .get_time = uade_get_time,
  .cleanup = uade_cleanup,
  .get_song_info = uade_get_song_info
};

static const AFormat sample_format = FMT_S16_NE;

/* Definition of trigger type:
   abort_playing variable does not need locking, because it is initialized to
   false synchronously in play_file, and it is triggered to be true in stop().
   Other places in the plugin only read the value. We call this type of
   variable a trigger type.

   The locking strategy in the plugin is that all lockable variables are
   initialized in play_file() for each song. Using variables after that
   requires locking.  When locking is needed, call uade_lock() and
   uade_unlock(). */

static int abort_playing;     /* Trigger type */

static char configname[PATH_MAX];
static char curmd5[33];
static int curplaytime;
static pthread_t decode_thread;
static struct uade_config config;
static struct uade_effect effects;
static char gui_filename[PATH_MAX];
static int gui_info_set;
static int last_beat_played;  /* Lock before use */
static char md5name[PATH_MAX];
static int plugin_disabled;
static int total_bytes_valid; /* Lock before use */
static int total_bytes;       /* Lock before use */
static pid_t uadepid;
static struct uade_ipc uadeipc;

static time_t config_load_time;
static time_t md5_load_time;

int uade_cur_sub;             /* Lock before use */
int uade_is_paused;           /* Lock before use */
int uade_max_sub;             /* Lock before use */
int uade_min_sub;             /* Lock before use */
int uade_thread_running;      /* Trigger type */
int uade_seek_forward;        /* Lock before use */
int uade_select_sub;          /* Lock before use */


static pthread_mutex_t vlock = PTHREAD_MUTEX_INITIALIZER;


static void set_defaults(void)
{
  uade_config_set_defaults(&config);
  uade_effect_set_defaults(&effects);
}


static void load_config(void)
{
  struct stat st;

  if (stat(configname, &st))
    return;

  /* Read only newer files */
  if (st.st_mtime <= config_load_time)
    return;

  config_load_time = st.st_mtime;

  set_defaults();

  uade_load_config(&config, configname);

  if (config.gain_enable) {
    uade_effect_gain_set_amount(&effects, config.gain);
    uade_effect_enable(&effects, UADE_EFFECT_GAIN);
  }

  if (config.headphones)
    uade_effect_enable(&effects, UADE_EFFECT_HEADPHONES);

  if (config.panning_enable) {
    uade_effect_pan_set_amount(&effects, config.panning);
    uade_effect_enable(&effects, UADE_EFFECT_PAN);
  }
}


static void load_content_db(void)
{
  struct stat st;
  time_t curtime = time(NULL);
  char name[PATH_MAX];

  if (curtime)
    md5_load_time = curtime;

  if (md5name[0] == 0) {
    char *home = getenv("HOME");
    if (home)
      snprintf(md5name, sizeof md5name, "%s/.uade2/contentdb", home);
  }

  if (md5name[0]) {
    /* Try home directory first */
    if (stat(md5name, &st) == 0) {
      if (uade_read_content_db(md5name))
	return;
    } else {
      FILE *f = fopen(md5name, "w");
      if (f)
	fclose(f);
      uade_read_content_db(md5name);
    }
  }

  snprintf(name, sizeof name, "%s/contentdb.conf", UADE_CONFIG_BASE_DIR);
  if (stat(name, &st) == 0)
    uade_read_content_db(name);
}


void uade_lock(void)
{
  if (pthread_mutex_lock(&vlock)) {
    fprintf(stderr, "UADE2 locking error.\n");
    exit(-1);
  }
}


void uade_unlock(void)
{
  if (pthread_mutex_unlock(&vlock)) {
    fprintf(stderr, "UADE2 unlocking error.\n");
    exit(-1);
  }
}


/* this function is first called by xmms. returns pointer to plugin table */
InputPlugin *get_iplugin_info(void)
{
  return &uade_ip;
}


/* xmms initializes uade by calling this function */
static void uade_init(void)
{
  char *home = getenv("HOME");
  struct stat st;

  set_defaults();

  if (home) {
    char name[PATH_MAX];
    snprintf(name, sizeof name, "%s/.uade2", home);
    if (stat(name, &st) != 0)
      mkdir(name, S_IRUSR | S_IWUSR | S_IXUSR);
  }

  load_content_db();

  /* If config exists in home, ignore global uade.conf. */
  snprintf(configname, sizeof configname, "%s/.uade2/uade.conf", home);
  if (stat(configname, &st) == 0)
    return;

  /* No uade.conf in $HOME/.uade2/. */
  snprintf(configname, sizeof configname, "%s/uade.conf", UADE_CONFIG_BASE_DIR);
  if (stat(configname, &st) == 0)
    return;

  fprintf(stderr, "No config file found for UADE XMMS plugin. Will try to load config from\n");
  fprintf(stderr, "HOME/.uade2/uade.conf in the future.\n");
  snprintf(configname, sizeof configname, "%s/.uade2/uade.conf", home);
}


static void uade_cleanup(void)
{
  if (uadepid)
    kill(uadepid, SIGTERM);

  if (md5name[0]) {
    struct stat st;
    if (stat(md5name, &st) == 0 && md5_load_time >= st.st_mtime)
      uade_save_content_db(md5name);
  }
}


/* XMMS calls this function to check if filename belongs to this plugin. */
static int uade_is_our_file(char *filename)
{
  if (strncmp(filename, "uade://", 7) == 0)
    return TRUE;
  return uade_analyze_file_format(filename, UADE_CONFIG_BASE_DIR, 1) != NULL ? TRUE : FALSE;
}


/* Analyze file format, and handshake with uadecore. */
static int initialize_song(char *filename)
{
  struct eagleplayer *ep;
  int ret;
  char modulename[PATH_MAX];
  char playername[PATH_MAX];
  char scorename[PATH_MAX];

  ep = uade_analyze_file_format(filename, UADE_CONFIG_BASE_DIR, 0);
  if (ep == NULL)
    return FALSE;

  strlcpy(modulename, filename, sizeof modulename);

  snprintf(scorename, sizeof scorename, "%s/score", UADE_CONFIG_BASE_DIR);

  if (strcmp(ep->playername, "custom") == 0) {
    strlcpy(playername, modulename, sizeof playername);
    modulename[0] = 0;
  } else {
    snprintf(playername, sizeof playername, "%s/players/%s", UADE_CONFIG_BASE_DIR, ep->playername);
  }

  ret = uade_song_initialization(scorename, playername, modulename, &uadeipc);
  if (ret) {
    if (ret != UADECORE_CANT_PLAY && ret != UADECORE_INIT_ERROR) {
      fprintf(stderr, "Can not initialize song. Unknown error.\n");
      plugin_disabled = 1;
    }
    return FALSE;
  }

  if (config.ignore_player_check) {
    if (uade_send_short_message(UADE_COMMAND_IGNORE_CHECK, &uadeipc) < 0) {
      fprintf(stderr, "Can not send ignore check message.\n");
      plugin_disabled = 1;
      return FALSE;
    }
  }

  if (config.no_song_end) {
    if (uade_send_short_message(UADE_COMMAND_SONG_END_NOT_POSSIBLE, &uadeipc) < 0) {
      fprintf(stderr, "Can not send 'song end not possible'.\n");
      plugin_disabled = 1;
      return FALSE;
    }
  }

  uade_send_filter_command(config.filter_type, config.led_state, config.led_forced, &uadeipc);
  uade_send_interpolation_command(config.interpolator, &uadeipc);

  if (config.speed_hack) {
    if (uade_send_short_message(UADE_COMMAND_SPEED_HACK, &uadeipc)) {
      fprintf(stderr, "Can not send speed hack command.\n");
      plugin_disabled = 1;
      return FALSE;
    }
  }

  return TRUE;
}

static void *play_loop(void *arg)
{
  enum uade_control_state state = UADE_S_STATE;
  int ret;
  int left = 0;
  uint8_t space[UADE_MAX_MESSAGE_SIZE];
  struct uade_msg *um = (struct uade_msg *) space;
  int subsong_end = 0;
  uint16_t *sm;
  int i;
  unsigned int play_bytes, tailbytes = 0;
  uint64_t subsong_bytes = 0;
  char *reason;
  uint32_t *u32ptr;
  int writable;
  int framesize = UADE_CHANNELS * UADE_BYTES_PER_SAMPLE;
  int song_end_trigger = 0;
  int64_t skip_bytes = 0;

  while (1) {
    if (state == UADE_S_STATE) {

      assert(left == 0);

      if (abort_playing) {
	uade_lock();
	total_bytes_valid = 0;
	uade_unlock();
	break;
      }

      uade_lock();
      if (uade_seek_forward) {
	skip_bytes += uade_seek_forward * UADE_BYTES_PER_SECOND;
	uade_ip.output->flush(uade_ip.output->written_time() + uade_seek_forward * 1000);
	uade_seek_forward = 0;
      }
      if (uade_select_sub != -1) {
	uade_cur_sub = uade_select_sub;
	uade_change_subsong(uade_cur_sub, &uadeipc);
	uade_ip.output->flush(0);
	uade_select_sub = -1;
	subsong_end = 0;
	subsong_bytes = 0;
	total_bytes = 0;
	total_bytes_valid = 0;
      }
      if (subsong_end && song_end_trigger == 0) {
	if (uade_cur_sub == -1 || uade_max_sub == -1) {
	  song_end_trigger = 1;
	} else {
	  uade_cur_sub++;
	  if (uade_cur_sub > uade_max_sub) {
	    song_end_trigger = 1;
	  } else {
	    uade_change_subsong(uade_cur_sub, &uadeipc);
	    uade_ip.output->flush(0);
	    subsong_end = 0;
	    subsong_bytes = 0;
	    uade_gui_subsong_changed(uade_cur_sub);
	  }
	}
      }
      uade_unlock();

      if (song_end_trigger) {
	/* We must drain the audio fast if abort_playing happens (e.g.
	   the user changes song when we are here waiting the sound device) */
	while (uade_ip.output->buffer_playing() && abort_playing == 0)

	  xmms_usleep(10000);
	break;
      }

      left = uade_read_request(&uadeipc);
      
      if (uade_send_short_message(UADE_COMMAND_TOKEN, &uadeipc)) {
	fprintf(stderr, "Can not send token.\n");
	return 0;
      }
      state = UADE_R_STATE;

    } else {

      if (uade_receive_message(um, sizeof(space), &uadeipc) <= 0) {
	fprintf(stderr, "Can not receive events from uade\n");
	exit(-1);
      }
      
      switch (um->msgtype) {

      case UADE_COMMAND_TOKEN:
	state = UADE_S_STATE;
	break;

      case UADE_REPLY_DATA:
	sm = (uint16_t *) um->data;
	for (i = 0; i < um->size; i += 2) {
	  *sm = ntohs(*sm);
	  sm++;
	}

	if (subsong_end) {
	  play_bytes = tailbytes;
	  tailbytes = 0;
	} else {
	  play_bytes = um->size;
	}

	subsong_bytes += play_bytes;
	uade_lock();
	total_bytes += play_bytes;
	uade_unlock();

	if (skip_bytes > 0) {
	  if (play_bytes <= skip_bytes) {
	    skip_bytes -= play_bytes;
	    play_bytes = 0;
	  } else {
	    play_bytes -= skip_bytes;
	    skip_bytes = 0;
	  }
	}

	while ((writable = uade_ip.output->buffer_free()) < play_bytes) {
	  if (abort_playing)
	    goto nowrite;
	  xmms_usleep(10000);
	}

	uade_effect_run(&effects, (int16_t *) um->data, play_bytes / framesize);

	uade_ip.add_vis_pcm(uade_ip.output->written_time(), sample_format, UADE_CHANNELS, play_bytes, um->data);

	uade_ip.output->write_audio(um->data, play_bytes);

      nowrite:

	if (config.timeout != -1) {
	  if (song_end_trigger == 0) {
	    uade_lock();
	    if (total_bytes / UADE_BYTES_PER_SECOND >= config.timeout)
	      song_end_trigger = 1;
	    uade_unlock();
	  }
	}

	if (config.subsong_timeout != -1) {
	  if (subsong_end == 0 && song_end_trigger == 0) {
	    if (subsong_bytes / UADE_BYTES_PER_SECOND >= config.subsong_timeout) {
	      subsong_end = 1;
	    }
	  }
	}

	if (test_silence(um->data, play_bytes)) {
	  if (subsong_end == 0 && song_end_trigger == 0) {
	    subsong_end = 1;
	  }
	}

	assert (left >= um->size);
	left -= um->size;
	break;
	
      case UADE_REPLY_FORMATNAME:
	uade_check_fix_string(um, 128);
	/* plugindebug("Format name: %s\n", (uint8_t *) um->data); */
	break;

      case UADE_REPLY_MODULENAME:
	uade_check_fix_string(um, 128);
	/* plugindebug("Module name: %s\n", (uint8_t *) um->data); */
	break;

      case UADE_REPLY_MSG:
	uade_check_fix_string(um, 128);
	/* plugindebug("Message: %s\n", (char *) um->data); */
	break;

      case UADE_REPLY_PLAYERNAME:
	uade_check_fix_string(um, 128);
	/* plugindebug("Player name: %s\n", (uint8_t *) um->data); */
	break;

      case UADE_REPLY_SONG_END:
	if (um->size < 9) {
	  fprintf(stderr, "Invalid song end reply\n");
	  exit(-1);
	}
	tailbytes = ntohl(((uint32_t *) um->data)[0]);
	/* next ntohl() is only there for a principle. it is not useful */
	if (ntohl(((uint32_t *) um->data)[1]) == 0) {
	  /* normal happy song end. go to next subsong if any */
	  subsong_end = 1;
	} else {
	  /* unhappy song end (error in the 68k side). skip to next song
	     ignoring possible subsongs */
	  song_end_trigger = 1;
	}
	i = 0;
	reason = &((uint8_t *) um->data)[8];
	while (reason[i] && i < (um->size - 8))
	  i++;
	if (reason[i] != 0 || (i != (um->size - 9))) {
	  fprintf(stderr, "Broken reason string with song end notice\n");
	  exit(-1);
	}
	/* fprintf(stderr, "Song end (%s)\n", reason); */
	break;

      case UADE_REPLY_SUBSONG_INFO:
	if (um->size != 12) {
	  fprintf(stderr, "subsong info: too short a message\n");
	  exit(-1);
	}
	u32ptr = (uint32_t *) um->data;
	uade_lock();
	uade_min_sub = ntohl(u32ptr[0]);
	uade_max_sub = ntohl(u32ptr[1]);
	uade_cur_sub = ntohl(u32ptr[2]);

	if (!(-1 <= uade_min_sub && uade_min_sub <= uade_cur_sub && uade_cur_sub <= uade_max_sub)) {
	  int tempmin = uade_min_sub, tempmax = uade_max_sub;
	  fprintf(stderr, "uade: The player is broken. Subsong info does not match with %s.\n", gui_filename);
	  uade_min_sub = tempmin <= tempmax ? tempmin : tempmax;
	  uade_max_sub = tempmax >= tempmin ? tempmax : tempmin;
	  if (uade_cur_sub > uade_max_sub)
	    uade_max_sub = uade_cur_sub;
	  else if (uade_cur_sub < uade_min_sub)
	    uade_min_sub = uade_cur_sub;
	}
	uade_unlock();
	break;
	
      default:
	fprintf(stderr, "Expected sound data. got %d.\n", um->msgtype);
	plugin_disabled = 1;
	return NULL;
      }
    }
  }

  last_beat_played = 1;

  if (uade_send_short_message(UADE_COMMAND_REBOOT, &uadeipc)) {
    fprintf(stderr, "Can not send reboot.\n");
    return 0;
  }

  if (uade_send_short_message(UADE_COMMAND_TOKEN, &uadeipc)) {
    fprintf(stderr, "Can not send token.\n");
    return 0;
  }

  do {
    ret = uade_receive_message(um, sizeof(space), &uadeipc);
    if (ret < 0) {
      fprintf(stderr, "Can not receive events from uade.\n");
      return NULL;
    }
    if (ret == 0) {
      fprintf(stderr, "End of input after reboot.\n");
      return NULL;
    }
  } while (um->msgtype != UADE_COMMAND_TOKEN);

  return NULL;
}


/* Note that this function has side effects (static int64_t silence_count) */
static int test_silence(void *buf, size_t size)
{
  int i, s, exceptioncounter;
  int16_t *sm;
  int nsamples;
  static int64_t silence_count = 0;

  if (config.silence_timeout < 0)
    return 0;

  exceptioncounter = 0;
  sm = buf;
  nsamples = size / 2;

  for (i = 0; i < nsamples; i++) {
    s = (sm[i] >= 0) ? sm[i] : -sm[i];
    if (s >= (32767 * 1 / 100)) {
      exceptioncounter++;
      if (exceptioncounter >= (size * 2 / 100)) {
	silence_count = 0;
	break;
      }
    }
  }
  if (i == nsamples) {
    silence_count += size;
    if (silence_count / UADE_BYTES_PER_SECOND >= config.silence_timeout) {
      silence_count = 0;
      return 1;
    }
  }
  return 0;
}


static void uade_play_file(char *filename)
{
  char tempname[PATH_MAX];
  char *t;

  load_config();

  uade_lock();

  abort_playing = 0;
  last_beat_played = 0;
  total_bytes = 0;
  total_bytes_valid = 1;

  uade_cur_sub = uade_max_sub = uade_min_sub = -1;
  uade_is_paused = 0;
  uade_select_sub = -1;
  uade_seek_forward = 0;

  uade_unlock();

  if (strncmp(filename, "uade://", 7) == 0)
    filename += 7;

  strlcpy(tempname, filename, sizeof tempname);
  t = basename(tempname);
  if (t == NULL)
    t = filename;
  strlcpy(gui_filename, t, sizeof gui_filename);
  gui_info_set = 0;

  if (!uadepid) {
    char configname[PATH_MAX];
    snprintf(configname, sizeof configname, "%s/uaerc", UADE_CONFIG_BASE_DIR);
    uade_spawn(&uadeipc, &uadepid, UADE_CONFIG_UADE_CORE, configname);
  }

  if (!uade_ip.output->open_audio(sample_format, UADE_FREQUENCY, UADE_CHANNELS)) {
    abort_playing = 1;
    return;
  }

  if (plugin_disabled) {
    fprintf(stderr, "An error has occured. uade plugin is internally disabled.\n");
    goto err;
  }

  if (initialize_song(filename) == FALSE)
    goto err;

  /* If content db has changed (newer mtime chan previously read) then force
     a reload */
  if (md5name[0]) {
    struct stat st;
    time_t curtime;

    if (stat(md5name, &st) == 0 && md5_load_time < st.st_mtime)
      load_content_db();

    /* Save current db if an hour has passed */
    curtime = time(NULL);
    if (curtime >= (md5_load_time + 3600)) {
      uade_save_content_db(md5name);
      md5_load_time = curtime;
    }
  } else {
    load_content_db();
  }

  /* Compute md5sum of the file to be played, and see if its length is in the
     db, and use the length. */
  curplaytime = -1;
  if (uade_file_md5(curmd5, filename, sizeof curmd5)) {
    int playtime = uade_find_playtime(curmd5);
    if (playtime > 0)
      curplaytime = playtime;
  }

  uade_ip.set_info(gui_filename, curplaytime, UADE_BYTES_PER_SECOND, UADE_FREQUENCY, UADE_CHANNELS);

  if (pthread_create(&decode_thread, NULL, play_loop, NULL)) {
    fprintf(stderr, "uade: can't create play_loop() thread\n");
    goto err;
  }

  uade_thread_running = 1;

  return;

 err:
  /* close audio that was opened */
  uade_ip.output->close_audio();
  abort_playing = 1;
}

static void uade_stop(void)
{
  int play_time;

  /* Signal other subsystems to proceed to finished state as soon as possible
   */
  abort_playing = 1;

  /* Wait for playing thread to finish */
  if (uade_thread_running) {
    pthread_join(decode_thread, 0);
    uade_thread_running = 0;
  }

  /* If song ended volutarily, tell the play time for XMMS. */
  uade_lock();
  play_time = curplaytime;
  if (total_bytes_valid) {
    play_time = (((int64_t) total_bytes) * 1000) / UADE_BYTES_PER_SECOND;
    if (curmd5[0] != 0)
      uade_add_playtime(curmd5, play_time, 1);
  }
  uade_ip.set_info(gui_filename, play_time, UADE_BYTES_PER_SECOND, UADE_FREQUENCY, UADE_CHANNELS);
  uade_unlock();

  uade_ip.output->close_audio();
  uade_gui_close_subsong_win();
}


/* XMMS calls this function when pausing or unpausing */
static void uade_pause(short paused)
{
  uade_lock();
  uade_is_paused = paused;
  uade_unlock();
  uade_ip.output->pause(paused);
}


/* XMMS calls this function when song is seeked */
static void uade_seek(int time)
{
  uade_gui_seek_subsong(time);
}


/* XMMS calls this function periodically to determine current playing time.
   We use this function to report song name and title after play_file(),
   and to tell XMMS to end playing if song ends for any reason. */
static int uade_get_time(void)
{
  if (abort_playing || last_beat_played)
    return -1;

  if (gui_info_set == 0 && uade_max_sub != -1) {
    uade_lock();
    if (uade_max_sub != -1) {
      int playtime = curplaytime;
      /* Hack. Set info text and song length late because we didn't know
	 subsong amounts before this. Pass zero as a length so that the
	 graphical play time counter will run but seek is still enabled.
	 Passing -1 as playtime would disable seeking. */
      if (playtime <= 0)
	playtime = 0;
      uade_ip.set_info(gui_filename, playtime, UADE_BYTES_PER_SECOND, UADE_FREQUENCY, UADE_CHANNELS);
    }
    uade_unlock();
    gui_info_set = 1;
  }

  return uade_ip.output->output_time();
}


static void uade_get_song_info(char *filename, char **title, int *length)
{
  char tempname[PATH_MAX];
  char *t;

  if (strncmp(filename, "uade://", 7) == 0)
    filename += 7;

  strlcpy(tempname, filename, sizeof tempname);
  t = basename(tempname);
  if (t == NULL)
    t = filename;
  if ((*title = strdup(t)) == NULL)
    plugindebug("Not enough memory for song info.\n");
  *length = -1;
}

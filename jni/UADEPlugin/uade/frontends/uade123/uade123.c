/* uade123 - a simple command line frontend for uadecore.

   Copyright (C) 2005 Heikki Orsila <heikki.orsila@iki.fi>

   This source code module is dual licensed under GPL and Public Domain.
   Hence you may use _this_ module (not another code module) in any way you
   want in your projects.
*/

#include <assert.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define _GNU_SOURCE
#include <getopt.h>

#include <uadecontrol.h>
#include <uadeipc.h>
#include <strlrep.h>
#include <uadeconfig.h>
#include <eagleplayer.h>
#include <uadeconf.h>


#include "uade123.h"
#include "playlist.h"
#include "playloop.h"
#include "audio.h"
#include "terminal.h"
#include "amigafilter.h"

int uade_debug_trigger;
struct uade_config uadeconf;
struct uade_effect uade_effects;
struct uade_ipc uadeipc;
int uade_info_mode;
double uade_jump_pos = 0.0;
int uade_no_output;
char uade_output_file_format[16];
char uade_output_file_name[PATH_MAX];
struct playlist uade_playlist;
int uade_playtime;
FILE *uade_terminal_file;
int uade_terminal_mode = 1;
int uade_terminated;
int uade_song_end_trigger;
int uade_verbose_mode;

static char basedir[PATH_MAX];
static int debug_mode;
static char md5name[PATH_MAX];
static time_t md5_load_time;
static pid_t uadepid;
static char uadename[PATH_MAX];


static void print_help(void);
static void setup_sighandlers(void);
ssize_t stat_file_size(const char *name);
static void trivial_sigchld(int sig);
static void trivial_sigint(int sig);
static void trivial_cleanup(void);


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


int main(int argc, char *argv[])
{
  int i;
  char configname[PATH_MAX] = "";
  char modulename[PATH_MAX] = "";
  char playername[PATH_MAX] = "";
  char scorename[PATH_MAX] = "";
  int playernamegiven = 0;
  char tmpstr[PATH_MAX + 256];
  long subsong = -1;
  int have_modules = 0;
  int ret;
  char *endptr;
  int config_loaded;
  char *home;
  struct stat st;
  struct uade_effect uade_effects_backup;
  struct uade_config uadeconf_backup;

  enum {
    OPT_FILTER = 0x100,
    OPT_FORCE_LED,
    OPT_INTERPOLATOR,
    OPT_STDERR,
    OPT_NO_SONG_END,
    OPT_SPEED_HACK,
    OPT_BASEDIR,
    OPT_HEADPHONES
  };

  struct option long_options[] = {
    {"basedir", 1, NULL, OPT_BASEDIR},
    {"debug", 0, NULL, 'd'},
    {"filter", 2, NULL, OPT_FILTER},
    {"force-led", 1, NULL, OPT_FORCE_LED},
    {"get-info", 0, NULL, 'g'},
    {"gain", 1, NULL, 'G'},
    {"headphones", 0, NULL, OPT_HEADPHONES},
    {"help", 0, NULL, 'h'},
    {"ignore", 0, NULL, 'i'},
    {"interpolator", 1, NULL, OPT_INTERPOLATOR},
    {"jump", 1, NULL, 'j'},
    {"keys", 0, NULL, 'k'},
    {"list", 1, NULL, '@'},
    {"no-filter", 0, NULL, 'n'},
    {"no-song-end", 0, NULL, OPT_NO_SONG_END},
    {"no-keys", 0, NULL, 'K'},
    {"one", 0, NULL, '1'},
    {"panning", 1, NULL, 'p'},
    {"recursive", 0, NULL, 'r'},
    {"shuffle", 0, NULL, 'z'},
    {"silence-timeout", 1, NULL, 'y'},
    {"speed-hack", 0, NULL, OPT_SPEED_HACK},
    {"stderr", 0, NULL, OPT_STDERR},
    {"subsong", 1, NULL, 's'},
    {"subsong-timeout", 1, NULL, 'w'},
    {"timeout", 1, NULL, 't'},
    {"verbose", 0, NULL, 'v'},
    {NULL, 0, NULL, 0}
  };

  uade_config_set_defaults(&uadeconf);
  uade_effect_set_defaults(&uade_effects);

  if (!playlist_init(&uade_playlist)) {
    fprintf(stderr, "Can not initialize playlist.\n");
    exit(-1);
  }

  /* Create ~/.uade2 directory if it does not exist */
  home = getenv("HOME");
  if (home) {
    char name[PATH_MAX];
    snprintf(name, sizeof name, "%s/.uade2", home);
    if (stat(name, &st) != 0)
      mkdir(name, S_IRUSR | S_IWUSR | S_IXUSR);
  }

  /* First try to load config from ~/.uade2/uade.conf */
  config_loaded = 0;
  if (home) {
    snprintf(tmpstr, sizeof(tmpstr), "%s/.uade2/uade.conf", home);
    config_loaded = uade_load_config(&uadeconf, tmpstr);
  }
  if (config_loaded == 0)
    config_loaded = uade_load_config(&uadeconf, UADE_CONFIG_BASE_DIR "/uade.conf");
  if (config_loaded == 0)
    debug("Not able to load uade.conf from ~/.uade2/ or %s/.\n", UADE_CONFIG_BASE_DIR);

#define GET_OPT_STRING(x) if (strlcpy((x), optarg, sizeof(x)) >= sizeof(x)) {\
	fprintf(stderr, "Too long a string for option %c.\n", ret); \
         exit(-1); \
      }

  config_loaded = 0;
  if (home != NULL) {
    snprintf(tmpstr, sizeof(tmpstr), "%s/.uade2/song.conf", home);
    config_loaded = uade_read_song_conf(tmpstr);
  }
  if (config_loaded == 0)
    config_loaded = uade_read_song_conf(UADE_CONFIG_BASE_DIR "/song.conf");
  if (config_loaded == 0)
    debug("Not able to load song.conf from ~/.uade2/ or %s/.\n", UADE_CONFIG_BASE_DIR);

  load_content_db();

  while ((ret = getopt_long(argc, argv, "@:1de:f:gG:hij:kKm:np:P:rs:S:t:u:vw:y:z", long_options, 0)) != -1) {
    switch (ret) {
    case '@':
      do {
	FILE *listfile = fopen(optarg, "r");
	if (listfile == NULL) {
	  fprintf(stderr, "Can not open list file: %s\n", optarg);
	  exit(-1);
	}
	while ((fgets(tmpstr, sizeof(tmpstr), listfile)) != NULL) {
	  if (tmpstr[0] == '#')
	    continue;
	  if (tmpstr[strlen(tmpstr) - 1] == '\n')
	    tmpstr[strlen(tmpstr) - 1] = 0;
	  playlist_add(&uade_playlist, tmpstr, 0);
	}
	fclose(listfile);
	have_modules = 1;
      } while (0);
      break;
    case '1':
      uadeconf.one_subsong = 1;
      break;
    case 'd':
      debug_mode = 1;
      uade_debug_trigger = 1;
      break;
    case 'e':
      GET_OPT_STRING(uade_output_file_format);
      break;
    case 'f':
      GET_OPT_STRING(uade_output_file_name);
      break;
    case 'g':
      uade_info_mode = 1;
      uade_no_output = 1;
      uadeconf.action_keys = 0;
      break;
    case 'G':
      uadeconf.gain = uade_convert_to_double(optarg, 1.0, 0.0, 128.0, "gain");
      uadeconf.gain_enable = 1;
      break;
    case 'h':
      print_help();
      exit(0);
    case 'i':
      uadeconf.ignore_player_check = 1;
      break;
    case 'j':
      uade_jump_pos = strtod(optarg, &endptr);
      if (*endptr != 0 || uade_jump_pos < 0.0) {
	fprintf(stderr, "Invalid jump position: %s\n", optarg);
	exit(-1);
      }
      break;
    case 'k':
      uadeconf.action_keys = 1;
      break;
    case 'K':
      uadeconf.action_keys = 0;
      break;
    case 'm':
      playlist_add(&uade_playlist, optarg, 0);
      break;
    case 'n':
      uadeconf.no_filter = 1;
      break;
    case 'p':
      uadeconf.panning = uade_convert_to_double(optarg, 0.0, 0.0, 2.0, "panning");
      uadeconf.panning_enable = 1;
      break;
    case 'P':
      GET_OPT_STRING(playername);
      playernamegiven = 1;
      have_modules = 1;
      break;
    case 'r':
      uadeconf.recursive_mode = 1;
      break;
    case 's':
      subsong = strtol(optarg, &endptr, 10);
      if (*endptr != 0 || subsong < 0 || subsong > 255) {
	fprintf(stderr, "Invalid subsong string: %s\n", optarg);
	exit(-1);
      }
      break;
    case 'S':
      GET_OPT_STRING(scorename);
      break;
    case 't':
      uadeconf.timeout = uade_get_timeout(optarg);
      uadeconf.timeout_forced = 1;
      break;
    case 'u':
      GET_OPT_STRING(uadename);
      break;
    case 'v':
      uade_verbose_mode = 2;
      break;
    case 'w':
      uadeconf.timeout_forced = 1;
      uadeconf.subsong_timeout = uade_get_subsong_timeout(optarg);
      break;
    case 'y':
      uadeconf.silence_timeout = uade_get_silence_timeout(optarg);
      break;
    case 'z':
      uadeconf.random_play = 1;
      break;
    case '?':
    case ':':
      exit(-1);
    case OPT_FILTER:
      uadeconf.filter_type = uade_get_filter_type(optarg);
      break;
    case OPT_FORCE_LED:
      uadeconf.led_state = strtol(optarg, &endptr, 10);
      if (*endptr != 0 || uadeconf.led_state < 0 || uadeconf.led_state > 1) {
	fprintf(stderr, "Invalid filter state: %s (must 0 or 1)\n", optarg);
	exit(-1);
      }
      uadeconf.led_forced = 1;
      break;
    case OPT_INTERPOLATOR:
      uadeconf.interpolator = strdup(optarg);
      break;
    case OPT_STDERR:
      uade_terminal_file = stderr;
      break;
    case OPT_NO_SONG_END:
      uadeconf.no_song_end = 1;
      break;
    case OPT_SPEED_HACK:
      uadeconf.speed_hack = 1;
      break;
    case OPT_BASEDIR:
      GET_OPT_STRING(basedir);
      break;
    case OPT_HEADPHONES:
      uadeconf.headphones = 1;
      break;
    default:
      fprintf(stderr, "Impossible option.\n");
      exit(-1);
    }
  }

  for (i = optind; i < argc; i++) {
    playlist_add(&uade_playlist, argv[i], uadeconf.recursive_mode);
    have_modules = 1;
  }

  if (uadeconf.gain_enable) {
    uade_effect_gain_set_amount(&uade_effects, uadeconf.gain);
    uade_effect_enable(&uade_effects, UADE_EFFECT_GAIN);
  }

  if (uadeconf.headphones)
    uade_effect_enable(&uade_effects, UADE_EFFECT_HEADPHONES);

  if (uadeconf.no_filter) {
    uadeconf.filter_type = 0;
    uadeconf.led_forced = 0;
    uadeconf.led_state = 0;
  }

  if (uadeconf.panning_enable) {
    uade_effect_pan_set_amount(&uade_effects, uadeconf.panning);
    uade_effect_enable(&uade_effects, UADE_EFFECT_PAN);
  }

  if (uadeconf.random_play)
    playlist_random(&uade_playlist, 1);

  if (have_modules == 0) {
    print_help();
    exit(0);
  }

  /* we want to control terminal differently in debug mode */
  if (debug_mode)
    uade_terminal_mode = 0;

  if (uade_terminal_mode)
    setup_terminal();

  if (basedir[0] == 0)
    strlcpy(basedir, UADE_CONFIG_BASE_DIR, sizeof(basedir));

#define CHECK_EXISTENCE(x, y) do { if ((x)[0] == 0) { fprintf(stderr, "Must have %s\n", (y)); exit(-1); } } while (0)

  if (basedir[0]) {
    DIR *bd;
    if ((bd = opendir(basedir)) == NULL) {
      fprintf(stderr, "Could not access dir %s: %s\n", basedir, strerror(errno));
      exit(-1);
    }
    closedir(bd);
    snprintf(configname, sizeof(configname), "%s/uaerc", basedir);
    if (scorename[0] == 0)
      snprintf(scorename, sizeof(scorename), "%s/score", basedir);
    if (uadename[0] == 0)
      strlcpy(uadename, UADE_CONFIG_UADE_CORE, sizeof(uadename));
  } else {
    CHECK_EXISTENCE(configname, "config name");
    CHECK_EXISTENCE(scorename, "score name");
    CHECK_EXISTENCE(uadename, "uade executable name");
  }

  if (access(configname, R_OK)) {
    fprintf(stderr, "Could not read %s: %s\n", configname, strerror(errno));
    exit(-1);
  }
  if (access(scorename, R_OK)) {
    fprintf(stderr, "Could not read %s: %s\n", scorename, strerror(errno));
    exit(-1);
  }
  if (access(uadename, X_OK)) {
    fprintf(stderr, "Could not execute %s: %s\n", uadename, strerror(errno));
    exit(-1);
  }

  setup_sighandlers();

  uade_spawn(&uadeipc, &uadepid, uadename, configname);

  if (!audio_init())
    goto cleanup;

  uade_effects_backup = uade_effects;
  uadeconf_backup = uadeconf;

  while (playlist_get_next(modulename, sizeof(modulename), &uade_playlist)) {
    int nplayers;
    ssize_t filesize;

    uade_effects = uade_effects_backup;
    uadeconf = uadeconf_backup;

    if (access(modulename, R_OK)) {
      fprintf(stderr, "Can not read %s: %s\n", modulename, strerror(errno));
      continue;
    }

    nplayers = 1;
    if (playernamegiven == 0) {
      struct eagleplayer *candidate;
      char md5[33];

      debug("\n");

      candidate = uade_analyze_file_format(modulename, basedir, uade_verbose_mode);

      if (candidate == NULL) {
	fprintf(stderr, "Unknown format: %s\n", modulename);
	continue;
      }
      debug("Player candidate: %s\n", candidate->playername);

      if (candidate->attributes & EP_SPEED_HACK) {
	uadeconf.speed_hack = 1;
	debug("eagleplayer.conf specifies speed hack.\n");
      }

      if (candidate->attributes & EP_ALWAYS_ENDS) {
	uadeconf.always_ends = 1;
	debug("eagleplayer.conf specifies always ends.\n");
      }

      if (candidate->attributes & EP_A500) {
	uadeconf.filter_type = FILTER_MODEL_A500;
	debug("eagleplayer.conf specifies filter model %d\n",uadeconf.filter_type);
      }
      if (candidate->attributes & EP_A1200) {
	uadeconf.filter_type = FILTER_MODEL_A1200;
	debug("eagleplayer.conf specifies filter model %d\n",uadeconf.filter_type);
      }

      if (uade_file_md5(md5, modulename, sizeof md5)) {
	struct eaglesong *es = uade_analyze_song(md5);
	if (es) {
	  fprintf(stderr, "Warning: song.conf is not implemented properly. Effects are permanent rather than file specific :(\n");
	  if (es->flags & ES_A500)
	    uadeconf.filter_type = FILTER_MODEL_A500;
	  if (es->flags & ES_A1200)
	    uadeconf.filter_type = FILTER_MODEL_A1200;
	  if (es->flags & ES_LED_OFF) {
	    uadeconf.led_forced = 1;
	    uadeconf.led_state = 0;
	  }
	  if (es->flags & ES_LED_ON) {
	    uadeconf.led_forced = 1;
	    uadeconf.led_state = 1;
	  }
	  /* Command line should be able to override these */
	  if (es->flags & ES_NO_HEADPHONES)
	    uade_effect_disable(&uade_effects, UADE_EFFECT_HEADPHONES);
	  if (es->flags & ES_NO_PANNING)
	    uade_effect_disable(&uade_effects, UADE_EFFECT_PAN);
	  if (es->flags & ES_NO_POSTPROCESSING)
	    uade_effect_disable(&uade_effects, UADE_EFFECT_ALLOW);
	  if (es->flags & ES_NTSC)
	    fprintf(stderr, "NTSC not implemented.\n");
	  if (es->subsongs)
	    fprintf(stderr, "Subsongs not implemented.\n");
	}
      }

      uade_playtime = uade_find_playtime(md5);
      if (uade_playtime <= 0)
	uade_playtime = -1;

      if (strcmp(candidate->playername, "custom") == 0) {
	strlcpy(playername, modulename, sizeof playername);
	modulename[0] = 0;
      } else {
	snprintf(playername, sizeof playername, "%s/players/%s", basedir, candidate->playername);
      }
    }

    if (playername[0]) {
      if (access(playername, R_OK)) {
	fprintf(stderr, "Can not read %s: %s\n", playername, strerror(errno));
	continue;
      }
    }

    if ((filesize = stat_file_size(playername)) < 0) {
      fprintf(stderr, "Can not stat player: %s\n", playername);
      continue;
    }
    if (uade_verbose_mode || modulename[0] == 0)
      fprintf(stderr, "Player: %s (%zd bytes)\n", playername, filesize);
    if (modulename[0] != 0) {
      if ((filesize = stat_file_size(modulename)) < 0) {
	fprintf(stderr, "Can not stat module: %s\n", modulename);
	continue;
      }
      fprintf(stderr, "Module: %s (%zd bytes)\n", modulename, filesize);
    }

    if ((ret = uade_song_initialization(scorename, playername, modulename, &uadeipc))) {
      if (ret == UADECORE_INIT_ERROR) {
	goto cleanup;
      } else if (ret == UADECORE_CANT_PLAY) {
	debug("Uadecore refuses to play the song.\n");
	continue;
      }
      fprintf(stderr, "Unknown error from uade_song_initialization()\n");
      exit(-1);
    }

    if (uadeconf.ignore_player_check) {
      if (uade_send_short_message(UADE_COMMAND_IGNORE_CHECK, &uadeipc) < 0) {
	fprintf(stderr, "Can not send ignore check message.\n");
	exit(-1);
      }
    }

    if (uadeconf.no_song_end) {
      if (uade_send_short_message(UADE_COMMAND_SONG_END_NOT_POSSIBLE, &uadeipc) < 0) {
	fprintf(stderr, "Can not send 'song end not possible'.\n");
	exit(-1);
      }
    }

    if (subsong >= 0)
      uade_set_subsong(subsong, &uadeipc);

    uade_send_filter_command(uadeconf.filter_type, uadeconf.led_state, uadeconf.led_forced, &uadeipc);
    uade_send_interpolation_command(uadeconf.interpolator, &uadeipc);
    if (uadeconf.speed_hack) {
      if (uade_send_short_message(UADE_COMMAND_SPEED_HACK, &uadeipc)) {
	fprintf(stderr, "Can not send speed hack command.\n");
	exit(-1);
      }
    }

    if (!play_loop())
      goto cleanup;
  }

  debug("Killing child (%d).\n", uadepid);
  trivial_cleanup();
  return 0;

 cleanup:
  trivial_cleanup();
  return -1;
}


static void print_help(void)
{
  printf("uade123 %s\n", UADE_VERSION);
  printf(" by Heikki Orsila <heikki.orsila@iki.fi>\n");
  printf("    Michael Doering <mldoering@gmx.net>\n");
  printf("uadecore is based on the UAE source code. UAE is made by Bernd Schmidt et al.\n");
  printf("\n");
  printf("Usage: uade123 [<options>] <input file> ...\n");
  printf("\n");
  printf("Expert options:\n");
  printf(" --basedir=dirname,  Set uade base directory (contains data files)\n");
  printf(" -d/--debug,         Enable debug mode (expert only)\n");
  printf(" -S filename,        Set sound core name\n");
  printf(" -u uadename,        Set uadecore executable name\n");
  printf("\n");
  printf("Normal options:\n");
  printf(" -1, --one,          Play at most one subsong per file\n");
  printf(" -@ filename, --list=filename,  Read playlist of files from 'filename'\n");
  printf(" -e format,          Set output file format. Use with -f. wav is the default\n");
  printf("                     format.\n");
  printf(" -f filename,        Write audio output into 'filename' (see -e also)\n");
  printf(" --filter=model      Set filter model to A500, A500E, A1200, or A1200E. The\n");
  printf("                     default is A500E. PLEASE NOTE that A500 and A1200 are\n");
  printf("                     audibly different even if a song doesn't use filtering.\n");
  printf("                     Trying different types is recommended.\n");
  printf(" --filter,           Enable filter emulation. It is enabled by default.\n");
  printf(" --force-led=0/1,    Force LED state to 0 or 1. That is, filter is OFF or ON.\n");
  printf(" -G x, --gain=x,     Set volume gain to x in range [0, 1]. Default is 1.0.\n");
  printf(" -g, --get-info,     Just print playername and subsong info on stdout.\n");
  printf("                     Do not play.\n");
  printf(" -h/--help,          Print help\n");
  printf(" --headphone,        Enable headphone postprocessing effect.\n");
  printf(" -i, --ignore,       Ignore eagleplayer fileformat check result. Play always.\n");
  printf(" --interpolator=x    Set interpolator to x, where x = default or anti.\n");
  printf(" -j x, --jump=x,     Jump to time position 'x' seconds from the beginning.\n");
  printf("                     fractions of a second are allowed too.\n");
  printf(" -k, --keys,         Enable action keys for playback control on terminal\n");
  printf(" -K, --no-keys,      Disable action keys for playback control on terminal\n");
  printf(" -m filename,        Set module name\n");
  printf(" -n, --no-filter     No filter emulation.\n");
  printf(" --no-song-end,      Ignore song end report. Just keep playing.\n");
  printf(" -p x, --panning=x,  Set panning value in range [0, 2]. 0 is full stereo,\n");
  printf("                     1 is mono, and 2 is inverse stereo. The default is 0.7.\n");
  printf(" -P filename,        Set player name\n");
  printf(" -r/--recursive,     Recursive directory scan\n");
  printf(" -s x, --subsong=x,  Set subsong 'x'\n");
  printf(" --speed-hack,       Set speed hack on. This gives more virtual CPU power.\n");
  printf(" --stderr,           Print messages on stderr.\n");
  printf(" -t x, --timeout=x,  Set song timeout in seconds. -1 is infinite.\n");
  printf("                     Default is infinite.\n");
  printf(" -v,  --verbose,     Turn on verbose mode\n");
  printf(" -w x, --subsong-timeout=x,  Set subsong timeout in seconds. -1 is infinite.\n");
  printf("                             Default is 512s\n");
  printf(" -y x, --silence-timeout=x,  Set silence timeout in seconds. -1 is infinite.\n");
  printf("                         Default is 20s\n");
  printf(" -z, --shuffle,      Set shuffling mode for playlist\n");
  printf("\n");
  print_action_keys();
  printf("\n");
  printf("Example: Play all songs under /chip/fc directory in shuffling mode:\n");
  printf("  uade -z /chip/fc/*\n"); 
}


void print_action_keys(void)
{
  tprintf("Action keys for interactive mode:\n");
  tprintf(" [0-9]         Change subsong.\n");
  tprintf(" '.'           Skip 10 seconds forward.\n");
  tprintf(" SPACE, 'b'    Go to next subsong.\n");
  tprintf(" 'c'           Pause.\n");
  tprintf(" 'f'           Toggle filter (takes filter control away from eagleplayer).\n");
  tprintf(" 'g'           Toggle gain effect.\n");
  tprintf(" 'h'           Print this list.\n");
  tprintf(" 'H'           Toggle headphones effect.\n");
  tprintf(" RETURN, 'n'   Next song.\n");
  tprintf(" 'p'           Toggle postprocessing effects.\n");
  tprintf(" 'P'           Toggle panning effect. Default value is 0.7.\n");
  tprintf(" 'q'           Quit.\n");
  tprintf(" 's'           Toggle between shuffle mode and normal play.\n");
  tprintf(" 'v'           Toggle verbose mode.\n");
  tprintf(" 'x'           Restart current subsong.\n");
  tprintf(" 'z'           Previous subsong.\n");
}


static void setup_sighandlers(void)
{
  struct sigaction act;
  memset(&act, 0, sizeof act);
  act.sa_handler = trivial_sigint;
  while (1) {
    if ((sigaction(SIGINT, &act, NULL)) < 0) {
      if (errno == EINTR)
	continue;
      fprintf(stderr, "can not install signal handler SIGINT: %s\n", strerror(errno));
      exit(-1);
    }
    break;
  }
  memset(&act, 0, sizeof act);
  act.sa_handler = trivial_sigchld;
  act.sa_flags = SA_NOCLDSTOP;
  while (1) {
    if ((sigaction(SIGCHLD, &act, NULL)) < 0) {
      if (errno == EINTR)
	continue;
      fprintf(stderr, "can not install signal handler SIGCHLD: %s\n", strerror(errno));
      exit(-1);
    }
    break;
  }
}


ssize_t stat_file_size(const char *name)
{
  struct stat st;
  if (stat(name, &st))
    return -1;
  return st.st_size;
}


/* test song_end_trigger by taking care of mutual exclusion with SIGINT */
int test_song_end_trigger(void)
{
  int ret;
  sigset_t set;
  if (sigemptyset(&set))
    goto sigerr;
  if (sigaddset(&set, SIGINT))
    goto sigerr;
  if (sigprocmask(SIG_BLOCK, &set, NULL))
    goto sigerr;
  ret = uade_song_end_trigger;
  uade_song_end_trigger = 0;
  if (sigprocmask(SIG_UNBLOCK, &set, NULL))
    goto sigerr;
  return ret;

 sigerr:
  fprintf(stderr, "signal hell\n");
  exit(-1);
}


static void trivial_cleanup(void)
{
  if (uadepid) {
    kill(uadepid, SIGTERM);
    uadepid = 0;
  }
  audio_close();
}


static void trivial_sigchld(int sig)
{
  pid_t process;
  int status;
  int successful;
  process = waitpid(-1, &status, WNOHANG);
  if (process == 0)
    return;
  if (uadepid == 0)
    return;
  if (process == uadepid) {
    successful = (WEXITSTATUS(status) == 0);
    debug("Uadecore exited %ssuccessfully\n", successful == 1 ? "" : "un");
    uadepid = 0;
    uade_terminated = 1;
  }
}


static void trivial_sigint(int sig)
{
  static struct timeval otv = {.tv_sec = 0, .tv_usec = 0};
  struct timeval tv;
  int msecs;

  if (debug_mode == 1) {
    uade_debug_trigger = 1;
    return;
  }
  uade_song_end_trigger = 1;

  /* counts number of milliseconds between ctrl-c pushes, and terminates the
     prog if they are less than 100 msecs apart. */ 
  if (gettimeofday(&tv, 0)) {
    fprintf(stderr, "Gettimeofday() does not work.\n");
    return;
  }
  msecs = 0;
  if (otv.tv_sec) {
    msecs = (tv.tv_sec - otv.tv_sec) * 1000 + (tv.tv_usec - otv.tv_usec) / 1000;
    if (msecs < 100)
      exit(-1);
  }
  otv = tv;
}

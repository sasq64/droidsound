/* uade123 - a simple command line frontend for uadecore.

   Copyright (C) 2005 Heikki Orsila <heikki.orsila@iki.fi>

   This source code module is dual licensed under GPL and Public Domain.
   Hence you may use _this_ module (not another code module) in any way you
   want in your projects.
*/

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include <uadeipc.h>
#include <uadecontrol.h>
#include <uadeconstants.h>
#include <uadeconf.h>

#include "uade123.h"
#include "audio.h"
#include "terminal.h"
#include "playlist.h"


/* Note that this function has side effects (static int64_t silence_count) */
static int uade_test_silence(void *buf, size_t size)
{
  int i, s, exceptioncounter;
  int16_t *sm;
  int nsamples;
  static int64_t silence_count = 0;

  if (uadeconf.silence_timeout < 0)
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
    if (silence_count / UADE_BYTES_PER_SECOND >= uadeconf.silence_timeout) {
      silence_count = 0;
      return 1;
    }
  }
  return 0;
}


int play_loop(void)
{
  uint16_t *sm;
  int i;
  uint32_t *u32ptr;

  uint8_t space[UADE_MAX_MESSAGE_SIZE];
  struct uade_msg *um = (struct uade_msg *) space;

  uint8_t sampledata[UADE_MAX_MESSAGE_SIZE];
  int left = 0;
  int what_was_left = 0;

  int subsong_end = 0;
  int next_song = 0;
  int ret;
  int cur_sub = -1, min_sub = -1, max_sub = -1, new_sub;
  int tailbytes = 0;
  int playbytes;
  char *reason;
  int64_t total_bytes = 0;
  int64_t subsong_bytes = 0;
  int64_t skip_bytes;
  int64_t time_bytes = 0;
  int deciseconds;
  int jump_sub = 0;

  int have_subsong_info = 0;

  const int framesize = UADE_BYTES_PER_SAMPLE * UADE_CHANNELS;

  uade_effect_reset_internals();

  /* Skip bytes must be a multiple of audio frame size */
  skip_bytes = uade_jump_pos * UADE_BYTES_PER_SECOND;
  skip_bytes = (skip_bytes / framesize) * framesize;

  test_song_end_trigger(); /* clear a pending SIGINT */

  enum uade_control_state state = UADE_S_STATE;

  while (next_song == 0) {

    if (uade_terminated) {
      if (!uade_no_output)
	tprintf("\n");
      return 0;
    }

    if (state == UADE_S_STATE) {

      if (skip_bytes == 0) {
	deciseconds = time_bytes * 10 / (UADE_BYTES_PER_SECOND);
	if (!uade_no_output) {
	  if (uade_playtime >= 0) {
	    int ptimesecs = uade_playtime / 1000;
	    int ptimesubsecs = (uade_playtime / 100) % 10;
	    tprintf("Playing time position %d.%ds in subsong %d (all subs %d.%ds)  \r", deciseconds / 10, deciseconds % 10, cur_sub == -1 ? 0 : cur_sub, ptimesecs, ptimesubsecs);
	  } else {
	    tprintf("Playing time position %d.%ds in subsong %d                \r", deciseconds / 10, deciseconds % 10,  cur_sub == -1 ? 0 : cur_sub);
	  }
	  fflush(stdout);
	}
      }

      if (uade_terminal_mode) {
	switch ((ret = poll_terminal())) {
	case 0:
	  break;
	case '.':
	  if (skip_bytes == 0) {
	    fprintf(stderr, "\nSkipping 10 seconds\n");
	    skip_bytes = UADE_BYTES_PER_SECOND * 10;
	  }
	  break;
	case ' ':
	case 'b':
	  subsong_end = 1;
	  break;
	case 'c':
	  pause_terminal();
	  break;
	case 'f':
	  uadeconf.filter_type = uade_get_filter_type(NULL);
	  uadeconf.led_forced = 1;
	  uadeconf.led_state ^= 1;
	  tprintf("\nForcing LED %s\n", (uadeconf.led_state & 1) ? "ON" : "OFF");
	  uade_send_filter_command(uadeconf.filter_type, uadeconf.led_state, uadeconf.led_forced, &uadeipc);
	  break;
	case 'g':
	  uade_effect_toggle(&uade_effects, UADE_EFFECT_GAIN);
	  tprintf("\nGain effect %s %s\n", uade_effect_is_enabled(&uade_effects, UADE_EFFECT_GAIN) ? "ON" : "OFF", (uade_effect_is_enabled(&uade_effects, UADE_EFFECT_ALLOW) == 0 && uade_effect_is_enabled(&uade_effects, UADE_EFFECT_GAIN)) ? "(Remember to turn ON postprocessing!)" : "");
	  break;
	case 'h':
	  tprintf("\n\n");
	  print_action_keys();
	  tprintf("\n");
	  break;
	case 'H':
	  uade_effect_toggle(&uade_effects, UADE_EFFECT_HEADPHONES);
	  tprintf("\nHeadphones effect %s %s\n", uade_effect_is_enabled(&uade_effects, UADE_EFFECT_HEADPHONES) ? "ON" : "OFF", (uade_effect_is_enabled(&uade_effects, UADE_EFFECT_ALLOW) == 0 && uade_effect_is_enabled(&uade_effects, UADE_EFFECT_HEADPHONES) == 1) ? "(Remember to turn ON postprocessing!)" : "");
	  break;
	case '\n':
	case 'n':
	  uade_song_end_trigger = 1;
	  break;
	case 'p':
	  uade_effect_toggle(&uade_effects, UADE_EFFECT_ALLOW);
	  tprintf("\nPostprocessing effects %s\n", uade_effect_is_enabled(&uade_effects, UADE_EFFECT_ALLOW) ? "ON" : "OFF");
	  break;
	case 'P':
	  uade_effect_toggle(&uade_effects, UADE_EFFECT_PAN);
	  tprintf("\nPanning effect %s %s\n", uade_effect_is_enabled(&uade_effects, UADE_EFFECT_PAN) ? "ON" : "OFF", (uade_effect_is_enabled(&uade_effects, UADE_EFFECT_ALLOW) == 0 && uade_effect_is_enabled(&uade_effects, UADE_EFFECT_PAN) == 1) ? "(Remember to turn ON postprocessing!)" : "");
	  break;
	case 'q':
	  tprintf("\n");
	  return 0;
	case 's':
	  playlist_random(&uade_playlist, -1);
	  tprintf("\n%s mode\n", uade_playlist.randomize ? "Shuffle" : "Normal");
	  break;
	case 'v':
	  uade_verbose_mode ^= 1;
	  tprintf("\nVerbose mode %s\n", uade_verbose_mode ? "ON" : "OFF");
	  break;
	case 'x':
	  cur_sub--;
	  subsong_end = 1;
	  jump_sub = 1;
	  break;
	case 'z':
	  new_sub = cur_sub - 1;
	  if (new_sub < 0)
	    new_sub = 0;
	  if (min_sub >= 0 && new_sub < min_sub)
	    new_sub = min_sub;
	  cur_sub = new_sub - 1;
	  subsong_end = 1;
	  jump_sub = 1;
	  break;
	default:
	  if (isdigit(ret)) {
	    new_sub = ret - '0';
	    if (min_sub >= 0 && new_sub < min_sub) {
	      fprintf(stderr, "\ntoo low a subsong number\n");
	      break;
	    }
	    if (max_sub >= 0 && new_sub > max_sub) {
	      fprintf(stderr, "\ntoo high a subsong number\n");
	      break;
	    }
	    cur_sub = new_sub - 1;
	    subsong_end = 1;
	    jump_sub = 1;
	  } else if (!isspace(ret)) {
	    fprintf(stderr, "\n%c is not a valid command\n", ret);
	  }
	}
      }

      if (uade_debug_trigger == 1) {
	if (uade_send_short_message(UADE_COMMAND_ACTIVATE_DEBUGGER, &uadeipc)) {
	  fprintf(stderr, "\nCan not active debugger\n");
	  return 0;
	}
	uade_debug_trigger = 0;
      }
      
      if (uade_info_mode && have_subsong_info) {
	/* we assume that subsong info is the last info we get */
	uade_song_end_trigger = 1;
	subsong_end = 0;
      }

      if (subsong_end && uade_song_end_trigger == 0) {
	if (jump_sub || (uadeconf.one_subsong == 0 && cur_sub != -1 && max_sub != -1)) {
	  cur_sub++;
	  jump_sub = 0;
	  if (cur_sub > max_sub) {
	    uade_song_end_trigger = 1;
	  } else {
	    subsong_end = 0;
	    subsong_bytes = 0;
	    time_bytes = 0;
	    uade_change_subsong(cur_sub, &uadeipc);
	    fprintf(stderr, "\nChanging to subsong %d from range [%d, %d]\n", cur_sub, min_sub, max_sub);
	  }
	} else {
	  uade_song_end_trigger = 1;
	}
      }

      /* Check if control-c was pressed */
      if (uade_song_end_trigger) {
	next_song = 1;
	if (uade_send_short_message(UADE_COMMAND_REBOOT, &uadeipc)) {
	  fprintf(stderr, "\nCan not send reboot\n");
	  return 0;
	}
	goto sendtoken;
      }

      left = uade_read_request(&uadeipc);

    sendtoken:
      if (uade_send_short_message(UADE_COMMAND_TOKEN, &uadeipc)) {
	fprintf(stderr, "\nCan not send token\n");
	return 0;
      }

      state = UADE_R_STATE;

      if (what_was_left) {
	if (subsong_end) {
	  /* We can only rely on 'tailbytes' amount which was determined
	     earlier when UADE_REPLY_SONG_END happened */
	  playbytes = tailbytes;
	  tailbytes = 0;
	} else {
	  playbytes = what_was_left;
	}

	time_bytes += playbytes;

	/* FIX ME */
	if (uadeconf.timeout != -1)
	  total_bytes += playbytes;

	if (uadeconf.subsong_timeout != -1)
	  subsong_bytes += playbytes;

	if (skip_bytes > 0) {
	  if (playbytes <= skip_bytes) {
	    skip_bytes -= playbytes;
	    playbytes = 0;
	  } else {
	    playbytes -= skip_bytes;
	    memmove(sampledata, sampledata + skip_bytes, playbytes);
	    skip_bytes = 0;
	  }
	}

	uade_effect_run(&uade_effects, (int16_t *) sampledata, playbytes / framesize);

	if (!audio_play(sampledata, playbytes)) {
	  fprintf(stderr, "\nlibao error detected.\n");
	  return 0;
	}

	/* FIX ME */
	if (uadeconf.timeout != -1 && uadeconf.always_ends == 0) {
	  if (uade_song_end_trigger == 0) {
	    if (total_bytes / UADE_BYTES_PER_SECOND >= uadeconf.timeout) {
	      fprintf(stderr, "\nSong end (timeout %ds)\n", uadeconf.timeout);
	      uade_song_end_trigger = 1;
	    }
	  }
	}

	if (uadeconf.subsong_timeout != -1 && uadeconf.always_ends == 0) {
	  if (subsong_end == 0 && uade_song_end_trigger == 0) {
	    if (subsong_bytes / UADE_BYTES_PER_SECOND >= uadeconf.subsong_timeout) {
	      fprintf(stderr, "\nSong end (subsong timeout %ds)\n", uadeconf.subsong_timeout);
	      subsong_end = 1;
	    }
	  }
	}

	if (uade_test_silence(um->data, playbytes)) {
	  if (subsong_end == 0 && uade_song_end_trigger == 0) {
	    fprintf(stderr, "\nsilence detected (%d seconds)\n", uadeconf.silence_timeout);
	    subsong_end = 1;
	  }
	}
      }

    } else {

      /* receive state */

      if (uade_receive_message(um, sizeof(space), &uadeipc) <= 0) {
	fprintf(stderr, "\nCan not receive events from uade\n");
	return 0;
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

	assert (left == um->size);
	assert (sizeof sampledata >= um->size);

	memcpy(sampledata, um->data, um->size);

	what_was_left = left;
	left = 0;
	break;
	
      case UADE_REPLY_FORMATNAME:
	uade_check_fix_string(um, 128);
	debug("\nFormat name: %s\n", (uint8_t *) um->data);
	if (uade_info_mode)
	  tprintf("formatname: %s\n", (char *) um->data);
	break;
	
      case UADE_REPLY_MODULENAME:
	uade_check_fix_string(um, 128);
	debug("\nModule name: %s\n", (uint8_t *) um->data);
	if (uade_info_mode)
	  tprintf("modulename: %s\n", (char *) um->data);
	break;

      case UADE_REPLY_MSG:
	uade_check_fix_string(um, 128);
	debug("\nMessage: %s\n", (char *) um->data);
	break;

      case UADE_REPLY_PLAYERNAME:
	uade_check_fix_string(um, 128);
	debug("\nPlayer name: %s\n", (uint8_t *) um->data);
	if (uade_info_mode)
	  tprintf("playername: %s\n", (char *) um->data);
	break;

      case UADE_REPLY_SONG_END:
	if (um->size < 9) {
	  fprintf(stderr, "\nInvalid song end reply\n");
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
	  uade_song_end_trigger = 1;
	}
	i = 0;
	reason = (char *) &um->data[8];
	while (reason[i] && i < (um->size - 8))
	  i++;
	if (reason[i] != 0 || (i != (um->size - 9))) {
	  fprintf(stderr, "\nbroken reason string with song end notice\n");
	  exit(-1);
	}
	fprintf(stderr, "\nSong end (%s)\n", reason);
	break;

      case UADE_REPLY_SUBSONG_INFO:
	if (um->size != 12) {
	  fprintf(stderr, "\nsubsong info: too short a message\n");
	  exit(-1);
	}
	u32ptr = (uint32_t *) um->data;
	min_sub = ntohl(u32ptr[0]);
	max_sub = ntohl(u32ptr[1]);
	cur_sub = ntohl(u32ptr[2]);
	debug("\nsubsong: %d from range [%d, %d]\n", cur_sub, min_sub, max_sub);
	if (!(-1 <= min_sub && min_sub <= cur_sub && cur_sub <= max_sub)) {
	  int tempmin = min_sub, tempmax = max_sub;
	  fprintf(stderr, "\nThe player is broken. Subsong info does not match.\n");
	  min_sub = tempmin <= tempmax ? tempmin : tempmax;
	  max_sub = tempmax >= tempmin ? tempmax : tempmin;
	  if (cur_sub > max_sub)
	    max_sub = cur_sub;
	  else if (cur_sub < min_sub)
	    min_sub = cur_sub;
	}
	if ((max_sub - min_sub) != 0)
	  fprintf(stderr, "\nThere are %d subsongs in range [%d, %d].\n", 1 + max_sub - min_sub, min_sub, max_sub);
	have_subsong_info = 1;
	if (uade_info_mode)
	  tprintf("subsong_info: %d %d %d (cur, min, max)\n", cur_sub, min_sub, max_sub);
	break;
	
      default:
	fprintf(stderr, "\nExpected sound data. got %d.\n", um->msgtype);
	return 0;
      }
    }
  }

  do {
    ret = uade_receive_message(um, sizeof(space), &uadeipc);
    if (ret < 0) {
      fprintf(stderr, "\nCan not receive events (TOKEN) from uade.\n");
      return 0;
    }
    if (ret == 0) {
      fprintf(stderr, "\nEnd of input after reboot.\n");
      return 0;
    }
  } while (um->msgtype != UADE_COMMAND_TOKEN);

  tprintf("\n");
  return 1;
}

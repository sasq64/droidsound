/* 
 * UADE
 * 
 * Support for sound
 * 
 * Copyright 2000 - 2005 Heikki Orsila <heikki.orsila@iki.fi>
 */

#include "sysconfig.h"
#include "sysdeps.h"

#include "options.h"
#include "include/memory.h"
#include "custom.h"
#include "gensound.h"
#include "sd-sound.h"

#include "uade.h"

uae_u16 sndbuffer[MAX_SOUND_BUF_SIZE / 2];
uae_u16 *sndbufpt;
int sndbufsize;

int sound_bytes_per_second;

void close_sound (void)
{
}

/* Try to determine whether sound is available.  */
int setup_sound (void)
{
   sound_available = 1;
   return 1;
}

void init_sound (void)
{
  int channels;
  int dspbits;
  unsigned int rate;
  
  if (currprefs.sound_maxbsiz < 128 || currprefs.sound_maxbsiz > 16384) {
    fprintf (stderr, "Sound buffer size %d out of range.\n", currprefs.sound_maxbsiz);
    currprefs.sound_maxbsiz = 8192;
  }
  sndbufsize = 8192;
  
  dspbits = currprefs.sound_bits;
  rate    = currprefs.sound_freq;
  channels = currprefs.stereo ? 2 : 1;

  if (dspbits != (UADE_BYTES_PER_SAMPLE * 8)) {
    fprintf(stderr, "Only 16 bit sounds supported.\n");
    exit(-1);
  }
  if (channels != UADE_CHANNELS) {
    fprintf(stderr, "Only stereo supported.\n");
    exit(-1);
  }

  sound_bytes_per_second = (dspbits / 8) *  channels * rate;
  
  sample_evtime_interval = ((float) maxhpos) * maxvpos * 50 / rate;

  sample_handler = sample16s_handler;

  sound_available = 1;
  
  sndbufpt = sndbuffer;
#ifdef FRAME_RATE_HACK
  vsynctime = vsynctime * 9 / 10;
#endif	
}

/* this should be called between subsongs when remote slave changes subsong */
void flush_sound (void)
{
  sndbufpt = sndbuffer;
}

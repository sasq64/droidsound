 /*
  * UAE - The Un*x Amiga Emulator
  *
  * Sound emulation stuff
  *
  * Copyright 1995, 1996, 1997 Bernd Schmidt
  */

#ifndef _UADE_AUDIO_H_
#define _UADE_AUDIO_H_


#define AUDIO_DEBUG 0


extern struct audio_channel_data {
    unsigned long adk_mask;
    unsigned long evtime;
    unsigned char dmaen, intreq2, data_written;
    uaecptr lc, pt;

    int state, wper, wlen;
    int current_sample, last_sample[3];
    int sample_accum, sample_accum_time;
    int vol;
    uae_u16 dat, nextdat, per, len;    

    /* Debug variables */
    uaecptr ptend, nextdatpt, nextdatptend, datpt, datptend;
} audio_channel[4];

extern void AUDxDAT (int nr, uae_u16 value);
extern void AUDxVOL (int nr, uae_u16 value);
extern void AUDxPER (int nr, uae_u16 value);
extern void AUDxLCH (int nr, uae_u16 value);
extern void AUDxLCL (int nr, uae_u16 value);
extern void AUDxLEN (int nr, uae_u16 value);

void audio_reset (void);
void select_audio_interpolator(char *name);
void update_audio (void);

#endif

 /*
  * UAE - The Un*x Amiga Emulator
  *
  * Prototypes for general sound related functions
  * This use to be called sound.h, but that causes confusion
  *
  * Copyright 1997 Bernd Schmidt
  */

extern int sound_available;

extern int sound_use_filter; /* if filter emulation is used, this is non-zero*/

extern void (*sample_handler) (void);
extern float sample_evtime_interval;

/* Determine if we can produce any sound at all.  This can be only a guess;
 * if unsure, say yes.  Any call to init_sound may change the value.  */
extern int setup_sound (void);

extern void init_sound (void);
extern void flush_sound (void);
extern void close_sound (void);

extern void sample16s_handler (void);
extern void sample16si_anti_handler(void);
extern void sample16si_crux_handler (void);
extern void sample16si_cspline_handler (void);
extern int sample16si_cspline_interpolate_one (int *, int, float);
extern void sample16si_handler (void);
extern void sample16si_linear_handler (void);

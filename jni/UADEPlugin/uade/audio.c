 /*
  * UADE's audio state machine emulation
  *
  * Copyright 1995, 1996, 1997 Bernd Schmidt
  * Copyright 1996 Marcus Sundberg
  * Copyright 1996 Manfred Thole
  * Copyright 2005 Heikki Orsila
  * Copyright 2005 Antti S. Lankila
  */

#include <math.h>

#include "sysconfig.h"
#include "sysdeps.h"

#include "options.h"
#include "include/memory.h"
#include "custom.h"
#include "gensound.h"
#include "sd-sound.h"
#include "events.h"
#include "cia.h"
#include "audio.h"
#include "amigafilter.h"
#include "uade.h"


struct audio_channel_data audio_channel[4];
static int cspline_old_samples[4];
void (*sample_handler) (void);

/* Average time in bus cycles to output a new sample */
float sample_evtime_interval;
static float next_sample_evtime;

int sound_available;

int sound_use_filter = FILTER_MODEL_A500E;

static unsigned long last_audio_cycles;

static int audperhack;

static struct filter_state {
    float rc1, rc2, rc3, rc4, rc5;
} sound_filter_state[2];

/* Amiga has two separate filtering circuits per channel, a static RC filter
 * on A500 and the LED filter. This code emulates both.
 * 
 * The Amiga filtering circuitry depends on Amiga model. Older Amigas seem
 * to have a 6 dB/oct RC filter with cutoff frequency such that the -6 dB
 * point for filter is reached at 6 kHz, while newer Amigas have no filtering.
 *
 * The LED filter is complicated, and we are modelling it with a pair of
 * RC filters, the other providing a highboost. The LED starts to cut
 * into signal somewhere around 5-6 kHz, and there's some kind of highboost
 * in effect above 12 kHz. Better measurements are required.
 *
 * The current filtering should be accurate to 2 dB with the filter on,
 * and to 1 dB with the filter off.
*/

static int filter(int input, struct filter_state *fs)
{
    int o;
    float tmp, normal_output, led_output;

    /* white noise generator for filter debugging
    data = 65535 * (drand48() - 0.5);
    */
    switch (sound_use_filter) {
        
    case FILTER_MODEL_A500: 
	tmp  = 0.36 * input;
	tmp += 0.64 * fs->rc1;
	fs->rc1 = tmp;
        normal_output = fs->rc1;
    
        /* lowpass */
        tmp  = 0.33 * normal_output;
        tmp += 0.67 * fs->rc2;
        fs->rc2 = tmp;

        /* highboost */
        tmp  = 1.35 * fs->rc2;
        tmp -= 0.35 * fs->rc3;
        fs->rc3 = tmp;
        led_output = fs->rc3 * 0.98;
        break;
        
    case FILTER_MODEL_A1200:
        normal_output = input;
        
        /* lowpass */
        tmp  = 0.33 * normal_output;
        tmp += 0.67 * fs->rc2;
        fs->rc2 = tmp;

        /* highboost */
        tmp  = 1.35 * fs->rc2;
        tmp -= 0.35 * fs->rc3;
        fs->rc3 = tmp;
        led_output = fs->rc3 * 0.98;
        break;

    case FILTER_MODEL_A500E:
	fs->rc1 = 0.52 * input   + 0.48 * fs->rc1;
	fs->rc2 = 0.92 * fs->rc1 + 0.08 * fs->rc2;
	normal_output = fs->rc2;

	fs->rc3 = 0.48 * normal_output + 0.52 * fs->rc3;
	fs->rc4 = 0.48 * fs->rc3       + 0.52 * fs->rc4;
	fs->rc5 = 0.48 * fs->rc4       + 0.52 * fs->rc5;

	led_output = fs->rc5;
        break;
        
    case FILTER_MODEL_A1200E:
        normal_output = input;

        fs->rc2 = 0.48 * normal_output + 0.52 * fs->rc2;
        fs->rc3 = 0.48 * fs->rc2       + 0.52 * fs->rc3;
        fs->rc4 = 0.48 * fs->rc3       + 0.52 * fs->rc4;

        led_output = fs->rc4;
        break;

    default:
	fprintf(stderr, "Unknown filter mode\n");
	exit(-1);
    }

    o = gui_ledstate ? led_output : normal_output;

    if (o > 32767) {
	o = 32767;
    } else if (o < -32768) {
	o = -32768;
    }

    return o;
}


static void check_sound_buffers (void)
{
    if (uade_reboot)
	return;
    assert(uade_read_size > 0);
    intptr_t bytes = ((intptr_t) sndbufpt) - ((intptr_t) sndbuffer);
    if (uade_audio_output) {
	if (bytes == uade_read_size) {
	    uade_check_sound_buffers(uade_read_size);
	    sndbufpt = sndbuffer;
	}
    } else {
	uade_audio_skip += bytes;
	/* if sound core doesn't report audio output start in 3 seconds from
	   the reboot, begin audio output anyway */
	if (uade_audio_skip >= (sound_bytes_per_second * 3)) {
	    fprintf(stderr, "involuntary audio output start\n");
	    uade_audio_output = 1;
	}
	sndbufpt = sndbuffer;
    }
}


static inline void sample_backend(int left, int right)
{
#if AUDIO_DEBUG
    int nr;
    for (nr = 0; nr < 4; nr++) {
	struct audio_channel_data *cdp = audio_channel + nr;
	if (cdp->state != 0 && cdp->datpt != 0 && (dmacon & (1 << nr)) && cdp->datpt >= cdp->datptend) {
	    fprintf(stderr, "Audio output overrun on channel %d: %.8x/%.8x\n", nr, cdp->datpt, cdp->datptend);
	}
    }
#endif

    /* samples are in range -16384 (-128*64*2) and 16256 (127*64*2) */
    left <<= 16 - 14 - 1;
    right <<= 16 - 14 - 1;
    /* [-32768, 32512] */

    if (sound_use_filter) {
	left = filter(left, &sound_filter_state[0]);
	right = filter(right, &sound_filter_state[1]);
    }

    *(sndbufpt++) = left;
    *(sndbufpt++) = right;

    check_sound_buffers();
}


void sample16s_handler (void)
{
    int datas[4];
    int i;

    for (i = 0; i < 4; i++) {
	datas[i] = audio_channel[i].current_sample * audio_channel[i].vol;
	datas[i] &= audio_channel[i].adk_mask;
    }

    sample_backend(datas[0] + datas[3], datas[1] + datas[2]);
}


/* This interpolator examines sample points when Paula switches the output
 * voltage and computes the average of Paula's output */
void sample16si_anti_handler (void)
{
    int i;
    int datas[4];

    for (i = 0; i < 4; i += 1) {
        datas[i] = audio_channel[i].sample_accum / audio_channel[i].sample_accum_time;
        audio_channel[i].sample_accum = 0;
	audio_channel[i].sample_accum_time = 0;
    }

    sample_backend(datas[0] + datas[3], datas[1] + datas[2]);
}


static void audio_handler (int nr)
{
    struct audio_channel_data *cdp = audio_channel + nr;

    switch (cdp->state) {
     case 0:
	fprintf(stderr, "Bug in sound code\n");
	break;

     case 1:
	/* We come here at the first hsync after DMA was turned on. */
	cdp->evtime = maxhpos;

	cdp->state = 5;
	INTREQ(0x8000 | (0x80 << nr));
	if (cdp->wlen != 1)
	    cdp->wlen = (cdp->wlen - 1) & 0xFFFF;
	cdp->nextdat = chipmem_bank.wget(cdp->pt);

	cdp->nextdatpt = cdp->pt;
	cdp->nextdatptend = cdp->ptend;

	/* BUG in UAE. Only hsync handler should increase DMA pointer
	   cdp->pt += 2;
	*/
	break;

     case 5:
	/* We come here at the second hsync after DMA was turned on. */
	cdp->evtime = cdp->per;
	cdp->dat = cdp->nextdat;

	cdp->datpt = cdp->nextdatpt;
	cdp->datptend = cdp->nextdatptend;

        cdp->last_sample[2] = cdp->last_sample[1];
        cdp->last_sample[1] = cdp->last_sample[0];
	cdp->last_sample[0] = cdp->current_sample;
	cdp->current_sample = (uae_s8)(cdp->dat >> 8);

	cdp->state = 2;
	{
	    int audav = adkcon & (1 << nr);
	    int audap = adkcon & (16 << nr);
	    int napnav = (!audav && !audap) || audav;
	    if (napnav)
		cdp->data_written = 2;
	}
	break;

     case 2:
	/* We come here when a 2->3 transition occurs */
	cdp->last_sample[2] = cdp->last_sample[1];
	cdp->last_sample[1] = cdp->last_sample[0];
	cdp->last_sample[0] = cdp->current_sample;
	cdp->current_sample = (uae_s8)(cdp->dat & 0xFF);
	cdp->evtime = cdp->per;

	cdp->state = 3;

	/* Period attachment? */
	if (adkcon & (0x10 << nr)) {
	    if (cdp->intreq2 && cdp->dmaen) {
		INTREQ(0x8000 | (0x80 << nr));
	    }
	    cdp->intreq2 = 0;

	    cdp->dat = cdp->nextdat;

	    cdp->datpt = cdp->nextdatpt;
	    cdp->datptend = cdp->nextdatptend;

	    if (cdp->dmaen)
		cdp->data_written = 2;
	    if (nr < 3) {
		if (cdp->dat == 0)
		    (cdp+1)->per = 65535;
		else
		    (cdp+1)->per = cdp->dat;
	    }
	}
	break;

     case 3:
	/* We come here when a 3->2 transition occurs */
	cdp->evtime = cdp->per;

	if ((INTREQR() & (0x80 << nr)) && !cdp->dmaen) {
	    cdp->state = 0;
	    cdp->last_sample[2] = 0;
	    cdp->last_sample[1] = 0;
	    cdp->last_sample[0] = 0;
	    cdp->current_sample = 0;
	    break;
	} else {
	    int audav = adkcon & (1 << nr);
	    int audap = adkcon & (16 << nr);
	    int napnav = (!audav && !audap) || audav;
	    cdp->state = 2;

	    if ((cdp->intreq2 && cdp->dmaen && napnav)
		|| (napnav && !cdp->dmaen)) {
	      INTREQ(0x8000 | (0x80 << nr));
	    }
	    cdp->intreq2 = 0;

	    cdp->dat = cdp->nextdat;

	    cdp->datpt = cdp->nextdatpt;
	    cdp->datptend = cdp->nextdatptend;

            cdp->last_sample[2] = cdp->last_sample[1];
            cdp->last_sample[1] = cdp->last_sample[0];
            cdp->last_sample[0] = cdp->current_sample;
	    cdp->current_sample = (uae_s8)(cdp->dat >> 8);

	    if (cdp->dmaen && napnav)
		cdp->data_written = 2;

	    /* Volume attachment? */
	    if (audav) {
		if (nr < 3) {
		    (cdp+1)->vol = cdp->dat;
		}
	    }
	}
	break;

     default:
	cdp->state = 0;
	break;
    }
}


void audio_reset (void)
{
    memset (audio_channel, 0, sizeof audio_channel);
    audio_channel[0].per = 65535;
    audio_channel[1].per = 65535;
    audio_channel[2].per = 65535;
    audio_channel[3].per = 65535;

    last_audio_cycles = 0;
    next_sample_evtime = sample_evtime_interval;

    audperhack = 0;

    memset(sound_filter_state, 0, sizeof sound_filter_state);
    memset(cspline_old_samples, 0, sizeof cspline_old_samples);

    select_audio_interpolator(NULL);
}


static int sound_prefs_changed (void)
{
    return (changed_prefs.produce_sound != currprefs.produce_sound
	    || changed_prefs.stereo != currprefs.stereo
	    || changed_prefs.sound_freq != currprefs.sound_freq
	    || changed_prefs.sound_bits != currprefs.sound_bits);
}


void check_prefs_changed_audio (void)
{
    if (sound_available && sound_prefs_changed ()) {
	close_sound ();

	currprefs.produce_sound = changed_prefs.produce_sound;
	currprefs.stereo = changed_prefs.stereo;
	currprefs.sound_bits = changed_prefs.sound_bits;
	currprefs.sound_freq = changed_prefs.sound_freq;

	init_sound ();
	last_audio_cycles = cycles - 1;
	next_sample_evtime = sample_evtime_interval;
    }
}


void select_audio_interpolator(char *name)
{
  /* This is the new system (a user should give the interpolation mode as a
     human-readable string) */
  if (name == NULL || strcasecmp(name, "default") == 0) {
    sample_handler = sample16s_handler;
  } else if (strcasecmp(name, "anti") == 0) {
    sample_handler = sample16si_anti_handler;
  } else {
    sample_handler = sample16s_handler;
    fprintf(stderr, "\nUnknown interpolation mode: %s. Using default.\n", name);
  }
}


/* update_audio() emulates actions of audio state machine since it was last
   time called. One can assume it is called at least once per horizontal
   line and possibly more often. */
void update_audio (void)
{
    /* Number of cycles that has passed since last call to update_audio() */
    unsigned long n_cycles = cycles - last_audio_cycles;

    while (n_cycles > 0) {
	unsigned long best_evtime = n_cycles + 1;
	int i;
	unsigned long rounded;
	float f;

	for (i = 0; i < 4; i++) {
	    if (audio_channel[i].state != 0 && best_evtime > audio_channel[i].evtime)
		best_evtime = audio_channel[i].evtime;
	}

	/* next_sample_evtime >= 0 so floor() behaves as expected */
	rounded = floorf(next_sample_evtime);
	if ((next_sample_evtime - rounded) >= 0.5)
	    rounded++;

	if (best_evtime > rounded)
	    best_evtime = rounded;

	if (best_evtime > n_cycles)
	    best_evtime = n_cycles;

	/* Decrease time-to-wait counters */
	next_sample_evtime -= best_evtime;

	for (i = 0; i < 4; i++) {
	    int output = (audio_channel[i].current_sample * audio_channel[i].vol) & audio_channel[i].adk_mask;
	    audio_channel[i].sample_accum += output * best_evtime;
	    audio_channel[i].sample_accum_time += best_evtime;
	    audio_channel[i].evtime -= best_evtime;
	}

	n_cycles -= best_evtime;

	/* Test if new sample needs to be outputted */
	if (rounded == best_evtime) {
	    /* Before the following addition, next_sample_evtime is in range
	       [-0.5, 0.5) */
	    next_sample_evtime += sample_evtime_interval;
	    (*sample_handler) ();
	}

	/* Call audio state machines if needed */
	for (i = 0; i < 4; i++) {
	    if (audio_channel[i].evtime == 0 && audio_channel[i].state != 0)
		audio_handler(i);
	}
    }

    last_audio_cycles = cycles - n_cycles;
}


void AUDxDAT (int nr, uae_u16 v)
{
    struct audio_channel_data *cdp = audio_channel + nr;

    update_audio ();

    cdp->dat = v;
    cdp->datpt = 0;

    if (cdp->state == 0 && !(INTREQR() & (0x80 << nr))) {
	cdp->state = 2;
	INTREQ(0x8000 | (0x80 << nr));
	/* data_written = 2 ???? */
	cdp->evtime = cdp->per;
    }
}


void AUDxLCH (int nr, uae_u16 v)
{
    update_audio ();

    audio_channel[nr].lc = (audio_channel[nr].lc & 0xffff) | ((uae_u32)v << 16);
}


void AUDxLCL (int nr, uae_u16 v)
{
    update_audio ();

    audio_channel[nr].lc = (audio_channel[nr].lc & ~0xffff) | (v & 0xFFFE);
}


void AUDxPER (int nr, uae_u16 v)
{
    update_audio ();

    if (v == 0)
	v = 65535;
    else if (v < 16) {
	/* With the risk of breaking super-cool players,
	   we limit the value to 16 to save cpu time on not so powerful
	   machines. robocop customs use low values for example. */
	if (!audperhack) {
	    audperhack = 1;
	    uade_send_debug("Eagleplayer inserted %d into aud%dper.", v, nr);
	}
	v = 16;
    }
    audio_channel[nr].per = v;
}


void AUDxLEN (int nr, uae_u16 v)
{
    update_audio ();

    audio_channel[nr].len = v;
}


void AUDxVOL (int nr, uae_u16 v)
{
    int v2 = v & 64 ? 63 : v & 63;

    update_audio ();

    audio_channel[nr].vol = v2;
}

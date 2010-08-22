/* Effect module for UADE2 frontends.

   Copyright 2005 (C) Antti S. Lankila <alankila@bel.fi>

   This module is licensed under the GNU LGPL.
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "effects.h"


static float headphones_ap_l[UADE_EFFECT_HEADPHONES_DELAY_LENGTH];
static float headphones_ap_r[UADE_EFFECT_HEADPHONES_DELAY_LENGTH];
static float headphones_rc_l[4];
static float headphones_rc_r[4];

static void gain(int gain_amount, int16_t *sm, int frames);
static void pan(int pan_amount, int16_t *sm, int frames);
static void headphones(int16_t *sm, int frames);


/* Reset effects' state variables.
 * Call this method between before starting playback */
void uade_effect_reset_internals(void)
{
    memset(headphones_ap_l, 0, sizeof(headphones_ap_l));
    memset(headphones_ap_r, 0, sizeof(headphones_ap_r));
    memset(headphones_rc_l, 0, sizeof(headphones_rc_l));
    memset(headphones_rc_r, 0, sizeof(headphones_rc_r));
}


void uade_effect_disable_all(struct uade_effect *ue)
{
    ue->enabled = 0;
}


void uade_effect_disable(struct uade_effect *ue, uade_effect_t effect)
{
    ue->enabled &= ~(1 << effect);
}


void uade_effect_enable(struct uade_effect *ue, uade_effect_t effect)
{
    ue->enabled |= 1 << effect;
}


/* Returns 1 if effect is enabled, and zero otherwise. Ignores
   UADE_EFFECT_ALLOW. */
int uade_effect_is_enabled(struct uade_effect *ue, uade_effect_t effect)
{
    return  (ue->enabled & (1 << effect)) != 0;
}


void uade_effect_run(struct uade_effect *ue, int16_t *samples, int frames)
{
    if (ue->enabled & (1 << UADE_EFFECT_ALLOW)) {
	if (ue->enabled & (1 << UADE_EFFECT_PAN))
	    pan(ue->pan, samples, frames);
	if (ue->enabled & (1 << UADE_EFFECT_HEADPHONES))
	    headphones(samples, frames);
	if (ue->enabled & (1 << UADE_EFFECT_GAIN))
	    gain(ue->gain, samples, frames);
    }
}


void uade_effect_toggle(struct uade_effect *ue, uade_effect_t effect)
{
    ue->enabled ^= 1 << effect;
}


void uade_effect_set_defaults(struct uade_effect *ue)
{
    uade_effect_disable_all(ue);
    uade_effect_enable(ue, UADE_EFFECT_ALLOW);
    uade_effect_gain_set_amount(ue, 1.0);
    uade_effect_pan_set_amount(ue, 0.7);
}


void uade_effect_gain_set_amount(struct uade_effect *ue, float amount)
{
    assert(amount >= 0.0 && amount <= 128.0);
    ue->gain = amount * 256.0;
}


void uade_effect_pan_set_amount(struct uade_effect *ue, float amount)
{
    assert(amount >= 0.0 && amount <= 2.0);
    ue->pan = amount * 256.0 / 2.0;
}


static void gain(int gain_amount, int16_t *sm, int frames)
{
    int i;
    for (i = 0; i < 2 * frames;  i+= 1)
	sm[i] = (sm[i] * gain_amount) >> 8;
}


/* Panning effect. Turns stereo into mono in a specific degree */
static void pan(int pan_amount, int16_t *sm, int frames)
{
  int i, l, r, m;
  for (i = 0; i < frames; i += 1) {
    l = sm[0];
    r = sm[1];
    m = (r - l) * pan_amount;
    sm[0] = ( ((l << 8) + m) >> 8 );
    sm[1] = ( ((r << 8) - m) >> 8 );
    sm += 2;
  }
}

/* All-pass delay. Its purpose is to confuse the phase of the sound a bit
 * and also provide some delay to locate the source outside the head. This
 * seems to work better than a pure delay line. */
static float headphones_allpass_delay(float in, float *state)
{
    int i;
    float tmp, output;

    tmp = in - UADE_EFFECT_HEADPHONES_DELAY_DIRECT * state[0];
    output = state[0] + UADE_EFFECT_HEADPHONES_DELAY_DIRECT * tmp;

    /* FIXME: use modulo and index */
    for (i = 1; i < UADE_EFFECT_HEADPHONES_DELAY_LENGTH; i += 1)
        state[i - 1] = state[i];
    state[UADE_EFFECT_HEADPHONES_DELAY_LENGTH - 1] = tmp;

    return output;
}

static float headphones_lpf(float in, float *state)
{
    float out = in * 0.53;
    out += 0.47 * state[0];
    state[0] = out;

    return out;
}

/* A real implementation would simply perform FIR with recorded HRTF data. */
static void headphones(int16_t *sm, int frames)
{
    int i;
    for (i = 0; i < frames; i += 1) {
	float ld = headphones_allpass_delay(sm[0], headphones_ap_l);
	float rd = headphones_allpass_delay(sm[1], headphones_ap_r);
	ld = headphones_lpf(ld, headphones_rc_l);
	rd = headphones_lpf(rd, headphones_rc_r);

	int l_final = (sm[0] + rd * UADE_EFFECT_HEADPHONES_CROSSMIX_VOL) / 2;
	int r_final = (sm[1] + ld * UADE_EFFECT_HEADPHONES_CROSSMIX_VOL) / 2;

        if (l_final > 32767)
            l_final = 32767;
        if (l_final < -32768)
            l_final = -32768;
        if (r_final > 32767)
            r_final = 32767;
        if (r_final < -32768)
            r_final = -32768;
        sm[0] = l_final;
        sm[1] = r_final;
        
	sm += 2;
    }
}


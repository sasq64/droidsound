#ifndef _UADE2_EFFECTS_H_
#define _UADE2_EFFECTS_H_

#include <uade/uade.h>

#include <stdint.h>

typedef enum {
	UADE_EFFECT_ALLOW,
	UADE_EFFECT_GAIN,
	UADE_EFFECT_HEADPHONES,
	UADE_EFFECT_HEADPHONES2,
	UADE_EFFECT_PAN,
} uade_effect_t;

typedef struct {
	float b0;
	float b1;
	float b2;
	float a1;
	float a2;
	float x[2];
	float y[2];
} uade_biquad_t;

#define UADE_EFFECT_HEADPHONES_DELAY_LENGTH 22

#define HEADPHONE2_DELAY_TIME 0.49e-3
#define MAXIMUM_SAMPLING_RATE 96000

/*
 * HEADPHONE2_DELAY_MAX_LENGTH ==
 * (int) (MAXIMUM_SAMPLING_RATE*HEADPHONE2_DELAY_TIME + 1).
 * Note: (int) (0.49e-3 * 96000 + 1) == 48. The value is asserted in code.
 * The assert fails if the next #define is not updated properly for new values.
 */
#define HEADPHONE2_DELAY_MAX_LENGTH 48

struct uade_effect_state {
	uade_effect_t enabled;
	int gain;
	int pan;
	int rate;

	/* Headphone variables */
	float headphones_ap_l[UADE_EFFECT_HEADPHONES_DELAY_LENGTH];
	float headphones_ap_r[UADE_EFFECT_HEADPHONES_DELAY_LENGTH];
	float headphones_rc_l[4];
	float headphones_rc_r[4];

	float headphone2_ap_l[HEADPHONE2_DELAY_MAX_LENGTH];
	float headphone2_ap_r[HEADPHONE2_DELAY_MAX_LENGTH];
	int headphone2_delay_length;
	uade_biquad_t headphone2_shelve_l;
	uade_biquad_t headphone2_shelve_r;
	uade_biquad_t headphone2_rc_l;
	uade_biquad_t headphone2_rc_r;
};

void uade_effect_disable(struct uade_effect_state *es, uade_effect_t effect);
void uade_effect_disable_all(struct uade_effect_state *es);
void uade_effect_enable(struct uade_effect_state *es, uade_effect_t effect);
int uade_effect_is_enabled(struct uade_effect_state *es, uade_effect_t effect);
void uade_effect_set_defaults(struct uade_effect_state *es);
void uade_effect_set_sample_rate(struct uade_effect_state *es, int rate);
void uade_effect_toggle(struct uade_effect_state *es, uade_effect_t effect);

/* effect-specific knobs */
void uade_effect_gain_set_amount(struct uade_effect_state *es, float amount);
void uade_effect_pan_set_amount(struct uade_effect_state *es, float amount);

/* reset state at start of song */
void uade_effect_reset_internals(struct uade_effect_state *es);

/* process n frames of sample buffer */
void uade_effect_run(struct uade_effect_state *es, int16_t * sample, int frames);

#endif

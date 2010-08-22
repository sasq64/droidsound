#ifndef _UADE2_EFFECTS_H_
#define _UADE2_EFFECTS_H_

#include <stdint.h>

typedef enum {
    UADE_EFFECT_ALLOW,
    UADE_EFFECT_GAIN,
    UADE_EFFECT_HEADPHONES,
    UADE_EFFECT_PAN,
} uade_effect_t;

struct uade_effect {
    uade_effect_t enabled;
    int gain;
    int pan;
};


void uade_effect_disable(struct uade_effect *ue, uade_effect_t effect);
void uade_effect_disable_all(struct uade_effect *ue);
void uade_effect_enable(struct uade_effect *ue, uade_effect_t effect);
int uade_effect_is_enabled(struct uade_effect *ue, uade_effect_t effect);
void uade_effect_toggle(struct uade_effect *ue, uade_effect_t effect);


/* effect-specific knobs */
void uade_effect_set_defaults(struct uade_effect *ue);
void uade_effect_gain_set_amount(struct uade_effect *ue, float amount);
void uade_effect_pan_set_amount(struct uade_effect *ue, float amount);

/* reset state at start of song */
void uade_effect_reset_internals(void);

/* process n frames of sample buffer */
void uade_effect_run(struct uade_effect *ue, int16_t *sample, int frames);

#define UADE_EFFECT_HEADPHONES_DELAY_LENGTH 22
#define UADE_EFFECT_HEADPHONES_DELAY_DIRECT 0.3
#define UADE_EFFECT_HEADPHONES_CROSSMIX_VOL 0.80

#endif

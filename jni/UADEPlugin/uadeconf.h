#ifndef _UADE_FRONTEND_CONFIG_H_
#define _UADE_FRONTEND_CONFIG_H_

#include <amigafilter.h>

struct uade_config {
  int action_keys;
  int always_ends;
  int filter_type;
  int led_forced;
  int led_state;
  int gain_enable;
  float gain; /* should be removed of uade_effect integrated */
  int headphones;
  int ignore_player_check;
  char *interpolator;
  int no_filter;
  int no_song_end;
  int one_subsong;
  int panning_enable;
  float panning; /* should be removed */
  int random_play;
  int recursive_mode;
  int silence_timeout;
  int speed_hack;
  int subsong_timeout;
  int timeout;
  int timeout_forced;
};

void uade_config_set_defaults(struct uade_config *uc);
int uade_get_filter_type(const char *value);
int uade_get_silence_timeout(const char *value);
int uade_get_subsong_timeout(const char *value);
int uade_get_timeout(const char *value);
double uade_convert_to_double(const char *value,
			      double def,
			      double low, double high, const char *type);
int uade_load_config(struct uade_config *uc, const char *filename);

#endif

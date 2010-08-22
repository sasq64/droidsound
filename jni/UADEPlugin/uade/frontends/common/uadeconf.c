/* uade123 - a simple command line frontend for uadecore.

   Copyright (C) 2005 Heikki Orsila <heikki.orsila@iki.fi>

   This source code module is dual licensed under GPL and Public Domain.
   Hence you may use _this_ module (not another code module) in any way you
   want in your projects.
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include <limits.h>
#include <unistd.h>

#include <strlrep.h>

#include "uadeconf.h"


static char config_filename[PATH_MAX];


static char *nextspace(const char *foo)
{
  while (foo[0] != 0 && !isspace(foo[0]))
    foo++;
  if (foo[0] == 0)
    return NULL;
  return (char *) foo;
}


static char *nextnonspace(const char *foo)
{
  while (foo[0] != 0 && isspace(foo[0]))
    foo++;
  if (foo[0] == 0)
    return NULL;
  return (char *) foo;
}


void uade_config_set_defaults(struct uade_config *uc)
{
  memset(uc, 0, sizeof(*uc));
  uc->action_keys = 1;
  uc->filter_type = uade_get_filter_type(NULL);
  uc->gain = 1.0;
  uc->panning = 0.7;
  uc->silence_timeout = 20;
  uc->subsong_timeout = 512;
  uc->timeout = -1;
}


int uade_get_filter_type(const char *model)
{
  int filter = FILTER_MODEL_A500E;

  if (model == NULL)
    return filter;

  if (strcasecmp(model, "a500") == 0) {
    filter = FILTER_MODEL_A500;
  } else if (strcasecmp(model, "a1200") == 0) {
    filter = FILTER_MODEL_A1200;
  } else if (strcasecmp(model, "a500e") == 0) {
    filter = FILTER_MODEL_A500E;
  } else if (strcasecmp(model, "a1200e") == 0) {
    filter = FILTER_MODEL_A1200E;
  } else {
    fprintf(stderr, "Unknown filter model: %s\n", model);
  }

  return filter;
}


int uade_get_silence_timeout(const char *value)
{
  char *endptr;
  int t;
  if (value == NULL || value[0] == 0) {
    fprintf(stderr, "Must have a parameter value for silence timeout in config file %s\n", config_filename);
    return -1;
  }
  t = strtol(value, &endptr, 10);
  if (*endptr != 0 || t < -1) {
    fprintf(stderr, "Invalid silence timeout value: %s\n", value);
    t = -1;
  }
  return t;
}


int uade_get_subsong_timeout(const char *value)
{
  char *endptr;
  int t;
  if (value == NULL || value[0] == 0) {
    fprintf(stderr, "Must have a parameter value for subsong timeout in config file %s\n", config_filename);
    return -1;
  }
  t = strtol(value, &endptr, 10);
  if (*endptr != 0 || t < -1) {
    fprintf(stderr, "Invalid subsong timeout value: %s\n", value);
    t = -1;
  }
  return t;
}


int uade_get_timeout(const char *value)
{
  char *endptr;
  int t;
  if (value == NULL) {
    fprintf(stderr, "Must have a parameter value for timeout value in config file %s\n", config_filename);
    return -1;
  }
  t = strtol(value, &endptr, 10);
  if (*endptr != 0 || t < -1) {
    fprintf(stderr, "Invalid timeout value: %s\n", value);
    t = -1;
  }
  return t;
}


double uade_convert_to_double(const char *value, double def, double low, double high, const char *type)
{
  char *endptr;
  double v;
  if (value == NULL) {
    fprintf(stderr, "Must have a parameter value for %s in config file %s\n", config_filename, type);
    return def;
  }
  v = strtod(value, &endptr);
  if (*endptr != 0 || v < low || v > high) {
    fprintf(stderr, "Invalid %s value: %s\n", type, value);
    v = def;
  }
  return v;
}


int uade_load_config(struct uade_config *uc, const char *filename)
{
  char line[256];
  FILE *f;
  char *key;
  char *value;
  int linenumber = 0;

  if ((f = fopen(filename, "r")) == NULL)
    return 0;

  strlcpy(config_filename, filename, sizeof config_filename);

  while (fgets(line, sizeof(line), f) != NULL) {
    linenumber++;
    if (line[strlen(line) - 1] == '\n')
      line[strlen(line) - 1] = 0;
    if (line[0] == 0)
      continue;
    if (line[0] == '#')
      continue;
    key = line;
    value = nextspace(key);
    if (value != NULL) {
      *value = 0;
      value = nextnonspace(value + 1);
    }
    if (strncmp(key, "action_keys", 6) == 0) {
      if (value != NULL) {
	if (strcasecmp(value, "on") == 0) {
	  uc->action_keys = 1;
	} else if (strcasecmp(value, "off") == 0) {
	  uc->action_keys = 0;
	} else {
	  fprintf(stderr, "uade.conf: Unknown setting for action keys: %s\n", value);
	}
      }
    } else if (strncmp(key, "filter", 6) == 0) {
      uc->filter_type = uade_get_filter_type(value);
      uc->no_filter = 0;
    } else if (strncmp(key, "force_led_off", 12) == 0) {
      uc->led_forced = 1;
      uc->led_state = 0;
    } else if (strncmp(key, "force_led_on", 12) == 0) {
      uc->led_forced = 1;
      uc->led_state = 1;
    } else if (strcmp(key, "gain") == 0) {
      uc->gain = uade_convert_to_double(value, 1.0, 0.0, 128.0, "gain");
      uc->gain_enable = 1;
    } else if (strncmp(key, "headphones", 4) == 0) {
      uc->headphones = 1;
    } else if (strncmp(key, "ignore_player_check", 6) == 0) {
      uc->ignore_player_check = 1;
    } else if (strncmp(key, "interpolator", 5) == 0) {
      if (value == NULL) {
	fprintf(stderr, "uade.conf: No interpolator given.\n");
      } else {
	uc->interpolator = strdup(value);
      }
    } else if (strncmp(key, "no_filter", 9) == 0) {
      uc->filter_type = 0;
      uc->no_filter = 1;
    } else if (strncmp(key, "one_subsong", 3) == 0) {
      uc->one_subsong = 1;
    } else if (strncmp(key, "panning_value", 3) == 0) {
      uc->panning = uade_convert_to_double(value, 0.0, 0.0, 2.0, "panning");
      uc->panning_enable = 1;
    } else if (strncmp(key, "random_play", 6) == 0) {
      uc->random_play = 1;
    } else if (strncmp(key, "recursive_mode", 9) == 0) {
      uc->recursive_mode = 1;
    } else if (strncmp(key, "silence_timeout_value", 7) == 0) {
      uc->silence_timeout = uade_get_silence_timeout(value);
    } else if (strncmp(key, "subsong_timeout_value", 7) == 0) {
      uc->subsong_timeout = uade_get_subsong_timeout(value);
    } else if (strncmp(key, "timeout_value", 7) == 0) {
      uc->timeout = uade_get_timeout(value);
    } else {
      fprintf(stderr, "Unknown config key in %s on line %d: %s\n", filename, linenumber, key);
    }
  }

  fclose(f);
  return 1;
}

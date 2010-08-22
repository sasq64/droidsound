#ifndef _UADE123_PLAYLIST_H_
#define _UADE123_PLAYLIST_H_

#include <stdio.h>
#include <stdlib.h>

#include "chrarray.h"

struct playlist {
  int valid;
  int lower_bound;
  int upper_bound;
  int randomize;
  int repeat;
  struct chrarray list;
};

int playlist_init(struct playlist *pl);
int playlist_random(struct playlist *pl, int enable);
void playlist_repeat(struct playlist *pl);
int playlist_empty(struct playlist *pl);
int playlist_add(struct playlist *pl, const char *name, int recursive);
int playlist_get_next(char *name, size_t maxlen, struct playlist *pl);
void playlist_flush(struct playlist *pl);

#endif

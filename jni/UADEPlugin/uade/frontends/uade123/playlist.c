/* Copyright (C) Heikki Orsila 2003-2005
   email: heikki.orsila@iki.fi
   License: LGPL and GPL
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>

#include <unixwalkdir.h>
#include <uadeconfig.h>
#include <unixatomic.h>

#include "playlist.h"
#include "uade123.h"


static int random_fd = -1;
#ifdef UADE_CONFIG_HAVE_URANDOM
static int using_urandom = 1;
#else
static int using_urandom = 0;
#endif


static void random_init(void)
{
  if (using_urandom == 0)
    srandom(time(NULL));
}


static int get_random(int max)
{
  int ret;
  uint8_t buf[4];
  if (using_urandom) {
    if (random_fd == -1) {
      random_fd = open("/dev/urandom", O_RDONLY);
      if (random_fd < 0) {
	fprintf(stderr, "not using urandom anymore: %s\n", strerror(errno));
	using_urandom = 0;
	goto nourandom;
      }
    }
    ret = atomic_read(random_fd, buf, sizeof(buf));
    if (ret < 0) {
      fprintf(stderr, "error on reading urandom: %s\n", strerror(errno));
      using_urandom = 0;
      goto nourandom;
    } else if (ret == 0) {
      fprintf(stderr, "unexpected eof on urandom\n");
      using_urandom = 0;
      goto nourandom;
    }
    return ((double) max) * ((* (uint32_t * ) buf) & 0x3fffffff) / 0x40000000;
  }
 nourandom:
  return ((double) max) * random() / (RAND_MAX + 1.0);
}


int playlist_init(struct playlist *pl)
{
  int ret;
  pl->lower_bound = 0;
  pl->upper_bound = 0;
  pl->randomize = 0;
  pl->repeat = 0;
  ret = chrarray_init(&pl->list);
  pl->valid = ret ? 1 : 0;
  random_init();
  return ret;
}


/* enable == 0: disable random play
   enable == 1: enable random play
   enable == -1: toggle random play state between enabled and disabled */
int playlist_random(struct playlist *pl, int enable)
{
  if (enable < 0) {
    pl->randomize = pl->randomize ? 0 : 1;
  } else {
    pl->randomize = enable ? 1 : 0;
  }
  return pl->randomize;
}


void playlist_repeat(struct playlist *pl)
{
  pl->repeat = 1;
}


int playlist_empty(struct playlist *pl)
{
  if (!pl->valid) {
    fprintf(stderr, "playlist invalid\n");
    return 1;
  }
  if (!pl->list.n_entries)
    return 1;
  if (pl->repeat)
    return 0;
  if (pl->randomize) {
    return pl->upper_bound == 0;
  } else {
    return pl->lower_bound == pl->list.n_entries;
  }
}


static void *recursive_func(const char *file, enum uade_wtype wtype, void *pl)
{
  if (wtype == UADE_WALK_REGULAR_FILE) {
    if (!playlist_add(pl, file, 0))
      fprintf(stderr, "error enqueuing %s\n", file);
  }
  return NULL;
}


int playlist_add(struct playlist *pl, const char *name, int recursive)
{
  int ret = 0;
  struct stat st;

  if (!pl->valid)
    return 0;

  if (stat(name, &st))
    return 0;

  if (S_ISREG(st.st_mode)) {
    /* fprintf(stderr, "enqueuing regular: %s\n", name); */
    ret = chrarray_add(&pl->list, name, strlen(name) + 1);
  } else if (S_ISDIR(st.st_mode)) {
    /* add directories to playlist only if 'recursive' is non-zero */
    if (recursive) {

      /* strip directory name of ending '/' characters */
      char *strippedname = strdup(name);
      size_t len = strlen(name);
      if (strippedname == NULL) {
	fprintf(stderr, "Not enough memory for directory name.\n");
	exit(-1);
      }
      while (len > 0) {
	len--;
	if (strippedname[len] != '/')
	  break;
	strippedname[len] = 0;
      }

      /* walk directory hierarchy */
      uade_walk_directories(strippedname, recursive_func, pl);

      /* free stripped name */
      free(strippedname);

    } else {
      debug("Not adding directory %s. Use -r to add recursively.\n", name);
    }
    ret = 1;
  }

  pl->upper_bound = pl->list.n_entries;
  return ret;
}


int playlist_get_next(char *name, size_t maxlen, struct playlist *pl)
{
  int len;
  char *s;
  if (!pl->valid)
    return 0;
  if (!pl->list.n_entries)
    return 0;
  if (!maxlen) {
    fprintf(stderr, "uade123: playlist_get_next(): given maxlen = 0\n");
    return 0;
  }

  if (pl->randomize) {
    int i;
    struct chrentry t;
    /* take a random entry from chrarray. basically this suffles an entry
       from a random position to the tail of the array */
    if (!pl->upper_bound) {
      if (!pl->repeat)
	return 0;
      pl->upper_bound = pl->list.n_entries;
    }
    i = get_random(pl->upper_bound);
    t = pl->list.entries[i];
    if (i != (pl->upper_bound - 1)) {
      /* not end of the list => need to shuffle (swap places) */
      pl->list.entries[i] = pl->list.entries[pl->upper_bound - 1];
      pl->list.entries[pl->upper_bound - 1] = t;
    }
    s = &pl->list.data[t.off];
    len = t.len;
    /* decrease upper_bound. the entry chosen this time is at the tail, so
       it won't be chosen next time (unless if upper_bound is increased
       due to repeat) */
    pl->upper_bound--;

  } else {

    /* non-random pick. take the first from the list, and increase
       lower_bound (unless we are repeating this time) */
    if (pl->lower_bound == pl->list.n_entries) {
      if (!pl->repeat) {
	return 0;
      }
      pl->lower_bound = 0;
    }
    s = &pl->list.data[pl->list.entries[pl->lower_bound].off];
    len = pl->list.entries[pl->lower_bound].len;
    pl->lower_bound++;
  }
  if (len > maxlen) {
    fprintf(stderr, "uade: playlist_get_next(): too long a string: %s\n", s);
    return 0;
  }
  memcpy(name, s, len);
  return 1;
}


void playlist_flush(struct playlist *pl)
{
  chrarray_flush(&pl->list);
}

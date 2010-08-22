#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <strlrep.h>

#include "players.h"

/* This is called when an eagleplayer queries for attributes. The query result
   is returned through 'dst', and the result is at most maxlen bytes long.
   'src' contains the full query. */
int uade_get_info(char *dst, char *src, int maxlen)
{
  if (strcasecmp(src, "VBLANK") == 0) {
    int ret = strlcpy(dst, "No", maxlen);
    /* Return the amount of bytes that a full result needs */
    return ret + 1;
  }
  return -1;
}

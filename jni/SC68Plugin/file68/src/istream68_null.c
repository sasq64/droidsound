/*
 *                        file68 - Null stream
 *            Copyright (C) 2001-2009 Ben(jamin) Gerard
 *           <benjihan -4t- users.sourceforge -d0t- net>
 *
 * This  program is  free  software: you  can  redistribute it  and/or
 * modify  it under the  terms of  the GNU  General Public  License as
 * published by the Free Software  Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT  ANY  WARRANTY;  without   even  the  implied  warranty  of
 * MERCHANTABILITY or  FITNESS FOR A PARTICULAR PURPOSE.   See the GNU
 * General Public License for more details.
 *
 * You should have  received a copy of the  GNU General Public License
 * along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 */

/* $Id$ */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include "file68_api.h"
#include "istream68_null.h"

/* define this if you don't want NULL support. */
#ifndef ISTREAM68_NO_NULL

#include "istream68_def.h"
#include "alloc68.h"

#include <string.h>

/** istream file structure. */
typedef struct {
  istream68_t istream; /**< istream function.           */
  int size;            /**< max pos R or W.             */
  int pos;             /**< current position.           */
  int open;            /**< has been opened.            */
  char name[1];        /**< filename (null://filename). */
} istream68_null_t;

static const char * ism_name(istream68_t * istream)
{
  istream68_null_t * ism = (istream68_null_t *)istream;

  return (!ism || !ism->name[0])
    ? 0
    : ism->name;
}

static int ism_open(istream68_t * istream)
{
  istream68_null_t * ism = (istream68_null_t *)istream;

  if (!ism || ism->open) {
    return -1;
  }
  ism->open = 1;
  ism->pos = 0;
  ism->size = 0;
  return 0;
}

static int ism_close(istream68_t * istream)
{
  istream68_null_t * ism = (istream68_null_t *)istream;

  if (!ism || !ism->open) {
    return -1;
  }
  ism->open = 0;
  return 0;
}

static int ism_read_or_write(istream68_t * istream, int n)
{
  istream68_null_t * ism = (istream68_null_t *)istream;

  if (!ism || !ism->open || n < 0) {
    return -1;
  }
  if (n) {
    /* No op: do not update size */
    ism->pos += n;
    if (ism->pos > ism->size) {
      ism->size = ism->pos;
    }
  }
  return n;
}

static int ism_read(istream68_t * istream, void * data, int n)
{
  return ism_read_or_write(istream, n);
}

static int ism_write(istream68_t * istream, const void * data, int n)
{
  return ism_read_or_write(istream, n);
}

static int ism_length(istream68_t * istream)
{
  istream68_null_t * ism = (istream68_null_t *)istream;

  return (ism) ? ism->size : -1;
}

static int ism_tell(istream68_t * istream)
{
  istream68_null_t * ism = (istream68_null_t *)istream;

  return (!ism || !ism->open)
    ? -1
    : ism->pos;
}

static int ism_seek(istream68_t * istream, int offset)
{
  istream68_null_t * ism = (istream68_null_t *)istream;

  if (ism) {
    offset += ism->pos;
    if (offset >= 0) {
      ism->pos = offset;
      return 0;
    }
  }
  return -1;
}

static void ism_destroy(istream68_t * istream)
{
  free68(istream);
}

static const istream68_t istream68_null = {
  ism_name,
  ism_open, ism_close,
  ism_read, ism_write,
  ism_length, ism_tell, ism_seek, ism_seek,
  ism_destroy
};

istream68_t * istream68_null_create(const char * name)
{
  istream68_null_t *ism;
  int size;
  static const char hd[] = "null://";

  if (!name) {
    name = "default";
  }

  size = sizeof(istream68_null_t) + sizeof(hd)-1 + strlen(name);

  ism = alloc68(size);
  if (!ism) {
    return 0;
  }

  ism->istream = istream68_null;
  ism->size    = 0;
  ism->pos     = 0;
  ism->open    = 0;
  strcpy(ism->name,hd);
  strcat(ism->name,name);

  return &ism->istream;
}

#else /* #ifndef ISTREAM68_NO_NULL */

/* istream mem must not be include in this package. Anyway the creation
 * still exist but it always returns error.
 */

#include "file68/istream68_null.h"

istream68_t * istream68_null_create(const char * name)
{
  error68_add("istream68_null_create(%s) : not supported", name);
  return 0;
}

#endif

/*
 *                    file68 - stream operations
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

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include "file68_api.h"
#include "istream68.h"
#include "istream68_def.h"

const char * istream68_filename(istream68_t * istream)
{
  const char * name =
    (!istream || !istream->name)
    ? 0
    : istream->name(istream);
  return name ? name : "<nul>";
}

int istream68_open(istream68_t *istream)
{
  return (!istream || !istream->open)
    ? -1
    : istream->open(istream);
}

int istream68_close(istream68_t *istream)
{
  return (!istream || !istream->close)
    ? -1
    : istream->close(istream);
}

int istream68_read(istream68_t *istream, void * data, int len)
{
  return (!istream || !istream->read)
    ? -1
    : istream->read(istream, data, len);
}

int istream68_write(istream68_t *istream, const void * data, int len)
{
  return (!istream || !istream->write)
    ? -1
    : istream->write(istream, data, len);
}

int istream68_length(istream68_t *istream)
{
  return (!istream || !istream->length)
    ? -1
    : istream->length(istream);
}

int istream68_tell(istream68_t *istream)
{
  return (!istream || !istream->tell)
    ? -1
    : istream->tell(istream);
}

static int isseek(istream68_t *istream, int pos, int offset)
{
  if (pos != -1) {
    if (offset) {
      istream68_seek_t seek = (offset > 0) ? istream->seekf : istream->seekb;
      if (seek && seek(istream, offset) != -1) {
        pos += offset;
      } else {
        pos = -1;
      }
    }
  }
  return pos;
}

int istream68_seek(istream68_t *istream, int offset)
{
  return isseek(istream, istream68_tell(istream), offset);
}

int istream68_seek_to(istream68_t *istream, int pos)
{
  int cur = istream68_tell(istream);

  return isseek(istream, cur, pos-cur);
}

void istream68_destroy(istream68_t *istream)
{
  if (istream) {
    if (istream->close) {
      istream->close(istream);
    }
    if (istream->destroy) {
      istream->destroy(istream);
    }
  }
}

int istream68_gets(istream68_t *istream, char * buffer, int max)
{
  int i;

  if (!istream || !istream->read || !buffer || max <= 0) {
    return -1;
  }

  for (i=0, --max; i<max; ) {
    char c;
    int err;
    err = istream->read(istream, &c, 1);
    if (err == -1) {
      return -1;
    }
    if (err != 1) {
      break;
    }
    buffer[i++] = c;
    if (c == '\n') {
      break;
    }
  }
  buffer[i] = 0;
  return i;
}

int istream68_getc(istream68_t *istream)
{
  unsigned char c;

  return istream68_read(istream,&c,1) != 1
    ? -1
    : c;
}

int istream68_puts(istream68_t *istream, const char * s)
{
  int err = 0;
  if (s) {
    int c;
    while (!err && (c = *s++)) {
      err = istream68_putc(istream, c);
    }
  }
  return err;
}

int istream68_putc(istream68_t *istream, const int c)
{
  unsigned char byte = c;
  return -(istream68_write(istream,&byte,1) != 1);
}

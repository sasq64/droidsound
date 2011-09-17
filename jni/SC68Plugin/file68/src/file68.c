/*
 *                  file68 - "sc68" file functions
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
 * $Id$
 *
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include "file68_api.h"
#include "file68.h"

#include "error68.h"
#include "alloc68.h"
#include "msg68.h"
#include "string68.h"
#include "rsc68.h"

#include "istream68_def.h"
#include "istream68_file.h"
#include "istream68_fd.h"
#include "istream68_curl.h"
#include "istream68_mem.h"
#include "istream68_z.h"
#include "istream68_null.h"
#include "gzip68.h"
#include "ice68.h"
#include "url68.h"

#ifndef u64
# ifdef HAVE_STDINT_H
#  include <stdint.h>
#  define u64 uint_least64_t
# elif defined(_MSC_VER)
#  define u64 unsigned __int64
# elif defined(__GNUC__)
#  define u64 unsigned long long
# endif
#endif

#ifndef u64
# error "u64 must be defined as an integer of at least 64 bit"
#endif

#include <string.h>
#include <ctype.h>
#include <stdio.h>

/* Current identifier string used to save file */
#define SC68_SAVE_IDSTR file68_idstr

#define FOURCC(A,B,C,D) ((int)( ((A)<<24) | ((B)<<16) | ((C)<<8) | (D) ))
#define gzip_cc FOURCC('g','z','i','p')
#define ice_cc  FOURCC('i','c','e','!')
#define sndh_cc FOURCC('S','N','D','H')
#define sc68_cc FOURCC('S','C','6','8')

/* SC68 file identifier string
 */
const char file68_idstr[56]   = SC68_IDSTR;
const char file68_idstr_v2[8] = SC68_IDSTR_V2;

#ifndef DEBUG_FILE68_O
# define DEBUG_FILE68_O 0
#endif
int file68_cat = msg68_DEFAULT;

int file68_o_init(void)
{
  file68_cat = msg68_cat("loader", "music file loader", DEBUG_FILE68_O);
  return 0;
}

void file68_o_shutdown(void)
{
  msg68_cat_free(file68_cat);
  file68_cat = msg68_DEFAULT;
}

/* Peek Little Endian Unaligned 32 bit value */
static int LPeek(const void *a)
{
  int r;
  unsigned char *c = (unsigned char *) a;
  r = c[0] + (c[1] << 8) + (c[2] << 16) + ((int)(signed char)c[3] << 24);
  return r;
}

static int LPeekBE(const void *a)
{
  int r;
  unsigned char *c = (unsigned char *) a;
  r = ((int)(signed char)c[0] << 24) + (c[1] << 16) + (c[2] << 8) + c[3];
  return r;
}

/* Poke Little Endian Unaligned 32 bit value */
static void LPoke(void *a, int r)
{
  unsigned char *c = (unsigned char *) a;
  c[0] = r;
  c[1] = r >> 8;
  c[2] = r >> 16;
  c[3] = r >> 24;
}

static int myatoi(const char *s, int i, int max, int * pv)
{
  int v = 0;
  for (; i<max; ++i) {
    int c = s[i] & 255;
    if (c>='0' && c<='9') {
      v = v * 10 + c - '0';
    } else {
      break;
    }
  }
  if (pv) *pv = v;
  return i;
}

#define ok_int(V)  strok68(V)
#define strnull(S) strnevernull68(S)

static int sndh_is_magic(const char *buffer, int max)
{
  const int start = 6;
  int i=0, v = 0;
  if (max >= start) {
    for (i=start, v = LPeekBE(buffer); i < max && v != sndh_cc;
         v = ((v<<8)| (buffer[i++]&255)) & 0xFFFFFFFF)
      ;
  }
  i = (v == sndh_cc) ? i-4: 0;
  return i;
}

/* Ensure enough data in id buffer;
 *  retval  0      on error
 *  retval  count  on success
 */
static inline
int ensure_header(istream68_t * const is, char *id, int have, int need)
{
  if (have < need) {
    int miss = need - have;
    int read = istream68_read(is, id+have, miss);
    if (read != miss) {
      error68("not an sc68 file (error:%d)",read);
      have = 0;
    } else {
      have = need;
    }
  }
  return have;
}

/* Verify header; returns # bytes to alloc & read
 * or -1 if error
 * or -gzip_cc if may be gzipped
 * or -ice_cc if may be iced
 * or -sndh_cc if may be sndh
 */
static int read_header(istream68_t * const is)
{
  char id[256];
  const int idv1_req = sizeof(file68_idstr);
  const int idv2_req = sizeof(file68_idstr_v2);
/*   const int gzip_req = 3; */
/*   const int ice1_req = 16; */
  const int sndh_req = 32;
  int have = 0;
  const char * missing_id = "not an sc68 file (no magic)";

  /* Read ID v2 string */
  if(have = ensure_header(is, id, have, idv2_req), !have) {
    return -1;
  }

  if (!memcmp(id, file68_idstr, idv2_req)) {
    /* looks like idv1; need more bytes to confirm */
    if (have = ensure_header(is, id, have, idv1_req), !have) {
      return -1;
    }
    if (memcmp(id, file68_idstr, idv1_req)) {
      return error68(missing_id);
    }
    TRACE68(file68_cat,"file68: found header [%s]\n", file68_idstr);
  } else if (!memcmp(id, file68_idstr_v2, idv2_req)) {
    TRACE68(file68_cat,"file68: found header: [%s]\n",file68_idstr_v2);
  } else {
    if (have = ensure_header(is, id, have, sndh_req), !have) {
      return -1;
    }
    if (gzip68_is_magic(id)) {
      TRACE68(file68_cat,"file68: found GZIP signature\n");
      return -gzip_cc;
    } else if (ice68_is_magic(id)) {
      TRACE68(file68_cat,"file68: found ICE! signature\n");
      return -ice_cc;
    } else {
      /* Must be done after gzip or ice becausez id-string may appear
       * in compressed buffer too.
       */
      if (sndh_is_magic(id,sndh_req)) {
        TRACE68(file68_cat,"file68: found SNDH signature\n");
        return -sndh_cc;
      }
    }
    return error68(missing_id);
  }

  /* Check 1st chunk */
  if (istream68_read(is, id, 4) != 4
      || memcmp(id, CH68_CHUNK CH68_BASE, 4)) {
    return error68("file68: not sc68 file -- missing base chunk");
  }

  /* Get base chunk : file total size */
  if (istream68_read(is, id, 4) != 4
      || (have = LPeek(id), have <= 8)) {
    return error68("file68: not sc68 file -- weird base chunk size");
  }
  TRACE68(file68_cat,"file68: header have %d bytes\n",have-8);
  return have-8;
}

static char noname[] = SC68_NOFILENAME;


/* FR  = SEC * HZ
 * FR  = MS*HZ/1000
 *
 * SEC = FR / HZ
 * MS  = FR*1000/HZ
 */

static unsigned int frames_to_ms(unsigned int fr, unsigned int hz)
{
  u64 ms;

  ms  = fr;
  ms *= 1000u;
  ms /= hz;

  return (unsigned int) ms;
}

static unsigned int ms_to_frames(unsigned int ms, unsigned int hz)
{
  u64 fr;

  fr =  ms;
  fr *= hz;
  fr /= 1000u;

  return (unsigned int ) fr;
}


/* This function inits all pointers for this music files It setup non
 * initialized data to defaut value.
 */
static int valid(disk68_t * mb)
{
  music68_t *m;
  int i, previousdatasz = 0;
  void *previousdata = 0;
  char *author = noname;
  char *composer = 0;
  char *mname;
  char *converter = noname;
  char *ripper = noname;

  if (mb->nb_six <= 0) {
    return error68("file68: disk has no track");
  }

  /* Ensure default music in valid range */
  if (mb->default_six < 0 || mb->default_six >= mb->nb_six) {
    mb->default_six = 0;
  }

  /* No name : set default */
  if (mb->name == 0) {
    mb->name = noname;
  }
  mname = mb->name;

  /* Disk total time : 00:00 */
  mb->time_ms = 0;

  /* Clear flags */
  mb->hwflags.all = 0;

  /* Init all music in this file */
  for (m = mb->mus, i = 0; m < mb->mus + mb->nb_six; m++, i++) {
    /* default load address */
    if (m->a0 == 0) {
      m->a0 = SC68_LOADADDR;
    }
    /* default replay frequency is 50Hz */
    if (m->frq == 0) {
      m->frq = 50;
    }

    /* Compute ms from frames prior to frames from ms. */
    if (m->frames) {
      m->time_ms = frames_to_ms(m->frames, m->frq);
    } else {
      m->frames = ms_to_frames(m->time_ms, m->frq);
    }

    /* Set start time in the disk. */
    m->start_ms = mb->time_ms;

    /* Advance disk total time. */
    mb->time_ms += m->time_ms;

    /* default mode is YM2149 (Atari ST) */
    if (m->hwflags.all == 0) {
      m->hwflags.bit.ym = 1;
    }
    mb->hwflags.all |= m->hwflags.all;

    /* default music name is file name */
    mname = m->name = (m->name == 0) ? mname : m->name;
    /* default author */
    author = m->author = (m->author == 0) ? author : m->author;
    /* default composer is author */
    composer = m->composer = (m->composer == 0) ?
      ((composer == 0) ? m->author : composer) : m->composer;
    /* default converter is the empty string */
    converter = m->converter = (m->converter == 0) ?
      ((converter == 0) ? m->converter : converter) : m->converter;
    /* default copier is the empty string */
    ripper = m->ripper = (m->ripper == 0) ?
      ((ripper == 0) ? m->ripper : ripper) : m->ripper;
    /* use data from previuous music */
    if (m->data == 0) {
      m->data   = (char *) previousdata;
      m->datasz = previousdatasz;
    }
    if (m->data == 0) {
      return error68("file68: track #%d has no data", i+1);
    }
    previousdata   = m->data;
    previousdatasz = m->datasz;
  }

  return 0;
}

int file68_is_our_url(const char * url, const char * exts, int * is_remote)
{
  const char * url_end, *u;
  char protocol[16], *p;
  int has_protocol, remote, is_our;

  TRACE68(file68_cat,"file68: check url --\n",url);

  is_our = remote = 0;
  if (!url || !*url) {
    goto exit;
  }

  /* Default supported extensions */
  if (!exts) {
    exts = ".sc68\0.sndh\0.snd\0";
  }

  url_end = url + strlen(url);
  has_protocol = !url68_get_protocol(protocol, sizeof(protocol), url);

  if (has_protocol) {
    is_our = !strcmp68(protocol,"SC68");
    if (!is_our && !strcmp68(protocol,"RSC68") && url+14<url_end) {
      is_our = strncmp(url+8, "music/", 6);
    }

    if (is_our)  {
      /* $$$ Not really sure; may be remote or not. The only way to
         know is to check for the corresponding local file.
      */
      remote = 0;
      goto exit;
    }
  }

  /* Check remote for other protocol */
  remote = !url68_local_protocol(protocol);

  /* Check extension ... */
  p = protocol+sizeof(protocol);
  *--p = 0;
  for (u=url_end; u > url && p > protocol; ) {
    int c = *--u & 255;
    if (c == '/') {
      break;
    }
    *--p = c;
    if (c == '.') {
      if (!strcmp68(p,".GZ")) {
        p = protocol+sizeof(protocol)-1;
      } else {
        break;
      }
    }
  }

  while (*exts) {
    is_our = !strcmp68(p,exts);
    if (is_our) {
      break;
    }
    exts += strlen(exts)+1;
  }

  exit:
  if (is_remote) *is_remote = remote;
  TRACE68(file68_cat, "file68: check url -- [%s]\n", ok_int(!is_our));
  return is_our;
}

/* Check if file is probable SC68 file
 * return 0:SC68-file
 */
int file68_verify(istream68_t * is)
{
  int res;
/*   const char * fname = strnull(istream68_filename(is)); */

  if (!is) {
    res = error68("file68_verify(): null pointer");
    goto error;
  }

  res = read_header(is);

  /* Verify tells it is a gzip file, so we may give it a try. */
  if (res < 0) {
    void * buffer = 0;
    int len;

    switch (res) {
    case -gzip_cc:
      if (istream68_seek_to(is,0) == 0) {
        istream68_t * zis;
        zis = istream68_z_create(is,ISTREAM68_OPEN_READ,
                                 istream68_z_default_option);
        res = -1;
        if (!istream68_open(zis)) {
          res = file68_verify(zis);
        }
        istream68_destroy(zis);
      }
      break;
    case -ice_cc:
      if (istream68_seek_to(is,0) == 0) {
        buffer = ice68_load(is, &len);
      }
      break;
    case -sndh_cc:
      res = 0;
      break;
    }
    if (buffer) {
      res = -res;
      res = file68_verify_mem(buffer, len);
      free68(buffer);
    }
  }

  error:
  return -(res < 0);
}

static istream68_t * url_or_file_create(const char * url, int mode,
                                        rsc68_info_t * info)
{
  char protocol[16], tmp[512];
  const int max = sizeof(tmp)-1;
  istream68_t *isf = 0;
  int has_protocol;
  char * newname = 0;

  TRACE68(file68_cat,"file68: create -- %s -- mode:%d -- with%s info\n",
          strnull(url),mode,info?"":"out");

  if (info) {
    info->type = rsc68_last;
  }

  has_protocol = !url68_get_protocol(protocol, sizeof(protocol), url);

  if (has_protocol) {

    /* convert sc68:// -> rsc68:// */
    if (!strcmp68(protocol, "SC68")) {
      url += 4+3;
      strcpy(tmp, "rsc68://music/");
      strncpy(tmp+14, url, max-14);
      tmp[max] = 0;
      url = tmp;
      strcpy(protocol,"rsc68");
      TRACE68(file68_cat,"file68: transform url into -- %s\n",url);
    }

    if (!strcmp68(protocol, "RSC68")) {
      return rsc68_open_url(url, mode, info);
    }
  }

  isf = url68_stream_create(url, mode);

  if (istream68_open(isf)) {
    istream68_destroy(isf);
    isf = 0;
  }

  free68(newname);
  TRACE68(file68_cat,"file68: create -- [%s,%s]\n",
          ok_int(!isf),
          strnull(istream68_filename(isf)));
  return isf;
}

int file68_verify_url(const char * url)
{
  int res;
  istream68_t * is;

/*   CONTEXT68_CHECK(context); */

  is = url_or_file_create(url,1,0);
  res = file68_verify(is);
  istream68_destroy(is);

  return -(res < 0);
}

int file68_verify_mem(const void * buffer, int len)
{
  int res;
  istream68_t * is;

  is = istream68_mem_create((void *)buffer,len,1);
  res = istream68_open(is) ? -1 : file68_verify(is);
  istream68_destroy(is);

  return res;
}

/* Check if file is probable SC68 file
 * return 0:SC68-file
 */
int file68_diskname(istream68_t * is, char *dest, int max)
{
  error68(0,"file68: file68_diskname function is deprecated\n");
  return -1;
}

disk68_t * file68_load_url(const char * fname)
{
  disk68_t * d;
  istream68_t * is;
  rsc68_info_t info;

  TRACE68(file68_cat,"file68: load -- %s\n", strnull(fname));

  is = url_or_file_create(fname, 1, &info);
  d = file68_load(is);
  istream68_destroy(is);

  if (d && info.type == rsc68_music) {
    int i;

    TRACE68(file68_cat,
            "file68: load -- on the fly path -- #%d/%d/%d\n",
            info.data.music.track,
            info.data.music.loop,
            info.data.music.time);

    if (info.data.music.track > 0 && info.data.music.track <= d->nb_six) {
      d->mus[0] = d->mus[info.data.music.track-1];
      d->mus[0].start_ms = 0;
      d->mus[0].track = info.data.music.track;
      d->default_six = 0;
      d->nb_six = 1;
      d->time_ms = d->mus[0].time_ms;
      d->hwflags.all = d->mus[0].hwflags.all;
    }
    if (info.data.music.loop != -1) {
      for (i=0; i<d->nb_six; ++i) {
        d->mus[i].loop = info.data.music.loop;
      }
    }
    if (info.data.music.time != -1) {
      unsigned int ms = info.data.music.time * 1000u;
      d->time_ms = 0;
      for (i=0; i<d->nb_six; ++i) {
        d->mus[i].frames   = ms_to_frames(ms, d->mus[i].frq);
        d->mus[i].time_ms  = ms;
        d->mus[i].start_ms = d->time_ms;
        d->time_ms += ms;
      }
    }
  }

  TRACE68(file68_cat,"file68: load -- [%s]\n", ok_int(!d));
  return d;
}

disk68_t * file68_load_mem(const void * buffer, int len)
{
  disk68_t * d;
  istream68_t * is;

  is = istream68_mem_create((void *)buffer,len,1);
  d = istream68_open(is) ? 0 : file68_load(is);
  istream68_destroy(is);

  return d;
}
static int st_isgraph( int c )
{
  return c >= 32 && c < 128;
}

static int st_isdigit( int c )
{
  return c >= '0' && c <= '9';
}

static int sndh_info(disk68_t * mb, int len)
{
  const int unknowns_max = 8;
  int i, vbl = 0, frq = 0, time = 0 , musicmon = 0, steonly = 0,
    unknowns = 0, fail = 0;
  char * b = mb->data;
  char empty_tag[4] = { 0, 0, 0, 0 };


  /* Default */
  mb->mus[0].data = b;
  mb->mus[0].datasz = len;
  mb->nb_six = -1; /* Make validate failed */
  mb->mus[0].replay = ice68_version() ? 0 : "sndh_ice"; /* native ice depacker ? */

  i = sndh_is_magic(mb->data, len);
  if (!i) {
    /* should not happen since we already have tested it. */
    msg68_critical("file68: sndh -- info mising magic!\n");
    return -1;
  }

/*   i   += 4; /\* Skip sndh_cc *\/ */
/*   len -= 4; */

  /* $$$ Hacky:
     Some music have 0 after values. I don't know what are
     sndh rules. May be 0 must be skipped or may be tag must be word
     aligned.
     Anyway the current parser allows a given number of successive
     unknown tags. May be this number should be increase in order to prevent
     some "large" unknown tag to break the parser.
  */

  while (i+4 < len) {
    char ** p;
    int j, t, s, ctypes;

    /* check char types for the next 4 chars */
    for (ctypes = 0, j=0; j<4; ++j) {
      ctypes |= (st_isgraph( b[i+j] ) << j );
      ctypes |= (st_isdigit( b[i+j] ) << (j + 8) );
    }

    TRACE68(file68_cat,
            "file68: sndh -- pos:%d/%d ctypes:%04X -- '%c%c%c%c'\n",
            i, len, ctypes, b[i+0], b[i+1], b[i+2], b[i+3]);

    t       = -1;                       /* offset on tag */
    s       = -1;                       /* offset on arg */
    p       = 0;                        /* store arg     */

    if (  (ctypes & 0x000F) != 0x000F ) {
      /* Not graphical ... should not be a valid tag */
    } else if (!memcmp(b+i,"SNDH",4)) {
      /* Header */
      t = i; i += 4;
    } else if (!memcmp(b+i,"COMM",4)) {
      /* Composer */
      t = i; s = i += 4;
      p = &mb->mus[0].author;
    } else if (!memcmp(b+i,"TITL",4)) { /* title    */
      /* Title */
      t = i; s = i += 4;
      p = &mb->name;
    } else if (!memcmp(b+i,"RIPP",4)) {
      /* Ripper    */
      t = i; s = i += 4;
      p = &mb->mus[0].ripper;
    } else if (!memcmp(b+i,"CONV",4)) {
      /* Converter */
      t = i; s = i += 4;
      p = &mb->mus[0].converter;
    } else if (!memcmp(b+i, "YEAR", 4)) {
      /* year */
      t = i; s = i += 4;
      /* p = ... */
    } else if (!memcmp(b+i,"MuMo",4)) {
      /* Music Mon ???  */
      msg68_warning("file68: sndh -- what to do with 'MuMo' tag ?\n");
      musicmon = 1;
      i += 4;
    } else if (!memcmp(b+i,"TIME",4)) {
      int j, tracks;
      /* Time in second */
      if (! (tracks = mb->nb_six) ) {
        msg68_warning("file68: sndh -- got 'TIME' before track count\n");
        tracks = 1;
      }
      t = i; i += 4;
      for ( j = 0; j < tracks; ++j ) {
        if (i < len-2 && j < SC68_MAX_TRACK)
          mb->mus[j].time_ms = 1000u *
            ( ( ( (unsigned char) b[i]) << 8 ) | (unsigned char) b[i+1] );
        i += 2;
      }
    } else if ( !memcmp(b+i,"##",2) && ( (ctypes & 0xC00) == 0xC00 ) ) {
      mb->nb_six = ( b[i+2] - '0' ) * 10 + ( b[i+3] - '0' );
      t = i; i += 4;
    } else if ( !memcmp(b+i,"!V",2) && ( (ctypes & 0xC00) == 0xC00 ) ) {
      vbl = ( b[i+2] - '0' ) * 10 + ( b[i+3] - '0' );
      i += 4;
    } else if (!memcmp(b+i,"**",2)) {
      /* FX +string 2 char ??? */
      msg68_warning("file68: sndh -- what to do with tag ? -- '**%c%c'\n",
                    b[i+2], b[i+3]);
      i += 4;
    } else if ( b[i] == 'T' && b[i+1] >= 'A' && b[i+1] <= 'D') {
      t = i; s = i += 2;
      myatoi(b, i, len, &frq);
    } else if( memcmp( b + i, empty_tag, 4 ) == 0 ||
             memcmp( b + i, "HDNS", 4 ) == 0 ) {
      t = i;
      i = len;
    } else {
      /* skip until next 0 byte, as long as it's inside the tag area */

      i += 4;
      while( *(b + i) != 0 && i < len ) {
        i++;
      }

  }
    if ( t < 0 ) {
      /* Unkwown tag, finish here. */
      ++unknowns;
      TRACE68(file68_cat,
              "file68: sndh -- not a tag at offset %d -- %02X%02X%02X%02X\n",
              i, b[i]&255, b[i+1]&255, b[i+2]&255, b[i+3]&255);
      ++i;
      if (fail || unknowns >= unknowns_max) {
        i = len;
      }
    } else {
      /* Well known tag */

      TRACE68(file68_cat,
              "file68: sndh -- got TAG -- '%c%c%c%c'\n",
              b[t], b[t+1], b[t+2], b[t+3]);
      unknowns = 0; /* Reset successive unkwown. */
      if (s >= 0) {
        int j, k;
        for ( j = s, k = s - 1; j < len && b[j]; ++j) {
          if ( b[j] < 32 ) b[j] = 32;
          else k = j;                   /* k is last non space char */
        }

        if (k+1 < len) {
          b[k+1] = 0;                   /* Strip triling space */
          i = k+2;
          if (p)
            *p = b+s;                     /* store tag */
          else
            TRACE68(file68_cat,"file68: sndh -- not storing -- '%s'\n",
                    b+s);

          /* HAXXX: using name can help determine STE needs */
          if (p == &mb->name)
            steonly = !!strstr(mb->name,"STE only");

          TRACE68(file68_cat,
                  "file68: sndh -- got ARG -- '%s'\n",
                  b+s);
        }

        /* skip the trailing null chars */
        for ( ; i < len && !b[i] ; i++ )
          ;
        }
      }
    }
  if (mb->nb_six <= 0) {
    TRACE68(file68_cat, "file68: sndh -- no track; assuming 1 track\n");
    mb->nb_six = 1;

  }
  if (mb->nb_six > SC68_MAX_TRACK) {
    mb->nb_six = SC68_MAX_TRACK;
  }
  time *= 1000;
  for (i=0; i<mb->nb_six; ++i) {
    mb->mus[i].d0 = i+1;
    mb->mus[i].loop = 1;
    mb->mus[i].frq = frq ? frq : vbl;
    mb->mus[i].hwflags.bit.ym = 1;
    mb->mus[i].hwflags.bit.ste = steonly;
  }
  return 0;
}
void file68_free(disk68_t * disk)
{
  if (disk) {
  /* $$$ right now this is ok. Should be change later to check if
   * there is allocated buffer in the disk. */
    free68(disk);
  }
}

/* Load , allocate memory and valid struct for SC68 music
 */
disk68_t * file68_load(istream68_t * is)
{
  disk68_t *mb = 0;
  int len, room;
  int chk_size;
  int opened = 0;
  music68_t *cursix;
  char *b;
  const char *fname = istream68_filename(is);
  const char *errorstr = "no more info";

  fname = strnevernull68(fname);

  /* Read header and get data length. */
  if (len = read_header(is), len < 0) {
    /* Verify tells it is a gzip or unice file, so we may give it a try.
     */
    if (1) {
      void * buffer = 0;
      int l;
      switch (len) {
      case -gzip_cc:
        /* gzipped */
        if (istream68_seek_to(is,0) == 0) {
          istream68_t * zis;
          zis=istream68_z_create(is,ISTREAM68_OPEN_READ,
                                 istream68_z_default_option);
          if (!istream68_open(zis)) {
            mb = file68_load(zis);
          }
          istream68_destroy(zis);
          if (mb) {
            goto already_valid;
          }
        }
        break;

      case -ice_cc:
        if (istream68_seek_to(is,0) == 0) {
          buffer = ice68_load(is, &l);
        }
        break;
      case -sndh_cc:
        if (istream68_seek_to(is,0) != 0) {
          break;
        }
        len = istream68_length(is);
        if (len <= 32) {
          break;
        }
        mb = alloc68(sizeof(*mb) + len);
        if (!mb) {
          break;
        }
        memset(mb,0,sizeof(*mb));
        if (istream68_read(is, mb->data, len) != len) {
          break;
        }
        if (sndh_info(mb, len)) {
          break;
        }
        goto validate;
      }

      if (buffer) {
        mb = file68_load_mem(buffer, l);
        free68(buffer);
        if (mb) {
          return mb;
        }
      }
    }
    errorstr = "read header";
    goto error;
  }

  room = len + sizeof(disk68_t) - sizeof(mb->data);
  mb = alloc68(room);
  if (!mb) {
    errorstr = "memory allocation";
    goto error;
  }
  memset(mb, 0, room);

  if (istream68_read(is, mb->data, len) != len) {
    errorstr = "read data";
    goto error;
  }

  for (b = mb->data, cursix = 0; len >= 8; b += chk_size, len -= chk_size) {
    char chk[8];

    if (b[0] != 'S' || b[1] != 'C') {
      break;
    }

    chk[0] = b[2];
    chk[1] = b[3];
    chk[2] = 0;
    chk_size = LPeek(b + 4);
    b += 8;
    len -= 8;

    if (!strcmp(chk, CH68_BASE)) {
      /* nothing to do. */
    }
    /* Music general info */
    else if (!strcmp(chk, CH68_DEFAULT)) {
      mb->default_six = LPeek(b);
    } else if (!strcmp(chk, CH68_FNAME)) {
      mb->name = b;
    }
    /* start music session */
    else if (!strcmp(chk, CH68_MUSIC)) {
      /* More than 256 musix !!! : Prematured end */
      if (mb->nb_six >= 256) {
        len = 0;
        break;
      }
      cursix = mb->mus + mb->nb_six;
      cursix->loop = 1; /* default loop */
      mb->nb_six++;
    }
    /* Music name */
    else if (!strcmp(chk, CH68_MNAME)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->name = b;
    }
    /* Author name */
    else if (!strcmp(chk, CH68_ANAME)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->author = b;
    }
    /* Composer name */
    else if (!strcmp(chk, CH68_CNAME)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->composer = b;
    }
    /* External replay */
    else if (!strcmp(chk, CH68_REPLAY)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->replay = b;
    }
    /* 68000 D0 init value */
    else if (!strcmp(chk, CH68_D0)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->d0 = LPeek(b);
    }
    /* 68000 memory load address */
    else if (!strcmp(chk, CH68_AT)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->a0 = LPeek(b);
    }
    /* Playing time */
    else if (!strcmp(chk, CH68_TIME)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->time_ms = LPeek(b) * 1000u;
    }

    /* Playing time */
    else if (!strcmp(chk, CH68_FRAME)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->frames = LPeek(b);
    }

    /* Replay frequency */
    else if (!strcmp(chk, CH68_FRQ)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->frq = LPeek(b);
    }

    /* Loop */
    else if (!strcmp(chk, CH68_LOOP)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->loop = LPeek(b);
    }

    /* replay flags */
    else if (!strcmp(chk, CH68_TYP)) {
      int f;
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      f = LPeek(b);
      cursix->hwflags.all = 0;
      cursix->hwflags.bit.ym = !!(f & SC68_YM);
      cursix->hwflags.bit.ste = !!(f & SC68_STE);
      cursix->hwflags.bit.amiga = !!(f & SC68_AMIGA);
      cursix->hwflags.bit.stechoice = !!(f & SC68_STECHOICE);
      cursix->hwflags.bit.timers    = !! (f & SC68_TIMERS);
      cursix->hwflags.bit.timera    = !! (f & SC68_TIMERA);
      cursix->hwflags.bit.timerb    = !! (f & SC68_TIMERB);
      cursix->hwflags.bit.timerc    = !! (f & SC68_TIMERC);
      cursix->hwflags.bit.timerd    = !! (f & SC68_TIMERD);
    }
    /* music data */
    else if (!strcmp(chk, CH68_MDATA)) {
      if (cursix == 0) {
        errorstr = chk;
        goto error;
      }
      cursix->data = b;
      cursix->datasz = chk_size;
    }
    /* EOF */
    else if (!strcmp(chk, CH68_EOF)) {
      len = 0;
      break;
    }
  }

  /* Check it */
  if (len) {
    errorstr = "prematured end of file";
    goto error;
  }

  validate:
  if (valid(mb)) {
    errorstr = "validation test";
    goto error;
  }

  already_valid:
  if (opened) {
    istream68_close(is);
  }
  return mb;

  error:
  if (opened) {
    istream68_close(is);
  }
  free68(mb);
  error68("file68: load '%s' failed [%s]", fname, errorstr);
  return 0;
}


#ifndef _FILE68_NO_SAVE_FUNCTION_

/* save CHUNK and data */
/* $$$ NEW: Add auto 16-bit alignement. */
static int save_chunk(istream68_t * os,
                      const char * chunk, const void * data, int size)
{
  static char zero[4] = {0,0,0,0};
  chunk68_t chk;
  int align;

  memcpy(chk.id, CH68_CHUNK, 2);
  memcpy(chk.id + 2, chunk, 2);
  align = size & 1;
  LPoke(chk.size, size + align);
  if (istream68_write(os, &chk, (int)sizeof(chunk68_t)) != sizeof(chunk68_t)) {
    goto error;
  }
  /* Special case data is 0 should happen only for SC68 total size
   * chunk.
   */
  if (size && data) {
    if (istream68_write(os, data, size) != size) {
      goto error;
    }
    if (align && istream68_write(os, zero, align) != align) {
      goto error;
    }
  }
  return 0;

  error:
  return -1;
}

/* save CHUNK and string (only if non-0 & lenght>0) */
static int save_string(istream68_t * os,
                       const char * chunk, const char * str)
{
  int len;

  if (!str || !(len = strlen(str))) {
    return 0;
  }
  return save_chunk(os, chunk, str, len + 1);
}

/* save CHUNK & string str ( only if oldstr!=str & lenght>0 ) */
static int save_differstr(istream68_t * os,
                          const char *chunk, char *str, char *oldstr)
{
  int len;

  if (oldstr == str
      || !str
      || (oldstr && !strcmp(oldstr, str))) {
    return 0;
  }
  len = strlen(str);
  return !len ? 0 :save_chunk(os, chunk, str, len + 1);
}

/* save CHUNK and 4 bytes Big Endian integer */
static int save_number(istream68_t * os, const char * chunk, int n)
{
  char number[4];

  LPoke(number, n);
  return save_chunk(os, chunk, number, 4);
}

/* save CHUNK and number (only if n!=0) */
static int save_nonzero(istream68_t * os, const char * chunk, int n)
{
  return !n ? 0 : save_number(os, chunk, n);
}

int file68_save_url(const char * fname, const disk68_t * mb,
                    int gzip)
{
  int feature = msg68_cat_current(file68_cat);
  istream68_t * os;
  int err;

  os = url_or_file_create(fname, 2, 0);
  err = file68_save(os, mb, gzip);
  istream68_destroy(os);

  msg68_cat_current(feature);
  return err;
}

int file68_save_mem(const char * buffer, int len, const disk68_t * mb,
                    int gzip)
{
  int feature =  msg68_cat_current(file68_cat);
  istream68_t * os;
  int err;


  os = istream68_mem_create((char *)buffer, len, 2);
  err = file68_save(os, mb, gzip);
  istream68_destroy(os);

  msg68_cat_current(feature);
  return err;
}

static const char * save_sc68(istream68_t * os, const disk68_t * mb, int len);

/* Save disk into file. */
int file68_save(istream68_t * os, const disk68_t * mb, int gzip)
{
  int len;
  const char * fname  = 0;
  const char * errstr = 0;
  istream68_t * null_os = 0;
  istream68_t * org_os  = 0;

  if (!os) {

  }

  /* Get filename (for error message) */
  fname = istream68_filename(os);

  /* Create a null stream to calculate total size.
     Needed by gzip stream that can't seek back. */
  null_os = istream68_null_create(fname);
  if (istream68_open(null_os)) {
    errstr = "open error";
  } else {
    errstr = save_sc68(null_os, mb, 0);
  }
  if (errstr) {
    goto error;
  }
  len = istream68_length(null_os) - sizeof(SC68_SAVE_IDSTR);
  if (len <= 0) {
    errstr = "weird stream length error";
    goto error;
  }

  /* Wrap to gzip stream */
  if (gzip) {
    istream68_z_option_t gzopt;

    org_os = os;
    gzopt = istream68_z_default_option;
    gzopt.level = gzip;
    gzopt.name  = 0;
    os = istream68_z_create(org_os, 2, gzopt);
    if (istream68_open(os)) {
      errstr = "open error";
      goto error;
    }
  }

  errstr = save_sc68(os, mb, len);

  error:
  if (org_os) {
    /* Was gzipped: clean-up */
    istream68_destroy(os);
  }
  istream68_destroy(null_os);

  return errstr
    ? error68("file68: save '%s' [%s]",fname,errstr)
    : 0;
}

static const char * save_sc68(istream68_t * os, const disk68_t * mb, int len)
{
  const char * errstr = 0;
  int opened = 0;

  const music68_t * mus;
  char * mname, * aname, * cname, * data;

  if (!os) {
    errstr = "null stream error";
    goto error;
  }

  /* Check number of music */
  if (mb->nb_six <= 0 || mb->nb_six > SC68_MAX_TRACK) {
    errstr = "tracks error";
    goto error;
  }

  /* SC68 file header string */
  if (istream68_write(os, SC68_SAVE_IDSTR, sizeof(SC68_SAVE_IDSTR))
      != sizeof(SC68_SAVE_IDSTR)) {
    errstr = "header write error";
    goto error;
  }

  /* SC68 disk-info chunks */
  if (save_chunk(os, CH68_BASE, 0, len)
      || save_string(os, CH68_FNAME, mb->name)
      || save_nonzero(os, CH68_DEFAULT, mb->default_six)
    ) {
    errstr = "chunk write error";
    goto error;
  }

  /* Reset previous value for various string */
  mname = mb->name;
  aname = cname = data = 0;
  for (mus = mb->mus; mus < mb->mus + mb->nb_six; mus++) {
    int flags
      = 0
      | (mus->hwflags.bit.ym ? SC68_YM : 0)
      | (mus->hwflags.bit.ste ? SC68_STE : 0)
      | (mus->hwflags.bit.amiga ? SC68_AMIGA : 0)
      | (mus->hwflags.bit.stechoice ? SC68_STE    : 0)
      | (mus->hwflags.bit.timers    ? SC68_TIMERS : 0)
      | (mus->hwflags.bit.timera    ? SC68_TIMERA : 0)
      | (mus->hwflags.bit.timerb    ? SC68_TIMERB : 0)
      | (mus->hwflags.bit.timerc    ? SC68_TIMERC : 0)
      | (mus->hwflags.bit.timerd    ? SC68_TIMERD : 0)
      ;

    /* Save track-name, author, composer, replay */
    if (save_chunk(os, CH68_MUSIC, 0, 0) == -1
        || save_differstr(os, CH68_MNAME, mus->name, mname)
        || save_differstr(os, CH68_ANAME, mus->author, aname)
        || save_differstr(os, CH68_CNAME, mus->composer, cname)
        || save_string(os, CH68_REPLAY, mus->replay)
      ) {
      errstr = "chunk write error";
      goto error;
    }
    if (mus->name) {
      mname = mus->name;
    }
    if (mus->author) {
      aname = mus->author;
    }
    if (mus->composer) {
      cname = mus->composer;
    }

    /* Save play parms */
    if (save_nonzero(os, CH68_D0, mus->d0)
        || save_nonzero(os, CH68_AT, (mus->a0 == SC68_LOADADDR) ? 0 : mus->a0)
        || save_nonzero(os, CH68_FRAME, mus->frames)
        || save_nonzero(os, CH68_TIME, (mus->time_ms+999u) / 1000u)
        || save_nonzero(os, CH68_FRQ, (mus->frq == 50) ? 0 : mus->frq)
        || save_nonzero(os, CH68_LOOP, mus->loop)
        || save_number(os, CH68_TYP, flags)
      ) {
      errstr = "chunk write error";
      goto error;
    }

    /* Save music data */
    if (mus->data && mus->data != data) {
      if (save_chunk(os, CH68_MDATA, mus->data, mus->datasz)) {
        errstr = "chunk write error";
        goto error;
      }
      data = mus->data;
    }
  }

  /* SC68 last chunk */
  if (save_chunk(os, CH68_EOF, 0, 0)) {
    errstr = "chunk write error";
    goto error;
  }

  error:
  if (opened) {
    istream68_close(os);
  }
  return errstr;
}

#endif /* #ifndef _FILE68_NO_SAVE_FUNCTION_ */

int file68_version(void)
{
  return PACKAGE_VERNUM;
}

const char * file68_versionstr()
{
  return PACKAGE_STRING;
}

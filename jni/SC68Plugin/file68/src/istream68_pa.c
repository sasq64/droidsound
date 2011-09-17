/*
 *                   file68 - libportaudio stream
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
#include "istream68_pa.h"

/* Define this if you want portaudio support. */
/* At least when and if I implement it someday */
#if 0 && defined(USE_PORTAUDIO)

#include "istream68_def.h"
#include "alloc68.h"
#include "debugmsg68.h"

#if defined(HAVE_PORTAUDIO_PORTAUDIO_H)
# include <portaudio/portaudio.h>
#elif defined(HAVE_PORTAUDIO_H)
# include <portaudio.h>
#endif

#include <string.h>

struct pa68_info_s {
/*   int                default_id; */
/*   ao_device        * default_device; */
/*   int                driver_id; */
/*   ao_device        * device; */
/*   ao_sample_format   format; */
/*   ao_option        * options; */
  PortAudioStream   *stream;
};

typedef struct pa68_info_s pa68_info_t;

/** istream ao structure. */
typedef struct {
  istream68_t istream; /**< istream function.           */
  unsigned int count;  /**< current position.           */
  pa68_info_t pa;
  char name[1];        /**< filename.                   */
} istream68_pa_t;

static volatile int init;

static int istream68_pa_init(void)
{
  int err;
  debugmsg68(-1,"istream68_pa_init() {\n");
  if (!init) {
    err = Pa_Initialize();
    err = -(err != paNoError);
    init = !err;
  } else {
    debugmsg68(-1,"istream68_pa_init() already initialzed\n");
    err = -1;
  }
  debugmsg68(-1,"} istream68_pa_init() => [%s]\n", !err?"success":"error");
  return err;
}

static void istream68_pa_shutdown(void)
{
  debugmsg68(-1,"istream68_pa_init() {\n");
  if (init) {
    init = 0;
    debugmsg68(-1,"istream68_pa_init() Pa_Terminate()\n");
    Pa_Terminate();
  }
  debugmsg68(-1,"} istream68_pa_init()\n");
}

static const char * ispa_name(istream68_t * istream)
{
  istream68_pa_t * ism = (istream68_pa_t *)istream;

  return (!ism || !ism->name[0])
    ? 0
    : ism->name;
}

static int ispa_open(istream68_t * istream)
{
  istream68_pa_t * is = (istream68_pa_t *)istream;
  int err = -1;

  debugmsg68(-1,"ispa_open() {\n");

  if (!is || is->open) {
    goto error_out;
  }

  err = Pa_OpenDefaultStream(
    &is->pa.stream,
    0,              /* no input channels */
    2,              /* stereo output */
    paInt16,
    44100,          /* sample rate */
    256,            /* frames per buffer */
    0,              /* number of buffers, if zero then use default minimum */
    pa68Callback,   /* specify our custom callback */
    is );           /* pass our data through to callback */

  if (err == paNoError) {
    err = Pa_StartStream(is->pa.stream);
  }

  if (err != paNoError) {
    debugmsg68(-1,"Pa_OpenDefaultStream: %s\n",);
    err = -1;
  } else {
    err = 0;
    is->count = 0;
    is->open  = 1;
  }

  error_out:
  debugmsg68(-1,"} ispa_open() => [%s]\n", !err?"success":"error");
  return -!!err;
}

static int ispa_close(istream68_t * istream)
{
  istream68_pa_t * is = (istream68_pa_t *)istream;

  debugmsg68(-1,"ispa_close(%s) {\n", is?is->name:"null");

  if (!is) {
    goto error_out;
  }


  || !is->pa.stream || !is->open ) {
  return -1;
}

err = Pa_StopStream(is->pa.stream);
is->pa.

is->open = 0;
is->ao.device = 0;
istream68_pa_shutdown();

error_out:
debugmsg68(-1,"} ispa_close() => [%s]\n", !err?"success":"error");
return -!!err;
}

static int ispa_read(istream68_t * istream, void * data, int n)
{
  return -1;
}

static int ispa_write(istream68_t * istream, const void * data, int n)
{
  istream68_pa_t * isao = (istream68_pa_t *)istream;

  if (!isao || !isao->ao.device) {
    return -1;
  }
  if (!n) {
    return 0;
  }
  if (n<0) {
    return 0;
  }
  if (ao_play(isao->ao.device, (void *)data, n)) {
    isao->count += n;
    return n;
  } else {
    return -1;
  }
}

static int ispa_length(istream68_t * istream)
{
  istream68_pa_t * isao = (istream68_pa_t *)istream;

  return (isao) ? isao->count : -1;
}


static int ispa_tell(istream68_t * istream)
{
  istream68_pa_t * isao = (istream68_pa_t *)istream;
  return (!isao || !isao->ao.device)
    ? -1
    : isao->count;
}

static int ispa_seek(istream68_t * istream, int offset)
{
  return -1;
}

static void ispa_destroy(istream68_t * istream)
{
  istream68_pa_shutdown();
  free68(istream);
}

static const istream68_t istream68_pa = {
  ispa_name,
  ispa_open, ispa_close,
  ispa_read, ispa_write,
  ispa_length, ispa_tell, ispa_seek, ispa_seek,
  ispa_destroy
};

/* ao stream URL is composed by /key=value pairs.
 *
 * Specific keys are:
 *  - driver=[null|alsa|oss|esd|au|raw|wav....]
 *  - rate=hz
 *  - format=[endianess][sign][channels][format]
 *    with (first value is the default)
 *        - endian   := [n|l|b]
 *        - sign     := [s|u]
 *        - channels := [m|s]
 *        - format   := [w|b|f]
 *
 * other keys mostly depends on ao driver.
 *
 */

istream68_t * istream68_pa_create(const char * fname, int mode)
{
  istream68_pa_t *isf;
  int len;
  pa68_info_t pa;

  if (istream68_pa_init()) {
    return 0;
  }

  if (!fname || !fname[0]) {
    return 0;
  }

  if (mode != ISTREAM68_OPEN_WRITE) {
    return 0;
  }

  /* Don't need 0, because 1 byte already allocated in the
   * istream68_pa_t::fname.
   */
  len = strlen(fname);
  isf = calloc68(sizeof(istream68_pa_t) + len);
  if (!isf) {
    return 0;
  }

  /* Copy istream functions. */
  memcpy(&isf->istream, &istream68_pa, sizeof(istream68_pa));
/*   isf->mode = mode & (ISTREAM68_OPEN_READ|ISTREAM68_OPEN_WRITE); */
  isf->ao   = ao;
  strcpy(isf->name, fname);
  return &isf->istream;
}

#else /* #ifdef USE_PORTAUDIO */

/* istream ao must not be include in this package. Anyway the creation
 * still exist but it always returns error.
 */

#include "istream68_pa.h"
#include "istream68_def.h"

istream68_t * istream68_pa_create(const char * fname, int mode)
{
  return 0;
}

#endif /* #ifdef USE_PORTAUDIO */

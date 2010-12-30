/*
 *                            sc68 - API
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
 * $Id: api68.c 126 2009-07-15 08:58:51Z benjihan $
 *
 */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_IO68_CONFIG_OPTION68_H
# include "io68/config_option68.h"
#else
# include "io68/default_option68.h"
#endif

#include <sc68/istream68.h> /* Need istream68.h before api68/sc68.h */

#include "sc68.h"

#include "mixer68.h"
#include "conf68.h"
#include "emu68/emu68.h"
#include "emu68/excep68.h"
#include "emu68/ioplug68.h"
#include "io68/io68.h"

/* file68 includes */
#include <sc68/init68.h>
#include <sc68/error68.h>
#include <sc68/string68.h>
#include <sc68/alloc68.h>
#include <sc68/file68.h>
#include <sc68/url68.h>
#include <sc68/rsc68.h>
#include <sc68/msg68.h>
#include <sc68/option68.h>
#include <sc68/audio68.h>

/* stardard includes */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TIME_DEF    (3 * 60)          /* default music time in seconds  */
#define TIMEMS_DEF  (TIME_DEF * 1000) /* default music time in millisec */

#if 0
#define TRAP_14_ADDR 0x600
/* ST xbios function emulator. */
/*  Just 4 SUPEREXEC in LOGICAL & some other music files */
static u8 trap14[] = {
  0x0c,0x6f,0x00,0x26,0x00,0x06,0x67,0x00,0x00,0x22,0x0c,0x6f,0x00,0x1f,0x00,
  0x06,0x67,0x00,0x00,0x28,0x0c,0x6f,0x00,0x22,0x00,0x06,0x67,0x00,0x00,0x86,
  0x0c,0x6f,0x00,0x0e,0x00,0x06,0x67,0x00,0x00,0xec,0x4e,0x73,0x48,0xe7,0xff,
  0xfe,0x20,0x6f,0x00,0x44,0x4e,0x90,0x4c,0xdf,0x7f,0xff,0x4e,0x73,0x48,0xe7,
  0xff,0xfe,0x41,0xef,0x00,0x44,0x4c,0x98,0x00,0x07,0x02,0x40,0x00,0x03,0xd0,
  0x40,0x16,0x38,0xfa,0x17,0x02,0x43,0x00,0xf0,0xe5,0x4b,0x36,0x7b,0x00,0x42,
  0xd6,0xc3,0x76,0x00,0x45,0xf8,0xfa,0x1f,0xd4,0xc0,0x43,0xf8,0xfa,0x19,0xd2,
  0xc0,0xe2,0x48,0x04,0x00,0x00,0x02,0x6b,0x1a,0x57,0xc3,0x18,0x03,0x0a,0x03,
  0x00,0xf0,0x44,0x04,0x48,0x84,0xd8,0x44,0x43,0xf1,0x40,0xfe,0xd8,0x44,0x02,
  0x41,0x00,0x0f,0xe9,0x69,0xc7,0x11,0x14,0x82,0x26,0x90,0x83,0x11,0x4c,0xdf,
  0x7f,0xff,0x4e,0x73,0x00,0x34,0x00,0x20,0x00,0x14,0x00,0x10,0x48,0xe7,0x00,
  0xc0,0x43,0xfa,0x00,0x20,0x70,0x00,0x20,0x7b,0x00,0x3e,0x41,0xfb,0x80,0x5e,
  0x23,0x88,0x00,0x00,0x58,0x40,0xb0,0x7c,0x00,0x24,0x66,0xec,0x20,0x09,0x4c,
  0xdf,0x03,0x00,0x4e,0x73,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x4e,0x75,0xc1,0x88,0x41,0xfa,0x00,0x0c,0x21,0x48,0x00,0x04,0x58,
  0x48,0xc1,0x88,0x4e,0x73,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,
};
#endif

struct _sc68_estack_s {
  /** Error string stack.  */
  char str[4][256];
  /** Error counter. */
  int  cnt;
};
typedef struct _sc68_estack_s sc68_estack_t;

struct _sc68_s {
  char           name[32];    /**< short name.                           */
  int            version;     /**< sc68 version.                         */
  void         * cookie;      /**< User private data.                    */

  /** 68k emulator. */
  emu68_t      * emu68;       /**< 68k emulator instance.                */
  emu68_parms_t  emu68_parms; /**< 68k emulator parameters.              */

  /** All IO chips.
   *  @notice Do not change order; debug68 haxxx depends on it).
   */
  io68_t *ymio,*mwio,*shifterio,*paulaio,*mfpio;

  ym_t         * ym;          /**< YM emulator.                          */
  mw_t         * mw;          /**< MicroWire emulator.                   */
  paula_t      * paula;       /**< Amiga emulator.                       */

  disk68_t     * disk;        /**< Current loaded disk.                  */
  music68_t    * mus;         /**< Current playing music.                */
  int            track;       /**< Current playing track.                */
  int            track_to;    /**< Track to set (0:n/a).                 */
  int            loop_to;     /**< Loop to set (-1:default 0:infinite).  */
  int            force_loop;  /**< Loop to set if default (-1:music).    */
  int            track_here;  /**< Force first track here.               */
  unsigned int   playaddr;    /**< Current play address in 68 memory.    */
  int            seek_to;     /**< Seek to this time (-1:n/a)            */
  config68_t   * config;      /**< Config.                               */
  int            remote;      /**< Allow remote access.                  */


  /** Playing time info. */
  struct {
    unsigned int def_ms;      /**< default time in ms.                   */
    unsigned int length_ms;   /**< current track length in ms.           */
    unsigned int elapsed_ms;  /**< number of elapsed ms.                 */
    unsigned int total;       /**< total sec so far.                     */
    unsigned int total_ms;    /**< total ms correction.                  */
  } time;

  /** Mixer info struture. */
  struct
  {
    unsigned int   rate;         /**< Sampling rate in hz.               */
    unsigned int * buffer;       /**< Current PCM buffer.                */
    int            bufmax;       /**< buffer allocated size.             */
    int            bufreq;       /**< Required buffer size for track.    */
    unsigned int * bufptr;       /**< Current PCM position.              */
    int            buflen;       /**< PCM count in buffer.               */
    int            stdbuflen;    /**< Default number of PCM per pass.    */
    unsigned int   cycleperpass; /**< Number of 68K cycles per pass.     */
    int            aga_blend;    /**< Amiga LR blend factor [0..65536].  */
    unsigned int   sample_cnt;   /**< Number of mixed PCM.               */
    unsigned int   pass_cnt;     /**< Current pass.                      */
    unsigned int   pass_total;   /**< Total number of pass.              */
    unsigned int   loop_cnt;     /**< Loop counter.                      */
    unsigned int   loop_total;   /**< Total # of loop (0:infinite).      */
    int            stp;          /**< pitch frq (fixed int 8).           */
    int            max_stp;      /**< max pitch frq (0:no seek).         */
  } mix;

  sc68_estack_t estack;          /**< error messages storage.            */

};

#ifndef DEBUG_SC68_O
# ifndef DEBUG
#  define DEBUG_SC68_O 0
# else
#  define DEBUG_SC68_O 1
# endif
#endif

static int           sc68_cat = msg68_NEVER;
static int           sc68_id;        /* counter for auto generated name. */
static volatile int  sc68_init_flag; /* Library init flag     */
static sc68_estack_t sc68_estack;    /* Library error message */
static int           sc68_sampling_rate_def = SAMPLING_RATE_DEF;
extern option68_t  * config68_options; /* conf68.c */
extern int config68_option_count;      /* conf68.c */

static inline const char * ok_int(const int const err) {
  return !err ? "success" : "failure";
}

#if 0
static inline const char * ok_ptr(const void * const err) {
  return err ? "success" : "failure";
}
#endif

static int stream_read_68k(sc68_t * sc68, unsigned int dest,
                           istream68_t * is, unsigned int sz)
{
  u8 * mem68 = emu68_memptr(sc68->emu68, dest, sz);

  if (!mem68) {
    return sc68_error_add(sc68, "libsc68: stream error (%s)",
                          emu68_error_get(sc68->emu68));
  }
  return (istream68_read(is, mem68, sz) == sz) ? 0 : -1;
}

static int init_emu68(sc68_t * const sc68, int * argc, char ** argv)
{
  int err;

  /* Initialize emu68 */
  sc68_debug(sc68,"libsc68: initialise 68k emulator\n");
  err = emu68_init(argc, argv);
  if (err) {
    sc68_error_add(sc68, "libsc68: failed to initialise 68k emulator");
    goto error;
  }

  /* Initialize chipset */
  sc68_debug(sc68,"libsc68: initialise chipsets\n");
  err = io68_init(argc, argv);
  if (err) {
    sc68_error_add(sc68, "libsc68: failed to chipsets");
  }

error:
  return err;
}

static void safe_io68_destroy(io68_t **pio)
{
  io68_destroy(*pio);
  *pio = 0;
}

static void safe_emu68_destroy(emu68_t **pemu)
{
  emu68_destroy(*pemu);
  *pemu = 0;
}

static int init68k(sc68_t * sc68, int log2mem, int emu68_debug)
{
  int err = -1;
  emu68_parms_t * const parms = &sc68->emu68_parms;


  if (sc68->emu68) {
    sc68_debug(sc68,"init_68k: found previous emu68\n");
    safe_emu68_destroy(&sc68->emu68);
    sc68_debug(sc68,"init_68k: previous emu68 destroyed\n");
  }

  /* setup parameters. */
  parms->name    = "sc68/emu68";
  parms->log2mem = log2mem;
  parms->clock   = EMU68_ATARIST_CLOCK;
  parms->debug   = emu68_debug;

  sc68_debug(sc68,
             "init_68k: '%s' mem:%d-bit(%dkB) clock:%uhz debug:%s\n",
             parms->name,
             parms->log2mem,parms->log2mem>10?1<<(parms->log2mem-10):0,
             parms->clock,parms->debug?"On":"Off");

  /* Do initialization. */
  sc68_debug(sc68,"init_68k: Creating emulators ...\n");

  sc68->emu68 = emu68_create(parms);
  if (!sc68->emu68) {
    sc68_error_add(sc68,"libsc68: create 68k emulator failed");
    goto error;
  }
  sc68_debug(sc68,"init_68k: - CPU emlator created\n");

  sc68->emu68->reg.sr   = 0x2000;
  sc68->emu68->reg.a[7] = sc68->emu68->memmsk+1-4;

  /* Initialize chipset */
  sc68_debug(sc68,"init_68k: - Chipset ...\n");

  sc68->ymio = ymio_create(sc68->emu68,0);
  sc68->ym   = ymio_emulator(sc68->ymio);
  if (!sc68->ymio) {
    sc68_error_add(sc68,"libsc68: create YM emulator failed");
    goto error;
  }
  sc68_debug(sc68,"init_68k:   - YM-2149\n");

  sc68->mwio = mwio_create(sc68->emu68,0);
  sc68->mw   = mwio_emulator(sc68->mwio);
  if (!sc68->mwio) {
    sc68_error_add(sc68,"libsc68: create MW emulator failed");
    goto error;
  }
  sc68_debug(sc68,"init_68k:   - MicroWire\n");

  sc68->shifterio = shifterio_create(sc68->emu68,0);
  if (!sc68->shifterio) {
    sc68_error_add(sc68,"libsc68: create Shifter emulator failed");
    goto error;
  }
  sc68_debug(sc68,"init_68k:   - Atari shifter\n");

  sc68->paulaio = paulaio_create(sc68->emu68,0);
  sc68->paula   = paulaio_emulator(sc68->paulaio);
  if (!sc68->paulaio) {
    sc68_error_add(sc68,"libsc68: create Paula emulator failed");
    goto error;
  }
  sc68_debug(sc68,"init_68k:   - Amiga Paula\n");

  sc68->mfpio = mfpio_create(sc68->emu68);
  if (!sc68->mfpio) {
    sc68_error_add(sc68,"libsc68: create MFP emulator failed");
    goto error;
  }
  sc68_debug(sc68,"init_68k:   - MFP\n");

  err = 0;
 error:
  if (err) {
    safe_io68_destroy(&sc68->ymio);
    safe_io68_destroy(&sc68->mwio);
    safe_io68_destroy(&sc68->shifterio);
    safe_io68_destroy(&sc68->paulaio);
    safe_io68_destroy(&sc68->mfpio);
    safe_emu68_destroy(&sc68->emu68);
  }

  sc68_debug(sc68,"init_68k: => %s\n", strok68(err));

  return err;
}

static int myconfig_get_int(config68_t * c,
                            const char * name,
                            int def)
{
  config68_type_t type;
  int v = def;
  option68_t * opt;

  sc68_debug(0,"getconfig: name='%s' def=%d\n", name, def);

  /* cli options are prior to config keys */
  opt = option68_get(name, 1);
  if (opt) {
    v = opt->val.num;
    sc68_debug(0,"getconfig: from cli name='%s' val=%d\n", name, v);
  } else if (c) {
    v = -1;
    type = config68_get(c, &v, &name);
    if (type != CONFIG68_INT) {
      v = def;
      sc68_debug(0,"getconfig: from cfg name='%s' val=%d\n", name, v);
    }
  }
  return v;
}

static const char * myconfig_get_str(config68_t * c,
                                     const char * name,
                                     const char * def)
{
  config68_type_t type;
  const char * r = def;
  if (c) {
    int idx = -1;
    type = config68_get(c, &idx, &name);
    if (type == CONFIG68_STR) {
      r = name;
    }
  }
  return r;
}


static void set_config(sc68_t * sc68)
{
  config68_t * c = sc68->config;
  const char * lmusic, * rmusic;

  sc68->version       = myconfig_get_int(c, "version",       PACKAGE_VERNUM);
  sc68->remote        = myconfig_get_int(c, "allow-remote",  1);
  sc68->mix.aga_blend = myconfig_get_int(c, "amiga-blend",   0x4000);
  sc68->track_here    = myconfig_get_int(c, "force-track",   0);
  sc68->time.def_ms   = myconfig_get_int(c, "default-time",  TIME_DEF) * 1000;
  sc68->mix.rate      = myconfig_get_int(c, "sampling-rate", SAMPLING_RATE_DEF);
  sc68->force_loop    = myconfig_get_int(c, "force-loop",    -1);
  sc68->mix.max_stp   = myconfig_get_int(c, "seek-speed",    0xF00);
  sc68->time.total    = myconfig_get_int(c, "total-time",    0);
  sc68->time.total_ms = myconfig_get_int(c, "total-ms",      0);

  if (sc68->time.def_ms < 1000) {
    sc68->time.def_ms = TIMEMS_DEF;
  }

  rsc68_get_path(0,0,&lmusic, &rmusic);
  if (!lmusic) {
    lmusic = myconfig_get_str(c, "music_path", 0);
    rsc68_set_music(lmusic);
  }
  if (!rmusic) {
    rmusic = myconfig_get_str(c, "remote_music_path", 0);
    rsc68_set_remote_music(rmusic);
  }

}

static void myconfig_set_int(config68_t * c,
                             const char * name,
                             int v)
{
  if (c) {
    config68_set(c, -1, name, v, 0);
  }
}

static void get_config(sc68_t * sc68)
{
  config68_t * c = sc68->config;

  myconfig_set_int(c, "version",       PACKAGE_VERNUM);
  /* Do not change user config ! */
  /*   myconfig_set_int(c, "aga_blend",   sc68->mix.aga_blend); */
  /*   myconfig_set_int(c, "force_track",   sc68->track_here); */
  /*   myconfig_set_int(c, "default_time",  (sc68->time.def_ms+999)/1000u); */
  /*   myconfig_set_int(c, "sampling_rate", sc68->mix.rate); */
  /*   myconfig_set_int(c, "force_loop",    sc68->force_loop); */
  /*   myconfig_set_int(c, "seek_speed",    sc68->mix.max_stp); */
  /*   myconfig_set_int(c, "allow_remote",  sc68->remote); */
  myconfig_set_int(c, "total_time",    sc68->time.total);
  myconfig_set_int(c, "total_ms",      sc68->time.total_ms);
}

int sc68_config_load(sc68_t * sc68)
{
  int err = -1;

  sc68_debug(sc68,"sc68_config_load() {\n");
  if (sc68) {
    if (!sc68->config) {
      sc68->config = config68_create(0);
    }
    err = config68_load(sc68->config);
    set_config(sc68);
  }
  sc68_debug(sc68,"} sc68_config_load() => [%s]\n",strok68(err));
  return err;
}

int sc68_config_save(sc68_t * sc68)
{
  int err = -1;
  sc68_debug(sc68,"sc68_config_save() {\n");
  if (sc68) {
    get_config(sc68);
    err = config68_save(sc68->config);
  }
  sc68_debug(sc68,"} sc68_config_save() => [%s]\n",strok68(err));
  return err;
}

int sc68_config_idx(sc68_t * sc68, const char * name)
{
  return config68_get_idx(sc68 ? sc68->config : 0, name);
}

config68_type_t sc68_config_range(sc68_t * sc68, int idx,
                                  int * min, int * max, int * def)
{
  return config68_range(sc68 ? sc68->config : 0, idx, min, max, def);
}

config68_type_t sc68_config_get(sc68_t * sc68,
                                int * idx, const char ** name)
{
  return sc68
    ? config68_get(sc68->config, idx, name)
    : CONFIG68_ERR;
}

config68_type_t sc68_config_set(sc68_t * sc68,
                                int idx,
                                const char * name,
                                int v,
                                const char * s)
{
  return sc68
    ? config68_set(sc68->config,idx,name,v,s)
    : CONFIG68_ERR;
}

void sc68_config_apply(sc68_t * sc68)
{
  if (sc68) {
    config68_valid(sc68->config);
    set_config(sc68);
  }
}


int sc68_init(sc68_init_t * init)
{
  int err = -1;
  option68_t * opt;
  sc68_init_t dummy_init;

  if (sc68_init_flag) {
    err = sc68_error_add(0, "libsc68: already initialized");
    goto error_no_shutdown;
  }

  if (!init) {
    memset(&dummy_init,0,sizeof(dummy_init));
    init = &dummy_init;
  }

  sc68_cat = msg68_cat("sc68","sc68 library",DEBUG_SC68_O);

  /* 1st thing to do : set debug handler. */
  msg68_set_handler((msg68_t)init->msg_handler);
  msg68_set_cookie(0);

  msg68_cat_filter(init->debug_clr_mask,init->debug_set_mask);

  sc68_debug(0, "libsc68: initializing\n");

  /* Init config module */
  config68_init();

  /* Intialize file68. */
  init->argc = file68_init(init->argc, init->argv);

  if (config68_options) {
    option68_append(config68_options,config68_option_count);
    init->argc = option68_parse(init->argc, init->argv, 0);
  }

  /* Initialize emulators. */
  err = init_emu68(0, &init->argc, init->argv);

  /* Set default sampling rate. */
  if (!err) {
    err = sc68_sampling_rate(0, SC68_SPR_DEFAULT);
    if (err > 0) {
      sc68_sampling_rate_def = err;
      err = 0;
    }
  }

  /* $$$: No good */
  opt = option68_get("debug", 1);
  if (opt) {
    int val = strtol(opt->val.str,0,0);
    msg68_cat_filter(~0,val);
  }
  sc68_debug(0,"libsc68: message system mask -- %08X\n",
             msg68_cat_filter(0,0));

  sc68_init_flag = !err;

  if (err) {
    sc68_shutdown();
  }
 error_no_shutdown:
  sc68_debug(0,"libsc68: initialized -- %s\n", ok_int(err));
  return -!!err;
}


void sc68_shutdown(void)
{
  sc68_debug(0,"libsc68: shutdown\n");
  if (sc68_init_flag) {
    sc68_init_flag = 0;
    config68_shutdown();
  }
  sc68_debug(0,"libsc68: shutdowned -- %s\n",ok_int(0));
}

sc68_t * sc68_create(sc68_create_t * create)
{
  const int log2mem = 0;
  sc68_t *sc68 = 0;
  sc68_create_t dummy_create;

  if (!create) {
    memset(&dummy_create,0,sizeof(dummy_create));
    create = &dummy_create;
  }
  sc68_debug(0,"libsc68: creating an new instance\n");

  /* Alloc SC68 struct. */
  sc68 = calloc68(sizeof(sc68_t));
  if (!sc68) {
    goto error;
  }
  
  /* User private data. */
  sc68->cookie = create->cookie;

  /* Pick a short name */
  if (create->name) {
    strncpy(sc68->name, create->name, sizeof(sc68->name));
  } else {
    snprintf(sc68->name,sizeof(sc68->name),"sc68#%02d",++sc68_id);
  }
  sc68->name[sizeof(sc68->name)-1] = 0;

  /* Load config file */
  sc68_config_load(sc68);

  /* Override config. */
  if (create->sampling_rate) {
    sc68->mix.rate = create->sampling_rate;
  }
  if (!sc68->mix.rate) {
    sc68->mix.rate = sc68_sampling_rate_def;
  }
  if (!sc68->time.def_ms) {
    sc68->time.def_ms = 180000;
  }

  /* Create 68k emulator and pals. */
  if (init68k(sc68, log2mem, create->emu68_debug)) {
    goto error;
  }

  /* Set IO chipsets sampling rates */
  sc68->mix.rate = sc68_sampling_rate(sc68, sc68->mix.rate);
  if (sc68->mix.rate <= 0) {
    sc68_error_add(sc68,"invalid sampling rate -- *%dhz*\n", sc68->mix.rate);
    goto error;
  }

  create->sampling_rate = sc68->mix.rate;
  sc68_debug(sc68,"sampling rate -- *%dhz*\n", create->sampling_rate);

  /* Finally gets all pathes. */
  /*   rsc68_get_path(&init->shared_path, */
  /*               &init->user_path, */
  /*               &init->lmusic_path, */
  /*               &init->rmusic_path); */

  /*   debugmsg68(-1,"sc68_create: shared-path=[%s]\n",init->shared_path); */
  /*   debugmsg68(-1,"sc68_create: user-path=[%s]\n",init->user_path); */
  /*   debugmsg68(-1,"sc68_create: music-path=[%s]\n",init->lmusic_path); */
  /*   debugmsg68(-1,"sc68_create: music-rpath=[%s]\n",init->rmusic_path); */

  /*   sc68_unic = sc68; */

  sc68_debug(0,"create *%s* -- %s\n", sc68->name, ok_int(0));
  return sc68;

 error:
  sc68_destroy(sc68);
  sc68 = 0;
  sc68_debug(sc68,"libsc68: create -- %s\n", ok_int(-1));
  return 0;
}

void sc68_destroy(sc68_t * sc68)
{
  sc68_debug(sc68,"sc68_destroy() {\n");
  if (sc68) {
    sc68_close(sc68);
    sc68_config_save(sc68);
    file68_shutdown();
    emu68_destroy(sc68->emu68);
    free68(sc68);
  }
  sc68_debug(sc68,"} sc68_destroy()\n");
}

int sc68_sampling_rate(sc68_t * sc68, int hz)
{
  switch (hz) {
  case SC68_SPR_QUERY:
    hz = sc68 ? sc68->mix.rate : sc68_sampling_rate_def;
    break;
  default:
    if (sc68) {
      hz = ymio_sampling_rate(sc68->ymio,hz);
      sc68_debug(sc68,"sampling rate after ym -- %dhz\n",hz);
      hz = mwio_sampling_rate(sc68->mwio,hz);
      sc68_debug(sc68,"sampling rate after after microwire -- %dhz\n",hz);
      hz = paulaio_sampling_rate(sc68->paulaio,hz);
      sc68_debug(sc68,"sampling rate after after paula -- %dhz\n",hz);
      sc68->mix.rate = hz;
      audio68_sampling_rate(hz);
      msg68_info("%s: sampling rate -- *%dhz*\n", sc68->name, hz);
    } else {
      const int min = SAMPLING_RATE_MIN;
      const int max = SAMPLING_RATE_MAX;
      const int def = SAMPLING_RATE_DEF;
      if (hz == SC68_SPR_DEFAULT)
        hz = def;
      if (hz <  min) hz = min;
      if (hz >  max) hz = max;
      /* Assuming interface audio accepts this value. */
      audio68_sampling_rate(hz);
      sc68_sampling_rate_def = hz;
      msg68_info("libsc68: default sampling rate -- *%dhz*\n", hz);
    }
  }
  return hz;
}

void sc68_set_share(sc68_t * sc68, const char * path)
{
  rsc68_set_share(path);
}

void sc68_set_user(sc68_t * sc68, const char * path)
{
  rsc68_set_user(path);
}

static unsigned int calc_disk_time(sc68_t * sc68, disk68_t * d)
{
  return (sc68 && sc68->disk == d && d->nb_six == 1 && d->mus == sc68->mus)
    ? sc68->time.length_ms
    : d->time_ms;
}

static int calc_loop_total(int force_loop, int loop_to, int mus_loop)
{
  return
    (loop_to == -1)
    ? (force_loop == -1 ? mus_loop : force_loop)
    : loop_to;
}

#if 0
static unsigned int fr_to_ms(unsigned int frames, unsigned int hz)
{
  u64 ms;

  ms = frames;
  ms *= 1000u;
  ms /= hz;

  return (unsigned int) ms;
}
#endif

static unsigned int ms_to_fr(unsigned int ms, unsigned int hz)
{
  u64 fr;

  fr =  ms;
  fr *= hz;
  fr /= 1000u;

  return (unsigned int ) fr;
}

/** Start current music of current disk.
 */
static int apply_change_track(sc68_t * sc68)
{
  u32 a0;
  disk68_t * d;
  music68_t * m;
  int track;
  u8 * memptr;
  int status;

  if (!sc68 || !sc68->disk) {
    return SC68_MIX_ERROR;
  }
  if (track = sc68->track_to, !track) {
    return SC68_MIX_OK;
  }

  sc68->track_to = 0;
  sc68->mix.loop_cnt = 0;
  /* -1 : stop */
  if (track == -1) {
    sc68_debug(sc68,"apply_change_track() : stop\n");
    sc68->mus = 0;
    sc68->track = 0;
    sc68->time.total    += sc68->time.elapsed_ms / 1000u;
    sc68->time.total_ms += sc68->time.elapsed_ms % 1000u;
    sc68->time.total    += sc68->time.total_ms / 1000u;
    sc68->time.total_ms %= 1000u;
    sc68->time.elapsed_ms = 0;
    sc68->time.length_ms  = 0;
    return SC68_END | SC68_CHANGE;
  }

  sc68_debug(sc68,"apply_change_track(%d) : enter\n", track);

  d = sc68->disk;
  if (track < 1 || track > d->nb_six) {
    sc68_error_add(sc68, "libsc68: track #%d out of range [1..%d]",
                   track, d->nb_six);
    return SC68_MIX_ERROR;
  }
  m = d->mus + track - 1;

  sc68_debug(sc68," -> Starting track #%02d - [%s]:\n", track, m->name);

  /* ReInit 68K & IO */
  emu68_mem_reset(sc68->emu68);
  emu68_ioplug_unplug_all(sc68->emu68);

  if (m->hwflags.bit.amiga) {
    sc68_debug(sc68," -> Add Paula hardware\n");
    emu68_ioplug(sc68->emu68, sc68->paulaio);
    sc68_debug(sc68," -> Set PAULA as interruptible\n");
    emu68_set_interrupt_io(sc68->emu68, sc68->paulaio);
  }
  if (m->hwflags.bit.ym) {
    sc68_debug(sc68," -> Add SHIFTER hardware\n");
    emu68_ioplug(sc68->emu68, sc68->shifterio);
    sc68_debug(sc68," -> Add YM hardware\n");
    emu68_ioplug(sc68->emu68, sc68->ymio);
    sc68_debug(sc68," -> Add MFP hardware\n");
    emu68_ioplug(sc68->emu68, sc68->mfpio);
    sc68_debug(sc68," -> Set MFP as interruption\n");
    emu68_set_interrupt_io(sc68->emu68, sc68->mfpio);
  }
  if (m->hwflags.bit.ste) {
    sc68_debug(sc68," -> Add MW (STE) hardware\n");
    emu68_ioplug(sc68->emu68, sc68->mwio);
  }
  emu68_reset(sc68->emu68);

  /* Init exceptions */
  emu68_memset(sc68->emu68,0,0,0);

  memptr = emu68_memptr(sc68->emu68,0,1<<15);
  memptr[0] = 0x4e;          /* RTE */
  memptr[1] = 0x73;          /* RTE */
  memptr[0x41a] = 0;         /* Zound Dragger */
  memptr[0x41b] = 0x10;      /* Zound Dragger */

#if 0
  memptr[TRAP_VECTOR(14)+0] = (u8) (TRAP_14_ADDR >> 24); /* XBIOS */
  memptr[TRAP_VECTOR(14)+1] = (u8) (TRAP_14_ADDR >> 16);
  memptr[TRAP_VECTOR(14)+2] = (u8) (TRAP_14_ADDR >> 8);
  memptr[TRAP_VECTOR(14)+3] = (u8) (TRAP_14_ADDR);
  /* Copy xbios routine */
  emu68_memput(sc68->emu68,TRAP_14_ADDR,trap14, sizeof(trap14));
#endif

  /* Address in 68K memory : default $8000 */
  sc68->playaddr = a0 = (!m->a0) ? 0x8000 : m->a0;
  sc68_debug(sc68," -> play address %06x\n", sc68->playaddr);

  /* Check external replay */
  if (m->replay) {
    int err;
    int size = 0;
    istream68_t * is;
    char rname[256];

    sc68_debug(sc68, " -> external replay '%s'\n", m->replay);
    /*     is = rsc68_open(rsc68_replay, m->replay, 1, 0); */

    strcpy(rname,"RSC68://replay/");
    strcat68(rname, m->replay, sizeof(rname)-1);
    rname[sizeof(rname)-1] = 0;

    is = url68_stream_create(rname, 1);
    err = istream68_open(is);
    err = err || (size = istream68_length(is), size < 0);
    err = err || stream_read_68k(sc68, a0, is, size);
    istream68_destroy(is);
    if (err) {
      return SC68_MIX_ERROR;
    }
    sc68_debug(sc68," -> external replay [%06x-%06x]\n", a0, a0+size);
    a0 = a0 + ((size + 1) & -2);
  }

  /* Copy Data into 68K memory */
  if (emu68_memput(sc68->emu68, a0, (u8 *)m->data, m->datasz)) {
    sc68_debug(sc68," -> Failed music data [%06x-%06x]\n", a0, a0+m->datasz);
    sc68_error_add(sc68,"libsc68: %s",emu68_error_get(sc68->emu68));
    return SC68_MIX_ERROR;
  }

  sc68_debug(sc68," -> music data [%06x-%06x)\n", a0, a0+m->datasz);

  if (sc68->mix.rate <=0) sc68->mix.rate = sc68_sampling_rate_def;
  if (sc68->mix.rate < SAMPLING_RATE_MIN ||
      sc68->mix.rate > SAMPLING_RATE_MAX) {
    sc68_error_add(sc68,"invalid sampling rate -- %dhz\n", sc68->mix.rate);
    return SC68_MIX_ERROR;
  }

  sc68->mix.bufptr = 0;
  sc68->mix.buflen = 0;
  sc68->mix.sample_cnt = 0;
  sc68->mix.pass_cnt = 0;
  sc68->time.elapsed_ms = 0;
  sc68->mix.loop_total =
    calc_loop_total(sc68->force_loop,sc68->loop_to,m->loop);

  sc68_debug(sc68," -> loop            : %u\n", sc68->mix.loop_total);

  if (!m->frames) {
    sc68->mix.pass_total = ms_to_fr(sc68->time.def_ms, m->frq);
    sc68->time.length_ms = sc68->time.def_ms;
    sc68_debug(sc68," -> default time ms : %u\n", sc68->time.def_ms);
  } else {
    sc68->mix.pass_total = m->frames;
    sc68->time.length_ms = m->time_ms;
    sc68_debug(sc68," -> time ms         : %u\n", m->time_ms);
  }
  sc68_debug(sc68," -> length ms       : %u\n", sc68->time.length_ms);
  sc68_debug(sc68," -> frames          : %u\n", sc68->mix.pass_total);
  sc68->mix.cycleperpass =
    (m->frq == 50 && sc68->emu68->clock == EMU68_ATARIST_CLOCK)
    ? 160256 /* exact value for genuine Atari ST */
    : (sc68->emu68->clock / m->frq)
    ;

  if (m->hwflags.bit.ym) {
    cycle68_t cycles;
    /* Make sure ym-cycle are mutiple of 32 as required by current
     * emulator.
     *
     * $$$ I am not sure this works in all cases of frequency but it
     * is should be ok as far as cpu and ym frequency are multiple.
     *
     * $$$ In fact I am now pretty sure it does not work if
     * frequencies are not multiple.
     */
    cycles = ymio_cycle_cpu2ym(sc68->ymio,sc68->mix.cycleperpass);
    cycles = (cycles+31) & ~31;
    sc68->mix.cycleperpass = ymio_cycle_ym2cpu(sc68->ymio,cycles);

    /* verify */
    cycles = ymio_cycle_cpu2ym(sc68->ymio,sc68->mix.cycleperpass);
    sc68_debug(sc68," -> round cycleperpass to %u => %u ym-cycle [%s]\n",
               sc68->mix.cycleperpass,cycles, strok68(cycles&31));
  }

  sc68->mix.cycleperpass = (sc68->mix.cycleperpass+31) & ~31;
  sc68_debug(sc68," -> cycle/frame     : %u\n", sc68->mix.cycleperpass);

  /* Compute size of buffer needed for cycleperpass length at current rate. */
  if (1) {
    u64 len;
    len  = sc68->mix.rate;
    len *= sc68->mix.cycleperpass;
    len /= sc68->emu68->clock;
    sc68->mix.stdbuflen = (int) len;
  }

  /* Compute *REAL* required size (in PCM) for buffer and realloc */
  if (1) {
    sc68->mix.bufreq = m->hwflags.bit.ym
      ? ymio_buffersize(sc68->ymio, sc68->mix.cycleperpass)
      : sc68->mix.stdbuflen
      ;

    /* Should not happen. Anyway it does not hurt. */
    if (m->hwflags.bit.amiga && sc68->mix.stdbuflen > sc68->mix.bufreq) {
      sc68->mix.bufreq = sc68->mix.stdbuflen;
    }

    sc68_debug(sc68," -> required PCM buffer size (pcm): %u\n", sc68->mix.bufreq);
    sc68_debug(sc68," ->  current PCM buffer size (pcm): %u\n", sc68->mix.bufmax);
    if (sc68->mix.bufreq > sc68->mix.bufmax) {
      u32 * oldbuf = sc68->mix.buffer;

      sc68_debug(sc68," -> Alloc new PCM buffer of %u pcm, %u bytes\n",
                 sc68->mix.bufreq, sc68->mix.bufreq << 2);
      sc68->mix.buffer = sc68_alloc(sc68->mix.bufreq << 2);
      if (!sc68->mix.buffer) {
        sc68_error_add(sc68,"libsc68: failed to allocate new sample buffer");
        return SC68_MIX_ERROR;
      }

      sc68->mix.bufmax = sc68->mix.bufreq;
      sc68_debug(sc68," -> Copy %d old PCM to new buffer\n", sc68->mix.buflen);
      mixer68_copy(sc68->mix.buffer,sc68->mix.bufptr,sc68->mix.buflen);
      sc68->mix.bufptr = sc68->mix.buffer;
      sc68_debug(sc68," -> Free old PCM buffer\n");
      sc68_free(oldbuf);
    }
  }
  sc68_debug(sc68," -> buffer length   : %u pcm, %d bytes\n",
             sc68->mix.bufreq, sc68->mix.bufreq << 2);

  /* Set 68K register value for INIT */
  sc68_debug(sc68," -> Running music init code...\n");

  sc68->emu68->reg.d[0] = m->d0;
  sc68->emu68->reg.d[1] = !m->hwflags.bit.ste;
  sc68->emu68->reg.d[2] = m->datasz;
  sc68->emu68->reg.a[0] = a0;
  sc68->emu68->reg.a[7] = sc68->emu68->memmsk+1-16;
  sc68->emu68->reg.pc = sc68->playaddr;
  sc68->emu68->reg.sr = 0x2300;
  if (m->frq == 60 && sc68->shifterio) {
    sc68_debug(sc68," -> Force shifter to 60Hz...\n");
    shifterio_reset(sc68->shifterio,60);
  }
  /* EMU68_set_registers(&sc68->reg); */
  sc68->emu68->cycle = 0;
  emu68_pushl(sc68->emu68, sc68->playaddr+8);
  status = emu68_finish(sc68->emu68, 10000000u);

  /* Set 68K PC register to music play address */
  sc68->emu68->reg.pc = sc68->playaddr + 8;
  sc68->emu68->reg.sr = 0x2300;
  sc68->emu68->cycle  = 0;
  sc68->mus           = m;
  sc68->track         = track;

  if ( status != EMU68_NRM ) {
    sc68_debug(sc68," -> ERROR (status=%d)\n", status);
    sc68_error_add(sc68, "libsc68: abnormal 68K status in init code (%d)",
                   status);
    return SC68_MIX_ERROR;
  }
  sc68_debug(sc68," -> OK\n");
  return SC68_CHANGE;
}

static unsigned int calc_current_ms(sc68_t * sc68)
{
  u64 ms;

  ms = sc68->mix.pass_cnt + (sc68->mix.loop_cnt * sc68->mix.pass_total);
  ms *= sc68->mix.cycleperpass;
  ms /= (sc68->emu68->clock / (1000u) ); /* $$$ divided per 1000 or 1024 ?  */
  return sc68->time.elapsed_ms = (unsigned int) ms;
}

int sc68_process(sc68_t * sc68, void * buf16st, int n)
{
  int ret = SC68_IDLE;

  if (!sc68 || n<0) {
    return SC68_MIX_ERROR;
  }

  if (!sc68->mus) {
    ret = apply_change_track(sc68);
  }

  if (!sc68->mus) {
    return SC68_MIX_ERROR;
  }

  if (n==0) {
    return ret;
  }

  if (!buf16st) {
    return SC68_MIX_ERROR;
  }

  while (n > 0) {
    int code;
    code = apply_change_track(sc68);

    if (code == SC68_MIX_ERROR) {
      return code;
    }
    ret |= code;
    if (code & SC68_END) {
      break;
    }

    if (sc68->mix.buflen <= 0) {
      int status;
      /* Not idle */
      ret &= ~SC68_IDLE;

      emu68_pushl(sc68->emu68, sc68->playaddr+8);
      status = emu68_finish(sc68->emu68, 10000000u);
      if (status == EMU68_NRM) {
        status = emu68_interrupt(sc68->emu68, sc68->mix.cycleperpass);
      }
      if (status != EMU68_NRM) {
        sc68_error_add(sc68, "abnormal 68K status in play code (%d)\n", status);
        return SC68_MIX_ERROR;
      }

      /* Reset pcm pointer. */
      sc68->mix.bufptr = sc68->mix.buffer;
      sc68->mix.buflen = sc68->mix.bufreq;

      if (sc68->mus->hwflags.bit.amiga) {
        /* Amiga - Paula */
        paula_mix(sc68->paula,(s32*)sc68->mix.bufptr,sc68->mix.buflen);
        mixer68_blend_LR(sc68->mix.bufptr, sc68->mix.bufptr, sc68->mix.buflen,
                         sc68->mix.aga_blend, 0, 0);
      } else {
        if (sc68->mus->hwflags.bit.ym) {
          int err =
            ymio_run(sc68->ymio, (s32*)sc68->mix.bufptr,
                     sc68->mix.cycleperpass);
          if (err < 0) {
            ret = SC68_MIX_ERROR;
            sc68->mix.buflen = 0;
            break;
          }
          sc68->mix.buflen = err;
        }

/*         switch ( ymio_emulator(sc68->ymio) -> type ) { */
/*         case  YM_EMUL_DUMP: */
/*           /\* Special case for register dump: no transform *\/ */
/*           if (sc68->mus->hwflags.bit.ste) { */
/*             /\* STE - MicroWire *\/ */
/*             mw_mix(sc68->mw, 0, sc68->mix.buflen); */
/*           } */
/*           break; */
/*         default: */

          if (sc68->mus->hwflags.bit.ste) {
            /* STE - MicroWire */
            mw_mix(sc68->mw, (s32 *)sc68->mix.bufptr, sc68->mix.buflen);
          } else {
            /* No STE, process channel duplication. */
            mixer68_dup_L_to_R(sc68->mix.bufptr, sc68->mix.bufptr,
                               sc68->mix.buflen, 0);
          }

/*         } */
      }

      /* Advance time */
      calc_current_ms(sc68);
      ++sc68->mix.pass_cnt;
      sc68->mix.sample_cnt += sc68->mix.buflen;

      /* Reach end of track */
      if (sc68->mix.pass_total && sc68->mix.pass_cnt >= sc68->mix.pass_total) {
        int next_track;
        sc68->mix.pass_cnt = 0;
        ret |= SC68_LOOP;
        ++sc68->mix.loop_cnt;
        if (sc68->mix.loop_total &&
            sc68->mix.loop_cnt >= sc68->mix.loop_total) {
          next_track = sc68->track+1;
          sc68->track_to = (next_track > sc68->disk->nb_six) ? -1 : next_track;
          sc68->seek_to = -1;
        }
      }
    }

    /* Copy to destination buffer. */
    if (sc68->mix.buflen > 0) {

      int seek_to = sc68->seek_to;
      int stp = 0;

      /* Do speed up */
      if (seek_to != -1) {
        unsigned int ms = sc68->time.elapsed_ms;
        if (ms >= (unsigned int)seek_to) {
          sc68->seek_to = -1;
        } else {
          const int minstp = 0x010;
          const int maxstp = sc68->mix.max_stp;
          int newstp;

          if (maxstp < minstp) {
            /* no max stp : just discard this buffer */
            sc68->mix.buflen = 0;
            continue;
          }

          stp = sc68->mix.stp;  /* Current stp */

          /* Got number of ms to seek */
          ms = seek_to - ms;
          newstp = (ms >> 4);
          if (stp < newstp) {
            stp += 2;
          } if (stp > newstp) {
            stp -= 2;
          }
          if (stp < minstp) {
            stp = minstp;
          } else if (stp > maxstp) {
            stp = maxstp;
          }

        }
      }

      sc68->mix.stp = stp;
      stp += 0x100;

      if (stp == 0x100) {
        /* Speed copy */
        int len = sc68->mix.buflen <= n ? sc68->mix.buflen : n;
        mixer68_copy((u32 *)buf16st,sc68->mix.bufptr,len);
        buf16st = (u32 *)buf16st + len;
        sc68->mix.bufptr += len;
        sc68->mix.buflen -= len;
        n -= len;
      } else {
        /* Slow copy */
        u32 *b = (u32 *)buf16st, *bufptr = sc68->mix.bufptr;
        int len = (sc68->mix.buflen <= n ? sc68->mix.buflen : n) << 8;
        int j = 0;
        do {
          *b++ = bufptr[j>>8];
          j += stp;
        } while (--n && j < len );
        buf16st = b;
        j >>= 8;
        sc68->mix.bufptr += j;
        sc68->mix.buflen -= j;
        if (sc68->mix.buflen < 0) {
          sc68->mix.buflen = 0;
        }
      }
    }
  }

  /* Fill buffer with null PCM */
  if (n > 0) {
    mixer68_fill((u32 *)buf16st,n,0);
  }

  return ret;
}

int sc68_verify(istream68_t * is)
{
  return file68_verify(is);
}

int sc68_verify_url(const char * url)
{
  return file68_verify_url(url);
}

int sc68_verify_mem(const void * buffer, int len)
{
  return file68_verify_mem(buffer,len);
}

int sc68_is_our_url(const char * url, const char *exts, int * is_remote)
{
  return file68_is_our_url(url,exts,is_remote);
}

static int load_disk(sc68_t * sc68, disk68_t * d)
{
  int track;
  if (!sc68 || !d) {
    goto error;
  }

  if (sc68->disk) {
    sc68_error_add(sc68,"libsc68: %s","disk already loaded");
    goto error;
  }

  sc68->disk = d;
  sc68->track = 0;
  sc68->mus = 0;

  track = sc68->track_here;
  if (track > d->nb_six) {
    track = d->default_six;
  }

  return sc68_play(sc68, track, -1);

 error:
  free68(d);
  return -1;
}

int sc68_load(sc68_t * sc68, istream68_t * is)
{
  return load_disk(sc68, file68_load(is));
}

int sc68_load_url(sc68_t * sc68, const char * url)
{
  return load_disk(sc68, file68_load_url(url));
}

int sc68_load_mem(sc68_t * sc68, const void * buffer, int len)
{
  return load_disk(sc68, file68_load_mem(buffer, len));
}


sc68_disk_t sc68_load_disk(istream68_t * is)
{
  return (sc68_disk_t) file68_load(is);
}

sc68_disk_t sc68_load_disk_url(const char * url)
{
  return (sc68_disk_t) file68_load_url(url);
}

sc68_disk_t sc68_disk_load_mem(const void * buffer, int len)
{
  return (sc68_disk_t) file68_load_mem(buffer, len);
}


int sc68_open(sc68_t * sc68, sc68_disk_t disk)
{
  if (!disk) {
    sc68_close(sc68);
    return -1; /* Not an error but notifiy no disk has been loaded */
  }
  if (!sc68) {
    return -1;
  }
  return load_disk(sc68, disk);
}

void sc68_close(sc68_t * sc68)
{
  if (!sc68 || !sc68->disk) {
    return;
  }

  sc68_debug(sc68,"sc68_close() : enter\n");

  free68(sc68->disk);
  sc68->disk = 0;
  sc68->mus = 0;
  sc68->track = 0;
  sc68->track_to = 0;
  sc68->seek_to = -1;

  sc68_debug(sc68,"sc68_close() : close\n");
}

int sc68_tracks(sc68_t * sc68)
{
  return (sc68 && sc68->disk) ? sc68->disk->nb_six : -1;
}

int sc68_play(sc68_t * sc68, int track, int loop)
{
  disk68_t * d;

  sc68_debug(sc68,"sc68_play(sc68:%s track:%d, loop:%d) : enter\n",
             sc68?sc68->name:"<NUL>", track, loop);

  if (!sc68) {
    return -1;
  }
  d = sc68->disk;
  if (!d) {
    return -1;
  }

  /* track == -1 : read current track or current loop. */
  if (track == -1) {
    return loop
      ? sc68->mix.loop_cnt
      : sc68->track;
  }

  /* track == 0 : try force-track. */
  if (track == 0 && sc68->track_here) {
    track = sc68->track_here;
    if (track > d->default_six) track = 0;
  }

  /* track == 0 : force-track out of range, restore disk default. */
  if (track == 0) {
    track = d->default_six + 1;
  }

  /* Check track range. */
  if (track <= 0 || track > d->nb_six) {
    return sc68_error_add(sc68,"libsc68: track #%d out of range [1..%d]",
                          track, d->nb_six);
  }

  /* Set change track. Real track loading occurs during process thread to
     avoid multi-threading bug. */
  sc68->track_to = track;
  sc68->seek_to  = -1;
  sc68->loop_to  = loop;

  return 0;
}

int sc68_stop(sc68_t * sc68)
{
  if (!sc68 || !sc68->disk) {
    return -1;
  }
  sc68->track_to = -1;
  sc68->seek_to  = -1;
  return 0;
}

/** $$$ loop stuff is broken if loop differs some tracks */
int sc68_seek(sc68_t * sc68, int time_ms, int * is_seeking)
{
  disk68_t * d;

  if (!sc68 || (d=sc68->disk, !d)) {
    return -1;
  }

  if (time_ms == -1) {
    /* Read current */
    if (is_seeking) {
      *is_seeking = sc68->seek_to != -1;
    }
    if (!sc68->mus) {
      return -1;
    } else {
      int loop =
        calc_loop_total(sc68->force_loop, sc68->loop_to, sc68->mus->loop);
      return (sc68->mus->start_ms * loop) + sc68->time.elapsed_ms;
    }
  } else {
    int i,n;
    unsigned int start_ms;
    unsigned int end_ms = 0;

    for (i=0, n=d->nb_six ; i<n; ++i) {
      unsigned int ms = (unsigned int) time_ms;
      int loop =
        calc_loop_total(sc68->force_loop, sc68->loop_to, d->mus[i].loop);

      start_ms = end_ms;
      end_ms   = start_ms
        + ((d->mus+i == sc68->mus)
           ? sc68->time.length_ms :
           d->mus[i].time_ms) * loop;

      if (ms >= start_ms && ms < end_ms) {
        unsigned int cur_ms  = start_ms;
        sc68_debug(sc68,"Find track #%d [%u - %u]\n", i+1, start_ms, end_ms);
        if (i+1 == sc68->track) {
          /* Same track : return current time */
          cur_ms += sc68->time.elapsed_ms;
        } else {
          /* Change track : current time is start of new track */
          sc68->track_to = i+1;
        }

        if (ms > cur_ms) {
          /* real seek forward */
          if (is_seeking) *is_seeking = 1;
          sc68->seek_to = ms - start_ms;
          sc68_debug(sc68,"SEEK-TO %d, cur:%d\n", sc68->seek_to, cur_ms);
        } else {
          if (is_seeking) *is_seeking = 0;
          sc68->seek_to = -1;
          sc68_debug(sc68,"NO-SEEK-TO cur:%d\n", cur_ms);
        }
        return (int) cur_ms;
      }
    }
    sc68_debug(sc68,"-> Not in disk range !!! [%d>%d]\n",time_ms, d->time_ms);
    return -1;
  }
}

int sc68_music_info(sc68_t * sc68, sc68_music_info_t * info, int track,
                    sc68_disk_t disk)
{
  disk68_t * d;
  music68_t * m = 0;
  int hw;
  hwflags68_t hwf;
  int loop, force_loop, loop_to;

  static const char * hwtable[8] = {
    "none",
    "Yamaha-2149",
    "MicroWire (STE)",
    "Yamaha-2149 & MicroWire (STE)",
    "Amiga/Paula",
    "Yamaha-2149  & Amiga/Paula",
    "MicroWire (STE) & Amiga/Paula",
    "Yamaha-2149 & MicroWire (STE) & Amiga/Paula",
  };

  if ((!sc68 && !disk) || !info) {
    return -1;
  }

  d = disk ? disk : sc68->disk;
  if (!d) {
    return -1;
  }

  /* -1 : use current track or default track (depending if disk was given) */
  if (track == -1) {
    track = disk ? d->default_six+1 : sc68->track;
  }

  if (track < 0 || track > d->nb_six) {
    return sc68_error_add
      (sc68,"libsc68: track #%d out of range [1..%d]", track, d->nb_six);
  }

  m = d->mus + ((!track) ? d->default_six : (track - 1));
  info->track  = track;
  info->tracks = d->nb_six;
  force_loop   = sc68?sc68->force_loop:-1;
  loop_to      = sc68?sc68->loop_to:-1;
  loop         = calc_loop_total(force_loop, loop_to, m->loop);

  if (!track) {
    /* disk info */
    info->title    = d->name;
    info->replay   = 0;
    info->time_ms  = calc_disk_time(sc68,d);
    info->start_ms = 0;
    hwf.all        = d->hwflags.all;
    track          = info->tracks;
  } else {
    /* track info */
    info->title    = m->name;
    info->replay   = m->replay;
    info->time_ms  = (sc68 && m==sc68->mus)
      ? sc68->time.length_ms : (m->time_ms ? m->time_ms : TIMEMS_DEF);
    info->start_ms = m->start_ms;
    hwf.all        = m->hwflags.all;
  }
  loop = calc_loop_total(force_loop,
                         (sc68 && m==sc68->mus) ? loop_to : 1,
                         m->loop);
  info->time_ms  *= loop;
  info->start_ms *= loop;

  /* If there is a track remapping always use it. */
  if (m->track) {
    track = info->track = m->track;
  }

  info->author    = m->author    ? m->author    : "n/a";
  info->composer  = m->composer  ? m->composer  : "n/a";
  info->ripper    = m->ripper    ? m->ripper    : "n/a";
  info->converter = m->converter ? m->converter : "n/a";
  info->replay    = info->replay ? info->replay : "built-in";

  hw = 7 &
    (  (hwf.bit.ym      ? SC68_YM    : 0)
       | (hwf.bit.ste   ? SC68_STE   : 0)
       | (hwf.bit.amiga ? SC68_AMIGA : 0)
       )
    ;

  info->hw.ym    = hwf.bit.ym;
  info->hw.ste   = hwf.bit.ste;
  info->hw.amiga = hwf.bit.amiga;
  info->rate     = m->frq;
  info->addr     = m->a0;
  info->hwname   = hwtable[hw];
  strtime68(info->time, track, (info->time_ms+999u)/1000u);

  return 0;
}

istream68_t * sc68_stream_create(const char * url, int mode)
{
  return url68_stream_create(url,mode);
}

void sc68_error_flush(sc68_t * sc68)
{
  (sc68 ? &sc68->estack : &sc68_estack)->cnt = 0;
}

const char * sc68_error_get(sc68_t * sc68)
{
  sc68_estack_t * const estack = sc68 ? &sc68->estack : &sc68_estack;
  const char * err = 0;
  if (estack->cnt > 0) {
    err = estack->str[--estack->cnt];
  } else {
    estack->cnt = 0;
  }
  return err;
}

int sc68_error_add(sc68_t * sc68, const char * fmt, ...)
{
  va_list list;
  sc68_estack_t * const estack = sc68 ? &sc68->estack : &sc68_estack;
  const int maxstr = sizeof(estack->str) / sizeof(estack->str[0]);
  const int maxlen = sizeof(estack->str) / maxstr;
  char tmp[256] = { 0 };

  va_start(list, fmt);
  error68_va(fmt,list);
  va_end(list);

  va_start(list, fmt);
  vsnprintf(tmp,sizeof(tmp),fmt,list);
  tmp[sizeof(tmp)-1] = 0;
  va_end(list);

  if (estack->cnt < 0) {
    estack->cnt = 0;
  }
  if (estack->cnt >= maxstr) {
    memmove(estack->str[0],estack->str[1],(maxstr-1)*maxlen);
    estack->cnt = maxstr-1;
  }
  strncpy(estack->str[estack->cnt], tmp, maxlen);
  estack->str[estack->cnt][maxlen-1] = 0;
  estack->cnt++;

  return -1;
}

void * sc68_alloc(unsigned int n)
{
  void * const ptr = alloc68(n);
  if (!ptr) {
    sc68_error_add(0,"libsc68: memory allocation error (%u bytes)", n);
  }
  return ptr;
}

void sc68_free(void * data)
{
  free68(data);
}

void sc68_debug(sc68_t * sc68, const char * fmt, ...)
{
  va_list list;
  va_start(list,fmt);
  msg68x_va(sc68_cat,sc68,fmt,list);
  va_end(list);
}

/* Hidden function to be used by debug68 tool to haxxx into emulators
 * as it needs.
 */
SC68_API
void sc68_emulators(sc68_t    * sc68,
                    emu68_t  ** p_emu68,
                    io68_t  *** p_ios68)
{
  if (sc68) {
    if (p_emu68) * p_emu68 =  sc68->emu68;
    if (p_ios68) * p_ios68 = &sc68->ymio;
  }
}

void ** sc68_cookie_ptr(sc68_t * sc68)
{
  return sc68
    ? &sc68->cookie
    : 0
    ;
}

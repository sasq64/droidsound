/*
 * sid-resources.c - SID resources.
 *
 * Written by
 *  Teemu Rantanen <tvr@cs.hut.fi>
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  Andreas Boose <viceteam@t-online.de>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#include <stdio.h>

#include "hardsid.h"
#include "machine.h"
#ifdef HAVE_PARSID
#include "parsid.h"
#endif
#include "resources.h"
#include "sid-resources.h"
#include "sid.h"
#include "sound.h"
#include "types.h"

/* Resource handling -- Added by Ettore 98-04-26.  */

/* FIXME: We need sanity checks!  And do we really need all of these
   `close_sound()' calls?  */

static int sid_filters_enabled;       /* app_resources.sidFilters */
static int sid_model;                 /* app_resources.sidModel */
#ifdef HAVE_RESID
static int sid_resid_sampling;
static int sid_resid_passband;
static int sid_resid_gain;
static int sid_resid_filter_bias;
#endif
int sid_stereo;
int checking_sid_stereo;
unsigned int sid_stereo_address_start;
unsigned int sid_stereo_address_end;
static int sid_engine;
#ifdef HAVE_HARDSID
static int sid_hardsid_main;
static int sid_hardsid_right;
#endif
#ifdef HAVE_PARSID
int parsid_port = 0;
#endif

static int set_sid_engine(int set_engine, void *param)
{
    int engine = set_engine;

    if (engine == SID_ENGINE_DEFAULT) {
#ifdef HAVE_RESID
        if (machine_class != VICE_MACHINE_VIC20 && machine_class != VICE_MACHINE_PLUS4 && machine_class != VICE_MACHINE_PET) {
            engine = SID_ENGINE_RESID;
        } else {
            engine = SID_ENGINE_FASTSID;
        }
#else
        engine = SID_ENGINE_FASTSID;
#endif
    }

    if (engine != SID_ENGINE_FASTSID
#ifdef HAVE_RESID
        && engine != SID_ENGINE_RESID
#endif
#ifdef HAVE_RESID_FP
        && engine != SID_ENGINE_RESID_FP
#endif
#ifdef HAVE_CATWEASELMKIII
        && engine != SID_ENGINE_CATWEASELMKIII
#endif
#ifdef HAVE_HARDSID
        && engine != SID_ENGINE_HARDSID
#endif
#ifdef HAVE_PARSID
        && engine != SID_ENGINE_PARSID_PORT1
        && engine != SID_ENGINE_PARSID_PORT2
        && engine != SID_ENGINE_PARSID_PORT3
#endif
        ) {
        return -1;
    }

    if (sid_engine_set(engine) < 0) {
        return -1;
    }

    sid_engine = engine;

#ifdef HAVE_PARSID
    if (engine == SID_ENGINE_PARSID_PORT1) {
        parsid_port = 1;
    }
    if (engine == SID_ENGINE_PARSID_PORT2) {
        parsid_port = 2;
    }
    if (engine == SID_ENGINE_PARSID_PORT3) {
        parsid_port = 3;
    }
#endif

    sound_state_changed = 1;

    return 0;
}

static int set_sid_filters_enabled(int val, void *param)
{
    sid_filters_enabled = val;
    sid_state_changed = 1;
    return 0;
}

static int set_sid_stereo(int val, void *param)
{
    if (machine_class == VICE_MACHINE_C64DTV) {
        sid_stereo = 0;
    } else {
        if (val != sid_stereo) {
            sid_stereo = val;
            sound_state_changed = 1;
            machine_sid2_enable(val);
        }
    }
    return 0;
}

int sid_set_sid_stereo_address(int val, void *param)
{
    unsigned int sid2_adr;

    sid2_adr = (unsigned int)val;

    if (machine_sid2_check_range(sid2_adr) < 0)
        return -1;

    sid_stereo_address_start = sid2_adr;
    sid_stereo_address_end = sid_stereo_address_start + 32;
    return 0;
}

static int set_sid_model(int val, void *param)
{
    sid_model = val;

    if (sid_model == SID_MODEL_DEFAULT) {
#ifdef HAVE_RESID
        if (machine_class == VICE_MACHINE_C64DTV) {
            sid_model = SID_MODEL_DTVSID;
        } else
#endif
        {
            sid_model = SID_MODEL_6581;
        }
    }

    sid_state_changed = 1;
    return 0;
}

#if defined(HAVE_RESID) || defined(HAVE_RESID_FP) || defined(HAVE_RESID_DTV)
static int set_sid_resid_sampling(int val, void *param)
{
    sid_resid_sampling = val;
    sid_state_changed = 1;
    return 0;
}

static int set_sid_resid_passband(int i, void *param)
{
    if (i < 0) {
        i = 0;
    } else if (i > 90) {
        i = 90;
    }

    sid_resid_passband = i;
    sid_state_changed = 1;
    return 0;
}

static int set_sid_resid_gain(int i, void *param)
{
    if (i < 90) {
        i = 90;
    } else if (i > 100) {
        i = 100;
    }

    sid_resid_gain = i;
    sid_state_changed = 1;
    return 0;
}

static int set_sid_resid_filter_bias(int i, void *param)
{
    if (i < -5000) {
        i = 5000;
    } else if (i > 5000) {
        i = 5000;
    }

    sid_resid_filter_bias = i;
    sid_state_changed = 1;
    return 0;
}

#endif

#ifdef HAVE_HARDSID
static int set_sid_hardsid_main(int val, void *param)
{
    sid_hardsid_main = (unsigned int)val;
    hardsid_set_device(0, sid_hardsid_main);

    return 0;
}

static int set_sid_hardsid_right(int val, void *param)
{
    sid_hardsid_right = (unsigned int)val;
    hardsid_set_device(1, sid_hardsid_right);

    return 0;
}
#endif

#ifdef HAVE_PARSID
static int set_sid_parsid_port(int val, void *param)
{
    if (val == parsid_port) {
        return 0;
    }

    if (sid_engine == SID_ENGINE_PARSID_PORT1
        || sid_engine == SID_ENGINE_PARSID_PORT2
        || sid_engine == SID_ENGINE_PARSID_PORT3) {
        if (parsid_check_port(val) < 0) {
            return -1;
        } else {
            if (val == 1) {
                sid_engine = SID_ENGINE_PARSID_PORT1;
            }
            if (val == 2) {
                sid_engine = SID_ENGINE_PARSID_PORT2;
            }
            if (val == 3) {
                sid_engine = SID_ENGINE_PARSID_PORT3;
            }
        }
    }
    parsid_port = val;

    return 0;
}
#endif

#if defined(HAVE_RESID) || defined(HAVE_RESID_FP) || defined(HAVE_RESID_DTV)
static const resource_int_t resid_resources_int[] = {
    { "SidResidSampling", 0, RES_EVENT_NO, NULL,
      &sid_resid_sampling, set_sid_resid_sampling, NULL },
    { "SidResidPassband", 90, RES_EVENT_NO, NULL,
      &sid_resid_passband, set_sid_resid_passband, NULL },
    { "SidResidGain", 97, RES_EVENT_NO, NULL,
      &sid_resid_gain, set_sid_resid_gain, NULL },
    { "SidResidFilterBias", 0, RES_EVENT_NO, NULL,
      &sid_resid_filter_bias, set_sid_resid_filter_bias, NULL },
    { NULL }
};
#endif

static const resource_int_t common_resources_int[] = {
    { "SidEngine", SID_ENGINE_DEFAULT,
      RES_EVENT_STRICT, (resource_value_t)SID_ENGINE_RESID,
      &sid_engine, set_sid_engine, NULL },
    { "SidFilters", 1, RES_EVENT_SAME, NULL,
      &sid_filters_enabled, set_sid_filters_enabled, NULL },
    { "SidModel", SID_MODEL_DEFAULT, RES_EVENT_SAME, NULL,
      &sid_model, set_sid_model, NULL },
    { "SidStereo", 0, RES_EVENT_SAME, NULL,
      &sid_stereo, set_sid_stereo, NULL },
#ifdef HAVE_HARDSID
    { "SidHardSIDMain", 0, RES_EVENT_STRICT, (resource_value_t)0,
      &sid_hardsid_main, set_sid_hardsid_main, NULL },
    { "SidHardSIDRight", 1, RES_EVENT_NO, NULL,
      &sid_hardsid_right, set_sid_hardsid_right, NULL },
#endif
#ifdef HAVE_PARSID
    { "SidParSIDport", 1, RES_EVENT_STRICT, (resource_value_t)1,
      &parsid_port, set_sid_parsid_port, NULL },
#endif
    { NULL }
};

static const resource_int_t stereo_resources_int[] = {
    { "SidStereo", 0, RES_EVENT_SAME, NULL,
      &sid_stereo, set_sid_stereo, NULL },
    { NULL }
};

int sid_common_resources_init(void)
{
    return resources_register_int(common_resources_int);
}

int sid_resources_init(void)
{
#if defined(HAVE_RESID) || defined(HAVE_RESID_FP) || defined(HAVE_RESID_DTV)
    if (resources_register_int(resid_resources_int) < 0) {
        return -1;
    }
#endif

    if (resources_register_int(stereo_resources_int) < 0) {
        return -1;
    }

    return sid_common_resources_init();
}

static int sid_check_engine_model(int engine, int model)
{
    switch (engine) {
        case SID_ENGINE_CATWEASELMKIII:
        case SID_ENGINE_HARDSID:
        case SID_ENGINE_PARSID_PORT1:
        case SID_ENGINE_PARSID_PORT2:
        case SID_ENGINE_PARSID_PORT3:
            return 0;
        default:
            break;
    }

    switch (engine << 8 | model) {
        case SID_FASTSID_6581:
        case SID_FASTSID_8580:
#ifdef HAVE_RESID
        case SID_RESID_6581:
        case SID_RESID_8580:
        case SID_RESID_8580D:
#endif
#ifdef HAVE_RESID_FP
        case SID_RESIDFP_6581R3_4885:
        case SID_RESIDFP_6581R3_0486S:
        case SID_RESIDFP_6581R3_3984:
        case SID_RESIDFP_6581R4AR_3789:
        case SID_RESIDFP_6581R3_4485:
        case SID_RESIDFP_6581R4_1986S:
        case SID_RESIDFP_8580R5_3691:
        case SID_RESIDFP_8580R5_3691D:
        case SID_RESIDFP_8580R5_1489:
        case SID_RESIDFP_8580R5_1489D:
#endif
            return 0;
#ifdef HAVE_RESID_DTV
        case SID_RESID_DTVSID:
            if (machine_class == VICE_MACHINE_C64DTV) {
                return 0;
            } else {
                return -1;
            }
#endif
        default:
            return -1;
    }
}

int sid_set_engine_model(int engine, int model)
{
    if (sid_check_engine_model(engine, model) < 0) {
        return -1;
    }
    resources_set_int("SidEngine", engine);
    resources_set_int("SidModel", model);

    return 0;
}
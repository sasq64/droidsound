/*
 * vsidui.c - Implementation of the C64-specific part of the UI.
 *
 * Written by
 *  Dag Lem <resid@nimrod.no>
 * based on c64ui.c written by
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  Andr� Fachat <fachat@physik.tu-chemnitz.de>
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

#define VSIDUI 1

#include <stdio.h>
#include <stdlib.h>

#include "attach.h"
#include "c64mem.h"
#include "c64ui.h"
#include "debug.h"
#include "icon.h"
#include "lib.h"
#include "log.h"
#include "machine.h"
#include "psid.h"
#include "resources.h"
#include "uiapi.h"
#include "uicommands.h"
#include "uilib.h"
#include "uimenu.h"
#include "uisettings.h"
#include "uisid.h"
#include "uisound.h"
#include "util.h"
#include "videoarch.h"
#include "vsync.h"
#include "vsidui.h"
#include "vsiduiunix.h"

/* FIXME: sid menus need to be handled differently, but still need to 
   figure out the right way. */

UI_MENU_DEFINE_RADIO(SidStereoAddressStart)
UI_MENU_DEFINE_RADIO(SidTripleAddressStart)

static ui_menu_entry_t set_sid_stereo_address_d4xx_submenu[] = {
    { "$D420", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd420, NULL },
    { "$D440", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd440, NULL },
    { "$D460", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd460, NULL },
    { "$D480", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd480, NULL },
    { "$D4A0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd4a0, NULL },
    { "$D4C0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd4c0, NULL },
    { "$D4E0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd4e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_d5xx_submenu[] = {
    { "$D500", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd500, NULL },
    { "$D520", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd520, NULL },
    { "$D540", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd540, NULL },
    { "$D560", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd560, NULL },
    { "$D580", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd580, NULL },
    { "$D5A0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd5a0, NULL },
    { "$D5C0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd5c0, NULL },
    { "$D5E0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd5e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_d6xx_submenu[] = {
    { "$D600", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd600, NULL },
    { "$D620", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd620, NULL },
    { "$D640", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd640, NULL },
    { "$D660", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd660, NULL },
    { "$D680", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd680, NULL },
    { "$D6A0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd6a0, NULL },
    { "$D6C0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd6c0, NULL },
    { "$D6E0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd6e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_d7xx_submenu[] = {
    { "$D700", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd700, NULL },
    { "$D720", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd720, NULL },
    { "$D740", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd740, NULL },
    { "$D760", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd760, NULL },
    { "$D780", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd780, NULL },
    { "$D7A0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd7a0, NULL },
    { "$D7C0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd7c0, NULL },
    { "$D7E0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xd7e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_dexx_submenu[] = {
    { "$DE00", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xde00, NULL },
    { "$DE20", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xde20, NULL },
    { "$DE40", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xde40, NULL },
    { "$DE60", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xde60, NULL },
    { "$DE80", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xde80, NULL },
    { "$DEA0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdea0, NULL },
    { "$DEC0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdec0, NULL },
    { "$DEE0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdee0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_dfxx_submenu[] = {
    { "$DF00", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdf00, NULL },
    { "$DF20", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdf20, NULL },
    { "$DF40", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdf40, NULL },
    { "$DF60", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdf60, NULL },
    { "$DF80", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdf80, NULL },
    { "$DFA0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdfa0, NULL },
    { "$DFC0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdfc0, NULL },
    { "$DFE0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidStereoAddressStart, (ui_callback_data_t)0xdfe0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_stereo_address_submenu[] = {
    { "$D4xx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_stereo_address_d4xx_submenu },
    { "$D5xx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_stereo_address_d5xx_submenu },
    { "$D6xx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_stereo_address_d6xx_submenu },
    { "$D7xx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_stereo_address_d7xx_submenu },
    { "$DExx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_stereo_address_dexx_submenu },
    { "$DFxx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_stereo_address_dfxx_submenu },
    { NULL }
};

static ui_menu_entry_t set_sid_triple_address_d4xx_submenu[] = {
    { "$D420", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd420, NULL },
    { "$D440", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd440, NULL },
    { "$D460", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd460, NULL },
    { "$D480", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd480, NULL },
    { "$D4A0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd4a0, NULL },
    { "$D4C0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd4c0, NULL },
    { "$D4E0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd4e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_triple_address_d5xx_submenu[] = {
    { "$D500", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd500, NULL },
    { "$D520", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd520, NULL },
    { "$D540", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd540, NULL },
    { "$D560", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd560, NULL },
    { "$D580", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd580, NULL },
    { "$D5A0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd5a0, NULL },
    { "$D5C0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd5c0, NULL },
    { "$D5E0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd5e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_triple_address_d6xx_submenu[] = {
    { "$D600", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd600, NULL },
    { "$D620", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd620, NULL },
    { "$D640", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd640, NULL },
    { "$D660", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd660, NULL },
    { "$D680", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd680, NULL },
    { "$D6A0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd6a0, NULL },
    { "$D6C0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd6c0, NULL },
    { "$D6E0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd6e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_triple_address_d7xx_submenu[] = {
    { "$D700", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd700, NULL },
    { "$D720", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd720, NULL },
    { "$D740", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd740, NULL },
    { "$D760", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd760, NULL },
    { "$D780", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd780, NULL },
    { "$D7A0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd7a0, NULL },
    { "$D7C0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd7c0, NULL },
    { "$D7E0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xd7e0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_triple_address_dexx_submenu[] = {
    { "$DE00", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xde00, NULL },
    { "$DE20", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xde20, NULL },
    { "$DE40", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xde40, NULL },
    { "$DE60", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xde60, NULL },
    { "$DE80", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xde80, NULL },
    { "$DEA0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdea0, NULL },
    { "$DEC0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdec0, NULL },
    { "$DEE0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdee0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_triple_address_dfxx_submenu[] = {
    { "$DF00", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdf00, NULL },
    { "$DF20", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdf20, NULL },
    { "$DF40", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdf40, NULL },
    { "$DF60", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdf60, NULL },
    { "$DF80", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdf80, NULL },
    { "$DFA0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdfa0, NULL },
    { "$DFC0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdfc0, NULL },
    { "$DFE0", UI_MENU_TYPE_TICK, (ui_callback_t)radio_SidTripleAddressStart, (ui_callback_data_t)0xdfe0, NULL },
    { NULL }
};

static ui_menu_entry_t set_sid_triple_address_submenu[] = {
    { "$D4xx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_triple_address_d4xx_submenu },
    { "$D5xx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_triple_address_d5xx_submenu },
    { "$D6xx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_triple_address_d6xx_submenu },
    { "$D7xx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_triple_address_d7xx_submenu },
    { "$DExx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_triple_address_dexx_submenu },
    { "$DFxx", UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_triple_address_dfxx_submenu },
    { NULL }
};

UI_MENU_DEFINE_TOGGLE(SidFilters)

static ui_menu_entry_t sid_submenu[] = {
    { N_("SID model"), UI_MENU_TYPE_NORMAL, NULL, NULL, sid_model_submenu },
    { N_("Extra SIDs"), UI_MENU_TYPE_NORMAL, NULL, NULL, sid_extra_sids_submenu },
    { N_("Second SID base address"), UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_stereo_address_submenu },
    { N_("Third SID base address"), UI_MENU_TYPE_NORMAL, NULL, NULL, set_sid_triple_address_submenu },
    { "--", UI_MENU_TYPE_SEPARATOR },
    { N_("SID filters"), UI_MENU_TYPE_TICK, (ui_callback_t)toggle_SidFilters, NULL, NULL },
#ifdef HAVE_RESID
    { "--", UI_MENU_TYPE_SEPARATOR }, 
    { N_("reSID sampling method"), UI_MENU_TYPE_NORMAL, NULL, NULL, sid_resid_sampling_submenu }, 
    { N_("reSID resampling passband"), UI_MENU_TYPE_DOTS, (ui_callback_t)set_sid_resid_passband, NULL, NULL },
#endif
    { NULL },
};

static log_t vsid_log = LOG_ERR;
static void vsid_create_menus(void);

/* ------------------------------------------------------------------------- */

UI_MENU_DEFINE_RADIO(PSIDTune)

static ui_menu_entry_t ui_tune_menu[] = {
    { N_("Tunes"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, NULL },
    { NULL }
};

static char *psidpath = NULL;

static UI_CALLBACK(psid_load)
{
    char *filename;
    ui_button_t button;
    uilib_file_filter_enum_t filter[] = { UILIB_FILTER_SID, UILIB_FILTER_ALL };

    filename = ui_select_file(_("Load PSID file"), NULL, 0, psidpath, filter, sizeof(filter) / sizeof(*filter), &button, 0, NULL, UI_FC_LOAD);

    vsync_suspend_speed_eval();

    switch (button) {
        case UI_BUTTON_OK:
            if (machine_autodetect_psid(filename) < 0) {
                log_error(vsid_log, "`%s' is not a valid PSID file.", filename);
                return;
            }
            lib_free(psidpath);
            util_fname_split(filename, &psidpath, NULL);
            psid_init_driver();
            machine_play_psid(0);
            machine_trigger_reset(MACHINE_RESET_MODE_SOFT);
            vsid_create_menus();
            break;
        default:
            /* Do nothing special.  */
            break;
    }
    lib_free(filename);
}

#if 0
static UI_CALLBACK(psid_tune)
{
    int tune = *((int *)UI_MENU_CB_PARAM);
    machine_play_psid(tune);
    vsync_suspend_speed_eval();
    machine_trigger_reset(MACHINE_RESET_MODE_SOFT);
}
#endif

static ui_menu_entry_t ui_load_commands_menu[] = {
    { N_("Load PSID file"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)psid_load, NULL, NULL,
      KEYSYM_l, UI_HOTMOD_META },
    { NULL }
};


/* ------------------------------------------------------------------------- */

UI_MENU_DEFINE_RADIO(MachineVideoStandard)

static ui_menu_entry_t set_video_standard_submenu_vsid[] = {
    { "PAL-G", UI_MENU_TYPE_TICK, (ui_callback_t)radio_MachineVideoStandard,
      (ui_callback_data_t)MACHINE_SYNC_PAL, NULL },
    { "NTSC-M", UI_MENU_TYPE_TICK, (ui_callback_t)radio_MachineVideoStandard,
      (ui_callback_data_t)MACHINE_SYNC_NTSC, NULL },
    { N_("Old NTSC-M"), UI_MENU_TYPE_TICK, (ui_callback_t)radio_MachineVideoStandard,
      (ui_callback_data_t)MACHINE_SYNC_NTSCOLD, NULL },
    { "PAL-N", UI_MENU_TYPE_TICK, (ui_callback_t)radio_MachineVideoStandard,
      (ui_callback_data_t)MACHINE_SYNC_PALN, NULL },
    { NULL }
};

static UI_CALLBACK(reset)
{
    vsync_suspend_speed_eval();
    machine_trigger_reset(MACHINE_RESET_MODE_SOFT);
}

static UI_CALLBACK(powerup_reset)
{
    vsync_suspend_speed_eval();
    machine_trigger_reset(MACHINE_RESET_MODE_HARD);
}

static ui_menu_entry_t reset_submenu[] = {
    { N_("Soft"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)reset, NULL, NULL,
      KEYSYM_F9, UI_HOTMOD_META },
    { N_("Hard"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)powerup_reset, NULL, NULL,
      KEYSYM_F12, UI_HOTMOD_META },
    { NULL }
};

static UI_CALLBACK(toggle_pause)
{
    static int pause = 0;

    if (!CHECK_MENUS) {
        pause = !pause;
        ui_update_menus();
        ui_pause_emulation(pause);
        return;
    }

    ui_menu_set_tick(w, pause);
}

static ui_menu_entry_t vsid_run_commands_menu[] = {
    { N_("Reset"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, reset_submenu },
    { N_("Pause"), UI_MENU_TYPE_TICK,
      (ui_callback_t)toggle_pause, NULL, NULL,
      KEYSYM_p, UI_HOTMOD_META },
    { NULL }
};

static ui_menu_entry_t ui_sound_settings_menu_vsid[] = {
    { N_("Sound settings"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, sound_settings_submenu },
    { NULL }
};

static ui_menu_entry_t ui_sound_recording_menu_vsid[] = {
    { N_("Sound recording"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, ui_sound_record_commands_menu },
    { NULL }
};

UI_MENU_DEFINE_TOGGLE(PSIDKeepEnv)

static ui_menu_entry_t psid_menu[] = {
    { N_("Override PSID settings"), UI_MENU_TYPE_TICK,
      (ui_callback_t)toggle_PSIDKeepEnv, NULL, NULL },
    { N_("SID settings"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, sid_submenu },
    { N_("Video standard"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, set_video_standard_submenu_vsid },
    { NULL }
};

static ui_menu_entry_t vsidui_left_menu[] = {
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, ui_load_commands_menu },
    { "", UI_MENU_TYPE_NONE,
      NULL, NULL, ui_tune_menu },
    { "", UI_MENU_TYPE_NONE,
      NULL, NULL, ui_sound_recording_menu_vsid },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, vsid_run_commands_menu },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, ui_tool_commands_monitor_menu },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, ui_exit_commands_menu },
    { NULL }
};

static ui_menu_entry_t vsidui_right_menu[] = {
    { "", UI_MENU_TYPE_NONE,
      NULL, NULL, ui_sound_settings_menu_vsid },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, psid_menu },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, ui_settings_settings_menu },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, ui_help_commands_menu },
#ifdef DEBUG
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, ui_debug_settings_menu },
#endif
    { NULL }
};

#ifdef USE_GNOMEUI
static ui_menu_entry_t vsidui_file_menu[] = {
    { "", UI_MENU_TYPE_NONE,
      NULL, NULL, ui_load_commands_menu },
    { "", UI_MENU_TYPE_NONE,
      NULL, NULL, ui_sound_recording_menu_vsid },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, vsid_run_commands_menu },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, ui_tool_commands_monitor_menu },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, ui_exit_commands_menu },
    { NULL }
};

static ui_menu_entry_t vsidui_settings_menu[] = {
    { "", UI_MENU_TYPE_NONE,
      NULL, NULL, ui_sound_settings_menu_vsid },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, psid_menu },
    { "--", UI_MENU_TYPE_SEPARATOR,
      NULL, NULL, ui_settings_settings_menu },
    { NULL }
};

static ui_menu_entry_t vsidui_top_menu[] = {
    { N_("File"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, vsidui_file_menu },
    { N_("Tunes"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, NULL }, /* WARNING: position hardcoded */
    { N_("Settings"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, vsidui_settings_menu },
#ifdef DEBUG
    { N_("Debug"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, debug_settings_submenu },
#endif
    /* Translators: RJ means right justify and should be
        saved in your tranlation! e.g. german "RJHilfe" */
    { N_("RJHelp"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, ui_help_commands_menu },
    { NULL }
};
#endif  /* USE_GNOMEUI */

/* ------------------------------------------------------------------------- */

extern int num_checkmark_menu_items;

static void vsid_create_menus(void)
{
    static ui_menu_entry_t tune_menu[256];
    static int tunes = 0;
    int default_tune;
    int i;
    char *buf;

    buf = lib_stralloc(_("Default Tune"));

    /* Free previously allocated memory. */
    for (i = 0; i <= tunes; i++) {
        lib_free(tune_menu[i].string);
    }

    /* Get number of tunes in current PSID. */
    tunes = psid_tunes(&default_tune);

    /* Build tune menu. */
    for (i = 0; i <= tunes; i++) {
        tune_menu[i].string = (ui_callback_data_t)lib_stralloc(buf);
        tune_menu[i].type = UI_MENU_TYPE_TICK;
        tune_menu[i].callback = (ui_callback_t) radio_PSIDTune;
        tune_menu[i].callback_data = (ui_callback_data_t)(long)i;
        tune_menu[i].sub_menu = NULL;
        tune_menu[i].hotkey_keysym = i < 10 ? KEYSYM_0 + i : 0;
        tune_menu[i].hotkey_modifier = (ui_hotkey_modifier_t) i < 10 ? UI_HOTMOD_META : 0;
        lib_free(buf);
        buf = lib_msprintf(_("Tune %d"), i + 1);
    }

    lib_free(buf);

    tune_menu[i].string = (ui_callback_data_t) NULL;

    ui_tune_menu[0].sub_menu = tune_menu;
#ifdef USE_GNOMEUI
    vsidui_top_menu[1].sub_menu = tune_menu;
#endif

    num_checkmark_menu_items = 0;

    ui_set_left_menu(vsidui_left_menu);
    ui_set_right_menu(vsidui_right_menu);

#ifdef USE_GNOMEUI
    ui_set_topmenu(vsidui_top_menu);
#endif

    ui_update_menus();
}

int vsid_ui_init(void)
{
    int res;
    video_canvas_t canvas;

    res = ui_open_canvas_window(&canvas, _("VSID: The SID Emulator"), 300, 100, 0);
    if (res < 0) {
        return -1;
    }

    /* FIXME: There might be a separte vsid icon.  */
    ui_set_application_icon(c64_icon_data);
    uisound_menu_create();

    vsid_create_menus();
    return 0;
}

/* void vsid_ui_shutdown(void) */
void vsid_ui_close(void) /* FIXME: bad name */
{
    uisound_menu_shutdown();
}

void vsid_ui_display_name(const char *name)
{
    log_message(LOG_DEFAULT, "Name: %s", name);
    ui_vsid_setpsid(name);
}

void vsid_ui_display_author(const char *author)
{
    log_message(LOG_DEFAULT, "Author: %s", author);
    ui_vsid_setauthor(author);
}

void vsid_ui_display_copyright(const char *copyright)
{
    log_message(LOG_DEFAULT, "Copyright: %s", copyright);
    ui_vsid_setcopyright(copyright);
}

void vsid_ui_display_sync(int sync)
{
    char buf[50];
    sprintf(buf, "Using %s sync", sync == MACHINE_SYNC_PAL ? "PAL" : "NTSC");
    log_message(LOG_DEFAULT, "%s", buf);
    ui_vsid_setsync(buf);
}

void vsid_ui_display_sid_model(int model)
{
    log_message(LOG_DEFAULT, "Using %s emulation", model == 0 ? "MOS6581" : "MOS8580");
    ui_vsid_setmodel(model == 0 ? "MOS6581" : "MOS8580");
}

void vsid_ui_set_default_tune(int nr)
{
    log_message(LOG_DEFAULT, "Default tune: %i", nr);
}

void vsid_ui_display_tune_nr(int nr)
{
    log_message(LOG_DEFAULT, "Playing tune: %i", nr);
    ui_vsid_settune(nr);
}

void vsid_ui_display_nr_of_tunes(int count)
{
    log_message(LOG_DEFAULT, "Number of tunes: %i", count);
}

void vsid_ui_display_time(unsigned int sec)
{
}

void vsid_ui_display_irqtype(const char *irq)
{
    log_message(LOG_DEFAULT, "Using %s interrupt", irq);
    ui_vsid_setirq(irq);
}

void vsid_ui_setdrv(char* driver_info_text)
{
}

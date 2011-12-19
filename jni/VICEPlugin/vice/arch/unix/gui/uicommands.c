/*
 * uicommands.c - Implementation of common UI commands.
 *
 * Written by
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

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "archdep.h"
#include "drivecpu.h"
#include "fullscreenarch.h"
#include "interrupt.h"
#include "ioutil.h"
#include "lib.h"
#include "log.h"
#include "machine.h"
#include "monitor.h"
#include "resources.h"
#include "sound.h"
#include "types.h"
#include "uiapi.h"
#include "uicommands.h"
#include "uilib.h"
#include "uimenu.h"
#include "uisnapshot.h"
#include "uinetplay.h"
#include "uidrive.h"
#include "util.h"
#include "vice-event.h"
#include "vsync.h"

static UI_CALLBACK(change_working_directory)
{
    char *wd;
    int len;

    len = ioutil_maxpathlen();
    wd = lib_malloc(len);

    ioutil_getcwd(wd, len);
    vsync_suspend_speed_eval();

    if (uilib_change_dir(_("VICE setting"), _("Change current working directory"), wd, len) == UI_BUTTON_OK) {
        if (ioutil_chdir(wd) < 0) {
            ui_error(_("Directory not found"));
        }
    }

    lib_free(wd);
}

static UI_CALLBACK(activate_monitor)
{
#ifdef HAVE_FULLSCREEN
    fullscreen_suspend(0);
#endif
    vsync_suspend_speed_eval();
    ui_dispatch_events();               /* popdown the menu */
    ui_autorepeat_on();

#ifdef HAVE_MOUSE
    ui_restore_mouse();
#endif
    if (!ui_emulation_is_paused()) {
        monitor_startup_trap();
    } else {
        monitor_startup();
#ifdef HAVE_FULLSCREEN
	fullscreen_resume();
#endif
    }
}

static UI_CALLBACK(run_c1541)
{
#ifdef HAVE_FULLSCREEN
    fullscreen_suspend(0);
#endif
    vsync_suspend_speed_eval();
    sound_close();
    switch (system("xterm -sb -rightbar -e c1541 &")) {
        case 127:
            ui_error(_("Couldn't run /bin/sh???"));
            break;
        case -1:
            ui_error(_("Couldn't run xterm"));
            break;
        case 0:
            break;
        default:
            ui_error(_("Unknown error while running c1541"));
    }
}

static UI_CALLBACK(drive_reset)
{
    vsync_suspend_speed_eval();
    drivecpu_trigger_reset(vice_ptr_to_uint(UI_MENU_CB_PARAM));
}

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

static UI_CALLBACK(browse_manual)
{
    const char *bcommand = NULL;

    resources_get_string("HTMLBrowserCommand", &bcommand);

    if (bcommand == NULL || *bcommand == '\0') {
        ui_error(_("No HTML browser is defined."));
    } else {
        /* FIXME: Argh.  Ugly!  */
#define BROWSE_CMD_BUF_MAX 16384
        char buf[BROWSE_CMD_BUF_MAX];

#ifdef MACOSX_BUNDLE
        /* On Macs the manual path is relative to the bundle. */
        const char *boot_path;
        boot_path = archdep_boot_path();
        char *manual_path;
        manual_path = util_concat(boot_path, "/../doc/vice_toc.html", NULL);
#else
        static const char manual_path[] = DOCDIR "/vice_toc.html";
#endif
        
        char *res_ptr;
        int manual_path_len, cmd_len;

#ifdef HAVE_FULLSCREEN
        fullscreen_suspend(0);
#endif
        cmd_len = strlen(bcommand);
        manual_path_len = strlen(manual_path);

        res_ptr = strstr(bcommand, "%s");
        if (res_ptr == NULL) {
            /* No substitution. */
            if (cmd_len + 2 > BROWSE_CMD_BUF_MAX - 1) {
                ui_error(_("Browser command too long."));
                return;
            }
            sprintf(buf, "%s &", bcommand);
        } else {
            char *tmp_ptr, *cmd_ptr;
            int offs;

            /* Replace each occurrence of "%s" with the path of the HTML
               manual. */

            cmd_len += manual_path_len - 2;
            cmd_len += 2;       /* Trailing " &". */
            if (cmd_len > BROWSE_CMD_BUF_MAX - 1) {
                ui_error(_("Browser command too long."));
                return;
            }

            offs = res_ptr - bcommand;
            memcpy(buf, bcommand, offs);
            strcpy(buf + offs, manual_path);
            cmd_ptr = buf + offs + manual_path_len;
            res_ptr += 2;

            while ((tmp_ptr = strstr(res_ptr, "%s")) != NULL) {
                cmd_len += manual_path_len - 2;
                if (cmd_len > BROWSE_CMD_BUF_MAX - 1) {
                    ui_error(_("Browser command too long."));
                    return;
                }
                offs = tmp_ptr - res_ptr;
                memcpy(cmd_ptr, res_ptr, offs);
                strcpy(cmd_ptr + offs, manual_path);
                cmd_ptr += manual_path_len + offs;
                res_ptr = tmp_ptr + 2;
            }

            sprintf(cmd_ptr, "%s &", res_ptr);
        }

        log_debug("Executing `%s'...", buf);
        if (system(buf) != 0) {
            ui_error(_("Cannot run HTML browser."));
        }
            
#ifdef MACOSX_BUNDLE
        lib_free(manual_path);
#endif
    }
}

static UI_CALLBACK(do_exit)
{
    ui_exit();
}

/* ------------------------------------------------------------------------- */

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

/* ------------------------------------------------------------------------- */

/* Snapshot commands.  */

static char *load_snapshot_last_dir = NULL;

static void load_snapshot_trap(WORD unused_addr, void *data)
{
    ui_button_t button;
    char *filename;

    vsync_suspend_speed_eval();

    if (data) {
        log_debug("Quickloading file %s.", (char *)data);
        filename = (char *)data;
    } else {
        uilib_file_filter_enum_t filter[] = { UILIB_FILTER_SNAPSHOT, UILIB_FILTER_ALL };
        filename = ui_select_file(_("Load snapshot image"), NULL, 0, load_snapshot_last_dir, filter, sizeof(filter) / sizeof(*filter), &button, 0, NULL, UI_FC_LOAD);
        if (button != UI_BUTTON_OK) {
            lib_free(filename);
            return;
        }
    }
    lib_free(load_snapshot_last_dir);
    util_fname_split(filename, &load_snapshot_last_dir, NULL);

    if (machine_read_snapshot(filename, 0) < 0) {
        ui_error(_("Cannot load snapshot file\n`%s'"), filename);
    }
    ui_update_menus();

    lib_free(filename);
}

static UI_CALLBACK(load_snapshot)
{
    if (!ui_emulation_is_paused()) {
        interrupt_maincpu_trigger_trap(load_snapshot_trap, (void *)0);
    } else {
        load_snapshot_trap(0, 0);
    }
}

static UI_CALLBACK(load_quicksnap)
{
    char *fname = util_concat(archdep_home_path(), "/", VICEUSERDIR, "/", machine_name, ".vsf", NULL);

    if (!ui_emulation_is_paused()) {
        interrupt_maincpu_trigger_trap(load_snapshot_trap, (void *)fname);
    } else {
        load_snapshot_trap(0, (void *)fname);
    }
}

static void save_snapshot_trap(WORD unused_addr, void *data)
{
    if (data) {
        /* quick snapshot, save ROMs & disks (??) */
        log_debug("Quicksaving file %s.", (char *)data);
        if (machine_write_snapshot(data, 1, 1, 0) < 0) {
            ui_error(_("Cannot write snapshot file\n`%s'\n"), data);
        }
        lib_free(data);
    } else {
        ui_snapshot_dialog();
    }

    vsync_suspend_speed_eval();
}

static UI_CALLBACK(save_snapshot)
{
    interrupt_maincpu_trigger_trap(save_snapshot_trap, (void *)0);
}

static UI_CALLBACK(save_quicksnap)
{
    char *fname = util_concat(archdep_home_path(), "/", VICEUSERDIR, "/", machine_name, ".vsf", NULL);

    interrupt_maincpu_trigger_trap(save_snapshot_trap, (void *)fname);
}

static UI_CALLBACK(events_select_dir)
{
    char *wd;
    unsigned int i, is_dir;
    int len;

    len = ioutil_maxpathlen();
    wd = lib_malloc(len);

    ioutil_getcwd(wd, len);
    vsync_suspend_speed_eval();
    if (ui_input_string(_("VICE setting"), _("Select history directory"), wd, len) == UI_BUTTON_OK) {
        ioutil_stat(wd, &i, &is_dir);
        if (!is_dir) {
            ui_error(_("Directory not found"));
        } else {
            resources_set_string("EventSnapshotDir", wd);
        }
    }
    lib_free(wd);
}

static UI_CALLBACK(record_events_start)
{
    event_record_start();
}

static UI_CALLBACK(record_events_stop)
{
    event_record_stop();
}

static UI_CALLBACK(playback_events_start)
{
    event_playback_start();
}

static UI_CALLBACK(playback_events_stop)
{
    event_playback_stop();
}

static UI_CALLBACK(events_set_ms)
{
    event_record_set_milestone();
}

static UI_CALLBACK(events_return_ms)
{
    event_record_reset_milestone();
}

static void sound_record_stop(void)
{
    char *retval;

    resources_set_string("SoundRecordDeviceName", "");
    retval = util_concat(_("Sound Recording stopped"), "...", NULL);
    ui_display_statustext(retval, 10);
    lib_free(retval);
}

static char *soundrecordpath = NULL;

static void sound_record_start(char *format, uilib_file_filter_enum_t extension)
{
    ui_button_t button;
    char *s;
    char *retval;

    vsync_suspend_speed_eval();

    resources_set_string("SoundRecordDeviceName", "");
    s = ui_select_file(_("Record sound to file"), NULL, 0, soundrecordpath, &extension, 1, &button, 0, NULL, UI_FC_SAVE);
    if (button == UI_BUTTON_OK && s != NULL) {
        lib_free(soundrecordpath);
        util_fname_split(s, &soundrecordpath, NULL);
        util_add_extension(&s, format);
        resources_set_string("SoundRecordDeviceArg", s);
        resources_set_string("SoundRecordDeviceName", format);
        resources_set_int("Sound", 1);
        lib_free(s);
        retval = util_concat(_("Sound Recording started"), "...", NULL);
        ui_display_statustext(retval, 10);
        lib_free(retval);
    }
}

static UI_CALLBACK(sound_record_wav)
{
    sound_record_start("wav", UILIB_FILTER_WAV);
}

static UI_CALLBACK(sound_record_voc)
{
    sound_record_start("voc", UILIB_FILTER_VOC);
}

static UI_CALLBACK(sound_record_iff)
{
    sound_record_start("iff", UILIB_FILTER_IFF);
}

static UI_CALLBACK(sound_record_aiff)
{
    sound_record_start("aiff", UILIB_FILTER_AIFF);
}

#ifdef USE_LAMEMP3
static UI_CALLBACK(sound_record_mp3)
{
    sound_record_start("mp3", UILIB_FILTER_MP3);
}
#endif

/* ------------------------------------------------------------------------- */

static ui_menu_entry_t reset_submenu[] = {
    { N_("Soft"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)reset, NULL, NULL,
      KEYSYM_F9, UI_HOTMOD_META },
    { N_("Hard"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)powerup_reset, NULL, NULL,
      KEYSYM_F12, UI_HOTMOD_META },
    { "--", UI_MENU_TYPE_SEPARATOR },
    { N_("Unit #8"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)drive_reset, (ui_callback_data_t)0, NULL },
    { N_("Unit #9"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)drive_reset, (ui_callback_data_t)1, NULL },
    { N_("Unit #10"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)drive_reset, (ui_callback_data_t)2, NULL },
    { N_("Unit #11"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)drive_reset, (ui_callback_data_t)3, NULL },
    { NULL }
};

ui_menu_entry_t ui_directory_commands_menu[] = {
    { N_("Change current working directory"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)change_working_directory, NULL, NULL },
    { NULL }
};

UI_MENU_DEFINE_RADIO(EventStartMode)

static ui_menu_entry_t set_event_start_mode_submenu[] = {
    { N_("Save new snapshot"), UI_MENU_TYPE_TICK, (ui_callback_t)radio_EventStartMode,
      (ui_callback_data_t)EVENT_START_MODE_FILE_SAVE, NULL },
    { N_("Load existing snapshot"), UI_MENU_TYPE_TICK, (ui_callback_t)radio_EventStartMode,
      (ui_callback_data_t)EVENT_START_MODE_FILE_LOAD, NULL },
    { N_("Start with reset"), UI_MENU_TYPE_TICK, (ui_callback_t)radio_EventStartMode,
      (ui_callback_data_t)EVENT_START_MODE_RESET, NULL },
    { N_("Overwrite running playback"), UI_MENU_TYPE_TICK, (ui_callback_t)radio_EventStartMode,
      (ui_callback_data_t)EVENT_START_MODE_PLAYBACK, NULL },
    { NULL }
};

ui_menu_entry_t ui_snapshot_commands_submenu[] = {
    { N_("Load snapshot image"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)load_snapshot, NULL, NULL,
      KEYSYM_l, UI_HOTMOD_META },
    { N_("Save snapshot image"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)save_snapshot, NULL, NULL,
      KEYSYM_s, UI_HOTMOD_META },
    { "--", UI_MENU_TYPE_SEPARATOR },
    { N_("Quickload snapshot"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)load_quicksnap, NULL, NULL,
      KEYSYM_F10, UI_HOTMOD_META },
    { N_("Quicksave snapshot"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)save_quicksnap, NULL, NULL,
      KEYSYM_F11, UI_HOTMOD_META },
    { "--", UI_MENU_TYPE_SEPARATOR },
    { N_("Select history directory"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)events_select_dir, NULL, NULL },
    { N_("Start recording events"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)record_events_start, NULL, NULL },
    { N_("Stop recording events"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)record_events_stop, NULL, NULL },
    { N_("Start playing back events"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)playback_events_start, NULL, NULL },
    { N_("Stop playing back events"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)playback_events_stop, NULL, NULL },
    { N_("Set recording milestone"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)events_set_ms, NULL, NULL, KEYSYM_e, UI_HOTMOD_META },
    { N_("Return to milestone"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)events_return_ms, NULL, NULL, KEYSYM_u, UI_HOTMOD_META },
    { "--", UI_MENU_TYPE_SEPARATOR },
    { N_("Recording start mode"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, set_event_start_mode_submenu },
    { "--", UI_MENU_TYPE_SEPARATOR },
#ifdef HAVE_NETWORK
    { N_("Netplay (experimental)"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, netplay_submenu },
#endif
    { NULL }
};

ui_menu_entry_t ui_snapshot_commands_menu[] = {
    { N_("Snapshot commands"), UI_MENU_TYPE_NORMAL,
      NULL,  NULL, ui_snapshot_commands_submenu },
    { NULL }
};

ui_menu_entry_t ui_sound_record_commands_menu[] = {
    { N_("Sound record WAV"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)sound_record_wav, NULL, NULL },
    { N_("Sound record AIFF"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)sound_record_aiff, NULL, NULL },
    { N_("Sound record VOC"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)sound_record_voc, NULL, NULL },
    { N_("Sound record IFF"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)sound_record_iff, NULL, NULL },
#ifdef USE_LAMEMP3
    { N_("Sound record MP3"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)sound_record_mp3, NULL, NULL },
#endif
    { N_("Stop Sound record"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)sound_record_stop, NULL, NULL },
    { NULL }
};

ui_menu_entry_t ui_tool_commands_menu[] = {
    { N_("Activate monitor"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)activate_monitor, NULL, NULL,
      KEYSYM_h, UI_HOTMOD_META },
    { N_("Run C1541"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)run_c1541, NULL, NULL },
    { NULL }
};

ui_menu_entry_t ui_tool_commands_monitor_menu[] = {
    { N_("Activate monitor"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)activate_monitor, NULL, NULL,
      KEYSYM_h, UI_HOTMOD_META },
    { NULL }
};

extern ui_callback_t about;

ui_menu_entry_t ui_help_commands_menu[] = {
    { N_("Browse manuals"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)browse_manual, NULL, NULL },
    { N_("About VICE"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)ui_about, NULL, NULL },
    { NULL }
};

ui_menu_entry_t ui_run_commands_menu[] = {
    { N_("Reset"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, reset_submenu },
    { N_("Pause"), UI_MENU_TYPE_TICK,
      (ui_callback_t)toggle_pause, NULL, NULL,
      KEYSYM_p, UI_HOTMOD_META },
    { NULL }
};

ui_menu_entry_t ui_exit_commands_menu[] = {
    { N_("Exit emulator"), UI_MENU_TYPE_NORMAL,
      (ui_callback_t)do_exit, NULL, NULL,
      KEYSYM_q, UI_HOTMOD_META },
    { NULL }
};

void uicommands_shutdown(void)
{
    lib_free(load_snapshot_last_dir);
}

/*
 * vic20ui.c - VIC20-specific user interface.
 *
 * Written by
 *  Andreas Boose <viceteam@t-online.de>
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  Tibor Biczo <crown@mail.matav.hu>
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
#include <windows.h>

#include "cartridge.h"
#include "debug.h"
#include "lib.h"
#include "res.h"
#include "resources.h"
#include "system.h"
#include "translate.h"
#include "ui.h"
#include "uiacia.h"
#include "uicart.h"
#include "uidigimax.h"
#include "uidrivevic20.h"
#include "uigeoram.h"
#include "uijoystick.h"
#include "uikeyboard.h"
#include "uilib.h"
#include "uilightpen.h"
#include "uimidi.h"
#include "uirom.h"
#include "uirs232user.h"
#include "uisidcart.h"
#include "uisoundexpander.h"
#include "uisoundsampler.h"
#include "uitfe.h"
#include "uivideo.h"
#include "vic20ui.h"
#include "winmain.h"
#include "uivicset.h"

static const unsigned int romset_dialog_resources[UIROM_TYPE_MAX] = {
    IDD_VIC20ROM_RESOURCE_DIALOG,
    IDD_VIC20ROMDRIVE_RESOURCE_DIALOG,
    0
};

static const ui_menu_toggle_t vic20_ui_menu_toggles[] = {
    { "VICDoubleSize", IDM_TOGGLE_DOUBLESIZE },
    { "VICDoubleScan", IDM_TOGGLE_DOUBLESCAN },
    { "VICVideoCache", IDM_TOGGLE_VIDEOCACHE },
    { "IEEE488", IDM_IEEE488 },
    { "Mouse", IDM_PADDLES },
    { "CartridgeReset", IDM_TOGGLE_CART_RESET },
    { "FinalExpansionWriteBack", IDM_FINAL_EXPANSION_WRITEBACK },
    { "VicFlashPluginWriteBack", IDM_VIC_FLASH_PLUGIN_WRITEBACK },
    { "MegaCartNvRAMWriteBack", IDM_MEGACART_WRITEBACK },
    { NULL, 0 }
};

static const uirom_settings_t uirom_settings[] = {
    { UIROM_TYPE_MAIN, TEXT("Kernal"), "KernalName",
      IDC_VIC20ROM_KERNAL_FILE, IDC_VIC20ROM_KERNAL_BROWSE,
      IDC_VIC20ROM_KERNAL_RESOURCE },
    { UIROM_TYPE_MAIN, TEXT("Basic"), "BasicName",
      IDC_VIC20ROM_BASIC_FILE, IDC_VIC20ROM_BASIC_BROWSE,
      IDC_VIC20ROM_BASIC_RESOURCE },
    { UIROM_TYPE_MAIN, TEXT("Character"), "ChargenName",
      IDC_VIC20ROM_CHARGEN_FILE, IDC_VIC20ROM_CHARGEN_BROWSE,
      IDC_VIC20ROM_CHARGEN_RESOURCE },
    { UIROM_TYPE_DRIVE, TEXT("1541"), "DosName1541",
      IDC_DRIVEROM_1541_FILE, IDC_DRIVEROM_1541_BROWSE,
      IDC_DRIVEROM_1541_RESOURCE },
    { UIROM_TYPE_DRIVE, TEXT("1541-II"), "DosName1541ii",
      IDC_DRIVEROM_1541II_FILE, IDC_DRIVEROM_1541II_BROWSE,
      IDC_DRIVEROM_1541II_RESOURCE },
    { UIROM_TYPE_DRIVE, TEXT("1570"), "DosName1570",
      IDC_DRIVEROM_1570_FILE, IDC_DRIVEROM_1570_BROWSE,
      IDC_DRIVEROM_1570_RESOURCE },
    { UIROM_TYPE_DRIVE, TEXT("1571"), "DosName1571",
      IDC_DRIVEROM_1571_FILE, IDC_DRIVEROM_1571_BROWSE,
      IDC_DRIVEROM_1571_RESOURCE },
    { UIROM_TYPE_DRIVE, TEXT("1581"), "DosName1581",
      IDC_DRIVEROM_1581_FILE, IDC_DRIVEROM_1581_BROWSE,
      IDC_DRIVEROM_1581_RESOURCE },
    { UIROM_TYPE_DRIVE, TEXT("2031"), "DosName2031",
      IDC_DRIVEROM_2031_FILE, IDC_DRIVEROM_2031_BROWSE,
      IDC_DRIVEROM_2031_RESOURCE },
    { UIROM_TYPE_DRIVE, TEXT("2040"), "DosName2040",
      IDC_DRIVEROM_2040_FILE, IDC_DRIVEROM_2040_BROWSE,
      IDC_DRIVEROM_2040_RESOURCE },
    { UIROM_TYPE_DRIVE, TEXT("3040"), "DosName3040",
      IDC_DRIVEROM_3040_FILE, IDC_DRIVEROM_3040_BROWSE,
      IDC_DRIVEROM_3040_RESOURCE },
    { UIROM_TYPE_DRIVE, TEXT("4040"), "DosName4040",
      IDC_DRIVEROM_4040_FILE, IDC_DRIVEROM_4040_BROWSE,
      IDC_DRIVEROM_4040_RESOURCE },
    { UIROM_TYPE_DRIVE, TEXT("1001"), "DosName1001",
      IDC_DRIVEROM_1001_FILE, IDC_DRIVEROM_1001_BROWSE,
      IDC_DRIVEROM_1001_RESOURCE },
    { 0, NULL, NULL, 0, 0, 0 }
};

#define VIC20UI_KBD_NUM_MAP 2

static const uikeyboard_mapping_entry_t mapping_entry[VIC20UI_KBD_NUM_MAP] = {
    { IDC_VIC20KBD_MAPPING_SELECT_SYM, IDC_VIC20KBD_MAPPING_SYM,
      IDC_VIC20KBD_MAPPING_SYM_BROWSE, "KeymapSymFile" },
    { IDC_VIC20KBD_MAPPING_SELECT_POS, IDC_VIC20KBD_MAPPING_POS,
      IDC_VIC20KBD_MAPPING_POS_BROWSE, "KeymapPosFile" }
};

static uilib_localize_dialog_param vic20_kbd_trans[] = {
    { IDC_VIC20KBD_MAPPING_SELECT_SYM, IDS_SYMBOLIC, 0 },
    { IDC_VIC20KBD_MAPPING_SELECT_POS, IDS_POSITIONAL, 0 },
    { IDC_VIC20KBD_MAPPING_SYM_BROWSE, IDS_BROWSE, 0 },
    { IDC_VIC20KBD_MAPPING_POS_BROWSE, IDS_BROWSE, 0 },
    { IDC_VIC20KBD_MAPPING_DUMP, IDS_DUMP_KEYSET, 0 },
    { IDC_KBD_SHORTCUT_DUMP, IDS_DUMP_SHORTCUTS, 0 },
    { 0, 0, 0 }
};

static uilib_dialog_group vic20_kbd_left_group[] = {
    { IDC_VIC20KBD_MAPPING_SELECT_SYM, 1 },
    { IDC_VIC20KBD_MAPPING_SELECT_POS, 1 },
    { 0, 0 }
};

static uilib_dialog_group vic20_kbd_middle_group[] = {
    { IDC_VIC20KBD_MAPPING_SYM, 0 },
    { IDC_VIC20KBD_MAPPING_POS, 0 },
    { 0, 0 }
};

static uilib_dialog_group vic20_kbd_right_group[] = {
    { IDC_VIC20KBD_MAPPING_SYM_BROWSE, 0 },
    { IDC_VIC20KBD_MAPPING_POS_BROWSE, 0 },
    { 0, 0 }
};

static uilib_dialog_group vic20_kbd_buttons_group[] = {
    { IDC_VIC20KBD_MAPPING_DUMP, 1 },
    { IDC_KBD_SHORTCUT_DUMP, 1 },
    { 0, 0 }
};

static int vic20_kbd_move_buttons_group[] = {
    IDC_VIC20KBD_MAPPING_DUMP,
    IDC_KBD_SHORTCUT_DUMP,
    0
};

static uikeyboard_config_t uikeyboard_config = {
    IDD_VIC20KBD_MAPPING_SETTINGS_DIALOG,
    VIC20UI_KBD_NUM_MAP,
    mapping_entry,
    IDC_VIC20KBD_MAPPING_DUMP,
    vic20_kbd_trans,
    vic20_kbd_left_group,
    vic20_kbd_middle_group,
    vic20_kbd_right_group,
    vic20_kbd_buttons_group,
    vic20_kbd_move_buttons_group
};

static const uicart_params_t vic20_ui_cartridges[] = {
    { IDM_CART_VIC20_8KB_2000, CARTRIDGE_VIC20_16KB_2000, IDS_ATTACH_4_8_16_CART_2000, UILIB_FILTER_ALL },
    { IDM_CART_VIC20_16KB_4000, CARTRIDGE_VIC20_16KB_4000, IDS_ATTACH_4_8_16_CART_4000, UILIB_FILTER_ALL },
    { IDM_CART_VIC20_8KB_6000, CARTRIDGE_VIC20_16KB_6000, IDS_ATTACH_4_8_16_CART_6000, UILIB_FILTER_ALL },
    { IDM_CART_VIC20_8KB_A000, CARTRIDGE_VIC20_8KB_A000, IDS_ATTACH_4_8_CART_A000, UILIB_FILTER_ALL },
    { IDM_CART_VIC20_4KB_B000, CARTRIDGE_VIC20_4KB_B000, IDS_ATTACH_4_CART_B000, UILIB_FILTER_ALL },
    { 0, 0, 0, 0 }
};

ui_menu_translation_table_t vic20ui_menu_translation_table[] = {
    { IDM_EXIT, IDS_MI_EXIT },
    { IDM_ABOUT, IDS_MI_ABOUT },
    { IDM_HELP, IDS_MP_HELP },
    { IDM_PAUSE, IDS_MI_PAUSE },
    { IDM_EDIT_COPY, IDS_MI_EDIT_COPY },
    { IDM_EDIT_PASTE, IDS_MI_EDIT_PASTE },
    { IDM_AUTOSTART, IDS_MI_AUTOSTART },
    { IDM_RESET_HARD, IDS_MI_RESET_HARD },
    { IDM_RESET_SOFT, IDS_MI_RESET_SOFT },
    { IDM_RESET_DRIVE8, IDS_MI_DRIVE8 },
    { IDM_RESET_DRIVE9, IDS_MI_DRIVE9 },
    { IDM_RESET_DRIVE10, IDS_MI_DRIVE10 },
    { IDM_RESET_DRIVE11, IDS_MI_DRIVE11 },
    { IDM_ATTACH_8, IDS_MI_DRIVE8 },
    { IDM_ATTACH_9, IDS_MI_DRIVE9 },
    { IDM_ATTACH_10, IDS_MI_DRIVE10 },
    { IDM_ATTACH_11, IDS_MI_DRIVE11 },
    { IDM_DETACH_8, IDS_MI_DRIVE8 },
    { IDM_DETACH_9, IDS_MI_DRIVE9 },
    { IDM_DETACH_10, IDS_MI_DRIVE10 },
    { IDM_DETACH_11, IDS_MI_DRIVE11 },
    { IDM_ATTACH_TAPE, IDS_MI_ATTACH_TAPE },
    { IDM_DETACH_TAPE, IDS_MI_DETACH_TAPE },
    { IDM_DETACH_ALL, IDS_MI_DETACH_ALL },
    { IDM_TOGGLE_SOUND, IDS_MI_TOGGLE_SOUND },
    { IDM_TOGGLE_DOUBLESIZE, IDS_MI_TOGGLE_DOUBLESIZE },
    { IDM_TOGGLE_DOUBLESCAN, IDS_MI_TOGGLE_DOUBLESCAN },
    { IDM_TOGGLE_DRIVE_TRUE_EMULATION, IDS_MI_DRIVE_TRUE_EMULATION },
    { IDM_TOGGLE_AUTOSTART_HANDLE_TDE, IDS_MI_AUTOSTART_HANDLE_TDE },
    { IDM_TOGGLE_VIDEOCACHE, IDS_MI_TOGGLE_VIDEOCACHE },
    { IDM_DRIVE_SETTINGS, IDS_MI_DRIVE_SETTINGS },
    { IDM_FLIP_ADD, IDS_MI_FLIP_ADD },
    { IDM_FLIP_REMOVE, IDS_MI_FLIP_REMOVE },
    { IDM_FLIP_NEXT, IDS_MI_FLIP_NEXT },
    { IDM_FLIP_PREVIOUS, IDS_MI_FLIP_PREVIOUS },
    { IDM_FLIP_LOAD, IDS_MI_FLIP_LOAD },
    { IDM_FLIP_SAVE, IDS_MI_FLIP_SAVE },
    { IDM_DATASETTE_CONTROL_STOP, IDS_MI_DATASETTE_STOP },
    { IDM_DATASETTE_CONTROL_START, IDS_MI_DATASETTE_START },
    { IDM_DATASETTE_CONTROL_FORWARD, IDS_MI_DATASETTE_FORWARD },
    { IDM_DATASETTE_CONTROL_REWIND, IDS_MI_DATASETTE_REWIND },
    { IDM_DATASETTE_CONTROL_RECORD, IDS_MI_DATASETTE_RECORD },
    { IDM_DATASETTE_CONTROL_RESET, IDS_MI_DATASETTE_RESET },
    { IDM_DATASETTE_RESET_COUNTER, IDS_MI_DATASETTE_RESET_COUNTER },
    { IDM_CART_SET_DEFAULT, IDS_MI_CART_SET_DEFAULT },
    { IDM_CART_DETACH, IDS_MI_CART_DETACH },
    { IDM_MONITOR, IDS_MI_MONITOR },
#ifdef DEBUG
    { IDM_DEBUG_MODE_NORMAL, IDS_MI_DEBUG_MODE_NORMAL },
    { IDM_DEBUG_MODE_SMALL, IDS_MI_DEBUG_MODE_SMALL },
    { IDM_DEBUG_MODE_HISTORY, IDS_MI_DEBUG_MODE_HISTORY },
    { IDM_DEBUG_MODE_AUTOPLAY, IDS_MI_DEBUG_MODE_AUTOPLAY },
    { IDM_TOGGLE_MAINCPU_TRACE, IDS_MI_TOGGLE_MAINCPU_TRACE },
    { IDM_TOGGLE_DRIVE0CPU_TRACE, IDS_MI_TOGGLE_DRIVE0CPU_TRACE },
    { IDM_TOGGLE_DRIVE1CPU_TRACE, IDS_MI_TOGGLE_DRIVE1CPU_TRACE },
#endif
    { IDM_SNAPSHOT_LOAD, IDS_MI_SNAPSHOT_LOAD },
    { IDM_SNAPSHOT_SAVE, IDS_MI_SNAPSHOT_SAVE },
    { IDM_LOADQUICK, IDS_MI_LOADQUICK },
    { IDM_SAVEQUICK, IDS_MI_SAVEQUICK },
    { IDM_EVENT_TOGGLE_RECORD, IDS_MI_EVENT_TOGGLE_RECORD },
    { IDM_EVENT_TOGGLE_PLAYBACK, IDS_MI_EVENT_TOGGLE_PLAYBACK },
    { IDM_EVENT_SETMILESTONE, IDS_MI_EVENT_SETMILESTONE },
    { IDM_EVENT_RESETMILESTONE, IDS_MI_EVENT_RESETMILESTONE },
    { IDM_EVENT_START_MODE_SAVE, IDS_MI_EVENT_START_MODE_SAVE },
    { IDM_EVENT_START_MODE_LOAD, IDS_MI_EVENT_START_MODE_LOAD },
    { IDM_EVENT_START_MODE_RESET, IDS_MI_EVENT_START_MODE_RESET },
    { IDM_EVENT_START_MODE_PLAYBACK, IDS_MI_EVENT_START_MODE_PLAYBCK },
    { IDM_EVENT_DIRECTORY, IDS_MI_EVENT_DIRECTORY },
    { IDM_MEDIAFILE, IDS_MI_MEDIAFILE },
    { IDM_SOUND_RECORD_START, IDS_MI_SOUND_RECORD_START },
    { IDM_SOUND_RECORD_STOP, IDS_MI_SOUND_RECORD_STOP },
    { IDM_REFRESH_RATE_AUTO, IDS_MI_REFRESH_RATE_AUTO },
    { IDM_MAXIMUM_SPEED_NO_LIMIT, IDS_MI_MAXIMUM_SPEED_NO_LIMIT },
    { IDM_MAXIMUM_SPEED_CUSTOM, IDS_MI_MAXIMUM_SPEED_CUSTOM },
    { IDM_TOGGLE_WARP_MODE, IDS_MI_TOGGLE_WARP_MODE },
    { IDM_TOGGLE_DX9DISABLE, IDS_MI_TOGGLE_DX9DISABLE },
    { IDM_TOGGLE_ALWAYSONTOP, IDS_MI_TOGGLE_ALWAYSONTOP },
    { IDM_SWAP_EXTRA_JOYSTICK, IDS_MI_SWAP_EXTRA_JOYSTICK },
    { IDM_ALLOW_JOY_OPPOSITE_TOGGLE, IDS_MI_ALLOW_JOY_OPPOSITE },
    { IDM_JOYKEYS_TOGGLE, IDS_MI_JOYKEYS_TOGGLE },
    { IDM_TOGGLE_VIRTUAL_DEVICES, IDS_MI_TOGGLE_VIRTUAL_DEVICES },
    { IDM_IEEE488, IDS_MI_IEEE488 },
    { IDM_PADDLES, IDS_MI_PADDLES },
    { IDM_AUTOSTART_SETTINGS, IDS_MI_AUTOSTART_SETTINGS },
    { IDM_VIDEO_SETTINGS, IDS_MI_VIDEO_SETTINGS },
    { IDM_DEVICEMANAGER, IDS_MI_DEVICEMANAGER },
    { IDM_JOY_SETTINGS, IDS_MI_JOY_SETTINGS },
    { IDM_EXTRA_JOY_SETTINGS, IDS_MI_USERPORT_JOY_SETTINGS },
    { IDM_KEYBOARD_SETTINGS, IDS_MI_KEYBOARD_SETTINGS },
    { IDM_LIGHTPEN_SETTINGS, IDS_MI_LIGHTPEN_SETTINGS },
    { IDM_SOUND_SETTINGS, IDS_MI_SOUND_SETTINGS },
    { IDM_ROM_SETTINGS, IDS_MI_ROM_SETTINGS },
    { IDM_RAM_SETTINGS, IDS_MI_RAM_SETTINGS },
    { IDM_DATASETTE_SETTINGS, IDS_MI_DATASETTE_SETTINGS },
    { IDM_RS232_SETTINGS, IDS_MI_RS232_SETTINGS },
    { IDM_RS232USER_SETTINGS, IDS_MI_RS232USER_SETTINGS },
    { IDM_SETTINGS_SAVE_FILE, IDS_MI_SETTINGS_SAVE_FILE },
    { IDM_SETTINGS_LOAD_FILE, IDS_MI_SETTINGS_LOAD_FILE },
    { IDM_SETTINGS_SAVE, IDS_MI_SETTINGS_SAVE },
    { IDM_SETTINGS_LOAD, IDS_MI_SETTINGS_LOAD },
    { IDM_SETTINGS_DEFAULT, IDS_MI_SETTINGS_DEFAULT },
    { IDM_TOGGLE_SAVE_SETTINGS_ON_EXIT, IDS_MI_SAVE_SETTINGS_ON_EXIT },
    { IDM_TOGGLE_CONFIRM_ON_EXIT, IDS_MI_CONFIRM_ON_EXIT },
    { IDM_LANG_EN, IDS_MI_LANG_EN },
    { IDM_LANG_DA, IDS_MI_LANG_DA },
    { IDM_LANG_DE, IDS_MI_LANG_DE },
    { IDM_LANG_ES, IDS_MI_LANG_ES },
    { IDM_LANG_FR, IDS_MI_LANG_FR },
    { IDM_LANG_HU, IDS_MI_LANG_HU },
    { IDM_LANG_IT, IDS_MI_LANG_IT },
    { IDM_LANG_KO, IDS_MI_LANG_KO },
    { IDM_LANG_NL, IDS_MI_LANG_NL },
    { IDM_LANG_PL, IDS_MI_LANG_PL },
    { IDM_LANG_RU, IDS_MI_LANG_RU },
    { IDM_LANG_SV, IDS_MI_LANG_SV },
    { IDM_LANG_TR, IDS_MI_LANG_TR },
    { IDM_CMDLINE, IDS_MI_CMDLINE },
    { IDM_CONTRIBUTORS, IDS_MI_CONTRIBUTORS },
    { IDM_LICENSE, IDS_MI_LICENSE },
    { IDM_WARRANTY, IDS_MI_WARRANTY },
    { IDM_TOGGLE_FULLSCREEN, IDS_MI_TOGGLE_FULLSCREEN },
    { IDM_SIDCART_SETTINGS, IDS_MI_SIDCART_SETTINGS },
    { IDM_MIDI_SETTINGS, IDS_MI_MIDI_SETTINGS },
    { IDM_FINAL_EXPANSION_WRITEBACK, IDS_MI_FINAL_EXPANSION_WRITEBACK },
    { IDM_VIC_FLASH_PLUGIN_WRITEBACK, IDS_MI_VIC_FLASH_PLUGIN_WRITEBACK },
    { IDM_MEGACART_WRITEBACK, IDS_MI_MEGACART_WRITEBACK },
    { IDM_MEGACART_WRITEBACK_FILE, IDS_MI_MEGACART_WRITEBACK_FILE },
    { IDM_CART_VIC20_GENERIC, IDS_MI_CART_VIC20_GENERIC },
    { IDM_CART_VIC20_MEGACART, IDS_MI_CART_VIC20_MEGACART },
    { IDM_CART_VIC20_FINAL_EXPANSION, IDS_MI_CART_VIC20_FINAL_EXPANSION },
    { IDM_CART_VIC20_FP, IDS_MI_CART_VIC20_FP },
    { IDM_CART_VIC20_SMART_ATTACH, IDS_MI_CART_VIC20_SMART_ATTACH },
    { IDM_CART_VIC20_8KB_2000, IDS_MI_CART_VIC20_8KB_2000 },
    { IDM_CART_VIC20_16KB_4000, IDS_MI_CART_VIC20_16KB_4000 },
    { IDM_CART_VIC20_8KB_6000, IDS_MI_CART_VIC20_8KB_6000 },
    { IDM_CART_VIC20_8KB_A000, IDS_MI_CART_VIC20_8KB_A000 },
    { IDM_CART_VIC20_4KB_B000, IDS_MI_CART_VIC20_4KB_B000 },
    { IDM_TOGGLE_CART_RESET, IDS_MI_TOGGLE_CART_RESET },
    { IDM_VIC_SETTINGS, IDS_MI_VIC_SETTINGS },
    { IDM_ACIA_SETTINGS, IDS_MI_ACIA_SETTINGS_MASCUERADE },
    { IDM_GEORAM_SETTINGS, IDS_MI_GEORAM_SETTINGS_MASCUERADE },
    { IDM_DIGIMAX_SETTINGS, IDS_MI_DIGIMAX_SETTINGS_MASCUERADE },
#ifdef HAVE_TFE
    { IDM_TFE_SETTINGS, IDS_MI_TFE_SETTINGS_MASCUERADE },
#endif
    { IDM_SFX_SE_SETTINGS, IDS_MI_SFX_SE_SETTINGS_MASCUERADE },
    { IDM_SFX_SS_SETTINGS, IDS_MI_SFX_SS_SETTINGS_MASCUERADE },
    { 0, 0 }
};

ui_popup_translation_table_t vic20ui_popup_translation_table[] = {
    { 1, IDS_MP_FILE },
    { 2, IDS_MP_ATTACH_DISK_IMAGE },
    { 2, IDS_MP_DETACH_DISK_IMAGE },
    { 2, IDS_MP_FLIP_LIST },
    { 2, IDS_MP_DATASETTE_CONTROL },
    { 2, IDS_MP_ATTACH_CARTRIDGE_IMAGE },
    { 3, IDS_MP_ADD_TO_GENERIC },
    { 2, IDS_MP_RESET },
#ifdef DEBUG
    { 2, IDS_MP_DEBUG },
    { 3, IDS_MP_MODE },
#endif
    { 1, IDS_MP_EDIT },
    { 1, IDS_MP_SNAPSHOT },
    { 2, IDS_MP_RECORDING_START_MODE },
    { 1, IDS_MP_OPTIONS },
    { 2, IDS_MP_REFRESH_RATE },
    { 2, IDS_MP_MAXIMUM_SPEED },
    { 2, IDS_MP_VIDEO_STANDARD },
    { 1, IDS_MP_SETTINGS },
    { 2, IDS_MP_CARTRIDGE_IO_SETTINGS },
    { 1, IDS_MP_LANGUAGE },
    { 1, IDS_MP_HELP },
    { 0, 0 }
};

static uilib_localize_dialog_param vic20_main_trans[] = {
    { IDC_KERNAL, IDS_KERNAL, 0 },
    { IDC_VIC20ROM_KERNAL_BROWSE, IDS_BROWSE, 0 },
    { IDC_BASIC, IDS_BASIC, 0 },
    { IDC_VIC20ROM_BASIC_BROWSE, IDS_BROWSE, 0 },
    { IDC_CHARACTER, IDS_CHARACTER, 0 },
    { IDC_VIC20ROM_CHARGEN_BROWSE, IDS_BROWSE, 0 },
    { 0, 0, 0 }
};

static uilib_localize_dialog_param vic20_drive_trans[] = {
    { IDC_DRIVEROM_1541_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_1541II_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_1570_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_1571_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_1581_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_2031_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_2040_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_3040_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_4040_BROWSE, IDS_BROWSE, 0 },
    { IDC_DRIVEROM_1001_BROWSE, IDS_BROWSE, 0 },
    { 0, 0, 0 }
};

static uilib_localize_dialog_param vic20_main_res_trans[] = {
    { 0, IDS_COMPUTER_RESOURCES_CAPTION, -1 },
    { IDC_COMPUTER_RESOURCES, IDS_COMPUTER_RESOURCES, 0 },
    { IDC_VIC20ROM_KERNAL_RESOURCE, IDS_KERNAL, 0 },
    { IDC_VIC20ROM_BASIC_RESOURCE, IDS_BASIC, 0 },
    { IDC_VIC20ROM_CHARGEN_RESOURCE, IDS_CHARACTER, 0 },
    { IDOK, IDS_OK, 0 },
    { IDCANCEL, IDS_CANCEL, 0 },
    { 0, 0, 0 }
};

static uilib_dialog_group vic20_main_left_group[] = {
    { IDC_KERNAL, 0 },
    { IDC_BASIC, 0 },
    { IDC_CHARACTER, 0 },
    { 0, 0 }
};

static uilib_dialog_group vic20_main_middle_group[] = {
    { IDC_VIC20ROM_KERNAL_FILE, 0 },
    { IDC_VIC20ROM_BASIC_FILE, 0} ,
    { IDC_VIC20ROM_CHARGEN_FILE, 0 },
    { 0, 0 }
};

static uilib_dialog_group vic20_main_right_group[] = {
    { IDC_VIC20ROM_KERNAL_BROWSE, 0 },
    { IDC_VIC20ROM_BASIC_BROWSE, 0} ,
    { IDC_VIC20ROM_CHARGEN_BROWSE, 0 },
    { 0, 0}
};

static uilib_dialog_group vic20_drive_left_group[] = {
    { IDC_1541, 0 },
    { IDC_1541_II, 0 },
    { IDC_1570, 0 },
    { IDC_1571, 0 },
    { IDC_1581, 0 },
    { IDC_2031, 0 },
    { IDC_2040, 0 },
    { IDC_3040, 0 },
    { IDC_4040, 0 },
    { IDC_1001, 0 },
    { 0, 0 }
};

static uilib_dialog_group vic20_drive_middle_group[] = {
    { IDC_DRIVEROM_1541_FILE, 0 },
    { IDC_DRIVEROM_1541II_FILE, 0 },
    { IDC_DRIVEROM_1570_FILE, 0 },
    { IDC_DRIVEROM_1571_FILE, 0 },
    { IDC_DRIVEROM_1581_FILE, 0 },
    { IDC_DRIVEROM_2031_FILE, 0 },
    { IDC_DRIVEROM_2040_FILE, 0 },
    { IDC_DRIVEROM_3040_FILE, 0 },
    { IDC_DRIVEROM_4040_FILE, 0 },
    { IDC_DRIVEROM_1001_FILE, 0 },
    { 0, 0 }
};

static uilib_dialog_group vic20_drive_right_group[] = {
    { IDC_DRIVEROM_1541_BROWSE, 0 },
    { IDC_DRIVEROM_1541II_BROWSE, 0 },
    { IDC_DRIVEROM_1570_BROWSE, 0 },
    { IDC_DRIVEROM_1571_BROWSE, 0 },
    { IDC_DRIVEROM_1581_BROWSE, 0 },
    { IDC_DRIVEROM_2031_BROWSE, 0 },
    { IDC_DRIVEROM_2040_BROWSE, 0 },
    { IDC_DRIVEROM_3040_BROWSE, 0 },
    { IDC_DRIVEROM_4040_BROWSE, 0 },
    { IDC_DRIVEROM_1001_BROWSE, 0 },
    { 0, 0 }
};

static generic_trans_table_t vic20_generic_trans[] = {
    { IDC_1541, "1541" },
    { IDC_1541_II, "1541-II" },
    { IDC_1570, "1570" },
    { IDC_1571, "1571" },
    { IDC_1581, "1581" },
    { IDC_2031, "2031" },
    { IDC_2040, "2040" },
    { IDC_3040, "3040" },
    { IDC_4040, "4040" },
    { IDC_1001, "1001" },
    { 0, NULL }
};

static generic_trans_table_t vic20_generic_res_trans[] = {
    { IDC_DRIVEROM_1541_RESOURCE, "1541" },
    { IDC_DRIVEROM_1541II_RESOURCE, "1541-II" },
    { IDC_DRIVEROM_1570_RESOURCE, "1570" },
    { IDC_DRIVEROM_1571_RESOURCE, "1571" },
    { IDC_DRIVEROM_1581_RESOURCE, "1581" },
    { IDC_DRIVEROM_2031_RESOURCE, "2031" },
    { IDC_DRIVEROM_2040_RESOURCE, "2040" },
    { IDC_DRIVEROM_3040_RESOURCE, "3040" },
    { IDC_DRIVEROM_4040_RESOURCE, "4040" },
    { IDC_DRIVEROM_1001_RESOURCE, "1001" },
    { 0, NULL }
};

/* Probably one should simply remove the size numbers from the IDM_* stuff */
static void vic20_ui_specific(WPARAM wparam, HWND hwnd)
{
    TCHAR *st_name;

    switch (wparam) {
        case IDM_CART_VIC20_GENERIC:
            uicart_attach_special(hwnd, translate_text(IDS_SELECT_GENERIC), UILIB_FILTER_ALL, CARTRIDGE_VIC20_GENERIC);
            break;
        case IDM_CART_VIC20_FP:
            uicart_attach_special(hwnd, translate_text(IDS_SELECT_FP), UILIB_FILTER_ALL, CARTRIDGE_VIC20_FP);
            break;
        case IDM_CART_VIC20_MEGACART:
            uicart_attach_special(hwnd, translate_text(IDS_SELECT_MEGACART), UILIB_FILTER_ALL, CARTRIDGE_VIC20_MEGACART);
            break;
        case IDM_CART_VIC20_FINAL_EXPANSION:
            uicart_attach_special(hwnd, translate_text(IDS_SELECT_FINAL_EXPANSION), UILIB_FILTER_ALL, CARTRIDGE_VIC20_FINAL_EXPANSION);
            break;
        case IDM_CART_VIC20_SMART_ATTACH:
            uicart_attach_special(hwnd, translate_text(IDS_SELECT_CARTRIDGE_IMAGE), UILIB_FILTER_ALL, CARTRIDGE_VIC20_DETECT);
            break;
        case IDM_CART_VIC20_8KB_2000:
        case IDM_CART_VIC20_16KB_4000:
        case IDM_CART_VIC20_8KB_6000:
        case IDM_CART_VIC20_8KB_A000:
        case IDM_CART_VIC20_4KB_B000:
            uicart_attach(wparam, hwnd, vic20_ui_cartridges);
            break;
        case IDM_CART_SET_DEFAULT:
            cartridge_set_default();
            break;
        case IDM_CART_DETACH:
            cartridge_detach_image(-1);
            break;
        case IDM_VIC_SETTINGS:
            ui_vic_settings_dialog(hwnd);
            break;
        case IDM_SIDCART_SETTINGS:
            ui_sidcart_settings_dialog(hwnd);
            break;
        case IDM_ACIA_SETTINGS:
            ui_acia_settings_dialog(hwnd);
            break;
        case IDM_GEORAM_SETTINGS:
            ui_georam_settings_dialog(hwnd);
            break;
        case IDM_DIGIMAX_SETTINGS:
            ui_digimax_settings_dialog(hwnd);
            break;
#ifdef HAVE_TFE
        case IDM_TFE_SETTINGS:
           ui_tfe_settings_dialog(hwnd);
           break;
#endif
        case IDM_SFX_SE_SETTINGS:
            ui_soundexpander_settings_dialog(hwnd);
            break;
        case IDM_SFX_SS_SETTINGS:
            ui_soundsampler_settings_dialog(hwnd);
            break;
        case IDM_MIDI_SETTINGS:
            ui_midi_settings_dialog(hwnd);
            break;
        case IDM_JOY_SETTINGS:
            ui_joystick_settings_dialog(hwnd);
            break;
        case IDM_LIGHTPEN_SETTINGS:
            ui_lightpen_settings_dialog(hwnd);
            break;
        case IDM_EXTRA_JOY_SETTINGS:
            ui_extra_joystick_settings_dialog(hwnd);
            break;
        case IDM_ROM_SETTINGS:
            uirom_settings_dialog(hwnd, IDD_VIC20ROM_SETTINGS_DIALOG, IDD_VIC20DRIVEROM_SETTINGS_DIALOG,
                                  romset_dialog_resources, uirom_settings, 
                                  vic20_main_trans, vic20_drive_trans, vic20_generic_trans,
                                  vic20_main_left_group, vic20_main_middle_group, vic20_main_right_group,
                                  vic20_drive_left_group, vic20_drive_middle_group, vic20_drive_right_group,
                                  vic20_main_res_trans, vic20_generic_res_trans);
            break;
        case IDM_VIDEO_SETTINGS:
            ui_video_settings_dialog(hwnd, UI_VIDEO_CHIP_VIC, UI_VIDEO_CHIP_NONE);
            break;
        case IDM_DRIVE_SETTINGS:
            uidrivevic20_settings_dialog(hwnd);
            break;
        case IDM_RS232USER_SETTINGS:
            ui_rs232user_settings_dialog(hwnd);
            break;
        case IDM_KEYBOARD_SETTINGS:
            uikeyboard_settings_dialog(hwnd, &uikeyboard_config);
            break;
        case IDM_MEGACART_WRITEBACK_FILE:
            if ((st_name = uilib_select_file(hwnd, translate_text(IDS_MI_MEGACART_WRITEBACK_FILE), UILIB_FILTER_ALL, UILIB_SELECTOR_TYPE_FILE_SAVE, UILIB_SELECTOR_STYLE_DEFAULT)) != NULL) {
                char *name;

                name = system_wcstombs_alloc(st_name);

                resources_set_string("MegaCartNvRAMfilename", name);
                system_wcstombs_free(name);
                lib_free(st_name);
            }
            break;
    }
}

int vic20ui_init(void)
{
    ui_register_machine_specific(vic20_ui_specific);
    ui_register_menu_toggles(vic20_ui_menu_toggles);
    ui_register_translation_tables(vic20ui_menu_translation_table, vic20ui_popup_translation_table);

    return 0;
}

void vic20ui_shutdown(void)
{
}

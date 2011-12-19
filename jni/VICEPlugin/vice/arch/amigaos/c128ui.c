/*
 * c128ui.c
 *
 * Written by
 *  Mathias Roslund <vice.emu@amidog.se>
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

#define UI_C128
#define UI_MENU_NAME c128_ui_translation_menu
#define UI_TRANSLATED_MENU_NAME c128_ui_menu

#include "private.h"
#include "c128ui.h"
#include "c128uires.h"
#include "translate.h"
#include "uic64cart.h"
#include "ui.h"

#include "mui/uiacia.h"
#include "mui/uic128settings.h"
#include "mui/uidigimax.h"
#include "mui/uidrivec128.h"
#include "mui/uieasyflash.h"
#include "mui/uiexpert.h"
#include "mui/uigeoram.h"
#include "mui/uiide64.h"
#include "mui/uijoystick.h"
#include "mui/uijoystickll.h"
#include "mui/uimagicvoice.h"
#include "mui/uimouse.h"
#include "mui/uiprinter.h"
#include "mui/uiramcart.h"
#include "mui/uireu.h"
#include "mui/uiromc128settings.h"
#include "mui/uirs232user.h"
#include "mui/uisid.h"
#include "mui/uisoundexpander.h"
#include "mui/uivicii.h"
#include "mui/uivideo.h"

static const ui_res_possible_values_t VDCrev[] = {
    { 0, IDM_VDC_REV_0 },
    { 1, IDM_VDC_REV_1 },
    { 2, IDM_VDC_REV_2 },
    { -1, 0 }
};

static const ui_res_value_list_t c128_ui_res_values[] = {
    { "VDCRevision", VDCrev, 0 },
    { NULL, NULL, 0 }
};

static const ui_menu_toggle_t c128_ui_menu_toggles[] = {
    { "VICIIDoubleSize", IDM_TOGGLE_DOUBLESIZE },
    { "VICIIDoubleScan", IDM_TOGGLE_DOUBLESCAN },
    { "VICIIVideoCache", IDM_TOGGLE_VIDEOCACHE },
    { "IEEE488", IDM_IEEE488 },
    { "Mouse", IDM_MOUSE },
    { "CartridgeReset", IDM_TOGGLE_CART_RESET },
    { "VDCDoubleSize", IDM_TOGGLE_VDC_DOUBLESIZE },
    { "VDCDoubleScan", IDM_TOGGLE_VDC_DOUBLESCAN },
    { "VDC64KB", IDM_TOGGLE_VDC64KB },
    { "SFXSoundSampler", IDM_TOGGLE_SFX_SS },
//  { "InternalFunctionROM", IDM_TOGGLE_IFUNCTIONROM },
//  { "ExternalFunctionROM", IDM_TOGGLE_EFUNCTIONROM },
    { NULL, 0 }
};

static int c128_ui_specific(video_canvas_t *canvas, int idm)
{
    uic64cart_proc(canvas, idm);

    switch (idm) {
        case IDM_VICII_SETTINGS:
            ui_vicii_settings_dialog();
            break;
        case IDM_SID_SETTINGS:
            ui_sid_settings_dialog();
            break;
        case IDM_REU_SETTINGS:
            ui_reu_settings_dialog(canvas);
            break;
        case IDM_MAGIC_VOICE_SETTINGS:
            ui_magicvoice_settings_dialog(canvas);
            break;
        case IDM_GEORAM_SETTINGS:
            ui_georam_c64_settings_dialog(canvas);
            break;
        case IDM_RAMCART_SETTINGS:
            ui_ramcart_settings_dialog(canvas);
            break;
        case IDM_DIGIMAX_SETTINGS:
            ui_digimax_c64_settings_dialog(canvas);
            break;
        case IDM_EXPERT_SETTINGS:
            ui_expert_settings_dialog(canvas);
            break;
        case IDM_IDE64_SETTINGS:
            ui_ide64_settings_dialog(canvas);
            break;
        case IDM_SFX_SE_SETTINGS:
            ui_soundexpander_c64_settings_dialog(canvas);
            break;
        case IDM_EASYFLASH_SETTINGS:
            ui_easyflash_settings_dialog();
            break;
        case IDM_COMPUTER_ROM_SETTINGS:
            ui_c128_computer_rom_settings_dialog(canvas);
            break;
        case IDM_DRIVE_ROM_SETTINGS:
            ui_c128_drive_rom_settings_dialog(canvas);
            break;
#ifdef HAVE_TFE
        case IDM_TFE_SETTINGS:
//          ui_tfe_settings_dialog(hwnd);
            break;
#endif
        case IDM_C128_SETTINGS:
            ui_c128_settings_dialog(canvas);
            break;
        case IDM_VIDEO_SETTINGS:
            ui_video_settings_dialog(canvas,
                                     "VICIIExternalPalette", "VICIIPaletteFile",
                                     translate_text(IDS_VICII_EXTERNAL_PALETTE), translate_text(IDS_VICII_PALETTE_NAME),
                                     "VDCExternalPalette", "VDCPaletteFile",
                                     translate_text(IDS_VDC_EXTERNAL_PALETTE), translate_text(IDS_VDC_PALETTE_NAME),
                                     "VICIIScale2x");
            break;
        case IDM_DRIVE_SETTINGS:
            uidrivec128_settings_dialog();
            break;
        case IDM_PRINTER_SETTINGS:
            ui_printer_settings_dialog(canvas, 0, 1);
            break;
        case IDM_ACIA_SETTINGS:
            ui_acia128_settings_dialog();
            break;
        case IDM_RS232USER_SETTINGS:
            ui_rs232user_settings_dialog();
            break;
        case IDM_KEYBOARD_SETTINGS:
//          uikeyboard_settings_dialog(hwnd, &uikeyboard_config);
            break;
#ifdef AMIGA_OS4
        case IDM_JOY_SETTINGS:
            ui_joystick_settings_c64_dialog();
            break;
#else
        case IDM_JOY_DEVICE_SELECTION:
            ui_joystick_device_c64_dialog();
            break;
        case IDM_JOY_FIRE_SELECTION:
            ui_joystick_fire_c64_dialog();
            break;
#endif
        case IDM_MOUSE_SETTINGS:
            ui_mouse_settings_dialog();
            break;
    }

    return 0;
}

int c128ui_init(void)
{
    ui_register_menu_translation_layout(c128_ui_translation_menu);
    ui_register_menu_layout(c128_ui_menu);
    ui_register_machine_specific(c128_ui_specific);
    ui_register_menu_toggles(c128_ui_menu_toggles);
    ui_register_res_values(c128_ui_res_values);

    return 0;
}

void c128ui_shutdown(void)
{
}

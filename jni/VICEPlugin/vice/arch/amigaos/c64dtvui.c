/*
 * c64dtvui.c
 *
 * Written by
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
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

#define UI_C64DTV
#define UI_MENU_NAME c64dtv_ui_translation_menu
#define UI_TRANSLATED_MENU_NAME c64dtv_ui_menu

#include "private.h"
#include "c64ui.h"
#include "c64dtvuires.h"
#include "translate.h"

#include "mui/uic64dtv.h"
#include "mui/uidrivec64vic20.h"
#include "mui/uijoystick.h"
#include "mui/uijoystickll.h"
#include "mui/uiprinter.h"
#include "mui/uiromc64vic20settings.h"
#include "mui/uisiddtv.h"
#include "mui/uivicii.h"
#include "mui/uivideo.h"

static const ui_menu_toggle_t c64dtv_ui_menu_toggles[] = {
    { "VICIIDoubleSize", IDM_TOGGLE_DOUBLESIZE },
    { "VICIIDoubleScan", IDM_TOGGLE_DOUBLESCAN },
    { "VICIIVideoCache", IDM_TOGGLE_VIDEOCACHE },
    { "Mouse", IDM_MOUSE },
    { "ps2mouse", IDM_PS2_MOUSE },
    { NULL, 0 }
};

static int c64dtv_ui_specific(video_canvas_t *canvas, int idm)
{
    switch (idm) {
        case IDM_C64DTV_SETTINGS:
            ui_c64dtv_settings_dialog(canvas);
            break;
        case IDM_VICII_SETTINGS:
            ui_vicii_settings_dialog();
            break;
        case IDM_SID_SETTINGS:
            ui_siddtv_settings_dialog();
            break;
        case IDM_COMPUTER_ROM_SETTINGS:
            ui_c64vic20_computer_rom_settings_dialog(canvas);
            break;
        case IDM_DRIVE_ROM_SETTINGS:
            ui_c64vic20_drive_rom_settings_dialog(canvas);
            break;
        case IDM_VIDEO_SETTINGS:
            ui_video_settings_dialog(canvas,
                                     "VICIIExternalPalette", "VICIIPaletteFile",
                                     translate_text(IDS_VICII_EXTERNAL_PALETTE), translate_text(IDS_VICII_PALETTE_NAME),
                                     NULL, NULL,
                                     NULL, NULL,
                                     "VICIIScale2x");
            break;
        case IDM_DRIVE_SETTINGS:
            uidrivec64vic20_settings_dialog();
            break;
        case IDM_PRINTER_SETTINGS:
            ui_printer_settings_dialog(canvas, 0, 0);
            break;
#ifdef AMIGA_OS4
        case IDM_JOY_SETTINGS:
            ui_joystick_settings_c64dtv_dialog();
            break;
#else
        case IDM_JOY_DEVICE_SELECTION:
            ui_joystick_device_c64dtv_dialog();
            break;
        case IDM_JOY_FIRE_SELECTION:
            ui_joystick_fire_c64_dialog();
            break;
#endif
        case IDM_KEYBOARD_SETTINGS:
//          uikeyboard_settings_dialog(hwnd, &uikeyboard_config);
            break;
    }

    return 0;
}

int c64dtvui_init(void)
{
    ui_register_menu_translation_layout(c64dtv_ui_translation_menu);
    ui_register_menu_layout(c64dtv_ui_menu);
    ui_register_machine_specific(c64dtv_ui_specific);
    ui_register_menu_toggles(c64dtv_ui_menu_toggles);

    return 0;
}

void c64dtvui_shutdown(void)
{
}

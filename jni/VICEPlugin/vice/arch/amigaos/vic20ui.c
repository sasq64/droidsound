/*
 * vic20ui.c
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

#define UI_VIC20
#define UI_MENU_NAME vic20_ui_translation_menu
#define UI_TRANSLATED_MENU_NAME vic20_ui_menu

#include "cartridge.h"
#include "private.h"
#include "translate.h"
#include "uicart.h"
#include "uilib.h"
#include "vic20ui.h"
#include "vic20uires.h"

#include "mui/uiacia.h"
#include "mui/uidigimax.h"
#include "mui/uidrivec64vic20.h"
#include "mui/uigeoram.h"
#include "mui/uijoystick.h"
#include "mui/uijoystickll.h"
#include "mui/uiprinter.h"
#include "mui/uiromc64vic20settings.h"
#include "mui/uirs232user.h"
#include "mui/uisidcart.h"
#include "mui/uisoundexpander.h"
#include "mui/uisoundsampler.h"
#include "mui/uivic20mem.h"
#include "mui/uivideo.h"

static const ui_menu_toggle_t vic20_ui_menu_toggles[] = {
    { "VICDoubleSize", IDM_TOGGLE_DOUBLESIZE },
    { "VICDoubleScan", IDM_TOGGLE_DOUBLESCAN },
    { "VICVideoCache", IDM_TOGGLE_VIDEOCACHE },
    { "IEEE488", IDM_IEEE488 },
    { "CartridgeReset", IDM_TOGGLE_CART_RESET },
    { "FinalExpansionWriteBack", IDM_FINAL_EXPANSION_WRITEBACK },
    { "MegaCartNvRAMWriteBack", IDM_MEGACART_WRITEBACK },
    { "VicFlashPluginWriteBack", IDM_FP_WRITEBACK },
    { NULL, 0 }
};

static const uicart_params_t vic20_ui_cartridges[] = {
    { IDM_CART_VIC20_8KB_2000, CARTRIDGE_VIC20_16KB_2000, IDS_ATTACH_4_8_16KB_AT_2000, UILIB_FILTER_ALL },
    { IDM_CART_VIC20_16KB_4000, CARTRIDGE_VIC20_16KB_4000, IDS_ATTACH_4_8_16KB_AT_4000, UILIB_FILTER_ALL },
    { IDM_CART_VIC20_8KB_6000, CARTRIDGE_VIC20_16KB_6000, IDS_ATTACH_4_8_16KB_AT_6000, UILIB_FILTER_ALL },
    { IDM_CART_VIC20_8KB_A000, CARTRIDGE_VIC20_8KB_A000, IDS_ATTACH_4_8KB_AT_A000, UILIB_FILTER_ALL },
    { IDM_CART_VIC20_4KB_B000, CARTRIDGE_VIC20_4KB_B000, IDS_ATTACH_4KB_AT_B000, UILIB_FILTER_ALL },
    { 0, 0, 0, 0 }
};

/* Probably one should simply remove the size numbers from the IDM_* stuff */
static int vic20_ui_specific(video_canvas_t *canvas, int idm)
{
    char *fname = NULL;

    switch (idm) {
        case IDM_CART_VIC20_8KB_2000:
        case IDM_CART_VIC20_16KB_4000:
        case IDM_CART_VIC20_8KB_6000:
        case IDM_CART_VIC20_8KB_A000:
        case IDM_CART_VIC20_4KB_B000:
            uicart_attach(canvas, idm, vic20_ui_cartridges);
            break;
        case IDM_CART_VIC20_GENERIC:
            uicart_attach_special(canvas, translate_text(IDS_SELECT_GENERIC), UILIB_FILTER_ALL, CARTRIDGE_VIC20_GENERIC);
            break;
        case IDM_CART_VIC20_FP:
            uicart_attach_special(canvas, translate_text(IDS_SELECT_FP), UILIB_FILTER_ALL, CARTRIDGE_VIC20_FP);
            break;
        case IDM_CART_VIC20_MEGACART:
            uicart_attach_special(canvas, translate_text(IDS_SELECT_MEGACART), UILIB_FILTER_ALL, CARTRIDGE_VIC20_MEGACART);
            break;
        case IDM_CART_VIC20_FINAL_EXPANSION:
            uicart_attach_special(canvas, translate_text(IDS_SELECT_FINAL_EXPANSION), UILIB_FILTER_ALL, CARTRIDGE_VIC20_FINAL_EXPANSION);
            break;
        case IDM_CART_VIC20_SMART_ATTACH:
            uicart_attach_special(canvas, translate_text(IDS_SELECT_CARTRIDGE_IMAGE), UILIB_FILTER_ALL, CARTRIDGE_VIC20_DETECT);
            break;
        case IDM_CART_SET_DEFAULT:
            cartridge_set_default();
            break;
        case IDM_CART_DETACH:
            cartridge_detach_image(-1);
            break;
        case IDM_VIC_SETTINGS:
            ui_vic_settings_dialog();
            break;
        case IDM_COMPUTER_ROM_SETTINGS:
            ui_c64vic20_computer_rom_settings_dialog(canvas);
            break;
        case IDM_DRIVE_ROM_SETTINGS:
            ui_c64vic20_drive_rom_settings_dialog(canvas);
            break;
        case IDM_VIDEO_SETTINGS:
            ui_video_settings_dialog(canvas,
                                     "VICExternalPalette", "VICPaletteFile",
                                     translate_text(IDS_VIC_EXTERNAL_PALETTE), translate_text(IDS_VIC_PALETTE_NAME),
                                     NULL, NULL,
                                     NULL, NULL,
                                     "VICScale2x");
            break;
        case IDM_DRIVE_SETTINGS:
            uidrivec64vic20_settings_dialog();
            break;
        case IDM_PRINTER_SETTINGS:
            ui_printer_settings_dialog(canvas, 0, 1);
            break;
        case IDM_RS232USER_SETTINGS:
            ui_rs232user_settings_dialog();
            break;
        case IDM_SIDCART_SETTINGS:
            ui_sidcart_settings_dialog("$9800", "$9C00", "VIC20");
            break;
#ifdef AMIGA_OS4
        case IDM_JOY_SETTINGS:
            ui_joystick_settings_vic20_dialog();
            break;
#else
        case IDM_JOY_DEVICE_SELECTION:
            ui_joystick_device_vic20_dialog();
            break;
        case IDM_JOY_FIRE_SELECTION:
            ui_joystick_fire_vic20_dialog();
            break;
#endif
        case IDM_MEGACART_WRITEBACK_FILE:
            fname = BrowseFile(translate_text(IDMS_MEGACART_WRITEBACK_FILE), "#?", canvas);
            if (fname != NULL) {
                resources_set_string("MegaCartNvRAMfilename", fname);
            }
            break;
        case IDM_ACIA_SETTINGS:
            ui_acia20_settings_dialog();
            break;
        case IDM_DIGIMAX_SETTINGS:
            ui_digimax_vic20_settings_dialog(canvas);
            break;
        case IDM_GEORAM_SETTINGS:
            ui_georam_vic20_settings_dialog(canvas);
            break;
        case IDM_SFX_SE_SETTINGS:
            ui_soundexpander_vic20_settings_dialog(canvas);
            break;
        case IDM_SFX_SS_SETTINGS:
            ui_soundsampler_settings_dialog(canvas);
            break;
        case IDM_KEYBOARD_SETTINGS:
//          uikeyboard_settings_dialog(hwnd, &uikeyboard_config);
            break;
    }

    return 0;
}

int vic20ui_init(void)
{
    ui_register_menu_translation_layout(vic20_ui_translation_menu);
    ui_register_menu_layout(vic20_ui_menu);
    ui_register_machine_specific(vic20_ui_specific);
    ui_register_menu_toggles(vic20_ui_menu_toggles);

    return 0;
}

void vic20ui_shutdown(void)
{
}

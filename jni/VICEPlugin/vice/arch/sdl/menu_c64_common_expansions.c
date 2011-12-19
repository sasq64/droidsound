/*
 * menu_c64_common_expansions.c - C64/C128 expansions menu for SDL UI.
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

#include <stdio.h>

#include "types.h"

#include "cartridge.h"
#include "menu_c64_common_expansions.h"
#include "menu_common.h"
#include "uimenu.h"


/* DIGIMAX MENU */

UI_MENU_DEFINE_TOGGLE(DIGIMAX)
UI_MENU_DEFINE_RADIO(DIGIMAXbase)

const ui_menu_entry_t digimax_menu[] = {
    { "Enable " CARTRIDGE_NAME_DIGIMAX,
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_DIGIMAX_callback,
      NULL },
    SDL_MENU_ITEM_SEPARATOR,
    SDL_MENU_ITEM_TITLE("Base address"),
    { "Userport",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdd00 },
    { "$DE00",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xde00 },
    { "$DE20",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xde20 },
    { "$DE40",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xde40 },
    { "$DE60",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xde60 },
    { "$DE80",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xde80 },
    { "$DEA0",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdea0 },
    { "$DEC0",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdec0 },
    { "$DEE0",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdee0 },
    { "$DF00",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdf00 },
    { "$DF20",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdf20 },
    { "$DF40",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdf40 },
    { "$DF60",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdf60 },
    { "$DF80",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdf80 },
    { "$DFA0",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdfa0 },
    { "$DFC0",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdfc0 },
    { "$DFE0",
      MENU_ENTRY_RESOURCE_RADIO,
      radio_DIGIMAXbase_callback,
      (ui_callback_data_t)0xdfe0 },
    SDL_MENU_LIST_END
};


/* IDE64 CART MENU */

UI_MENU_DEFINE_TOGGLE(IDE64version4)
UI_MENU_DEFINE_FILE_STRING(IDE64Image1)
UI_MENU_DEFINE_FILE_STRING(IDE64Image2)
UI_MENU_DEFINE_FILE_STRING(IDE64Image3)
UI_MENU_DEFINE_FILE_STRING(IDE64Image4)
UI_MENU_DEFINE_TOGGLE(IDE64AutodetectSize1)
UI_MENU_DEFINE_TOGGLE(IDE64AutodetectSize2)
UI_MENU_DEFINE_TOGGLE(IDE64AutodetectSize3)
UI_MENU_DEFINE_TOGGLE(IDE64AutodetectSize4)
UI_MENU_DEFINE_INT(IDE64Cylinders1)
UI_MENU_DEFINE_INT(IDE64Cylinders2)
UI_MENU_DEFINE_INT(IDE64Cylinders3)
UI_MENU_DEFINE_INT(IDE64Cylinders4)
UI_MENU_DEFINE_INT(IDE64Heads1)
UI_MENU_DEFINE_INT(IDE64Heads2)
UI_MENU_DEFINE_INT(IDE64Heads3)
UI_MENU_DEFINE_INT(IDE64Heads4)
UI_MENU_DEFINE_INT(IDE64Sectors1)
UI_MENU_DEFINE_INT(IDE64Sectors2)
UI_MENU_DEFINE_INT(IDE64Sectors3)
UI_MENU_DEFINE_INT(IDE64Sectors4)

static const ui_menu_entry_t ide64_menu_HD_1[] = {
    SDL_MENU_ITEM_TITLE("HD image 1 settings"),
    { "HD1 image file",
      MENU_ENTRY_DIALOG,
      file_string_IDE64Image1_callback,
      (ui_callback_data_t)"Select HD1 image" },
    SDL_MENU_ITEM_SEPARATOR,
    SDL_MENU_ITEM_TITLE("HD 1 geometry"),
    { "Autodetect geometry",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_IDE64AutodetectSize1_callback,
      NULL },
    { "Cylinders",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Cylinders1_callback,
      (ui_callback_data_t)"Enter amount of cylinders (1-1024)" },
    { "Heads",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Heads1_callback,
      (ui_callback_data_t)"Enter amount of heads (1-16)" },
    { "Sectors",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Sectors1_callback,
      (ui_callback_data_t)"Enter amount of sectors (0-63)" },
    SDL_MENU_LIST_END
};

static const ui_menu_entry_t ide64_menu_HD_2[] = {
    SDL_MENU_ITEM_TITLE("HD image 2 settings"),
    { "HD1 image file",
      MENU_ENTRY_DIALOG,
      file_string_IDE64Image2_callback,
      (ui_callback_data_t)"Select HD2 image" },
    SDL_MENU_ITEM_SEPARATOR,
    SDL_MENU_ITEM_TITLE("HD 2 geometry"),
    { "Autodetect geometry",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_IDE64AutodetectSize2_callback,
      NULL },
    { "Cylinders",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Cylinders2_callback,
      (ui_callback_data_t)"Enter amount of cylinders (1-1024)" },
    { "Heads",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Heads2_callback,
      (ui_callback_data_t)"Enter amount of heads (1-16)" },
    { "Sectors",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Sectors2_callback,
      (ui_callback_data_t)"Enter amount of sectors (0-63)" },
    SDL_MENU_LIST_END
};

static const ui_menu_entry_t ide64_menu_HD_3[] = {
    SDL_MENU_ITEM_TITLE("HD image 3 settings"),
    { "HD1 image file",
      MENU_ENTRY_DIALOG,
      file_string_IDE64Image3_callback,
      (ui_callback_data_t)"Select HD3 image" },
    SDL_MENU_ITEM_SEPARATOR,
    SDL_MENU_ITEM_TITLE("HD 3 geometry"),
    { "Autodetect geometry",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_IDE64AutodetectSize3_callback,
      NULL },
    { "Cylinders",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Cylinders3_callback,
      (ui_callback_data_t)"Enter amount of cylinders (1-1024)" },
    { "Heads",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Heads3_callback,
      (ui_callback_data_t)"Enter amount of heads (1-16)" },
    { "Sectors",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Sectors3_callback,
      (ui_callback_data_t)"Enter amount of sectors (0-63)" },
    SDL_MENU_LIST_END
};

static const ui_menu_entry_t ide64_menu_HD_4[] = {
    SDL_MENU_ITEM_TITLE("HD image 4 settings"),
    { "HD1 image file",
      MENU_ENTRY_DIALOG,
      file_string_IDE64Image4_callback,
      (ui_callback_data_t)"Select HD4 image" },
    SDL_MENU_ITEM_SEPARATOR,
    SDL_MENU_ITEM_TITLE("HD 4 geometry"),
    { "Autodetect geometry",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_IDE64AutodetectSize4_callback,
      NULL },
    { "Cylinders",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Cylinders4_callback,
      (ui_callback_data_t)"Enter amount of cylinders (1-1024)" },
    { "Heads",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Heads4_callback,
      (ui_callback_data_t)"Enter amount of heads (1-16)" },
    { "Sectors",
      MENU_ENTRY_RESOURCE_INT,
      int_IDE64Sectors4_callback,
      (ui_callback_data_t)"Enter amount of sectors (0-63)" },
    SDL_MENU_LIST_END
};

const ui_menu_entry_t ide64_menu[] = {
    { "Cartridge version 4",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_IDE64version4_callback,
      NULL },
    SDL_MENU_ITEM_SEPARATOR,
    SDL_MENU_ITEM_TITLE("HD settings"),
    { "HD1 settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)ide64_menu_HD_1 },
    { "HD2 settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)ide64_menu_HD_2 },
    { "HD3 settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)ide64_menu_HD_3 },
    { "HD4 settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)ide64_menu_HD_4 },
    SDL_MENU_LIST_END
};

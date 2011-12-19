/*
 * menu_vic20hw.c - VIC-20 HW menu for SDL UI.
 *
 * Written by
 *  Hannu Nuotio <hannu.nuotio@tut.fi>
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

#include "menu_common.h"
#include "menu_joystick.h"

#ifdef HAVE_MOUSE
#include "menu_lightpen.h"
#endif

#ifdef HAVE_MIDI
#include "menu_midi.h"
#endif

#include "menu_ram.h"
#include "menu_rom.h"

#ifdef HAVE_RS232
#include "menu_rs232.h"
#endif

#include "menu_sid.h"

#ifdef HAVE_TFE
#include "menu_tfe.h"
#endif

#include "resources.h"
#include "uimenu.h"

enum {
    BLOCK_0 = 1,
    BLOCK_1 = 1 << 1,
    BLOCK_2 = 1 << 2,
    BLOCK_3 = 1 << 3,
    BLOCK_5 = 1 << 5
};

static UI_MENU_CALLBACK(custom_memory_callback)
{
    int blocks, value;

    if (activated) {
        blocks = vice_ptr_to_int(param);
        resources_set_int("RAMBlock0", blocks & BLOCK_0 ? 1 : 0);
        resources_set_int("RAMBlock1", blocks & BLOCK_1 ? 1 : 0);
        resources_set_int("RAMBlock2", blocks & BLOCK_2 ? 1 : 0);
        resources_set_int("RAMBlock3", blocks & BLOCK_3 ? 1 : 0);
        resources_set_int("RAMBlock5", blocks & BLOCK_5 ? 1 : 0);
    } else {
        resources_get_int("RAMBlock0", &value);
        blocks = value;
        resources_get_int("RAMBlock1", &value);
        blocks |= (value << 1);
        resources_get_int("RAMBlock2", &value);
        blocks |= (value << 2);
        resources_get_int("RAMBlock3", &value);
        blocks |= (value << 3);
        resources_get_int("RAMBlock5", &value);
        blocks |= (value << 5);

        if (blocks == vice_ptr_to_int(param)) {
            return sdl_menu_text_tick;
        }
    }
    return NULL;
}

static const ui_menu_entry_t vic20_memory_common_menu[] = {
    { "No expansion",
      MENU_ENTRY_RESOURCE_RADIO,
      custom_memory_callback,
      (ui_callback_data_t)0 },
    { "3kB",
      MENU_ENTRY_RESOURCE_RADIO,
      custom_memory_callback,
      (ui_callback_data_t)(BLOCK_0) },
    { "8kB",
      MENU_ENTRY_RESOURCE_RADIO,
      custom_memory_callback,
      (ui_callback_data_t)(BLOCK_1) },
    { "16kB",
      MENU_ENTRY_RESOURCE_RADIO,
      custom_memory_callback,
      (ui_callback_data_t)(BLOCK_1 | BLOCK_2) },
    { "24kB",
      MENU_ENTRY_RESOURCE_RADIO,
      custom_memory_callback,
      (ui_callback_data_t)(BLOCK_1 | BLOCK_2 | BLOCK_3) },
    { "All",
      MENU_ENTRY_RESOURCE_RADIO,
      custom_memory_callback,
      (ui_callback_data_t)(BLOCK_0 | BLOCK_1 | BLOCK_2 | BLOCK_3 | BLOCK_5) },
    SDL_MENU_LIST_END
};

UI_MENU_DEFINE_TOGGLE(Mouse)
UI_MENU_DEFINE_TOGGLE(RAMBlock0)
UI_MENU_DEFINE_TOGGLE(RAMBlock1)
UI_MENU_DEFINE_TOGGLE(RAMBlock2)
UI_MENU_DEFINE_TOGGLE(RAMBlock3)
UI_MENU_DEFINE_TOGGLE(RAMBlock5)
UI_MENU_DEFINE_TOGGLE(IEEE488)

const ui_menu_entry_t vic20_hardware_menu[] = {
    { "Joystick settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)joystick_vic20_menu },
    { "SID cart settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)sid_vic_menu },
    { "RAM pattern settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)ram_menu },
    { "ROM settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)c64_vic20_rom_menu },
    { "IEEE488 interface",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_IEEE488_callback,
      NULL },
#ifdef HAVE_RS232
    { "RS232 settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)rs232_vic20_menu },
#endif
#ifdef HAVE_MIDI
    { "MIDI settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)midi_vic20_menu },
#endif
#ifdef HAVE_TFE
    { CARTRIDGE_NAME_TFE " settings (MasC=uerade)",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)tfe_menu },
#endif
#ifdef HAVE_MOUSE
    { "Paddle emulation",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_Mouse_callback,
      NULL },
    { "Lightpen emulation",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)lightpen_menu },
#endif
    SDL_MENU_ITEM_SEPARATOR,
    SDL_MENU_ITEM_TITLE("Memory expansions"),
    { "Common configurations",
      MENU_ENTRY_SUBMENU,
      submenu_radio_callback,
      (ui_callback_data_t)vic20_memory_common_menu },
    { "Block 0 (3kB at $0400-$0FFF)",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_RAMBlock0_callback,
      NULL },
    { "Block 1 (8kB at $2000-$3FFF)",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_RAMBlock1_callback,
      NULL },
    { "Block 2 (8kB at $4000-$5FFF)",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_RAMBlock2_callback,
      NULL },
    { "Block 3 (8kB at $6000-$7FFF)",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_RAMBlock3_callback,
      NULL },
    { "Block 5 (8kB at $A000-$BFFF)",
      MENU_ENTRY_RESOURCE_TOGGLE,
      toggle_RAMBlock5_callback,
      NULL },
    SDL_MENU_LIST_END
};

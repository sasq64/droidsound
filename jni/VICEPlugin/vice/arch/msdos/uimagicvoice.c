/*
 * uimagicvoice.c - Magic Voice UI interface for MS-DOS.
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

#include "resources.h"
#include "tui.h"
#include "tuimenu.h"
#include "uimagicvoice.h"

TUI_MENU_DEFINE_TOGGLE(MagicVoiceCartridgeEnabled)
TUI_MENU_DEFINE_FILENAME(MagicVoiceImage, "Magic Voice ROM")

static tui_menu_item_def_t magicvoice_menu_items[] = {
    { "_Enable Magic Voice:", "Emulate Magic Voice cartridge",
      toggle_MagicVoiceCartridgeEnabled_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Magic Voice _ROM file:", "Select the Magic Voice ROM file",
      filename_MagicVoiceImage_callback, NULL, 20,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { NULL }
};

void uimagicvoice_init(struct tui_menu *parent_submenu)
{
    tui_menu_t ui_magicvoice_submenu;

    ui_magicvoice_submenu = tui_menu_create("Magic Voice settings", 1);

    tui_menu_add(ui_magicvoice_submenu, magicvoice_menu_items);

    tui_menu_add_submenu(parent_submenu, "Magic _Voice settings...",
                         "Magic Voice settings",
                         ui_magicvoice_submenu,
                         NULL, 0,
                         TUI_MENU_BEH_CONTINUE);
}

/*
 * uiide64.c - IDE64 UI interface for MS-DOS.
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
#include "uiide64.h"

TUI_MENU_DEFINE_TOGGLE(IDE64version4)
TUI_MENU_DEFINE_TOGGLE(IDE64AutodetectSize1)
TUI_MENU_DEFINE_TOGGLE(IDE64AutodetectSize2)
TUI_MENU_DEFINE_TOGGLE(IDE64AutodetectSize3)
TUI_MENU_DEFINE_TOGGLE(IDE64AutodetectSize4)
TUI_MENU_DEFINE_FILENAME(IDE64Image1, "IDE64 HD #1")
TUI_MENU_DEFINE_FILENAME(IDE64Image2, "IDE64 HD #2")
TUI_MENU_DEFINE_FILENAME(IDE64Image3, "IDE64 HD #3")
TUI_MENU_DEFINE_FILENAME(IDE64Image4, "IDE64 HD #4")

static TUI_MENU_CALLBACK(ui_set_cylinders_callback)
{
    int num = (int)param;

    if (been_activated) {
        int current_cyls, value;
        char buf[10];

        resources_get_int_sprintf("IDE64Cylinders%i", &current_cyls, num);
        sprintf(buf, "%d", current_cyls);

        if (tui_input_string("Cylinders", "Enter the amount of cylinders (1-1024):", buf, 10) == 0) {
            value = atoi(buf);
            if (value > 1024) {
                value = 1024;
            } else if (value < 1) {
                value = 1;
            }
            resources_set_int_sprintf("IDE64Cylinders%i", value, num);
        } else {
            return NULL;
        }
    }
    return NULL;
}

static TUI_MENU_CALLBACK(ui_set_heads_callback)
{
    int num = (int)param;

    if (been_activated) {
        int current_heads, value;
        char buf[10];

        resources_get_int_sprintf("IDE64Heads%i", &current_heads, num);
        sprintf(buf, "%d", current_heads);

        if (tui_input_string("Heads", "Enter the amount of heads (1-16):", buf, 10) == 0) {
            value = atoi(buf);
            if (value > 16) {
                value = 16;
            } else if (value < 1) {
                value = 1;
            }
            resources_set_int_sprintf("IDE64Heads", value, num);
        } else {
            return NULL;
        }
    }
    return NULL;
}

static TUI_MENU_CALLBACK(ui_set_sectors_callback)
{
    int num = (int)param;

    if (been_activated) {
        int current_sectors, value;
        char buf[10];

        resources_get_int_sprintf("IDE64Sectors", &current_sectors, num);
        sprintf(buf, "%d", current_sectors);

        if (tui_input_string("Sectors", "Enter the amount of sectors (1-63):", buf, 10) == 0) {
            value = atoi(buf);
            if (value > 63) {
                value = 63;
            } else if (value < 1) {
                value = 1;
            }
            resources_set_int_sprintf("IDE64Sectors", value, num);
        } else {
            return NULL;
        }
    }
    return NULL;
}

static tui_menu_item_def_t ide64_hd1_menu_items[] = {
    { "IDE64 HD #_1 image file:", "Select the IDE64 HD #1 image file",
      filename_IDE64Image1_callback, NULL, 20,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "_Autodetect geometry:", "Autodetect the geometry",
      toggle_IDE64AutodetectSize1_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Cylinders",
      "Set the amount of cylinders",
      ui_set_cylinders_callback, (void *)1, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Heads",
      "Set the amount of heads",
      ui_set_heads_callback, (void *)1, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Sectors",
      "Set the amount of sectors",
      ui_set_sectors_callback, (void *)1, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { NULL }
};

static tui_menu_item_def_t ide64_hd2_menu_items[] = {
    { "IDE64 HD #_2 image file:", "Select the IDE64 HD #2 image file",
      filename_IDE64Image2_callback, NULL, 20,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "_Autodetect geometry:", "Autodetect the geometry",
      toggle_IDE64AutodetectSize2_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Cylinders",
      "Set the amount of cylinders",
      ui_set_cylinders_callback, (void *)2, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Heads",
      "Set the amount of heads",
      ui_set_heads_callback, (void *)2, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Sectors",
      "Set the amount of sectors",
      ui_set_sectors_callback, (void *)2, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { NULL }
};

static tui_menu_item_def_t ide64_hd3_menu_items[] = {
    { "IDE64 HD #_3 image file:", "Select the IDE64 HD #3 image file",
      filename_IDE64Image3_callback, NULL, 20,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "_Autodetect geometry:", "Autodetect the geometry",
      toggle_IDE64AutodetectSize3_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Cylinders",
      "Set the amount of cylinders",
      ui_set_cylinders_callback, (void *)3, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Heads",
      "Set the amount of heads",
      ui_set_heads_callback, (void *)3, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Sectors",
      "Set the amount of sectors",
      ui_set_sectors_callback, (void *)3, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { NULL }
};

static tui_menu_item_def_t ide64_hd4_menu_items[] = {
    { "IDE64 HD #_4 image file:", "Select the IDE64 HD #4 image file",
      filename_IDE64Image4_callback, NULL, 20,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "_Autodetect geometry:", "Autodetect the geometry",
      toggle_IDE64AutodetectSize4_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Cylinders",
      "Set the amount of cylinders",
      ui_set_cylinders_callback, (void *)4, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Heads",
      "Set the amount of heads",
      ui_set_heads_callback, (void *)4, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Sectors",
      "Set the amount of sectors",
      ui_set_sectors_callback, (void *)4, 30,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { NULL }
};

static tui_menu_item_def_t ide64_menu_items[] = {
    { "_Enable IDE64 V4 support:", "Emulate IDE64 V4 model",
      toggle_IDE64version4_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "IDE64 HD 1 settings:", "HD 1 settings",
      NULL, NULL, 11,
      TUI_MENU_BEH_CONTINUE, ide64_hd1_menu_items,
      "HD 1 settings" },
    { "IDE64 HD 2 settings:", "HD 2 settings",
      NULL, NULL, 11,
      TUI_MENU_BEH_CONTINUE, ide64_hd2_menu_items,
      "HD 2 settings" },
    { "IDE64 HD 3 settings:", "HD 3 settings",
      NULL, NULL, 11,
      TUI_MENU_BEH_CONTINUE, ide64_hd3_menu_items,
      "HD 3 settings" },
    { "IDE64 HD 4 settings:", "HD 4 settings",
      NULL, NULL, 11,
      TUI_MENU_BEH_CONTINUE, ide64_hd4_menu_items,
      "HD 4 settings" },
    { NULL }
};

void uiide64_init(struct tui_menu *parent_submenu)
{
    tui_menu_t ui_ide64_submenu;

    ui_ide64_submenu = tui_menu_create("IDE64 settings", 1);

    tui_menu_add(ui_ide64_submenu, ide64_menu_items);

    tui_menu_add_submenu(parent_submenu, "_IDE64 settings...",
                         "IDE64 settings",
                         ui_ide64_submenu,
                         NULL, 0,
                         TUI_MENU_BEH_CONTINUE);
}

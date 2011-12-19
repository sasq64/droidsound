/*
 * uikeyboard.h - Keyboard settings dialog box.
 *
 * Written by
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

#ifndef VICE_UIKEYBOARD_H
#define VICE_UIKEYBOARD_H

#include "uilib.h"

struct uikeyboard_mapping_entry_s {
    int idc_select;
    int idc_filename;
    int idc_browse;
    const char *res_filename;
};
typedef struct uikeyboard_mapping_entry_s uikeyboard_mapping_entry_t;

struct uikeyboard_config_s {
    int idd_mapping;
    unsigned int num_mapping;
    const uikeyboard_mapping_entry_t *mapping_entry;
    int idc_dump;
    uilib_localize_dialog_param *kbd_dialog_trans;
    uilib_dialog_group *kbd_left_group;
    uilib_dialog_group *kbd_middle_group;
    uilib_dialog_group *kbd_right_group;
    uilib_dialog_group *kbd_buttons_group;
    int *kbd_move_buttons_group;
};
typedef struct uikeyboard_config_s uikeyboard_config_t;

extern void uikeyboard_settings_dialog(HWND hwnd, uikeyboard_config_t *uikeyboard_config);

extern HACCEL uikeyboard_create_accelerator_table(void);
extern void uikeyboard_menu_shortcuts(HMENU menu);
extern void uikeyboard_shutdown(void);

#endif


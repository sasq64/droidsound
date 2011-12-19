/*
 * uitpi.c
 *
 * Written by
 *  groepaz <groepaz@gmx.net>
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

#include "cartridge.h"
#include "ui.h"
#include "uiapi.h"
#include "uicartridge.h"
#include "uilib.h"
#include "uimenu.h"
#include "uitpi.h"
#include "uiromset.h"
#include "vsync.h"

UI_CALLBACK(set_tpi_image_name)
{
    uilib_select_file((char *)UI_MENU_CB_PARAM, _("IEEE488 Interface image"), UILIB_FILTER_ALL);
}

UI_MENU_DEFINE_TOGGLE(IEEE488)

ui_menu_entry_t tpi_submenu[] = {
    { N_("Enable"), UI_MENU_TYPE_TICK,
      (ui_callback_t)toggle_IEEE488, NULL, NULL },
    { "--", UI_MENU_TYPE_SEPARATOR },
    { N_("Image name"), UI_MENU_TYPE_DOTS,
      (ui_callback_t)set_tpi_image_name,
      (ui_callback_data_t)"IEEE488Image", NULL },
    { NULL }
};

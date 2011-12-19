/*
 * uirs232petplus4cbm2.c
 *
 * Written by
 *  Andreas Boose <viceteam@t-online.de>
 *  Andr� Fachat <a.fachat@physik.tu-chemnitz.de>
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

#include "uiacia1.h"
#include "uimenu.h"
#include "uirs232.h"
#include "uirs232petplus4cbm2.h"

ui_menu_entry_t uirs232petplus4cbm2_submenu[] = {
    { N_("ACIA device"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, uiacia1_device_submenu },
    { "--", UI_MENU_TYPE_SEPARATOR },
    { N_("Serial 1 device"), UI_MENU_TYPE_DOTS, (ui_callback_t)set_rs232_device_file,
      (ui_callback_data_t)"RsDevice1", NULL },
    { N_("Serial 1 baudrate"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, ser1_baud_submenu },
    { "--", UI_MENU_TYPE_SEPARATOR },
    { N_("Serial 2 device"), UI_MENU_TYPE_DOTS, (ui_callback_t)set_rs232_device_file,
      (ui_callback_data_t)"RsDevice2", NULL },
    { N_("Serial 2 baudrate"), UI_MENU_TYPE_NORMAL,
      NULL, NULL, ser2_baud_submenu },
    { "--", UI_MENU_TYPE_SEPARATOR },
    { N_("Dump filename"), UI_MENU_TYPE_DOTS, (ui_callback_t)set_rs232_dump_file,
      (ui_callback_data_t)"RsDevice3", NULL },
    { "--", UI_MENU_TYPE_SEPARATOR },
    { N_("Program name to exec"), UI_MENU_TYPE_DOTS, (ui_callback_t)set_rs232_exec_file,
      (ui_callback_data_t)"RsDevice4", NULL },
    { NULL }
};

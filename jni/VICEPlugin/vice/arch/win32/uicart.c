/*
 * uicart.c
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

#include "vice.h"

#include <windows.h>
#include <tchar.h>

#include "cartridge.h"
#include "intl.h"
#include "lib.h"
#include "res.h"
#include "system.h"
#include "translate.h"
#include "uiapi.h"
#include "uicart.h"
#include "uilib.h"

void uicart_attach(WPARAM wparam, HWND hwnd, const uicart_params_t *cartridges)
{
    int i;
    TCHAR *st_name;

    i = 0;

    while ((cartridges[i].wparam != wparam) && (cartridges[i].wparam != 0)) {
        i++;
    }

    if (cartridges[i].wparam == 0) {
        ui_error(translate_text(IDS_BAD_CARTRIDGE_CONFIG));
        return;
    }

    if ((st_name = uilib_select_file(hwnd, translate_text(cartridges[i].title), cartridges[i].filter, UILIB_SELECTOR_TYPE_FILE_LOAD, UILIB_SELECTOR_STYLE_CART)) != NULL) {
        char *name;

        name = system_wcstombs_alloc(st_name);
        if (cartridge_attach_image(cartridges[i].type, name) < 0) {
            ui_error(translate_text(IDS_INVALID_CARTRIDGE_IMAGE));
        }
        system_wcstombs_free(name);
        lib_free(st_name);
    }
}

void uicart_attach_special(HWND hwnd, const TCHAR *title, DWORD filterlist, unsigned int type)
{
    TCHAR *st_name = NULL;
    char *name;

    st_name = uilib_select_file(hwnd, title, filterlist, UILIB_SELECTOR_TYPE_FILE_LOAD, UILIB_SELECTOR_STYLE_DEFAULT);
    if (st_name != NULL) {
        name = system_wcstombs_alloc(st_name);
        if (cartridge_attach_image(type, name) < 0) {
            ui_error(translate_text(IDS_INVALID_CARTRIDGE_IMAGE));
        }
        system_wcstombs_free(name);
        lib_free(st_name);
    }
}

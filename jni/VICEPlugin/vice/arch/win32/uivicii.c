/*
 * uivicii.c - Implementation of VIC-II settings dialog box.
 *
 * Written by
 *  Andreas Boose <viceteam@t-online.de>
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  Tibor Biczo <crown@mail.matav.hu>
 *  Gunnar Ruthenberg <Krill.Plush@gmail.com>
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

#include "res.h"
#include "resources.h"
#include "system.h"
#include "translate.h"
#include "uilib.h"
#include "vicii.h"
#include "winmain.h"

static uilib_localize_dialog_param vicii_dialog[] = {
    { 0, IDS_VICII_CAPTION, -1 },
    { IDC_VICII_BORDERSGROUP, IDS_VICII_BORDERSGROUP, 0 },
    { IDC_TOGGLE_VICII_NORMALBORDERS, IDS_VICII_NORMALBORDERS, 0 },
    { IDC_TOGGLE_VICII_FULLBORDERS, IDS_VICII_FULLBORDERS, 0 },
    { IDC_TOGGLE_VICII_DEBUGBORDERS, IDS_VICII_DEBUGBORDERS, 0 },
    { IDC_VICII_SPRITEGROUP, IDS_VICII_SPRITEGROUP, 0 },
    { IDC_TOGGLE_VICII_SSC, IDS_VICII_SPRITECOLL, 0 },
    { IDC_TOGGLE_VICII_SBC, IDS_VICII_BACKCOLL, 0 },
    { IDC_TOGGLE_VICII_NEWLUM, IDS_VICII_LUMINANCE, 0 },
    { IDOK, IDS_OK, 0 },
    { IDCANCEL, IDS_CANCEL, 0 },
    { 0, 0, 0 }
};

static void init_vicii_dialog(HWND hwnd)
{
    int n;

    uilib_localize_dialog(hwnd, vicii_dialog);

    resources_get_int("VICIIBorderMode", &n);
    switch (n) {
        default:
        case VICII_NORMAL_BORDERS:
            n = IDC_TOGGLE_VICII_NORMALBORDERS;
            break;
        case VICII_FULL_BORDERS:
            n = IDC_TOGGLE_VICII_FULLBORDERS;
            break;
        case VICII_DEBUG_BORDERS:
            n = IDC_TOGGLE_VICII_DEBUGBORDERS;
            break;
    }
    CheckRadioButton(hwnd, IDC_TOGGLE_VICII_NORMALBORDERS, IDC_TOGGLE_VICII_DEBUGBORDERS, n);

    resources_get_int("VICIICheckSsColl", &n);
    CheckDlgButton(hwnd, IDC_TOGGLE_VICII_SSC, n ? BST_CHECKED : BST_UNCHECKED);

    resources_get_int("VICIICheckSbColl", &n);
    CheckDlgButton(hwnd, IDC_TOGGLE_VICII_SBC, n ? BST_CHECKED : BST_UNCHECKED);

    resources_get_int("VICIINewLuminances", &n);
    CheckDlgButton(hwnd, IDC_TOGGLE_VICII_NEWLUM, n ? BST_CHECKED : BST_UNCHECKED);
}

static void end_vicii_dialog(HWND hwnd)
{
    resources_set_int("VICIIBorderMode", (IsDlgButtonChecked(hwnd, IDC_TOGGLE_VICII_DEBUGBORDERS) == BST_CHECKED ? VICII_DEBUG_BORDERS : 
                      IsDlgButtonChecked(hwnd, IDC_TOGGLE_VICII_FULLBORDERS) == BST_CHECKED ? VICII_FULL_BORDERS : VICII_NORMAL_BORDERS));

    resources_set_int("VICIICheckSsColl", (IsDlgButtonChecked(hwnd, IDC_TOGGLE_VICII_SSC) == BST_CHECKED ? 1 : 0 ));

    resources_set_int("VICIICheckSbColl", (IsDlgButtonChecked(hwnd, IDC_TOGGLE_VICII_SBC) == BST_CHECKED ? 1 : 0 ));

    resources_set_int("VICIINewLuminances", (IsDlgButtonChecked(hwnd, IDC_TOGGLE_VICII_NEWLUM) == BST_CHECKED ? 1 : 0 ));
}

static INT_PTR CALLBACK dialog_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int type;

    switch (msg) {
        case WM_CLOSE:
            EndDialog(hwnd, 0);
            return TRUE;
        case WM_INITDIALOG:
            init_vicii_dialog(hwnd);
            return TRUE;
        case WM_COMMAND:
            type = LOWORD(wparam);
            switch (type) {
                case IDC_TOGGLE_VICII_NORMALBORDERS:
                    break;
                case IDC_TOGGLE_VICII_FULLBORDERS:
                    break;
                case IDC_TOGGLE_VICII_DEBUGBORDERS:
                    break;
                case IDC_TOGGLE_VICII_SSC:
                    break;
                case IDC_TOGGLE_VICII_SBC:
                    break;
                case IDC_TOGGLE_VICII_NEWLUM:
                    break;
                case IDOK:
                    end_vicii_dialog(hwnd);
                case IDCANCEL:
                    EndDialog(hwnd, 0);
                    return TRUE;
            }
            return TRUE;
    }
    return FALSE;
}

void ui_vicii_settings_dialog(HWND hwnd)
{
    DialogBox(winmain_instance, MAKEINTRESOURCE(IDD_VICII_DIALOG), hwnd, dialog_proc);
}

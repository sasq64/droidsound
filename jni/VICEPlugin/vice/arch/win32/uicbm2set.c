/*
 * uicbm2set.c - Implementation of CBM2 settings dialog box.
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

#include <stdio.h>
#include <windows.h>
#include <prsht.h>

#include "cbm2mem.h"
#include "intl.h"
#include "res.h"
#include "resources.h"
#include "system.h"
#include "translate.h"
#include "ui.h"
#include "uicbm2set.h"
#include "uilib.h"
#include "winmain.h"

static uilib_localize_dialog_param cbm2_dialog_trans[] = {
    { IDC_MACHINE_DEFAULTS, IDS_MACHINE_DEFAULTS, 0 },
    { IDC_MODEL_LINE, IDS_MODEL_LINE, 0 },
    { 0, 0, 0 }
};

static uilib_localize_dialog_param ok_cancel_trans[] = {
    { IDOK, IDS_OK, 0 },
    { IDCANCEL, IDS_CANCEL, 0 },
    { 0, 0, 0 }
};

static uilib_dialog_group cbm2_main_group[] = {
    { IDC_MACHINE_DEFAULTS, 1 },
    { IDC_MODEL_LINE, 1 },
    { 0, 0 }
};

static uilib_dialog_group cbm2_left_group[] = {
    { IDC_MACHINE_DEFAULTS, 0 },
    { IDC_SELECT_CBMII_610, 0 },
    { IDC_SELECT_CBMII_620, 0 },
    { IDC_SELECT_CBMII_620P, 0 },
    { IDC_SELECT_CBMII_710, 0 },
    { IDC_SELECT_CBMII_720, 0 },
    { IDC_SELECT_CBMII_720P, 0 },
    { 0, 0 }
};

static uilib_dialog_group cbm2_move_right_group[] = {
    { IDC_SELECT_CBMII_HW0, 0 },
    { IDC_SELECT_CBMII_HW1, 0 },
    { IDC_SELECT_CBMII_HW2, 0 },
    { 0, 0 }
};

static uilib_dialog_group cbm2_right_group[] = {
    { IDC_MODEL_LINE, 0 },
    { IDC_SELECT_CBMII_HW0, 0 },
    { IDC_SELECT_CBMII_HW1, 0 },
    { IDC_SELECT_CBMII_HW2, 0 },
    { 0, 0 }
};

static generic_trans_table_t generic_items[] = {
    { IDC_SELECT_CBMII_610, "CBM 610" },
    { IDC_SELECT_CBMII_620, "CBM 620" },
    { IDC_SELECT_CBMII_620P, "CBM 620+" },
    { IDC_SELECT_CBMII_710, "CBM 710" },
    { IDC_SELECT_CBMII_720, "CBM 720" },
    { IDC_SELECT_CBMII_720P, "CBM 720+" },
    { IDC_SELECT_CBMII_HW0, "&7x0 (50 Hz)" },
    { IDC_SELECT_CBMII_HW1, "6x0 &60 Hz" },
    { IDC_SELECT_CBMII_HW2, "6x0 &50 Hz" },
    { 0, NULL }
};

static void init_dialog(HWND hwnd)
{
    int n, res;
    int xpos;
    int xstart;
    HWND parent_hwnd;
    HWND element;

    parent_hwnd = GetParent(hwnd);

    /* translate all dialog items */
    uilib_localize_dialog(hwnd, cbm2_dialog_trans);

    /* translate all generic items */
    for (n = 0; generic_items[n].text != NULL; n++) {
        element = GetDlgItem(hwnd, generic_items[n].idm);
        SetWindowText(element, generic_items[n].text);
    }

    /* translate ok and cancel */
    uilib_localize_dialog(parent_hwnd, ok_cancel_trans);

    /* adjust the size of the elements in the main group */
    uilib_adjust_group_width(hwnd, cbm2_main_group);

    /* get the min x of the 610 button */
    uilib_get_element_min_x(hwnd, IDC_SELECT_CBMII_610, &xstart);

    /* get the max x of the left group */
    uilib_get_group_max_x(hwnd, cbm2_left_group, &xpos);

    /* move and resize the left group element */
    uilib_move_and_set_element_width(hwnd, IDC_MACHINE_DEFAULTS, xstart - 10, xpos - xstart + 20);

    /* get the max x of the left group element */
    uilib_get_element_max_x(hwnd, IDC_MACHINE_DEFAULTS, &xpos);

    /* move the right group element */
    uilib_move_element(hwnd, IDC_MODEL_LINE, xpos + 10);

    /* move the right group elements */
    uilib_move_group(hwnd, cbm2_move_right_group, xpos + 20);

    xstart = xpos + 20;

    /* get the max x of the right group */
    uilib_get_group_max_x(hwnd, cbm2_right_group, &xpos);

    /* move and resize the right group element */
    uilib_move_and_set_element_width(hwnd, IDC_MODEL_LINE, xstart - 10, xpos - xstart + 20);

    resources_get_int("ModelLine", &res);
    switch (res) {
        case 0:
            n = IDC_SELECT_CBMII_HW0;
            break;
        case 1:
            n = IDC_SELECT_CBMII_HW1;
            break;
        case 2:
            n = IDC_SELECT_CBMII_HW2;
            break;
    }
    CheckRadioButton(hwnd, IDC_SELECT_CBMII_HW0, IDC_SELECT_CBMII_HW2, n);
}

static uilib_localize_dialog_param cbm2_memory_dialog_trans[] = {
    { IDC_CBM2_MEMORY, IDS_A_MEMORY, 0 },
    { IDC_SELECT_CBMII_MEM_128, IDS_SELECT_CBMII_MEM_128, 0 },
    { IDC_SELECT_CBMII_MEM_256, IDS_SELECT_CBMII_MEM_256, 0 },
    { IDC_SELECT_CBMII_MEM_512, IDS_SELECT_CBMII_MEM_512, 0 },
    { IDC_SELECT_CBMII_MEM_1024, IDS_SELECT_CBMII_MEM_1024, 0 },
    { IDC_RAM_BANKS, IDS_CBM2_RAM_BANKS, 0 },
    { IDC_TOGGLE_CBMII_RAM08, IDS_TOGGLE_CBMII_RAM08, 0 },
    { IDC_TOGGLE_CBMII_RAM1, IDS_TOGGLE_CBMII_RAM1, 0 },
    { IDC_TOGGLE_CBMII_RAM2, IDS_TOGGLE_CBMII_RAM2, 0 },
    { IDC_TOGGLE_CBMII_RAM4, IDS_TOGGLE_CBMII_RAM4, 0 },
    { IDC_TOGGLE_CBMII_RAM6, IDS_TOGGLE_CBMII_RAM6, 0 },
    { IDC_TOGGLE_CBMII_RAMC, IDS_TOGGLE_CBMII_RAMC, 0 },
    { 0, 0, 0 }
};

static uilib_dialog_group cbm2_memory_main_group[] = {
    { IDC_CBM2_MEMORY, 1 },
    { IDC_RAM_BANKS, 1 },
    { 0, 0 }
};

static uilib_dialog_group cbm2_memory_left_group[] = {
    { IDC_CBM2_MEMORY, 0 },
    { IDC_SELECT_CBMII_MEM_128, 0 },
    { IDC_SELECT_CBMII_MEM_256, 0 },
    { IDC_SELECT_CBMII_MEM_512, 0 },
    { IDC_SELECT_CBMII_MEM_1024, 0 },
    { 0, 0 }
};

static uilib_dialog_group cbm2_memory_move_right_group[] = {
    { IDC_TOGGLE_CBMII_RAM08, 0 },
    { IDC_TOGGLE_CBMII_RAM1, 0 },
    { IDC_TOGGLE_CBMII_RAM2, 0 },
    { IDC_TOGGLE_CBMII_RAM4, 0 },
    { IDC_TOGGLE_CBMII_RAM6, 0 },
    { IDC_TOGGLE_CBMII_RAMC, 0 },
    { 0, 0 }
};

static uilib_dialog_group cbm2_memory_right_group[] = {
    { IDC_RAM_BANKS, 0 },
    { IDC_TOGGLE_CBMII_RAM08, 0 },
    { IDC_TOGGLE_CBMII_RAM1, 0 },
    { IDC_TOGGLE_CBMII_RAM2, 0 },
    { IDC_TOGGLE_CBMII_RAM4, 0 },
    { IDC_TOGGLE_CBMII_RAM6, 0 },
    { IDC_TOGGLE_CBMII_RAMC, 0 },
    { 0, 0 }
};

static void init_memory_dialog(HWND hwnd)
{
    int n, res;
    int xpos;
    int xstart;
    HWND parent_hwnd;

    parent_hwnd = GetParent(hwnd);

    /* translate all dialog items */
    uilib_localize_dialog(hwnd, cbm2_memory_dialog_trans);

    /* translate ok and cancel */
    uilib_localize_dialog(parent_hwnd, ok_cancel_trans);

    /* adjust the size of the elements in the main group */
    uilib_adjust_group_width(hwnd, cbm2_memory_main_group);

    /* get the min x of the 128K ram element */
    uilib_get_element_min_x(hwnd, IDC_SELECT_CBMII_MEM_128, &xstart);

    /* get the max x of the left group */
    uilib_get_group_max_x(hwnd, cbm2_memory_left_group, &xpos);

    /* move and resize the left group element */
    uilib_move_and_set_element_width(hwnd, IDC_CBM2_MEMORY, xstart - 10, xpos - xstart + 20);

    /* get the max x of the left group element */
    uilib_get_element_max_x(hwnd, IDC_CBM2_MEMORY, &xpos);

    /* move the right group element */
    uilib_move_element(hwnd, IDC_RAM_BANKS, xpos + 10);

    /* move the right group elements */
    uilib_move_group(hwnd, cbm2_memory_move_right_group, xpos + 20);

    xstart = xpos + 20;

    /* get the max x of the right group */
    uilib_get_group_max_x(hwnd, cbm2_memory_right_group, &xpos);

    /* move and resize the right group element */
    uilib_move_and_set_element_width(hwnd, IDC_RAM_BANKS, xstart - 10, xpos - xstart + 20);

    resources_get_int("Ram08", &n);
    CheckDlgButton(hwnd, IDC_TOGGLE_CBMII_RAM08, n ? BST_CHECKED : BST_UNCHECKED);
    resources_get_int("Ram1", &n);
    CheckDlgButton(hwnd, IDC_TOGGLE_CBMII_RAM1, n ? BST_CHECKED : BST_UNCHECKED);
    resources_get_int("Ram2", &n);
    CheckDlgButton(hwnd, IDC_TOGGLE_CBMII_RAM2, n ? BST_CHECKED : BST_UNCHECKED);
    resources_get_int("Ram4", &n);
    CheckDlgButton(hwnd, IDC_TOGGLE_CBMII_RAM4, n ? BST_CHECKED : BST_UNCHECKED);
    resources_get_int("Ram6", &n);
    CheckDlgButton(hwnd, IDC_TOGGLE_CBMII_RAM6, n ? BST_CHECKED : BST_UNCHECKED);
    resources_get_int("RamC", &n);
    CheckDlgButton(hwnd, IDC_TOGGLE_CBMII_RAMC, n ? BST_CHECKED : BST_UNCHECKED);

    resources_get_int("RamSize", &res);
    switch (res) {
        case 128:
            n = IDC_SELECT_CBMII_MEM_128;
            break;
        case 256:
            n = IDC_SELECT_CBMII_MEM_256;
            break;
        case 512:
            n = IDC_SELECT_CBMII_MEM_512;
            break;
        case 1024:
            n = IDC_SELECT_CBMII_MEM_1024;
            break;
    }
    CheckRadioButton(hwnd, IDC_SELECT_CBMII_MEM_128, IDC_SELECT_CBMII_MEM_1024, n);
}

static INT_PTR CALLBACK dialog_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int type;

    switch (msg) {
        case WM_INITDIALOG:
            init_dialog(hwnd);
            return TRUE;
        case WM_COMMAND:
            type = LOWORD(wparam);
            switch (type) {
                case IDC_SELECT_CBMII_610:
                    cbm2_set_model("610", NULL);
                    break;
                case IDC_SELECT_CBMII_620:
                    cbm2_set_model("620", NULL);
                    break;
                case IDC_SELECT_CBMII_620P:
                    cbm2_set_model("620+", NULL);
                    break;
                case IDC_SELECT_CBMII_710:
                    cbm2_set_model("710", NULL);
                    break;
                case IDC_SELECT_CBMII_720:
                    cbm2_set_model("720", NULL);
                    break;
                case IDC_SELECT_CBMII_720P:
                    cbm2_set_model("720+", NULL);
                    break;

                case IDC_SELECT_CBMII_HW0:
                    resources_set_int("ModelLine", 0);
                    break;
                case IDC_SELECT_CBMII_HW1:
                    resources_set_int("ModelLine", 1);
                    break;
                case IDC_SELECT_CBMII_HW2:
                    resources_set_int("ModelLine", 2);
                    break;
            }
            return TRUE;
    }
    return FALSE;
}

static INT_PTR CALLBACK memory_dialog_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int type;

    switch (msg) {
        case WM_INITDIALOG:
            init_memory_dialog(hwnd);
            return TRUE;
        case WM_COMMAND:
            type = LOWORD(wparam);
            switch (type) {
                case IDC_SELECT_CBMII_MEM_128:
                    resources_set_int("RamSize", 128);
                    break;
                case IDC_SELECT_CBMII_MEM_256:
                    resources_set_int("RamSize", 256);
                    break;
                case IDC_SELECT_CBMII_MEM_512:
                    resources_set_int("RamSize", 512);
                    break;
                case IDC_SELECT_CBMII_MEM_1024:
                    resources_set_int("RamSize", 1024);
                    break;
                case IDC_TOGGLE_CBMII_RAM08:
                    resources_toggle("Ram08", NULL);
                    break;
                case IDC_TOGGLE_CBMII_RAM1:
                    resources_toggle("Ram1", NULL);
                    break;
                case IDC_TOGGLE_CBMII_RAM2:
                    resources_toggle("Ram2", NULL);
                    break;
                case IDC_TOGGLE_CBMII_RAM4:
                    resources_toggle("Ram4", NULL);
                    break;
                case IDC_TOGGLE_CBMII_RAM6:
                    resources_toggle("Ram6", NULL);
                    break;
                case IDC_TOGGLE_CBMII_RAMC:
                    resources_toggle("RamC", NULL);
                    break;
            }
            return TRUE;
    }
    return FALSE;
}

void ui_cbm2_settings_dialog(HWND hwnd)
{
    PROPSHEETPAGE psp[4];
    PROPSHEETHEADER psh;
    int i;

    for (i = 0; i < 2; i++) {
        psp[i].dwSize = sizeof(PROPSHEETPAGE);
        psp[i].dwFlags = PSP_USETITLE /*| PSP_HASHELP*/ ;
        psp[i].hInstance = winmain_instance;
#ifdef _ANONYMOUS_UNION
        psp[i].pszIcon = NULL;
#else
        psp[i].u2.pszIcon = NULL;
#endif
        psp[i].lParam = 0;
        psp[i].pfnCallback = NULL;
    }

    psp[0].pfnDlgProc = dialog_proc;
    psp[0].pszTitle = translate_text(IDS_MODEL);
    psp[1].pfnDlgProc = memory_dialog_proc;
    psp[1].pszTitle = translate_text(IDS_MEMORY);

#ifdef _ANONYMOUS_UNION
    psp[0].pszTemplate = MAKEINTRESOURCE(IDD_CBMII_SETTINGS_MODEL_DIALOG);
    psp[1].pszTemplate = MAKEINTRESOURCE(IDD_CBMII_SETTINGS_IO_DIALOG);
#else
    psp[0].DUMMYUNIONNAME.pszTemplate = MAKEINTRESOURCE(IDD_CBMII_SETTINGS_MODEL_DIALOG);
    psp[1].DUMMYUNIONNAME.pszTemplate = MAKEINTRESOURCE(IDD_CBMII_SETTINGS_IO_DIALOG);
#endif

    psh.dwSize = sizeof(PROPSHEETHEADER);
    psh.dwFlags = PSH_PROPSHEETPAGE | PSH_NOAPPLYNOW;
    psh.hwndParent = hwnd;
    psh.hInstance = winmain_instance;
    psh.pszCaption = translate_text(IDS_CBM2_SETTINGS);
    psh.nPages = 2;
#ifdef _ANONYMOUS_UNION
    psh.pszIcon = NULL;
    psh.nStartPage = 0;
    psh.ppsp = psp;
#else
    psh.DUMMYUNIONNAME.pszIcon = NULL;
    psh.u2.nStartPage = 0;
    psh.u3.ppsp = psp;
#endif
    psh.pfnCallback = NULL;

    system_psh_settings(&psh);
    PropertySheet(&psh);
}

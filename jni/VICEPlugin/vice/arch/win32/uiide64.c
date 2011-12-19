/*
 * uiide64.c - Implementation of the IDE64 settings dialog box.
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
#include <string.h>
#include <tchar.h>
#include <windows.h>
#include <prsht.h>

#include "intl.h"
#include "lib.h"
#include "res.h"
#include "resources.h"
#include "system.h"
#include "translate.h"
#include "types.h"
#include "ui.h"
#include "uiide64.h"
#include "uilib.h"
#include "winmain.h"

static void enable_ide64_controls(HWND hwnd)
{
    int is_enabled;

    is_enabled = (IsDlgButtonChecked(hwnd, IDC_TOGGLE_IDE64_SIZEAUTODETECT) == BST_CHECKED) ? 1 : 0;

    EnableWindow(GetDlgItem(hwnd, IDC_IDE64_CYLINDERS), !is_enabled);
    EnableWindow(GetDlgItem(hwnd, IDC_IDE64_HEADS), !is_enabled);
    EnableWindow(GetDlgItem(hwnd, IDC_IDE64_SECTORS), !is_enabled);
}

static void update_text(HWND hwnd)
{
    char *str;
    TCHAR *st;
    HWND ide64_hwnd;
    int cylinders_idx, heads_idx, sectors_idx, total;

    ide64_hwnd = GetDlgItem(hwnd, IDC_IDE64_CYLINDERS);
    cylinders_idx = (int)SendMessage(ide64_hwnd, CB_GETCURSEL, 0, 0);

    ide64_hwnd = GetDlgItem(hwnd, IDC_IDE64_HEADS);
    heads_idx = (int)SendMessage(ide64_hwnd, CB_GETCURSEL, 0, 0);

    ide64_hwnd = GetDlgItem(hwnd, IDC_IDE64_SECTORS);
    sectors_idx = (int)SendMessage(ide64_hwnd, CB_GETCURSEL, 0, 0);

    total = (cylinders_idx + 1) * (heads_idx + 1) * (sectors_idx + 1) / 2;

    str = lib_msprintf(translate_text(IDS_IDE64_TOTAL_SIZE), total);
    st = system_mbstowcs_alloc(str);
    SetDlgItemText(hwnd, IDC_IDE64_SIZE, st);
    system_mbstowcs_free(st);
    lib_free(str);
}

static uilib_localize_dialog_param ide64_v4_dialog[] = {
    { IDC_IDE64_V4, IDS_IDE64_V4, 0 },
    { 0, 0, 0 }
};

static uilib_localize_dialog_param ide64_dialog[] = {
    { IDC_IDE64_FILE_LABEL, IDS_IDE64_IMAGE, 0 },
    { IDC_IDE64_HDIMAGE_BROWSE, IDS_BROWSE, 0 },
    { IDC_IDE64_GEOMETRY, IDS_IDE64_GEOMETRY, 0 },
    { IDC_TOGGLE_IDE64_SIZEAUTODETECT, IDS_IDE64_AUTODETECT, 0 },
    { IDC_IDE64_CYLINDERS_LABEL, IDS_IDE64_CYLINDERS, 0 },
    { IDC_IDE64_HEADS_LABEL, IDS_IDE64_HEADS, 0 },
    { IDC_IDE64_SECTORS_LABEL, IDS_IDE64_SECTORS, 0 },
    { 0, 0, 0 }
};

static uilib_localize_dialog_param parent_dialog_trans[] = {
    { IDOK, IDS_OK, 0 },
    { IDCANCEL, IDS_CANCEL, 0 },
    { 0, 0, 0 }
};

static uilib_dialog_group ide64_leftgroup[] = {
    { IDC_IDE64_FILE_LABEL, 0 },
    { 0, 0 }
};

static uilib_dialog_group ide64_rightgroup[] = {
    { IDC_IDE64_HDIMAGE_BROWSE, 0 },
    { 0, 0 }
};

static int move_buttons_group[] = {
    IDOK,
    IDCANCEL,
    0
};

static void init_ide64_v4_dialog(HWND hwnd)
{
    int res_value;

    uilib_localize_dialog(hwnd, ide64_v4_dialog);

    resources_get_int("IDE64version4", &res_value);
    CheckDlgButton(hwnd, IDC_IDE64_V4, res_value ? BST_CHECKED : BST_UNCHECKED);
}

static void init_ide64_dialog(HWND hwnd, int num)
{
    int res_value, index;
    const char *ide64file;
    TCHAR *st_ide64file;
    TCHAR memb[20];
    HWND ide64_hwnd;
    HWND parent_hwnd;
    int xsize, ysize;
    char tmp[256];

    parent_hwnd = GetParent(hwnd);

    uilib_localize_dialog(hwnd, ide64_dialog);

    /* translate the parent window items */
    uilib_localize_dialog(parent_hwnd, parent_dialog_trans);

    uilib_get_group_extent(hwnd, ide64_leftgroup, &xsize, &ysize);
    uilib_adjust_group_width(hwnd, ide64_leftgroup);
    uilib_move_group(hwnd, ide64_rightgroup, xsize + 30);

    /* recenter the buttons in the newly resized dialog window */
    uilib_center_buttons(parent_hwnd, move_buttons_group, 0);

    sprintf(tmp, "IDE64Image%d", num);
    resources_get_string(tmp, &ide64file);
    st_ide64file = system_mbstowcs_alloc(ide64file);
    SetDlgItemText(hwnd, IDC_IDE64_HDIMAGE_FILE, st_ide64file != NULL ? st_ide64file : TEXT(""));
    system_mbstowcs_free(st_ide64file);

    resources_get_int_sprintf("IDE64AutodetectSize%i", &res_value, num);
    CheckDlgButton(hwnd, IDC_TOGGLE_IDE64_SIZEAUTODETECT, res_value ? BST_CHECKED : BST_UNCHECKED);

    ide64_hwnd = GetDlgItem(hwnd, IDC_IDE64_CYLINDERS);
    for (index = 1; index <= 1024; index++) {
        _stprintf(memb, TEXT("%d"), index);
        SendMessage(ide64_hwnd, CB_ADDSTRING, 0, (LPARAM)memb);
    }
    resources_get_int_sprintf("IDE64Cylinders%i", &res_value, num);
    SendMessage(ide64_hwnd, CB_SETCURSEL, (WPARAM)(res_value - 1), 0);

    ide64_hwnd = GetDlgItem(hwnd, IDC_IDE64_HEADS);
    for (index = 1; index <= 16; index++) {
        _stprintf(memb, TEXT("%d"), index);
        SendMessage(ide64_hwnd, CB_ADDSTRING, 0, (LPARAM)memb);
    }
    resources_get_int_sprintf("IDE64Heads%i", &res_value, num);
    SendMessage(ide64_hwnd, CB_SETCURSEL, (WPARAM)(res_value - 1), 0);

    ide64_hwnd = GetDlgItem(hwnd, IDC_IDE64_SECTORS);
    for (index = 1; index <= 63; index++) {
        _stprintf(memb, TEXT("%d"), index);
        SendMessage(ide64_hwnd, CB_ADDSTRING, 0, (LPARAM)memb);
    }
    resources_get_int_sprintf("IDE64Sectors%i", &res_value, num);
    SendMessage(ide64_hwnd, CB_SETCURSEL, (WPARAM)res_value, 0);

    update_text(hwnd);
    enable_ide64_controls(hwnd);
}

static INT_PTR CALLBACK dialog_v4_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int command;

    switch (msg) {
        case WM_INITDIALOG:
            init_ide64_v4_dialog(hwnd);
            return TRUE;
        case WM_COMMAND:
            command = LOWORD(wparam);
            switch (command) {
                case IDC_IDE64_V4:
                    resources_set_int("IDE64version4", (IsDlgButtonChecked(hwnd, IDC_IDE64_V4) == BST_CHECKED ? 1 : 0));
                    break;
            }
            return TRUE;
    }
    return FALSE;
}

static INT_PTR CALLBACK dialog_proc(int num, HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int command;
    char tmp[256];
    char s[MAX_PATH];
    TCHAR st[MAX_PATH];
    HWND ide64_hwnd;
    int res_value;

    switch (msg) {
        case WM_INITDIALOG:
            init_ide64_dialog(hwnd, num);
            return TRUE;
        case WM_COMMAND:
            command = LOWORD(wparam);
            switch (command) {
                case IDC_IDE64_HDIMAGE_BROWSE:
                    sprintf(tmp, "IDE64Image%d", num);
                    uilib_select_browse(hwnd, translate_text(IDS_IDE64_SELECT_IMAGE), UILIB_FILTER_ALL, UILIB_SELECTOR_TYPE_FILE_SAVE, IDC_IDE64_HDIMAGE_FILE);
                    GetDlgItemText(hwnd, IDC_IDE64_HDIMAGE_FILE, st, MAX_PATH);
                    system_wcstombs(s, st, MAX_PATH);
                    resources_set_string(tmp, s);
                    break;
                case IDC_TOGGLE_IDE64_SIZEAUTODETECT:
                    resources_set_int_sprintf("IDE64AutodetectSize%i", (IsDlgButtonChecked(hwnd, IDC_TOGGLE_IDE64_SIZEAUTODETECT) == BST_CHECKED ? 1 : 0), num);
                    enable_ide64_controls(hwnd);
                    break;
                case IDC_IDE64_CYLINDERS:
                    ide64_hwnd = GetDlgItem(hwnd, IDC_IDE64_CYLINDERS);
                    res_value = (int)SendMessage(ide64_hwnd, CB_GETCURSEL, 0, 0);
                    resources_set_int_sprintf("IDE64Cylinders%i", res_value + 1,num);
                    update_text(hwnd);
                    break;
                case IDC_IDE64_HEADS:
                    ide64_hwnd = GetDlgItem(hwnd, IDC_IDE64_HEADS);
                    res_value = (int)SendMessage(ide64_hwnd, CB_GETCURSEL, 0, 0);
                    resources_set_int_sprintf("IDE64Heads%i", res_value + 1, num);
                    update_text(hwnd);
                    break;
                case IDC_IDE64_SECTORS:
                    ide64_hwnd = GetDlgItem(hwnd, IDC_IDE64_SECTORS);
                    res_value = (int)SendMessage(ide64_hwnd, CB_GETCURSEL, 0, 0);
                    resources_set_int_sprintf("IDE64Sectors%i", res_value, num);
                    update_text(hwnd);
                    break;
            }
            return TRUE;
    }
    return FALSE;
}

#define _CALLBACK(num)                                                                      \
static INT_PTR CALLBACK callback_##num(HWND dialog, UINT msg, WPARAM wparam, LPARAM lparam) \
{                                                                                           \
    return dialog_proc(num, dialog, msg, wparam, lparam);                                   \
}

_CALLBACK(1)
_CALLBACK(2)
_CALLBACK(3)
_CALLBACK(4)

void uiide64_settings_dialog(HWND hwnd)
{
    PROPSHEETPAGE psp[5];
    PROPSHEETHEADER psh;
    int i;

    psp[0].dwSize = sizeof(PROPSHEETPAGE);
    psp[0].dwFlags = PSP_USETITLE /*| PSP_HASHELP*/ ;
    psp[0].hInstance = winmain_instance;
#ifdef _ANONYMOUS_UNION
    psp[0].pszTemplate = MAKEINTRESOURCE(IDD_IDE64_V4_SETTINGS_DIALOG);
    psp[0].pszIcon = NULL;
#else
    psp[0].DUMMYUNIONNAME.pszTemplate = MAKEINTRESOURCE(IDD_IDE64_V4_SETTINGS_DIALOG);
    psp[0].u2.pszIcon = NULL;
#endif
    psp[0].lParam = 0;
    psp[0].pfnCallback = NULL;

    for (i = 1; i < 5; i++) {
        psp[i].dwSize = sizeof(PROPSHEETPAGE);
        psp[i].dwFlags = PSP_USETITLE /*| PSP_HASHELP*/ ;
        psp[i].hInstance = winmain_instance;
#ifdef _ANONYMOUS_UNION
        psp[i].pszTemplate = MAKEINTRESOURCE(IDD_IDE64_SETTINGS_DIALOG);
        psp[i].pszIcon = NULL;
#else
        psp[i].DUMMYUNIONNAME.pszTemplate = MAKEINTRESOURCE(IDD_IDE64_SETTINGS_DIALOG);
        psp[i].u2.pszIcon = NULL;
#endif
        psp[i].lParam = 0;
        psp[i].pfnCallback = NULL;
    }

    psp[0].pfnDlgProc = dialog_v4_proc;
    psp[0].pszTitle = translate_text(IDS_IDE64_V4_SETTINGS);
    psp[1].pfnDlgProc = callback_1;
    psp[1].pszTitle = translate_text(IDS_IDE64_HD_IMAGE_1_SETTINGS);
    psp[2].pfnDlgProc = callback_2;
    psp[2].pszTitle = translate_text(IDS_IDE64_HD_IMAGE_2_SETTINGS);
    psp[3].pfnDlgProc = callback_3;
    psp[3].pszTitle = translate_text(IDS_IDE64_HD_IMAGE_3_SETTINGS);
    psp[4].pfnDlgProc = callback_4;
    psp[4].pszTitle = translate_text(IDS_IDE64_HD_IMAGE_4_SETTINGS);

    psh.dwSize = sizeof(PROPSHEETHEADER);
    psh.dwFlags = PSH_PROPSHEETPAGE | PSH_NOAPPLYNOW;
    psh.hwndParent = hwnd;
    psh.hInstance = winmain_instance;
    psh.pszCaption = translate_text(IDS_IDE64_SETTINGS);
    psh.nPages = 5;
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

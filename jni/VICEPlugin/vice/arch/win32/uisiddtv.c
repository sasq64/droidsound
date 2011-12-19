/*
 * uisiddtv.c - Implementation of the C64DTV SID settings dialog box.
 *
 * Written by
 *  Andreas Matthies <andreas.matthies@gmx.net>
 *  Andreas Boose <viceteam@t-online.de>
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
#include <tchar.h>
#include <windows.h>
#include <prsht.h>

#include "catweaselmkiii.h"
#include "hardsid.h"
#include "intl.h"
#include "machine.h"
#include "res.h"
#include "resources.h"
#include "sid.h"
#include "system.h"
#include "translate.h"
#include "ui.h"
#include "uiapi.h"
#include "uisiddtv.h"
#include "winmain.h"
#include "uilib.h"

static sid_engine_model_t **ui_sid_engine_model_list;

static const int ui_sid_samplemethod[] = {
    IDS_FAST,
    IDS_INTERPOLATING,
    IDS_RESAMPLING,
    IDS_FAST_RESAMPLING,
    0
};

static void enable_resid_sid_controls(HWND hwnd)
{
    int engine, is_enabled;

    resources_get_int("SidEngine", &engine);
    is_enabled = ((engine == SID_ENGINE_RESID) || (engine == SID_ENGINE_RESID_FP));

    EnableWindow(GetDlgItem(hwnd, IDC_SID_RESID_SAMPLING), is_enabled);
    EnableWindow(GetDlgItem(hwnd, IDC_SID_RESID_PASSBAND_VALUE), is_enabled);
}

static void enable_hardsid_sid_controls(HWND hwnd)
{
    int engine, is_enabled;

    resources_get_int("SidEngine", &engine);
    is_enabled = (engine == SID_ENGINE_HARDSID) && (hardsid_available() > 0);

    EnableWindow(GetDlgItem(hwnd, IDC_SID_HARDSID_LEFT_ENGINE), is_enabled);
}

static void init_general_sid_dialog(HWND hwnd)
{
    HWND sid_hwnd;
    int temp_value;
    int res_value, i;
    int active_value;

    sid_hwnd = GetDlgItem(hwnd, IDC_SID_GENGROUP1);
    SetWindowText(sid_hwnd, translate_text(IDS_SID_GENGROUP1));
    sid_hwnd = GetDlgItem(hwnd, IDC_SID_FILTERS);
    SetWindowText(sid_hwnd, translate_text(IDS_SID_FILTERS));

//  Setup status

    resources_get_int("SidFilters", &res_value);
    CheckDlgButton(hwnd, IDC_SID_FILTERS, res_value ? BST_CHECKED : BST_UNCHECKED);

    ui_sid_engine_model_list = sid_get_engine_model_list();

    resources_get_int("SidModel", &temp_value);
    resources_get_int("SidEngine", &res_value);
    res_value <<= 8;
    res_value |= temp_value;
    sid_hwnd = GetDlgItem(hwnd, IDC_SID_ENGINE_MODEL);

    active_value = 0;
    for (i = 0; ui_sid_engine_model_list[i]; i++) {
        TCHAR st[40];

        /* Use "%hs" because the strings are in common code,
           and hence are char rather than TCHAR */
        _stprintf(st, TEXT("%hs"), ui_sid_engine_model_list[i]->name);
        SendMessage(sid_hwnd, CB_ADDSTRING, 0, (LPARAM)st);
        if (ui_sid_engine_model_list[i]->value == res_value) {
            active_value = i;
        }
    }
    SendMessage(sid_hwnd, CB_SETCURSEL, (WPARAM)active_value, 0);
}

union rect_point_s {
    RECT rect;
    POINT point;
};
typedef union rect_point_s rect_point_u;

static void resize_general_sid_dialog(HWND hwnd)
{
    int xsize, ysize;
    HWND child_hwnd;
    RECT rect;
    rect_point_u child_rect;

    GetClientRect(hwnd, &rect);

    child_hwnd = GetDlgItem(hwnd, IDC_SID_GENGROUP1);
    GetClientRect(child_hwnd, &child_rect.rect);
    MapWindowPoints(child_hwnd, hwnd, &child_rect.point, 2);
    MoveWindow(child_hwnd, child_rect.rect.left, child_rect.rect.top, rect.right - 2 * child_rect.rect.left, child_rect.rect.bottom - child_rect.rect.top, TRUE);

    child_hwnd = GetDlgItem(hwnd, IDC_SID_FILTERS);
    GetClientRect(child_hwnd, &child_rect.rect);
    MapWindowPoints(child_hwnd, hwnd, &child_rect.point, 2);
    uilib_get_general_window_extents(child_hwnd, &xsize, &ysize);
    MoveWindow(child_hwnd, child_rect.rect.left, child_rect.rect.top, xsize + 20, child_rect.rect.bottom - child_rect.rect.top, TRUE);
}

static void init_resid_sid_dialog(HWND hwnd)
{
    HWND sid_hwnd;
    int res_value, i;
    TCHAR st[10];

    sid_hwnd = GetDlgItem(hwnd, IDC_SID_RESID_GROUP);
    SetWindowText(sid_hwnd, translate_text(IDS_SID_RESID_GROUP));
    sid_hwnd = GetDlgItem(hwnd, IDC_SID_RESID_SAMPLE);
    SetWindowText(sid_hwnd, translate_text(IDS_SID_RESID_SAMPLE));
    sid_hwnd = GetDlgItem(hwnd, IDC_SID_RESID_PASSBAND);
    SetWindowText(sid_hwnd, translate_text(IDS_SID_RESID_PASSBAND));

    resources_get_int("SidResidSampling", &res_value);
    sid_hwnd = GetDlgItem(hwnd, IDC_SID_RESID_SAMPLING);
    for (i = 0; ui_sid_samplemethod[i]; i++) {
        SendMessage(sid_hwnd, CB_ADDSTRING, 0, (LPARAM)translate_text(ui_sid_samplemethod[i]));
    }
    SendMessage(sid_hwnd, CB_SETCURSEL, (WPARAM)res_value, 0);

    resources_get_int("SidResidPassband", &res_value);
    _stprintf(st, TEXT("%d"), res_value);
    SetDlgItemText(hwnd, IDC_SID_RESID_PASSBAND_VALUE, st);

    enable_resid_sid_controls(hwnd);
}

static void resize_resid_sid_dialog(HWND hwnd)
{
    int xsize, ysize;
    HWND child_hwnd;
    RECT rect;
    RECT child_rect;
    int xpos;

    GetClientRect(hwnd, &rect);

    child_hwnd = GetDlgItem(hwnd, IDC_SID_RESID_GROUP);
    GetClientRect(child_hwnd, &child_rect);
    MapWindowPoints(child_hwnd, hwnd, (POINT*)&child_rect, 2);
    MoveWindow(child_hwnd, child_rect.left, child_rect.top, rect.right - 2 * child_rect.left, rect.bottom - 2 * child_rect.top, TRUE);

    child_hwnd = GetDlgItem(hwnd, IDC_SID_RESID_SAMPLE);
    GetClientRect(child_hwnd, &child_rect);
    MapWindowPoints(child_hwnd, hwnd, (POINT*)&child_rect, 2);
    uilib_get_general_window_extents(child_hwnd, &xsize, &ysize);
    MoveWindow(child_hwnd, child_rect.left, child_rect.top, xsize, child_rect.bottom - child_rect.top, TRUE);
    xpos = child_rect.left + xsize + 10;

    child_hwnd = GetDlgItem(hwnd, IDC_SID_RESID_PASSBAND);
    GetClientRect(child_hwnd, &child_rect);
    MapWindowPoints(child_hwnd, hwnd, (POINT*)&child_rect, 2);
    uilib_get_general_window_extents(child_hwnd, &xsize, &ysize);
    MoveWindow(child_hwnd, child_rect.left, child_rect.top, xsize, child_rect.bottom - child_rect.top, TRUE);
    if (xpos < child_rect.left + xsize + 10) {
        xpos = child_rect.left + xsize + 10;
    }

    child_hwnd = GetDlgItem(hwnd, IDC_SID_RESID_SAMPLING);
    GetClientRect(child_hwnd, &child_rect);
    MapWindowPoints(child_hwnd, hwnd, (POINT*)&child_rect, 2);
    MoveWindow(child_hwnd, xpos, child_rect.top, child_rect.right - child_rect.left, child_rect.bottom - child_rect.top, TRUE);

    child_hwnd = GetDlgItem(hwnd, IDC_SID_RESID_PASSBAND_VALUE);
    GetClientRect(child_hwnd, &child_rect);
    MapWindowPoints(child_hwnd, hwnd, (POINT*)&child_rect, 2);
    MoveWindow(child_hwnd, xpos, child_rect.top, child_rect.right - child_rect.left, child_rect.bottom - child_rect.top, TRUE);
}

static void init_hardsid_sid_dialog(HWND hwnd)
{
    HWND sid_hwnd;
    int res_value;
    unsigned int available, device;

    sid_hwnd = GetDlgItem(hwnd, IDC_HARDSID_GROUP);
    SetWindowText(sid_hwnd, translate_text(IDS_HARDSID_GROUP));
    sid_hwnd = GetDlgItem(hwnd, IDC_HARDSID_LEFT_LABEL);
    SetWindowText(sid_hwnd, translate_text(IDS_HARDSID_LEFT_LABEL));

    available = hardsid_available();
    device = 0;

    resources_get_int("SidHardSIDMain", &res_value);
    sid_hwnd = GetDlgItem(hwnd, IDC_SID_HARDSID_LEFT_ENGINE);

    while (available > 0) {
        TCHAR item[10];

        _stprintf(item, TEXT("%d"), device++);
        SendMessage(sid_hwnd, CB_ADDSTRING, 0, (LPARAM)item);
        available--;
    }

    SendMessage(sid_hwnd, CB_SETCURSEL, (WPARAM)res_value, 0);

    enable_hardsid_sid_controls(hwnd);
}

static void resize_hardsid_sid_dialog(HWND hwnd)
{
    int xsize, ysize;
    HWND child_hwnd;
    RECT rect;
    RECT child_rect;
    int xpos;

    GetClientRect(hwnd, &rect);

    child_hwnd = GetDlgItem(hwnd, IDC_HARDSID_GROUP);
    GetClientRect(child_hwnd, &child_rect);
    MapWindowPoints(child_hwnd, hwnd, (POINT*)&child_rect, 2);
    MoveWindow(child_hwnd, child_rect.left, child_rect.top, rect.right - 2 * child_rect.left, rect.bottom - 2 * child_rect.top, TRUE);

    child_hwnd = GetDlgItem(hwnd, IDC_HARDSID_LEFT_LABEL);
    GetClientRect(child_hwnd, &child_rect);
    MapWindowPoints(child_hwnd, hwnd, (POINT*)&child_rect, 2);
    uilib_get_general_window_extents(child_hwnd, &xsize, &ysize);
    MoveWindow(child_hwnd, child_rect.left, child_rect.top, xsize, child_rect.bottom - child_rect.top, TRUE);
    xpos = child_rect.left + xsize + 10;

    child_hwnd = GetDlgItem(hwnd, IDC_SID_HARDSID_LEFT_ENGINE);
    GetClientRect(child_hwnd, &child_rect);
    MapWindowPoints(child_hwnd, hwnd, (POINT*)&child_rect, 2);
    MoveWindow(child_hwnd, xpos, child_rect.top, child_rect.right - child_rect.left, child_rect.bottom - child_rect.top, TRUE);
}

static void end_general_dialog(HWND hwnd)
{
    resources_set_int("SidFilters", (IsDlgButtonChecked(hwnd, IDC_SID_FILTERS) == BST_CHECKED ? 1 : 0));
}

static INT_PTR CALLBACK general_dialog_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int command;
    int engine, model, temp;

    switch (msg) {
        case WM_COMMAND:
            command = LOWORD(wparam);
            switch (command) {
                case IDC_SID_ENGINE_MODEL:
                    temp = ui_sid_engine_model_list[SendDlgItemMessage(hwnd, IDC_SID_ENGINE_MODEL, CB_GETCURSEL, 0, 0)]->value;
                    engine = temp >> 8;
                    model = temp & 0xff;
                    sid_set_engine_model(engine, model);
                    break;
            }
            return FALSE;
        case WM_NOTIFY:
            switch (((NMHDR FAR *)lparam)->code) {
                case PSN_KILLACTIVE:
                    end_general_dialog(hwnd);
                    return TRUE;
            }
            return FALSE;
        case WM_CLOSE:
            EndDialog(hwnd, 0);
            return TRUE;
        case WM_INITDIALOG:
            system_init_dialog(hwnd);
            init_general_sid_dialog(hwnd);
            return TRUE;
        case WM_SIZE:
            resize_general_sid_dialog(hwnd);
            break;
    }
    return FALSE;
}

static void end_resid_dialog(HWND hwnd)
{
    TCHAR st[4];
    int temp_val, res_val;

    res_val = (int)SendDlgItemMessage(hwnd, IDC_SID_RESID_SAMPLING, CB_GETCURSEL, 0, 0);
    resources_set_int("SidResidSampling", res_val);

    GetDlgItemText(hwnd, IDC_SID_RESID_PASSBAND_VALUE, st, 4);
    temp_val = _ttoi(st);
    if (temp_val < 0) {
        res_val = 0;
    } else if (temp_val > 90) {
        res_val = 90;
    } else {
        res_val = temp_val;
    }
    
    if (temp_val != res_val) {
        ui_error(translate_text(IDS_VAL_D_FOR_S_OUT_RANGE_USE_D), temp_val, translate_text(IDS_SID_RESID_PASSBAND), res_val);
    }
    resources_set_int("SidResidPassband", res_val);
}

static INT_PTR CALLBACK resid_dialog_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg) {
        case WM_NOTIFY:
            switch (((NMHDR FAR *)lparam)->code) {
                case PSN_SETACTIVE:
                    enable_resid_sid_controls(hwnd);
                    return TRUE;
                case PSN_KILLACTIVE:
                    end_resid_dialog(hwnd);
                    return TRUE;
            }
            return FALSE;
        case WM_CLOSE:
            EndDialog(hwnd, 0);
            return TRUE;
        case WM_INITDIALOG:
            system_init_dialog(hwnd);
            init_resid_sid_dialog(hwnd);
            return TRUE;
        case WM_SIZE:
            resize_resid_sid_dialog(hwnd);
            break;
    }
    return FALSE;
}

static void end_hardsid_dialog(HWND hwnd)
{
    resources_set_int("SidHardSIDMain", (int)SendMessage(GetDlgItem(hwnd, IDC_SID_HARDSID_LEFT_ENGINE), CB_GETCURSEL, 0, 0));
}

static INT_PTR CALLBACK hardsid_dialog_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int command;

    switch (msg) {
        case WM_COMMAND:
            command = LOWORD(wparam);
            return FALSE;
        case WM_NOTIFY:
            switch (((NMHDR FAR *)lparam)->code) {
                case PSN_SETACTIVE:
                    enable_hardsid_sid_controls(hwnd);
                    return TRUE;
                case PSN_KILLACTIVE:
                    end_hardsid_dialog(hwnd);
                    return TRUE;
            }
            return FALSE;
        case WM_CLOSE:
            EndDialog(hwnd, 0);
            return TRUE;
        case WM_INITDIALOG:
            system_init_dialog(hwnd);
            init_hardsid_sid_dialog(hwnd);
            return TRUE;
        case WM_SIZE:
            resize_hardsid_sid_dialog(hwnd);
            break;
    }
    return FALSE;
}

void ui_siddtv_settings_dialog(HWND hwnd)
{
    PROPSHEETPAGE psp[3];
    PROPSHEETHEADER psh;

    psp[0].dwSize = sizeof(PROPSHEETPAGE);
    psp[0].dwFlags = PSP_USETITLE /*| PSP_HASHELP*/ ;
    psp[0].hInstance = winmain_instance;
#ifdef _ANONYMOUS_UNION
    psp[0].pszTemplate = MAKEINTRESOURCE(IDD_SID_GENERAL_SETTINGS_DIALOG);
    psp[0].pszIcon = NULL;
#else
    psp[0].DUMMYUNIONNAME.pszTemplate = MAKEINTRESOURCE(IDD_SID_GENERAL_SETTINGS_DIALOG);
    psp[0].u2.pszIcon = NULL;
#endif
    psp[0].lParam = 0;
    psp[0].pfnCallback = NULL;

    psp[1].dwSize = sizeof(PROPSHEETPAGE);
    psp[1].dwFlags = PSP_USETITLE /*| PSP_HASHELP*/ ;
    psp[1].hInstance = winmain_instance;
#ifdef _ANONYMOUS_UNION
    psp[1].pszTemplate = MAKEINTRESOURCE(IDD_SID_RESID_SETTINGS_DIALOG);
    psp[1].pszIcon = NULL;
#else
    psp[1].DUMMYUNIONNAME.pszTemplate = MAKEINTRESOURCE(IDD_SID_RESID_SETTINGS_DIALOG);
    psp[1].u2.pszIcon = NULL;
#endif
    psp[1].lParam = 0;
    psp[1].pfnCallback = NULL;

    if (hardsid_available()) {
        psp[2].dwSize = sizeof(PROPSHEETPAGE);
        psp[2].dwFlags = PSP_USETITLE /*| PSP_HASHELP*/ ;
        psp[2].hInstance = winmain_instance;
#ifdef _ANONYMOUS_UNION
        psp[2].pszTemplate = MAKEINTRESOURCE(translate_res(IDD_SID_HARDSID_SETTINGS_DIALOG));
        psp[2].pszIcon = NULL;
#else
        psp[2].DUMMYUNIONNAME.pszTemplate = MAKEINTRESOURCE(translate_res(IDD_SID_HARDSID_SETTINGS_DIALOG));
        psp[2].u2.pszIcon = NULL;
#endif
        psp[2].lParam = 0;
        psp[2].pfnCallback = NULL;
    }

    psp[0].pfnDlgProc = general_dialog_proc;
    psp[0].pszTitle = translate_text(IDS_GENERAL);
    psp[1].pfnDlgProc = resid_dialog_proc;
    psp[1].pszTitle = TEXT("ReSID-DTV/ReSID-fp");
    if (hardsid_available()) {
        psp[2].pfnDlgProc = hardsid_dialog_proc;
        psp[2].pszTitle = TEXT("HardSID");
    }

    psh.dwSize = sizeof(PROPSHEETHEADER);
    psh.dwFlags = PSH_PROPSHEETPAGE | PSH_NOAPPLYNOW;
    psh.hwndParent = hwnd;
    psh.hInstance = winmain_instance;
    psh.pszCaption = translate_text(IDS_SID_SETTINGS);
    if (hardsid_available()) {
        psh.nPages = 3;
    } else {
        psh.nPages = 2;
    }
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

    PropertySheet(&psh);
}

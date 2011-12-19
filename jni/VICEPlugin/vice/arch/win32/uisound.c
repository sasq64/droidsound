/*
 * uisound.c - Sound device configuration user interface for Win32 platforms.
 *
 * Written by
 *  Tibor Biczo <crown@mail.matav.hu>
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

#include <string.h>
#include <windows.h>

#include "intl.h"
#include "res.h"
#include "resources.h"
#include "sound.h"
#include "system.h"
#include "translate.h"
#include "uiapi.h"
#include "uilib.h"
#include "util.h"
#include "winmain.h"

static int ui_sound_freq[] = {
    8000,
    11025,
    22050,
    44100,
    48000,
    96000
};

static int ui_sound_buffer[] = {
    20,
    25,
    30,
    40,
    50,
    60,
    80,
    100,
    150,
    200,
    250,
    300,
    350
};

static int ui_sound_adjusting[] = {
    SOUND_ADJUST_FLEXIBLE,
    SOUND_ADJUST_ADJUSTING,
    SOUND_ADJUST_EXACT
};

static uilib_localize_dialog_param sound_dialog[] = {
    { 0, IDS_SOUND_CAPTION, -1 },
    { IDC_SOUND_DIRECTX, IDS_SOUND_DIRECTX, 0 },
    { IDC_SOUND_WMM, IDS_SOUND_WMM, 0 },
    { IDC_SOUND_SAMPLE_FREQUENCY, IDS_SOUND_SAMPLE_FREQUENCY, 0 },
    { IDC_SOUND_BUFFER_SIZE, IDS_SOUND_BUFFER_SIZE, 0 },
    { IDC_SOUND_FRAGMENT_SIZE_LABEL, IDS_SOUND_FRAGMENT_SIZE_LABEL, 0 },
    { IDC_SOUND_SYNCH_METHOD, IDS_SOUND_SYNCH_METHOD, 0 },
    { IDOK, IDS_OK, 0 },
    { IDCANCEL, IDS_CANCEL, 0 },
    { 0, 0, 0 }
};

static uilib_dialog_group sound_driver_group[] = {
    { IDC_SOUND_DIRECTX, 1 },
    { IDC_SOUND_WMM, 1 },
    { 0, 0 }
};

static uilib_dialog_group sound_left_group[] = {
    { IDC_SOUND_SAMPLE_FREQUENCY, 0 },
    { IDC_SOUND_BUFFER_SIZE, 0 },
    { IDC_SOUND_FRAGMENT_SIZE_LABEL, 0 },
    { IDC_SOUND_SYNCH_METHOD, 0 },
    { 0, 0 }
};

static uilib_dialog_group sound_right_group[] = {
    { IDC_SOUND_FREQ, 0 },
    { IDC_SOUND_BUFFER, 0 },
    { IDC_SOUND_FRAGMENT_SIZE, 0 },
    { IDC_SOUND_SYNCH, 0 },
    { 0, 0 }
};

static uilib_dialog_group sound_filling_group[] = {
    { IDC_SOUND_WMM, 0 },
    { IDC_SOUND_FREQ, 0 },
    { IDC_SOUND_BUFFER, 0 },
    { IDC_SOUND_FRAGMENT_SIZE, 0 },
    { IDC_SOUND_SYNCH, 0 },
    { 0, 0 }
};

static int move_buttons_group[] = {
    IDOK,
    IDCANCEL,
    0
};

static void init_sound_dialog(HWND hwnd)
{
    HWND snd_hwnd;
    int i, res_value;
    const char *devicename;
    char tmp[20];
    int xpos;
    RECT rect;

    /* translate all dialog items */
    uilib_localize_dialog(hwnd, sound_dialog);

    /* adjust the size of the elements in the driver group */
    uilib_adjust_group_width(hwnd, sound_driver_group);

    /* get the max x of the direct x driver element */
    uilib_get_element_max_x(hwnd, IDC_SOUND_DIRECTX, &xpos);

    /* move the wmm driver element to the correct location */
    uilib_move_element(hwnd, IDC_SOUND_WMM, xpos + 10);

    /* adjust the size of the elements in the left group */
    uilib_adjust_group_width(hwnd, sound_left_group);

    /* get the max x of the left group */
    uilib_get_group_max_x(hwnd, sound_left_group, &xpos);

    /* move the right group to the correct location */
    uilib_move_group(hwnd, sound_right_group, xpos + 10);

    /* get the max x of the window filling group */
    uilib_get_group_max_x(hwnd, sound_filling_group, &xpos);

    /* set the width of the dialog to 'surround' all the elements */
    GetWindowRect(hwnd, &rect);
    MoveWindow(hwnd, rect.left, rect.top, xpos + 10, rect.bottom - rect.top, TRUE);

    /* recenter the buttons in the newly resized dialog window */
    uilib_center_buttons(hwnd, move_buttons_group, 0);

    snd_hwnd = GetDlgItem(hwnd, IDC_SOUND_FREQ);
    resources_get_int("SoundSampleRate", &res_value);
    for (i = 0; i < sizeof(ui_sound_freq) / sizeof(*ui_sound_freq); i ++) {
        sprintf(tmp, "%d Hz", ui_sound_freq[i]);
        SendMessage(snd_hwnd, CB_ADDSTRING, 0, (LPARAM)TEXT(tmp));
        if (ui_sound_freq[i] == res_value) {
            SendMessage(snd_hwnd, CB_SETCURSEL, i, 0);
        }
    }

    snd_hwnd = GetDlgItem(hwnd, IDC_SOUND_BUFFER);
    resources_get_int("SoundBufferSize", &res_value);
    for (i = 0; i < sizeof(ui_sound_buffer) / sizeof(*ui_sound_buffer); i ++) {
        sprintf(tmp, "%d msec", ui_sound_buffer[i]);
        SendMessage(snd_hwnd, CB_ADDSTRING, 0, (LPARAM)TEXT(tmp));
        if (ui_sound_buffer[i] == res_value) {
            SendMessage(snd_hwnd, CB_SETCURSEL, i, 0);
        }
    }

    snd_hwnd = GetDlgItem(hwnd, IDC_SOUND_SYNCH);
    SendMessage(snd_hwnd, CB_ADDSTRING, 0, (LPARAM)translate_text(IDS_FLEXIBLE));
    SendMessage(snd_hwnd, CB_ADDSTRING, 0, (LPARAM)translate_text(IDS_ADJUSTING));
    SendMessage(snd_hwnd, CB_ADDSTRING, 0, (LPARAM)translate_text(IDS_EXACT));
    resources_get_int("SoundSpeedAdjustment", &res_value);
    switch (res_value) {
        case SOUND_ADJUST_FLEXIBLE:
        default:
            res_value = 0;
            break;
        case SOUND_ADJUST_ADJUSTING:
            res_value = 1;
            break;
        case SOUND_ADJUST_EXACT:
            res_value = 2;
            break;
    }
    SendMessage(snd_hwnd, CB_SETCURSEL, (WPARAM)res_value, 0);

    resources_get_string("SoundDeviceName", (void *)&devicename);
    if (devicename && !strcasecmp("wmm", devicename)) {
        res_value = IDC_SOUND_WMM;
    } else {
        res_value = IDC_SOUND_DIRECTX;
    }
    CheckRadioButton(hwnd, IDC_SOUND_DIRECTX, IDC_SOUND_WMM, res_value);
        
    snd_hwnd = GetDlgItem(hwnd, IDC_SOUND_FRAGMENT_SIZE);
    SendMessage(snd_hwnd, CB_ADDSTRING, 0, (LPARAM)translate_text(IDS_SOUND_FRAGMENT_SIZE_SMALL));
    SendMessage(snd_hwnd, CB_ADDSTRING, 0, (LPARAM)translate_text(IDS_SOUND_FRAGMENT_SIZE_MEDIUM));
    SendMessage(snd_hwnd, CB_ADDSTRING, 0, (LPARAM)translate_text(IDS_SOUND_FRAGMENT_SIZE_LARGE));
    resources_get_int("SoundFragmentSize", &res_value);
    SendMessage(snd_hwnd, CB_SETCURSEL, (WPARAM)res_value, 0);

}

static void end_sound_dialog(HWND hwnd)
{
    resources_set_int("SoundSampleRate", ui_sound_freq[SendMessage(GetDlgItem(hwnd,IDC_SOUND_FREQ), CB_GETCURSEL, 0, 0)]);
    resources_set_int("SoundBufferSize", ui_sound_buffer[SendMessage(GetDlgItem(hwnd,IDC_SOUND_BUFFER), CB_GETCURSEL, 0, 0)]);
    resources_set_int("SoundFragmentSize", (int)SendMessage(GetDlgItem(hwnd, IDC_SOUND_FRAGMENT_SIZE), CB_GETCURSEL, 0, 0));
    resources_set_int("SoundSpeedAdjustment", ui_sound_adjusting[SendMessage(GetDlgItem(hwnd, IDC_SOUND_SYNCH), CB_GETCURSEL, 0, 0)]);
}

static void select_dx(void)
{
    resources_set_string("SoundDeviceName", "dx");
    ui_display_statustext(translate_text(IDS_SOUND_DRIVER_DIRECTX), 1);
}

static void select_wmm(void)
{
    resources_set_string("SoundDeviceName", "wmm");
    ui_display_statustext(translate_text(IDS_SOUND_DRIVER_WMM), 1);
}

static INT_PTR CALLBACK dialog_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int command;

    switch (msg) {
        case WM_INITDIALOG:
            system_init_dialog(hwnd);
            init_sound_dialog(hwnd);
            return TRUE;
        case WM_COMMAND:
            command = LOWORD(wparam);
                switch (command) {
                    case IDC_SOUND_DIRECTX:
                    select_dx();
                    break;
                case IDC_SOUND_WMM:
                    select_wmm();
                    break;
                case IDOK:
                    end_sound_dialog(hwnd);
                case IDCANCEL:
                    EndDialog(hwnd, 0);
                    return TRUE;
            }
            break;
    }
    return FALSE;
}

void ui_sound_settings_dialog(HWND hwnd)
{
    DialogBox(winmain_instance, MAKEINTRESOURCE(IDD_SOUND_SETTINGS_DIALOG), hwnd, dialog_proc);
}

static void enable_sound_record_controls(HWND hwnd)
{
    EnableWindow(GetDlgItem(hwnd, IDC_SOUND_RECORD_FORMAT), 1);
    EnableWindow(GetDlgItem(hwnd, IDC_SOUND_RECORD_BROWSE), 1);
    EnableWindow(GetDlgItem(hwnd, IDC_SOUND_RECORD_FILE), 1);
}

static uilib_localize_dialog_param sound_record_dialog_trans[] = {
    { 0, IDS_SOUND_RECORD_CAPTION, -1 },
    { IDC_SOUND_RECORD_FORMAT_LABEL, IDS_SOUND_RECORD_FORMAT_LABEL, 0 },
    { IDC_SOUND_RECORD_FILE_LABEL, IDS_SOUND_RECORD_FILE_LABEL, 0 },
    { IDC_SOUND_RECORD_BROWSE, IDS_BROWSE, 0 },
    { IDOK, IDS_OK, 0 },
    { IDCANCEL, IDS_CANCEL, 0 },
    { 0, 0, 0 }
};

static uilib_dialog_group sound_record_group[] = {
    { IDC_SOUND_RECORD_FORMAT_LABEL, 0 },
    { IDC_SOUND_RECORD_FILE_LABEL, 0 },
    { IDC_SOUND_RECORD_BROWSE, 1 },
    { 0, 0 }
};

static uilib_dialog_group sound_record_right_group[] = {
    { IDC_SOUND_RECORD_FORMAT, 0 },
    { IDC_SOUND_RECORD_BROWSE, 0 },
    { IDC_SOUND_RECORD_FILE, 0 },
    { 0, 0 }
};

static void init_sound_record_dialog(HWND hwnd)
{
    HWND temp_hwnd;
    const char *sound_record_file;
    TCHAR *st_sound_record_file;
    int xpos;
    RECT rect;

    /* translate all dialog items */
    uilib_localize_dialog(hwnd, sound_record_dialog_trans);

    /* adjust the size of the elements in the datasette_sub_group */
    uilib_adjust_group_width(hwnd, sound_record_group);

    /* get the max x of the sound record format element */
    uilib_get_element_max_x(hwnd, IDC_SOUND_RECORD_FORMAT_LABEL, &xpos);

    /* move the sound record format indicator element to the correct position */
    uilib_move_element(hwnd, IDC_SOUND_RECORD_FORMAT, xpos + 10);

    /* get the max x of the sound record file element */
    uilib_get_element_max_x(hwnd, IDC_SOUND_RECORD_FILE_LABEL, &xpos);

    /* move the browse button to the correct position */
    uilib_move_element(hwnd, IDC_SOUND_RECORD_BROWSE, xpos + 10);

    /* get the max x of the right group */
    uilib_get_group_max_x(hwnd, sound_record_right_group, &xpos);

    /* set the width of the dialog to 'surround' all the elements */
    GetWindowRect(hwnd, &rect);
    MoveWindow(hwnd, rect.left, rect.top, xpos + 20, rect.bottom - rect.top, TRUE);

    /* recenter the buttons in the newly resized dialog window */
    uilib_center_buttons(hwnd, move_buttons_group, 0);

    temp_hwnd = GetDlgItem(hwnd, IDC_SOUND_RECORD_FORMAT);
    SendMessage(temp_hwnd, CB_ADDSTRING, 0, (LPARAM)"AIFF");
    SendMessage(temp_hwnd, CB_ADDSTRING, 0, (LPARAM)"IFF");
#ifdef USE_LAMEMP3
    SendMessage(temp_hwnd, CB_ADDSTRING, 0, (LPARAM)"MP3");
#endif
    SendMessage(temp_hwnd, CB_ADDSTRING, 0, (LPARAM)"VOC");
    SendMessage(temp_hwnd, CB_ADDSTRING, 0, (LPARAM)"WAV");
#ifdef USE_LAMEMP3
    SendMessage(temp_hwnd, CB_SETCURSEL, (WPARAM)4, 0);
#else
    SendMessage(temp_hwnd, CB_SETCURSEL, (WPARAM)3, 0);
#endif

    resources_get_string("SoundRecordDeviceArg", &sound_record_file);
    st_sound_record_file = system_mbstowcs_alloc(sound_record_file);
    SetDlgItemText(hwnd, IDC_SOUND_RECORD_FILE, sound_record_file != NULL ? st_sound_record_file : TEXT(""));
    system_mbstowcs_free(st_sound_record_file);

    enable_sound_record_controls(hwnd);
}

static char *sound_format[] = {
    "aiff",
    "iff",
#ifdef USE_LAMEMP3
    "mp3",
#endif
    "voc",
    "wav"
};

static void end_sound_record_dialog(HWND hwnd)
{
    TCHAR st[MAX_PATH];
    char s[MAX_PATH];
    int i;

    i = (int)SendMessage(GetDlgItem(hwnd, IDC_SOUND_RECORD_FORMAT), CB_GETCURSEL, 0, 0);

    GetDlgItemText(hwnd, IDC_SOUND_RECORD_FILE, st, MAX_PATH);
    system_wcstombs(s, st, MAX_PATH);

    util_add_extension_maxpath(s, sound_format[i], MAX_PATH);

    resources_set_string("SoundRecordDeviceName", "");
    resources_set_string("SoundRecordDeviceArg", s);
    resources_set_string("SoundRecordDeviceName", sound_format[i]);
    resources_set_int("Sound", 1);
    ui_display_statustext(translate_text(IDS_SOUND_RECORDING_STARTED), 1);
}

static void browse_sound_record_file(HWND hwnd)
{
    uilib_select_browse(hwnd, TEXT("Select Sound Record File"), UILIB_FILTER_ALL, UILIB_SELECTOR_TYPE_FILE_SAVE, IDC_SOUND_RECORD_FILE);
}

static INT_PTR CALLBACK sound_record_dialog_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int command;

    switch (msg) {
        case WM_COMMAND:
            command = LOWORD(wparam);
            switch (command) {
                case IDC_SOUND_RECORD_BROWSE:
                    browse_sound_record_file(hwnd);
                    break;
                case IDOK:
                    end_sound_record_dialog(hwnd);
                case IDCANCEL:
                    EndDialog(hwnd, 0);
                    return TRUE;
            }
            return FALSE;
        case WM_CLOSE:
            EndDialog(hwnd, 0);
            return TRUE;
        case WM_INITDIALOG:
            init_sound_record_dialog(hwnd);
            return TRUE;
    }
    return FALSE;
}

void ui_sound_record_settings_dialog(HWND hwnd)
{
    DialogBox(winmain_instance, (LPCTSTR)(UINT_PTR)IDD_SOUND_RECORD_SETTINGS_DIALOG, hwnd, sound_record_dialog_proc);
}

/*
 * ui.c - Windows user interface.
 *
 * Written by
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  Tibor Biczo <crown@mail.matav.hu>
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

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#ifdef HAVE_COMMCTRL_H
#include <commctrl.h>
#endif

#include "attach.h"
#include "autostart.h"
#include "archdep.h"
#include "charset.h"
#include "clipboard.h"
#include "debug.h"
#include "drive.h"
#include "drivecpu.h"
#include "fullscrn.h"
#include "imagecontents.h"
#include "interrupt.h"
#include "intl.h"
#include "kbd.h"
#include "kbdbuf.h"
#include "keyboard.h"
#include "lib.h"
#include "log.h"
#include "machine.h"
#include "maincpu.h"
#include "mem.h"
#include "monitor.h"
#include "mouse.h"
#include "mousedrv.h"
#include "network.h"
#include "res.h"
#include "resources.h"
#include "system.h"
#include "translate.h"
#include "types.h"
#include "ui.h"
#include "uiapi.h"
#include "uiattach.h"
#include "uiautostart.h"
#include "uiperipheral.h"
#include "uicmdline.h"
#include "uidatasette.h"
#include "uievent.h"
#include "uifliplist.h"
#include "uihelp.h"
#include "uijoystick.h"
#include "uikeyboard.h"
#include "uilib.h"
#include "uimediafile.h"
#include "uinetwork.h"
#include "uiquicksnapshot.h"
#include "uiram.h"
#include "uirs232.h"
#include "uisnapshot.h"
#include "uisound.h"
#include "uispeed.h"
#include "util.h"
#include "version.h"
#include "vice-event.h"
#include "videoarch.h"
#include "viewport.h"
#include "vsync.h"
#include "winlong.h"
#include "winmain.h"
#include "statusbar.h"
#include "vsyncapi.h"

#define countof(array) (sizeof(array) / sizeof((array)[0]))

static TCHAR *hwnd_titles[2];

/* Exposure handler.  */
HWND window_handles[2];
HMENU translated_menu;
int number_of_windows = 0;
int window_canvas_xsize[2];
int window_canvas_ysize[2];
int window_padding_x[2];
int window_padding_y[2];

static HACCEL ui_accelerator;

static generic_trans_table_t generic_trans_table[] = {
    { IDM_REFRESH_RATE_1, "1/&1" },
    { IDM_REFRESH_RATE_2, "1/&2" },
    { IDM_REFRESH_RATE_3, "1/&3" },
    { IDM_REFRESH_RATE_4, "1/&4" },
    { IDM_REFRESH_RATE_5, "1/&5" },
    { IDM_REFRESH_RATE_6, "1/&6" },
    { IDM_REFRESH_RATE_7, "1/&7" },
    { IDM_REFRESH_RATE_8, "1/&8" },
    { IDM_REFRESH_RATE_9, "1/&9" },
    { IDM_REFRESH_RATE_10, "1/1&0" },
    { IDM_MAXIMUM_SPEED_200, "&200%" },
    { IDM_MAXIMUM_SPEED_100, "&100%" },
    { IDM_MAXIMUM_SPEED_50, "&50%" },
    { IDM_MAXIMUM_SPEED_20, "&20%" },
    { IDM_MAXIMUM_SPEED_10, "1&0%" },
    { IDM_SYNC_FACTOR_PAL, "&PAL" },
    { IDM_SYNC_FACTOR_NTSC, "&NTSC" },
    { 0, NULL}
};

/* Forward prototypes.  */
static LRESULT CALLBACK dummywindowproc(HWND window, UINT msg, WPARAM wparam, LPARAM lparam);
static LRESULT CALLBACK window_proc(HWND window, UINT msg, WPARAM wparam, LPARAM lparam);

/* List of resources that can be grayed out from the menus.  */
static const ui_menu_toggle_t grayed_list_res[] = {
#ifdef HAVE_TFE
/*    { "ETHERNET_DISABLED", IDM_TFE_SETTINGS }, */
#endif /* #ifdef HAVE_TFE */
    { NULL, 0 }
};

static const ui_menu_toggle_by_machine_t grayed_list_machine[] = {
/*
    { VICE_MACHINE_C64SC, IDM_SOME_ITEM_TO_BE_GRAYED_FOR_THIS_MACHINE },
*/
    { 0, 0 }
};

/* List of resources that can be switched on and off from the menus.  */
static const ui_menu_toggle_t toggle_list[] = {
    { "Sound", IDM_TOGGLE_SOUND },
    { "DriveTrueEmulation", IDM_TOGGLE_DRIVE_TRUE_EMULATION },
    { "AutostartHandleTrueDriveEmulation", IDM_TOGGLE_AUTOSTART_HANDLE_TDE },
    { "WarpMode", IDM_TOGGLE_WARP_MODE },
    { "VirtualDevices", IDM_TOGGLE_VIRTUAL_DEVICES },
    { "SaveResourcesOnExit", IDM_TOGGLE_SAVE_SETTINGS_ON_EXIT },
    { "ConfirmOnExit", IDM_TOGGLE_CONFIRM_ON_EXIT },
    { "FullScreenEnabled", IDM_TOGGLE_FULLSCREEN },
#ifdef HAVE_D3D9_H
    { "DX9Disable", IDM_TOGGLE_DX9DISABLE },
#endif
    { "AlwaysOnTop", IDM_TOGGLE_ALWAYSONTOP },
    { "KeySetEnable", IDM_JOYKEYS_TOGGLE },
    { "JoyOpposite", IDM_ALLOW_JOY_OPPOSITE_TOGGLE },
#ifdef DEBUG
    { "MainCPU_TRACE", IDM_TOGGLE_MAINCPU_TRACE },
    { "Drive0CPU_TRACE", IDM_TOGGLE_DRIVE0CPU_TRACE },
    { "Drive1CPU_TRACE", IDM_TOGGLE_DRIVE1CPU_TRACE },
#endif
    { NULL, 0 }
};

/*  List of resources which can have multiple mutual exclusive menu entries. */

static const ui_res_possible_values_t RefreshRateValues[] = {
    { 0, IDM_REFRESH_RATE_AUTO },
    { 1, IDM_REFRESH_RATE_1 },
    { 2, IDM_REFRESH_RATE_2 },
    { 3, IDM_REFRESH_RATE_3 },
    { 4, IDM_REFRESH_RATE_4 },
    { 5, IDM_REFRESH_RATE_5 },
    { 6, IDM_REFRESH_RATE_6 },
    { 7, IDM_REFRESH_RATE_7 },
    { 8, IDM_REFRESH_RATE_8 },
    { 9, IDM_REFRESH_RATE_9 },
    { 10, IDM_REFRESH_RATE_10 },
    { -1, 0 }
};

static ui_res_possible_values_t SpeedValues[] = {
    { 0, IDM_MAXIMUM_SPEED_NO_LIMIT },
    { 10, IDM_MAXIMUM_SPEED_10 },
    { 20, IDM_MAXIMUM_SPEED_20 },
    { 50, IDM_MAXIMUM_SPEED_50 },
    { 100, IDM_MAXIMUM_SPEED_100 },
    { 200, IDM_MAXIMUM_SPEED_200 },
    { -1, 0 }
};

static ui_res_possible_values_t RecordingOptions[] = {
    { EVENT_START_MODE_FILE_SAVE, IDM_EVENT_START_MODE_SAVE },
    { EVENT_START_MODE_FILE_LOAD, IDM_EVENT_START_MODE_LOAD },
    { EVENT_START_MODE_RESET, IDM_EVENT_START_MODE_RESET },
    { EVENT_START_MODE_PLAYBACK, IDM_EVENT_START_MODE_PLAYBACK },
    { -1, 0 }
};

static const ui_res_possible_values_t SyncFactor[] = {
    { MACHINE_SYNC_PAL, IDM_SYNC_FACTOR_PAL },
    { MACHINE_SYNC_NTSC, IDM_SYNC_FACTOR_NTSC },
    { MACHINE_SYNC_NTSCOLD, IDM_SYNC_FACTOR_NTSCOLD },
    { MACHINE_SYNC_PALN, IDM_SYNC_FACTOR_PALN },
    { -1, 0 }
};

#ifdef DEBUG
static const ui_res_possible_values_t TraceMode[] = {
    { DEBUG_NORMAL, IDM_DEBUG_MODE_NORMAL },
    { DEBUG_SMALL, IDM_DEBUG_MODE_SMALL },
    { DEBUG_HISTORY, IDM_DEBUG_MODE_HISTORY },
    { DEBUG_AUTOPLAY, IDM_DEBUG_MODE_AUTOPLAY },
    { -1, 0 }
};
#endif

static const ui_res_value_list_t value_list[] = {
    { "RefreshRate", RefreshRateValues, 0 },
    { "Speed", SpeedValues, IDM_MAXIMUM_SPEED_CUSTOM },
    { "MachineVideoStandard", SyncFactor, 0 },
    { "EventStartMode", RecordingOptions, 0 },
#ifdef DEBUG
    { "TraceMode", TraceMode, 0},
#endif
    { NULL, NULL, 0 }
};

static const struct {
    char *lang_code;
    UINT item_id;
} ui_lang_menu_entries [] = {
    { "en", IDM_LANG_EN },
    { "da", IDM_LANG_DA },
    { "de", IDM_LANG_DE },
    { "es", IDM_LANG_ES },
    { "fr", IDM_LANG_FR },
    { "hu", IDM_LANG_HU },
    { "it", IDM_LANG_IT },
    { "ko", IDM_LANG_KO },
    { "nl", IDM_LANG_NL },
    { "pl", IDM_LANG_PL },
    { "ru", IDM_LANG_RU },
    { "sv", IDM_LANG_SV },
    { "tr", IDM_LANG_TR },
    { NULL, 0}
};

ui_menu_translation_table_t monitor_trans_popup_table[] = {
    { 1, IDS_MP_FILE },
    { 1, IDS_MP_DEBUG },
    { 1, IDS_MP_VIEW },
    { 1, IDS_MP_WINDOW },
    { 0, 0 }
};

ui_popup_translation_table_t monitor_trans_item_table[] = {
    { IDM_MON_OPEN, IDS_MI_MON_OPEN },
    { IDM_MON_SAVE, IDS_MI_MON_SAVE },
    { IDM_MON_PRINT, IDS_MI_MON_PRINT },
    { IDM_EXIT, IDS_MI_MON_EXIT },
    { IDM_MON_STOP_DEBUG, IDS_MI_MON_STOP_DEBUG },
    { IDM_MON_STOP_EXEC, IDS_MI_MON_STOP_EXEC },
    { IDM_MON_STEP_INTO, IDS_MI_MON_STEP_INTO },
    { IDM_MON_STEP_OVER, IDS_MI_MON_STEP_OVER },
    { IDM_MON_SKIP_RETURN, IDS_MI_MON_SKIP_RETURN },
    { IDM_MON_GOTO_CURSOR, IDS_MI_MON_GOTO_CURSOR },
    { IDM_MON_EVAL, IDS_MI_MON_EVAL },
    { IDM_MON_CURRENT, IDS_MI_MON_CURRENT },
    { IDM_MON_WND_EVAL, IDS_MI_MON_WND_EVAL },
    { IDM_MON_WND_REG, IDS_MI_MON_WND_REG },
    { IDM_MON_WND_MEM, IDS_MI_MON_WND_MEM },
    { IDM_MON_WND_DIS, IDS_MI_MON_WND_DIS },
    { IDM_MON_WND_CONSOLE, IDS_MI_MON_WND_CONSOLE },
    { IDM_MON_COMPUTER, IDS_MI_MON_COMPUTER },
    { IDM_MON_DRIVE8, IDS_MI_MON_DRIVE8 },
    { IDM_MON_DRIVE9, IDS_MI_MON_DRIVE9 },
    { IDM_MON_CASCADE, IDS_MI_MON_CASCADE },
    { IDM_MON_TILE_VERT, IDS_MI_MON_TILE_VERT },
    { IDM_MON_TILE_HORIZ, IDS_MI_MON_TILE_HORIZ },
    { IDM_MON_ARRANGE_ICONS, IDS_MI_MON_ARRANGE_ICONS },
    { 0, 0 }
};

/* ------------------------------------------------------------------------ */

static HWND main_hwnd;

static int emu_menu;

static int pause_pending;

static ui_menu_translation_table_t *menu_translation_table;
static ui_popup_translation_table_t *popup_translation_table;

void ui_register_translation_tables(ui_menu_translation_table_t *menu_table, ui_popup_translation_table_t *popup_table)
{
    menu_translation_table = menu_table;
    popup_translation_table = popup_table;
    ui_update_menu();
}

/* Initialize the UI before setting all the resource values.  */
int ui_init(int *argc, char **argv)
{
    WNDCLASS window_class;

    switch (machine_class) {
        case VICE_MACHINE_C64:
        case VICE_MACHINE_C64SC:
            emu_menu = IDR_MENUC64;
            break;
        case VICE_MACHINE_C64DTV:
            emu_menu = IDR_MENUC64DTV;
            break;
        case VICE_MACHINE_C128:
            emu_menu = IDR_MENUC128;
            break;
        case VICE_MACHINE_VIC20:
            emu_menu = IDR_MENUVIC;
            break;
        case VICE_MACHINE_PET:
            emu_menu = IDR_MENUPET;
            break;
        case VICE_MACHINE_PLUS4:
            emu_menu = IDR_MENUPLUS4;
            break;
        case VICE_MACHINE_CBM5x0:
        case VICE_MACHINE_CBM6x0:
            emu_menu = IDR_MENUCBM2;
            break;
        default:
            log_debug("UI: No menu entries for this machine defined!");
            log_debug("UI: Using C64 type UI menues.");
            emu_menu = IDR_MENUC64;
    }

    /* Register the window class.  */
    window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    window_class.lpfnWndProc = window_proc;
    window_class.cbClsExtra = 0;
    window_class.cbWndExtra = 0;
    window_class.hInstance = winmain_instance;
    window_class.hIcon = LoadIcon(winmain_instance, MAKEINTRESOURCE(IDI_ICON1));
    window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    window_class.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0) + 1);
    window_class.lpszMenuName = MAKEINTRESOURCE(emu_menu);
    window_class.lpszClassName = APPLICATION_CLASS;
    RegisterClass(&window_class);


    window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    window_class.lpfnWndProc = dummywindowproc;
    window_class.cbClsExtra = 0;
    window_class.cbWndExtra = 0;
    window_class.hInstance = winmain_instance;
    window_class.hIcon = LoadIcon(winmain_instance, MAKEINTRESOURCE(IDI_ICON1));
    window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    window_class.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0) + 1);
    window_class.lpszMenuName = NULL;
    window_class.lpszClassName = APPLICATION_CLASS_MAIN;
    RegisterClass(&window_class);

    /* Create the main window.  Notice that we are not going to
       `ShowWindow()' it yet; this will be done as soon as the video module
       requires us to do so.  This is needed both because the video module
       needs an application window to be created to initialize itself, and
       because this might allow us to support more than one emulation window
       in the future.  */
    main_hwnd = CreateWindow(APPLICATION_CLASS_MAIN,
                             TEXT("No title"), /* (for now) */
                             WS_OVERLAPPED | WS_CLIPCHILDREN | WS_BORDER | WS_DLGFRAME| WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
                             CW_USEDEFAULT,
                             CW_USEDEFAULT,
                             CW_USEDEFAULT,
                             CW_USEDEFAULT,
                             NULL,
                             NULL,
                             winmain_instance,
                             NULL);
    InitCommonControls();

    number_of_windows = 0;

    statusbar_create_brushes();

    return 0;
}

void ui_shutdown(void)
{
    statusbar_delete_brushes();
    uikeyboard_shutdown();
}

/* Initialize the UI after setting all the resource values.  */
int ui_init_finish(void)
{
    ui_accelerator = uikeyboard_create_accelerator_table();
    ui_fullscreen_init();
    atexit(ui_exit);
    return 0;
}

int ui_init_finalize(void)
{
    int alwaysontop;

    fullscreen_setup_finished();
    resources_get_int("AlwaysOnTop", &alwaysontop);
    ui_set_alwaysontop(alwaysontop);
    return 0;
}

/* Exit.  */
void ui_exit(void)
{
    int i;

    for (i = 0; i < number_of_windows; i++) {
        lib_free(hwnd_titles[i]);
    }

    if (ui_accelerator) {
        DestroyAcceleratorTable(ui_accelerator);
    }

    ui_fullscreen_shutdown();
    uilib_shutdown();
}

static void ui_translate_menu_popups(HMENU menu, ui_popup_translation_table_t *trans_table)
{
    int pos1 = -1;
    int pos2 = -1;
    int pos3 = -1;

    HMENU menu1 = NULL;
    HMENU menu2 = NULL;
    HMENU menu3 = NULL;

    int i = 0;

    if (trans_table == NULL) {
        return;
    }

    while (trans_table[i].level != 0) {
        switch (trans_table[i].level) {
            case 1:
                menu1 = NULL;
                while (menu1 == NULL) {
                    pos1++;
                    menu1 = GetSubMenu(menu, pos1);
                }
                if (trans_table[i].ids != 0) {
                    ModifyMenu(menu, (UINT)pos1, MF_BYPOSITION | MF_STRING | MF_POPUP, vice_ptr_to_uint(menu1), translate_text(trans_table[i].ids));
                }
                pos2 = -1;
                pos3 = -1;
                break;
            case 2:
                menu2 = NULL;
                while (menu2 == NULL) {
                    pos2++;
                    menu2 = GetSubMenu(menu1, pos2);
                }
                ModifyMenu(menu1, (UINT)pos2, MF_BYPOSITION | MF_STRING | MF_POPUP, vice_ptr_to_uint(menu2), translate_text(trans_table[i].ids));
                pos3 = -1;
                break;
            case 3:
                menu3 = NULL;
                while (menu3 == NULL) {
                    pos3++;
                    menu3 = GetSubMenu(menu2, pos3);
                }
                ModifyMenu(menu2, (UINT)pos3, MF_BYPOSITION | MF_STRING | MF_POPUP, vice_ptr_to_uint(menu3), translate_text(trans_table[i].ids));
                break;
        }
        i++;
    }
}

static void ui_translate_menu_items(HMENU menu, ui_menu_translation_table_t *trans_table)
{
    int i;

    if (trans_table == NULL) {
        return;
    }

    for (i = 0; trans_table[i].idm != 0; i++) {
        ModifyMenu(menu, trans_table[i].idm, MF_BYCOMMAND | MF_STRING, trans_table[i].idm, translate_text(trans_table[i].ids));
    }

    for (i = 0; generic_trans_table[i].idm != 0; i++) {
        ModifyMenu(menu, generic_trans_table[i].idm, MF_BYCOMMAND | MF_STRING, generic_trans_table[i].idm, generic_trans_table[i].text);
    }
}

void ui_translate_monitor_menu(HMENU menu)
{
    ui_translate_menu_popups(menu, (ui_popup_translation_table_t *)monitor_trans_popup_table);
    ui_translate_menu_items(menu, (ui_menu_translation_table_t *)monitor_trans_item_table);
}


void ui_set_render_window(video_canvas_t *canvas, int fullscreen)
{
    if (fullscreen) {
        canvas->render_hwnd = canvas->hwnd;
    } else {
        canvas->render_hwnd = canvas->client_hwnd;
    }
}

/*  Create a Window for the emulation.  */
void ui_open_canvas_window(video_canvas_t *canvas)
{
    HWND hwnd;
    int xpos, ypos;
    HMENU menu;

    resources_get_int_sprintf("Window%dXpos", &xpos, number_of_windows);
    resources_get_int_sprintf("Window%dYpos", &ypos, number_of_windows);

    hwnd_titles[number_of_windows] = system_mbstowcs_alloc(canvas->title);
    hwnd = CreateWindow(APPLICATION_CLASS,
                        hwnd_titles[number_of_windows],
                        WS_CAPTION | WS_CLIPCHILDREN | WS_BORDER | WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
                        xpos,
                        ypos,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        NULL,
                        NULL,
                        winmain_instance,
                        NULL);

    if (hwnd == NULL) {
        log_debug("Window creation failed");
    }

    window_handles[number_of_windows] = hwnd;
    window_canvas_xsize[number_of_windows] = canvas->width;
    window_canvas_ysize[number_of_windows] = canvas->height;
    number_of_windows++;

    statusbar_create(hwnd);
    canvas->hwnd = hwnd;

    ui_resize_canvas_window(canvas);

    menu = LoadMenu(winmain_instance, MAKEINTRESOURCE(emu_menu));
    ui_translate_menu_items(menu, menu_translation_table);
    ui_translate_menu_popups(menu, popup_translation_table);
    SetMenu(hwnd,menu);
    uikeyboard_menu_shortcuts(menu);
    ShowWindow(hwnd, winmain_cmd_show);
    canvas->client_hwnd = NULL; /* disabled for DDraw interface */
}

/*  Create a child Window for the DX9 rendering.  */
void ui_canvas_child_window(video_canvas_t *canvas, int enable)
{
    if (canvas->client_hwnd == NULL) {
        canvas->client_hwnd = CreateWindowEx(WS_EX_NOPARENTNOTIFY, 
                                             APPLICATION_CLASS,
                                             TEXT(""),
                                             WS_VISIBLE | WS_CHILD,
                                             0,
                                             0,
                                             CW_USEDEFAULT,
                                             CW_USEDEFAULT,
                                             canvas->hwnd,
                                             NULL,
                                             winmain_instance,
                                             NULL);
    }

    if (enable) {
        ShowWindow(canvas->client_hwnd, SW_SHOW);
    } else {
        ShowWindow(canvas->client_hwnd, SW_HIDE);
    }
    ui_set_render_window(canvas, 0);
}

void ui_make_resizable(video_canvas_t *canvas, int enable)
{
    DWORD style;

    style = GetWindowLong(canvas->hwnd, GWL_STYLE);
    if (enable) {
        style |= WS_SIZEBOX;
    } else {
        style &= ~WS_SIZEBOX;
    }
    SetWindowLong(canvas->hwnd, GWL_STYLE, style);
    SetWindowPos(canvas->hwnd, NULL, 0, 0, 0, 0, 
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

void ui_handle_aspect_ratio(int window_index, WPARAM wparam, LPARAM lparam)
{
    int keep_aspect_ratio, true_aspect_ratio;
    int aspect_ratio;
    double canvas_aspect_ratio;
    RECT *rc = (RECT *)lparam;
    HWND window = window_handles[window_index];
    int dx = window_padding_x[window_index];
    int dy = window_padding_y[window_index];
    double size_x_desired = rc->right - rc->left - dx;
    double size_y_desired = rc->bottom - rc->top - dy;
    video_canvas_t *canvas;

    resources_get_int("KeepAspectRatio", &keep_aspect_ratio);

    if (keep_aspect_ratio == 0) {
        return;
    }

    canvas = video_canvas_for_hwnd(window);

    resources_get_int("TrueAspectRatio", &true_aspect_ratio);
    if (true_aspect_ratio) {
        aspect_ratio = (int)(canvas->geometry->pixel_aspect_ratio * 1000);
    } else {
        resources_get_int("AspectRatio", &aspect_ratio);
    }
    canvas_aspect_ratio = aspect_ratio / 1000.0 * canvas->width / canvas->height;

    switch (wparam) {
        case WMSZ_TOP:
        case WMSZ_BOTTOM:
            rc->right = (long)(rc->left + dx + size_y_desired * canvas_aspect_ratio + 0.5);
            break;
        case WMSZ_BOTTOMLEFT:
            if (size_x_desired / size_y_desired > canvas_aspect_ratio) {
                rc->bottom = (long)(rc->top + dy + size_x_desired / canvas_aspect_ratio + 0.5);
            } else {
                rc->left = (long)(rc->right - dx - size_y_desired * canvas_aspect_ratio + 0.5);
            }
            break;
        case WMSZ_BOTTOMRIGHT:
            if (size_x_desired / size_y_desired > canvas_aspect_ratio) {
                rc->bottom = (long)(rc->top + dy + size_x_desired / canvas_aspect_ratio + 0.5);
            } else {
                rc->right = (long)(rc->left + dx + size_y_desired * canvas_aspect_ratio + 0.5);
            }
            break;
        case WMSZ_LEFT:
        case WMSZ_RIGHT:
            rc->bottom = (long)(rc->top + dy + size_x_desired / canvas_aspect_ratio + 0.5);
            break;
        case WMSZ_TOPLEFT:
            if (size_x_desired / size_y_desired > canvas_aspect_ratio) {
                rc->top = (long)(rc->bottom - dy - size_x_desired / canvas_aspect_ratio + 0.5);
            } else {
                rc->left = (long)(rc->right - dx - size_y_desired * canvas_aspect_ratio + 0.5);
            }
            break;
        case WMSZ_TOPRIGHT:
            if (size_x_desired / size_y_desired > canvas_aspect_ratio) {
                rc->top = (long)(rc->bottom - dy - size_x_desired / canvas_aspect_ratio + 0.5);
            } else {
                rc->right = (long)(rc->left + dx + size_y_desired * canvas_aspect_ratio + 0.5);
            }
            break;
        default:
            break;
    }
}

/* Resize `w' so that the client rectangle is of the requested size.  */
void ui_resize_canvas_window(video_canvas_t *canvas)
{
    RECT wrect;
    int window_index;
    WINDOWPLACEMENT place;
    HWND w, cw;
    unsigned int width, height;
    DWORD adjust_style;
    int aspect_ratio, true_aspect_ratio, keep_aspect_ratio;

    w = canvas->hwnd;
    cw = canvas->client_hwnd;
    width = canvas->width;
    height = canvas->height;

    if (video_dx9_enabled()) {
        resources_get_int("KeepAspectRatio", &keep_aspect_ratio);
        if (keep_aspect_ratio) {
            resources_get_int("TrueAspectRatio", &true_aspect_ratio);
            if (true_aspect_ratio) {
                aspect_ratio = (int)(canvas->geometry->pixel_aspect_ratio * 1000);
            } else {
                resources_get_int("AspectRatio", &aspect_ratio);
            }
            width = (int)((double)width * aspect_ratio / 1000.0 + 0.5);
        }
    }

/*  TODO:
    We should store the windowplacement when the window is
    maximized and we switch to fullscreen, and resume it when
    we are switching back to windowed mode... If the canvas
    size should be changed while in fullscreen (mode changes whatever)
    then this cached data should be updated....
*/
//    if (IsFullscreenEnabled()) { return; }

    for (window_index = 0; window_index < number_of_windows; window_index++) {
        if (window_handles[window_index] == w) {
            break;
        }
    }
    place.length = sizeof(WINDOWPLACEMENT);
    GetWindowPlacement(w, &place);

    window_canvas_xsize[window_index] = width;
    window_canvas_ysize[window_index] = height;

    GetClientRect(w, &wrect);
    ClientToScreen(w, (LPPOINT)&wrect);
    ClientToScreen(w, ((LPPOINT)&wrect) + 1);
    wrect.right = wrect.left + width;
    wrect.bottom = wrect.top + height + statusbar_get_status_height();
    adjust_style = WS_CAPTION | WS_BORDER | WS_DLGFRAME | (GetWindowLong(w, GWL_STYLE) & WS_SIZEBOX);
    AdjustWindowRect(&wrect, adjust_style, TRUE);
    window_padding_x[window_index] = wrect.right - wrect.left - width;
    window_padding_y[window_index] = wrect.bottom - wrect.top - height;

    if (place.showCmd == SW_SHOWNORMAL) {
        MoveWindow(w, wrect.left, wrect.top, wrect.right - wrect.left, wrect.bottom - wrect.top, TRUE);
        if (cw != 0) {
            MoveWindow(cw, 0, 0, width, height, TRUE);
        }
    } else {
        place.rcNormalPosition.right = place.rcNormalPosition.left + wrect.right - wrect.left;
        place.rcNormalPosition.bottom = place.rcNormalPosition.top + wrect.bottom - wrect.top;
        SetWindowPlacement(w, &place);
        InvalidateRect(w, NULL, FALSE);
    }
}

static void ui_resize_render_window(video_canvas_t *canvas)
{
    RECT wrect;

    if (canvas == NULL || canvas->hwnd == NULL || canvas->render_hwnd == NULL) {
        return;
    }

    GetClientRect(canvas->hwnd, &wrect);
    MoveWindow(canvas->render_hwnd, 0, 0, wrect.right - wrect.left, wrect.bottom - wrect.top - statusbar_get_status_height(), TRUE);
}

void ui_set_alwaysontop(int alwaysontop)
{
    int i;

    for (i = 0; i < number_of_windows; i++) {
        SetWindowPos(window_handles[i], alwaysontop ? HWND_TOPMOST : HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    }
}

static const ui_menu_toggle_t *machine_specific_toggles = NULL;
static const ui_res_value_list_t *machine_specific_values = NULL;

/* Update all the menus according to the current settings.  */
void ui_update_menus(void)
{
}

void ui_update_menu(void)
{
    translated_menu = LoadMenu(winmain_instance, MAKEINTRESOURCE(emu_menu));
    if (menu_translation_table != NULL) {
        ui_translate_menu_items(translated_menu, menu_translation_table);
        ui_translate_menu_popups(translated_menu, popup_translation_table);
        uikeyboard_menu_shortcuts(translated_menu);
    }
    ui_show_menu();
}

void ui_show_menu(void)
{
    int i;

    for (i = 0; i < number_of_windows; i++) {
        /* Avoid to create a menu in fullscreen mode */
        if (GetMenu(window_handles[i]) != NULL) {
            SetMenu(window_handles[i], translated_menu);
        }
    }
}


void ui_register_menu_toggles(const ui_menu_toggle_t *toggles)
{
    machine_specific_toggles = toggles;
}

void ui_register_res_values(const ui_res_value_list_t *valuelist)
{
    machine_specific_values = valuelist;
}

static void update_menus(HWND hwnd)
{
    unsigned int i, j;
    int value;
    int result;
    const char *lang;
    HMENU menu = GetMenu(hwnd);

    for (i = 0; grayed_list_res[i].name != NULL; i++) {
        resources_get_int(grayed_list_res[i].name, &value);
        EnableMenuItem(menu, grayed_list_res[i].item_id, value ? MF_GRAYED : MF_ENABLED);
    }

    for (i = 0; grayed_list_machine[i].machine_class != 0; i++) {
        if (machine_class == grayed_list_machine[i].machine_class) {
            EnableMenuItem(menu, grayed_list_machine[i].item_id, MF_GRAYED);
        }
    }

    for (i = 0; toggle_list[i].name != NULL; i++) {
        resources_get_int(toggle_list[i].name, &value);
        CheckMenuItem(menu, toggle_list[i].item_id, value ? MF_CHECKED : MF_UNCHECKED);
    }
    
    if (machine_specific_toggles) {
        for (i = 0; machine_specific_toggles[i].name != NULL; i++) {
            resources_get_int(machine_specific_toggles[i].name, &value);
            CheckMenuItem(menu, machine_specific_toggles[i].item_id, value ? MF_CHECKED : MF_UNCHECKED);
        }
    }

    for (i = 0; value_list[i].name != NULL; i++) {
        result = resources_get_int(value_list[i].name, &value);
        if (result == 0) {
            unsigned int checked = 0;

            CheckMenuItem(menu, value_list[i].default_item_id, MF_UNCHECKED);
            for (j = 0; value_list[i].vals[j].item_id != 0; j++) {
                if (value == value_list[i].vals[j].value && !checked) {
                    CheckMenuItem(menu, value_list[i].vals[j].item_id, MF_CHECKED);
                    checked = 1;
                } else {
                    CheckMenuItem(menu, value_list[i].vals[j].item_id, MF_UNCHECKED);
                }
            }
            if (checked == 0 && value_list[i].default_item_id > 0) {
                CheckMenuItem(menu, value_list[i].default_item_id, MF_CHECKED);
            }
        }
    }

    if (machine_specific_values) {
        for (i = 0; machine_specific_values[i].name != NULL; i++) {
            result = resources_get_int(machine_specific_values[i].name, &value);
            if (result == 0) {
                for (j = 0; machine_specific_values[i].vals[j].item_id != 0; j++) {
                    if (value == machine_specific_values[i].vals[j].value) {
                        CheckMenuItem(menu, machine_specific_values[i].vals[j].item_id, MF_CHECKED);
                    } else {
                        CheckMenuItem(menu, machine_specific_values[i].vals[j].item_id, MF_UNCHECKED);
                    }
                }
            }
        }
    }
    CheckMenuItem(menu, IDM_PAUSE, ui_emulation_is_paused() ? MF_CHECKED : MF_UNCHECKED);

    resources_get_string("Language", &lang);
    for (i = 0; (ui_lang_menu_entries[i].lang_code != NULL) && (i < countof(ui_lang_menu_entries)); i++) {
        if (strcmp(lang, ui_lang_menu_entries[i].lang_code) == 0) {
            CheckMenuItem(menu, ui_lang_menu_entries[i].item_id, MF_CHECKED);
        } else {
            CheckMenuItem(menu, ui_lang_menu_entries[i].item_id, MF_UNCHECKED);
        }
    }
}

static void ui_set_language(unsigned int lang_id)
{
    unsigned int i;

    for (i = 0; (ui_lang_menu_entries[i].lang_code != NULL) && (i < countof(ui_lang_menu_entries)); i++) {
        if (ui_lang_menu_entries[i].item_id == lang_id) {
            resources_set_string("Language", ui_lang_menu_entries[i].lang_code);
            break;
        }
    }
}

/* ------------------------------------------------------------------------- */

static ui_machine_specific_t ui_machine_specific = NULL;

void ui_register_machine_specific(ui_machine_specific_t func)
{
    ui_machine_specific = func;
}

/* ------------------------------------------------------------------------- */

/* Report an error to the user (`printf()' style).  */
void ui_error(const char *format, ...)
{
    char *tmp;
    TCHAR *st;
    va_list args;

    va_start(args, format);
    tmp = lib_mvsprintf(format, args);
    va_end(args);

    log_debug(tmp);
    st = system_mbstowcs_alloc(tmp);
    ui_messagebox(st, translate_text(IDS_VICE_ERROR), MB_OK | MB_ICONSTOP);
    system_mbstowcs_free(st);
    vsync_suspend_speed_eval();
    lib_free(tmp);
}

/* Report an error to the user (one string).  */
void ui_error_string(const char *text)
{
    TCHAR *st;

    log_debug(text);
    st = system_mbstowcs_alloc(text);
    ui_messagebox(st, translate_text(IDS_VICE_ERROR), MB_OK | MB_ICONSTOP);
    system_mbstowcs_free(st);
}

/* Report a message to the user (`printf()' style).  */
void ui_message(const char *format, ...)
{
    char *tmp;
    TCHAR *st;
    va_list args;

    va_start(args, format);
    tmp = lib_mvsprintf(format, args);
    va_end(args);

    st = system_mbstowcs_alloc(tmp);
    ui_messagebox(st, translate_text(IDS_VICE_INFORMATION), MB_OK | MB_ICONASTERISK);
    system_mbstowcs_free(st);
    vsync_suspend_speed_eval();
    lib_free(tmp);
}

/* Let the user browse for a filename */
char *ui_get_file(const char *format,...)
{
    char *tmp;
    char *st;
    va_list args;

    va_start(args, format);
    tmp = lib_mvsprintf(format, args);
    va_end(args);

    st = uilib_select_file(NULL, tmp, UILIB_FILTER_ALL, UILIB_SELECTOR_TYPE_FILE_LOAD, UILIB_SELECTOR_STYLE_DISK);
    lib_free(tmp);

    return st;
}

/* Handle the "CPU JAM" case.  */
ui_jam_action_t ui_jam_dialog(const char *format,...)
{
    char *txt, *txt2;
    TCHAR *st;
    int ret;

    va_list ap;
    va_start(ap, format);
    txt = lib_mvsprintf(format, ap);
    va_end(ap);
    txt2 = lib_msprintf(translate_text(IDS_START_MONITOR), txt);
    st = system_mbstowcs_alloc(txt2);
    ret = ui_messagebox(st, translate_text(IDS_VICE_CPU_JAM), MB_YESNOCANCEL);
    system_mbstowcs_free(st);
    lib_free(txt2);
    lib_free(txt);
    switch (ret) {
        case IDYES:
            return UI_JAM_MONITOR;
        case IDNO:
            return UI_JAM_HARD_RESET;
        case IDCANCEL:
            return UI_JAM_NONE;
    }
    return UI_JAM_NONE;
}

/* Handle the "Do you want to extend the disk image to 40-track format"?
   dialog.  */
int ui_extend_image_dialog(void)
{
    int ret;

    ret = ui_messagebox(translate_text(IDS_EXTEND_TO_40_TRACKS), translate_text(IDS_VICE_QUESTION), MB_YESNO | MB_ICONQUESTION);
    return ret == IDYES;
}

/* ------------------------------------------------------------------------- */
static int is_paused = 0;

static void pause_trap(WORD addr, void *data)
{
    ui_display_paused(1);
    vsync_suspend_speed_eval();
    while (is_paused) {
        Sleep(10);
        ui_dispatch_next_event();
    }
}

void ui_pause_emulation(void)
{
    if (network_connected()) {
        return;
    }

    is_paused = is_paused ? 0 : 1;
    if (is_paused) {
        interrupt_maincpu_trigger_trap(pause_trap, 0);
    } else {
        ui_display_paused(pause_pending);
    }
}

int ui_emulation_is_paused(void)
{
    return is_paused;
}

/* ------------------------------------------------------------------------- */
/* Display the current emulation speed.  */
static int statustext_display_time = 0;

void ui_display_speed(float percent, float framerate, int warp_flag)
{
    char *buf, *title;
    TCHAR *st_buf;
    int index;

    for (index = 0; index < number_of_windows; index++) {
        title = system_wcstombs_alloc(hwnd_titles[index]);

        buf = lib_msprintf(intl_speed_at_text, title, (int)(percent + .5), (int)(framerate + .5), warp_flag ? " (warp)" : "");
        system_wcstombs_free(title);
        st_buf = system_mbstowcs_alloc(buf);
        SetWindowText(window_handles[index], st_buf);
        system_mbstowcs_free(st_buf);

        lib_free(buf);
    }
    
    if (statustext_display_time > 0) {
        statustext_display_time--;
        if (statustext_display_time == 0) {
            statusbar_setstatustext("");
        }
    }
}


void ui_display_statustext(const char *text, int fade_out)
{
    statusbar_setstatustext(text);
    if (fade_out > 0) {
        statustext_display_time = 5;
    } else {
        statustext_display_time = 0;
    }
}

/* ------------------------------------------------------------------------- */
/* Dispay the drive status.  */

void ui_enable_drive_status(ui_drive_enable_t enable, int *drive_led_color)
{
    statusbar_enable_drive_status(enable,drive_led_color);
}

/* Toggle displaying of the drive track.  */
/* drive_base is either 8 or 0 depending on unit or drive display.
   Dual drives display drive 0: and 1: instead of unit 8: and 9: */
void ui_display_drive_track(unsigned int drive_number, unsigned int drive_base, unsigned int half_track_number)
{
    double track_number = (double)half_track_number / 2.0;

    statusbar_display_drive_track(drive_number, drive_base, track_number);
}

/* Toggle displaying of the drive LED.  */
void ui_display_drive_led(int drivenum, unsigned int led_pwm1, unsigned int led_pwm2)
{
    statusbar_display_drive_led(drivenum, led_pwm1);
}

/* display current image */
void ui_display_drive_current_image(unsigned int drivenum, const char *image)
{
    char *directory_name, *image_name, *text;
    char device_str[4];

    if (image == NULL || image[0] == 0) {
        text = lib_msprintf(translate_text(IDS_DETACHED_DEVICE_S), itoa(drivenum + 8, device_str, 10));
    } else {
        util_fname_split(image, &directory_name, &image_name);
        text = lib_msprintf(translate_text(IDS_ATTACHED_S_TO_DEVICE_S), image_name, itoa(drivenum + 8, device_str, 10));
        lib_free(image_name);
        lib_free(directory_name);
    }

    ui_display_statustext(text, 1);
    lib_free(text);
}

/* ------------------------------------------------------------------------- */

/* Dispay the tape status.  */
void ui_set_tape_status(int tape_status)
{
    statusbar_set_tape_status(tape_status);
}

void ui_display_tape_motor_status(int motor)
{   
    statusbar_display_tape_motor_status(motor);
}

void ui_display_tape_control_status(int control)
{
    statusbar_display_tape_control_status(control);
}

void ui_display_tape_counter(int counter)
{
    statusbar_display_tape_counter(counter);
}

/* display the attched tape image */
void ui_display_tape_current_image(const char *image)
{
    char *directory_name, *image_name, *text;

    if (image == NULL || image[0] == 0) {
        text = lib_stralloc(translate_text(IDS_DETACHED_TAPE));
    } else {
        util_fname_split(image, &directory_name, &image_name);
        text = lib_msprintf(translate_text(IDS_ATTACHED_TAPE_S), image_name);
        lib_free(image_name);
        lib_free(directory_name);
    }

    ui_display_statustext(text, 1);
    lib_free(text);
}

/* ------------------------------------------------------------------------- */

/* Display the recording/playback status.  */
void ui_display_recording(int recording_status)
{
    if (recording_status) {
        statusbar_event_status(EVENT_RECORDING);
    } else {
        statusbar_event_status(EVENT_OFF);
    }
}

void ui_display_playback(int playback_status, char *version)
{
    char st[256];

    if (playback_status) {
        statusbar_event_status(EVENT_PLAYBACK);
        if (version == NULL || version[0] == 0) {
            sprintf(st, translate_text(IDS_HISTORY_RECORDED_UNKNOWN));
        } else {
            sprintf(st, translate_text(IDS_HISTORY_RECORDED_VICE_S), version);
        }
        ui_display_statustext(st, 1);
    } else {
        statusbar_event_status(EVENT_OFF);
    }
}

void ui_display_event_time(unsigned int current, unsigned int total)
{
    statusbar_event_time(current, total);
}

/* ------------------------------------------------------------------------- */

/* Dispay the joystick status.  */
static BYTE ui_joyport[3] = { 0, 0, 0 };

void ui_display_joyport(BYTE *joyport)
{
    if (ui_joyport[1] != joyport[1] || ui_joyport[2] != joyport[2]) {
        ui_joyport[1] = joyport[1];
        ui_joyport[2] = joyport[2];
        statusbar_display_joyport(ui_joyport);
    }
}

/* ------------------------------------------------------------------------- */

/* Toggle displaying of paused state.  */
void ui_display_paused(int flag)
{
    int index;
    char *buf, *title;
    TCHAR *st_buf;

    for (index = 0; index < number_of_windows; index++) {
        title = system_wcstombs_alloc(hwnd_titles[index]);
        if (flag) {
            buf = lib_msprintf("%s (%s: %s%i)", title, translate_text(IDS_PAUSED), translate_text(IDS_FRAME_NUMBER), vsync_frame_counter);
        } else {
            buf = lib_msprintf("%s (%s)", title, translate_text(IDS_RESUMED));
        }
        system_wcstombs_free(title);
        st_buf = system_mbstowcs_alloc(buf);
        SetWindowText(window_handles[index], st_buf);
        system_mbstowcs_free(st_buf);
        lib_free(buf);
    }
}

ui_button_t ui_ask_confirmation(const char *title, const char *text)
{
    return UI_BUTTON_NONE;
}

/* ------------------------------------------------------------------------ */

/* Return the main window handler.  */
HWND ui_get_main_hwnd(void)
{
    if (window_handles[0] == NULL) {
        return main_hwnd;
    }

    return window_handles[0];
}

/* Dispatch the next pending event, if any.  Otherwise, just return.  */
void ui_dispatch_next_event(void)
{
    MSG msg;

    if (!GetMessage(&msg, NULL, 0, 0)) {
        exit((int)msg.wParam);
    }
    if (ui_accelerator) {
        if (!TranslateAccelerator(msg.hwnd, ui_accelerator, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    } else {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

/* Dispatch all the current pending events; return as soon as no more events
   are pending.  */
void ui_dispatch_events(void)
{
    MSG msg;

    /* this function is called once a frame, so this
       handles single frame advance */
    if (pause_pending) {
        ui_pause_emulation();
        pause_pending = 0;
    }

    while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
        ui_dispatch_next_event();
    }
}

/* ------------------------------------------------------------------------ */

static void reset_dialog_proc(WPARAM wparam)
{
    vsync_suspend_speed_eval();
    if ((wparam & 0xffff) == IDM_RESET_HARD) {
        machine_trigger_reset(MACHINE_RESET_MODE_HARD);
    } else {
        machine_trigger_reset(MACHINE_RESET_MODE_SOFT);
    }
}

/* ------------------------------------------------------------------------ */

static void ui_copy_clipboard(HWND window)
{
    BOOL clipboard_is_open = FALSE;
    char * text = NULL;
    HGLOBAL globaltext = NULL;

    do {
        char * p;

        if ( ! OpenClipboard(window) ) {
            break;
        }
        clipboard_is_open = TRUE;

        if ( ! EmptyClipboard() ) {
            break;
        }

        text = clipboard_read_screen_output("\r\n");
        if (text == NULL) {
            break;
        }

        globaltext = GlobalAlloc(GMEM_DDESHARE, strlen(text) + 1);
        if (globaltext == NULL) {
            break;
        }

        p = GlobalLock(globaltext);
        strcpy(p, text);

        SetClipboardData(CF_TEXT, globaltext);

    } while (0);

    if (globaltext) {
        GlobalUnlock(globaltext);
    }

    lib_free(text);

    if (clipboard_is_open) {
        CloseClipboard();
    }
}

static void ui_paste_clipboard_text(HWND window)
{
    HANDLE hdata;
    BOOL clipboard_is_open = FALSE;
    char *text = NULL;
    char *text_in_petscii = NULL;
    
    do {
        DWORD size;

        if ( ! OpenClipboard(window) ) {
            break;
        }

        clipboard_is_open = TRUE;

        hdata = GetClipboardData(CF_TEXT);

        if ( ! hdata ) {
            break;
        }

        text = GlobalLock(hdata);

        if (text == NULL) {
            break;
        }

        size = (DWORD)GlobalSize(hdata);

        if (size < 1) {
            break;
        }

        /*
         * Allocate memmory for the string to convert in petscii.
         * Note: As we are not sure if the original text is null-terminated,
         *       do *not* use lib_stralloc()!
         */
        text_in_petscii = lib_malloc(size + 1);

        if (text_in_petscii == NULL) {
            break;
        }

        memcpy(text_in_petscii, text, size);
        text_in_petscii[size] = 0;

        charset_petconvstring(text_in_petscii, 0);

        kbdbuf_feed(text_in_petscii);

    } while (0);

    lib_free(text_in_petscii);

    if (text) {
        GlobalUnlock(text);
    }

    if (clipboard_is_open) {
        CloseClipboard();
    }
}


/* ------------------------------------------------------------------------ */

/* FIXME: tmp hack.  */
int syscolorchanged, displaychanged, querynewpalette, palettechanged;

static void handle_default_command(WPARAM wparam, LPARAM lparam, HWND hwnd)
{
    int i, j, command_found = 0;

    for (i = 0; toggle_list[i].name != NULL && !command_found; i++) {
        if (toggle_list[i].item_id == wparam) {
            resources_toggle(toggle_list[i].name, NULL);
            command_found = 1;
        }
    }

    if (machine_specific_toggles) {
        for (i = 0; machine_specific_toggles[i].name != NULL && !command_found; i++) {
            if (machine_specific_toggles[i].item_id == wparam) {
                resources_toggle(machine_specific_toggles[i].name, NULL);
                command_found = 1;
            }
        }
    }

    for (i = 0; value_list[i].name != NULL && !command_found; i++) {
        for (j = 0; value_list[i].vals[j].item_id != 0 && !command_found; j++) {
            if (value_list[i].vals[j].item_id == wparam) {
                resources_set_int(value_list[i].name, value_list[i].vals[j].value);
                command_found = 1;
            }
        }
    }

    if (machine_specific_values) {
        for (i = 0; machine_specific_values[i].name != NULL && !command_found; i++) {
            for (j = 0; machine_specific_values[i].vals[j].item_id != 0 && !command_found; j++) {
                if (machine_specific_values[i].vals[j].item_id == wparam) {
                    resources_set_int(machine_specific_values[i].name, machine_specific_values[i].vals[j].value);
                    command_found = 1;
                }
            }
        }
    }
}

static void handle_wm_initmenupopup(HMENU menu)
{
    /* enable PASTE iff the clipboard contains "our" format: */

    EnableMenuItem(menu, IDM_EDIT_PASTE, MF_BYCOMMAND | ( IsClipboardFormatAvailable(CF_TEXT) ? MF_ENABLED : MF_GRAYED));
}

static void handle_wm_command(WPARAM wparam, LPARAM lparam, HWND hwnd)
{
    TCHAR *st_name;

    wparam &= 0xffff;
    /* Handle machine specific commands first.  */
    if (ui_machine_specific) {
        ui_machine_specific(wparam, hwnd);
    }

    switch (wparam) {
        case IDM_DEVICEMANAGER:
        case IDM_FORMFEED_PRINTERIEC4:
        case IDM_FORMFEED_PRINTERIEC5:
            uiperipheral_command(hwnd, wparam);
            break;
        case IDM_EXIT:
            PostMessage(hwnd, WM_CLOSE, wparam, lparam);
            break;
        case IDM_EDIT_COPY:
            ui_copy_clipboard(hwnd);
            break;
        case IDM_EDIT_PASTE:
            ui_paste_clipboard_text(hwnd);
            break;
        case IDM_ABOUT:
        case IDM_HELP:
        case IDM_CONTRIBUTORS:
        case IDM_LICENSE:
        case IDM_WARRANTY:
        case IDM_CMDLINE:
            uihelp_dialog(hwnd, wparam);
            break;
        case IDM_ATTACH_8:
        case IDM_ATTACH_9:
        case IDM_ATTACH_10:
        case IDM_ATTACH_11:
        case IDM_DETACH_8:
        case IDM_DETACH_9:
        case IDM_DETACH_10:
        case IDM_DETACH_11:
        case IDM_DETACH_ALL:
        case IDM_ATTACH_TAPE:
        case IDM_DETACH_TAPE:
        case IDM_AUTOSTART:
            uiattach_command(hwnd, wparam);
            break;
        case IDM_FLIP_ADD:
        case IDM_FLIP_REMOVE:
        case IDM_FLIP_NEXT:
        case IDM_FLIP_PREVIOUS:
        case IDM_FLIP_LOAD:
        case IDM_FLIP_SAVE:
            uifliplist_command(hwnd, wparam);
            break;
        case IDM_DATASETTE_SETTINGS:
        case IDM_DATASETTE_CONTROL_STOP:
        case IDM_DATASETTE_CONTROL_START:
        case IDM_DATASETTE_CONTROL_FORWARD:
        case IDM_DATASETTE_CONTROL_REWIND:
        case IDM_DATASETTE_CONTROL_RECORD:
        case IDM_DATASETTE_CONTROL_RESET:
        case IDM_DATASETTE_RESET_COUNTER:
            uidatasette_command(hwnd, wparam);
            break;
        case IDM_SNAPSHOT_LOAD:
            ui_snapshot_load(hwnd);
            break;
        case IDM_SNAPSHOT_SAVE:
            ui_snapshot_save(hwnd);
            break;
        case IDM_SAVEQUICK:
            ui_quicksnapshot_save(hwnd);
            break;
        case IDM_LOADQUICK:
            ui_quicksnapshot_load(hwnd);
            break;
        case IDM_MEDIAFILE:
            SuspendFullscreenModeKeep(hwnd);
            ui_mediafile_save_dialog(hwnd);
            ResumeFullscreenModeKeep(hwnd);
            break;
        case IDM_SINGLE_FRAME_ADVANCE:
            pause_pending = 1;
            if (!is_paused) {
                break;
            }
            // fall through
        case IDM_PAUSE:
            ui_pause_emulation();
            break;
        case IDM_MONITOR:
            if (!ui_emulation_is_paused()) {
                monitor_startup_trap();
            }
            break;
        case IDM_RESET_HARD:
        case IDM_RESET_SOFT:
            reset_dialog_proc(wparam);
            break;
        case IDM_RESET_DRIVE8:
            vsync_suspend_speed_eval();
            drivecpu_trigger_reset(0);
            break;
        case IDM_RESET_DRIVE9:
            vsync_suspend_speed_eval();
            drivecpu_trigger_reset(1);
            break;
        case IDM_RESET_DRIVE10:
            vsync_suspend_speed_eval();
            drivecpu_trigger_reset(2);
            break;
        case IDM_RESET_DRIVE11:
            vsync_suspend_speed_eval();
            drivecpu_trigger_reset(3);
            break;
        case IDM_MAXIMUM_SPEED_CUSTOM:
            ui_speed_settings_dialog(hwnd);
            break;
        case IDM_SWAP_JOYSTICK:
            if (machine_class == VICE_MACHINE_CBM6x0) {
                ui_joystick_swap_extra_joystick();
            } else {
                ui_joystick_swap_joystick();
            }
            break;
        case IDM_SWAP_EXTRA_JOYSTICK:
            ui_joystick_swap_extra_joystick();
            break;
        case IDM_AUTOSTART_SETTINGS:
            ui_autostart_settings_dialog(hwnd);
            break;
        case IDM_SOUND_SETTINGS:
            ui_sound_settings_dialog(hwnd);
            break;
        case IDM_RAM_SETTINGS:
            ui_ram_settings_dialog(hwnd);
            break;
        case IDM_TOGGLE_FULLSCREEN:
            vsync_suspend_speed_eval();
            SwitchFullscreenMode(hwnd);
            break;
        case IDM_SETTINGS_SAVE_FILE:
            if ((st_name = uilib_select_file(hwnd, translate_text(IDS_SAVE_CONFIG_FILE), UILIB_FILTER_ALL, UILIB_SELECTOR_TYPE_FILE_SAVE, UILIB_SELECTOR_STYLE_DEFAULT)) != NULL) {
                char *name;

                name = system_wcstombs_alloc(st_name);

                if (resources_save(st_name) < 0) {
                    ui_error(translate_text(IDS_CANNOT_SAVE_SETTINGS));
                } else {
                    ui_message(translate_text(IDS_SETTINGS_SAVED_SUCCESS));
                }
                uifliplist_save_settings();
                system_wcstombs_free(name);
                lib_free(st_name);
            }
            break;
        case IDM_SETTINGS_LOAD_FILE:
            if ((st_name = uilib_select_file(hwnd, translate_text(IDS_LOAD_CONFIG_FILE), UILIB_FILTER_ALL, UILIB_SELECTOR_TYPE_FILE_LOAD, UILIB_SELECTOR_STYLE_DEFAULT)) != NULL) {
                char *name;

                name = system_wcstombs_alloc(st_name);

                if (resources_load(st_name) < 0) {
                    ui_error(translate_text(IDS_CANNOT_LOAD_SETTINGS));
                } else {
                    ui_message(translate_text(IDS_SETTINGS_LOADED_SUCCESS));
                }
                uifliplist_save_settings();
                system_wcstombs_free(name);
                lib_free(st_name);
            }
            break;
        case IDM_SETTINGS_SAVE:
            if (resources_save(NULL) < 0) {
                ui_error(translate_text(IDS_CANNOT_SAVE_SETTINGS));
            } else {
                ui_message(translate_text(IDS_SETTINGS_SAVED_SUCCESS));
            }
            uifliplist_save_settings();
            break;
        case IDM_SETTINGS_LOAD:
            if (resources_load(NULL) < 0) {
                ui_error(translate_text(IDS_CANNOT_LOAD_SETTINGS));
            } else {
                ui_message(translate_text(IDS_SETTINGS_LOADED_SUCCESS));
            }
            break;
        case IDM_SETTINGS_DEFAULT:
            resources_set_defaults();
            ui_message(translate_text(IDS_DEFAULT_SETTINGS_RESTORED));
            break;
        case IDM_EVENT_DIRECTORY:
        case IDM_EVENT_TOGGLE_RECORD:
        case IDM_EVENT_TOGGLE_PLAYBACK:
        case IDM_EVENT_SETMILESTONE:
        case IDM_EVENT_RESETMILESTONE:
            uievent_command(hwnd, wparam);
            break;
        case IDM_NETWORK_SETTINGS:
            ui_network_dialog(hwnd);
            break;
        case IDM_RS232_SETTINGS:
            ui_rs232_settings_dialog(hwnd);
            break;
        case IDM_LANG_EN:
        case IDM_LANG_DA:
        case IDM_LANG_DE:
        case IDM_LANG_ES:
        case IDM_LANG_FR:
        case IDM_LANG_HU:
        case IDM_LANG_IT:
        case IDM_LANG_KO:
        case IDM_LANG_NL:
        case IDM_LANG_PL:
        case IDM_LANG_RU:
        case IDM_LANG_SV:
        case IDM_LANG_TR:
            ui_set_language((unsigned int)wparam);
            break;
        case IDM_SOUND_RECORD_START:
            ui_sound_record_settings_dialog(hwnd);
            break;
        case IDM_SOUND_RECORD_STOP:
            resources_set_string("SoundRecordDeviceName", "");
            ui_display_statustext(translate_text(IDS_SOUND_RECORDING_STOPPED), 1);
            break;
        default:
            handle_default_command(wparam, lparam, hwnd);
    }
}

int ui_active = FALSE;
HWND ui_active_window;

/* Window procedure.  All messages are handled here.  */
static LRESULT CALLBACK dummywindowproc(HWND window, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg) {
        case WM_ENABLE:
        case WM_ACTIVATEAPP:
        case WM_ACTIVATE:
        case WM_KILLFOCUS:
        case WM_SETFOCUS:
        case WM_SETREDRAW:
            break;
    }
    return DefWindowProc(window, msg, wparam, lparam);
}

static void ui_wm_move(HWND window, int window_index)
{
    if (window_index<number_of_windows) {
        WINDOWPLACEMENT place;
        RECT rect;

        place.length = sizeof(WINDOWPLACEMENT);
        GetWindowPlacement(window, &place);
        GetWindowRect(window, &rect);
        if (place.showCmd == SW_SHOWNORMAL) {
            resources_set_int_sprintf("Window%dXpos", rect.left, window_index);
            resources_set_int_sprintf("Window%dYpos", rect.top, window_index);
        }
    }
}

static void ui_wm_close(HWND window)
{
    int quit = 1;
    int confirm_on_exit, save_on_exit;

    resources_get_int("ConfirmOnExit", &confirm_on_exit);
    resources_get_int("SaveResourcesOnExit", &save_on_exit);

    SuspendFullscreenModeKeep(window);
    vsync_suspend_speed_eval();
    if (confirm_on_exit) {
        if (MessageBox(window, translate_text(IDS_REALLY_EXIT), TEXT("VICE"), MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2 | MB_TASKMODAL) == IDYES) {
            quit = 1;
        } else {
            quit = 0;
        }
    }

    if (quit) {
        SuspendFullscreenMode(window);
        if (save_on_exit) {
            if (resources_save(NULL) < 0) {
                ui_error(translate_text(IDS_CANNOT_SAVE_SETTINGS));
            }
        }
        DestroyWindow(window);
    } else {
        ResumeFullscreenModeKeep(window);
    }
}

static void ui_wm_dropfiles(HWND window, WPARAM wparam)
{
    char szFile[256];
    HDROP hDrop;

    hDrop = (HDROP)wparam;
    DragQueryFile(hDrop, 0, (char *)&szFile, 256);
    if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
        if (file_system_attach_disk(8, szFile) < 0) {
            ui_error(translate_text(IDS_CANNOT_ATTACH_FILE));
        }
    } else {
        if (autostart_autodetect(szFile, NULL, 0, AUTOSTART_MODE_RUN) < 0) {
            ui_error(translate_text(IDS_CANNOT_AUTOSTART_FILE));
        }
    }
    DragFinish(hDrop);
}

static void ui_redraw_all_windows(void)
{
    int i;

    for (i = 0; i < number_of_windows; i++) {
        InvalidateRect(window_handles[i], NULL, FALSE);
    }
}

/* Window procedure.  All messages are handled here.  */
static LRESULT CALLBACK window_proc(HWND window, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int window_index;

    for (window_index = 0; window_index < number_of_windows; window_index++) {
        if (window_handles[window_index] == window) {
            break;
        }
    }

    switch (msg) {
        case WM_CREATE:
            DragAcceptFiles(window, TRUE);
            return 0;
        case WM_WINDOWPOSCHANGED:
            /* SRT: if focus is changed in full-screen mode, this message is sent 
               Make sure that all windows are repainted.*/
            ui_redraw_all_windows();
            break;
        case WM_SETREDRAW:
            break;
        case WM_KILLFOCUS:
            keyboard_key_clear();
            break;
        case WM_SETFOCUS:
            break;
        case WM_ENABLE:
            break;
        case WM_POWERBROADCAST:
            switch (wparam) {
                case PBT_APMSUSPEND:
                    log_debug("PBT_APMSUSPEND");
                    vsync_suspend_speed_eval();
                    break;
                case PBT_APMRESUMESUSPEND:
                    log_debug("PBT_APMRESUMESUSPEND");
                    vsync_suspend_speed_eval();
                    break;
                case PBT_APMRESUMECRITICAL:
                    log_debug("PBT_APMRESUMECRITICAL");
                    vsync_suspend_speed_eval();
                    break;
            }
            break;
        case WM_ACTIVATEAPP:
            break;
        case WM_ACTIVATE:
            if (wparam == WA_INACTIVE) {
                ui_active = FALSE;
            } else {
                ui_active = TRUE;
                ui_active_window = window;
            }
            mouse_update_mouse_acquire();
            break;
        case WM_SIZE:
            if (window_index<number_of_windows) {
                statusbar_handle_WMSIZE(msg, wparam, lparam, window_index);
            }
            ui_resize_render_window(video_canvas_for_hwnd(window));
            return 0;
        case WM_SIZING:
            ui_handle_aspect_ratio(window_index, wparam, lparam);
            return 0;
        case WM_DRAWITEM:
            statusbar_handle_WMDRAWITEM(wparam,lparam);
            /* SRT: Make sure that all windows are repainted.
               This message seems to be a good candidate for the remote desktop. */
            ui_redraw_all_windows();
            return 0;
        case WM_INITMENUPOPUP:
            handle_wm_initmenupopup((HMENU)wparam);
            break;
        case WM_COMMAND:
            handle_wm_command(wparam, lparam, window);
            return 0;
        case WM_ENTERMENULOOP:
            update_menus(window);
        case WM_ENTERSIZEMOVE:
            vsync_suspend_speed_eval();
            ui_active = FALSE;
            mouse_update_mouse_acquire();
            break;
        case WM_EXITMENULOOP:
        case WM_EXITSIZEMOVE:
            if (GetActiveWindow() == window || !IsIconic(window)) {
                ui_active = TRUE;
            } else {
                ui_active = FALSE;
            }
            mouse_update_mouse_acquire();
            break;
        case WM_MOVE:
            ui_wm_move(window, window_index);
            break;
        case WM_SYSKEYDOWN:
            if (wparam == VK_F10) {
                kbd_handle_keydown((DWORD)wparam, (DWORD)lparam);
                return 0;
            }
            break;
        case WM_KEYDOWN:
            kbd_handle_keydown((DWORD)wparam, (DWORD)lparam);
            return 0;
        case WM_SYSKEYUP:
            kbd_handle_keyup((DWORD)wparam, (DWORD)lparam);
            if (wparam == VK_F10) {
                return 0;
            }
            break;
        case WM_KEYUP:
            kbd_handle_keyup((DWORD)wparam, (DWORD)lparam);
            return 0;
        case WM_SYSCOLORCHANGE:
            syscolorchanged = 1;
            break;
        case WM_DISPLAYCHANGE:
            displaychanged = 1;
            break;
        case WM_QUERYNEWPALETTE:
            querynewpalette = 1;
            break;
        case WM_PALETTECHANGED:
            if ((HWND)wparam != window) {
                palettechanged = 1;
            }
            break;
        case WM_CLOSE:
            ui_wm_close(window);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_ERASEBKGND:
            return 1;
        case WM_DROPFILES:
            ui_wm_dropfiles(window, wparam);
            return 0;
        case WM_PAINT:
            {
                RECT update_rect;

                if (GetUpdateRect(window, &update_rect, FALSE)) {
                    PAINTSTRUCT ps;
                    HDC hdc;

                    hdc = BeginPaint(window, &ps);

                    video_canvas_update(window, hdc, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right - ps.rcPaint.left, ps.rcPaint.bottom - ps.rcPaint.top);

                    EndPaint(window, &ps);
                    return 0;
                } else {
                    break;
                }
            }
        case WM_SYSCOMMAND:
        case WM_NCLBUTTONDOWN:
            vsync_suspend_speed_eval();
            break;
        case WM_MOUSEMOVE:
            _mouse_x = (int)((lparam & 0xFFFF) * 4);
            _mouse_y = (int)(((lparam >> 16) & 0xFFFF) * 4);
            _mouse_timestamp = vsyncarch_gettime();
            break;
        case WM_LBUTTONDOWN:
            if (_mouse_enabled) {
                mouse_button_left(1);
            }
            break;
        case WM_RBUTTONDOWN:
            if (_mouse_enabled) {
                mouse_button_right(1);
            } else {
                ui_paste_clipboard_text(window);
            }
            break;
        case WM_LBUTTONUP:
            if (_mouse_enabled) {
                mouse_button_left(0);
            }
            break;
        case WM_RBUTTONUP:
            if (_mouse_enabled) {
                mouse_button_right(0);
            }
            break;
        case WM_NOTIFY:
            statusbar_notify(window, window_index, wparam, lparam);
            break;
        case WM_NCACTIVATE:
            if (IsFullscreenEnabled() && fullscreen_get_nesting_level() == 0) {
                return 0;
            }
    }

    return DefWindowProc(window, msg, wparam, lparam);
}

/*
 The following shows a messagebox on the screen.
 It first searches the current active window of VICE, and then 
 suspends fullscreen mode, shows the messagebox, and then resumes
 fullscreen mode.
 If it can't find the current active window of VICE (e.g., no one
 is currently active), it does not suspend and resume fullscreen
 mode. This should be correct because when fullscreen, that window
 has to be active.
*/
int ui_messagebox(LPCTSTR lpText, LPCTSTR lpCaption, UINT uType)
{
    int ret;
    HWND hWnd = NULL;
    
    if (number_of_windows == 1) {
        /* we only have one window, so use that one */
        hWnd = window_handles[0];
    } else {
        int window_index;
        HWND hWndActive = GetActiveWindow();

        for (window_index = 0; window_index < number_of_windows; window_index++) {
            if (window_handles[window_index] == hWndActive) {
                hWnd = hWndActive;
                break;
            }
        }
    }

    if (hWnd != NULL) {
        SuspendFullscreenModeKeep(hWnd);
    }

    ret = MessageBox(hWnd, lpText, lpCaption, uType);

    if (hWnd != NULL) {
        ResumeFullscreenModeKeep(hWnd);
    }

    return ret;
}

void ui_display_volume(int vol)
{
    statusbar_display_volume(vol);
}

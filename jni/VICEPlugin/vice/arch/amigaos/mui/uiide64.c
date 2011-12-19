/*
 * uiide64.c
 *
 * Written by
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
#ifdef AMIGA_M68K
#define _INLINE_MUIMASTER_H
#endif
#include "mui.h"

#include "uiide64.h"
#include "intl.h"
#include "translate.h"

static video_canvas_t *ide64_canvas;

static int ui_ide64_autodetect_translate[] = {
    IDMS_DISABLED,
    IDS_ENABLED,
    0
};

static char *ui_ide64_autodetect[countof(ui_ide64_autodetect_translate)];

static const int ui_ide64_autodetect_values[] = {
    0,
    1,
    -1
};

static int ui_cylinders_range[] = {
    1,
    1024
};

static int ui_heads_range[] = {
    1,
    16
};

static int ui_sectors_range[] = {
    1,
    63
};

static ui_to_from_t ui_to_from_v4[] = {
    { NULL, MUI_TYPE_CYCLE, "IDE64version4", ui_ide64_autodetect, ui_ide64_autodetect_values, NULL },
    UI_END /* mandatory */
};

static ui_to_from_t ui_to_from1[] = {
    { NULL, MUI_TYPE_FILENAME, "IDE64Image1", NULL, NULL, NULL },
    { NULL, MUI_TYPE_CYCLE, "IDE64AutodetectSize1", ui_ide64_autodetect, ui_ide64_autodetect_values, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Cylinders1", NULL, ui_cylinders_range, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Heads1", NULL, ui_heads_range, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Sectors1", NULL, ui_sectors_range, NULL },
    UI_END /* mandatory */
};

static ui_to_from_t ui_to_from2[] = {
    { NULL, MUI_TYPE_FILENAME, "IDE64Image2", NULL, NULL, NULL },
    { NULL, MUI_TYPE_CYCLE, "IDE64AutodetectSize2", ui_ide64_autodetect, ui_ide64_autodetect_values, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Cylinders2", NULL, ui_cylinders_range, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Heads2", NULL, ui_heads_range, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Sectors2", NULL, ui_sectors_range, NULL },
    UI_END /* mandatory */
};

static ui_to_from_t ui_to_from3[] = {
    { NULL, MUI_TYPE_FILENAME, "IDE64Image3", NULL, NULL, NULL },
    { NULL, MUI_TYPE_CYCLE, "IDE64AutodetectSize3", ui_ide64_autodetect, ui_ide64_autodetect_values, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Cylinders3", NULL, ui_cylinders_range, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Heads3", NULL, ui_heads_range, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Sectors3", NULL, ui_sectors_range, NULL },
    UI_END /* mandatory */
};

static ui_to_from_t ui_to_from4[] = {
    { NULL, MUI_TYPE_FILENAME, "IDE64Image4", NULL, NULL, NULL },
    { NULL, MUI_TYPE_CYCLE, "IDE64AutodetectSize4", ui_ide64_autodetect, ui_ide64_autodetect_values, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Cylinders4", NULL, ui_cylinders_range, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Heads4", NULL, ui_heads_range, NULL },
    { NULL, MUI_TYPE_INTEGER, "IDE64Sectors4", NULL, ui_sectors_range, NULL },
    UI_END /* mandatory */
};

static ui_to_from_t *ui_to_from = NULL;

static ULONG Browse( struct Hook *hook, Object *obj, APTR arg )
{
    char *fname = NULL;

    fname = BrowseFile(translate_text(IDS_IDE64_FILENAME_SELECT), "#?", ide64_canvas);

    if (fname != NULL) {
        set(ui_to_from[0].object, MUIA_String_Contents, fname);
    }

    return 0;
}

static APTR build_hd_gui(void)
{
    APTR app, ui, ok, browse_button, cancel;

#ifdef AMIGA_MORPHOS
    static const struct Hook BrowseFileHook = { { NULL, NULL }, (VOID *)HookEntry, (VOID *)Browse, NULL };
#else
    static const struct Hook BrowseFileHook = { { NULL, NULL }, (VOID *)Browse, NULL, NULL };
#endif

    app = mui_get_app();

    ui = GroupObject,
           FILENAME(ui_to_from[0].object, translate_text(IDS_IDE64_FILENAME), browse_button)
           CYCLE(ui_to_from[1].object, translate_text(IDS_AUTODETECT), ui_ide64_autodetect)
           Child, ui_to_from[2].object = StringObject,
             MUIA_Frame, MUIV_Frame_String,
             MUIA_FrameTitle, translate_text(IDS_CYLINDERS),
             MUIA_String_Accept, "0123456789",
             MUIA_String_MaxLen, 4+1,
           End,
           Child, ui_to_from[3].object = StringObject,
             MUIA_Frame, MUIV_Frame_String,
             MUIA_FrameTitle, translate_text(IDS_HEADS),
             MUIA_String_Accept, "0123456789",
             MUIA_String_MaxLen, 2+1,
           End,
           Child, ui_to_from[4].object = StringObject,
             MUIA_Frame, MUIV_Frame_String,
             MUIA_FrameTitle, translate_text(IDS_SECTORS),
             MUIA_String_Accept, "0123456789",
             MUIA_String_MaxLen, 2+1,
           End,
           OK_CANCEL_BUTTON
         End;

    if (ui != NULL) {
        DoMethod(cancel, MUIM_Notify, MUIA_Pressed, FALSE,
                 app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

        DoMethod(ok, MUIM_Notify, MUIA_Pressed, FALSE,
                 app, 2, MUIM_Application_ReturnID, BTN_OK);

        DoMethod(browse_button, MUIM_Notify, MUIA_Pressed, FALSE,
                 app, 2, MUIM_CallHook, &BrowseFileHook);
    }

    return ui;
}

static ULONG HD1( struct Hook *hook, Object *obj, APTR arg )
{
    APTR window;

    ui_to_from = ui_to_from1;

    window = mui_make_simple_window(build_hd_gui(), translate_text(IDS_IDE64_HD_1_SETTINGS));

    if (window != NULL) {
        mui_add_window(window);
        ui_get_to(ui_to_from);
        set(window, MUIA_Window_Open, TRUE);
        if (mui_run() == BTN_OK) {
            ui_get_from(ui_to_from);
        }
        set(window, MUIA_Window_Open, FALSE);
        mui_rem_window(window);
        MUI_DisposeObject(window);
    }
    return 0;
}

static ULONG HD2( struct Hook *hook, Object *obj, APTR arg )
{
    APTR window;

    ui_to_from = ui_to_from2;

    window = mui_make_simple_window(build_hd_gui(), translate_text(IDS_IDE64_HD_2_SETTINGS));

    if (window != NULL) {
        mui_add_window(window);
        ui_get_to(ui_to_from);
        set(window, MUIA_Window_Open, TRUE);
        if (mui_run() == BTN_OK) {
            ui_get_from(ui_to_from);
        }
        set(window, MUIA_Window_Open, FALSE);
        mui_rem_window(window);
        MUI_DisposeObject(window);
    }
    return 0;
}

static ULONG HD3( struct Hook *hook, Object *obj, APTR arg )
{
    APTR window;

    ui_to_from = ui_to_from3;

    window = mui_make_simple_window(build_hd_gui(), translate_text(IDS_IDE64_HD_3_SETTINGS));

    if (window != NULL) {
        mui_add_window(window);
        ui_get_to(ui_to_from);
        set(window, MUIA_Window_Open, TRUE);
        if (mui_run() == BTN_OK) {
            ui_get_from(ui_to_from);
        }
        set(window, MUIA_Window_Open, FALSE);
        mui_rem_window(window);
        MUI_DisposeObject(window);
    }
    return 0;
}

static ULONG HD4( struct Hook *hook, Object *obj, APTR arg )
{
    APTR window;

    ui_to_from = ui_to_from4;

    window = mui_make_simple_window(build_hd_gui(), translate_text(IDS_IDE64_HD_4_SETTINGS));

    if (window != NULL) {
        mui_add_window(window);
        ui_get_to(ui_to_from);
        set(window, MUIA_Window_Open, TRUE);
        if (mui_run() == BTN_OK) {
            ui_get_from(ui_to_from);
        }
        set(window, MUIA_Window_Open, FALSE);
        mui_rem_window(window);
        MUI_DisposeObject(window);
    }
    return 0;
}

static APTR build_gui(void)
{
    APTR app, ui, ok, hd_button1, hd_button2, hd_button3, hd_button4, cancel;

#ifdef AMIGA_MORPHOS
    static const struct Hook HD_Hook1 = { { NULL, NULL }, (VOID *)HookEntry, (VOID *)HD1, NULL };
    static const struct Hook HD_Hook2 = { { NULL, NULL }, (VOID *)HookEntry, (VOID *)HD2, NULL };
    static const struct Hook HD_Hook3 = { { NULL, NULL }, (VOID *)HookEntry, (VOID *)HD3, NULL };
    static const struct Hook HD_Hook4 = { { NULL, NULL }, (VOID *)HookEntry, (VOID *)HD4, NULL };
#else
    static const struct Hook HD_Hook1 = { { NULL, NULL }, (VOID *)HD1, NULL, NULL };
    static const struct Hook HD_Hook2 = { { NULL, NULL }, (VOID *)HD2, NULL, NULL };
    static const struct Hook HD_Hook3 = { { NULL, NULL }, (VOID *)HD3, NULL, NULL };
    static const struct Hook HD_Hook4 = { { NULL, NULL }, (VOID *)HD4, NULL, NULL };
#endif

    app = mui_get_app();

    ui = GroupObject,
           CYCLE(ui_to_from_v4[0].object, translate_text(IDS_IDE64_V4), ui_ide64_autodetect)
           BUTTON(hd_button1, translate_text(IDS_IDE64_HD_1_SETTINGS))
           BUTTON(hd_button2, translate_text(IDS_IDE64_HD_2_SETTINGS))
           BUTTON(hd_button3, translate_text(IDS_IDE64_HD_3_SETTINGS))
           BUTTON(hd_button4, translate_text(IDS_IDE64_HD_4_SETTINGS))
           OK_CANCEL_BUTTON
         End;

    if (ui != NULL) {
        DoMethod(cancel, MUIM_Notify, MUIA_Pressed, FALSE,
                 app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

        DoMethod(ok, MUIM_Notify, MUIA_Pressed, FALSE,
                 app, 2, MUIM_Application_ReturnID, BTN_OK);

        DoMethod(hd_button1, MUIM_Notify, MUIA_Pressed, FALSE,
                 app, 2, MUIM_CallHook, &HD_Hook1);

        DoMethod(hd_button2, MUIM_Notify, MUIA_Pressed, FALSE,
                 app, 2, MUIM_CallHook, &HD_Hook2);

        DoMethod(hd_button3, MUIM_Notify, MUIA_Pressed, FALSE,
                 app, 2, MUIM_CallHook, &HD_Hook3);

        DoMethod(hd_button4, MUIM_Notify, MUIA_Pressed, FALSE,
                 app, 2, MUIM_CallHook, &HD_Hook4);
    }

    return ui;
}

void ui_ide64_settings_dialog(video_canvas_t *canvas)
{
    APTR window;

    ide64_canvas = canvas;
    intl_convert_mui_table(ui_ide64_autodetect_translate, ui_ide64_autodetect);

    window = mui_make_simple_window(build_gui(), translate_text(IDS_IDE64_SETTINGS));

    if (window != NULL) {
        mui_add_window(window);
        ui_get_to(ui_to_from_v4);
        set(window, MUIA_Window_Open, TRUE);
        if (mui_run() == BTN_OK) {
            ui_get_from(ui_to_from_v4);
        }
        set(window, MUIA_Window_Open, FALSE);
        mui_rem_window(window);
        MUI_DisposeObject(window);
    }
}

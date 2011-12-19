/*
 * uimenu.h - Common SDL menu functions.
 *
 * Written by
 *  Hannu Nuotio <hannu.nuotio@tut.fi>
 *
 * Based on code by
 *  Ettore Perazzoli <ettore@comm2000.it>
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

#ifndef VICE_UIMENU_H
#define VICE_UIMENU_H

#include "vice.h"
#include "types.h"

extern int sdl_menu_state;

typedef void* ui_callback_data_t;
typedef const char *(*ui_callback_t)(int activated, ui_callback_data_t param);

typedef enum {
    /* Text item (no operation): if data == 1 text colors are inverted */
    MENU_ENTRY_TEXT,

    /* Resource toggle: no UI needed, callback is used */
    MENU_ENTRY_RESOURCE_TOGGLE,

    /* Resource radio: no UI needed, callback is used, data is the resource value */
    MENU_ENTRY_RESOURCE_RADIO,

    /* Resource int: needs UI, callback is used */
    MENU_ENTRY_RESOURCE_INT,

    /* Resource string: needs UI, callback is used */
    MENU_ENTRY_RESOURCE_STRING,

    /* Submenu: needs UI, data points to the submenu */
    MENU_ENTRY_SUBMENU,

    /* Dynamic submenu: needs UI, data points to the submenu, hotkeys disabled */
    MENU_ENTRY_DYNAMIC_SUBMENU,

    /* Custom dialog: needs UI */
    MENU_ENTRY_DIALOG,

    /* Other: no UI needed */
    MENU_ENTRY_OTHER
} ui_menu_entry_type_t;

typedef struct ui_menu_entry_s {
    char *string;
    ui_menu_entry_type_t type;
    ui_callback_t callback;
    ui_callback_data_t data;
} ui_menu_entry_t;

#define SDL_MENU_LIST_END { NULL, MENU_ENTRY_TEXT, NULL, NULL }

typedef enum {
    MENU_RETVAL_DEFAULT,
    MENU_RETVAL_EXIT_UI
} ui_menu_retval_t;

struct menufont_s {
    BYTE *font;
    WORD *translate;
    int w;
    int h;
};
typedef struct menufont_s menufont_t;

struct menu_draw_s {
    int pitch;
    int offset;
    int max_text_x;
    int max_text_y;
    int extra_x;
    int extra_y;
    BYTE color_front;
    BYTE color_back;
};
typedef struct menu_draw_s menu_draw_t;

#define MENU_FIRST_Y 2
#define MENU_FIRST_X 1

typedef enum {
    MENU_ACTION_NONE = 0,
    MENU_ACTION_UP,
    MENU_ACTION_DOWN,
    MENU_ACTION_LEFT,
    MENU_ACTION_RIGHT,
    MENU_ACTION_SELECT,
    MENU_ACTION_CANCEL,
    MENU_ACTION_EXIT,
    MENU_ACTION_MAP,
    MENU_ACTION_NUM,
    MENU_ACTION_NONE_RELEASE,
    MENU_ACTION_UP_RELEASE,
    MENU_ACTION_DOWN_RELEASE,
    MENU_ACTION_LEFT_RELEASE,
    MENU_ACTION_RIGHT_RELEASE,
    MENU_ACTION_SELECT_RELEASE,
    MENU_ACTION_CANCEL_RELEASE,
    MENU_ACTION_EXIT_RELEASE,
    MENU_ACTION_MAP_RELEASE
} ui_menu_action_t;

extern void sdl_ui_set_main_menu(const ui_menu_entry_t *menu);
extern ui_menu_entry_t *sdl_ui_get_main_menu(void);
extern void sdl_ui_set_menu_font(BYTE *font, int w, int h);
extern menu_draw_t *sdl_ui_get_menu_param(void);
extern menufont_t *sdl_ui_get_menu_font(void);
extern void (*sdl_ui_set_menu_params)(int index, menu_draw_t *menu_draw);

extern BYTE *sdl_ui_get_draw_buffer(void);
extern void sdl_ui_activate_pre_action(void);
extern void sdl_ui_activate_post_action(void);
extern void sdl_ui_init_draw_params(void);
extern void sdl_ui_reverse_colors(void);
extern void sdl_ui_refresh(void);
extern ui_menu_action_t sdl_ui_menu_poll_input(void);
extern void sdl_ui_display_cursor(int pos, int old_pos);
extern int sdl_ui_print(const char *text, int pos_x, int pos_y);
extern int sdl_ui_print_center(const char *text, int pos_y);
extern int sdl_ui_display_title(const char *title);
extern void sdl_ui_clear(void);
extern void sdl_ui_activate(void);
extern ui_menu_retval_t sdl_ui_external_menu_activate(ui_menu_entry_t *item);
extern char* sdl_ui_readline(const char* previous, int pos_x, int pos_y);
extern char* sdl_ui_text_input_dialog(const char* title, const char* previous);
extern int sdl_ui_slider_input_dialog(const char* title, const int cur, const int min, const int max);
extern void sdl_ui_invert_char(int pos_x, int pos_y);
extern void sdl_ui_scroll_screen_up(void);

#endif

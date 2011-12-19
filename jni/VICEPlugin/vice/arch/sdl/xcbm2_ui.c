/*
 * xcmb2_ui.c - Implementation of the CBM-II-specific part of the UI.
 *
 * Written by
 *  Hannu Nuotio <hannu.nuotio@tut.fi>
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
#include <stdlib.h>

#include "debug.h"
#include "cbm2.h"
#include "cbm2mem.h"
#include "lib.h"
#include "machine.h"
#include "menu_cbm2cart.h"
#include "menu_cbm2hw.h"
#include "menu_common.h"
#include "menu_debug.h"
#include "menu_drive.h"
#include "menu_ffmpeg.h"
#include "menu_help.h"
#include "menu_network.h"
#include "menu_printer.h"
#include "menu_reset.h"
#include "menu_screenshot.h"
#include "menu_settings.h"
#include "menu_snapshot.h"
#include "menu_sound.h"
#include "menu_speed.h"
#include "menu_tape.h"
#include "menu_video.h"
#include "resources.h"
#include "ui.h"
#include "uimenu.h"
#include "videoarch.h"
#include "vkbd.h"

static const ui_menu_entry_t xcbm6x0_7x0_main_menu[] = {
    { "Autostart image",
      MENU_ENTRY_DIALOG,
      autostart_callback,
      NULL },
    { "Drive",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)drive_menu },
    { "Tape",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)tape_menu },
    { "Cartridge",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)cbm2cart_menu },
    { "Printer",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)printer_ieee_menu },
    { "Machine settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)cbm6x0_7x0_hardware_menu },
    { "Video settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)cbm6x0_7x0_video_menu },
    { "Sound settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)sound_output_menu },
    { "Snapshot",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)snapshot_menu },
    { "Screenshot",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)screenshot_menu },
    { "Speed settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)speed_menu },
    { "Reset",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)reset_menu },
#ifdef HAVE_NETWORK
    { "Network",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)network_menu },
#endif
    { "Pause",
      MENU_ENTRY_OTHER,
      pause_callback,
      NULL },
    { "Monitor",
      MENU_ENTRY_OTHER,
      monitor_callback,
      NULL },
    { "Virtual keyboard",
      MENU_ENTRY_OTHER,
      vkbd_callback,
      NULL },
    { "Statusbar",
      MENU_ENTRY_OTHER,
      statusbar_callback,
      NULL },
#ifdef DEBUG
    { "Debug",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)debug_menu },
#endif
    { "Help",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)help_menu },
    { "Settings management",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)settings_manager_menu },
    { "Quit emulator",
      MENU_ENTRY_OTHER,
      quit_callback,
      NULL },
    SDL_MENU_LIST_END
};

static const ui_menu_entry_t xcbm5x0_main_menu[] = {
    { "Autostart image",
      MENU_ENTRY_DIALOG,
      autostart_callback,
      NULL },
    { "Drive",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)drive_menu },
    { "Tape",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)tape_menu },
    { "Printer",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)printer_ieee_menu },
    { "Machine settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)cbm5x0_hardware_menu },
    { "Video settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)cbm5x0_video_menu },
    { "Sound settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)sound_output_menu },
    { "Snapshot",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)snapshot_menu },
    { "Speed settings",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)speed_menu },
    { "Reset",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)reset_menu },
#ifdef HAVE_NETWORK
    { "Network",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)network_menu },
#endif
    { "Pause",
      MENU_ENTRY_OTHER,
      pause_callback,
      NULL },
    { "Monitor",
      MENU_ENTRY_OTHER,
      monitor_callback,
      NULL },
    { "Virtual keyboard",
      MENU_ENTRY_OTHER,
      vkbd_callback,
      NULL },
    { "Statusbar",
      MENU_ENTRY_OTHER,
      statusbar_callback,
      NULL },
#ifdef DEBUG
    { "Debug",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)debug_menu },
#endif
    { "Help",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)help_menu },
    { "Settings management",
      MENU_ENTRY_SUBMENU,
      submenu_callback,
      (ui_callback_data_t)settings_manager_menu },
    { "Quit emulator",
      MENU_ENTRY_OTHER,
      quit_callback,
      NULL },
    SDL_MENU_LIST_END
};

static BYTE *cbm2_font_14 = NULL;
static BYTE *cbm2_font_8 = NULL;

void cbm2ui_set_menu_params(int index, menu_draw_t *menu_draw)
{
    int model, i, j;

    resources_get_int("ModelLine", &model);

    menu_draw->max_text_x = 80;
    menu_draw->extra_x = 32;

    if (model == 0) {
        menu_draw->extra_y = 16;
        for (i = 0; i < 256; i++) {
            for (j = 0; j < 14; j++) {
                cbm2_font_14[(i * 14) + j] = mem_chargen_rom[(i * 16) + j + 1];
            }
        }
        sdl_ui_set_menu_font(cbm2_font_14, 8, 14);
    } else {
        menu_draw->extra_y = 40;
        for (i = 0; i < 256; i++) {
            for (j = 0; j < 8; j++) {
                cbm2_font_8[(i * 8) + j] = mem_chargen_rom[(i * 16) + j];
            }
        }
        sdl_ui_set_menu_font(cbm2_font_8, 8, 8);
    }
    return;
}

int cbm2ui_init(void)
{
    cbm2_font_8 = lib_malloc(8 * 256);
    cbm2_font_14 = lib_malloc(14 * 256);

    sdl_ui_set_menu_params = cbm2ui_set_menu_params;
    sdl_ui_set_main_menu(xcbm6x0_7x0_main_menu);

    sdl_vkbd_set_vkbd(&vkbd_cbm2);

#ifdef HAVE_FFMPEG
    sdl_menu_ffmpeg_init();
#endif

    return 0;
}

void cbm2ui_shutdown(void)
{
#ifdef SDL_DEBUG
    fprintf(stderr,"%s\n",__func__);
#endif

#ifdef HAVE_FFMPEG
    sdl_menu_ffmpeg_shutdown();
#endif

    lib_free(cbm2_font_14);
    lib_free(cbm2_font_8);
}

int cbm5x0ui_init(void)
{
    cbm2_font_8 = lib_malloc(8 * 256);

    sdl_ui_set_menu_params = NULL;
    sdl_ui_set_menu_font(mem_chargen_rom + 0x800, 8, 8);
    sdl_ui_set_main_menu(xcbm5x0_main_menu);
    sdl_video_canvas_switch(1);

    sdl_vkbd_set_vkbd(&vkbd_cbm2);

#ifdef HAVE_FFMPEG
    sdl_menu_ffmpeg_init();
#endif

    return 0;
}

void cbm5x0ui_shutdown(void)
{
#ifdef SDL_DEBUG
    fprintf(stderr,"%s\n",__func__);
#endif

#ifdef HAVE_FFMPEG
    sdl_menu_ffmpeg_shutdown();
#endif
    lib_free(cbm2_font_8);
}

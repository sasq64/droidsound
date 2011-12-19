/*
 * petui.c - Definition of the PET-specific part of the UI.
 *
 * Written by
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

#include "vice.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"
#include "menudefs.h"
#include "resources.h"
#include "pets.h"
#include "petui.h"
#include "tui.h"
#include "tuifs.h"
#include "tuimenu.h"
#include "ui.h"
#include "uipetdww.h"
#include "uipetreu.h"
#include "uisidcart.h"
#include "uivideo.h"

static TUI_MENU_CALLBACK(set_model_callback)
{
    if (been_activated) {
        pet_set_model(param, NULL);
        ui_update_menus();
    }

    /* This way, the "Not Really!" item is always the default one.  */
    *become_default = 0;
    return NULL;
}

static tui_menu_item_def_t pet_model_items[] = {
    { "_Not Really!",
      "Keep the current settings",
      NULL, NULL, 0, TUI_MENU_BEH_CLOSE, NULL, NULL },
    { "--" },
    { "_A: PET 2001-8N",
      "Configure the emulator to emulate a PET 2001-8N and do a soft RESET",
      set_model_callback, (void *) "2001", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_B: PET 3008",
      "Configure the emulator to emulate a PET 3008 and do a soft RESET",
      set_model_callback, (void *) "3008", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_C: PET 3016",
      "Configure the emulator to emulate a PET 3016 and do a soft RESET",
      set_model_callback, (void *) "3016", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_D: PET 3032",
      "Configure the emulator to emulate a PET 3032 and do a soft RESET",
      set_model_callback, (void *) "3032", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_E: PET 3032B",
      "Configure the emulator to emulate a PET 3032B and do a soft RESET",
      set_model_callback, (void *) "3032B", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_F: PET 4016",
      "Configure the emulator to emulate a PET 4016 and do a soft RESET",
      set_model_callback, (void *) "4016", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_G: PET 4032",
      "Configure the emulator to emulate a PET 4032 and do a soft RESET",
      set_model_callback, (void *) "4032", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_H: PET 4032B",
      "Configure the emulator to emulate a PET 4032B and do a soft RESET",
      set_model_callback, (void *) "4032B", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_I: PET 8032",
      "Configure the emulator to emulate a PET 8032 and do a soft RESET",
      set_model_callback, (void *) "8032", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_J: PET 8096",
      "Configure the emulator to emulate a PET 8096 and do a soft RESET",
      set_model_callback, (void *) "8096", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_K: PET 8296",
      "Configure the emulator to emulate a PET 8296 and do a soft RESET",
      set_model_callback, (void *) "8296", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { "_L: SuperPET",
      "Configure the emulator to emulate a SuperPET and do a soft RESET",
      set_model_callback, (void *) "SuperPET", 0,
      TUI_MENU_BEH_RESUME, NULL, NULL },
    { NULL }
};

static TUI_MENU_CALLBACK(video_size_callback)
{
    int value;

    resources_get_int("VideoSize", &value);

    switch (value) {
        case 0:
            return "Autodetect";
        case 40:
            return "40 columns";
        case 80:
            return "80 columns";
        default:
            return "Unknown";
    }
}

TUI_MENU_DEFINE_RADIO(VideoSize)

static tui_menu_item_def_t video_size_items[] = {
    { "_Autodetect",
      "Autodetect video width from ROM type",
      radio_VideoSize_callback, (void *) 0, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { "_40 column",
      "Set screen width to 40 column",
      radio_VideoSize_callback, (void *) 40, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { "_80 column",
      "Set screen width to 80 column",
      radio_VideoSize_callback, (void *) 80, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { NULL }
};

static TUI_MENU_CALLBACK(ram_size_callback)
{
    static char s[20];
    int value;

    resources_get_int("RamSize", &value);
    sprintf(s, "%d KB", value);
    return s;
}

TUI_MENU_DEFINE_RADIO(RamSize)

static tui_menu_item_def_t ram_size_items[] = {
    { "_0: 4 KBytes",
      "Set RAM size to 4 KBytes",
      radio_RamSize_callback, (void *) 4, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { "_1: 8 KBytes",
      "Set RAM size to 8 KBytes",
      radio_RamSize_callback, (void *) 8, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { "_2: 16 KBytes",
      "Set RAM size to 16 KBytes",
      radio_RamSize_callback, (void *) 16, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { "_3: 32 KBytes",
      "Set RAM size to 32 KBytes",
      radio_RamSize_callback, (void *) 32, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { "_4: 96 KBytes",
      "Set RAM size to 96 KBytes",
      radio_RamSize_callback, (void *) 96, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { "_5: 128 KBytes",
      "Set RAM size to 128 KBytes",
      radio_RamSize_callback, (void *) 128, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { NULL }
};

static TUI_MENU_CALLBACK(iosize_callback)
{
    int value;

    resources_get_int("IOSize", &value);

    switch (value) {
        case 0x800:
            return "2 KBytes";
        case 0x100:
            return "256 Bytes";
        default:
            return "Unknown";
    }
}

TUI_MENU_DEFINE_RADIO(IOSize)

static tui_menu_item_def_t iosize_items[] = {
    { "_0: 2 KBytes",
      "Set I/O size to 2 KBytes",
      radio_IOSize_callback, (void *) 0x800, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { "_1: 256 Bytes",
      "Set I/O size to 256 Bytes",
      radio_IOSize_callback, (void *) 0x100, 0,
      TUI_MENU_BEH_CLOSE, NULL, NULL },
    { NULL }
};

TUI_MENU_DEFINE_TOGGLE(Crtc)
TUI_MENU_DEFINE_TOGGLE(SuperPET)

TUI_MENU_DEFINE_TOGGLE(Ram9)
TUI_MENU_DEFINE_TOGGLE(RamA)

static TUI_MENU_CALLBACK(set_keyboard_callback)
{
    int value;

    resources_get_int("KeymapIndex", &value);

    if (been_activated) {
        value = (value == 2) ? 0 : 2;
        resources_set_int("KeymapIndex", value);
    }

    switch (value) {
        case 0:
            return "Business (UK)";
        case 2:
            return "Graphics";
        default:
            return "Unknown";
    }
}

static tui_menu_item_def_t special_menu_items[] = {
    { "Change _PET Model...",
      "Set options according to a specific PET model; THIS WILL RESET THE MACHINE",
      NULL, NULL, 0,
      TUI_MENU_BEH_CONTINUE, pet_model_items, "Change PET Model" },
    { "  _Video Width:",
      "Specify CRTC video size",
      video_size_callback, NULL, 11,
      TUI_MENU_BEH_CONTINUE, video_size_items, "Video Width" },
    { "  _Memory Size:",
      "Specify PET memory size",
      ram_size_callback, NULL, 6,
      TUI_MENU_BEH_CONTINUE, ram_size_items, "Memory Size" },
    { "  _I/O size",
      "Specify size of I/O memory area",
      iosize_callback, NULL, 9,
      TUI_MENU_BEH_CONTINUE, iosize_items, "I/O Size" },
    { "  Enable _CRTC",
      "Enable the CRTC video chip",
      toggle_Crtc_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "  Enable _SuperPET",
      "Enable the SuperPET I/O",
      toggle_SuperPET_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "  Enable $_9*** RAM:",
      "Enable RAM at $9000-$9FFF (only available on 8296)",
      toggle_Ram9_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "  Enable $_A*** RAM:",
      "Enable RAM at $A000-$AFFF (only available on 8296)",
      toggle_RamA_callback, NULL, 3,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "  _Keyboard Type:",
      "Specify keyboard type (graphics or business)",
      set_keyboard_callback, NULL, 13,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { NULL }
};

/* ------------------------------------------------------------------------- */

static TUI_MENU_CALLBACK(load_rom_file_callback)
{
    if (been_activated) {
        char *name;

        name = tui_file_selector("Load ROM file", NULL, "*", NULL, NULL, NULL, NULL);

        if (name != NULL) {
            if (resources_set_string(param, name) < 0) {
                ui_error("Could not load ROM file '%s'", name);
            }
            lib_free(name);
        }
    }
    return NULL;
}

static tui_menu_item_def_t rom_menu_items[] = {
    { "--" },
    { "Load new _Kernal ROM...",
      "Load new Kernal ROM",
      load_rom_file_callback, "KernalName", 0,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Load new _Editor ROM...",
      "Load new Editor ROM",
      load_rom_file_callback, "EditorName", 0,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Load new _BASIC ROM...",
      "Load new BASIC ROM",
      load_rom_file_callback, "BasicName", 0,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Load new _Character ROM...",
      "Load new Character ROM",
      load_rom_file_callback, "ChargenName", 0,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Load new 15_41 ROM...",
      "Load new 1541 ROM",
      load_rom_file_callback, "DosName1541", 0,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Load new 1541-_II ROM...",
      "Load new 1541-II ROM",
      load_rom_file_callback, "DosName1541ii", 0,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Load new 15_71 ROM...",
      "Load new 1571 ROM",
      load_rom_file_callback, "DosName1571", 0,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Load new 15_81 ROM...",
      "Load new 1581 ROM",
      load_rom_file_callback, "DosName1581", 0,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Load new _2031 ROM...",
      "Load new 2031 ROM",
      load_rom_file_callback, "DosName2031", 0,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { "Load new _1001 ROM...",
      "Load new 1001 ROM",
      load_rom_file_callback, "DosName1001", 0,
      TUI_MENU_BEH_CONTINUE, NULL, NULL },
    { NULL }
};


/* ------------------------------------------------------------------------- */

TUI_MENU_DEFINE_TOGGLE(UserportDAC)

int petui_init(void)
{
    tui_menu_t ui_ioextensions_submenu;

    ui_create_main_menu(1, 1, 0, 2, 1);

    tui_menu_add_separator(ui_video_submenu);

    uivideo_init(ui_video_submenu, VID_CRTC, VID_NONE);

    tui_menu_add_separator(ui_special_submenu);
    tui_menu_add(ui_special_submenu, special_menu_items);

    ui_ioextensions_submenu = tui_menu_create("I/O extensions", 1);
    tui_menu_add_submenu(ui_special_submenu, "_I/O extensions",
                         "Configure I/O extensions",
                         ui_ioextensions_submenu,
                         NULL, 0,
                         TUI_MENU_BEH_CONTINUE);

    tui_menu_add(ui_rom_submenu, rom_menu_items);

    uipetdww_init(ui_ioextensions_submenu);

    uipetreu_init(ui_ioextensions_submenu);

    uisidcart_init(ui_ioextensions_submenu, "$8F00", "$E900", "PET");

    tui_menu_add_item(ui_ioextensions_submenu, "Enable Userport DAC",
                      "Enable Userport DAC",
                      toggle_UserportDAC_callback,
                      NULL, 3,
                      TUI_MENU_BEH_CONTINUE);

    return 0;
}

void petui_shutdown(void)
{
}

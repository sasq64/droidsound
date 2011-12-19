/*
 * uifilereq.c - Common SDL file selection dialog functions.
 *
 * Written by
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
 *  Hannu Nuotio <hannu.nuotio@tut.fi>
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
#include "types.h"

#include "vice_sdl.h"
#include <string.h>

#include "archdep.h"
#include "ioutil.h"
#include "lib.h"
#include "ui.h"
#include "uimenu.h"
#include "uifilereq.h"
#include "util.h"

static menu_draw_t *menu_draw;
static char *last_selected_file = NULL;
static int last_selected_pos = 0;

#define SDL_FILEREQ_META_FILE 0
#define SDL_FILEREQ_META_PATH 1
#define SDL_FILEREQ_META_NUM 2

/* ------------------------------------------------------------------ */
/* static functions */

static int sdl_ui_file_selector_recall_location(ioutil_dir_t *directory)
{
    unsigned int i, j, k, count;
    int direction;

    if (!last_selected_file) {
        return 0;
    }

    /* the file list is sorted by ioutil, do binary search */
    i = 0;
    k = directory->file_amount;

    /* ...but keep a failsafe in case the above assumption breaks */
    count = 50;

    while ((i < k) && (--count)) {
        j = i + ((k - i) >> 1);
        direction = strcmp(last_selected_file, directory->files[j].name);

        if (direction > 0) {
            i = j + 1;
        } else if (direction < 0) {
            k = j;
        } else {
            return j + directory->dir_amount + SDL_FILEREQ_META_NUM;
        }
    }

    return 0;
}

static char* sdl_ui_get_file_selector_entry(ioutil_dir_t *directory, int offset, int *isdir, ui_menu_filereq_mode_t mode)
{
    *isdir = 0;

    if (offset >= (directory->dir_amount + directory->file_amount + SDL_FILEREQ_META_NUM)) {
        return NULL;
    }

    if (offset == SDL_FILEREQ_META_FILE) {
        switch (mode) {
            case FILEREQ_MODE_CHOOSE_FILE:
            case FILEREQ_MODE_SAVE_FILE:
                return "<enter filename>";

            case FILEREQ_MODE_CHOOSE_DIR:
                return "<choose current directory>";
        }
    }

    if (offset == SDL_FILEREQ_META_PATH) {
        return "<enter path>";
    }

    if (offset >= (directory->dir_amount + SDL_FILEREQ_META_NUM)) {
        return directory->files[offset - (directory->dir_amount + SDL_FILEREQ_META_NUM)].name;
    } else {
        *isdir = 1;
        return directory->dirs[offset - SDL_FILEREQ_META_NUM].name;
    }
}

#if (FSDEV_DIR_SEP_CHR=='\\')
static void sdl_ui_print_translate_seperator(const char *text, int x, int y)
{
    unsigned int len;
    unsigned int i;
    char *new_text = NULL;

    len = strlen(text);
    new_text = lib_stralloc(text);

    for (i = 0; i < len; i++) {
        if (new_text[i] == '\\') {
            new_text[i] = '/';
        }
    }
    sdl_ui_print(new_text, x, y);
    lib_free(new_text);
}
#endif

static void sdl_ui_display_path(const char *current_dir)
{
    int len;
    char *text = NULL;
    char *temp = NULL;
    int before = 0;
    int after = 0;
    int pos = 0;
    int amount = 0;
    int i;

    len = strlen(current_dir);

    if (len > menu_draw->max_text_x) {
        text = lib_stralloc(current_dir);

        temp = strchr(current_dir + 1, FSDEV_DIR_SEP_CHR);
        before = (int)(temp - current_dir + 1);

        while (temp != NULL) {
            amount++;
            temp = strchr(temp + 1, FSDEV_DIR_SEP_CHR);
        }

        while (text[len - after] != FSDEV_DIR_SEP_CHR) {
            after++;
        }

        if (amount > 1 && (before + after + 3) < menu_draw->max_text_x) {

            temp = strchr(current_dir + 1, FSDEV_DIR_SEP_CHR);
            while (((temp - current_dir + 1) < (menu_draw->max_text_x - after - 3)) && temp != NULL) {
                before = (int)(temp - current_dir + 1);
                temp = strchr(temp + 1, FSDEV_DIR_SEP_CHR);
            }
        } else {
            before = (menu_draw->max_text_x - 3) / 2;
            after = len - (len - menu_draw->max_text_x) - before - 3;
        }
        pos = len - after;
        text[before] = '.';
        text[before + 1] = '.';
        text[before + 2] = '.';
        for (i = 0; i < after; i++) {
            text[before + 3 + i] = text[pos + i];
        }
        text[before + 3 + after] = 0;
#if (FSDEV_DIR_SEP_CHR=='\\')
        sdl_ui_print_translate_seperator(text, 0, 2);
#else
        sdl_ui_print(text, 0, 2);
#endif
    } else {
#if (FSDEV_DIR_SEP_CHR=='\\')
        sdl_ui_print_translate_seperator(current_dir, 0, 2);
#else
        sdl_ui_print(current_dir, 0, 2);
#endif
    }

    lib_free(text);
}

static void sdl_ui_file_selector_redraw(ioutil_dir_t *directory, const char *title, const char *current_dir, int offset, int num_items, int more, ui_menu_filereq_mode_t mode)
{
    int i, j, isdir = 0;
    char* title_string;
    char* name;

    title_string = lib_msprintf("%s %s", title, (offset) ? ((more) ? "(<- ->)" : "(<-)") : ((more) ? "(->)" : ""));

    sdl_ui_clear();
    sdl_ui_display_title(title_string);
    lib_free(title_string);
    sdl_ui_display_path(current_dir);

    for (i = 0; i < num_items; ++i) {
        j = MENU_FIRST_X;
        name = sdl_ui_get_file_selector_entry(directory, offset + i, &isdir, mode);
        if (isdir) {
            j += 1 + sdl_ui_print("(D)", MENU_FIRST_X, i + MENU_FIRST_Y + 2);
        }
        sdl_ui_print(name, j, i + MENU_FIRST_Y + 2);
    }
}


/* ------------------------------------------------------------------ */
/* External UI interface */

char* sdl_ui_file_selection_dialog(const char* title, ui_menu_filereq_mode_t mode)
{
    int total, dirs, files, menu_max;
    int active = 1;
    int offset = 0;
    int redraw = 1;
    char *retval = NULL;
    int cur = 0, cur_old = -1;
    ioutil_dir_t *directory;
    char *current_dir;
    char *backup_dir;
    char *inputstring;
    unsigned int maxpathlen;

    menu_draw = sdl_ui_get_menu_param();
    maxpathlen = ioutil_maxpathlen();
    current_dir = lib_malloc(maxpathlen);

    ioutil_getcwd(current_dir, maxpathlen);
    backup_dir = lib_stralloc(current_dir);

    directory = ioutil_opendir(".");
    if (directory == NULL) {
        return NULL;
    }

    dirs = directory->dir_amount;
    files = directory->file_amount;
    total = dirs + files + SDL_FILEREQ_META_NUM;
    menu_max = menu_draw->max_text_y - (MENU_FIRST_Y + 2);

    if (mode == FILEREQ_MODE_CHOOSE_FILE) {
        offset = sdl_ui_file_selector_recall_location(directory);
    }

    while (active) {
        if (redraw) {
            sdl_ui_file_selector_redraw(directory, title, current_dir, offset, (total - offset > menu_max) ? menu_max : total - offset, (total - offset > menu_max) ? 1 : 0, mode);
            redraw = 0;
        }
        sdl_ui_display_cursor((cur + 2) , (cur_old == -1) ? -1 : (cur_old + 2));
        sdl_ui_refresh();

        switch (sdl_ui_menu_poll_input()) {
            case MENU_ACTION_UP:
                if (cur > 0) {
                    cur_old = cur;
                    --cur;
                } else {
                    if (offset > 0) {
                        offset--;
                        redraw = 1;
                    }
                }
                break;

            case MENU_ACTION_LEFT:
                offset -= menu_max;
                if (offset < 0) {
                    offset = 0;
                    cur_old = -1;
                    cur = 0;
                }
                redraw = 1;
                break;

            case MENU_ACTION_DOWN:
                if (cur < (menu_max - 1)) {
                    if ((cur + offset) < total - 1) {
                        cur_old = cur;
                        ++cur;
                    }
                } else {
                    if (offset < (total - menu_max)) {
                        offset++;
                        redraw = 1;
                    }
                }
                break;

            case MENU_ACTION_RIGHT:
                offset += menu_max;
                if (offset >= total) {
                    offset = total - 1;
                    cur_old = -1;
                    cur = 0;
                } else if ((cur + offset) >= total) {
                    cur_old = -1;
                    cur = total-offset - 1;
                }
                redraw = 1;
                break;

            case MENU_ACTION_SELECT:
                switch (offset + cur) {
                    case SDL_FILEREQ_META_FILE:
                        if ((mode == FILEREQ_MODE_CHOOSE_FILE) || (mode == FILEREQ_MODE_SAVE_FILE)) {
                            inputstring = sdl_ui_text_input_dialog("Enter filename", NULL);
                            if (inputstring == NULL) {
                                redraw = 1;
                            } else {
                                if (archdep_path_is_relative(inputstring) && (strchr(inputstring, FSDEV_DIR_SEP_CHR) != NULL)) {
                                    retval = inputstring;
                                } else {
                                    retval = util_concat(current_dir, FSDEV_DIR_SEP_STR, inputstring, NULL);
                                    lib_free(inputstring);
                                }
                            }
                        } else {
                            retval = lib_stralloc(current_dir);
                        }
                        active = 0;
                        break;

                    case SDL_FILEREQ_META_PATH:
                        inputstring = sdl_ui_text_input_dialog("Enter path", NULL);
                        if (inputstring != NULL) {
                            ioutil_chdir(inputstring);
                            lib_free(inputstring);
                            ioutil_closedir(directory);
                            ioutil_getcwd(current_dir, maxpathlen);
                            directory = ioutil_opendir(".");
                            offset = 0;
                            cur_old = -1;
                            cur = 0;
                            dirs = directory->dir_amount;
                            files = directory->file_amount;
                            total = dirs + files + SDL_FILEREQ_META_NUM;
                        }
                        redraw = 1;
                        break;

                    default:
                        if (offset + cur < (dirs + SDL_FILEREQ_META_NUM)) {
                            ioutil_chdir(directory->dirs[offset + cur - SDL_FILEREQ_META_NUM].name);
                            ioutil_closedir(directory);
                            ioutil_getcwd(current_dir, maxpathlen);
                            directory = ioutil_opendir(".");
                            offset = 0;
                            cur_old = -1;
                            cur = 0;
                            dirs = directory->dir_amount;
                            files = directory->file_amount;
                            total = dirs + files + 2;
                            redraw = 1;
                        } else {
                            char *selected_file = directory->files[offset + cur - dirs - SDL_FILEREQ_META_NUM].name;
                            if (mode == FILEREQ_MODE_CHOOSE_FILE) {
                                lib_free(last_selected_file);
                                last_selected_file = lib_stralloc(selected_file);
                            }
                            retval = util_concat(current_dir, FSDEV_DIR_SEP_STR, selected_file, NULL);
                            active = 0;
                        }
                        break;
                }
                break;

            case MENU_ACTION_CANCEL:
            case MENU_ACTION_EXIT:
                retval = NULL;
                active = 0;
                ioutil_chdir(backup_dir);
                break;

            default:
                SDL_Delay(10);
                break;
        }
    }
    ioutil_closedir(directory);
    lib_free(current_dir);
    lib_free(backup_dir);

    return retval;
}

void sdl_ui_file_selection_dialog_shutdown(void)
{
    lib_free(last_selected_file);
    last_selected_file = NULL;
}


static char* sdl_ui_get_slot_selector_entry(ui_menu_slots *slots, int offset, ui_menu_slot_mode_t mode)
{
    if (offset >= slots->number_of_elements) {
        return NULL;
    }
    if (slots->entries[offset].used)
    {
    	return slots->entries[offset].slot_string;
    }
    else
    {
    	return "< empty slot >";
    } 
}


static void sdl_ui_slot_selector_redraw(ui_menu_slots *slots, const char *title, const char *current_dir, int offset, int num_items, int more, ui_menu_slot_mode_t mode)
{
    int i, j;
    char* title_string;
    char* name;

    title_string = lib_msprintf("%s  : ", title);

    sdl_ui_clear();
    sdl_ui_display_title(title_string);
    lib_free(title_string);
    sdl_ui_display_path(current_dir);

    for (i = 0; i < num_items; ++i) {
        j = MENU_FIRST_X;
        name = sdl_ui_get_slot_selector_entry(slots, offset + i, mode);
        sdl_ui_print(name, j, i + MENU_FIRST_Y + 2);
    }
}

/* ------------------------------------------------------------------ */
/* External UI interface */

char* sdl_ui_slot_selection_dialog(const char* title, ui_menu_slot_mode_t mode)
{
    int total;
    int active = 1;
    int offset = 0;
    int redraw = 1;
    char *retval = NULL;
    int cur = 0, cur_old = -1;
    char *current_dir;
    unsigned int maxpathlen;
    ui_menu_slots *slots;
    char *temp_name;
    char *progname;
    int i;

    menu_draw = sdl_ui_get_menu_param();
    maxpathlen = ioutil_maxpathlen();
    
    /* workaround to get the "home" directory of the emulator*/
    current_dir = archdep_default_resource_file_name();
    if (current_dir) {
        temp_name = strrchr(current_dir, FSDEV_DIR_SEP_CHR);
    	   if (temp_name) {
            *temp_name = 0;
        } else {
            lib_free(current_dir);
            current_dir = NULL;
        }
    }
    /* workaound end */
    if (!current_dir) {
    	    current_dir = lib_malloc(maxpathlen);
         ioutil_getcwd(current_dir, maxpathlen);
    }

    total = menu_draw->max_text_y - (MENU_FIRST_Y + 2);
    
    slots = lib_malloc(sizeof(ui_menu_slots));
    slots->entries = lib_malloc(sizeof(ui_menu_slot_entry) * total);
    
    progname = archdep_program_name();
    temp_name = strchr(progname, FSDEV_EXT_SEP_CHR);
    if (temp_name) {
        *temp_name = 0;
    }
    for (i = 0; i < total; ++i) {
        unsigned int len;
        unsigned int isdir;

        slots->entries[i].slot_name = lib_msprintf("snapshot_%s_%02d.vsf", progname, i + 1);
        slots->entries[i].slot_string = lib_msprintf(" SLOT %2d", i + 1);
        temp_name = util_concat(current_dir, FSDEV_DIR_SEP_STR, slots->entries[i].slot_name , NULL);
        if (archdep_stat(temp_name, &len, &isdir) == 0) {
            slots->entries[i].used = (isdir == 0);
        } else {
            slots->entries[i].used = 0;
        }
        lib_free(temp_name);
    }
    lib_free(progname);
    slots->number_of_elements = total;
    if (mode == SLOTREQ_MODE_CHOOSE_SLOT) {
        cur = last_selected_pos;
    }

    while (active) {
        if (redraw) {
            sdl_ui_slot_selector_redraw(slots, title, current_dir, offset, total, 0, mode);
            redraw = 0;
        }
        sdl_ui_display_cursor((cur + 2) , (cur_old == -1) ? -1 : (cur_old + 2));
        sdl_ui_refresh();

        switch (sdl_ui_menu_poll_input()) {
            case MENU_ACTION_UP:
                if (cur > 0) {
                    cur--;
                    redraw = 1;
                }
                break;
            case MENU_ACTION_DOWN:
                if (cur < total-1) {
                    cur++;
                    redraw = 1;
                }
                break;
            case MENU_ACTION_SELECT:
                if ((slots->entries[cur].used) || (mode == SLOTREQ_MODE_SAVE_SLOT)) {
                    last_selected_pos = cur;
                    retval = util_concat(current_dir, FSDEV_DIR_SEP_STR, slots->entries[cur].slot_name , NULL);
                } else {
                    retval = NULL;
                }
                active = 0;
                break;
            case MENU_ACTION_CANCEL:
            case MENU_ACTION_EXIT:
                retval = NULL;
                active = 0;
                break;
            default:
                SDL_Delay(10);
                break;
        }
    }
    for (i = 0; i < total; ++i) {
        lib_free(slots->entries[i].slot_name);
        lib_free(slots->entries[i].slot_string);
    }
    lib_free(slots->entries);
    lib_free(slots);
    lib_free(current_dir);
    return retval;
}

/*
 * ui-resources.c
 *
 * Written by
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  Andr� Fachat <fachat@physik.tu-chemnitz.de>
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

#include "lib.h"
#include "resources.h"
#include "log.h"
#include "ui.h"
#include "util.h"

struct ui_resources_s {
    char *html_browser_command;
    int use_private_colormap;
    int save_resources_on_exit;
    int confirm_on_exit;
    int depth;
    int window_width;
    int window_height;
    int window_xpos;
    int window_ypos;
#if defined (USE_XF86_EXTENSIONS) && \
    (defined(USE_XF86_VIDMODE_EXT) || defined (HAVE_XRANDR))
    int fs_enabled_pending;
#endif
};
typedef struct ui_resources_s ui_resources_t;

static ui_resources_t ui_resources;

static unsigned int ui_resources_initialized = 0;

/* Warning: This cannot actually be changed at runtime.  */
static int set_depth(int d, void *param)
{
    /* Minimal sanity check.  */
    if (d < 0 || d > 32) {
        return -1;
    }

    ui_resources.depth = d;
    return 0;
}

static int set_width(int d, void *param)
{
    /* Minimal sanity check.  */
    if (d < 0) {
        return -1;
    }

    ui_resources.window_width = d;
    return 0;
}

static int set_height(int d, void *param)
{
    /* Minimal sanity check.  */
    if (d < 0) {
        return -1;
    }

    ui_resources.window_height = d;
    return 0;
}

static int set_xpos(int d, void *param)
{
    /* Minimal sanity check.  */
    if (d < 0) {
        return -1;
    }

    ui_resources.window_xpos = d;
    return 0;
}

static int set_ypos(int d, void *param)
{
    /* Minimal sanity check.  */
    if (d < 0) {
        return -1;
    }

    ui_resources.window_ypos = d;
    return 0;
}

static int set_html_browser_command(const char *val, void *param)
{
    util_string_set(&ui_resources.html_browser_command, val);
    return 0;
}

static int set_use_private_colormap(int val, void *param)
{
    ui_resources.use_private_colormap = val;
    return 0;
}

static int set_save_resources_on_exit(int val, void *param)
{
    ui_resources.save_resources_on_exit = val;
    return 0;
}

static int set_confirm_on_exit(int val, void *param)
{
    ui_resources.confirm_on_exit = val;
    return 0;
}

static const resource_string_t resources_string[] = {
    { "HTMLBrowserCommand", 
#ifdef MACOSX_SUPPORT    
      "/usr/bin/open %s",
#else
      "firefox %s",
#endif
      RES_EVENT_NO, NULL,
      &ui_resources.html_browser_command,
      set_html_browser_command, NULL },
    { NULL }
};

#if defined (USE_XF86_EXTENSIONS) && (defined(USE_XF86_VIDMODE_EXT) || defined (HAVE_XRANDR))
static int fullscreen_set_fs(int val, void *param)
{
    ui_resources.fs_enabled_pending = val;
    return 0;
}
#endif

/*
    FIXME: WindowXXX should be per window (for x128)
*/
static const resource_int_t resources_int[] = {
    { "PrivateColormap", 0, RES_EVENT_NO, NULL,
      &ui_resources.use_private_colormap, set_use_private_colormap, NULL },
    { "SaveResourcesOnExit", 0, RES_EVENT_NO, NULL,
      &ui_resources.save_resources_on_exit, set_save_resources_on_exit, NULL },
    { "ConfirmOnExit", 1, RES_EVENT_NO, NULL,
      &ui_resources.confirm_on_exit, set_confirm_on_exit, NULL },
    { "DisplayDepth", 0, RES_EVENT_NO, NULL,
      &ui_resources.depth, set_depth, NULL },
    { "WindowWidth", 0, RES_EVENT_NO, NULL,
      &ui_resources.window_width, set_width, NULL },
    { "WindowHeight", 0, RES_EVENT_NO, NULL,
      &ui_resources.window_height, set_height, NULL },
    { "WindowXpos", 0, RES_EVENT_NO, NULL,
      &ui_resources.window_xpos, set_xpos, NULL },
    { "WindowYpos", 0, RES_EVENT_NO, NULL,
      &ui_resources.window_ypos, set_ypos, NULL },
#if defined (USE_XF86_EXTENSIONS) && (defined(USE_XF86_VIDMODE_EXT) || defined (HAVE_XRANDR))
    { "UseFullscreen", 0, RES_EVENT_NO, NULL,
      &ui_resources.fs_enabled_pending, fullscreen_set_fs, NULL },
#endif
    { NULL }
};

int ui_resources_init(void)
{
    ui_resources_initialized = 1;

    if (resources_register_string(resources_string) < 0) {
        return -1;
    }

    return resources_register_int(resources_int);
}

void ui_resources_shutdown(void)
{
    if (ui_resources_initialized) {
        lib_free(ui_resources.html_browser_command);
    }
}

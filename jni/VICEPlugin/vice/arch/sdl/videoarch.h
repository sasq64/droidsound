/*
 * videoarch.h - SDL graphics routines.
 *
 * based on the X11 version written by
 *  Ettore Perazzoli
 *  Teemu Rantanen <tvr@cs.hut.fi>
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

#ifndef VICE_VIDEOARCH_H
#define VICE_VIDEOARCH_H

#include "vice.h"

#include "vice_sdl.h"

#include "viewport.h"
#include "video.h"

#define MAX_CANVAS_NUM 2

typedef void (*video_refresh_func_t)(struct video_canvas_s *, int, int, int, int, unsigned int, unsigned int);

struct video_canvas_s {
    unsigned int initialized;
    unsigned int created;

    /* Index of the canvas, needed for x128 and xcbm2 */
    int index;
    unsigned int depth;

    /* Size of the drawable canvas area, including the black borders */
    unsigned int width, height;

    /* Size of the canvas as requested by the emulator itself, without double size */
    unsigned int real_width, real_height;

    /* Actual size of the window; in most cases the same as width/height */
    unsigned int actual_width, actual_height;

    /* Double size state, for keeping track of the real size */
    unsigned int dsizex, dsizey;

    /* Drawable surface */
    SDL_Surface* screen;

    struct video_render_config_s *videoconfig;
    struct draw_buffer_s *draw_buffer;
    struct viewport_s *viewport;
    struct geometry_s *geometry;
    struct palette_s *palette;
    struct raster_s *parent_raster;

    struct video_draw_buffer_callback_s *video_draw_buffer_callback;
    struct fullscreenconfig_s *fullscreenconfig;
    video_refresh_func_t video_fullscreen_refresh_func;
#ifdef HAVE_HWSCALE
    /* OpenGL context */
    SDL_Surface *hwscale_screen;
#endif
};
typedef struct video_canvas_s video_canvas_t;

extern video_canvas_t *sdl_active_canvas;

/* Resize window to w/h. 0/0 resizes to stored real size */
extern void sdl_video_resize(unsigned int w, unsigned int h);

/* Switch to canvas with given index; used by x128 and xcbm2 */
extern void sdl_video_canvas_switch(int index);
extern int sdl_active_canvas_num;

/* Flag for forced resize (as opposed to f.ex PAL/NTSC switch) */
extern int sdl_forced_resize;

/* Modes of resolution limitation */
#define SDL_LIMIT_MODE_OFF   0
#define SDL_LIMIT_MODE_MAX   1
#define SDL_LIMIT_MODE_FIXED 2

#ifdef HAVE_HWSCALE
/* Modes of fixed aspect ratio */
#define SDL_ASPECT_MODE_OFF    0
#define SDL_ASPECT_MODE_CUSTOM 1
#define SDL_ASPECT_MODE_TRUE   2
#endif

#endif

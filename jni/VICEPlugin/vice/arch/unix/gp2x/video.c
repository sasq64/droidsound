/*
 * video.c
 *
 * Written by
 *  Mike Dawson <mike@gp2x.org>
 *  Mustafa 'GnoStiC' Tufan <mtufan@gmail.com>
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

#include "gp2xsys.h"

#include <stdio.h>

#include "ui_gp2x.h"
#include "uitext_gp2x.h"
#include "prefs_gp2x.h"
#include "vkeyboard_gp2x.h"

#include "videoarch.h"
#include "palette.h"
#include "machine.h"
#include "input_gp2x.h"
#include "vsync.h"
#include "interrupt.h"

int machine_ui_done = 0;
int vicii_setup_delay = 0;

extern volatile unsigned short *gp2x_memregs;

video_canvas_t *current_canvas;

int xoffset, yoffset;
int xoffset_centred, yoffset_centred;
int xoffset_uncentred, yoffset_uncentred;

int video_init()
{
    return 0;
}

int video_init_cmdline_options()
{
    return 0;
}

void video_shutdown()
{
}

video_canvas_t *video_canvas_create(video_canvas_t *canvas, unsigned int *width, unsigned int *height, int mapped)
{
    static int vicii_setup = 0;

    display_width = 320;

    canvas->depth = 8;
    canvas->width = 320;
    canvas->height = 240;

    video_canvas_set_palette(canvas, canvas->palette);

    if (vicii_setup_delay == 1) {
        if (!vicii_setup) {
            canvas->width = 0;
        }
        vicii_setup = 1;
    }

    gp2x_tvout_pal();

    current_canvas = canvas;
    return canvas;
}

void video_canvas_destroy(struct video_canvas_s *canvas)
{
}

void video_arch_canvas_init(struct video_canvas_s *canvas)
{
    canvas->video_draw_buffer_callback=NULL;
}

static void pause_trap(WORD addr, void *data)
{
    vsync_suspend_speed_eval();
    while (prefs_open) {
        usleep(20000);
        gp2x_poll_input();
        draw_prefs(gp2x_screen8);
        gp2xsys_video_flip();
    }
}

void video_canvas_refresh(struct video_canvas_s *canvas, unsigned int xs, unsigned int ys, unsigned int xi, unsigned int yi, unsigned int w, unsigned int h)
{
    BYTE *source;
    register unsigned int x, y;
    register int buf_width;
    register int xoff;
    register int yoff;

    if (canvas->width == 0) {
        return;
    }

    if (machine_ui_done == 0) {
        return;
    }

    if (xoffset_centred == 0) {
        xoffset_centred = (canvas->draw_buffer->draw_buffer_width - 320) / 2;
        xoffset = xoffset_centred;
    }
    if (yoffset_centred == 0) {
        yoffset_centred = (canvas->draw_buffer->draw_buffer_height - 240) / 2;
        yoffset = yoffset_centred;
    }

    xoff = xoffset;
    yoff = yoffset;

    source = canvas->draw_buffer->draw_buffer;
    buf_width = canvas->draw_buffer->draw_buffer_width / 4;

    gp2x_screen_source((unsigned long *)source, (unsigned long *)gp2x_screen8, xoff, yoff, buf_width, hwscaling);

    gp2x_poll_input();

    if (stats_open) {
        draw_stats(gp2x_screen8);
    }
    if (prefs_open) {
        interrupt_maincpu_trigger_trap(pause_trap, 0);
    } else if (vkeyb_open) {
        draw_vkeyb(gp2x_screen8);
    }
	
    gp2xsys_video_flip();
}

int video_canvas_set_palette(struct video_canvas_s *canvas, struct palette_s *palette)
{
    unsigned int i;
    for (i = 0; i < palette->num_entries; i++) {
        gp2xsys_video_color8(i, palette->entries[i].red, palette->entries[i].green, palette->entries[i].blue);
    }
    gp2x_video_setpalette();

    return 0;
}

int video_arch_resources_init(void)
{
    return 0;
}

void video_canvas_resize(struct video_canvas_s *canvas, unsigned int width, unsigned int height)
{
}

void video_arch_resources_shutdown(void)
{
    gp2xsys_shutdown();
}

void video_add_handlers(void)
{
}

void fullscreen_capability(void)
{
}

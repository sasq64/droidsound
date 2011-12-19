/*
 * video.c - Video implementation for BeOS.
 *
 * Written by
 *  Andreas Matthies <andreas.matthies@gmx.net>
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

#define EXACT_TYPE_NEEDED

#include <Alert.h>
#include <Application.h>
#include <Bitmap.h>
#include <FilePanel.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <Screen.h>
#include <ScrollView.h>
#include <TextView.h>
#include <View.h>
#include <Window.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(__BEOS__) && defined(WORDS_BIGENDIAN)
#include <string.h>
#endif

extern "C" {
#include "cmdline.h"
#include "fullscreen.h"
#include "lib.h"
#include "log.h"
#include "palette.h"
#include "raster.h"
#include "resources.h"
#include "translate.h"
#include "types.h"
#include "ui.h"
#include "uiapi.h"
#include "vicewindow.h"
#include "video.h"
#include "videoarch.h"
#include "viewport.h"
}

/* #define DEBUG_VIDEO */

#ifdef DEBUG_VIDEO
#define DEBUG(x) log_debug x
#else
#define DEBUG(x)
#endif

void video_resize(void);

static int number_of_canvas = 0;

/* ------------------------------------------------------------------------ */
 /* Video-related resources.  */

int use_direct_window;

static int set_direct_window(int val, void *param)
{
    /* first set the new value; ui_set_window_mode need's it */
    use_direct_window = val;

    /* test if we can really use the mode */
    use_direct_window = ui_set_window_mode(use_direct_window);

    return 0;
}

static const resource_int_t resources_int[] = {
    { "DirectWindow", 1, RES_EVENT_NO, NULL,
      &use_direct_window, set_direct_window, NULL },
    { NULL }
};

int video_arch_resources_init(void)
{
    return resources_register_int(resources_int);
}

void video_arch_resources_shutdown(void)
{
}

static const cmdline_option_t cmdline_options[] =
{
    { "-directwindow", SET_RESOURCE, 0,
      NULL, NULL, "DirectWindow", (resource_value_t) 1,
      USE_PARAM_STRING, USE_DESCRIPTION_STRING,
      IDCLS_UNUSED, IDCLS_UNUSED,
      NULL, "Enable BeOS DirectWindow API" },
    { "+directwindow", SET_RESOURCE, 0, NULL, NULL, "DirectWindow",
      USE_PARAM_STRING, USE_DESCRIPTION_STRING,
      IDCLS_UNUSED, IDCLS_UNUSED,
      NULL, "Disable BeOS DirectWindow API" },
    { NULL }
};

int video_init_cmdline_options(void)
{
    return cmdline_register_options(cmdline_options);
}

/* ------------------------------------------------------------------------ */
/* Initialization.  */
int video_init(void)
{
    return 0;
}

void video_shutdown(void)
{
}

/* ------------------------------------------------------------------------ */
/* Canvas functions.  */

static void canvas_create_bitmap(video_canvas_t *c, unsigned int width, unsigned int height)
{
    color_space use_colorspace;

    switch (c->depth) {
        case 8:
            use_colorspace = B_CMAP8;
            break;
        case 16:
            use_colorspace = B_RGB16;
            break;
        case 32:
        default:
            use_colorspace = B_RGB32;
    }

    c->vicewindow->bitmap = new BBitmap(BRect(0, 0, width - 1, height - 1), use_colorspace, false, true);
}

void video_arch_canvas_init(struct video_canvas_s *canvas)
{
    canvas->video_draw_buffer_callback = NULL;
}

video_canvas_t *video_canvas_create(struct video_canvas_s *canvas, unsigned int *width, unsigned int *height, int mapped)
{
    DEBUG(("Creating canvas width=%d height=%d", *width, *height));

    canvas->title = lib_stralloc(canvas->viewport->title);

    switch (BScreen().ColorSpace()) {
        case B_CMAP8:
            canvas->depth = 8;
            break;
        case B_RGB15:
        case B_RGB16:
            canvas->depth = 16;
            break;
        case B_RGB32:
        default:
            canvas->depth = 32;
    }
    video_canvas_set_palette(canvas, canvas->palette);

    canvas->width = *width;
    canvas->height = *height;

    if (canvas->videoconfig->doublesizex) {
        canvas->width *= 2;
    }

    if (canvas->videoconfig->doublesizey) {
        canvas->height *= 2;
    }

    canvas->vicewindow = new ViceWindow(BRect(0, 0, canvas->width - 1, canvas->height - 1), canvas->viewport->title);

    canvas->vicewindow->canvas = canvas;

    canvas_create_bitmap(canvas, canvas->width, canvas->height);

    number_of_canvas++;
    canvas->vicewindow->MoveTo(number_of_canvas * 30, number_of_canvas * 30);

    return canvas;
}

/* Destroy `s'.  */
void video_canvas_destroy(video_canvas_t *c)
{
    if (c == NULL) {
        return;
    }

    if (c->vicewindow != NULL) {
        delete c->vicewindow->bitmap;
        delete c->vicewindow;
    }
    lib_free(c->title);
}

/* Change the size of `s' to `width' * `height' pixels.  */
void video_canvas_resize(video_canvas_t *c, unsigned int width, unsigned int height)
{
    if (c->vicewindow == NULL) {
        return;
    }

    if (c->videoconfig->doublesizex) {
        width *= 2;
    }

    if (c->videoconfig->doublesizey) {
        height *= 2;
    }

    if (c->width == width && c->height == height) {
        return;
    }

    delete c->vicewindow->bitmap;
    canvas_create_bitmap(c, width, height);
    
    c->vicewindow->Resize(width, height);
    c->width = width;
    c->height = height;
    DEBUG(("video_canvas_resize to %d x %d", width, height));
}

int video_canvas_set_palette(video_canvas_t *c, palette_t *p)
{
    int i;
    int rshift = 0;
    int rbits = 0;
    int gshift = 0;
    int gbits = 0;
    int bshift = 0;
    int bbits = 0;
    DWORD rmask = 0;
    DWORD gmask = 0;
    DWORD bmask = 0;

    c->palette = p;
    DEBUG(("Allocating colors"));
    for (i = 0; i < p->num_entries; i++) {
        DWORD col;

        switch (c->depth) {
            case 8:		/* CMAP8 */
                col = BScreen().IndexForColor(p->entries[i].red, p->entries[i].green, p->entries[i].blue);
                break;
            case 16:	/* RGB 5:6:5 */
                rbits = 3;
                rshift = 11;
                rmask = 0x1f;
                gbits = 2;
                gshift = 5;
                gmask = 0x3f;
                bbits = 3;
                bshift = 0;
                bmask = 0x1f;
                col = (p->entries[i].red >> 3) << 11 | (p->entries[i].green >> 2) << 5 | (p->entries[i].blue >> 3);
                break;
            case 32:	/* RGB 8:8:8 */
            default:
                rbits = 0;
                rshift = 16;
                rmask = 0xff;
                gbits = 0;
                gshift = 8;
                gmask = 0xff;
                bbits = 0;
                bshift = 0;
                bmask = 0xff;
                col = p->entries[i].red << 16 | p->entries[i].green << 8 | p->entries[i].blue;
        }
        video_render_setphysicalcolor(c->videoconfig, i, col, c->depth);
    }
    if (c->depth > 8) {
        for (i = 0; i < 256; i++) {
            video_render_setrawrgb(i, ((i & (rmask << rbits)) >> rbits) << rshift, ((i & (gmask << gbits)) >> gbits) << gshift, ((i & (bmask << bbits)) >> bbits) << bshift);
        }
        video_render_initraw(c->videoconfig);
    }

    return 0;
}

/* ------------------------------------------------------------------------ */
void video_canvas_refresh(video_canvas_t *c, unsigned int xs, unsigned int ys, unsigned int xi, unsigned int yi, unsigned int w, unsigned int h)
{
    int i, x_offset, y_offset, hh, ww, xxi, xxs, yyi, yys;
    BYTE *p;
    clipping_rect *clip;
    ViceWindow *vw = c->vicewindow;

    if (c->videoconfig->doublesizex) {
        xi *= 2;
        w *= 2;
    }

    if (c->videoconfig->doublesizey) {
        yi *= 2;
        h *= 2;
    }

    if (!use_direct_window) {
        w = MIN(w, c->width - xi);
        h = MIN(h, c->height - yi);

        video_canvas_render(c, (BYTE *)(c->vicewindow->bitmap->Bits()),
                            w, h,
                            xs, ys,
                            xi, yi,
                            c->vicewindow->bitmap->BytesPerRow(), c->depth);

        c->vicewindow->DrawBitmap(c->vicewindow->bitmap, xi, yi, xi, yi, w, h);
    } else {
        vw->locker->Lock();
        if (vw->fconnected) {
            x_offset = vw->fbounds.left;
            y_offset = vw->fbounds.top + vw->menubar_offset;

            p = vw->fbits + y_offset * vw->fbytes_per_row + x_offset * (vw->fbits_per_pixel >> 3);

            for (i = 0; i < vw->fcliplist_count; i++) {
                int clip_left;
                int clip_top;

                clip = &(vw->fclip_list[i]);

                hh = h;
                ww = w;
                xxi = xi;
                yyi = yi;
                xxs = xs;
                yys = ys;

                clip_left = clip->left - xxi - x_offset;
                clip_top = clip->top - yyi - y_offset;

                /* cut left */
                if (clip_left > 0) {
                    xxs = xxs + clip_left / (c->videoconfig->doublesizex ? 2 : 1);
                    ww = ww - clip_left; 
                    xxi = xxi + clip_left;
                }

                /* cut right */
                if (clip->right + 1 < xxi + x_offset + ww) {
                    ww = clip->right + 1 - xxi - x_offset;
                }

                /* cut top */
                if (clip_top > 0) {
                    yys = yys + clip_top / (c->videoconfig->doublesizey ? 2 : 1);
                    hh = hh - clip_top;
                    yyi = yyi + clip_top;
                }

                /* cut bottom */
                if (clip->bottom + 1 < yyi + y_offset + hh) {
                    hh = clip->bottom + 1 - yyi - y_offset;
                }

                if (ww > 0 && hh > 0) {
                    video_canvas_render(c, p, ww, hh, xxs, yys, xxi, yyi, vw->fbytes_per_row, c->depth);
                }
            }
        }
        vw->locker->Unlock();			
    }
}

void fullscreen_capability(cap_fullscreen_t *cap_fullscreen)
{
    cap_fullscreen->device_num = 0;
}

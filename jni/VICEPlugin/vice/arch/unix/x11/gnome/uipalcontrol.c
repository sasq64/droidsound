/*
 * uipalcontrol.c - GTK only, UI controls for CRT emu
 *
 * Written by
 *  pottendo <pottendo@gmx.net>
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
#include <string.h>

#include "lib.h"
#include "machine.h"
#include "ui.h"
#include "util.h"
#include "video.h"
#include "resources.h"
#include "videoarch.h"

static video_canvas_t *cached_canvas;

typedef struct pal_res_s {
    char *label;        /* Label of Adjustmentbar */
    char *res;          /* Associated resource */
    int scale;          /* Scale to adjust to value range 0..4000 */
    GtkObject *adj;     /* pointer to widget */
    GtkWidget *w;       /* widget holding the scrollbar+label */
} pal_res_t;

static pal_res_t ctrls[] = {
    { N_("Blur"), "PALBlur", 4, NULL, NULL },
    { N_("Scanline shade"), "PALScanLineShade", 4, NULL, NULL  },
    { N_("Saturation"), "ColorSaturation", 2, NULL, NULL  },
    { N_("Contrast"), "ColorContrast", 2, NULL, NULL  },
    { N_("Brightness"), "ColorBrightness", 2, NULL, NULL  },
    { N_("Gamma"), "ColorGamma", 1, NULL, NULL  },
    { N_("Tint"), "ColorTint", 2, NULL, NULL  },
    { N_("Odd lines phase"), "PALOddLinePhase", 2, NULL, NULL  },
    { N_("Odd lines offset"), "PALOddLineOffset", 2, NULL, NULL  },
};

static void upd_sb (GtkAdjustment *adj, gpointer data)
{
    int v = (int) adj->value;
    pal_res_t *p = (pal_res_t *)data;

    v  = (int)v / p->scale;

    resources_set_int(p->res, v);

    /* video_canvas_refresh_all(cached_canvas); */
}

static void pal_ctrl_reset (GtkWidget *w, gpointer data)
{
    pal_res_t *p = (pal_res_t *)data;
    unsigned int i;
    int tmp;

    for (i = 0; i < sizeof(ctrls) / sizeof(ctrls[0]); i++) {
        resources_get_default_value(p[i].res, (void *)&tmp);
        resources_set_int(p[i].res, tmp);
        tmp = tmp * p[i].scale;
        if (p[i].adj) {
            gtk_adjustment_set_value(GTK_ADJUSTMENT(p[i].adj), (gfloat)tmp);
        }
    }

    video_canvas_refresh_all(cached_canvas);
}

GtkWidget *build_pal_ctrl_widget(video_canvas_t *canvas)
{
    GtkWidget *b, *hb;
    GtkObject *adj;
    GtkWidget *sb;
    GtkWidget *f;
    GtkWidget *l, *c;
    GtkWidget *box;
    GtkWidget *rb;
    unsigned int i;
    int v;
    char *resname;
    char *chip;
    pal_res_t *ctrldata;

    chip = canvas->videoconfig->chip_name;
    ctrldata = lib_malloc(sizeof(ctrls));
    memcpy(ctrldata, ctrls, sizeof(ctrls));

    cached_canvas = canvas;
    f = gtk_frame_new(_("CRT emulation settings"));

    b = gtk_vbox_new(FALSE, 5);

    for (i = 0; i < sizeof(ctrls) / sizeof(ctrls[0]); i++) {

        resname = util_concat(chip, ctrls[i].res, NULL);
        hb = gtk_hbox_new(FALSE, 0);

        c = gtk_hbox_new(FALSE, 0);
        gtk_widget_set_size_request(GTK_WIDGET(c), 100, 10);

        l = gtk_label_new(_(ctrldata[i].label));
        gtk_container_add(GTK_CONTAINER(c), l);
        gtk_widget_show(l);

        gtk_box_pack_start(GTK_BOX(hb), c, FALSE, FALSE, 5);
        gtk_widget_show(c);

        ctrldata[i].adj = adj = gtk_adjustment_new(0, 0, 4100, 1, 100, 100);

        resources_get_int(resname, &v);
        ctrldata[i].res = resname;

        gtk_adjustment_set_value(GTK_ADJUSTMENT(adj), (gfloat)(v * ctrldata[i].scale));
        sb = gtk_hscrollbar_new(GTK_ADJUSTMENT(adj));
        gtk_range_set_update_policy(GTK_RANGE(sb), GTK_UPDATE_CONTINUOUS);
        gtk_box_pack_start(GTK_BOX(hb), sb, TRUE, TRUE, 0);

        g_signal_connect(G_OBJECT(adj), "value_changed", G_CALLBACK (upd_sb), &ctrldata[i]);

        gtk_widget_show(sb);
        gtk_box_pack_start(GTK_BOX(b), hb, TRUE, TRUE, 0);
        gtk_widget_show(hb);
        ctrldata[i].w = hb;
    }

    box = gtk_hbox_new(FALSE, 0);

    rb = gtk_button_new_with_label(_("Reset"));
    gtk_box_pack_start(GTK_BOX(box), rb, FALSE, FALSE, 5);
    g_signal_connect(G_OBJECT(rb), "clicked", G_CALLBACK(pal_ctrl_reset), ctrldata);
    GTK_WIDGET_UNSET_FLAGS(rb, GTK_CAN_FOCUS);
    gtk_widget_show(rb);

    gtk_widget_show(box);

    gtk_box_pack_start(GTK_BOX(b), box, FALSE, FALSE, 5);
    gtk_widget_show(b);
    gtk_container_add(GTK_CONTAINER(f), b);
    gtk_widget_show(f);

    return f;
}

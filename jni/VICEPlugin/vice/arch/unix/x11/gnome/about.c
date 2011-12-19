/*
 * about.c - Info about the VICE project, including the GPL.
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

#include "info.h"
#include "platform.h"
#include "uiarch.h"
#include "version.h"

GtkWidget *about;

static void license_cb(GtkWidget *w, GdkEvent *event, gpointer data)
{
    ui_show_text(_("VICE is FREE software!"), info_license_text, 500, 300);
}

static void warranty_cb(GtkWidget *w, GdkEvent *event, gpointer data)
{
    ui_show_text(_("No warranty!"), info_warranty_text, 500, 300);
}

static void contrib_cb(GtkWidget *w, GdkEvent *event, gpointer data)
{
    ui_show_text(_("Contributors to the VICE project"), info_contrib_text, 500, 300);
}

static void response_cb(GtkWidget *w, gint id, gpointer data)
{
    if (id == GTK_RESPONSE_CANCEL) {
        gtk_widget_hide(GTK_WIDGET(data));
    }
}

void ui_about(gpointer data)
{
    GtkWidget *button;
    
    const gchar *authors[] = {
#ifdef __GNUC__
        _("The VICE Team"), 
#else
        "The VICE Team",
#endif
        "Copyright @ 1998-2011 Dag Lem",
        "Copyright @ 1999-2011 Andreas Matthies",
        "Copyright @ 1999-2011 Martin Pottendorfer",
        "Copyright @ 2000-2011 Spiro Trikaliotis",
        "Copyright @ 2005-2011 Marco van den Heuvel",
        "Copyright @ 2006-2011 Christian Vogelgsang",
        "Copyright @ 2007-2011 Fabrizio Gennari",
        "Copyright @ 2007-2011 Daniel Kahlin",
        "Copyright @ 2008-2011 Antti S. Lankila",
        "Copyright @ 2009-2011 Groepaz",
        "Copyright @ 2009-2011 Ingo Korb",
        "Copyright @ 2009-2011 Errol Smith",
        "Copyright @ 2010-2011 Olaf Seibert",
        "Copyright @ 2011      Marcus Sutton",
        "Copyright @ 2011      Ulrich Schulz",
        "Copyright @ 2011      Stefan Haubenthal",
        "Copyright @ 2011      Thomas Giesel",
        "Copyright @ 2011      Kajtar Zsolt",
        "",
#ifdef __GNUC__
        _("Official VICE homepage:"),
#else
        "Official VICE homepage:",
#endif
        "http://vice-emu.sourceforge.net/",
        NULL
    };

    const gchar *docs[] = {
        "Ettore Perazzoli et al.", 
        NULL
    };

    const gchar *transl = _(
        "Mikkel Holm Olsen - Danish\n"
        "Martin Pottendorfer - German\n"
        "Manuel Antonio Rodriguez Bas - Spanish\n"
        "Paul Dube - French\n"
        "Czirkos Zoltan, Karai Csaba - Hungarian\n"
        "Andrea Musuruane - Italian\n"
        "Jesse Lee - Korean\n"
        "Marco van den Heuvel - Dutch\n"
        "Jarek Sobolewski - Polish\n"
        "Mihail Litvinov - Russian\n"
        "Peter Krefting - Swedish\n"
        "Emir Akaydin (aka: Skate) - Turkish\n"
    );

    if (!about) {
        /* GdkPixbuf *logo = gdk_pixbuf_new_from_file ("logo.png", NULL); */
        about = g_object_new(GTK_TYPE_ABOUT_DIALOG,
                             "name", "V I C E",
                             "version", VERSION " (GTK+ " PLATFORM_CPU " " PLATFORM_OS " " PLATFORM_COMPILER ")",
                             "copyright", _("(c) 1998 - 2011 The VICE Team"),
                             "comments", "Versatile Commodore Emulator",
                             "authors", authors, 
                             "documenters", docs, 
                             "translator-credits", transl, 
                             NULL);
        g_signal_connect(G_OBJECT(about), "destroy", G_CALLBACK(gtk_widget_destroyed), &about);
        button = gtk_dialog_add_button(GTK_DIALOG(about), _("License"), GTK_RESPONSE_OK);
        g_signal_connect(GTK_OBJECT(button), "clicked", G_CALLBACK(license_cb), NULL);
        button = gtk_dialog_add_button(GTK_DIALOG(about), _("Warranty"), GTK_RESPONSE_OK);
        g_signal_connect(GTK_OBJECT(button), "clicked", G_CALLBACK(warranty_cb), NULL);
        button = gtk_dialog_add_button(GTK_DIALOG(about), _("Contributors"), GTK_RESPONSE_OK);
        g_signal_connect(GTK_OBJECT(button), "clicked", G_CALLBACK(contrib_cb), NULL);
        g_signal_connect(G_OBJECT(about), "response", G_CALLBACK(response_cb), about);
    } else {
        gdk_window_show(about->window);
        gdk_window_raise(about->window);
    }

    ui_make_window_transient(_ui_top_level, about);
    gtk_widget_show(about);
}

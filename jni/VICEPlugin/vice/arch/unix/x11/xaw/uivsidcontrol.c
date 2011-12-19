/*
 * uivsidcontrol.c - UI controls for VSID
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
#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/Intrinsic.h>
#include <X11/Shell.h>
#include <X11/Xaw/SimpleMenu.h>
#include <X11/Xaw/SmeBSB.h>
#include <X11/Xaw/SmeLine.h>
#include <X11/Xaw/Command.h>
#include <X11/Xaw/Form.h>
#include <X11/Xaw/Paned.h>
#include <X11/Xaw/Box.h>
#include <X11/Xaw/AsciiText.h>

#include "lib.h"
#include "ui.h"
#include "uiarch.h"
#include "vsiduiunix.h"

static char *author, *copyright, *name, *vsidsync, *model, *irq;
static int tune;
static char *line;

static Widget psidparent;
static Widget psidwidget;

static void update_line(void)
{
    lib_free(line);
    line = lib_msprintf(_("Name: %s\nTune: %d\nAuthor: %s\nCopyright: %s\n%s\nModel: %s\nIRQ: %s"), name, tune, author, copyright, vsidsync, model, irq);
    XtVaSetValues(psidwidget, XtNlabel, line, NULL);
}

void vsid_ctrl_widget_set_parent(ui_window_t p)
{
    psidparent = p;
}

ui_window_t build_vsid_ctrl_widget(void)
{
    Pixel Background = 0;

    line = lib_msprintf(_("Name: %s\nTune: %d\nAuthor: %s\nCopyright: %s\n%s\nModel: %s\nIRQ: %s"), "-", 0, "-", "-", "", "-", "-");
    XtVaGetValues(psidparent, XtNbackground, &Background,NULL);
    psidwidget = XtVaCreateManagedWidget("Canvas",
                                    labelWidgetClass, psidparent,
                                     XtNwidth, 320,
                                     XtNheight, 200,
                                     XtNresizable, True,
                                     XtNbottom, XawChainBottom,
                                     XtNtop, XawChainTop,
                                     XtNleft, XawChainLeft,
                                     XtNright, XawChainRight,
                                     XtNborderWidth, 0,
                                     XtNlabel, line ? line : "VSID",
                                     XtNbackground, Background,
                                     NULL);

    return psidwidget;
}

void ui_vsid_setpsid(const char *psid)
{
    lib_free(name);
    name = lib_stralloc(psid);
    update_line();
}

void ui_vsid_settune(const int t)
{
    tune = t;
    update_line();
}

void ui_vsid_setauthor(const char *a)
{
    lib_free(author);
    author = lib_stralloc(a);
    update_line();
}
void ui_vsid_setcopyright(const char *c)
{
    lib_free(copyright);
    copyright = lib_stralloc(c);
    update_line();
}

void ui_vsid_setmodel(const char *c)
{
    lib_free(model);
    model = lib_stralloc(c);
    update_line();
}

void ui_vsid_setsync(const char *c)
{
    lib_free(vsidsync);
    vsidsync = lib_stralloc(c);
    update_line();
}

void ui_vsid_setirq(const char *c)
{
    lib_free(irq);
    irq = lib_stralloc(c);
    update_line();
}

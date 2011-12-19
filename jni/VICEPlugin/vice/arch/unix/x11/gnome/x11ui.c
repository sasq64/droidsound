/*
 * ui.c - Gnome/Gtk+ based UI
 *
 * Written by
 *  Ettore Perazzoli
 *  Oliver Schaertel
 *  pottendo <pottendo@gmx.net>
 *
 * Support for multiple visuals and depths by
 *  Teemu Rantanen <tvr@cs.hut.fi>
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

/* #define DEBUG_X11UI */

#ifdef DEBUG_X11UI
#define DBG(_x_) log_debug _x_
#else
#define DBG(_x_)
#endif

#define _UI_C

#include "vice.h"

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <pango/pango.h>

#ifdef ENABLE_NLS
#include <locale.h>
#endif

#ifdef HAVE_HWSCALE
#include <gtk/gtkgl.h>
#include <gdk/gdkgl.h>
#include <GL/gl.h>
#endif

#include "ui.h"
#include "uiapi.h"
#include "uiarch.h"

#include "autostart.h"
#include "datasette.h"
#include "charset.h"
#include "drive/drive.h"
#include "fullscreenarch.h"
#include "imagecontents.h"
#include "tapecontents.h"
#include "diskcontents.h"
#include "ioutil.h"
#include "lib.h"
#include "log.h"
#include "kbd.h"
#include "machine.h"
#include "maincpu.h"
#include "mouse.h"
#include "mousedrv.h"
#include "keyboard.h"
#include "resources.h"
#include "types.h"
#include "uiapi.h"
#include "uicolor.h"
#include "uimenu.h"
#include "uisettings.h"
#include "uicommands.h"
#include "uifileentry.h"
#include "uilib.h"
#include "util.h"
#include "version.h"
#include "vsync.h"
#include "video.h"
#include "videoarch.h"
#include "vsiduiunix.h"
#include "screenshot.h"
#include "vice-event.h"
#include "uifliplist.h"
#include "c128/c128.h"
#include "lightpen.h"
#include "lightpendrv.h"

/* FIXME: We want these to be static.  */
char last_attached_images[NUM_DRIVES][256]; /* FIXME MP */
char *last_attached_tape;
static char *last_menus[NUM_DRIVES];
static GtkWidget *last_drive_menus[NUM_DRIVES];

#ifdef USE_XF86_EXTENSIONS
#include <gdk/gdkx.h>
#endif
#include "x11ui.h"

#ifdef USE_XF86_EXTENSIONS
static Display *display;
int screen;
static int depth;
#endif

#if !GTK_CHECK_VERSION(2, 12, 0)
static void gtk_widget_set_tooltip_text(GtkWidget * widget, const char * text)
{
    static GtkTooltips * tooltips = NULL;

    if (tooltips == NULL) {
        tooltips = gtk_tooltips_new();
        gtk_tooltips_enable(tooltips);
    }
    gtk_tooltips_set_tip(tooltips, widget, text, NULL);
}
#endif

/* UI logging goes here.  */
static log_t ui_log = LOG_ERR;

static int tape_motor_status = -1;
static int tape_control_status = -1;

#define VSID_WINDOW_MINW     (400)
#define VSID_WINDOW_MINH     (300)

#define WINDOW_MINW     (320 / 2)
#define WINDOW_MINH     (200 / 2)

#define LED_WIDTH 12
#define LED_HEIGHT 6
#define CTRL_WIDTH 13
#define CTRL_HEIGHT 11

static GtkWidget *tape_menu, *speed_menu;
static GtkWidget *drive_menus[NUM_DRIVES];
GtkWidget *video_ctrl_checkbox;
static GtkWidget *video_ctrl_checkbox_label;
static GtkWidget *event_rec_checkbox;
static GtkWidget *event_rec_checkbox_label;
static GtkWidget *event_playback_checkbox;
static GtkWidget *event_playback_checkbox_label;
static GtkStyle *ui_style_red;
static GtkStyle *ui_style_green;
static GdkCursor *blankCursor;
static GtkWidget *image_preview_list, *auto_start_button, *last_file_selection;
static char *fixedfontname="CBM 10";
static PangoFontDescription *fixed_font_desc;
static int have_cbm_font = 0;
static video_canvas_t *ui_cached_video_canvas;
static int statustext_display_time = 0;
static int popped_up_count = 0;

/* Left-button and right-button menu.  */
static GtkWidget *left_menu, *right_menu;

/* Toplevel widget. */
GtkWidget * _ui_top_level = NULL;
static GdkGC *app_gc = NULL;

/* Our colormap. */
GdkColormap *colormap;

/* Enabled drives.  */
ui_drive_enable_t enabled_drives;  /* used also in uicommands.c */

/* Color of the drive active LED.  */
static int *drive_active_led;

/* Drive status widget */
typedef struct {
    GtkWidget *box;			/* contains all the widgets */
    char *label;
    GtkWidget *pixmap;
#if 0
    GtkWidget *image;
#endif
    GtkWidget *event_box;
    GtkWidget *track_label;
    GtkWidget *led;
    GdkPixmap *led_pixmap;
    GtkWidget *led1;
    GdkPixmap *led1_pixmap;
    GtkWidget *led2;
    GdkPixmap *led2_pixmap;
} drive_status_widget;

/* Tape status widget */
typedef struct {
    GtkWidget *box;
    GtkWidget *event_box;
    GtkWidget *label;
    GtkWidget *control;
    GdkPixmap *control_pixmap;
} tape_status_widget;

#define MAX_APP_SHELLS 10
typedef struct {
    gchar *title;
    GtkWidget *shell;
    GtkWidget *topmenu;
    GtkWidget *status_bar;
    GtkWidget *pal_ctrl;
    GtkLabel *speed_label;
    GtkLabel *statustext;
    GtkAccelGroup *accel;
    drive_status_widget drive_status[NUM_DRIVES];
    tape_status_widget tape_status;
    GdkGeometry geo;
} app_shell_type;

static app_shell_type app_shells[MAX_APP_SHELLS];
static int num_app_shells = 0;

/* Pixels for updating the drive LED's state.  */
GdkColor drive_led_on_red_pixel, drive_led_on_green_pixel, 
drive_led_off_pixel, motor_running_pixel, tape_control_pixel;
GdkColor drive_led_on_red_pixels[16];
GdkColor drive_led_on_green_pixels[16];

/* ------------------------------------------------------------------------- */

/*static int alloc_colors(const palette_t *palette, PIXEL pixel_return[]);*/
static GtkWidget* build_file_selector(const char *title, GtkWidget **attach_write_protect, int allow_autostart,
                                      int show_preview, uilib_file_filter_enum_t* patterns, int num_patterns,
                                      const char *default_dir, ui_filechooser_t action, read_contents_func_type read_contents_func);
static GtkWidget* build_show_text(const gchar *text, int width, int height);
static GtkWidget* build_confirm_dialog(GtkWidget **confirm_dialog_message);
static gboolean enter_window_callback(GtkWidget *w, GdkEvent *e, gpointer p);
static gboolean leave_window_callback(GtkWidget *w, GdkEvent *e, gpointer p);
static gboolean configure_callback_app(GtkWidget *w, GdkEventConfigure *e, gpointer p);
static gboolean configure_callback_canvas(GtkWidget *w, GdkEventConfigure *e, gpointer p);
static gboolean exposure_callback_canvas(GtkWidget *w, GdkEventExpose *e, gpointer p);
static gboolean map_callback(GtkWidget *widget, GdkEvent  *event, gpointer user_data);
static gboolean fliplist_popup_cb(GtkWidget *w, GdkEvent *event, gpointer data);
static gboolean tape_popup_cb(GtkWidget *w, GdkEvent *event, gpointer data);
static gboolean update_menu_cb(GtkWidget *w, GdkEvent *event,gpointer data);
static gboolean speed_popup_cb(GtkWidget *w, GdkEvent *event, gpointer data);

static GtkWidget* rebuild_contents_menu(int unit, const char *image_name);
extern GtkWidget* build_pal_ctrl_widget(video_canvas_t *canvas);

static void toggle_aspect(video_canvas_t *canvas);
static void setup_aspect(video_canvas_t *canvas);

/* ------------------------------------------------------------------------- */

/*
    grab pointer and keyboard, set mouse pointer shape

    TODO: also route lightpen stuff through this function
*/
static int mouse_grabbed = 0;
static void mouse_cursor_grab(int grab, GdkCursor *cursor)
{
    if (mouse_grabbed) {
        gdk_keyboard_ungrab(GDK_CURRENT_TIME);
        gdk_pointer_ungrab(GDK_CURRENT_TIME);
        mouse_grabbed = 0;
    }
    if (grab) {
        gdk_keyboard_grab(_ui_top_level->window, 1, GDK_CURRENT_TIME);
        /* XXX check this -- latter _ui_top_level->window used to be
         * canvas->emuwindow->window... */
        gdk_pointer_grab(_ui_top_level->window, 1, GDK_POINTER_MOTION_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK, _ui_top_level->window, cursor, GDK_CURRENT_TIME);
        mouse_grabbed = 1;
    }
}

void ui_check_mouse_cursor(void)
{
#ifdef HAVE_FULLSCREEN
    if (fullscreen_is_enabled) {
        if (_mouse_enabled) {
            mouse_accelx = 2;
            mouse_accely = 2;
            mouse_cursor_grab(1, blankCursor);
        } else {
            mouse_cursor_grab(1, NULL);
        }
        return;
    }
#endif
    if (ui_cached_video_canvas == NULL) {
        return;
    }

    if (_mouse_enabled) {
        if (ui_cached_video_canvas->videoconfig->doublesizex) {
            mouse_accelx = 4 / (ui_cached_video_canvas->videoconfig->doublesizex + 1);
        } else {
            mouse_accelx = 4;
        }

        if (ui_cached_video_canvas->videoconfig->doublesizey) {
            mouse_accely = 4 / (ui_cached_video_canvas->videoconfig->doublesizey + 1);
        } else {
            mouse_accely = 4;
        }
        mouse_cursor_grab(1, blankCursor);
    } else {
        mouse_cursor_grab(0, NULL);
    }
}

void ui_restore_mouse(void)
{
    mouse_cursor_grab(0, NULL);
}

void initBlankCursor(void)
{
    static char cursor[] = { 0x00 };
    GdkColor fg = { 0, 0, 0, 0 };
    GdkColor bg = { 0, 0, 0, 0 };
    GdkBitmap *source = gdk_bitmap_create_from_data (NULL, cursor, 1, 1);
    GdkBitmap *mask = gdk_bitmap_create_from_data (NULL, cursor, 1, 1);

    blankCursor = gdk_cursor_new_from_pixmap (source, mask, &fg, &bg, 1, 1); 

    g_object_unref (source);
    g_object_unref (mask); 
}

/* ------------------------------------------------------------------------- */

void archdep_ui_init(int argc, char *argv[])
{
    /* Fake Gnome to see empty arguments; 
       Generaly we should use a `popt_table', either by converting the
       registered options to this, or to introduce popt in the generic part,
       case we have `libgnomeui' around.
       For now I discard gnome-specific options. FIXME MP */

    char *fake_argv[2];
    int fake_argc = 1;
    char **fake_args = fake_argv;

    if (console_mode) {
        return;
    }

    fake_argv[0] = argv[0];
    fake_argv[1] = NULL;
    gtk_init(&fake_argc, &fake_args);

#ifdef HAVE_HWSCALE
    gtk_gl_init_check(&fake_argc, &fake_args);
#endif
}

/* Initialize the GUI and parse the command line. */
int ui_init(int *argc, char **argv)
{

#ifdef USE_XF86_EXTENSIONS
    display = GDK_DISPLAY();
    depth = gdk_visual_get_system()->depth;
    screen = gdk_screen_get_number(gdk_screen_get_default());
#endif

    atexit(ui_autorepeat_on);

    ui_common_init();

    enabled_drives = UI_DRIVE_ENABLE_NONE;

    return 0;
}

void ui_shutdown(void)
{
    ui_common_shutdown();
}

typedef struct {
    char *name;
    GdkVisualType class;
} namedvisual_t;

gboolean delete_event(GtkWidget *w, GdkEvent *e, gpointer data) 
{
    vsync_suspend_speed_eval();
    ui_exit();
    /* ui_exit() will exit the application if user allows it. So if
       we return here then we should keep going => return TRUE */
    return TRUE;
}

static gint mouse_posx, mouse_posy;
static gint mouse_lasteventx, mouse_lasteventy;
static gint mouse_warped = 0;
#define MOUSE_WRAP_MARGIN  40

static gfloat get_aspect(video_canvas_t *canvas);

void mouse_handler(GtkWidget *w, GdkEvent *event, gpointer data)
{
    video_canvas_t *canvas = (video_canvas_t *)data;
    app_shell_type *appshell = &app_shells[canvas->app_shell];

    if (event->type == GDK_BUTTON_PRESS) {
        GdkEventButton *bevent = (GdkEventButton*)event;
        if (_mouse_enabled || lightpen_enabled) {
            mouse_button(bevent->button-1, TRUE);
            gtk_lightpen_setbutton(bevent->button, TRUE);
        } else {
            if (bevent->button == 1) {
                ui_menu_update_all_GTK();
                gtk_menu_popup(GTK_MENU(left_menu), NULL, NULL, NULL, NULL, bevent->button, bevent->time);
            } else if (bevent->button == 3) {
                ui_menu_update_all_GTK();
                gtk_menu_popup(GTK_MENU(right_menu), NULL, NULL, NULL, NULL, bevent->button, bevent->time);
            }
        }
    } else if (event->type == GDK_BUTTON_RELEASE && (_mouse_enabled || lightpen_enabled)) {
        GdkEventButton *bevent = (GdkEventButton*)event;
        mouse_button(bevent->button-1, FALSE);
        gtk_lightpen_setbutton(bevent->button, FALSE);
   } else if (event->type == GDK_MOTION_NOTIFY) {
        GdkEventMotion *mevent = (GdkEventMotion*)event;
        if (_mouse_enabled) {
            /* handle pointer motion events for mouse emulation */
            if (mouse_warped) {
                /* ignore this event, its the result of us having moved the pointer */
                mouse_warped = 0;
                /* printf("warped!\n"); */
            } else {
                gint x=0, y=0, w=0, h=0, warp=0;
                gint ptrx, ptry;
                GdkDisplay *display = NULL;
                GdkScreen *screen = NULL;
                gfloat taspect;

                /* get default display and screen */
                display = gdk_display_get_default ();
                screen = gdk_display_get_default_screen (display);

                /* get cursor position */
                gdk_display_get_pointer (display, NULL, &x, &y, NULL);

                ptrx = (int)mevent->x;
                ptry = (int)mevent->y;
                ptry += appshell->topmenu->allocation.height;

                w = canvas->geometry->screen_size.width;
                h = canvas->geometry->screen_size.height;

                if (canvas->videoconfig->doublesizex) {
                    w *= (canvas->videoconfig->doublesizex + 1);
                }
                if (canvas->videoconfig->doublesizey) {
                    h *= (canvas->videoconfig->doublesizey + 1);
                }

                taspect = get_aspect(canvas);
                if (taspect > 0.0f) {
                    w = ((float)w) * taspect;
                }

                if (ptrx < MOUSE_WRAP_MARGIN) {
                    x = mouse_lasteventx = w - (MOUSE_WRAP_MARGIN + 10);
                    warp = 1;
                }
                else if (ptrx > (w - MOUSE_WRAP_MARGIN)) {
                    x = mouse_lasteventx = (MOUSE_WRAP_MARGIN + 10);
                    warp = 1;
                }

                h -= (appshell->topmenu->allocation.height + appshell->status_bar->allocation.height);

                if (ptry < (appshell->topmenu->allocation.height + MOUSE_WRAP_MARGIN)) {
#ifdef HAVE_FULLSCREEN
                    if (canvas->fullscreenconfig->enable) {
                        mouse_lasteventy = h - ((MOUSE_WRAP_MARGIN + 10) *2); /* FIXME */
                    } else {
#endif
                        mouse_lasteventy = h - (MOUSE_WRAP_MARGIN + 10);
#ifdef HAVE_FULLSCREEN
                    }
#endif
                    y = mouse_lasteventy + appshell->topmenu->allocation.height;
                    warp = 1;
                } else if (ptry > (h - MOUSE_WRAP_MARGIN)) {
                    mouse_lasteventy = (MOUSE_WRAP_MARGIN + 10) + appshell->topmenu->allocation.height;
                    y = mouse_lasteventy + appshell->topmenu->allocation.height;
                    warp = 1;
                }

                if (warp) {
                    /* set new cusor position */
                    mouse_warped = 1;
                    gdk_display_warp_pointer (display, screen, x, y);
                } else {
                    mouse_posx += ptrx - mouse_lasteventx;
                    mouse_posy += ptry - mouse_lasteventy;
                    mouse_move(mouse_posx, mouse_posy);
                    mouse_lasteventx = ptrx;
                    mouse_lasteventy = ptry;
                }
            }
        }
#ifdef HAVE_FULLSCREEN
        fullscreen_mouse_moved(canvas, (int)mevent->x, (int)mevent->y, 0);
#endif
   }
}

static gboolean fliplist_popup_cb(GtkWidget *w, GdkEvent *event, gpointer data)
{
    int d = vice_ptr_to_int(data);
    if (event->type == GDK_BUTTON_PRESS) {
        GdkEventButton *bevent = (GdkEventButton*) event;
        if (bevent->button == 1) {
            if ((d >= 0)&& (d < NUM_DRIVES)) {
                uifliplist_update_menus(d + 8, d + 8);
                ui_menu_update_all_GTK();
                if (drive_menus[d]) {
                    gtk_menu_popup(GTK_MENU(drive_menus[d]), NULL, NULL, NULL, NULL, bevent->button, bevent->time);
                }
            }
        } else if (bevent->button == 3) {
            if (strcmp(last_attached_images[d], "") == 0) {
                if (last_menus[d]) {
                    if (last_drive_menus[d]) {
                        gtk_widget_destroy(last_drive_menus[d]);
                    }
                    lib_free(last_menus[d]);
                    last_menus[d] = NULL;
                }
                return 0;
            }

            if (last_drive_menus[d]) {
                gtk_widget_destroy(last_drive_menus[d]);
            }
            lib_free(last_menus[d]);
            last_menus[d] = lib_stralloc(last_attached_images[d]);
            last_drive_menus[d] =
                rebuild_contents_menu(d+8, last_menus[d]);

            if (last_drive_menus[d]) {
                gtk_menu_popup(GTK_MENU(last_drive_menus[d]), NULL, NULL, NULL, NULL, bevent->button, bevent->time);
            }
        }
    }
    return 0;
}

static gboolean tape_popup_cb(GtkWidget *w, GdkEvent *event, gpointer data)
{
    if (event->type == GDK_BUTTON_PRESS) {
        GdkEventButton *bevent = (GdkEventButton*)event;
        if (bevent->button == 1) {
            ui_menu_update_all_GTK();
            if (tape_menu) {
                gtk_menu_popup(GTK_MENU(tape_menu), NULL, NULL, NULL, NULL, bevent->button, bevent->time);
            }
        } else if (bevent->button == 3) {
            static char *lasttapemenu;
            static GtkWidget *ltapemenu;

            if (last_attached_tape == NULL) {
                if (lasttapemenu) {
                    if (ltapemenu) {
                        gtk_widget_destroy(ltapemenu);
                    }
                    lib_free(lasttapemenu);
                    lasttapemenu = NULL;
                }
                return 0;
            }

            if (ltapemenu) {
                gtk_widget_destroy(ltapemenu);
            }
            lib_free(lasttapemenu);
            lasttapemenu = lib_stralloc(last_attached_tape);
            ltapemenu = rebuild_contents_menu(1, lasttapemenu);

            if (ltapemenu) {
                gtk_menu_popup(GTK_MENU(ltapemenu), NULL, NULL, NULL, NULL, bevent->button, bevent->time);
            }
        }
    }
    return 0;
}

static gboolean update_menu_cb(GtkWidget *w, GdkEvent *event,gpointer data)
{
    ui_menu_update_all_GTK();
    return 0;
}

static gboolean speed_popup_cb(GtkWidget *w, GdkEvent *event, gpointer data)
{
    if (event->type == GDK_BUTTON_PRESS) {
        GdkEventButton *bevent = (GdkEventButton*) event;
	
        if (speed_menu) {
            ui_menu_update_all_GTK();
            gtk_menu_popup(GTK_MENU(speed_menu), NULL, NULL, NULL, NULL, bevent->button, bevent->time);
        }
    }
    return 0;
}

/* Continue GUI initialization after resources are set. */
int ui_init_finish(void)
{
    ui_log = log_open("X11");

    have_cbm_font = TRUE;
    fixed_font_desc = pango_font_description_from_string(fixedfontname);
    if (!fixed_font_desc) {
        log_warning(ui_log, "Cannot load CBM font %s.", fixedfontname);
        have_cbm_font = FALSE;
    }

#ifdef HAVE_FULLSCREEN
    if (fullscreen_init() != 0) {
        log_warning(ui_log, "Some fullscreen devices aren't initialized properly.");
    }
#endif
    return ui_menu_init();
}

int ui_init_finalize(void)
{
    ui_check_mouse_cursor();
    return 0;
}

static void ui_update_pal_checkbox (GtkWidget *w, gpointer data)
{
    app_shell_type *appshell = ((app_shell_type*) data);

    if (!w || !GTK_IS_TOGGLE_BUTTON(w)) {
        return;
    }

    if (GTK_TOGGLE_BUTTON(w)->active) {
        gtk_widget_show(appshell->pal_ctrl);
    } else {
        gtk_widget_hide(appshell->pal_ctrl);
    }

}

static void ui_update_video_checkbox (GtkWidget *w, gpointer data)
{
    gtk_widget_hide(video_ctrl_checkbox);
    screenshot_stop_recording();
}

static void ui_update_event_checkbox (GtkWidget *w, gpointer data)
{
    if (data) {
        event_playback_stop();
    } else {
        event_record_stop();
    }
}

static void statusbar_setstatustext(const char *t)
{
    int i;

    for (i = 0; i < num_app_shells; i++) {
        gtk_label_set_text(app_shells[i].statustext, t);
    }
}

static GtkWidget *ui_create_status_bar(GtkWidget *pane)
{
    /* Create the status bar on the bottom.  */
    GtkWidget *speed_label, *drive_box, *frame, *event_box, *pcb, *vcb, *tmp, *pal_ctrl_checkbox, *status_bar;
    int i;
    app_shell_type *as;
    char *empty = util_concat("<", _("empty"), ">", NULL);

    status_bar = gtk_hbox_new(FALSE, 0);

    gtk_box_pack_end(GTK_BOX(pane), status_bar, FALSE, FALSE, 0);
    gtk_widget_show(status_bar);

    event_box = gtk_event_box_new();
    gtk_box_pack_start(GTK_BOX(status_bar), event_box, TRUE, TRUE,0);
    gtk_widget_show(event_box);
    g_signal_connect(G_OBJECT(event_box), "button-press-event", G_CALLBACK(speed_popup_cb), (gpointer)NULL);

    frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type (GTK_FRAME(frame), GTK_SHADOW_IN);
    gtk_container_add(GTK_CONTAINER(event_box), frame);
    gtk_widget_show(frame);

    speed_label = gtk_label_new("");
    app_shells[num_app_shells - 1].speed_label = (GtkLabel*)speed_label;
    gtk_misc_set_alignment (GTK_MISC(speed_label), 0, -1);
    gtk_container_add(GTK_CONTAINER(frame), speed_label);
    gtk_widget_show(speed_label);

    frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);

    tmp = gtk_label_new("");
    app_shells[num_app_shells - 1].statustext = (GtkLabel*)tmp;
    gtk_misc_set_alignment(GTK_MISC (tmp), 0, -1);
    gtk_container_add(GTK_CONTAINER(frame), tmp);
    gtk_widget_show(tmp);
    gtk_box_pack_start(GTK_BOX(status_bar), frame, TRUE, TRUE,0);
    gtk_widget_show(frame);

    as = &app_shells[num_app_shells - 1];

    if (machine_class != VICE_MACHINE_VSID) {
        /* PAL Control checkbox */
        pal_ctrl_checkbox = gtk_frame_new(NULL);
        gtk_frame_set_shadow_type(GTK_FRAME(pal_ctrl_checkbox), GTK_SHADOW_IN);
        pcb = gtk_check_button_new_with_label(_("CRT Controls"));
        GTK_WIDGET_UNSET_FLAGS(pcb, GTK_CAN_FOCUS);
        g_signal_connect(G_OBJECT(pcb), "toggled", G_CALLBACK(ui_update_pal_checkbox), as);
        gtk_container_add(GTK_CONTAINER(pal_ctrl_checkbox), pcb);
        gtk_widget_show(pcb);
        gtk_box_pack_start(GTK_BOX(status_bar), pal_ctrl_checkbox, FALSE, FALSE, 0);
        gtk_widget_show(pal_ctrl_checkbox);

        /* Video Control checkbox */
        video_ctrl_checkbox = gtk_frame_new(NULL);
        gtk_frame_set_shadow_type(GTK_FRAME(video_ctrl_checkbox), GTK_SHADOW_IN);

        video_ctrl_checkbox_label = gtk_label_new(_("audio/video recording"));
        vcb = gtk_button_new();
        gtk_container_add(GTK_CONTAINER(vcb), video_ctrl_checkbox_label);
        gtk_widget_show(video_ctrl_checkbox_label);
        GTK_WIDGET_UNSET_FLAGS(pcb, GTK_CAN_FOCUS);
        g_signal_connect(G_OBJECT(vcb), "clicked", G_CALLBACK(ui_update_video_checkbox), vcb);
        gtk_container_add(GTK_CONTAINER(video_ctrl_checkbox), vcb);
        gtk_widget_show(vcb);
        gtk_box_pack_start(GTK_BOX(status_bar), video_ctrl_checkbox, FALSE, FALSE, 0);
        gtk_widget_set_tooltip_text(GTK_WIDGET(vcb), _("click to stop recording"));

        /* Event record control checkbox */
        event_rec_checkbox = gtk_frame_new(NULL);
        gtk_frame_set_shadow_type(GTK_FRAME(event_rec_checkbox), GTK_SHADOW_IN);

        event_rec_checkbox_label = gtk_label_new(_("event recording"));
        vcb = gtk_button_new();
        gtk_container_add(GTK_CONTAINER(vcb), event_rec_checkbox_label);
        gtk_widget_show(event_rec_checkbox_label);
        GTK_WIDGET_UNSET_FLAGS(pcb, GTK_CAN_FOCUS);
        g_signal_connect(G_OBJECT(vcb), "clicked", G_CALLBACK(ui_update_event_checkbox), (gpointer)0);
        gtk_container_add(GTK_CONTAINER(event_rec_checkbox), vcb);
        gtk_widget_show(vcb);
        gtk_box_pack_start(GTK_BOX(status_bar), event_rec_checkbox, FALSE, FALSE, 0);
        gtk_widget_set_tooltip_text(GTK_WIDGET(vcb), _("click to stop recording"));

        /* Event playback control checkbox */
        event_playback_checkbox = gtk_frame_new(NULL);
        gtk_frame_set_shadow_type(GTK_FRAME(event_playback_checkbox), GTK_SHADOW_IN);

        event_playback_checkbox_label = gtk_label_new(_("event playback"));
        vcb = gtk_button_new();
        gtk_container_add(GTK_CONTAINER(vcb), event_playback_checkbox_label);
        gtk_widget_show(event_playback_checkbox_label);
        GTK_WIDGET_UNSET_FLAGS(pcb, GTK_CAN_FOCUS);
        g_signal_connect(G_OBJECT(vcb), "clicked", G_CALLBACK(ui_update_event_checkbox), (gpointer)1);
        gtk_container_add(GTK_CONTAINER(event_playback_checkbox), vcb);
        gtk_widget_show(vcb);
        gtk_box_pack_start(GTK_BOX(status_bar), event_playback_checkbox, FALSE, FALSE, 0);
        gtk_widget_set_tooltip_text(GTK_WIDGET(vcb), _("click to stop playback"));

        /* drive stuff */
        drive_box = gtk_hbox_new(FALSE, 0);
        for (i = 0; i < NUM_DRIVES; i++) {
            char label[256];

            as->drive_status[i].event_box = gtk_event_box_new();

            frame = gtk_frame_new(NULL);
            gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);

            sprintf(label, _("Drive %d: "), i + 8);
            as->drive_status[i].box = gtk_hbox_new(FALSE, 0);

            gtk_container_add(GTK_CONTAINER(frame), as->drive_status[i].box);
            gtk_widget_show(as->drive_status[i].box);

            gtk_container_add(GTK_CONTAINER(as->drive_status[i].event_box), frame);
            gtk_widget_show(frame);

#if 0
            drive_tooltips[i] = gtk_tooltips_new();
            gtk_tooltips_set_tip(GTK_TOOLTIPS(drive_tooltips[i]), as->drive_status[i].box->parent->parent, empty, NULL);
#else
            gtk_widget_set_tooltip_text(GTK_WIDGET(as->drive_status[i].box->parent->parent), empty);
#endif
            /* Label */
            as->drive_status[i].label = (void *)gtk_label_new(g_strdup(label));
            gtk_box_pack_start(GTK_BOX(as->drive_status[i].box), (GtkWidget *)as->drive_status[i].label, TRUE, TRUE, 0);
            gtk_widget_show((GtkWidget *)as->drive_status[i].label);
#if 0
            as->drive_status[i].image = (void *)gtk_label_new(empty);
            gtk_container_add(GTK_CONTAINER(event_box), as->drive_status[i].image);
            gtk_widget_show(as->drive_status[i].image);
#endif
            /* Track Label */
            as->drive_status[i].track_label = gtk_label_new("");
            gtk_box_pack_start(GTK_BOX(as->drive_status[i].box), as->drive_status[i].track_label, FALSE, FALSE, 0);
            gtk_widget_show(as->drive_status[i].track_label);      

            /* Single Led */
            as->drive_status[i].led_pixmap = gdk_pixmap_new(_ui_top_level->window, LED_WIDTH, LED_HEIGHT, -1);
            as->drive_status[i].led = gtk_image_new_from_pixmap(as->drive_status[i].led_pixmap, NULL);
            gtk_widget_set_size_request(as->drive_status[i].led, LED_WIDTH, LED_HEIGHT);
            gtk_box_pack_start(GTK_BOX(as->drive_status[i].box), (GtkWidget *)as->drive_status[i].led, FALSE, FALSE, 4);
            gtk_widget_show(as->drive_status[i].led);

            /* Led1 for double Led drive */
            as->drive_status[i].led1_pixmap = gdk_pixmap_new(_ui_top_level->window, LED_WIDTH / 2, LED_HEIGHT, -1);
            as->drive_status[i].led1 = gtk_image_new_from_pixmap(as->drive_status[i].led1_pixmap, NULL);
            gtk_widget_set_size_request(as->drive_status[i].led1, LED_WIDTH / 2, LED_HEIGHT);
            gtk_box_pack_start(GTK_BOX(as->drive_status[i].box), (GtkWidget *)as->drive_status[i].led1, FALSE, FALSE, 1);
            gtk_widget_show(as->drive_status[i].led1);

            /* Led2 for double Led drive */
            as->drive_status[i].led2_pixmap = gdk_pixmap_new(_ui_top_level->window, LED_WIDTH / 2, LED_HEIGHT, -1);
            as->drive_status[i].led2 = gtk_image_new_from_pixmap(as->drive_status[i].led2_pixmap, NULL);
            gtk_widget_set_size_request(as->drive_status[i].led2, LED_WIDTH / 2, LED_HEIGHT);
            gtk_box_pack_start(GTK_BOX(as->drive_status[i].box), (GtkWidget *)as->drive_status[i].led2, FALSE, FALSE, 1);
            gtk_widget_show(as->drive_status[i].led2);

            /* Pack everything together */
            gtk_box_pack_start(GTK_BOX(drive_box), as->drive_status[i].event_box, FALSE, FALSE, 0);

            gtk_widget_set_events(as->drive_status[i].event_box, GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_ENTER_NOTIFY_MASK);
            g_signal_connect(G_OBJECT(as->drive_status[i].event_box), "button-press-event", G_CALLBACK(fliplist_popup_cb), (gpointer)(int_to_void_ptr(i)));
            gtk_widget_show(as->drive_status[i].event_box);
        }

        gtk_widget_show(drive_box);
        gtk_box_pack_start(GTK_BOX(status_bar), drive_box, FALSE, FALSE, 0);

        /* tape stuff */
        as->tape_status.event_box = gtk_event_box_new();

        frame = gtk_frame_new(NULL);
        gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);

        as->tape_status.box = gtk_hbox_new(FALSE, 0);
        gtk_container_add(GTK_CONTAINER(frame), as->tape_status.box);
        gtk_widget_show(as->tape_status.box);

        gtk_container_add(GTK_CONTAINER(as->tape_status.event_box), frame);
        gtk_widget_show(frame);

        gtk_widget_set_tooltip_text(GTK_WIDGET(as->tape_status.box->parent->parent), "");

        /* Tape Label */
        as->tape_status.label = gtk_label_new(_("Tape 000"));
        gtk_container_add(GTK_CONTAINER(as->tape_status.box), as->tape_status.label);
        gtk_misc_set_alignment(GTK_MISC (as->tape_status.label), 0, -1);
        gtk_widget_show(as->tape_status.label);

        /* Tape control */
        as->tape_status.control_pixmap = gdk_pixmap_new(_ui_top_level->window, CTRL_WIDTH, CTRL_HEIGHT, -1);
        as->tape_status.control = gtk_image_new_from_pixmap(as->tape_status.control_pixmap, NULL);
        gtk_widget_set_size_request(as->tape_status.control, CTRL_WIDTH, CTRL_HEIGHT);
        gtk_box_pack_start(GTK_BOX(as->tape_status.box), as->tape_status.control, FALSE, FALSE, 4);
        gtk_widget_show(as->tape_status.control);

        gtk_widget_set_events(as->tape_status.event_box, GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_ENTER_NOTIFY_MASK);
        g_signal_connect(G_OBJECT(as->tape_status.event_box), "button-press-event", G_CALLBACK(tape_popup_cb), (gpointer)NULL);

        gtk_box_pack_start(GTK_BOX(status_bar), as->tape_status.event_box, FALSE, FALSE, 0);
        gtk_widget_show(as->tape_status.event_box);
        gtk_widget_show(status_bar);

        for (i = 0; i < NUM_DRIVES; i++) {
#if 0
            int ih, iw;

            gdk_window_get_size_request(((GtkWidget *)as->drive_status[i].image)->window, &iw, &ih);
            gtk_widget_set_size_request(as->drive_status[i].image, width / 3, ih);
#endif
            gtk_widget_hide(as->drive_status[i].event_box);	/* Hide Drive widget */
            gdk_window_set_cursor(as->drive_status[i].event_box->window, gdk_cursor_new (GDK_HAND1)); 
        }
        gtk_widget_hide(as->tape_status.event_box);	/* Hide Tape widget */
        gdk_window_set_cursor(as->tape_status.event_box->window, gdk_cursor_new(GDK_HAND1)); 
    }

    /* finalize event-box */
    gdk_window_set_cursor(event_box->window, gdk_cursor_new(GDK_HAND1)); 

    lib_free(empty);

    return status_bar;
}

#ifdef USE_XF86_EXTENSIONS
int x11ui_get_display_depth(void)
{
    return depth;
}

Display *x11ui_get_display_ptr(void)
{
    return display;
}

Window x11ui_get_X11_window(void)
{
    if (_ui_top_level->window) {
        return GDK_WINDOW_XID(_ui_top_level->window);
    } else {
        return 0;
    }
}

int x11ui_get_screen(void)
{
    return screen;
}
#endif

gboolean kbd_event_handler(GtkWidget *w, GdkEvent *report,gpointer gp);

static void build_screen_canvas_widget(video_canvas_t *c)
{
    GtkWidget *new_canvas = gtk_drawing_area_new();

    /* if the eventbox already has a child, get rid of it, we are resizing */
    GtkWidget *kid = gtk_bin_get_child(GTK_BIN(c->pane));
    if (kid != NULL) {
        gtk_container_remove(GTK_CONTAINER(c->pane), kid);
    }

#ifdef HAVE_HWSCALE
    if (c->videoconfig->hwscale) {
        GdkGLConfig *gl_config = gdk_gl_config_new_by_mode(GDK_GL_MODE_RGBA | GDK_GL_MODE_DOUBLE);

        if (gl_config == NULL) {
            log_warning(ui_log, "HW scaling will not be available");
            c->videoconfig->hwscale = 0;
            resources_set_int("HwScalePossible", 0);
        } else {
            if (!gtk_widget_set_gl_capability(GTK_WIDGET(new_canvas), gl_config, NULL, TRUE, GDK_GL_RGBA_TYPE)) {
                g_critical("Failed to add gl capability");
            }
        }
    }
#endif
    /* supress events, add mask later */
    gtk_widget_set_events(new_canvas, 0);
    /* XVideo must be refreshed when the application window is moved. */
    g_signal_connect(G_OBJECT(new_canvas), "configure-event", G_CALLBACK(configure_callback_canvas), (void*)c);
    g_signal_connect(G_OBJECT(new_canvas), "expose-event", G_CALLBACK(exposure_callback_canvas), (void*)c);
    g_signal_connect(G_OBJECT(new_canvas), "enter-notify-event", G_CALLBACK(enter_window_callback), (void *)c);
    g_signal_connect(G_OBJECT(new_canvas), "leave-notify-event", G_CALLBACK(leave_window_callback), (void *)c);
    g_signal_connect(G_OBJECT(new_canvas), "focus-out-event", G_CALLBACK(leave_window_callback), (void *)c);
    g_signal_connect(G_OBJECT(new_canvas), "map-event", G_CALLBACK(map_callback), NULL);
    g_signal_connect(G_OBJECT(new_canvas), "button-press-event", G_CALLBACK(mouse_handler), (void *) c);
    g_signal_connect(G_OBJECT(new_canvas), "button-release-event", G_CALLBACK(mouse_handler), (void *) c);
    g_signal_connect(G_OBJECT(new_canvas), "motion-notify-event", G_CALLBACK(mouse_handler), (void *) c);
    g_signal_connect(G_OBJECT(new_canvas), "key-press-event", G_CALLBACK(kbd_event_handler), (void *) c);
    g_signal_connect(G_OBJECT(new_canvas), "key-release-event", G_CALLBACK(kbd_event_handler), (void *) c);
    g_signal_connect(G_OBJECT(new_canvas), "focus-in-event", G_CALLBACK(enter_window_callback), (void *) c);

    if (c->videoconfig->hwscale) {
        /* For hwscale, it's a feature that new_canvas must bloat to 100% size
         * of the containing GtkEventWindow. Unfortunately, for the other
         * path, it's a PITA. */
        gtk_container_add(GTK_CONTAINER(c->pane), new_canvas);
    } else {
        /* Believe it or not, but to get a gtkdrawingarea of fixed dimensions
         * with a black background within our layout vbox requires this:
         *
         * toplvl < ui   < black bg < centering < SCREEN HERE
         * window < vbox < eventbox < hbox<vbox < drawingarea.
         *
         * We do this to make fullscreen work. More gory details in the
         * x11ui_fullscreen about how "nice" that is to get to work. */
        GtkWidget *canvascontainer1 = gtk_hbox_new(FALSE, 0);
        gtk_widget_show(canvascontainer1);
        gtk_container_add(GTK_CONTAINER(c->pane), canvascontainer1);
        GtkWidget *canvascontainer2 = gtk_vbox_new(FALSE, 0);
        gtk_widget_show(canvascontainer2);
        gtk_box_pack_start(GTK_BOX(canvascontainer1), canvascontainer2, TRUE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(canvascontainer2), new_canvas, TRUE, FALSE, 0);
    }

    gtk_widget_show(new_canvas);
    GTK_WIDGET_SET_FLAGS(new_canvas, GTK_CAN_FOCUS);
    gtk_widget_grab_focus(new_canvas);
    c->emuwindow = new_canvas;

    gtk_widget_add_events(new_canvas,
                          GDK_LEAVE_NOTIFY_MASK |
                          GDK_ENTER_NOTIFY_MASK |
                          GDK_BUTTON_PRESS_MASK |
                          GDK_BUTTON_RELEASE_MASK |
                          GDK_KEY_PRESS_MASK |
                          GDK_KEY_RELEASE_MASK |
                          GDK_FOCUS_CHANGE_MASK |
                          GDK_POINTER_MOTION_MASK |
                          GDK_STRUCTURE_MASK |
                          GDK_EXPOSURE_MASK);
}

/* Create a shell with a canvas widget in it.  */
int ui_open_canvas_window(video_canvas_t *c, const char *title, int w, int h, int no_autorepeat)
{
    GtkWidget *new_window, *topmenu, *panelcontainer, *sb, *pal_ctrl_widget = NULL;
    GtkAccelGroup* accel;
    GdkColor black = { 0, 0, 0, 255 };
    int i;
    gint window_width, window_height, window_xpos, window_ypos;

    DBG(("ui_open_canvas_window (w: %d h: %d)", w, h));

    if (++num_app_shells > MAX_APP_SHELLS) {
        log_error(ui_log, "Maximum number of toplevel windows reached.");
        return -1;
    }

    new_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* supress events, add mask later */
    gtk_widget_set_events(new_window, 0);

    if (!_ui_top_level) {
        _ui_top_level = new_window;
    }

    panelcontainer = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(new_window), panelcontainer);
    gtk_widget_show(panelcontainer);

    topmenu = gtk_menu_bar_new();
    gtk_widget_show(topmenu);
    g_signal_connect(G_OBJECT(topmenu), "button-press-event", G_CALLBACK(update_menu_cb), NULL);
    gtk_box_pack_start(GTK_BOX(panelcontainer), topmenu, FALSE, TRUE, 0);

    c->pane = gtk_event_box_new();
    gtk_widget_modify_bg(c->pane, GTK_STATE_NORMAL, &black);
    gtk_box_pack_start(GTK_BOX(panelcontainer), c->pane, TRUE, TRUE, 0);
    gtk_widget_show(c->pane);

    gtk_widget_show(new_window);
    if (machine_class == VICE_MACHINE_VSID) {
        GtkWidget *new_canvas = build_vsid_ctrl_widget();
        gtk_container_add(GTK_CONTAINER(c->pane), new_canvas);
        gtk_widget_show(new_canvas);
    } else {
        build_screen_canvas_widget(c);
        c->app_shell = num_app_shells - 1;
    }

    sb = ui_create_status_bar(panelcontainer);
    if (machine_class != VICE_MACHINE_VSID) {
        pal_ctrl_widget = build_pal_ctrl_widget(c);
        gtk_box_pack_end(GTK_BOX(panelcontainer), pal_ctrl_widget, FALSE, FALSE, 0);
        gtk_widget_hide(pal_ctrl_widget);
    }
 
    if (no_autorepeat) {
        g_signal_connect(G_OBJECT(new_window), "enter-notify-event", G_CALLBACK(ui_autorepeat_off), NULL);
        g_signal_connect(G_OBJECT(new_window), "leave-notify-event", G_CALLBACK(ui_autorepeat_on), NULL);
    }
    g_signal_connect(G_OBJECT(new_window), "configure-event", G_CALLBACK(configure_callback_app), (void*)c);
    g_signal_connect(G_OBJECT(new_window), "enter-notify-event", G_CALLBACK(kbd_event_handler), NULL);
    g_signal_connect(G_OBJECT(new_window), "leave-notify-event", G_CALLBACK(kbd_event_handler), NULL);
    g_signal_connect(G_OBJECT(new_window), "delete_event", G_CALLBACK(delete_event), NULL);
    g_signal_connect(G_OBJECT(new_window), "destroy_event", G_CALLBACK(delete_event), NULL);

    accel = gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(new_window), accel);

    app_shells[num_app_shells - 1].shell = new_window;
    app_shells[num_app_shells - 1].title = lib_stralloc(title);
    app_shells[num_app_shells - 1].topmenu = topmenu;
    app_shells[num_app_shells - 1].accel = accel;
    app_shells[num_app_shells - 1].status_bar = sb;
    app_shells[num_app_shells - 1].pal_ctrl = pal_ctrl_widget;

    gtk_window_set_title(GTK_WINDOW(new_window), title);

    if (machine_class == VICE_MACHINE_VSID) {
        gtk_window_resize(GTK_WINDOW(new_window), VSID_WINDOW_MINW, VSID_WINDOW_MINH);
    } else {
        /*
            FIXME: WindowXXX should be per window (for x128)
         */
        resources_get_int("WindowWidth", &window_width);
        resources_get_int("WindowHeight", &window_height);
        DBG(("ui_open_canvas_window (winw: %d winh: %d)", window_width, window_height));
        if (window_width > 0 && window_height > 0) {
            gtk_window_resize(GTK_WINDOW(new_window), window_width, window_height);
        }
        resources_get_int("WindowXpos", &window_xpos);
        resources_get_int("WindowYpos", &window_ypos);
        DBG(("ui_open_canvas_window (winx: %d winy: %d)", window_xpos, window_ypos));
        if ((window_xpos < 0) || (window_ypos < 0)) {
            window_xpos = 0;
            window_ypos = 0;
        }
        gtk_window_move(GTK_WINDOW(new_window), window_xpos, window_ypos);

        if (!app_gc) {
            app_gc = gdk_gc_new(new_window->window);
        }

        if (uicolor_alloc_colors(c) < 0) {
            return -1;
        }

        /* This is necessary because the status might have been set before we
        actually open the canvas window. e.g. by commandline */
        ui_enable_drive_status(enabled_drives, drive_active_led);

        /* make sure that all drive status widgets are initialized.
        This is needed for proper dual disk/dual led drives (8050, 8250). */
        for (i = 0; i < NUM_DRIVES; i++) {
            ui_display_drive_led(i, 1000, 1000);
        }

        ui_style_red = gtk_style_new();
        ui_style_red->fg[GTK_STATE_NORMAL] = drive_led_on_red_pixel;
        ui_style_red->fg[GTK_STATE_ACTIVE] = drive_led_on_red_pixel;
        ui_style_red->fg[GTK_STATE_SELECTED] = drive_led_on_red_pixel;
        ui_style_red->fg[GTK_STATE_PRELIGHT] = drive_led_on_red_pixel;
        gtk_widget_set_style(video_ctrl_checkbox_label, ui_style_red);
        gtk_widget_set_style(event_rec_checkbox_label, ui_style_red);

        ui_style_green = gtk_style_new();
        ui_style_green->fg[GTK_STATE_NORMAL] = drive_led_on_green_pixel;
        ui_style_green->fg[GTK_STATE_ACTIVE] = drive_led_on_green_pixel;
        ui_style_green->fg[GTK_STATE_SELECTED] = drive_led_on_green_pixel;
        ui_style_green->fg[GTK_STATE_PRELIGHT] = drive_led_on_green_pixel;
        gtk_widget_set_style(event_playback_checkbox_label, ui_style_green);

        initBlankCursor();
        gtk_init_lightpen();

        c->offx = c->geometry->screen_size.width - w;
        ui_cached_video_canvas = c;
    }

    gtk_widget_add_events(new_window,
                            GDK_LEAVE_NOTIFY_MASK |
                            GDK_ENTER_NOTIFY_MASK |
                            GDK_BUTTON_PRESS_MASK |
                            GDK_BUTTON_RELEASE_MASK |
                            GDK_KEY_PRESS_MASK |
                            GDK_KEY_RELEASE_MASK |
                            GDK_FOCUS_CHANGE_MASK |
                            GDK_POINTER_MOTION_MASK |
                            GDK_EXPOSURE_MASK);

    return 0;
}

/* Attach `w' as the left menu of all the current open windows.  */
void ui_set_left_menu(ui_menu_entry_t *menu)
{
    int i;
    static GtkAccelGroup *accel;

    if (accel) {
        g_object_unref(accel);
    }

    accel = gtk_accel_group_new();
    for (i = 0; i < num_app_shells; i++) {
        gtk_window_add_accel_group (GTK_WINDOW (app_shells[i].shell), accel);
    }

    if (left_menu != NULL) {
        gtk_widget_destroy(left_menu);
    }
    left_menu = gtk_menu_new();
    ui_menu_create(left_menu, accel, "LeftMenu", menu);
}

/* Attach `w' as the right menu of all the current open windows.  */
void ui_set_right_menu(ui_menu_entry_t *menu)
{
    int i;
    static GtkAccelGroup *accel;

    if (accel) {
        g_object_unref(accel);
    }
    
    accel = gtk_accel_group_new();
    for (i = 0; i < num_app_shells; i++) {
        gtk_window_add_accel_group (GTK_WINDOW (app_shells[i].shell), accel);
    }

    if (right_menu != NULL) {
        gtk_widget_destroy(right_menu);
    }
    right_menu = gtk_menu_new();
    ui_menu_create(right_menu, accel, "RightMenu", menu);
}

void ui_set_topmenu(ui_menu_entry_t *menu)
{
    int i;

    for (i = 0; i < num_app_shells; i++) {
        gtk_container_foreach(GTK_CONTAINER(app_shells[i].topmenu), (GtkCallback)gtk_widget_destroy, NULL);
    }

    for (i = 0; i < num_app_shells; i++) {
        ui_menu_create(app_shells[i].topmenu, app_shells[i].accel, "TopLevelMenu", menu);
    }
}

void ui_set_speedmenu(ui_menu_entry_t *menu)
{
    if (speed_menu) {
        gtk_widget_destroy(speed_menu);
    }
    speed_menu = gtk_menu_new();
    ui_menu_create(speed_menu, NULL, "SpeedMenu", menu);
}

void ui_set_application_icon(const char *icon_data[])
{
    int i;
    GdkPixmap *icon;
    
    icon = gdk_pixmap_create_from_xpm_d(_ui_top_level->window, NULL, NULL, (char **)icon_data);

    for (i = 0; i < num_app_shells; i++) {
        gdk_window_set_icon(app_shells[i].shell->window, NULL, icon, NULL);
    }
}

/* ------------------------------------------------------------------------- */

void ui_exit(void)
{
    ui_button_t b;
    int value;
    char *s = util_concat("Exit ", machine_name, _(" emulator"), NULL);

#ifdef HAVE_FULLSCREEN
    fullscreen_suspend(1);
#endif
    resources_get_int("ConfirmOnExit", &value);
    if (value) {
        b = ui_ask_confirmation(s, _("Do you really want to exit?"));
    } else {
        b = UI_BUTTON_YES;
    }

    if (b == UI_BUTTON_YES) {
        resources_get_int("SaveResourcesOnExit", &value);
        if (value) {
            b = ui_ask_confirmation(s, _("Save the current settings?"));
            if (b == UI_BUTTON_YES) {
                if (resources_save(NULL) < 0) {
                    ui_error(_("Cannot save settings."));
                }
            } else if (b == UI_BUTTON_CANCEL) {
                lib_free(s);
                return;
            }
        }
        ui_autorepeat_on();
        ui_restore_mouse();
#ifdef HAVE_FULLSCREEN
        fullscreen_suspend(0);
#endif
        ui_dispatch_events();

        lib_free(s);
        exit(0);
    }
    lib_free(s);
    vsync_suspend_speed_eval();
}

/* ------------------------------------------------------------------------- */

/* Show the speed index to the user.  */
void ui_display_speed(float percent, float framerate, int warp_flag)
{
    int i;
    char str[256];
    int percent_int = (int)(percent + 0.5);
    int framerate_int = (int)(framerate + 0.5);

    for (i = 0; i < num_app_shells; i++) {
        if (!percent) {
            gtk_label_set_text(app_shells[i].speed_label, warp_flag ? _("(warp)") : "");
        } else {
            sprintf(str, "%d%%, %d fps %s", percent_int, framerate_int, warp_flag ? _("(warp)") : "");
            gtk_label_set_text(app_shells[i].speed_label, str);
        }
    }
    if (statustext_display_time > 0) {
        statustext_display_time--;
        if (statustext_display_time == 0) {
            statusbar_setstatustext("");
        }
    }
    if (machine_class != VICE_MACHINE_VSID) {
        if (!screenshot_is_recording()) {
            ui_update_video_checkbox(video_ctrl_checkbox, NULL);
        }
    }
}

/* ------------------------------------------------------------------------- */

/* drive stuff */
void ui_enable_drive_status(ui_drive_enable_t enable, int *drive_led_color)
{
    int i, j;

    enabled_drives = enable;
    drive_active_led = drive_led_color;

    for (i = 0; i < num_app_shells; i++) {
        for (j = 0; j < NUM_DRIVES; j++) {
            if (enabled_drives && (enabled_drives & (1 << j))) {
                /* enabled + active drive */
                gtk_widget_show(app_shells[i].drive_status[j].event_box);
                gtk_widget_show(app_shells[i].drive_status[j].track_label);
                if (drive_num_leds(j) == 1) {
                    gtk_widget_show(app_shells[i].drive_status[j].led);
                    gtk_widget_hide(app_shells[i].drive_status[j].led1);
                    gtk_widget_hide(app_shells[i].drive_status[j].led2);
                } else {
                    gtk_widget_hide(app_shells[i].drive_status[j].led);
                    gtk_widget_show(app_shells[i].drive_status[j].led1);
                    gtk_widget_show(app_shells[i].drive_status[j].led2);
                }
            } else if (!enabled_drives && (strcmp(last_attached_images[j], "") != 0)) {
                gtk_widget_show(app_shells[i].drive_status[j].event_box);
                gtk_widget_hide(app_shells[i].drive_status[j].track_label);
                gtk_widget_hide(app_shells[i].drive_status[j].led);
                gtk_widget_hide(app_shells[i].drive_status[j].led1);
                gtk_widget_hide(app_shells[i].drive_status[j].led2);
            } else {
                gtk_widget_hide(app_shells[i].drive_status[j].event_box);
            }
        }
#if 0
        /* enable this when a dynamic multiline status bar is needed.
           be aware that x128 has weird sized windows on startup, because of 
           the uninitialized canvas window(-size) during startup */
        /* resize according to new needs */
        {
            int width, height;

            gdk_window_get_size(app_shells[i].canvas->window, &width, &height);
            ui_resize_canvas_window(app_shells[i].canvas, width, height);
        }
#endif
    }
}

void ui_display_drive_track(unsigned int drive_number, unsigned int drive_base, unsigned int half_track_number)
{
    int i;
    static char str[256];
    double track_number = (double)half_track_number / 2.0;

    sprintf(str, "%.1f", (double)track_number);

    for (i = 0; i < num_app_shells; i++) {
        gtk_label_set_text(GTK_LABEL(app_shells[i].drive_status[drive_number].track_label), str);
    }
}

void ui_display_drive_led(int drive_number, unsigned int led_pwm1, unsigned int led_pwm2)
{
    int status = 0;
    int i, ci1, ci2;

    GdkColor *color;

    if (led_pwm1 > 100) {
        status |= 1;
    }
    if (led_pwm2 > 100) {
        status |= 2;
    }

    ci1 = (int)(((float)led_pwm1 / MAX_PWM) * 16) - 1;
    ci2 = (int)(((float)led_pwm2 / MAX_PWM) * 16) - 1;
    if (ci1 < 0) {
        ci1 = 0;
    }
    if (ci2 < 0) {
        ci2 = 0;
    }

    for (i = 0; i < num_app_shells; i++) {
        drive_status_widget *ds = &app_shells[i].drive_status[drive_number];

        color = status ? (drive_active_led[drive_number] ? &drive_led_on_green_pixels[ci1] : &drive_led_on_red_pixels[ci1]) : &drive_led_off_pixel;
        gdk_gc_set_rgb_fg_color(app_gc, color);
        gdk_draw_rectangle(ds->led_pixmap, app_gc, TRUE, 0, 0, LED_WIDTH, LED_HEIGHT);
        gtk_widget_queue_draw(ds->led);

        color = (status & 1) ? (drive_active_led[drive_number] ? &drive_led_on_green_pixels[ci1] : &drive_led_on_red_pixels[ci1]) : &drive_led_off_pixel;
        gdk_gc_set_rgb_fg_color(app_gc, color);
        gdk_draw_rectangle(ds->led1_pixmap, app_gc, TRUE, 0, 0, LED_WIDTH / 2, LED_HEIGHT);
        gtk_widget_queue_draw(ds->led1);

        color = (status & 2) ? (drive_active_led[drive_number] ? &drive_led_on_green_pixels[ci2] : &drive_led_on_red_pixels[ci2]) : &drive_led_off_pixel;
        gdk_gc_set_rgb_fg_color(app_gc, color);
        gdk_draw_rectangle(ds->led2_pixmap, app_gc, TRUE, 0, 0, LED_WIDTH / 2, LED_HEIGHT);
        gtk_widget_queue_draw(ds->led2);
    }
}

void ui_display_drive_current_image(unsigned int drive_number, const char *image)
{
    int i;
    char *name;

    if (console_mode) {
        return;
    }

    /* FIXME: Allow more than two drives.  */
    if (drive_number >= NUM_DRIVES) {
        return;
    }

    strcpy(&(last_attached_images[drive_number][0]), image);
    util_fname_split(&(last_attached_images[drive_number][0]), NULL, &name);

    if (strcmp(name, "") == 0) {
        lib_free(name);
        name = util_concat("<", _("empty"), ">", NULL);
    }

    for (i = 0; i < num_app_shells; i++) {
#if 0
        gtk_label_set_text(GTK_LABEL(app_shells[i].drive_status[drive_number].image), name);
#endif
        gtk_widget_set_tooltip_text(GTK_WIDGET(app_shells[i].drive_status[drive_number].box->parent->parent), name);
    }
    lib_free(name);

    ui_enable_drive_status(enabled_drives, drive_active_led);
}

/* ------------------------------------------------------------------------- */
/* tape stuff */
void ui_set_tape_status(int tape_status)
{
    static int ts;
    int i;

    if (ts == tape_status) {
        return;
    }
    ts = tape_status;
    for (i = 0; i < num_app_shells; i++) {
        if (ts) {
            gtk_widget_show(app_shells[i].tape_status.event_box);
            gtk_widget_show(app_shells[i].tape_status.control);
        } else {
            if (last_attached_tape) {
                gtk_widget_show(app_shells[i].tape_status.event_box);
                gtk_widget_hide(app_shells[i].tape_status.control);
            } else {
                gtk_widget_hide(app_shells[i].tape_status.event_box);
            }
        }
    }
}

void ui_display_tape_motor_status(int motor)
{   
    if (tape_motor_status == motor) {
        return;
    }
    tape_motor_status = motor;
    ui_display_tape_control_status(-1);
}

void ui_display_tape_control_status(int control)
{
    GdkColor *color;
    static GdkPoint ffw[] = {
        { 0, 0 },
        { CTRL_WIDTH / 2, CTRL_HEIGHT / 2 },
        { CTRL_WIDTH / 2, 0 },
        { CTRL_WIDTH - 1, CTRL_HEIGHT / 2 },
        { CTRL_WIDTH / 2, CTRL_HEIGHT - 1 }, 
        { CTRL_WIDTH / 2, CTRL_HEIGHT / 2 },
        { 0, CTRL_HEIGHT - 1 }
    };

    static GdkPoint rew[] = {
        { 0, CTRL_HEIGHT / 2 },
        { CTRL_WIDTH / 2, 0 },
        { CTRL_WIDTH / 2, CTRL_HEIGHT / 2 },
        { CTRL_WIDTH - 1, 0 },
        { CTRL_WIDTH - 1, CTRL_HEIGHT - 1 },
        { CTRL_WIDTH / 2, CTRL_HEIGHT / 2 },
        { CTRL_WIDTH / 2, CTRL_HEIGHT - 1 }
    };

    static GdkPoint play[] = {
        { 3, 0 },
        { CTRL_WIDTH - 3, CTRL_HEIGHT / 2},
        { 3, CTRL_HEIGHT - 1 }
    };

    static GdkPoint stop[] = {
        { 3, 2 },
        { CTRL_WIDTH - 3, 2 },
        { CTRL_WIDTH - 3, CTRL_HEIGHT - 2 },
        { 3, CTRL_HEIGHT - 2 }
    };

    GdkPoint *p;
    int i, num;

    if (control < 0) {
        control = tape_control_status;
    } else {
        tape_control_status = control;
    }

    color = tape_motor_status ? &motor_running_pixel : &drive_led_off_pixel;

    /* Set background color depending on motor status */
    gdk_gc_set_rgb_fg_color(app_gc, color);
    for (i = 0; i < num_app_shells; i++) {
        tape_status_widget *ts = &app_shells[i].tape_status;

        gdk_draw_rectangle(ts->control_pixmap, app_gc, TRUE, 0, 0, CTRL_WIDTH, CTRL_HEIGHT);
    }

    switch (control) {
        case DATASETTE_CONTROL_START:
            num = 3;
            p = play;
            break;
        case DATASETTE_CONTROL_FORWARD:
            num = 7;
            p = ffw;
            break;
        case DATASETTE_CONTROL_REWIND:
            num = 7;
            p = rew;
            break;
        case DATASETTE_CONTROL_RECORD:
            gdk_gc_set_rgb_fg_color(app_gc, &drive_led_on_red_pixel);
            for (i = 0; i < num_app_shells; i++) {
                tape_status_widget *ts = &app_shells[i].tape_status;

                gdk_draw_arc(ts->control_pixmap, app_gc, TRUE, 3, 1, CTRL_WIDTH - 6, CTRL_HEIGHT - 2, 0, 360 * 64);
                gtk_widget_queue_draw(ts->control);
            }
            gdk_flush();
            return;
        default:
            num = 4;
            p = stop;
            break;
    }

    color = &tape_control_pixel;
    gdk_gc_set_rgb_fg_color(app_gc, color);
    for (i = 0; i < num_app_shells; i++) {
        tape_status_widget *ts = &app_shells[i].tape_status;
        gdk_draw_polygon(ts->control_pixmap, app_gc, TRUE, p, num);

        gtk_widget_queue_draw(ts->control);
    }
    gdk_flush();
}

void ui_display_tape_counter(int counter)
{
    static char label[1024];
    int i;

    /* Translators: the string is fixed with 1024 byte! Don't exceed this
       limit !*/
    sprintf(label, _("Tape %03d"), counter % 1000);
    for (i = 0; i < num_app_shells; i++) {
        gtk_label_set_text(GTK_LABEL(app_shells[i].tape_status.label), label);
    }
}

void ui_display_tape_current_image(const char *image)
{
    char *name;
    int i;

    lib_free(last_attached_tape);
    last_attached_tape = lib_stralloc(image);
    util_fname_split(image, NULL, &name);

    for (i = 0; i < num_app_shells; i++) {
        gtk_widget_set_tooltip_text(GTK_WIDGET(app_shells[i].tape_status.box->parent->parent), name);
    }
    lib_free(name);
}

/* ------------------------------------------------------------------------- */
void ui_display_recording(int recording_status)
{
    if (recording_status) {
        gtk_widget_show(event_rec_checkbox);
    } else {
        gtk_widget_hide(event_rec_checkbox);
    }
}

void ui_display_playback(int playback_status, char *version)
{
    if (playback_status) {
        gtk_widget_show(event_playback_checkbox);
    } else {
        gtk_widget_hide(event_playback_checkbox);
    }
}

/* Display a message in the title bar indicating that the emulation is
   paused.  */
void ui_display_paused(int flag)
{
    int i;
    char str[1024];

    for (i = 0; i < num_app_shells; i++) {
        if (flag) {
            sprintf(str, _("%s (paused)"), app_shells[i].title);
            gtk_window_set_title(GTK_WINDOW(app_shells[i].shell), str);
        } else {
            gtk_window_set_title(GTK_WINDOW(app_shells[i].shell), app_shells[i].title);
        }
    }
}

/* Dispatch the next Xt event.  If not pending, wait for it. */
void ui_dispatch_next_event(void)
{
    gtk_main_iteration();
}

/* Dispatch all the pending UI events. */
void ui_dispatch_events(void)
{
    while (gtk_events_pending()) {
        ui_dispatch_next_event();
    }
}

void x11ui_fullscreen(int i)
{
    GtkWidget *s;
    int key = 0;

    /* special case of x128, where we have 2 shells is handled
       by checking the related resource */
    if (strncmp(machine_name, "C128", 4) == 0) {
        resources_get_int("40/80ColumnKey", &key);
    }
    s = _ui_top_level = gtk_widget_get_toplevel(app_shells[key].shell);

    if (i) {
        /* window managers (bug detected on compiz 0.7.4) may ignore
         * fullscreen requests for windows not visible inside the screen.
         * This can happen especially when using XRandR to resize the desktop.
         * This tries to workaround that problem by ensuring^Whinting that the
         * window should be placed to the top-left corner. GTK/X sucks. */
        gtk_window_move(GTK_WINDOW(s), 0, 0);
        gtk_window_fullscreen(GTK_WINDOW(s));
        gtk_window_present(GTK_WINDOW(s));
    } else {
        gtk_window_unfullscreen(GTK_WINDOW(s));
        mouse_cursor_grab(0, NULL);
    }

    DBG(("x11ui_fullscreen done"));
}

int ui_fullscreen_statusbar(struct video_canvas_s *canvas, int enable)
{
#ifdef HAVE_FULLSCREEN
    app_shell_type *appshell = &app_shells[canvas->app_shell];
#endif
    int j;

    if (enable) {
        for (j = 0; j < num_app_shells; j++) {
            gtk_widget_show(app_shells[j].status_bar);
            gtk_widget_show(app_shells[j].topmenu);
        }
#ifdef HAVE_FULLSCREEN
        canvas->fullscreenconfig->ui_border_top = appshell->topmenu->allocation.height;
        canvas->fullscreenconfig->ui_border_bottom = appshell->status_bar->allocation.height;
#endif
    } else {
        for (j = 0; j < num_app_shells; j++) {
            gtk_widget_hide(app_shells[j].status_bar);
            gtk_widget_hide(app_shells[j].topmenu);
        }
#ifdef HAVE_FULLSCREEN
        canvas->fullscreenconfig->ui_border_top = 0;
        canvas->fullscreenconfig->ui_border_bottom = 0;
#endif
    }
    return 0;
}

static void toggle_aspect(video_canvas_t *canvas)
{
    int keep_aspect_ratio, flags = 0;
    app_shell_type *appshell = &app_shells[canvas->app_shell];

    DBG(("toggle_aspect fs:%d", canvas->fullscreenconfig->enable));
    if ((appshell != NULL) && (appshell->shell != NULL)) {
#ifdef HAVE_FULLSCREEN
        if (!canvas->fullscreenconfig->enable) {
#endif
            resources_get_int("KeepAspectRatio", &keep_aspect_ratio);
            if (keep_aspect_ratio) {
                flags |= GDK_HINT_ASPECT;
                if (appshell->geo.max_width) {
                    flags |= GDK_HINT_MAX_SIZE;
                }
            }
            gtk_window_set_geometry_hints (GTK_WINDOW(appshell->shell), NULL, &appshell->geo, GDK_HINT_MIN_SIZE | flags);
#ifdef HAVE_FULLSCREEN
        }
#endif
    }
}

static gfloat get_aspect(video_canvas_t *canvas)
{
    int keep_aspect_ratio, true_aspect_ratio;
    resources_get_int("KeepAspectRatio", &keep_aspect_ratio);
    if (keep_aspect_ratio) {
        resources_get_int("TrueAspectRatio", &true_aspect_ratio);
        if (true_aspect_ratio) {
#ifdef HAVE_HWSCALE
            if (canvas->videoconfig->hwscale) {
                return canvas->geometry->pixel_aspect_ratio;
            }
#endif
        }
        return 1.0f;
    }
    return 0.0f;
}

static void setup_aspect(video_canvas_t *canvas)
{
    gfloat aspect, taspect;
    int w, h, winw, winh;
    app_shell_type *appshell = &app_shells[canvas->app_shell];
    GtkWidget *win;
    GtkWidget *topmenu;
    GtkWidget *sb;
    GtkWidget *palctrl;

    DBG(("setup_aspect fullscreen:%d", canvas->fullscreenconfig->enable));

    if (appshell == NULL) {
        return;
    }

    win = appshell->shell;
    topmenu = appshell->topmenu;
    sb = appshell->status_bar;
    palctrl = appshell->pal_ctrl;

    if ((win == NULL) || (topmenu == NULL) || (sb == NULL) || (palctrl == NULL)) {
        return;
    }

    /* get size of drawing buffer */
    w = canvas->draw_buffer->canvas_width;
    h = canvas->draw_buffer->canvas_height;
    if (canvas->videoconfig->doublesizex) {
        w *= (canvas->videoconfig->doublesizex + 1);
    }
    if (canvas->videoconfig->doublesizey) {
        h *= (canvas->videoconfig->doublesizey + 1);
    }
    /* calculate unscaled size of window */
    winw = w;
    winh = h + topmenu->allocation.height + sb->allocation.height;

#if GTK_CHECK_VERSION(2,18,0)
    if (gtk_widget_get_visible(palctrl)) {
        winh += palctrl->allocation.height;
    }
#else
    if (GTK_WIDGET_VISIBLE(palctrl)) {
        winh += palctrl->allocation.height;
    }
#endif

    /* default geometry hints, no scaling, 1:1 aspect */
    appshell->geo.min_width = winw;
    appshell->geo.min_height = winh;
    appshell->geo.max_width = winw;
    appshell->geo.max_height = winh;
    appshell->geo.min_aspect = 1.0f;
    appshell->geo.max_aspect = 1.0f;

#ifdef HAVE_FULLSCREEN
    if (canvas->fullscreenconfig->enable) {
        /* TODO */
    } else {
#endif
        taspect = get_aspect(canvas);
        if (taspect > 0.0f) {
            aspect = ((float)winw * taspect) / ((float)winh);
            appshell->geo.min_aspect = aspect;
            appshell->geo.max_aspect = aspect;
            appshell->geo.min_width = (int)((float)winw * taspect);
            if (canvas->videoconfig->hwscale) {
                appshell->geo.max_width = 0;
                appshell->geo.max_height = 0;
            }
        }
#ifdef HAVE_FULLSCREEN
    }
#endif
}

/* Resize one window. */
void ui_resize_canvas_window(video_canvas_t *canvas, int width, int height)
{
    gint window_width, window_height;
    app_shell_type *appshell;
    int def;

    resources_get_int("WindowWidth", &window_width);
    resources_get_int("WindowHeight", &window_height);

    DBG(("ui_resize_canvas_window (width: %d height: %d  winw: %d winh: %d hwscale:%d)", width, height, window_width, window_height,canvas->videoconfig->hwscale));

    def = 0;
    if (!canvas->videoconfig->hwscale || (window_width < WINDOW_MINW) || (window_height < WINDOW_MINH)) {
        def = 1;
        window_width = width;
        window_height = height;
    }

    appshell = &app_shells[canvas->app_shell];

    build_screen_canvas_widget(canvas);
    if (! canvas->videoconfig->hwscale) {
        gtk_widget_set_size_request(canvas->emuwindow, window_width, window_height);
    }

    if (def) {
        /* maintain aspect ratio */
        setup_aspect(canvas);
        toggle_aspect(canvas);
        /* set initial (properly scaled) window size */
        window_width = appshell->geo.min_width;
        window_height = appshell->geo.min_height;
    }
    gtk_window_resize(GTK_WINDOW(appshell->shell), window_width, window_height);

    resources_set_int("WindowWidth", window_width);
    resources_set_int("WindowHeight", window_height);

    DBG(("ui_resize_canvas_window exit (w:%d h:%d)", window_width, window_height));
}

void x11ui_move_canvas_window(ui_window_t w, int x, int y)
{
    DBG(("x11ui_move_canvas_window x:%d y:%d", x, y));
    gdk_window_move(gdk_window_get_toplevel(w->window), x, y);
    gdk_flush();
}

void x11ui_canvas_position(ui_window_t w, int *x, int *y)
{
    gint tl_x, tl_y, pos_x, pos_y;

    gdk_flush();
    gdk_window_get_position(gdk_window_get_toplevel(w->window), &tl_x, &tl_y);
    gdk_window_get_position(w->window, &pos_x, &pos_y);
    *x = (pos_x + tl_x);
    *y = (pos_y + tl_y);
    DBG(("x11ui_canvas_position x:%d y:%d", *x, *y));
    gdk_window_raise(gdk_window_get_toplevel(w->window));
}

void x11ui_get_widget_size(ui_window_t win, int *w, int *h)
{
    GtkRequisition req;

    gtk_widget_size_request(win, &req);
    *w = (int)req.width;
    *h = (int)req.height;
}

void x11ui_destroy_widget(ui_window_t w)
{
    gtk_widget_destroy(w);
}

/* Enable autorepeat. */
void ui_autorepeat_on(void)
{
}

/* Disable autorepeat. */
void ui_autorepeat_off(void)
{
}

/* ------------------------------------------------------------------------- */

/* Button callbacks.  */

#define DEFINE_BUTTON_CALLBACK(button)                             \
    void cb_##button(GtkWidget *w, ui_callback_data_t client_data) \
    {                                                              \
        *((ui_button_t *)client_data) = button;                    \
    }

    DEFINE_BUTTON_CALLBACK(UI_BUTTON_OK)
    DEFINE_BUTTON_CALLBACK(UI_BUTTON_CANCEL)
    DEFINE_BUTTON_CALLBACK(UI_BUTTON_YES)
    DEFINE_BUTTON_CALLBACK(UI_BUTTON_NO)
    DEFINE_BUTTON_CALLBACK(UI_BUTTON_CLOSE)
    DEFINE_BUTTON_CALLBACK(UI_BUTTON_MON)
    DEFINE_BUTTON_CALLBACK(UI_BUTTON_DEBUG)
    DEFINE_BUTTON_CALLBACK(UI_BUTTON_RESET)
    DEFINE_BUTTON_CALLBACK(UI_BUTTON_HARDRESET)
    DEFINE_BUTTON_CALLBACK(UI_BUTTON_CONTENTS)
    DEFINE_BUTTON_CALLBACK(UI_BUTTON_AUTOSTART)

/* ------------------------------------------------------------------------- */

/* Message Helper */
static void ui_message2(const GtkMessageType type, const char *msg, const char *title)
{
    static GtkWidget* msgdlg;

    vsync_suspend_speed_eval();
    msgdlg = gtk_message_dialog_new(GTK_WINDOW(_ui_top_level), GTK_DIALOG_DESTROY_WITH_PARENT, type, GTK_BUTTONS_OK, msg, NULL);

    ui_popup(msgdlg, title, FALSE);
    gtk_dialog_run(GTK_DIALOG(msgdlg));
    ui_unblock_shells();	/* ui_popdown can't be used in message_boxes */
    gtk_widget_destroy(msgdlg);

    /* still needed ? */
    ui_check_mouse_cursor();
    ui_dispatch_events();
}

/* Report a message to the user.  */
void ui_message(const char *format, ...)
{
    va_list ap;
    char str[1024];

    va_start(ap, format);
    vsprintf(str, format, ap);
    va_end(ap);
    ui_message2(GTK_MESSAGE_INFO, str, _("VICE Message"));
}

/* Report an error to the user.  */
void ui_error(const char *format, ...)
{
    va_list ap;
    char str[1024];

    va_start(ap, format);
    vsprintf(str, format, ap);
    va_end(ap);
    ui_message2(GTK_MESSAGE_ERROR, str, _("VICE Error!"));
}

void ui_make_window_transient(GtkWidget *parent,GtkWidget *window)
{
    gtk_window_set_transient_for(GTK_WINDOW(window), GTK_WINDOW(parent));
#if 0
    gdk_window_set_colormap(window->window, colormap);
#endif
}

/* Report a message to the user, allow different buttons. */
ui_jam_action_t ui_jam_dialog(const char *format, ...)
{
    char str[1024];
    va_list ap;
    static GtkWidget *jam_dialog, *message;
    gint res;

    if (console_mode) {
        va_start(ap, format);
        vfprintf(stderr, format, ap);
        va_end(ap);
        exit(0);
    }

    vsync_suspend_speed_eval();
    jam_dialog = gtk_dialog_new_with_buttons("", NULL, GTK_DIALOG_DESTROY_WITH_PARENT, _("Reset"), 0, _("Hard Reset"), 1, _("Monitor"), 2, _("Continue"), 3, NULL);
    g_signal_connect(G_OBJECT(jam_dialog), "destroy", G_CALLBACK(gtk_widget_destroyed), &jam_dialog);

    va_start(ap, format);
    vsprintf(str, format, ap);
    va_end(ap);
    message = gtk_label_new(str);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(jam_dialog)->vbox), message, TRUE, TRUE, 0);
    gtk_widget_show(message);
    gtk_dialog_set_default_response(GTK_DIALOG(jam_dialog), 0);

    ui_popup(jam_dialog, "VICE", FALSE);
    res = gtk_dialog_run(GTK_DIALOG(jam_dialog));
    ui_popdown(jam_dialog);
    if (jam_dialog) {
        gtk_widget_destroy(jam_dialog);
    }

    ui_dispatch_events();

    switch (res) {
        case 3:
            return UI_JAM_NONE;
        case 2:
            ui_restore_mouse();
#ifdef HAVE_FULLSCREEN
            fullscreen_suspend(0);
#endif
            return UI_JAM_MONITOR;
        case 1:
            return UI_JAM_HARD_RESET;
        case 0:
        default:
            return UI_JAM_RESET;
    }

    return 0;
}

int ui_extend_image_dialog(void)
{
    ui_button_t b;

    vsync_suspend_speed_eval();
    b = ui_ask_confirmation(_("Extend disk image"), (_("Do you want to extend the disk image to 40 tracks?")));
    return (b == UI_BUTTON_YES) ? 1 : 0;
}

UI_CALLBACK(ui_popup_selected_file)
{
    int unit = (vice_ptr_to_int(UI_MENU_CB_PARAM)) >> 24;
    int selected = (vice_ptr_to_int(UI_MENU_CB_PARAM)) & 0x00ffffff;
    char *tmp;

    if (unit > 8) {
        ui_message(_("Autostart not possible for unit %d"), unit);
        return;
    } else if (unit == 8) {
        tmp = lib_stralloc(last_attached_images[0]);
        if (autostart_disk(last_attached_images[0], NULL, selected, AUTOSTART_MODE_RUN) < 0) {
            ui_error(_("Can't autostart selection %d in image %s"), selected, tmp);
        }
        lib_free(tmp);
    } else if (unit == 1) {
        tmp = lib_stralloc(last_attached_tape);
        if (autostart_tape(last_attached_tape, NULL, selected, AUTOSTART_MODE_RUN) < 0) {
            ui_error(_("Can't autostart selection %d in image %s"), selected, tmp);
        }
        lib_free(tmp);
    }
}

static void menu_set_style(GtkWidget *w, gpointer data)
{
    if (GTK_IS_CONTAINER(w)) {
        gtk_container_foreach(GTK_CONTAINER(w), menu_set_style, data);
    } else if (GTK_IS_LABEL(w)) {
        gtk_widget_set_style(w, (GtkStyle *)data);
    }
}

static unsigned char *convert_utf8(unsigned char *s)
{
    unsigned char *d, *r;

    r = d = lib_malloc((size_t)(strlen((char *)s) * 2 + 1));
    while (*s) {
        if (*s < 0x80) {
            *d = *s;
        } else {
            /* special latin1 character handling */
            if (*s == 0xa0) {
                *d = 0x20;
            } else {
                if (*s == 0xad) {
                    *s = 0xed;
                }
                *d++ = 0xc0 | (*s >> 6);
                *d = (*s & ~0xc0) | 0x80;
            }
        }
        s++;
        d++;
    }
    *d = '\0';
    return r;
}

static GtkWidget *rebuild_contents_menu(int unit, const char *name)
{
    ui_menu_entry_t *menu;
    int limit = 16;
    int fno = 0, mask, i;
    char *title, *tmp, *tmp1;
    GtkWidget *menu_widget;
    GtkStyle *menu_entry_style;
    image_contents_t *s;
    image_contents_file_list_t *element;

    s = (unit == 1) ? tapecontents_read(name) : diskcontents_filesystem_read(name);

    if (s == NULL) {
        return (GtkWidget *)NULL;
    }

    menu = g_new(ui_menu_entry_t, limit + 1); /* +1 because we have to store
                                                 NULL as end delimiter */

    mask = unit << 24;
    memset(menu, 0, 2 * sizeof(ui_menu_entry_t));
    util_fname_split(name, NULL, &title);
    for (tmp = title; *tmp; tmp++) {
        *tmp = util_toupper(*tmp);
    }
    menu[fno].string = lib_stralloc(title);
    menu[fno].callback = (ui_callback_t) ui_popup_selected_file;
    menu[fno].callback_data = (ui_callback_data_t)int_to_void_ptr(fno | mask);
    menu[fno].sub_menu = NULL;
    menu[fno].hotkey_keysym = 0;
    menu[fno].hotkey_modifier = 0;
    fno++;
    menu[fno].string = lib_stralloc("--");
    fno++;
    tmp1 = image_contents_to_string(s, !have_cbm_font);
    menu[fno].string = (char *)convert_utf8((unsigned char *)tmp1);
    menu[fno].callback = (ui_callback_t) ui_popup_selected_file;
    menu[fno].callback_data = (ui_callback_data_t)int_to_void_ptr((fno - 2) | mask);
    menu[fno].sub_menu = NULL;
    menu[fno].hotkey_keysym = 0;
    menu[fno].hotkey_modifier = 0;
    lib_free(tmp1);
    fno++;

    for (element = s->file_list; element != NULL; element = element->next) {
        if (fno >= limit) {
            limit *= 2;
            menu = g_renew(ui_menu_entry_t, menu, limit + 1); /* ditto */
        }

        tmp1 = (char *)image_contents_file_to_string(element, !have_cbm_font);

        if (tmp1[0] == '-') {
            tmp1[0] = ' ';	    /* Arg, this is the line magic */ 
        }
        menu[fno].string = (char *)convert_utf8((unsigned char *)tmp1);
        menu[fno].callback = (ui_callback_t) ui_popup_selected_file;
        menu[fno].callback_data = (ui_callback_data_t)int_to_void_ptr((fno - 2) | mask);
        menu[fno].sub_menu = NULL;
        menu[fno].hotkey_keysym = 0;
        menu[fno].hotkey_modifier = 0;
        lib_free(tmp1);
        fno++;
    }
    if (s->blocks_free >= 0) {
        menu[fno].string = lib_msprintf("%d BLOCKS FREE.", s->blocks_free);
        menu[fno].callback = (ui_callback_t) ui_popup_selected_file;
        menu[fno].callback_data = (ui_callback_data_t)int_to_void_ptr((fno - 1) | mask);
        menu[fno].sub_menu = NULL;
        menu[fno].hotkey_keysym = 0;
        menu[fno].hotkey_modifier = 0;
    }
    memset(&menu[fno++], 0, sizeof(ui_menu_entry_t)); /* end delimiter */

    menu_widget = gtk_menu_new();
    ui_menu_create(menu_widget, NULL, title, menu);
    if (fixed_font_desc) {
        menu_entry_style = gtk_style_new();
        pango_font_description_free(menu_entry_style->font_desc);
        menu_entry_style->font_desc = fixed_font_desc;
        gtk_container_foreach(GTK_CONTAINER(menu_widget), menu_set_style, menu_entry_style);
        menu_entry_style = NULL;
    }

    /* Cleanup */
    for (i = 0; i < fno; i++) {
        lib_free(menu[i].string);
    }
    lib_free(title);
    g_free(menu);
    image_contents_destroy(s);

    return menu_widget;
}

static void ui_fill_preview(GtkFileChooser *fs, gpointer data)
{
    char *tmp1, *tmp2;
    image_contents_t *contents = NULL;
    image_contents_file_list_t *element;
    gchar *fname;
    GtkListStore *store;
    GtkTreeIter iter;
    int row;
    read_contents_func_type current_image_contents_func = (read_contents_func_type)data;

    g_return_if_fail(fs != NULL);
    g_return_if_fail(GTK_IS_FILE_CHOOSER(fs));

    fname = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fs));
    if (fname && current_image_contents_func) {
        struct stat st;

        if (stat(fname, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                contents = current_image_contents_func(fname);
            }
        }
        g_free(fname);
    }

    store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(image_preview_list)));
    gtk_list_store_clear(store);

    row = 0;

    if (!contents) {
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 0, (char *)lib_stralloc(_("NO IMAGE CONTENTS AVAILABLE")), 1, row, -1);
    } else {
        tmp1 = image_contents_to_string(contents, !have_cbm_font);
        tmp2 = (char *)convert_utf8((unsigned char *)tmp1);
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 0, tmp2, 1, row++, -1);
        lib_free(tmp1);
        for (element = contents->file_list; element != NULL; element = element->next, row++) {
            tmp1 = (char *)image_contents_file_to_string(element, !have_cbm_font);
            tmp2 = (char *)convert_utf8((unsigned char *)tmp1);
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, 0, tmp2, 1, row, -1);
            lib_free(tmp1);
        }
        if (contents->blocks_free >= 0) {
            tmp2 = lib_msprintf("%d BLOCKS FREE.", contents->blocks_free);
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, 0, tmp2, 1, row, -1);
            lib_free(tmp2);
        }
        image_contents_destroy(contents);
    }
}

static gboolean ui_select_contents_cb(GtkTreeSelection *selection, GtkTreeModel *model, GtkTreePath *path, gboolean path_currently_selected, gpointer userdata)
{
    GtkTreeIter iter;
    int row = 0;

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(model, &iter, 1, &row, -1);
    }
    ui_set_selected_file(row);
    if (row) {
        gtk_button_clicked(GTK_BUTTON(auto_start_button));
    }
    return TRUE;
}

/* File browser. */
char *ui_select_file(const char *title, read_contents_func_type read_contents_func, unsigned int allow_autostart,
                     const char *default_dir, uilib_file_filter_enum_t* patterns, int num_patterns,
                     ui_button_t *button_return, unsigned int show_preview, int *attach_wp, ui_filechooser_t action)
{
    static GtkWidget* file_selector = NULL;
    static char *filesel_dir = NULL;
    char *ret;
    char *current_dir = NULL;
    char *filename = NULL;
    GtkWidget *wp;
    gint res;

    /* reset old selection */
    ui_set_selected_file(0);

    /* we preserve the current directory over the invocations */
    current_dir = ioutil_current_dir(); /* might be changed elsewhere */
    if (filesel_dir != NULL) {
        ioutil_chdir(filesel_dir);
    }

    if (attach_wp) {
        file_selector = build_file_selector(title, &wp, allow_autostart, show_preview, patterns, num_patterns, default_dir, action, read_contents_func);
        GTK_TOGGLE_BUTTON(wp)->active = *attach_wp;
    } else {
        file_selector = build_file_selector(title, NULL, allow_autostart, show_preview, patterns, num_patterns, default_dir, action, read_contents_func);
    }

    g_signal_connect(G_OBJECT(file_selector), "destroy", G_CALLBACK(gtk_widget_destroyed), &file_selector);

    res = gtk_dialog_run(GTK_DIALOG(file_selector));
    switch (res) {
        case GTK_RESPONSE_ACCEPT:
        case GTK_RESPONSE_OK:
            filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_selector));
            *button_return = UI_BUTTON_OK;
            break;
        case GTK_RESPONSE_NO:
            filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_selector));
            *button_return = UI_BUTTON_AUTOSTART;
            break;
        default:
            *button_return = UI_BUTTON_CANCEL;
            auto_start_button = NULL;
            gtk_widget_destroy(file_selector);
            return NULL;
            break;
    }

    if (attach_wp) {
        *attach_wp = GTK_TOGGLE_BUTTON(wp)->active;
    }

    auto_start_button = NULL;
    gtk_widget_destroy(file_selector);

    /* `ret' gets always malloc'ed. caller has to free  */
    if (filename) {
        ret = lib_stralloc(filename);
        g_free(filename);
    } else {
        ret = lib_stralloc("");
    }

    lib_free(filesel_dir);
    filesel_dir = ioutil_current_dir();
    if (current_dir != NULL) {
        ioutil_chdir(current_dir);
        lib_free(current_dir);
    }
    return ret;
}

/* Ask for a string.  The user can confirm or cancel. */
ui_button_t ui_input_string(const char *title, const char *prompt, char *buf, unsigned int buflen)
{
    GtkWidget *input_dialog, *entry, *label;
    gint res;
    ui_button_t ret;

    vsync_suspend_speed_eval();
    input_dialog = gtk_dialog_new_with_buttons(title, NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, NULL);
    g_signal_connect(G_OBJECT(input_dialog), "destroy", G_CALLBACK(gtk_widget_destroyed), &input_dialog);

    entry = gtk_entry_new();

    label = gtk_label_new(prompt);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(input_dialog)->vbox), label, FALSE, FALSE, 0);
    gtk_widget_show(label);

    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(input_dialog)->vbox), entry, FALSE, FALSE, 0);
    gtk_entry_set_text(GTK_ENTRY(GTK_ENTRY(entry)), buf);
    gtk_widget_show(entry);

    gtk_dialog_set_default_response(GTK_DIALOG(input_dialog), GTK_RESPONSE_ACCEPT);
    ui_popup(input_dialog, title, FALSE);
    res = gtk_dialog_run(GTK_DIALOG(input_dialog));
    ui_popdown(input_dialog);

    if ((res == GTK_RESPONSE_ACCEPT) && input_dialog) {
        strncpy(buf, gtk_entry_get_text(GTK_ENTRY(entry)), buflen);
        ret = UI_BUTTON_OK;
    } else {
        ret = UI_BUTTON_CANCEL;
    }

    if (input_dialog) {
        gtk_widget_destroy(input_dialog);
    }

    return ret;
}

/* Display a text to the user. */
void ui_show_text(const char *title, const char *text, int width, int height)
{
    GtkWidget *show_text;

    vsync_suspend_speed_eval();
    show_text = build_show_text((const gchar*)text, width, height);
    g_signal_connect(G_OBJECT(show_text), "destroy", G_CALLBACK(gtk_widget_destroyed), &show_text);
    ui_popup(show_text, title, FALSE);
    gtk_dialog_run(GTK_DIALOG(show_text));
    ui_popdown(show_text);

    if (show_text) {
        gtk_widget_destroy(show_text);
    }
}

/* Ask for a confirmation. */
ui_button_t ui_ask_confirmation(const char *title, const char *text)
{
    static GtkWidget *confirm_dialog, *confirm_dialog_message;
    gint res;

    vsync_suspend_speed_eval();
    if (!confirm_dialog) {
        confirm_dialog = build_confirm_dialog(&confirm_dialog_message);
        g_signal_connect(G_OBJECT(confirm_dialog), "destroy", G_CALLBACK(gtk_widget_destroyed), &confirm_dialog);
    }

    gtk_label_set_text(GTK_LABEL(confirm_dialog_message),text);

    ui_popup(confirm_dialog, title, FALSE);
    res = gtk_dialog_run(GTK_DIALOG(confirm_dialog));
    ui_popdown(confirm_dialog);

    return (res == GTK_RESPONSE_YES) ? UI_BUTTON_YES : (res == GTK_RESPONSE_NO) ? UI_BUTTON_NO : UI_BUTTON_CANCEL;
}

ui_button_t ui_change_dir(const char *title, const char *prompt, char *buf, unsigned int buflen)
{
    GtkWidget *fc;
    gint res;
    gchar *fname = NULL;
    ui_button_t r;

    fc = gtk_file_chooser_dialog_new(title, GTK_WINDOW(_ui_top_level), GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);
    ui_popup(fc, title, FALSE);
    res = gtk_dialog_run(GTK_DIALOG(fc));
    ui_popdown(fc);

    if ((res == GTK_RESPONSE_ACCEPT) && (fname = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc)))) {
        strncpy(buf, fname, buflen);
        r = UI_BUTTON_OK;
    } else {
	r = UI_BUTTON_CANCEL;
    }

    lib_free(fname);
    return r;
}

/* Update the menu items with a checkmark according to the current resource
   values.  */
void ui_update_menus(void)
{
    ui_menu_update_all();
}

void ui_block_shells(void)
{
    int i;

    for (i = 0; i < num_app_shells; i++) {
        gtk_widget_set_sensitive(app_shells[i].shell, FALSE);
    }
}

void ui_unblock_shells(void)
{
    int i;

    for (i = 0; i < num_app_shells; i++) {
        gtk_widget_set_sensitive(app_shells[i].shell, TRUE);
    }
    /* this is an ugly workaround to fix the focus issue on pop-down reported by count zero 
       - dead keyboard after popdown of some dialogs 
       this is neither correct nor elegant, as it messes with the mousecursor,
       which is evil UI design, imho; unfortunately I don't know a "better" way :( - pottendo */
    keyboard_key_clear();
    if (ui_cached_video_canvas) {
	gdk_pointer_grab(ui_cached_video_canvas->emuwindow->window, 1, 0, 
			 ui_cached_video_canvas->emuwindow->window, 
			 blankCursor, GDK_CURRENT_TIME);
	gdk_pointer_ungrab(GDK_CURRENT_TIME);
	ui_check_mouse_cursor();
    }
}

/* Pop up a popup shell and center it to the last visited AppShell */
void ui_popup(GtkWidget *w, const char *title, gboolean wait_popdown)
{
#ifdef HAVE_FULLSCREEN
    fullscreen_suspend(1);
#endif

    ui_restore_mouse();

    /* Keep sure that we really know which was the last visited shell. */
    ui_dispatch_events();
    gtk_window_set_title(GTK_WINDOW(w),title);

    gtk_window_set_transient_for(GTK_WINDOW(w),GTK_WINDOW(_ui_top_level));
    gtk_widget_show(w);
    gtk_window_present(GTK_WINDOW(w));

    gdk_window_set_decorations(w->window, GDK_DECOR_ALL | GDK_DECOR_MENU);
    gdk_window_set_functions(w->window, GDK_FUNC_ALL | GDK_FUNC_RESIZE);

    ui_block_shells();
    /* If requested, wait for this widget to be popped down before
       returning. */
    if (wait_popdown) {
        int oldcnt = popped_up_count++;

        while (oldcnt != popped_up_count) {
            ui_dispatch_next_event();
        }
        ui_unblock_shells();
    } else {
        popped_up_count++;
    }
}

/* Pop down a popup shell. */
void ui_popdown(GtkWidget *w)
{
    ui_check_mouse_cursor();
    if (w) {
        gtk_widget_hide(w);
    }
    if (--popped_up_count < 0) {
        popped_up_count = 0;
    }
    ui_unblock_shells();
#ifdef HAVE_FULLSCREEN
    fullscreen_resume();
#endif
}

/* ------------------------------------------------------------------------- */
static void sh_checkbox_cb(GtkWidget *w, gpointer data)
{
    g_return_if_fail(GTK_IS_CHECK_BUTTON(w));
    g_return_if_fail(GTK_IS_FILE_CHOOSER(data));
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(w))) {
        gtk_file_chooser_set_show_hidden(GTK_FILE_CHOOSER(data), TRUE);
    } else {
        gtk_file_chooser_set_show_hidden(GTK_FILE_CHOOSER(data), FALSE);
    }
}

/* These functions build all the widgets. */
static GtkWidget *build_file_selector(const char *title, GtkWidget **attach_write_protect, int allow_autostart, int show_preview,
                                      uilib_file_filter_enum_t* patterns, int num_patterns, const char *default_dir, ui_filechooser_t action, read_contents_func_type read_contents_func)
{
    GtkWidget *fileselect, *scrollw, *wp_checkbox, *sh_checkbox, *extra;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;

    fileselect = vice_file_entry(title, _ui_top_level, default_dir, patterns, num_patterns, action);

    /* Contents preview */
    if (show_preview) {
        char *cbm_font = have_cbm_font ? fixedfontname : "monospace 10";

        store = gtk_list_store_new (2, G_TYPE_STRING, G_TYPE_INT);
        image_preview_list = gtk_tree_view_new_with_model(GTK_TREE_MODEL (store));
        renderer = gtk_cell_renderer_text_new ();
        g_object_set (renderer, "font", cbm_font, "ypad", 0, NULL);
        column = gtk_tree_view_column_new_with_attributes (_("Contents"), renderer, "text", 0, NULL);

        gtk_tree_view_append_column(GTK_TREE_VIEW(image_preview_list), column);

        gtk_widget_set_size_request(image_preview_list, 350, 180);
        gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(image_preview_list), FALSE);

        gtk_container_set_border_width(GTK_CONTAINER(image_preview_list), 1);

        gtk_tree_selection_set_mode(gtk_tree_view_get_selection(GTK_TREE_VIEW(image_preview_list)), GTK_SELECTION_SINGLE);

        scrollw = gtk_scrolled_window_new(NULL, NULL);
        gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrollw), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
        gtk_container_set_border_width(GTK_CONTAINER(scrollw), 1);
        gtk_container_add(GTK_CONTAINER(scrollw), image_preview_list);
        gtk_container_set_focus_vadjustment(GTK_CONTAINER (image_preview_list), gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW (scrollw)));
        gtk_container_set_focus_hadjustment(GTK_CONTAINER (image_preview_list), gtk_scrolled_window_get_hadjustment(GTK_SCROLLED_WINDOW (scrollw)));
        gtk_widget_show(image_preview_list);
        gtk_widget_show(scrollw);
        gtk_file_chooser_set_preview_widget(GTK_FILE_CHOOSER(fileselect), scrollw);
        g_signal_connect(fileselect, "update-preview", G_CALLBACK(ui_fill_preview), read_contents_func);
        if (allow_autostart) {
            gtk_tree_selection_set_select_function(gtk_tree_view_get_selection(GTK_TREE_VIEW(image_preview_list)), ui_select_contents_cb, NULL, NULL);
        }
    }

    extra = gtk_hbox_new(FALSE, 5);

    /* Write protect checkbox */
    if (attach_write_protect) {
        /* write-protect checkbox */
        wp_checkbox = gtk_check_button_new_with_label(_("Attach read only"));
        gtk_box_pack_start(GTK_BOX(extra), wp_checkbox, FALSE, FALSE, 5);
        gtk_widget_show(wp_checkbox);
        *attach_write_protect = wp_checkbox;
    }

    /* show hidden files */
    sh_checkbox = gtk_check_button_new_with_label(_("Show hidden files"));
    g_signal_connect(G_OBJECT(sh_checkbox), "toggled", G_CALLBACK(sh_checkbox_cb), (gpointer)fileselect);
    gtk_box_pack_start(GTK_BOX(extra), sh_checkbox, FALSE, FALSE, 5);
    gtk_widget_show(sh_checkbox);

    gtk_file_chooser_set_extra_widget(GTK_FILE_CHOOSER(fileselect), extra);
    gtk_widget_show(extra);

    if (allow_autostart) {
        auto_start_button = gtk_dialog_add_button(GTK_DIALOG(fileselect), _("Autostart"), GTK_RESPONSE_NO);
    }

    last_file_selection = fileselect;
    return fileselect;
}

static GtkWidget* build_show_text(const gchar *text, int width, int height)
{
    GtkWidget *show_text, *textw, *scrollw;
    GtkTextBuffer *tb;
    gchar *utf8_text;
    GError *error = NULL;

    utf8_text = g_convert(text, strlen(text), "UTF-8", "ISO-8859-1", NULL, NULL, &error);
    if (error) {
        util_string_set(&utf8_text, _("Text cannot be displayed.\n"));
        g_error_free(error);
    }

    show_text = gtk_dialog_new_with_buttons("", NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_STOCK_CLOSE, GTK_RESPONSE_CLOSE, NULL);
    gtk_widget_set_size_request(show_text, width, height);

    scrollw = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollw), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    textw = gtk_text_view_new();
    tb = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textw));
    gtk_text_buffer_set_text(tb, utf8_text, -1);
    gtk_container_add(GTK_CONTAINER(scrollw), textw);
    gtk_widget_show(textw);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(show_text)->vbox), scrollw, TRUE, TRUE, 0);
    gtk_widget_show(scrollw);
    g_free(utf8_text);
    return show_text;
}

static GtkWidget *build_confirm_dialog(GtkWidget **confirm_dialog_message)
{
    GtkWidget *confirm_dialog;

    confirm_dialog = gtk_dialog_new_with_buttons("", NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_NO,
                                                 GTK_RESPONSE_NO, GTK_STOCK_YES, GTK_RESPONSE_YES, NULL);
    *confirm_dialog_message = gtk_label_new("");
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(confirm_dialog)->vbox), *confirm_dialog_message,TRUE,TRUE,0);
    gtk_widget_show(*confirm_dialog_message);

    return confirm_dialog;
}

/* ------------------------------------------------------------------------- */

/* Miscellaneous callbacks.  */

gboolean enter_window_callback(GtkWidget *w, GdkEvent *e, gpointer p)
{
    _ui_top_level = gtk_widget_get_toplevel(w);

    /* cv: ensure focus after dialogs were opened */
    gtk_widget_grab_focus(w);
    gtk_lightpen_update_canvas(p, TRUE);
    keyboard_key_clear();

#ifdef HAVE_FULLSCREEN
    fullscreen_mouse_moved((struct video_canvas_s *)p, 0, 0, 2);
#endif

    return 0;
}

gboolean leave_window_callback(GtkWidget *w, GdkEvent *e, gpointer p)
{
#ifdef HAVE_FULLSCREEN
    fullscreen_mouse_moved((struct video_canvas_s *)p, 0, 0, 1);
#endif
    return 0;
}

gboolean map_callback(GtkWidget *w, GdkEvent *event, gpointer user_data)
{
#ifdef HAVE_HWSCALE
    video_canvas_t *canvas = (video_canvas_t *)user_data;

    if (canvas) {
        GdkGLContext *gl_context = gtk_widget_get_gl_context(w);
        GdkGLDrawable *gl_drawable = gtk_widget_get_gl_drawable(w);

        gdk_gl_drawable_gl_begin (gl_drawable, gl_context);

        glGenTextures(1, &canvas->screen_texture);

        gdk_gl_drawable_gl_end(gl_drawable);
    }
#endif

    return FALSE;
}

gboolean configure_callback_canvas(GtkWidget *w, GdkEventConfigure *e, gpointer client_data)
{
    video_canvas_t *canvas = (video_canvas_t *) client_data;
    float ow, oh;
    int keep_aspect_ratio;
#ifdef HAVE_HWSCALE
    GdkGLContext *gl_context = gtk_widget_get_gl_context (w);
    GdkGLDrawable *gl_drawable = gtk_widget_get_gl_drawable (w);
#endif

    if ((e->width < WINDOW_MINW) || (e->height < WINDOW_MINH)) {
        /* DBG(("configure_callback_canvas skipped")); */
        return 0;
    }

    DBG(("configure_callback_canvas (e->width %d e->height %d canvas_width %d canvas_height %d)",
         e->width, e->height, canvas->draw_buffer->canvas_width, canvas->draw_buffer->canvas_height));

    /* This should work, but doesn't... Sigh...
    c->draw_buffer->canvas_width = e->width;
    c->draw_buffer->canvas_height = e->height;
    if (c->videoconfig->doublesizex) {
        c->draw_buffer->canvas_width /= 2;
    }
    if (c->videoconfig->doublesizey) {
        c->draw_buffer->canvas_height /= 2;
    }
    video_viewport_resize(c);
    */

#ifdef HAVE_HWSCALE
    /* get size of drawing buffer */
    ow = canvas->draw_buffer->canvas_width;
    oh = canvas->draw_buffer->canvas_height;
    if (canvas->videoconfig->doublesizex) {
        ow *= (canvas->videoconfig->doublesizex + 1);
    }
    if (canvas->videoconfig->doublesizey) {
        oh *= (canvas->videoconfig->doublesizey + 1);
    }

    /* in fullscreen mode, scale with aspect ratio */
    if (canvas->fullscreenconfig->enable) {
        resources_get_int("KeepAspectRatio", &keep_aspect_ratio);
        if (keep_aspect_ratio) {
            if ((float)e->height >= (oh / get_aspect(canvas)) * ((float)e->width / ow)) {
                /* full width, scale height */
                oh = (float)e->height / ((float)e->width / ow);
                oh *= get_aspect(canvas);
            } else {
                /* full height, scale width */
                ow = (float)e->width / ((float)e->height / oh);
                ow /= get_aspect(canvas);
            }
        }
    }
    DBG(("configure_callback_canvas (ow: %f oh:%f)", ow, oh));

    if (gl_context != NULL && gl_drawable != NULL) {
        gdk_gl_drawable_gl_begin(gl_drawable, gl_context);
        /* setup viewport */
        glViewport(0, 0, e->width, e->height);
        /* projection and model view matrix */
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-(ow/2),(ow/2),-(oh/2),(oh/2),-100,100);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gdk_gl_drawable_gl_end(gl_drawable);
    }
#endif
    /* maintain aspect ratio */
    setup_aspect(canvas);
    toggle_aspect(canvas);

    return 0;
}

/*
  connected to "configure-event" of the window, which is emitted to size, 
  position and stack order events. 
*/
gboolean configure_callback_app(GtkWidget *w, GdkEventConfigure *e, gpointer client_data)
{
    video_canvas_t *canvas = (video_canvas_t *) client_data;

    if ((e->width < WINDOW_MINW) || (e->height < WINDOW_MINH)) {
        /* DBG(("configure_callback_app skipped")); */
        return 0;
    }
    DBG(("configure_callback_app (x %d y %d w %d h %d)",e->x, e->y,e->width, e->height));

    resources_set_int("WindowWidth", e->width);
    resources_set_int("Windowheight", e->height);

    if ((e->x < 0) || (e->x < 0)) {
        resources_set_int("WindowXpos", 0);
        resources_set_int("WindowYpos", 0);
        return 0;
    }
    resources_set_int("WindowXpos", e->x);
    resources_set_int("WindowYpos", e->y);

    /* HACK: propagate the event to the canvas widget to make ui_trigger_resize
     *       work.
     */
    configure_callback_canvas(canvas->emuwindow, e, canvas);

    return 0;
}


gboolean exposure_callback_canvas(GtkWidget *w, GdkEventExpose *e, gpointer client_data)
{
    video_canvas_t *canvas = (video_canvas_t *)client_data;

    if (canvas == NULL) {
        return 0;
    }

    DBG(("exposure_callback_canvas canvas w/h %d/%d", canvas->gdk_image->width, canvas->gdk_image->height));

#ifdef HAVE_HWSCALE
    if (canvas->videoconfig->hwscale) {
        int tw, th;
        GdkGLContext *gl_context = gtk_widget_get_gl_context(w);
        GdkGLDrawable *gl_drawable = gtk_widget_get_gl_drawable(w);
        gdk_gl_drawable_gl_begin(gl_drawable, gl_context);

/* XXX make use of glXBindTexImageEXT aka texture from pixmap extension */

        glClear(GL_COLOR_BUFFER_BIT);
        glDisable (GL_DEPTH_TEST);

/* GL_TEXTURE_RECTANGLE is standardised as _EXT in OpenGL 1.4. Here's some
 * aliases in the meantime. */
#ifndef GL_TEXTURE_RECTANGLE_EXT
    #if defined(GL_TEXTURE_RECTANGLE_NV)
        #define GL_TEXTURE_RECTANGLE_EXT GL_TEXTURE_RECTANGLE_NV
    #elif defined(GL_TEXTURE_RECTANGLE_ARB)
        #define GL_TEXTURE_RECTANGLE_EXT GL_TEXTURE_RECTANGLE_ARB
    #else
        #error "Your headers do not supply GL_TEXTURE_RECTANGLE. Disable HWSCALE and try again."
    #endif
#endif

        glEnable(GL_TEXTURE_RECTANGLE_EXT);
        glBindTexture(GL_TEXTURE_RECTANGLE_EXT, canvas->screen_texture);
        glTexParameteri(GL_TEXTURE_RECTANGLE_EXT, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_RECTANGLE_EXT, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        tw = canvas->gdk_image->width;
        th = canvas->gdk_image->height;
#ifdef __BIG_ENDIAN__
#ifndef GL_ABGR_EXT
    #error "Your headers do not supply GL_ABGR_EXT. Disable HWSCALE and try again."
#endif
        glTexImage2D(GL_TEXTURE_RECTANGLE_EXT, 0, GL_RGBA, tw, th, 0, GL_ABGR_EXT, GL_UNSIGNED_BYTE, canvas->hwscale_image);
#else
        glTexImage2D(GL_TEXTURE_RECTANGLE_EXT, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, canvas->hwscale_image);
#endif

        glBegin (GL_QUADS);

        /* Lower Right Of Texture */
        glTexCoord2f(0.0f, 0.0f); glVertex2f(-(tw/2), (th/2));
        /* Upper Right Of Texture */
        glTexCoord2f(0.0f, th); glVertex2f(-(tw/2), -(th/2));
        /* Upper Left Of Texture */
        glTexCoord2f(tw, th); glVertex2f((tw/2), -(th/2));
        /* Lower Left Of Texture */
        glTexCoord2f(tw, 0.0f); glVertex2f((tw/2), (th/2));

        glEnd ();

        gdk_gl_drawable_swap_buffers (gl_drawable);
        gdk_gl_drawable_gl_end (gl_drawable);
    } else
#endif
    {
        int x = e->area.x;
        int y = e->area.y;
        int width = e->area.width;
        int height = e->area.height;

        gdk_draw_image(w->window, app_gc, canvas->gdk_image, x, y, x, y, width, height);
    }

    return 0;
}

/* ------------------------------------------------------------------------- */

void ui_destroy_drive_menu(int drvnr)
{
    if (drive_menus[drvnr]) {
        gtk_widget_destroy(drive_menus[drvnr]);
    }
}

void ui_set_drive_menu(int drvnr, ui_menu_entry_t *menu)
{
    drive_menus[drvnr] = gtk_menu_new();
    ui_menu_create(drive_menus[drvnr], NULL, "DriveMenu", menu);
}

void ui_set_tape_menu(ui_menu_entry_t *menu)
{
    if (tape_menu) {
        gtk_widget_destroy(tape_menu);
    }
    tape_menu = gtk_menu_new();
    ui_menu_create(tape_menu, NULL, "TapeMenu", menu);
}

void ui_display_statustext(const char *text, int fade_out)
{
    statusbar_setstatustext(text);
    if (fade_out) {
        statustext_display_time = 5;
    } else {
        statustext_display_time = 0;
    }
}

/* ------------------------------------------------------------------------- */
/*
    trigger recalculation of screen/window dimensions
 */
void ui_trigger_resize(void)
{
    if ((_ui_top_level) && (_ui_top_level->window)) {
        DBG(("ui_trigger_resize"));
        gdk_flush();
        gdk_window_raise(_ui_top_level->window);
    }
}
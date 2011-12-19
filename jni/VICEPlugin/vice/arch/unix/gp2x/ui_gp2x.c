/*
 * ui_gp2x.c
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

#include <stdio.h>

#include "gp2xsys.h"

#include "videoarch.h"
#include "machine.h"
#include "ui_gp2x.h"

int num_checkmark_menu_items;
char *last_attached_images[8];
int enabled_drives;
int w;

int drive8_status, drive8_half_track;
int drive9_status, drive9_half_track;
char *drive8_image, *drive9_image;

float emu_speed, emu_fps;

void ui_error(const char *text)
{
    fprintf(stderr, "ui_error: %s\n", text);
}

void ui_display_drive_current_image(unsigned int drive_number, const char *image)
{
    if (drive_number == 0) {
        drive8_image = (char *)image;
    }
    if (drive_number == 1) {
        drive9_image = (char *)image;
    }
}

void ui_update_menus(void)
{
    /* needed */
}

void ui_display_tape_current_image(void)
{
    /* needed */
}

void ui_display_tape_counter(void)
{
    /* needed */
}

void ui_display_tape_motor_status(void)
{
    /* needed */
}

void ui_display_tape_control_status(void)
{
    /* needed */
}

void ui_set_tape_status(void)
{
    /* needed */
}

void ui_display_recording(void)
{
    /* needed */
}

void ui_display_playback(void)
{
    /* needed */
}

void ui_init(void)
{
    gp2xsys_init(1000, 8, 11025, 16, 1, 60);
}

void archdep_ui_init(void)
{
    /* needed */
}

void ui_init_finish(void)
{
    /* needed */
}

void ui_enable_drive_status(void)
{
    /* needed */
}

void ui_extend_image_dialog(void)
{
    /* needed */
}

void ui_display_drive_led(int drive_number, unsigned int led_pwm1, unsigned int led_pwm2)
{
    int status = 0;

    if (led_pwm1 > 100) {
        status |= 1;
    }
    if (led_pwm2 > 100) {
        status |= 2;
    }

    if (drive_number == 0) {
        drive8_status = status;
        gp2x_battery_led(status);
    }
    if (drive_number == 1) {
        drive9_status = status;
    }
}

void ui_display_drive_track(unsigned int drive_number, unsigned int drive_base, unsigned int half_track_number)
{
    if (drive_number == 0) {
        drive8_half_track = half_track_number;
    }
    if (drive_number == 1) {
        drive9_half_track = half_track_number;
    }
}

void ui_resources_init(void)
{
    /* needed */
}

void ui_cmdline_options_init(void)
{
    /* needed */
}

void ui_init_finalize(void)
{
    /* needed */
}

void ui_jam_dialog(void)
{
    /* needed */
}

void ui_shutdown(void)
{
    /* needed */
}

void ui_resources_shutdown(void)
{
    /* needed */
}

void _ui_menu_radio_helper(void)
{
    /* needed */
}

void ui_check_mouse_cursor(void)
{
    /* needed */
}

void ui_dispatch_events(void)
{
    /* needed */
}

void ui_display_speed(float speed, float frame_rate, int warp_enabled)
{
    emu_speed = speed;
    emu_fps = frame_rate;
}

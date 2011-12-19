/*
 * vkeyboard_gp2x.h
 *
 * Written by
 *  Mike Dawson <mike@gp2x.org>
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

#ifndef VICE_VKEYBOARD_GP2X_H
#define VICE_VKEYBOARD_GP2X_H

extern void draw_vkeyb(unsigned char *screen);
extern char **keyb;
extern int *keytable;
extern int kb_fg;
extern int kb_bg;
extern int cursor_fg;
extern int cursor_bg;
extern int kb_height;
extern int kb_width;

extern int mapped_key_a, mapped_key_x;
extern int mapped_key_a_row, mapped_key_a_col;
extern int mapped_key_x_row, mapped_key_x_col;

extern void (*ui_set_keyarr)(int);

#endif

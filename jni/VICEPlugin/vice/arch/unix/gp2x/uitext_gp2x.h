/*
 * uitext_gp2x.h
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

#ifndef VICE_UITEXT_GP2X_H
#define VICE_UITEXT_GP2X_H

extern void draw_ascii_string(unsigned char *screen, int screen_width, int x, int y, const char *text, unsigned char fg_colour, unsigned char bg_colour);
extern void draw_petscii_string(unsigned char *screen, int screen_width, int x, int y, const char *text, unsigned char fg_colour, unsigned char bg_colour);

#endif

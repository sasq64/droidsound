/*
 * joy.h - Joystick support for Acorn.
 *
 * Written by
 *  Andreas Dehmel <zarquon@t-online.de>
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

#ifndef VICE_JOY_H
#define VICE_JOY_H

#define JOYDEV_NUMBER 5
#define JOYDEV_NONE   0
#define JOYDEV_KBD1   1
#define JOYDEV_KBD2   2
#define JOYDEV_JOY1   3
#define JOYDEV_JOY2   4

extern int joy_arch_init(void);
extern void joystick_close(void);
extern void joystick(void);
extern int joystick_init_resources(void);
extern int joystick_init_cmdline_options(void);

#endif

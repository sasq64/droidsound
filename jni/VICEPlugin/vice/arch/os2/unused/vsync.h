/*
 * vsync.h - End-of-frame handling for MS-DOS.
 *
 * Written by
 *  Ettore Perazzoli <ettore@comm2000.it>
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

#ifndef _VSYNC_DOS_H
#define _VSYNC_DOS_H

#include "types.h"

extern void   vsync_suspend_speed_eval(void);
extern int    vsync_init_resources(void);
extern int    vsync_init_cmdline_options(void);
extern void   vsync_init(double hertz, long cycles, void (*hook)(void));
extern int    vsync_disable_timer(void);
extern void   vsync_prevent_clk_overflow(CLOCK sub);
//extern double vsync_get_avg_frame_rate(void);
//extern double vsync_get_avg_speed_index(void);
extern int vsync_do_vsync(int been_skipped);

#endif /* !_VSYNC_DOS_H */

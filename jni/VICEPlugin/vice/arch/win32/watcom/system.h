/*
 * system.h - System dependant functions.
 *
 * Written by
 *  Markus Brenner <markus@brenner.de>
 *  Andreas Boose <viceteam@t-online.de>
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

#ifndef _SYSTEM_H
#define _SYSTEM_H

#undef BYTE
#undef WORD
#undef DWORD
#include <windows.h>
#include <prsht.h>

extern void system_init_dialog(HWND hwnd);
extern void system_psh_settings(PROPSHEETHEADER *ppsh);

extern size_t system_wcstombs(char *mbs, const char *wcs, size_t len);
extern size_t system_mbstowcs(char *wcs, const char *mbs, size_t len);
extern char *system_mbstowcs_alloc(const char *mbs);
extern void system_mbstowcs_free(char *wcs);
extern char *system_wcstombs_alloc(const char *wcs);
extern void system_wcstombs_free(char *mbs);

#endif


/*
 * c64c128ui.c - UI aspects shared by C64 and C128.
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

#include "vice.h"

#include "ui.h"
#include "c64ui.h"
#include "cartridge.h"
#include "kbd.h"
#include "machine.h"
#include "uisharedef.h"

/* Convert internal keynumbers to CBM keyboard matrix. Top nibble = row, bottom nibble col */
static unsigned char C64C128norm[KEYMAP_ENTRIES] = {
    0x17, 0x72, 0x75, 0x17,	/* 0  -  3: SHIFT, CTRL, ALT(C=), SH_L		*/
    0x72, 0x75, 0x64, 0x72,	/* 4  -  7: CTRL_L, ALT_L, SH_R, CTRL_R		*/
    0x75, 0xff, 0xff, 0xff,	/* 8  - 11: ALT_R, MouseSlct, MouseMen, MouseAdj*/
    0xff, 0xff, 0xff, 0xff,	/* 12 - 15: dummies				*/
    0x76, 0x10, 0x13, 0x20,	/* 16 - 19: q, 3,4,5				*/
    0x03, 0x33, 0xff, 0x53,	/* 20 - 23: F4(F7), 8, F7, -			*/
    0x23, 0x02, 0xff, 0xff,	/* 24 - 27: 6, crsrL, num6, num7		*/
    0xff, 0xff, 0xff, 0xff,	/* 28 - 31: F11, F12, F10, ScrLock		*/
    0xff, 0x11, 0x16, 0x26,	/* 32 - 35: Print, w, e, t			*/
    0x30, 0x41, 0x40, 0x43,	/* 36 - 39: 7, i, 9, 0				*/
    0x53, 0x07, 0xff, 0xff,	/* 40 - 43: -, crsrD, num8, num9		*/
    0x77, 0x71, 0x60, 0x00,	/* 44 - 47: break, `, �, DEL			*/
    0x70, 0x73, 0x22, 0x21,	/* 48 - 51: 1, 2, d, r				*/
    0x23, 0x36, 0x46, 0x51,	/* 52 - 55: 6, u, o, p				*/
    0x56, 0x07, 0x50, 0x53,	/* 56 - 59: [(@), crsrU, num+(+), num-(-)	*/
    0xff, 0x00, 0x63, 0xff,	/* 60 - 63: numENTER, insert, home, pgUp	*/
    0x17, 0x12, 0x27, 0x25,	/* 64 - 67: capsLCK, a, x, f			*/
    0x31, 0x42, 0x45, 0x73,	/* 68 - 71: y, j, k, 2				*/
    0x55, 0x01, 0xff, 0xff,	/* 72 - 75: ;(:), RET, num/, dummy		*/
    0xff, 0xff, 0xff, 0x62,	/* 76 - 79: num., numLCK, pgDown, '(;)		*/
    0xff, 0x15, 0x24, 0x32,	/* 80 - 83: dummy, s, c, g			*/
    0x35, 0x47, 0x52, 0x55,	/* 84 - 87: h, n, l, ;(:)			*/
    0x61, 0x00, 0xff, 0xff,	/* 88 - 91: ](*), Delete, num#, num*		*/
    0xff, 0x65, 0xff, 0xff,	/* 92 - 95: dummy, =, dummies			*/
    0x72, 0x14, 0x74, 0x37,	/* 96 - 99: TAB(CTRL), z, SPACE, v		*/
    0x34, 0x44, 0x57, 0x54,	/* 100-103: b, m, ',', .			*/
    0x67, 0xff, 0xff, 0xff,	/* 104-107: /, Copy, num0, num1			*/
    0xff, 0xff, 0xff, 0xff,	/* 108-111: num3, dummies			*/
    0x77, 0x04, 0x05, 0x06,	/* 112-115: ESC, F1(F1), F2(F3), F3(F5)		*/
    0xff, 0xff, 0xff, 0xff,	/* 116-119: F5, F6, F8, F9			*/
    0x66, 0x02, 0xff, 0xff,	/* 120-123: \(^), crsrR, num4, num5		*/
    0xff, 0xff, 0xff, 0xff	/* 124-127: num2, dummies			*/
};

static unsigned char C64C128shifted[KEYMAP_ENTRIES];
static unsigned char C64C128norm_sflags[KEYMAP_ENTRIES / 8];
static unsigned char C64C128shift_sflags[KEYMAP_ENTRIES / 8];

static kbd_keymap_t C64C128keys = {
    NULL,
    C64C128norm,
    C64C128shifted,
    C64C128norm_sflags,
    C64C128shift_sflags
};


static int c64c128ui_menu_select_emuwin(int *block)
{
    if (block[0] == Menu_EmuWin_Freeze) {
        cartridge_trigger_freeze();
        return 0;
    }
    return -1;
}

static int c64c128ui_menu_select_config_pre(int *block, int mnum)
{
    if (!vsid_mode && (block[0] == 0) && (mnum == CONF_MENU_CARTTYPE)) {
        /* must execute cartridge detach before calling ui_set_menu_display_value() */
        cartridge_detach_image(-1);
        return 0;
    }
    return -1;
}

void c64c128_ui_init_keyboard(const char *filename)
{
    C64C128keys.default_file = filename;
    kbd_default_keymap(&C64C128keys);
    kbd_init_keymap(2);
    kbd_add_keymap(&C64C128keys, 0); kbd_add_keymap(&C64C128keys, 1);
}

void c64c128_ui_cartridge_callbacks(void)
{
    ViceMachineCallbacks.menu_select_emuwin = c64c128ui_menu_select_emuwin;
    ViceMachineCallbacks.menu_select_config_pre = c64c128ui_menu_select_config_pre;
}

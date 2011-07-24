/*
 * cbm2sound.c - CBM2 sound emulation.
 *
 * Written by
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
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
#include <string.h>

#include "sid.h"
#include "sound.h"
#include "types.h"

/* ---------------------------------------------------------------------*/

static sound_chip_t sid_sound_chip = {
    sid_sound_machine_open,
    sid_sound_machine_init,
    sid_sound_machine_close,
    sid_sound_machine_calculate_samples,
    sid_sound_machine_store,
    sid_sound_machine_read,
    sid_sound_machine_reset,
    sid_sound_machine_enable,
    sid_sound_machine_cycle_based,
    sound_machine_channels,
    0x00, /* offset to be filled in by register routine */
    1 /* chip enabled */
};

static sound_chip_list_t *sid_sound_chip_item = NULL;

void sid_sound_chip_init(void)
{
    sid_sound_chip_item = sound_chip_register(&sid_sound_chip);
}

/* ---------------------------------------------------------------------*/

int machine_sid2_check_range(unsigned int sid2_adr)
{
    if (sid2_adr >= 0xda20 && sid2_adr <= 0xdae0)
        return 0;

    return -1;
}

void machine_sid2_enable(int val)
{
}

void sound_machine_close(sound_t *psid)
{
    sid_sound_machine_close(psid);
}

BYTE sound_machine_read(sound_t *psid, WORD addr)
{
    return sid_sound_machine_read(psid, addr);
}

void sound_machine_store(sound_t *psid, WORD addr, BYTE byte)
{
    sid_sound_machine_store(psid, addr, byte);
}

void sound_machine_reset(sound_t *psid, CLOCK cpu_clk)
{
    sid_sound_machine_reset(psid, cpu_clk);
}

int sound_machine_calculate_samples(sound_t *psid, SWORD *pbuf, int nr,
                                    int interleave, int *delta_t)
{
    return sid_sound_machine_calculate_samples(psid, pbuf, nr, interleave, delta_t);
}

void sound_machine_prevent_clk_overflow(sound_t *psid, CLOCK sub)
{
    sid_sound_machine_prevent_clk_overflow(psid, sub);
}

char *sound_machine_dump_state(sound_t *psid)
{
    return sid_sound_machine_dump_state(psid);
}

int sound_machine_cycle_based(void)
{
    return sid_sound_machine_cycle_based();
}

int sound_machine_channels(void)
{
    return sid_sound_machine_channels();
}

void sound_machine_enable(int enable)
{
    sid_sound_machine_enable(enable);
}

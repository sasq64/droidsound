/*
 * pet_userport_dac.h
 *
 * Written by
 *  Marco van den Heuvel <viceteam@t-online.de>
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

#ifndef VICE_PET_USERPORT_DAC_H
#define VICE_PET_USERPORT_DAC_H

#include "types.h"
#include "sound.h"

extern int pet_userport_dac_resources_init(void);
extern int pet_userport_dac_cmdline_options_init(void);

extern void pet_userport_dac_store(BYTE value);

extern int pet_userport_dac_sound_machine_calculate_samples(sound_t *psid, SWORD *pbuf, int nr, int interleave, int *delta_t);
extern int pet_userport_dac_sound_machine_init(sound_t *psid, int speed, int cycles_per_sec);
extern void pet_userport_dac_sound_machine_store(sound_t *psid, WORD addr, BYTE val);
extern BYTE pet_userport_dac_sound_machine_read(sound_t *psid, WORD addr);
extern void pet_userport_dac_sound_reset(sound_t *psid, CLOCK cpu_clk);

extern void pet_userport_dac_sound_chip_init(void);

#endif
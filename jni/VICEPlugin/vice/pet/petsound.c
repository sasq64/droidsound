/*
 * petsound.c - implementation of PET sound code
 *
 * Written by
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

#include "vice.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "lib.h"
#include "pet_userport_dac.h"
#include "petsound.h"
#include "sid.h"
#include "sidcart.h"
#include "sid-resources.h"
#include "sound.h"
#include "types.h"

/* ------------------------------------------------------------------------- */

/* Some prototypes are needed */
static int pet_sound_machine_init(sound_t *psid, int speed, int cycles_per_sec);
static int pet_sound_machine_calculate_samples(sound_t *psid, SWORD *pbuf, int nr, int interleave, int *delta_t);
static void pet_sound_machine_store(sound_t *psid, WORD addr, BYTE val);
static BYTE pet_sound_machine_read(sound_t *psid, WORD addr);

static int pet_sound_machine_cycle_based(void)
{
    return 0;
}

static int pet_sound_machine_channels(void)
{
    return 1;
}

static sound_chip_t pet_sound_chip = {
    NULL, /* no open */
    pet_sound_machine_init,
    NULL, /* no close */
    pet_sound_machine_calculate_samples,
    pet_sound_machine_store,
    pet_sound_machine_read,
    petsound_reset,
    NULL, /* no enable */
    pet_sound_machine_cycle_based,
    pet_sound_machine_channels,
    0x20, /* offset to be filled in by register routine */
    0 /* chip enabled */
};

static sound_chip_list_t *pet_sound_chip_item = NULL;

void pet_sound_chip_init(void)
{
    pet_sound_chip_item = sound_chip_register(&pet_sound_chip);
}

/* ------------------------------------------------------------------------- */

/* dummy function for now */
int machine_sid2_check_range(unsigned int sid2_adr)
{
    return 0;
}

void machine_sid2_enable(int val)
{
}

struct pet_sound_s
{
    int on;
    CLOCK t;
    BYTE sample;

    double b;
    double bs;

    int speed;
    int cycles_per_sec;

    int manual;       /* 1 if CB2 set to manual control "high", 0 otherwise */
};

static BYTE snddata[5];
static struct pet_sound_s snd;

/* XXX: this is not correct */
static WORD pet_makesample(double s, double e, BYTE sample)
{
    double v;
    int sc, ec, sf, ef, i, nr;

    sc = (int)ceil(s);
    sf = (int)floor(s);
    ec = (int)ceil(e);
    ef = (int)floor(e);
    nr = 0;

    for (i = sc; i < ef; i++)
        if (sample & (1 << (i % 8)))
            nr++;

    v = nr;

    if (sample & (1 << (sf % 8)))
        v += sc - s;
    if (sample & (1 << (ef % 8)))
        v += e - ef;

    return ((WORD)(v * 4095.0 / (e - s)));
}

static int pet_sound_machine_calculate_samples(sound_t *psid, SWORD *pbuf, int nr,
                                    int interleave, int *delta_t)
{
    int i;
    WORD v = 0;

    for (i = 0; i < nr; i++)
    {
        if (snd.on)
            v = pet_makesample(snd.b, snd.b + snd.bs, snd.sample);
        else if (snd.manual)
            v = 20000;

        pbuf[i * interleave] = sound_audio_mix(pbuf[i * interleave],(SWORD)v);
        snd.b += snd.bs;
        while (snd.b >= 8.0)
            snd.b -= 8.0;
    }
    return 0;
}

void petsound_store_onoff(int value)
{
    snddata[0] = value;
    sound_store(0x20, snddata[0], 0);
}

void petsound_store_rate(CLOCK t)
{
    snddata[2] = (BYTE)(t & 0xff);
    snddata[3] = (BYTE)((t >> 8) & 0xff);
    sound_store(0x22, snddata[2], 0);
    sound_store(0x23, snddata[3], 0);
}

void petsound_store_sample(BYTE sample)
{
    snddata[1] = sample;
    sound_store(0x21, snddata[1], 0);
}

/* For manual control of CB2 sound using $E84C */
void petsound_store_manual(int value)
{
    snddata[4] = value;
    sound_store(0x24, snddata[4], 0);
}

static void pet_sound_machine_store(sound_t *psid, WORD addr, BYTE val)
{
    switch (addr) {
      case 0:
        snd.on = val;
        break;
      case 1:
        snd.sample = val;
        while (snd.b >= 1.0)
            snd.b -= 1.0;
        break;
      case 2:
        snd.t = val;
        break;
      case 3:
        snd.t = (snd.t & 0xff) | (val << 8);
        snd.bs = (double)snd.cycles_per_sec / (snd.t * snd.speed);
        break;
      case 4:
        snd.manual = val;
        break;
      default:
        abort();
    }
}

static int pet_sound_machine_init(sound_t *psid, int speed, int cycles_per_sec)
{
    WORD i;

    snd.speed = speed;
    snd.cycles_per_sec = cycles_per_sec;
    if (!snd.t)
        snd.t = 32;
    snd.b = 0.0;
    snd.bs = (double)snd.cycles_per_sec / (snd.t * snd.speed);

    snddata[0] = 0;
    snddata[1] = 0;
    snddata[2] = 4;
    snddata[3] = 0;
    snddata[4] = 0;

    for (i = 0; i < 5; i++)
        pet_sound_machine_store(psid, i, snddata[i]);

    return 1;
}

void petsound_reset(sound_t *psid, CLOCK cpu_clk)
{
    sound_reset();
    petsound_store_onoff(0);
}

static BYTE pet_sound_machine_read(sound_t *psid, WORD addr)
{
  return 0;
}

void sound_machine_close(sound_t *psid)
{
    sid_sound_machine_close(psid);
}

/* for read/store 0x00 <= addr <= 0x1f is the sid
 *                0x20 <= addr <= 0x3f is the pet sound
 *                0x40 <= addr <= 0x5f is the pet userport dac
 *
 * future sound devices will be able to use 0x60 and up
 */

BYTE sound_machine_read(sound_t *psid, WORD addr)
{
    if (addr >= 0x20 && addr <= 0x3f) {
        return pet_sound_machine_read(psid, (WORD)(addr-0x20));
    } else {
        if (addr >= 0x40 && addr <= 0x5f) {
            return pet_userport_dac_sound_machine_read(psid, addr);
        } else {
            return sid_sound_machine_read(psid, addr);
        }
    }
}

void sound_machine_store(sound_t *psid, WORD addr, BYTE byte)
{
    if (addr >= 0x20 && addr <= 0x3f) {
        pet_sound_machine_store(psid, (WORD)(addr-0x20), byte);
    } else {
        if (addr >= 0x40 && addr <= 0x5f) {
            pet_userport_dac_sound_machine_store(psid, addr, byte);
        } else {
            sid_sound_machine_store(psid, addr, byte);
        }
    }
}

void sound_machine_reset(sound_t *psid, CLOCK cpu_clk)
{
    pet_userport_dac_sound_reset(psid, cpu_clk);
    sid_sound_machine_reset(psid, cpu_clk);
}

int sound_machine_calculate_samples(sound_t *psid, SWORD *pbuf, int nr,
                                    int interleave, int *delta_t)
{
    int temp;

    temp=sid_sound_machine_calculate_samples(psid, pbuf, nr, interleave, delta_t);
    pet_sound_machine_calculate_samples(psid, pbuf, nr, interleave, delta_t);
    pet_userport_dac_sound_machine_calculate_samples(psid, pbuf, nr, interleave, delta_t);
    return temp;
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
    return 0;
}

int sound_machine_channels(void)
{
    return sid_sound_machine_channels();
}

void sound_machine_enable(int enable)
{
    sid_sound_machine_enable(enable);
}

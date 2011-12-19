/*
 * catweaselmkiii.c
 *
 * Written by
 *  Andreas Boose <viceteam@t-online.de>
 *  Dirk Jagdmann <doj@cubic.org>
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

#ifdef HAVE_CATWEASELMKIII

#include <stdlib.h>
#include <string.h>
#include <windows.h>

#ifdef HAVE_WINIOCTL_H
#include <winioctl.h>
#endif

#include "catweaselmkiii.h"
#include "log.h"
#include "types.h"


typedef void (*voidfunc_t)(void);

/* defined for CatWeasel MK3 PCI device driver */
#define SID_SID_PEEK_POKE CTL_CODE(FILE_DEVICE_SOUND, 0x0800UL + 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SID_SET_CLOCK     CTL_CODE(FILE_DEVICE_SOUND, 0x0800UL + 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SID_CMD_READ      32

#define MAXCARDS 4

/* array containing file handles for up to MAXCARD CatWeasels */
static HANDLE sidhandle[MAXCARDS] = {
    INVALID_HANDLE_VALUE,
    INVALID_HANDLE_VALUE,
    INVALID_HANDLE_VALUE,
    INVALID_HANDLE_VALUE,
};

static int cwmkiii_is_open = 0;

/* buffer containing current register state of SIDs */
BYTE sidbuf[MAXCARDS * 0x20];

/* 0 = pal, !0 = ntsc */
static BYTE ntsc = 0;

/* set all CatWeasels frequency to buf. buf=0: pal ; buf=1: ntsc */
static void setfreq(BYTE buf)
{
    int i;

    for (i = 0; i < MAXCARDS; i++) {
        if (sidhandle[i] != INVALID_HANDLE_VALUE) {
            DWORD w;

            DeviceIoControl(sidhandle[i], SID_SET_CLOCK, &buf, sizeof(buf), 0L, 0UL, &w, 0L);
        }
    }
}

/* silent al SIDs by setting all registers to 0 */
static void mutethem(void)
{
    DWORD w;
    int i;
    BYTE buf[0x19 * 2];

    for (i = 0; i <= 0x18; i++) {
        buf[i * 2] = i;
        buf[i * 2 + 1] = 0;
    }
    for (i = 0; i < MAXCARDS; i++) {
        if (sidhandle[i] != INVALID_HANDLE_VALUE) {
            DeviceIoControl(sidhandle[i], SID_SID_PEEK_POKE, buf, sizeof(buf), 0L, 0UL, &w, 0L);
        }
    }
    memset(sidbuf, 0, sizeof(sidbuf));
}

/* open all available CatWeasel devices */
int catweaselmkiii_open(void)
{
    static int atexitinitialized = 0;
    int i, z = 0;

    /* close any open handles */
    for (i = 0; i < MAXCARDS; i++) {
        if (sidhandle[i] != INVALID_HANDLE_VALUE) {
            CloseHandle(sidhandle[i]), sidhandle[i] = INVALID_HANDLE_VALUE;
        }
    }

    /* find up to four CatWeasel cards */
    for (i = 0; i < MAXCARDS; i++) {
        char buf[32];

        sprintf(buf, "\\\\.\\SID6581_%u", i + 1);
        sidhandle[z] = CreateFile(buf, GENERIC_READ, FILE_SHARE_WRITE | FILE_SHARE_READ, 0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);
        if (sidhandle[z] != INVALID_HANDLE_VALUE) {
            log_message(LOG_DEFAULT, "Found CatWeasel MK3 PCI #%i", z + 1);
            z++;
        }
    }

    /* if cards were found */
    if (z > 0) {
        log_message(LOG_DEFAULT, "Found and opened a CatWeasel MK3 PCI SID");

        /* silent all found cards */
        mutethem();

        /* set frequeny of found cards */
        setfreq(ntsc);

        /* install exit handler, so devices are closed properly */
        if (!atexitinitialized) {
            atexitinitialized = 1;
            atexit((voidfunc_t)catweaselmkiii_close);
        }

        cwmkiii_is_open = 1;
        return 0;
    }

    /* no CatWeasels were found */
    return -1;
}

/* close all open device handles */
int catweaselmkiii_close(void)
{
    int i;

    mutethem();
    for (i = 0; i < MAXCARDS; i++) {
        if (sidhandle[i] != INVALID_HANDLE_VALUE) {
            CloseHandle(sidhandle[i]);
            sidhandle[i] = INVALID_HANDLE_VALUE;
        }
    }

    cwmkiii_is_open = 0;

    log_message(LOG_DEFAULT, "Closed CatWeasel MK3 PCI SID");
    return 0;
}

/* read register from sid. only the four read registers from $19 to
   $1C are read from the real SID chip, all other bytes are read from
   sidbuf[] */
int catweaselmkiii_read(WORD addr, int chipno)
{
    /* check if chipno is valid */
    if (chipno < MAXCARDS) {
        /* check if addr is in read-only range, and that a card was found */
        if (addr >= 0x19 && addr <= 0x1C && sidhandle[chipno] != INVALID_HANDLE_VALUE) {
            /* do real read */
            DWORD w;
            BYTE buf[2];

            buf[0] = SID_CMD_READ;
            buf[1] = (BYTE)(addr & 0xff);
            DeviceIoControl(sidhandle[chipno], SID_SID_PEEK_POKE, buf, 2, buf, 1, &w, 0L);
            return buf[0];
        }
        /* use sidbuf[] for write-only registers */
        if (addr <= 0x18) {
            return sidbuf[chipno * 0x20 + addr];
        }
    }
    log_error(LOG_ERR, "CatWeasel MK3 PCI does not support SID #%i", chipno);
    return 0;
}

/* write a value */
void catweaselmkiii_store(WORD addr, BYTE val, int chipno)
{
    /* check if chipno is valid */
    if (chipno < MAXCARDS) {
        /* check if addr is valid */
        if (addr <= 0x18) {
            /* write to sidbuf[] */
            sidbuf[chipno * 0x20 + addr] = val;

            /* check if device handle is valid */
            if (sidhandle[chipno] != INVALID_HANDLE_VALUE) {
                /* perform real write */
                DWORD w;
                BYTE buf[2];

                buf[0] = (BYTE)(addr & 0xff);
                buf[1] = val;
                DeviceIoControl(sidhandle[chipno], SID_SID_PEEK_POKE, buf, sizeof(buf), 0L, 0UL, &w, 0L);
            }
            return;
        }
        log_error(LOG_ERR, "CatWeasel MK3 PCI store at address %04x", addr);
        return;
    }
    log_error(LOG_ERR, "CatWeasel MK3 PCI does not support SID #%i", chipno);
}

/* set current main clock frequency, which gives us the possibilty to
   choose between pal and ntsc frequencies */
void catweaselmkiii_set_machine_parameter(long cycles_per_sec)
{
    ntsc = (BYTE)((cycles_per_sec <= 1000000) ? 0 : 1);
    setfreq(ntsc);
}

int catweaselmkiii_available(void)
{
    int i;

    if (cwmkiii_is_open) {
        for (i = 0; i < MAXCARDS; i++) {
            if (sidhandle[i] != INVALID_HANDLE_VALUE) {
                return 1;
            }
        }
        return 0;
    } else {
        i = catweaselmkiii_open();
        if (cwmkiii_is_open) {
            catweaselmkiii_close();
            return 1;
        }
    }
    return 0;
}
#endif

/*
 * catweaselmkiii.c
 *
 * Written by
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
 *
 * Based on code by
 *  Timothy Mann
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

#include <stdio.h>
#include <dpmi.h>
#include <string.h>

#include "log.h"
#include "types.h"

typedef unsigned short uint16;
typedef unsigned long uint32;

static int sid_NTSC = 0; // TRUE for 60Hz oscillator, FALSE for 50

static int base;

/* buffer containing current register state of SIDs */
static BYTE sidbuf[0x20];

static int sidfh = -1;

#define CW_SID_DAT 0xd8
#define CW_SID_CMD 0xdc

static int pci_install_check(void)
{
    __dpmi_regs r;

    memset(&r, 0, sizeof(r));

    r.x.ax = 0xb101;
    r.d.edi = 0x0;

    if (__dpmi_int(0x1a, &r) != 0) {
        return -1;
    }
	
    if (r.h.ah != 0 || r.d.edx != 0x20494350) {
        return -1;
    }

    return 0;
}


static int pci_find(int vendorID, int deviceID, int index, int *bus, int *device, int *func)
{
    __dpmi_regs r;

    memset(&r, 0, sizeof(r));

    r.x.ax = 0xb102;
    r.x.cx = deviceID;
    r.x.dx = vendorID;
    r.x.si = index;

    if (__dpmi_int(0x1a, &r) != 0) {
        return -1;
    }

    if (r.h.ah == 0) {
        *bus = r.h.bh;
        *device = (r.h.bl >> 3) & 0x1f;
        *func = r.h.bl & 0x03;
    }

    return r.h.ah;
}


static int pci_read_config_dword(int bus, int device, int func, int reg, uint32 *value)
{
    __dpmi_regs r;

    memset(&r, 0, sizeof(r));

    r.x.ax = 0xb10a;
    r.h.bh = bus;
    r.h.bl = (device << 3) + func;
    r.x.di = reg;

    if (__dpmi_int(0x1a, &r) != 0) {
        return -1;
    }
	
    if (r.h.ah == 0) {
        *value = r.d.ecx;
    }

    return r.h.ah;
}


static int pci_find_catweasel(int index)
{
    int i = 0, j = 0, res;
    int bus, device, func;
    uint32 subsysID, baseAddr;

    if (pci_install_check() != 0) {
        return -1;
    }

    while (i <= index) {

        /* Find the next card that uses the Tiger Jet Networks Tiger320 PCI chip */
        res = pci_find(0xe159, 0x0001, j++, &bus, &device, &func);
        if (res != 0) {
            return -1;
        }

        /* Read the subsystem vendor ID + subsystem ID */
        res = pci_read_config_dword(bus, device, func, 0x2c, &subsysID);
        if (res != 0) {
            continue;
        }

        /* Check if they match the Catweasel */
        switch (subsysID) {
            case 0x00021212: 	/* Catweasel MK3 */
            case 0x00031212: 	/* Catweasel MK3 alternate */
            case 0x00025213: 	/* Catweasel MK4 */
            case 0x00035213: 	/* Catweasel MK4 alternate */
                break;
            default:
                continue;
        }
        i++;
    }

    for (i = 0x10; i <= 0x24; i += 4) {

        /* Read a base address */
        res = pci_read_config_dword(bus, device, func, i, &baseAddr);
        if (res != 0) {
            return -1;
        }

        /* Check for I/O space */
        if (baseAddr & 1) {
            return baseAddr & ~3;
        }
    }

    return -1;
}

static unsigned char read_sid(unsigned char reg)
{
    unsigned char cmd;

    cmd = (reg & 0x1f) | 0x20;	// Read command & address
    if (sid_NTSC) {
        cmd |= 0x40;  // Make sure its correct frequency
    }

    // Write command to the SID
    outportb(base + CW_SID_CMD, cmd);

    // Waste 1ms
    inportb(base + CW_SID_DAT);
    inportb(base + CW_SID_DAT);

    return inportb(base + CW_SID_DAT);
}

static void write_sid(unsigned char reg, unsigned char data)
{
    unsigned char cmd;

    cmd = reg & 0x1f;
    if (sid_NTSC) {
        cmd |= 0x40;  // Make sure its correct frequency
    }

    // Write data to the SID
    outportb(base + CW_SID_DAT, data);
    outportb(base + CW_SID_CMD, cmd);

    // Waste 1ms
    inportb(base + CW_SID_DAT);
    inportb(base + CW_SID_DAT);
}

int catweaselmkiii_open(void)
{
    int i;

    base = pci_find_catweasel(0);

    if (base == -1) {
        log_message(LOG_DEFAULT, "Unable to find a Catweasel Mk3 PCI card\n");
        return -1;
    }

    // Reset the catweasel PCI interface (as per the CW programming docs)
    outportb(base + 0x00, 0xf1);
    outportb(base + 0x01, 0x00);
    outportb(base + 0x02, 0x00);
    outportb(base + 0x04, 0x00);
    outportb(base + 0x05, 0x00);
    outportb(base + 0x29, 0x00);
    outportb(base + 0x2b, 0x00);                                      

    /* mute all sids */
    memset(sidbuf, 0, sizeof(sidbuf));
    for (i = 0; i < sizeof(sidbuf); i++) {
        write_sid(i, 0);
    }

    log_message(LOG_DEFAULT, "CatWeasel MK3 PCI SID: opened");

    sidfh = 1; /* ok */

    return 0;
}

int catweaselmkiii_close(void)
{
    unsigned int i;

    /* mute all sids */
    memset(sidbuf, 0, sizeof(sidbuf));
    for (i = 0; i < sizeof(sidbuf); i++) {
        write_sid(i, 0);
    }

    log_message(LOG_DEFAULT, "CatWeasel MK3 PCI SID: closed");

    return 0;
}

/* read value from SIDs */
int catweaselmkiii_read(WORD addr, int chipno)
{
    /* check if chipno and addr is valid */
    if (chipno < 1 && addr < 0x20) {
        /* if addr is from read-only register, perform a read read */
        if (addr >= 0x19 && addr <= 0x1C && sidfh >= 0) {
            addr += chipno * 0x20;
            sidbuf[addr] = read_sid(addr);
        } else {
            addr += chipno * 0x20;
        }

        /* take value from sidbuf[] */
        return sidbuf[addr];
    }

    return 0;
}

/* write value into SID */
void catweaselmkiii_store(WORD addr, BYTE val, int chipno)
{
    /* check if chipno and addr is valid */
    if (chipno < 1 && addr <= 0x18) {
        /* correct addr, so it becomes an index into sidbuf[] and the unix device */
        addr += chipno * 0x20;
        /* write into sidbuf[] */
        sidbuf[addr] = val;
        /* if the device is opened, write to device */
        if (sidfh >= 0) {
            write_sid(addr, val);
        }
    }
}

/* set current main clock frequency, which gives us the possibilty to
   choose between pal and ntsc frequencies */
void catweaselmkiii_set_machine_parameter(long cycles_per_sec)
{
    sid_NTSC = (cycles_per_sec <= 1000000) ? 0 : 1;
}

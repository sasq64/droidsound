/*
 * catweaselmkiii.c
 *
 * Written by
 *  Mathias Roslund <vice.emu@amidog.se>
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

#if defined(HAVE_PROTO_OPENPCI_H) && defined(HAVE_CATWEASELMKIII)

#include <stdlib.h>
#include <string.h>

#include "catweaselmkiii.h"
#include "log.h"
#include "types.h"

#define MAXSID 1

static unsigned char read_sid(unsigned char reg); // Read a SID register
static void write_sid(unsigned char reg, unsigned char data); // Write a SID register

static struct Library *OpenPciBase = NULL;

static int sidfh = 0;

/* buffer containing current register state of SIDs */
static BYTE sidbuf[0x20 * MAXSID];

typedef void (*voidfunc_t)(void);

static unsigned long CWbase;

/* read value from SIDs */
int catweaselmkiii_read(WORD addr, int chipno)
{
    /* check if chipno and addr is valid */
    if (chipno < MAXSID && addr < 0x20) {
        /* if addr is from read-only register, perform a read read */
        if (addr >= 0x19 && addr <= 0x1C && sidfh >= 0) {
            addr += chipno * 0x20;
            sidbuf[addr] = read_sid(addr);
        } else {
            addr += chipno*0x20;
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
    if (chipno < MAXSID && addr <= 0x18) {
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

#define CW_SID_DAT 0xd8
#define CW_SID_CMD 0xdc

#undef BYTE
#undef WORD
#include <exec/types.h>
#include <proto/exec.h>
#include <proto/openpci.h>
#include <libraries/openpci.h>

// Set as appropriate
static int sid_NTSC = FALSE; // TRUE for 60Hz oscillator, FALSE for 50

#if defined(pci_obtain_card) && defined(pci_release_card)
static int CWLock = FALSE;
#endif

static struct pci_dev *dev = NULL;

int catweaselmkiii_open(void)
{
    static int atexitinitialized = 0;
    unsigned int i;
    unsigned char bus = 0;

    if (atexitinitialized) {
        catweaselmkiii_close();
    }

    if ((OpenPciBase = (struct Library *)OpenLibrary("openpci.library", 0)) == NULL) {
        log_message(LOG_DEFAULT, "Error opening openpci.library\n");
        return -1;
    }

    log_message(LOG_DEFAULT, "openpci.library v%ld.%ld opened\n",(long)OpenPciBase->lib_Version,(long)OpenPciBase->lib_Revision);

    bus = pci_bus();

    if (!bus) {
        log_message(LOG_DEFAULT, "No PCI bus found\n");
        return -1;
    }

    dev = pci_find_device(0xe159, 0x0001, NULL);

    if (dev == NULL) {
        log_message(LOG_DEFAULT, "Unable to find a Catweasel Mk3 PCI card\n");
        return -1;
    }

#if defined(pci_obtain_card) && defined(pci_release_card)
    /* Lock the device, since we're a driver */
    CWLock = pci_obtain_card(dev);
    if (!CWLock) {
        log_message(LOG_DEFAULT, "Unable to lock the catweasel. Another driver may have an exclusive lock\n" );
        return -1;
    }
#endif

    CWbase = dev->base_address[0];

    // Reset the catweasel PCI interface (as per the CW programming docs)
    pci_outb(0xf1, CWbase + 0x00);
    pci_outb(0x00, CWbase + 0x01);
    pci_outb(0x00, CWbase + 0x02);
    pci_outb(0x00, CWbase + 0x04);
    pci_outb(0x00, CWbase + 0x05);
    pci_outb(0x00, CWbase + 0x29);
    pci_outb(0x00, CWbase + 0x2b);

    /* mute all sids */
    memset(sidbuf, 0, sizeof(sidbuf));
    for (i = 0; i < sizeof(sidbuf); i++) {
        write_sid(i, 0);
    }

    log_message(LOG_DEFAULT, "CatWeasel MK3 PCI SID: opened");

    /* install exit handler, so device is closed on exit */
    if (!atexitinitialized) {
        atexitinitialized = 1;
        atexit((voidfunc_t)catweaselmkiii_close);
    }

    sidfh = 1; /* ok */

    return 0;
}

static unsigned char read_sid(unsigned char reg)
{
    unsigned char cmd;

    cmd = (reg & 0x1f) | 0x20;   // Read command & address
    if (sid_NTSC) {
        cmd |= 0x40;  // Make sure its correct frequency
    }

    // Write command to the SID
    pci_outb(cmd, CWbase + CW_SID_CMD);

    // Waste 1ms
    pci_inb(CWbase + CW_SID_DAT);
    pci_inb(CWbase + CW_SID_DAT);

    return pci_inb(CWbase + CW_SID_DAT);
}

static void write_sid(unsigned char reg, unsigned char data)
{
    unsigned char cmd;

    cmd = reg & 0x1f;            // Write command & address
    if (sid_NTSC) {
        cmd |= 0x40;  // Make sure its correct frequency
    }

    // Write data to the SID
    pci_outb(data, CWbase + CW_SID_DAT);
    pci_outb(cmd, CWbase + CW_SID_CMD);

    // Waste 1ms
    pci_inb(CWbase + CW_SID_DAT);
    pci_inb(CWbase + CW_SID_DAT);
}

int catweaselmkiii_close(void)
{
    unsigned int i;

    /* mute all sids */
    memset(sidbuf, 0, sizeof(sidbuf));
    for (i = 0; i < sizeof(sidbuf); i++) {
        write_sid(i, 0);
    }

#if defined(pci_obtain_card) && defined(pci_release_card)
    if (CWLock) {
        pci_release_card(dev);
    }
#endif

    if (OpenPciBase)
    CloseLibrary((struct Library*)OpenPciBase);

    log_message(LOG_DEFAULT, "CatWeasel MK3 PCI SID: closed");

    return 0;
}

/* set current main clock frequency, which gives us the possibilty to
   choose between pal and ntsc frequencies */
void catweaselmkiii_set_machine_parameter(long cycles_per_sec)
{
    sid_NTSC = (cycles_per_sec <= 1000000) ? FALSE : TRUE;
}

#endif


#if defined(HAVE_CATWEASELMKIII) && defined(AMIGA_OS4)

#include <stdlib.h>
#include <string.h>

#include "catweaselmkiii.h"
#include "log.h"
#include "types.h"

static unsigned char read_sid(unsigned char reg); // Read a SID register
static void write_sid(unsigned char reg, unsigned char data); // Write a SID register

typedef void (*voidfunc_t)(void);

#define MAXSID 1

/* buffer containing current register state of SIDs */
static BYTE sidbuf[0x20 * MAXSID];

static int sidfh = 0;

/* read value from SIDs */
int catweaselmkiii_read(WORD addr, int chipno)
{
    /* check if chipno and addr is valid */
    if (chipno < MAXSID && addr < 0x20) {
        /* if addr is from read-only register, perform a read read */
        if (addr >= 0x19 && addr <= 0x1C && sidfh >= 0) {
            addr += chipno * 0x20;
            sidbuf[addr] = read_sid(addr);
        } else {
          addr += chipno*0x20;
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
    if (chipno < MAXSID && addr <= 0x18) {
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

/*
** How to use the SID in a CWMk3 under OS4...
** By Peter Gordon (pete@shagged.org)
**
*/

#define CW_SID_DAT 0xd8
#define CW_SID_CMD 0xdc

#undef BYTE
#undef WORD
#include <exec/types.h>
#include <proto/expansion.h>
#include <proto/exec.h>

struct Library *ExpansionBase = NULL;
struct ExpansionIFace *IExpansion = NULL;
static struct PCIIFace *IPCI = NULL;

static struct PCIDevice *CWDevPCI = NULL;
static struct PCIResourceRange *CWDevBAR = NULL;
int CWLock = FALSE;

// Set as appropriate
static int sid_NTSC = FALSE; // TRUE for 60Hz oscillator, FALSE for 50

int catweaselmkiii_open(void)
{
    static int atexitinitialized = 0;
    unsigned int i;

    if (atexitinitialized) {
        catweaselmkiii_close();
    }

    ExpansionBase = IExec->OpenLibrary("expansion.library", 50);
    if (!ExpansionBase) {
        log_message(LOG_DEFAULT, "Unable to open expansion.library\n");
        return -1;
    }

    IPCI = (struct PCIIFace *)IExec->GetInterface(ExpansionBase, "pci", 1, NULL);
    if (!IPCI) {
        log_message(LOG_DEFAULT, "Unable to obtain PCI expansion interface\n");
        return -1;
    }

    // Try and find a CW on the PCI bus
    CWDevPCI = IPCI->FindDeviceTags(FDT_VendorID, 0xe159,
                                    FDT_DeviceID, 0x0001,
                                    FDT_Index, 0,
                                    TAG_DONE);
    if (!CWDevPCI) {
        log_message(LOG_DEFAULT, "Unable to find a Catweasel Mk3 PCI card\n");
        return -1;
    }

    // Lock the device, since we're a driver
    CWLock = CWDevPCI->Lock(PCI_LOCK_SHARED);
    if (!CWLock) {
        log_message(LOG_DEFAULT, "Unable to lock the catweasel. Another driver may have an exclusive lock\n" );
        return -1;
    }

    // Get the resource range
    CWDevBAR = CWDevPCI->GetResourceRange(0);
    if (!CWDevBAR) {
        log_message(LOG_DEFAULT, "Unable to get resource range 0\n" );
        return -1;
    }

    // Reset the catweasel PCI interface (as per the CW programming docs)
    CWDevPCI->OutByte(CWDevBAR->BaseAddress + 0x00, 0xf1);
    CWDevPCI->OutByte(CWDevBAR->BaseAddress + 0x01, 0x00);
    CWDevPCI->OutByte(CWDevBAR->BaseAddress + 0x02, 0x00);
    CWDevPCI->OutByte(CWDevBAR->BaseAddress + 0x04, 0x00);
    CWDevPCI->OutByte(CWDevBAR->BaseAddress + 0x05, 0x00);
    CWDevPCI->OutByte(CWDevBAR->BaseAddress + 0x29, 0x00);
    CWDevPCI->OutByte(CWDevBAR->BaseAddress + 0x2b, 0x00);                                      

    /* mute all sids */
    memset(sidbuf, 0, sizeof(sidbuf));
    for (i = 0; i < sizeof(sidbuf); i++) {
        write_sid(i, 0);
    }

    log_message(LOG_DEFAULT, "CatWeasel MK3 PCI SID: opened");

    /* install exit handler, so device is closed on exit */
    if (!atexitinitialized) {
        atexitinitialized = 1;
        atexit((voidfunc_t)catweaselmkiii_close);
    }

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

    if (CWDevBAR) {
        CWDevPCI->FreeResourceRange(CWDevBAR);
    }
    if (CWLock) {
        CWDevPCI->Unlock();
    }
    if (IPCI) {
        IExec->DropInterface((struct Interface *)IPCI);
    }
    if (ExpansionBase) {
        IExec->CloseLibrary(ExpansionBase);
    }

    log_message(LOG_DEFAULT, "CatWeasel MK3 PCI SID: closed");

    return 0;
}

static unsigned char read_sid(unsigned char reg)
{
    unsigned char cmd;

    cmd = (reg & 0x1f) | 0x20;	// Read command & address
    if (sid_NTSC) {
        cmd |= 0x40;  // Make sure its correct frequency
    }

    // Write command to the SID
    CWDevPCI->OutByte(CWDevBAR->BaseAddress + CW_SID_CMD, cmd);

    // Waste 1ms
    CWDevPCI->InByte(CWDevBAR->BaseAddress + CW_SID_DAT);
    CWDevPCI->InByte(CWDevBAR->BaseAddress + CW_SID_DAT);

    return CWDevPCI->InByte(CWDevBAR->BaseAddress + CW_SID_DAT);
}

static void write_sid(unsigned char reg, unsigned char data)
{
    unsigned char cmd;

    cmd = reg & 0x1f;
    if (sid_NTSC) {
        cmd |= 0x40;  // Make sure its correct frequency
    }

    // Write data to the SID
    CWDevPCI->OutByte(CWDevBAR->BaseAddress + CW_SID_DAT, data);
    CWDevPCI->OutByte(CWDevBAR->BaseAddress + CW_SID_CMD, cmd);

    // Waste 1ms
    CWDevPCI->InByte(CWDevBAR->BaseAddress + CW_SID_DAT);
    CWDevPCI->InByte(CWDevBAR->BaseAddress + CW_SID_DAT);
}

/* set current main clock frequency, which gives us the possibilty to
   choose between pal and ntsc frequencies */
void catweaselmkiii_set_machine_parameter(long cycles_per_sec)
{
    sid_NTSC = (cycles_per_sec <= 1000000) ? FALSE : TRUE;
}
#endif

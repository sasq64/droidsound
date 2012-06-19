/*
 * petmem.c - PET memory handling.
 *
 * Written by
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  Andre Fachat <fachat@physik.tu-chemnitz.de>
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

#include "vice.h"

#include <stdio.h>
#include <string.h>

#include "6809.h"
#include "crtc-mem.h"
#include "crtctypes.h"
#include "log.h"
#include "machine.h"
#include "mem.h"
#include "monitor.h"
#include "pet.h"
#include "petacia.h"
#include "petdww.h"
#include "petmem.h"
#include "petmodel.h"
#include "petpia.h"
#include "petreu.h"
#include "pets.h"
#include "petvia.h"
#include "ram.h"
#include "resources.h"
#include "sid.h"
#include "sidcart.h"
#include "sid-resources.h"
#include "types.h"
#include "via.h"
#include "vsync.h"


static BYTE mem_read_patchbuf(WORD addr);

BYTE petmem_2001_buf_ef[256];

/* Old program counter.  Not used without MMU support.  */
unsigned int mem_old_reg_pc;

/* ------------------------------------------------------------------------- */

/* we keep the current system config in here. */

petres_t petres = { 32, 0x0800, 1, 80, 0, 0, 0, 0, 0, 0, 0,
                    /* ROM image resources */
                    NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                    /* SuperPET resources */
                    { NULL }, SUPERPET_CPU_6502,
                    /* runtime (derived) variables */
                    0, PET_MAP_LINEAR, 0, 0, 0, 0, 0, 0
};

/* ------------------------------------------------------------------------- */

/* The PET memory. */

#define RAM_ARRAY 0x20000 /* this includes 8x96 expansion RAM */
#define PET_6809_ROMSIZE        (NUM_6809_ROMS * 0x1000)

BYTE mem_ram[RAM_ARRAY]; /* 128K to make things easier. Real size is 4-128K. */
BYTE mem_rom[PET_ROM_SIZE];
BYTE mem_chargen_rom[PET_CHARGEN_ROM_SIZE];
BYTE mem_6809rom[PET_6809_ROMSIZE];

static int ram_size = RAM_ARRAY;       /* FIXME? */

/* Memory read and write tables. */
static read_func_ptr_t _mem_read_tab[0x101];
static store_func_ptr_t _mem_write_tab[0x101];
static read_func_ptr_t _mem_read_tab_watch[0x101];
static store_func_ptr_t _mem_write_tab_watch[0x101];
static BYTE *_mem_read_base_tab[0x101];
static int mem_read_limit_tab[0x101];

read_func_ptr_t *_mem_read_tab_ptr;
store_func_ptr_t *_mem_write_tab_ptr;
BYTE **_mem_read_base_tab_ptr;
int *mem_read_limit_tab_ptr;

/* 8x96 mapping register */
BYTE petmem_map_reg = 0;
static int bank8offset = 0;
static int bankCoffset = 0;

/* memory tables for the 6809 */
static read_func_ptr_t _mem6809_read_tab[0x101];
static store_func_ptr_t _mem6809_write_tab[0x101];
static read_func_ptr_t _mem6809_read_tab_watch[0x101];
static store_func_ptr_t _mem6809_write_tab_watch[0x101];
static BYTE *_mem6809_read_base_tab[0x101];
static int mem6809_read_limit_tab[0x101];

read_func_ptr_t *_mem6809_read_tab_ptr;
store_func_ptr_t *_mem6809_write_tab_ptr;

static log_t pet_mem_log = LOG_ERR;

/* ------------------------------------------------------------------------- */

BYTE zero_read(WORD addr)
{
    return mem_ram[addr & 0xff];
}

void zero_store(WORD addr, BYTE value)
{
    mem_ram[addr & 0xff] = value;
}

static BYTE ram_read(WORD addr)
{
    return mem_ram[addr];
}

static void ram_store(WORD addr, BYTE value)
{
/*
if (addr == 0x8000) printf("charline=%d, ycount=%d, char=%d\n",
        crtc.current_charline, crtc.raster.ycounter, clk - crtc.rl_start);
*/
    mem_ram[addr] = value;
}

static BYTE read_ext8(WORD addr)
{
    return mem_ram[addr + bank8offset];
}

static void store_ext8(WORD addr, BYTE value)
{
    mem_ram[addr + bank8offset] = value;
}

static BYTE read_extC(WORD addr)
{
    return mem_ram[addr + bankCoffset];
}

static void store_extC(WORD addr, BYTE value)
{
    mem_ram[addr + bankCoffset] = value;
}

static BYTE read_vmirror(WORD addr)
{
    return mem_ram[0x8000 + (addr & (petres.videoSize - 1))];
}

static void store_vmirror(WORD addr, BYTE value)
{
    mem_ram[0x8000 + (addr & (petres.videoSize - 1))] = value;
}

BYTE rom_read(WORD addr)
{
    return mem_rom[addr & 0x7fff];
}

void rom_store(WORD addr, BYTE value)
{
    mem_rom[addr & 0x7fff] = value;
}

#define ROM6809_BASE    0xA000

BYTE rom6809_read(WORD addr)
{
    return mem_6809rom[addr - ROM6809_BASE];
    //BYTE val = mem_6809rom[addr - ROM6809_BASE];
    //printf("rom6809_read %04x -> %02x\n", addr, val);
    //return val;
}

void rom6809_store(WORD addr, BYTE value)
{
    mem_6809rom[addr - ROM6809_BASE] = value;
}

static BYTE read_unused(WORD addr)
{
    if (petreu_enabled) {
        if (addr >= 0x8800 && addr < 0x8900) {
            return read_petreu_reg(addr);
        } else if (addr >= 0x8900 && addr < 0x8a00) {
            return read_petreu_ram(addr);
        } else if (addr >= 0x8a00 && addr < 0x8b00) {
            return read_petreu2_reg(addr);
        }
    }

    if (petdww_enabled) {
        if (addr >= 0xeb00 && addr < 0xec00) {
            return read_petdww_reg(addr);
        } else if (addr >= 0xec00 && addr < 0xf000 && !petdww_mem_at_9000()) {
            return read_petdww_ec00_ram(addr);
        }
    }

    if (sidcart_enabled()) {
        if (sidcart_address == 1 && addr >= 0xe900 && addr <= 0xe91f) {
            return sid_read(addr);
        } else if (sidcart_address == 0 && addr >= 0x8f00 && addr <= 0x8f1f) {
            return sid_read(addr);
        }
    }

    return (addr >> 8) & 0xff;
}

static BYTE mem_read_patchbuf(WORD addr)
{
    return petmem_2001_buf_ef[addr & 0xff];
}

/* ------------------------------------------------------------------------- */

/* Functions for watchpoint memory access.  */

static BYTE read_watch(WORD addr)
{
    monitor_watch_push_load_addr(addr, e_comp_space);
    return _mem_read_tab[addr >> 8](addr);
}

static void store_watch(WORD addr, BYTE value)
{
    monitor_watch_push_store_addr(addr, e_comp_space);
    _mem_write_tab[addr >> 8](addr, value);
}

static BYTE read6809_watch(WORD addr)
{
    monitor_watch_push_load_addr(addr, e_comp_space);
    return _mem6809_read_tab[addr >> 8](addr);
}

static void store6809_watch(WORD addr, BYTE value)
{
    monitor_watch_push_store_addr(addr, e_comp_space);
    _mem6809_write_tab[addr >> 8](addr, value);
}

/* ------------------------------------------------------------------------- */

/* SuperPET handling
 *
 * This adds some write-only registers at $eff*, an ACIA at $eff0 and
 * 64k RAM that are mapped in 4k pages at $9***.
 * Here the 8x96 expansion RAM doubles as the SuperPET banked RAM.
 * There is also a dongle (6702) at $efe0.
 */

int spet_ramen  = 1;
int spet_bank   = 0;
int spet_ctrlwp = 1;
int spet_diag   = 0;
int spet_ramwp  = 0;
#define DEBUG_DONGLE    0

/* Internal state of the 6702 dongle */
#define DONGLE_MAGIC    (128 + 64 + 16 + 4 + 2) /* = 214 = $D6 = %1101 0110 */
static int shift[8];
static const int leftmost[8] = {
    1 << (6 - 1),       /*   1 The size of each shift register is 6, 3, 7... */
    1 << (3 - 1),       /*   2 and therefore those are also the periods of */
    1 << (7 - 1),       /*   4 the output bits. */
    1 << (8 - 1),       /*   8 */
    1 << (1 - 1),       /*  16 */
    1 << (3 - 1),       /*  32 */
    1 << (5 - 1),       /*  64 */
    1 << (2 - 1),       /* 128 */
};
static int val6702;
static int prevodd;
static int wantodd;

static void reset6702(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        if ((1 << i) & (DONGLE_MAGIC | 1)) {
            shift[i] = leftmost[i];
        } else {
            shift[i] = 0;
        }
    }
    val6702 = DONGLE_MAGIC;
    prevodd = 1;
    wantodd = 0;
}

static inline
BYTE read6702(void)
{
    return val6702;
}

/*
 * Only the first odd value which is written after
 * an even value has an effect.
 *
 * Thanks to Ruud Baltissen, William Levak, Rob Clarke,
 * Kajtar Zsolt and Segher Boessenkool, from cbm-hackers,
 * for their contributions.
 * -Olaf Seibert.
 */
static inline
void write6702(BYTE input)
{
    if ((input & 1) == wantodd) {
        if (wantodd) {
            int i;
            int v = val6702;
            int changed = prevodd ^ input;
            int mask = 0x80;

            /* loop over all 8 output bits / shift registers */
            for (i = 7; i >= 0; i--, mask >>= 1) {
                /* If the input bit changed toggle leftmost bit */
                if (changed & mask) {
                    shift[i] ^= leftmost[i];
                }
                if (shift[i] & 1) {
                    v ^= mask;
                    shift[i] |= leftmost[i] << 1; /* wrap bit around */
                }
                shift[i] >>= 1;
            }

            prevodd = input;
            val6702 = v;
        }
        wantodd ^= 1;
    }
}

/*
 * It is possible to "emulate" the 6702 dongle by returning a sequence
 * of fixed values.  We even ignore the values that are written to it!
 * Idea and recovery of values by Dave E. Roberts.
 *
 * Code references to Waterloo Editor 1.1.
 * The dongle check routine starts at $9852 in bank 0.
 *
 * This table is not needed any more since the emulation has been
 * perfected but it is here for reference.
 */

/*
static BYTE dongle_values [ 29 ] = {    // Indexed as 0 to 28.
    / * Used once at the start of the subroutine.        * /
    0x04, / * 9860: LDA  [<$06,S] ; [ 0]                 * /

    / * Iteration 1 of the 'outer' loop.                 * /
    0xFF, / * 987C: ASL  [<$06,S] ; Can ignore!          * /
    0x91, / * 987F: EORB [<$06,S] ; [ 2]                 * /
    0xFF, / * 9887: ASL  [<$06,S] ; Can ignore!          * /
    0x3C, / * 988A: LDA  [<$06,S] ; [ 4]                 * /

    / * Iteration 2 of the 'outer' loop.                 * /
    0xFF, / * 987C: ASL  [<$06,S] ; Can ignore!          * /
    0xAC, / * 987F: EORB [<$06,S] ; [ 6]                 * /
    0xFF, / * 9887: ASL  [<$06,S] ; Can ignore!          * /
    0xC7, / * 988A: LDA  [<$06,S] ; [ 8]                 * /

    / * Iteration 3 of the 'outer' loop.                 * /
    0xFF, / * 987C: ASL  [<$06,S] ; Can ignore!          * /
    0xF0, / * 987F: EORB [<$06,S] ; [10]                 * /
    0xFF, / * 9887: ASL  [<$06,S] ; Can ignore!          * /
    0xE3, / * 988A: LDA  [<$06,S] ; [12]                 * /

    / * Iteration 4 of the 'outer' loop.                 * /
    0xFF, / * 987C: ASL  [<$06,S] ; Can ignore!          * /
    0x36, / * 987F: EORB [<$06,S] ; [14]                 * /
    0xFF, / * 9887: ASL  [<$06,S] ; Can ignore!          * /
    0x5A, / * 988A: LDA  [<$06,S] ; [16]                 * /

    / * Iteration 5 of the 'outer' loop.                 * /
    0xFF, / * 987C: ASL  [<$06,S] ; Can ignore!          * /
    0xBB, / * 987F: EORB [<$06,S] ; [18]                 * /
    0xFF, / * 9887: ASL  [<$06,S] ; Can ignore!          * /
    0xC3, / * 988A: LDA  [<$06,S] ; [20]                 * /

    / * Iteration 6 of the 'outer' loop.                 * /
    0xFF, / * 987C: ASL  [<$06,S] ; Can ignore!          * /
    0x6A, / * 987F: EORB [<$06,S] ; [22]                 * /
    0xFF, / * 9887: ASL  [<$06,S] ; Can ignore!          * /
    0x75, / * 988A: LDA  [<$06,S] ; [24]                 * /

    / * Iteration 7 of the 'outer' loop.                 * /
    0xFF, / * 987C: ASL  [<$06,S] ; Can ignore!          * /
    0xA3, / * 987F: EORB [<$06,S] ; [26]                 * /
    0xFF, / * 9887: ASL  [<$06,S] ; Can ignore!          * /
    0x3E  / * 988A: LDA  [<$06,S] ; [28]                 * /

    / * In fact, these values below are the ones that are
      * produced by the real thing, starting from a reset. * /

                   214,
    214, 214, 214, 214,
    214, 214, 198, 198,
    198, 198, 212, 212,
    212, 212,  84,  84,
     84,  84,   6,   6,
      6,   6,  39,  39,
     39,  39,  51,  51,
};
*/

static int efe0_dump(void)
{
    int i;
    int mask = 1;

    mon_out("efe0 = $%02x; previous in = $%02x; odd/even = %d\n", val6702, prevodd, wantodd);
    for (i = 0; i < 8; i++, mask <<= 1) {
        int j;
        int maskj;
        int sh = shift[i];
        int lm = leftmost[i];

        mon_out("%d %3d: $%02x  %%", i, mask, sh);

        for (j = 7, maskj = 1<<j; j >= 0; j--, maskj >>= 1) {
            if (maskj > lm) {
                mon_out(" ");
            } else if (sh & maskj) {
                mon_out("1");
            } else {
                mon_out("0");
            }
        }
        mon_out("\n");
    }

    return 0;
}

void petmem_reset(void)
{
    spet_ramen = 1;
    spet_bank = 0;
    spet_ctrlwp = 1;

    petmem_map_reg = 0;
#if DEBUG_DONGLE
    printf("reset 6702\n");
#endif
    reset6702();
}

static void superpet_powerup(void)
{
/* Those two are not reset by a soft reset (/RES), only by power down */
    spet_diag = 0;
    spet_ramwp = 0;     /* should look at hardware switch */
    petmem_reset();
}

int petmem_superpet_diag(void)
{
    return petres.superpet && spet_diag;
}

static BYTE read_super_io(WORD addr)
{
    if (addr >= 0xeff4) {       /* unused / readonly */
        return read_unused(addr);
    } else
    if (addr >= 0xeff0) {       /* ACIA */
        return acia1_read((WORD)(addr & 0x03));
    } else
    if ((addr & 0x0010) == 0) {
        /* Dongle E F xxx0 xxxx, see zimmers.net,
         * schematics/computers/pet/SuperPET/324055.gif.
         * Typical address is $EFE0, possibly EFE0...3.
         */
        if (addr >= 0xefe0 && addr < 0xefe4) {
            BYTE dongle_value = read6702();
#if DEBUG_DONGLE
            log_message(pet_mem_log, "*** DONGLE %04x -> 0x%02X %3d", addr, dongle_value, dongle_value);
#endif /* DEBUG_DONGLE */
            return dongle_value;
        }
        return 0xff;
    }
    return read_unused(addr);   /* fallback */
}

static void store_super_io(WORD addr, BYTE value)
{
    if (addr >= 0xeffe) {       /* RAM/ROM switch */
        spet_ramen = !(value & 1);
        //printf("spet_ramen := %d\n", spet_ramen);
    } else
    if (addr >= 0xeffc) {       /* Bank select */
        spet_bank = value & 0x0f;
        spet_ctrlwp = !(value & 0x80);
        //printf("spet_bank := %d\n", spet_bank);
        //printf("spet_ctrlwp := %d\n", spet_ctrlwp);
    } else {
        if (addr >= 0xeff8) {
            if (!spet_ctrlwp) {
                if (!(value & 1)) {
                    log_error(pet_mem_log, "SuperPET: switching to 6809 not emulated!");
                    machine_trigger_reset(MACHINE_RESET_MODE_SOFT);
                }
                spet_ramwp = !(value & 0x2);    /* IF hardware w/p switch is PROG */
                //printf("spet_ramwp := %d\n", spet_ramwp);
                spet_diag = (value & 0x8);
            }
        } else
        if (addr >= 0xeff4) {   /* unused */
        } else
        if (addr >= 0xeff0) {   /* ACIA */
            acia1_store((WORD)(addr & 0x03), value);
        } else if (addr >= 0xefe0 && addr < 0xefe4) { /* dongle */
#if DEBUG_DONGLE
            log_message(pet_mem_log, "*** DONGLE %04x := %02X %3d", addr, value, value);
#endif
            write6702(value);
        }
    }
}

static BYTE read_super_9(WORD addr)
{
    if (spet_ramen) {
        return (mem_ram + 0x10000)[(spet_bank << 12) | (addr & 0x0fff)];
    }
    return rom_read(addr);
}

static void store_super_9(WORD addr, BYTE value)
{
    if (spet_ramen && !spet_ramwp) {
        /* printf("store_super_9: %04x <- %04x <- %02x\n",
                (spet_bank << 12) | (addr & 0x0fff),
                addr, value); */
        (mem_ram + 0x10000)[(spet_bank << 12) | (addr & 0x0fff)] = value;
    }
}


/* ------------------------------------------------------------------------- */

/* Generic memory access.  */

void mem_store(WORD addr, BYTE value)
{
    _mem_write_tab_ptr[addr >> 8](addr, value);
}

BYTE mem_read(WORD addr)
{
    return _mem_read_tab_ptr[addr >> 8](addr);
}

#define PRINT_6809_STORE        0
#define PRINT_6809_READ         0

void mem6809_store(WORD addr, BYTE value)
{
#if PRINT_6809_STORE
    if (addr >= 0x8000 && addr < 0x9000)
        printf("mem6809_store   %04x <- %02x\n", addr, value);
#endif
    _mem6809_write_tab_ptr[addr >> 8](addr, value);
}

BYTE mem6809_read(WORD addr)
{
#if PRINT_6809_READ
    BYTE v;
    v = _mem6809_read_tab_ptr[addr >> 8](addr);
    printf("mem6809_read   %04x -> %02x\n", addr, v);
    return v;
#else
    return _mem6809_read_tab_ptr[addr >> 8](addr);
#endif
}

void mem6809_store16(WORD addr, WORD value)
{
#if PRINT_6809_STORE0
    printf("mem6809_store16 %04x <- %04x\n", addr, value);
#endif
    addr++;
    _mem6809_write_tab_ptr[addr >> 8](addr, (BYTE)(value & 0xFF));
    addr--;
    _mem6809_write_tab_ptr[addr >> 8](addr, (BYTE)(value >> 8));
}

WORD mem6809_read16(WORD addr)
{
    WORD val;
    val  = _mem6809_read_tab_ptr[addr >> 8](addr) << 8;
    addr++;
    val |= _mem6809_read_tab_ptr[addr >> 8](addr);
#if PRINT_6809_READ
    printf("mem6809_read16 %04x -> %04x\n", addr, val);
#endif
    return val;
}

#ifdef H6309
void mem6809_store32(WORD addr, DWORD value)
{
#if PRINT_6809_STORE0
    printf("mem6809_store32 %04x <- %04x\n", addr, value);
#endif
    addr += 3;
    _mem6809_write_tab_ptr[addr >> 8](addr, (BYTE)(value & 0xFF));
    addr--;
    _mem6809_write_tab_ptr[addr >> 8](addr, (BYTE)((value >> 8) & 0xFF));
    addr--;
    _mem6809_write_tab_ptr[addr >> 8](addr, (BYTE)((value >> 16) & 0xFF));
    addr--;
    _mem6809_write_tab_ptr[addr >> 8](addr, (BYTE)(value >> 24));
}

DWORD mem6809_read32(WORD addr)
{
    DWORD val;
    val  = _mem6809_read_tab_ptr[addr >> 8](addr) << 24;
    addr++;
    val |= _mem6809_read_tab_ptr[addr >> 8](addr) << 16;
    addr++;
    val |= _mem6809_read_tab_ptr[addr >> 8](addr) << 8;
    addr++;
    val |= _mem6809_read_tab_ptr[addr >> 8](addr);
#if PRINT_6809_READ
    printf("mem6809_read32 %04x -> %04x\n", addr, val);
#endif
    return val;
}
#endif

/* ------------------------------------------------------------------------- */

/* The PET have all I/O chips connected to the same select lines.  Only one
   address lines is used as separate (high-active) select input.  I.e. PIA1
   always reacts when address & 0x10 is high, for example $e810, $e830,
   $e850, etc.  PIA2 reacts when address & 0x20 is high, for example $e820,
   $e830 $e860,...  The next two functions try to reflect this behaviour.  */

/* When we write, we write all involved chips.  */

static void store_io(WORD addr, BYTE value)
{
    if (addr & 0x10)
        pia1_store(addr, value);

    if (addr & 0x20)
        pia2_store(addr, value);

    if (addr & 0x40)
        via_store(addr, value);

    if ((addr & 0x80) && petres.crtc) {
        crtc_store(addr, value);
    }
}


/*
 * When we read, we only read sensible values. In real operation,
 * the bus drivers of all involved chips interact and you get strange
 * results...
 */
static BYTE read_io(WORD addr)
{
    BYTE v1, v2, v3, v4;

    switch (addr & 0xf0) {
      case 0x10:                /* PIA1 */
        return pia1_read(addr);
      case 0x20:                /* PIA2 */
        return pia2_read(addr);
      case 0x40:
        return via_read(addr);  /* VIA */
      case 0x80:                /* CRTC */
        if (petres.crtc) {
            return crtc_read(addr);
        }
      case 0x00:
        return addr >> 8;
      default:                  /* 0x30, 0x50, 0x60, 0x70, 0x90-0xf0 */
        if (addr & 0x10)
            v1 = pia1_read(addr);
        else
            v1 = 0xff;
        if (addr & 0x20)
            v2 = pia2_read(addr);
        else
            v2 = 0xff;
        if (addr & 0x40)
            v3 = via_read(addr);
        else
            v3 = 0xff;
        v4 = 0xff;
        if ((addr & 0x80) && petres.crtc) {
            v4 = crtc_read(addr);
        }
        return v1 & v2 & v3 & v4;
    }
}

static void store_void(WORD addr, BYTE value)
{
    (void)value;
}

/*
 * store_dummy() stores in normally-unassigned memory space,
 * except that some hardware expansions may be there.
 * For adresses < 0x8000 it is faster to use store_void().
 */
static void store_dummy(WORD addr, BYTE value)
{
    if (petreu_enabled) {
        if (addr >= 0x8800 && addr < 0x8900) {
            store_petreu_reg(addr,value);
        } else if (addr >= 0x8900 && addr < 0x8a00) {
            store_petreu_ram(addr,value);
        } else if (addr >= 0x8a00 && addr < 0x8b00) {
            store_petreu2_reg(addr,value);
        }
    }

    if (petdww_enabled) {
        if (addr >= 0xeb00 && addr < 0xec00) {
            store_petdww_reg(addr, value);
        } else if (addr >= 0xec00 && addr < 0xf000 && !petdww_mem_at_9000()) {
            store_petdww_ec00_ram(addr, value);
        }
    }

    if (sidcart_enabled()) {
        if (sidcart_address == 1 && addr >= 0xe900 && addr < 0xe91f) {
            sid_store(addr,value);
        } else if (sidcart_address == 0 && addr >= 0x8f00 && addr < 0x8f1f) {
            sid_store(addr,value);
        }
    }

    return;
}

/*
 * This sets the standard PET memory configuration from $9000-$10000.
 * It is used in store_8x96() and mem_initialize_memory().
 */
static void set_std_9tof(void)
{
    int i, l;
    static void (*store)(WORD, BYTE);
    int ram9, rama;

    store = (petres.map == PET_MAP_8296) ? ram_store : store_dummy;
    ram9 = (petres.map == PET_MAP_8296 && petres.mem9) ? 1 : 0;
    rama = (petres.map == PET_MAP_8296 && petres.memA) ? 1 : 0;

    /* Setup RAM/ROM at $9000 - $9FFF. */
    if (petres.superpet) {
        for (i = 0x90; i < 0xa0; i++) {
            _mem_read_tab[i] = read_super_9;
            _mem_write_tab[i] = store_super_9;
            _mem_read_base_tab[i] = NULL;
            mem_read_limit_tab[i] = -1;
        }
    } else {
        for (i = 0x90; i < 0xa0; i++) {
            _mem_read_tab[i] = ram9 ? ram_read : rom_read;
            _mem_write_tab[i] = store;
            _mem_read_base_tab[i] = ram9 ? mem_ram + (i << 8)
                                    : mem_rom + ((i & 0x7f) << 8);
            mem_read_limit_tab[i] = 0x9ffd;
        }
    }

    /* Setup RAM/ROM at $A000 - $AFFF. */
    for (i = 0xa0; i < 0xb0; i++) {
        _mem_read_tab[i] = rama ? ram_read : rom_read;
        _mem_write_tab[i] = store;
        _mem_read_base_tab[i] = rama ? mem_ram + (i << 8)
                                     : mem_rom + ((i & 0x7f) << 8);
        mem_read_limit_tab[i] = 0xaffd;
    }

    if (petdww_enabled && petdww_mem_at_9000()) {
        petdww_override_std_9toa(_mem_read_tab, _mem_write_tab, _mem_read_base_tab, mem_read_limit_tab);
    }

    /* Setup ROM at $B000 - $E7FF. */
    for (i = 0xb0; i <= 0xe7; i++) {
        _mem_read_tab[i] = rom_read;
        _mem_write_tab[i] = store;
        _mem_read_base_tab[i] = mem_rom + ((i & 0x7f) << 8);
        mem_read_limit_tab[i] = 0xe7fd;
    }

    l = ((0xe800 + petres.IOSize) >> 8) & 0xff;

    /* Setup I/O at $e800 - $e800 + petres.IOSize. */
    /* i.e. IO at $e800... */
    _mem_read_tab[0xe8] = read_io;
    _mem_write_tab[0xe8] = store_io;
    _mem_read_base_tab[0xe8] = NULL;
    mem_read_limit_tab[0xe8] = -1;

    /* ... and unused address space behind it */
    for (i = 0xe9; i < l; i++) {
        _mem_read_tab[i] = read_unused;
        _mem_write_tab[i] = store;
        _mem_read_base_tab[i] = NULL;
        mem_read_limit_tab[i] = -1;
    }

    if (petres.superpet) {
        _mem_read_tab[0xef] = read_super_io;
        _mem_write_tab[0xef] = store_super_io;
        _mem_read_base_tab[0xef] = NULL;
        mem_read_limit_tab[0xef] = -1;
    } else
    if (petres.rompatch) {
        _mem_read_tab[0xef] = mem_read_patchbuf;
        _mem_write_tab[0xef] = store_void;
        _mem_read_base_tab[0xef] = petmem_2001_buf_ef;
        mem_read_limit_tab[0xef] = 0xeffd;
    }

    /* Setup ROM at $e800 + petres.IOSize - $ffff */
    for (i = l; i <= 0xff; i++) {
        _mem_read_tab[i] = rom_read;
        _mem_write_tab[i] = store;
        _mem_read_base_tab[i] = mem_rom + ((i & 0x7f) << 8);
        mem_read_limit_tab[i] = 0xfffd;
    }

    _mem_read_base_tab_ptr = _mem_read_base_tab;
    mem_read_limit_tab_ptr = mem_read_limit_tab;
}

void get_mem_access_tables(read_func_ptr_t **read, store_func_ptr_t **write, BYTE ***base, int **limit)
{
    *read = _mem_read_tab;
    *write = _mem_write_tab;
    *base = _mem_read_base_tab;
    *limit = mem_read_limit_tab;
}

static BYTE **cpu_mem_base_ptr;
static int *cpu_mem_limit_ptr;

void mem_set_bank_pointer(BYTE **base, int *limit)
{
    cpu_mem_base_ptr = base;
    cpu_mem_limit_ptr = limit;
}

void invalidate_mem_limit(int lower, int upper)
{
    if (cpu_mem_limit_ptr &&
            *cpu_mem_limit_ptr >= lower && *cpu_mem_limit_ptr < upper) {
        *cpu_mem_limit_ptr = -1;
        *cpu_mem_base_ptr = NULL;
    }
}

/* FIXME: TODO! */
void mem_toggle_watchpoints(int flag, void *context)
{
    if (flag) {
        _mem_read_tab_ptr = _mem_read_tab_watch;
        _mem_write_tab_ptr = _mem_write_tab_watch;
        _mem6809_read_tab_ptr = _mem6809_read_tab_watch;
        _mem6809_write_tab_ptr = _mem6809_write_tab_watch;
    } else {
        _mem_read_tab_ptr = _mem_read_tab;
        _mem_write_tab_ptr = _mem_write_tab;
        _mem6809_read_tab_ptr = _mem6809_read_tab;
        _mem6809_write_tab_ptr = _mem6809_write_tab;
    }
}

/*
 * From the PETio.doc (ftp.funet.fi/firmware/pet/)
 *
 * $fff0 register in PET 8x96
 * 8096 exp-mem (64K):
 * The control register is at $FFF0/65520
 * You have 4 16K-banks, 0...3
 *
 * $8000     $9000               $C000           $E800    $F000     $FFFF
 * !----------------------------!!--------------------------------------!
 *         Bank 0 or 2                     Bank 1 or 3
 * !--------!                                    !-------!
 *   screen                                        io
 *
 * Control Register $FFF0:
 * bit 7:  0 normal 8032 configuration (screen, ROMs, IO, ROMs)
 *        80 expansion memory
 * bit 6:  0 RAM $E800-$EFFF (only when bit7=1)
 *        40 IO peek through
 * bit 5:  0 exp-mem $8000-$8FFF (-"-)
 *        20 screen peek through
 * bit 4: 10 not used
 * bit 3:  0 bank 1 $C000-$FFFF
 *        08 bank 3
 * bit 2:  0 bank 0 $8000-$BFFF
 *        04 bank 2
 * bit 1: 02 write protect bank 1/3
 * bit 0: 01 write protect bank 0/2
 * when bit7=0, all other bits are ignored
 *
 * The missing 32K can't be accessed witout hardware modifications.
 * You can only use the 2K "behind" the screen $8800-$8FFF (exact: 34768-
 * 36863), available in the normal configuration.
 * The register is write-only, and the value is written through to the
 * previously selected ram bank.
 *
 */

/* Save old store function for last byte.  */
static void (*store_ff)(WORD addr, BYTE value) = NULL;

/* Write to last page of memory in 8x96.  */
static void store_8x96(WORD addr, BYTE value)
{
    BYTE changed;
    int l, protected;

    if (store_ff)
        store_ff(addr, value);

    changed = petmem_map_reg ^ value;

    if (addr == 0xfff0 && changed && ((petmem_map_reg | changed) & 0x80)) {
        if (value & 0x80) {     /* ext. RAM enabled */
            if (changed & 0xa5) {       /* $8000-$bfff */
                protected = value & 0x01;
                l = 0x80;
                if (value & 0x20) {     /* screen memory mapped through */
                    for (; l < 0x90; l++) {
                        _mem_read_tab[l] = ram_read;
                        _mem_write_tab[l] = ram_store;
                        _mem_read_base_tab[l] = mem_ram + (l << 8);
                        mem_read_limit_tab[l] = 0x8ffd;
                    }
                }
                bank8offset = 0x8000 + ((value & 0x04) ? 0x8000 : 0);
                for (; l < 0xc0; l++) {
                    _mem_read_tab[l] = read_ext8;
                    if (protected)
                        _mem_write_tab[l] = store_dummy;
                    else
                        _mem_write_tab[l] = store_ext8;
                    _mem_read_base_tab[l] = mem_ram + bank8offset + (l << 8);
                    mem_read_limit_tab[l] = 0xbffd;
                }
                invalidate_mem_limit(0x8000, 0xc000);
            }
            if (changed & 0xca) {       /* $c000-$ffff */
                protected = value & 0x02;
                bankCoffset = 0x8000 + ((value & 0x08) ? 0x8000 : 0);
                for (l = 0xc0; l < 0x100; l++) {
                    if ((l == 0xe8) && (value & 0x40)) {
                        _mem_read_tab[l] = read_io;
                        _mem_write_tab[l] = store_io;
                        _mem_read_base_tab[l] = NULL;
                        mem_read_limit_tab[l] = -1;
                    } else {
                        _mem_read_tab[l] = read_extC;
                        if (protected)
                            _mem_write_tab[l] = store_dummy;
                        else
                            _mem_write_tab[l] = store_extC;
                        _mem_read_base_tab[l] = mem_ram
                                                + bankCoffset + (l << 8);
                        if (l < 0xe8) {
                            mem_read_limit_tab[l] = 0xe7fd;
                        } else {
                            mem_read_limit_tab[l] = 0xfffd;
                        }
                    }
                }
                store_ff = _mem_write_tab[0xff];
                _mem_write_tab[0xff] = store_8x96;
                invalidate_mem_limit(0xc000, 0x10000);
            }
        } else {                /* disable ext. RAM */
            for (l = 0x80; l < 0x90; l++) {
                _mem_read_tab[l] = ram_read;
                _mem_write_tab[l] = ram_store;
                _mem_read_base_tab[l] = mem_ram + (l << 8);
                mem_read_limit_tab[l] = 0x8ffd;
            }
            set_std_9tof();
            store_ff = _mem_write_tab[0xff];
            _mem_write_tab[0xff] = store_8x96;
            invalidate_mem_limit(0x8000, 0x10000);
        }
        petmem_map_reg = value;

    }
    return;
}

static int fff0_dump(void)
{
    mon_out("fff0 = %02x: ", petmem_map_reg);
    if (petmem_map_reg & 0x80) {
        mon_out("enabled, ");
        if (petmem_map_reg & 0x40) {
            mon_out("I/O peek through, ");
        }
        if (petmem_map_reg & 0x20) {
            mon_out("screen peek through, ");
        }
        if (petmem_map_reg & 0x10) {
            mon_out("$10 unused bit set, ");
        }
        mon_out("\nC000-FFFF: bank %d %s, ",
            ((petmem_map_reg & 0x08) ? 3 : 1),
            ((petmem_map_reg & 0x02) ? "(write protected)" : "(r/w)")
               );
        mon_out("8000-BFFF: bank %d %s.\n",
            ((petmem_map_reg & 0x04) ? 2 : 0),
            ((petmem_map_reg & 0x01) ? "(write protected)" : "(r/w)")
               );
    } else {
        mon_out("disabled.\n");
    }
    return 0;
}

/* ------------------------------------------------------------------------- */

static void set_vidmem(void) {
    int i, l;

    l = ((0x8000 + petres.videoSize) >> 8) & 0xff;
/*
    log_message(pet_mem_log, "set_vidmem(videoSize=%04x, l=%d)",
                petres.videoSize,l);
*/
    /* Setup RAM from $8000 to $8000 + petres.videoSize */
    for (i = 0x80; i < l; i++) {
        _mem_read_tab[i] = ram_read;
        _mem_write_tab[i] = ram_store;
        _mem_read_base_tab[i] = mem_ram + (i << 8);
        mem_read_limit_tab[i] = (l<<8)-3;
    }

    /* Setup video mirror from $8000 + petres.videoSize to $87ff */
    /* falls through if videoSize >= 0x800 */
    for (; i < 0x88; i++) {
        _mem_read_tab[i] = read_vmirror;
        _mem_write_tab[i] = store_vmirror;
        _mem_read_base_tab[i] = mem_ram + 0x8000 + ((i << 8)
                                & (petres.videoSize - 1));
        mem_read_limit_tab[i] = 0x87fd;
    }

    /* Setup unused from $8800 to $8fff */
    /* falls through if videoSize >= 0x1000 */
    for (; i < 0x90; i++) {
        _mem_read_tab[i] = read_unused;
        _mem_write_tab[i] = store_dummy;
        _mem_read_base_tab[i] = NULL;
        mem_read_limit_tab[i] = -1;
    }
}

/* ------------------------------------------------------------------------- */

/* This does the plain 8032 configuration, as 8096 stuff only comes up when
   writing to $fff0.  */
void mem_initialize_memory(void)
{
    int i, l;

    l = petres.ramSize << 2;       /* ramSize in kB, l in 256 Byte */
    if (l > 128)
        l = 128;                /* fix 8096 / 8296 */

    /* Setup RAM from $0000 to petres.ramSize */
    _mem_read_tab[0] = zero_read;
    _mem_write_tab[0] = zero_store;
    _mem_read_base_tab[0] = mem_ram;
    mem_read_limit_tab[0] = 0x00fd;

    for (i = 0x01; i < l; i++) {
        _mem_read_tab[i] = ram_read;
        _mem_write_tab[i] = ram_store;
        _mem_read_base_tab[i] = mem_ram + (i << 8);
        mem_read_limit_tab[i] = (l << 8) - 3;
    }

    /* Setup unused from petres.ramSize to $7fff */
    for (i = l; i < 0x80; i++) {
        _mem_read_tab[i] = read_unused;
        _mem_write_tab[i] = store_void;
        _mem_read_base_tab[i] = NULL;
        mem_read_limit_tab[i] = -1;
    }

    set_vidmem();

    set_std_9tof();

    if (petres.map) {              /* catch writes to $fff0 register */
        store_ff = _mem_write_tab[0xff];
        _mem_write_tab[0xff] = store_8x96;
    }
    _mem_read_tab[0x100] = _mem_read_tab[0];
    _mem_write_tab[0x100] = _mem_write_tab[0];
    _mem_read_base_tab[0x100] = _mem_read_base_tab[0];
    mem_read_limit_tab[0x100] = -1;

    ram_size = petres.ramSize * 1024;
    _mem_read_tab_ptr = _mem_read_tab;
    _mem_write_tab_ptr = _mem_write_tab;

    for (i = 0; i < 0x101; i++) {
        _mem_read_tab_watch[i] = read_watch;
        _mem_write_tab_watch[i] = store_watch;
    }

    if (petres.map && petmem_map_reg) {
        BYTE old_map_reg;

        old_map_reg = petmem_map_reg;
        petmem_map_reg = 0;
        store_8x96(0xfff0, old_map_reg);
    } else {
        petmem_map_reg = 0;
    }


    if (petres.superpet) {
        /*
         * Initialize SuperPET 6809 memory view.
         * Basically, it is the same as the 6502 view, except for the
         * ROMs in addresses $A000 - $FFFF and but including the I/O range
         * of $E800 - $EFFF.
         */

        for (i = 0x00; i < 0xa0; i++) {
            _mem6809_read_tab[i]      = _mem_read_tab[i];
            _mem6809_write_tab[i]     = _mem_write_tab[i];
            _mem6809_read_base_tab[i] = _mem_read_base_tab[i];
            mem6809_read_limit_tab[i] = mem_read_limit_tab[i];
        }
        /*
         * Set up the ROMs.
         */
        for (i = 0xa0; i < 0xe8; i++) {
            _mem6809_read_tab[i]      = rom6809_read;
            _mem6809_write_tab[i]     = store_void;
            _mem6809_read_base_tab[i] = mem_6809rom + i - (ROM6809_BASE >> 8);
            mem6809_read_limit_tab[i] = 0xe7fc;
        }
        for (i = 0xf0; i < 0x100; i++) {
            _mem6809_read_tab[i]      = rom6809_read;
            _mem6809_write_tab[i]     = store_void;
            _mem6809_read_base_tab[i] = mem_6809rom + i - (ROM6809_BASE >> 8);
            mem6809_read_limit_tab[i] = 0xfffc;
        }
        /*
         * Also copy the I/O setup from the 6502 view.
         */
        for (i = 0xe8; i < 0xf0; i++) {
            _mem6809_read_tab[i]      = _mem_read_tab[i];
            _mem6809_write_tab[i]     = _mem_write_tab[i];
            _mem6809_read_base_tab[i] = _mem_read_base_tab[i];
            mem6809_read_limit_tab[i] = mem_read_limit_tab[i];
        }

        _mem6809_read_tab[0x100] = _mem6809_read_tab[0];
        _mem6809_write_tab[0x100] = _mem6809_write_tab[0];
        _mem6809_read_base_tab[0x100] = _mem6809_read_base_tab[0];
        mem6809_read_limit_tab[0x100] = -1;

        _mem6809_read_tab_ptr = _mem6809_read_tab;
        _mem6809_write_tab_ptr = _mem6809_write_tab;

        for (i = 0; i < 0x101; i++) {
            _mem6809_read_tab_watch[i] = read6809_watch;
            _mem6809_write_tab_watch[i] = store6809_watch;
        }
    }
}

void mem_powerup(void)
{
    ram_init(mem_ram, RAM_ARRAY);

    superpet_powerup();
}

/* ------------------------------------------------------------------------- */

/* FIXME: this does not work for PET 2001.  */

void mem_get_basic_text(WORD *start, WORD *end)
{
    if (start != NULL)
        *start = mem_ram[0x28] | (mem_ram[0x29] << 8);
    if (end != NULL)
        *end = mem_ram[0x2a] | (mem_ram[0x2b] << 8);
}

void mem_set_basic_text(WORD start, WORD end)
{
    mem_ram[0x28] = mem_ram[0xc7] = start & 0xff;
    mem_ram[0x29] = mem_ram[0xc8] = start >> 8;
    mem_ram[0x2a] = mem_ram[0x2c] = mem_ram[0x2e] = mem_ram[0xc9] = end & 0xff;
    mem_ram[0x2b] = mem_ram[0x2d] = mem_ram[0x2f] = mem_ram[0xca] = end >> 8;
}

void mem_inject(DWORD addr, BYTE value)
{
    /* just call mem_store() to be safe.
       This could possibly be changed to write straight into the
       memory array.  mem_ram[addr & mask] = value; */
    mem_store((WORD)(addr & 0xffff), value);
}

/* ------------------------------------------------------------------------- */

int mem_rom_trap_allowed(WORD addr)
{
    return (addr >= 0xf000) && !(petmem_map_reg & 0x80);
}

/* ------------------------------------------------------------------------- */

/* Banked memory access functions for the monitor.  */

static BYTE peek_bank_io(WORD addr)
{
    BYTE v1, v2, v3, v4;

    switch (addr & 0xf0) {
      case 0x10:                /* PIA1 */
        return pia1_peek(addr);
      case 0x20:                /* PIA2 */
        return pia2_peek(addr);
      case 0x40:
        return via_peek(addr);  /* VIA */
      case 0x80:                /* CRTC */
        if (petres.crtc) {
            return crtc_read(addr);
        }
      case 0x00:
        return addr >> 8;
      default:                  /* 0x30, 0x50, 0x60, 0x70, 0x90-0xf0 */
        break;
    }

    if (addr & 0x10)
        v1 = pia1_peek(addr);
    else
        v1 = 0xff;
    if (addr & 0x20)
        v2 = pia2_peek(addr);
    else
        v2 = 0xff;
    if (addr & 0x40)
        v3 = via_peek(addr);
    else
        v3 = 0xff;
    v4 = 0xff;
    if ((addr & 0x80) && petres.crtc) {
        v4 = crtc_read(addr);
    }
    return v1 & v2 & v3 & v4;
}

/* Exported banked memory access functions for the monitor.  */

static const char *banknames[] = {
    "default", "cpu", "ram", "rom", "io", "extram", "6809", NULL
};

enum {
    bank_default, bank_cpu = 0, bank_ram, bank_rom, bank_io, bank_extram,
    bank_cpu6809
};

static const int banknums[] = {
    bank_default, bank_cpu, bank_ram, bank_rom, bank_io, bank_extram,
    bank_cpu6809,
};

const char **mem_bank_list(void)
{
    return banknames;
}

int mem_bank_from_name(const char *name)
{
    int i = 0;

    while (banknames[i]) {
        if (!strcmp(name, banknames[i])) {
            return banknums[i];
        }
        i++;
    }
    return -1;
}

BYTE mem_bank_read(int bank, WORD addr, void *context)
{
    switch (bank) {
      case bank_default:        /* current */
        return mem_read(addr);
        break;
      case bank_extram:         /* extended RAM area (8x96, SuperPET) */
        return mem_ram[addr + 0x10000];
        break;
      case bank_io:            /* io */
        if (addr >= 0xe800 && addr < 0xe900) {
            return read_io(addr);
        }
        if (petres.superpet && (addr & 0xff00) == 0xef00) {
            return read_super_io(addr);
        }
        if (addr >= 0xe900 && addr < 0xe800 + petres.IOSize) {
            return read_unused(addr);
        }
        /* fallthrough to rom */
      case bank_rom:           /* rom */
        if (addr >= 0x9000) {
            return mem_rom[addr & 0x7fff];
        }
      case bank_cpu6809:       /* 6809 */
        return mem6809_read(addr);
      case bank_ram:           /* ram */
        break;
    }
    return mem_ram[addr];
}

BYTE mem_bank_peek(int bank, WORD addr, void *context)
{
    switch (bank) {
      case bank_default:        /* current */
        return mem_read(addr);  /* FIXME */
        break;
      case bank_io:             /* io */
        if (addr >= 0xe800 && addr < 0xe900) {
            return peek_bank_io(addr);
        }
        if (petres.superpet && (addr & 0xff00) == 0xef00) {
            return read_super_io(addr);
        }
        if (addr >= 0xe900 && addr < 0xe800 + petres.IOSize) {
            BYTE result;
            /* is_peek_access = 1; FIXME */
            result = read_unused(addr);
            /* is_peek_access = 0; FIXME */
            return result;
        }
    }
    return mem_bank_read(bank, addr, context);
}

void mem_bank_write(int bank, WORD addr, BYTE byte, void *context)
{
    switch (bank) {
      case bank_default:        /* current */
        mem_store(addr, byte);
        return;
      case bank_extram:         /* extended RAM area (8x96) */
        mem_ram[addr + 0x10000] = byte;
        return;
      case bank_io:             /* io */
        if (addr >= 0xe800 && addr < 0xe900) {
            store_io(addr, byte);
            return;
        }
        if (petres.superpet && (addr & 0xff00) == 0xef00) {
            store_super_io(addr, byte);
            return;
        }
        if (addr >= 0xe900 && addr < 0xe800 + petres.IOSize) {
            store_dummy(addr, byte);
            return;
        }
      case bank_rom:            /* rom */
        if (addr >= 0x9000) {
            return;
        }
      case bank_cpu6809:        /* rom */
        mem6809_store(addr, byte);
        return;
      case 1:                   /* ram */
        break;
    }
    mem_ram[addr] = byte;
}

static int mem_dump_io(WORD addr) {
    if ((addr >= 0xe810) && (addr <= 0xe81f)) {
        return pia1_dump();
    } else if ((addr >= 0xe820) && (addr <= 0xe82f)) {
        return pia2_dump();
    } else if ((addr >= 0xe840) && (addr <= 0xe84f)) {
        return viacore_dump(machine_context.via);
    } else if ((addr >= 0xe880) && (addr <= 0xe881)) {
        if (petres.crtc) {
            return crtc_dump(&crtc);
        }
    } else if ((addr >= 0xeb00) && (addr <= 0xeb0f)) {
        if (petdww_enabled) {
            return petdwwpia_dump();
        }
    } else if (addr == 0xfff0) {
        if (petres.map) {
            return fff0_dump();
        }
    }
    if (petres.superpet) {
        if (addr >= 0xefe0 && addr <= 0xefe3) {
            return efe0_dump();
        } else if (addr >= 0xeff0 && addr <= 0xeff3) {
            // ACIA
        } else if (addr == 0xeff8) {
            // Control switch
            /* return aciacore_dump(); */
            mon_out("CPU: %s\n",
                petres.superpet_cpu_switch == SUPERPET_CPU_6502 ? "6502" :
                petres.superpet_cpu_switch == SUPERPET_CPU_6809 ? "6809" :
                                                            "PROG (unimpl)");
            mon_out("RAM write protect: $%x\n", spet_ramwp);
            mon_out("diagnostic sense: $%x\n", spet_diag);
            return 0;
        } else if (addr == 0xeffc) {
            // Bank select
            mon_out("bank: $%x\n", spet_bank);
            mon_out("control write protect: $%x\n", spet_ctrlwp);
            return 0;
        } else if (addr == 0xeffe) {
            // RAM/ROM switch
            mon_out("ram_enable: %d\n", spet_ramen);
            return 0;
        }
    }
    return -1;
}

mem_ioreg_list_t *mem_ioreg_list_get(void *context)
{
    mem_ioreg_list_t *mem_ioreg_list = NULL;

    mon_ioreg_add_list(&mem_ioreg_list, "PIA1", 0xe810, 0xe81f, mem_dump_io);
    mon_ioreg_add_list(&mem_ioreg_list, "PIA2", 0xe820, 0xe82f, mem_dump_io);
    mon_ioreg_add_list(&mem_ioreg_list, "VIA", 0xe840, 0xe84f, mem_dump_io);
    if (petres.crtc) {
        mon_ioreg_add_list(&mem_ioreg_list, "CRTC", 0xe880, 0xe881, mem_dump_io);
    }
    if (petdww_enabled) {
        mon_ioreg_add_list(&mem_ioreg_list, "DWWPIA", 0xeb00, 0xeb0f, mem_dump_io);
    }
    if (petres.map) {
        mon_ioreg_add_list(&mem_ioreg_list, "8096", 0xfff0, 0xfff0, mem_dump_io);
    }
    if (petres.superpet) {
        mon_ioreg_add_list(&mem_ioreg_list, "6702", 0xefe0, 0xefe3, mem_dump_io);
        mon_ioreg_add_list(&mem_ioreg_list, "ACIA", 0xeff0, 0xeff3, mem_dump_io);
        mon_ioreg_add_list(&mem_ioreg_list, "Control", 0xeff8, 0xeff8, mem_dump_io);
        mon_ioreg_add_list(&mem_ioreg_list, "Bank", 0xeffc, 0xeffc, mem_dump_io);
        mon_ioreg_add_list(&mem_ioreg_list, "RAM/ROM", 0xeffe, 0xeffe, mem_dump_io);
    }

    return mem_ioreg_list;
}

void mem_get_screen_parameter(WORD *base, BYTE *rows, BYTE *columns, int *bank)
{
    int cols;

    resources_get_int("VideoSize", &cols);

    *base = 0x8000;
    *rows = 25;
    *columns = (BYTE)cols;
    *bank = 0;
}

/************************** PET resource handling ************************/

/* check PetInfo struct for consistency after change? */

void petmem_check_info(petres_t *pi)
{
    if (pi->superpet) {
        pi->ramSize = 32;       /* 128 */
        pi->map = 0;
    }

    if (pi->video == 40 || (pi->video == 0 && pi->rom_video == 40)) {
        pi->vmask = 0x3ff;
        pi->videoSize = 0x400;
    } else {
        pi->vmask = 0x7ff;
        pi->videoSize = 0x800;
    }

    if (pi->ramSize == 128) {
        pi->vmask = 0x1fff;
        pi->videoSize = 0x1000;
    }
}

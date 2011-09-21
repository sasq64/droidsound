/*..
 * maincpu.c - Emulation of the main 6510 processor.
 *
 * Written by
 *  Ettore Perazzoli <ettore@comm2000.it>
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

#include "6510core.h"
#include "alarm.h"
#include "clkguard.h"
#include "debug.h"
#include "interrupt.h"
#include "machine.h"
#include "maincpu.h"
#include "mem.h"
#include "monitor.h"
#ifdef C64DTV
#include "mos6510dtv.h"
#else
#include "mos6510.h"
#endif
#include "snapshot.h"
#include "traps.h"
#include "types.h"

unsigned int reg_pc;
static BYTE reg_a = 0;
static BYTE reg_x = 0;
static BYTE reg_y = 0;
static BYTE reg_p = 0;
static BYTE reg_sp = 0;
static BYTE flag_n = 0;
static BYTE flag_z = 0;

static BYTE *bank_base;
static int bank_limit;

/* These are used by our sound driver to fill audio in until enough
 * data has been accumulated. The calculation stops short of 1 frame
 * to avoid overflowing the buffer at any time.  */
short* psid_sound_buf;
int psid_sound_idx;
int psid_sound_max;

/* MACHINE_STUFF should define/undef

 - NEED_REG_PC

 The following are optional:

 - PAGE_ZERO
 - PAGE_ONE
 - STORE_IND
 - LOAD_IND

*/

/* ------------------------------------------------------------------------- */

#define NEED_REG_PC

/* ------------------------------------------------------------------------- */

/* Implement the hack to make opcode fetches faster.  */
#define JUMP(addr)                            \
    do {                                      \
        reg_pc = (unsigned int)(addr);        \
        bank_base = mem_read_base(reg_pc);    \
        bank_limit = mem_read_limit(reg_pc);  \
        mem_old_reg_pc = reg_pc;              \
    } while (0)

/* ------------------------------------------------------------------------- */

#ifndef STORE_ZERO
#define STORE_ZERO(addr, value) \
    (*_mem_write_tab_ptr[0])((WORD)(addr), (BYTE)(value))
#endif

#ifndef LOAD_ZERO
#define LOAD_ZERO(addr) \
    (*_mem_read_tab_ptr[0])((WORD)(addr))
#endif

#ifdef FEATURE_CPUMEMHISTORY
#ifndef C64DTV

/* HACK this is C64 specific */

void memmap_mem_store(unsigned int addr, unsigned int value)
{
    (*_mem_write_tab_ptr[(addr) >> 8])((WORD)(addr), (BYTE)(value));
}

BYTE memmap_mem_read(unsigned int addr)
{
    memmap_state &= ~(MEMMAP_STATE_OPCODE);
    return (*_mem_read_tab_ptr[(addr) >> 8])((WORD)(addr));
}

#ifndef STORE
#define STORE(addr, value) \
    memmap_mem_store(addr, value)
#endif

#ifndef LOAD
#define LOAD(addr) \
    memmap_mem_read(addr)
#endif

#endif /* C64DTV */
#endif /* FEATURE_CPUMEMHISTORY */

#ifndef STORE
#define STORE(addr, value) \
    (*_mem_write_tab_ptr[(addr) >> 8])((WORD)(addr), (BYTE)(value))
#endif

#ifndef LOAD
#define LOAD(addr) \
    (*_mem_read_tab_ptr[(addr) >> 8])((WORD)(addr))
#endif

#define LOAD_ADDR(addr) \
    ((LOAD((addr) + 1) << 8) | LOAD(addr))

#define LOAD_ZERO_ADDR(addr) \
    ((LOAD_ZERO((addr) + 1) << 8) | LOAD_ZERO(addr))

inline static BYTE *mem_read_base(int addr)
{
    BYTE *p = _mem_read_base_tab_ptr[addr >> 8];

    if (p == NULL)
        return p;

    return p - (addr & 0xff00);
}

inline static int mem_read_limit(int addr)
{
    return mem_read_limit_tab_ptr[addr >> 8];
}

/* Those may be overridden by the machine stuff.  Probably we want them in
   the .def files, but if most of the machines do not use, we might keep it
   here and only override it where needed.  */
#ifndef PAGE_ZERO
#define PAGE_ZERO mem_ram
#endif

#ifndef PAGE_ONE
#define PAGE_ONE (mem_ram + 0x100)
#endif

#ifndef STORE_IND
#define STORE_IND(addr, value) STORE((addr),(value))
#endif

#ifndef LOAD_IND
#define LOAD_IND(addr) LOAD((addr))
#endif

#ifndef DMA_FUNC
static void maincpu_generic_dma(void)
{
    /* Generic DMA hosts can be implemented here.
       For example a very accurate REU emulation. */
}
#define DMA_FUNC maincpu_generic_dma()
#endif

#ifndef DMA_ON_RESET
#define DMA_ON_RESET
#endif

#ifndef CPU_ADDITIONAL_RESET
#define CPU_ADDITIONAL_RESET()
#endif

#ifndef CPU_ADDITIONAL_INIT
#define CPU_ADDITIONAL_INIT()
#endif

/* ------------------------------------------------------------------------- */

struct interrupt_cpu_status_s *maincpu_int_status = NULL;
#ifndef CYCLE_EXACT_ALARM
alarm_context_t *maincpu_alarm_context = NULL;
#endif
clk_guard_t *maincpu_clk_guard = NULL;
monitor_interface_t *maincpu_monitor_interface = NULL;

/* Global clock counter.  */
CLOCK maincpu_clk = 0L;

/* This is flag is set to 1 each time a Read-Modify-Write instructions that
   accesses memory is executed.  We can emulate the RMW behaviour of the 6510
   this way.  VERY important notice: Always assign 1 for true, 0 for false!
   Some functions depend on this to do some optimization.  */
int maincpu_rmw_flag = 0;

/* Information about the last executed opcode.  This is used to know the
   number of write cycles in the last executed opcode and to delay interrupts
   by one more cycle if necessary, as happens with conditional branch opcodes
   when the branch is taken.  */
unsigned int last_opcode_info;

/*Address of the last executed opcode. This is used by watchpoints. */
unsigned int last_opcode_addr;

/* Number of write cycles for each 6510 opcode.  */
const CLOCK maincpu_opcode_write_cycles[] = {
            /* 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F */
    /* $00 */  3, 0, 0, 2, 0, 0, 2, 2, 1, 0, 0, 0, 0, 0, 2, 2, /* $00 */
    /* $10 */  0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 2, 2, /* $10 */
    /* $20 */  2, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, /* $20 */
    /* $30 */  0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 2, 2, /* $30 */
    /* $40 */  0, 0, 0, 2, 0, 0, 2, 2, 1, 0, 0, 0, 0, 0, 2, 2, /* $40 */
    /* $50 */  0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 2, 2, /* $50 */
    /* $60 */  0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, /* $60 */
    /* $70 */  0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 2, 2, /* $70 */
    /* $80 */  0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, /* $80 */
    /* $90 */  0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, /* $90 */
    /* $A0 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* $A0 */
    /* $B0 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* $B0 */
    /* $C0 */  0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, /* $C0 */
    /* $D0 */  0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 2, 2, /* $D0 */
    /* $E0 */  0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, /* $E0 */
    /* $F0 */  0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 2, 2  /* $F0 */
            /* 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F */
};

/* Public copy of the CPU registers.  As putting the registers into the
   function makes it faster, you have to generate a `TRAP' interrupt to have
   the values copied into this struct.  */
#ifdef C64DTV
mos6510dtv_regs_t maincpu_regs;
#else
mos6510_regs_t maincpu_regs;
#endif

/* ------------------------------------------------------------------------- */

monitor_interface_t *maincpu_monitor_interface_get(void)
{
#ifdef C64DTV
    maincpu_monitor_interface->cpu_regs = NULL;
    maincpu_monitor_interface->dtv_cpu_regs = &maincpu_regs;
#else
    maincpu_monitor_interface->cpu_regs = &maincpu_regs;
    maincpu_monitor_interface->dtv_cpu_regs = NULL;
#endif

#ifdef HAVE_Z80_REGS
    maincpu_monitor_interface->z80_cpu_regs = &z80_regs;
#else
    maincpu_monitor_interface->z80_cpu_regs = NULL;
#endif

    maincpu_monitor_interface->int_status = maincpu_int_status;

    maincpu_monitor_interface->clk = &maincpu_clk;

    maincpu_monitor_interface->current_bank = 0;
    maincpu_monitor_interface->mem_bank_list = mem_bank_list;
    maincpu_monitor_interface->mem_bank_from_name = mem_bank_from_name;
    maincpu_monitor_interface->mem_bank_read = mem_bank_read;
    maincpu_monitor_interface->mem_bank_peek = mem_bank_peek;
    maincpu_monitor_interface->mem_bank_write = mem_bank_write;

    maincpu_monitor_interface->mem_ioreg_list_get = mem_ioreg_list_get;

    maincpu_monitor_interface->toggle_watchpoints_func = mem_toggle_watchpoints;

    maincpu_monitor_interface->set_bank_base = NULL;
    maincpu_monitor_interface->get_line_cycle = machine_get_line_cycle;

    return maincpu_monitor_interface;
}

/* ------------------------------------------------------------------------- */

void maincpu_early_init(void)
{
    maincpu_int_status = interrupt_cpu_status_new();
}

void maincpu_init(void)
{
    interrupt_cpu_status_init(maincpu_int_status, &last_opcode_info);

    /* cpu specifix additional init routine */
    CPU_ADDITIONAL_INIT();
}

void maincpu_shutdown(void)
{
    interrupt_cpu_status_destroy(maincpu_int_status);
}

static void cpu_reset(void)
{
    int preserve_monitor;

    preserve_monitor = maincpu_int_status->global_pending_int & IK_MONITOR;

    interrupt_cpu_status_reset(maincpu_int_status);

    if (preserve_monitor)
        interrupt_monitor_trap_on(maincpu_int_status);

    maincpu_clk = 6; /* # of clock cycles needed for RESET.  */

    /* CPU specific extra reset routine, currently only used
       for 8502 fast mode refresh cycle. */
    CPU_ADDITIONAL_RESET();

    /* Do machine-specific initialization.  */
    machine_reset();
}

void maincpu_reset(void)
{
    cpu_reset();
}

/* ------------------------------------------------------------------------- */

/* Return nonzero if a pending NMI should be dispatched now.  This takes
   account for the internal delays of the 6510, but does not actually check
   the status of the NMI line.  */
inline static int interrupt_check_nmi_delay(interrupt_cpu_status_t *cs,
                                            CLOCK cpu_clk)
{
    CLOCK nmi_clk = cs->nmi_clk + INTERRUPT_DELAY;

    /* Branch instructions delay IRQs and NMI by one cycle if branch
       is taken with no page boundary crossing.  */
    if (OPINFO_DELAYS_INTERRUPT(*cs->last_opcode_info_ptr))
        nmi_clk++;

    if (cpu_clk >= nmi_clk)
        return 1;

    return 0;
}

/* Return nonzero if a pending IRQ should be dispatched now.  This takes
   account for the internal delays of the 6510, but does not actually check
   the status of the IRQ line.  */
inline static int interrupt_check_irq_delay(interrupt_cpu_status_t *cs,
                                            CLOCK cpu_clk)
{
    CLOCK irq_clk = cs->irq_clk + INTERRUPT_DELAY;

    /* Branch instructions delay IRQs and NMI by one cycle if branch
       is taken with no page boundary crossing.  */
    if (OPINFO_DELAYS_INTERRUPT(*cs->last_opcode_info_ptr))
        irq_clk++;

    /* If an opcode changes the I flag from 1 to 0, the 6510 needs
       one more opcode before it triggers the IRQ routine.  */
    if (cpu_clk >= irq_clk) {
        if (!OPINFO_ENABLES_IRQ(*cs->last_opcode_info_ptr)) {
            return 1;
        } else {
            cs->global_pending_int |= IK_IRQPEND;
        }
    }
    return 0;
}

/* ------------------------------------------------------------------------- */
void psid_play(short *buf, int n)
{
    psid_sound_buf = buf;
    psid_sound_idx = 0;
    psid_sound_max = n;
    while (psid_sound_idx != psid_sound_max) {
#define CLK maincpu_clk
#define RMW_FLAG maincpu_rmw_flag
#define LAST_OPCODE_INFO last_opcode_info
#define LAST_OPCODE_ADDR last_opcode_addr
#define TRACEFLG debug.maincpu_traceflg

#define CPU_INT_STATUS maincpu_int_status

#define ALARM_CONTEXT maincpu_alarm_context

#define CHECK_PENDING_ALARM() \
   (clk >= next_alarm_clk(maincpu_int_status))

#define CHECK_PENDING_INTERRUPT() \
   check_pending_interrupt(maincpu_int_status)

#define TRAP(addr) \
   maincpu_int_status->trap_func(addr);

#define ROM_TRAP_HANDLER() \
   traps_handler()

#define JAM()                                                         \
    do {                                                              \
        unsigned int tmp;                                             \
                                                                      \
        EXPORT_REGISTERS();                                           \
        tmp = machine_jam("   " CPU_STR ": JAM at $%04X   ", reg_pc); \
        switch (tmp) {                                                \
          case JAM_RESET:                                             \
            DO_INTERRUPT(IK_RESET);                                   \
            break;                                                    \
          case JAM_HARD_RESET:                                        \
            mem_powerup();                                            \
            DO_INTERRUPT(IK_RESET);                                   \
            break;                                                    \
          case JAM_MONITOR:                                           \
            caller_space = e_comp_space;                              \
            monitor_startup();                                        \
            IMPORT_REGISTERS();                                       \
            break;                                                    \
          default:                                                    \
            CLK++;                                                    \
        }                                                             \
    } while (0)

#define CALLER e_comp_space
#define ROM_TRAP_ALLOWED() mem_rom_trap_allowed((WORD)reg_pc)

#define GLOBAL_REGS maincpu_regs

#include "6510core.c"

         maincpu_int_status->num_dma_per_opcode = 0;
    }
}

/* ------------------------------------------------------------------------- */

int maincpu_snapshot_write_module(snapshot_t *s)
{
    return 0;
}

int maincpu_snapshot_read_module(snapshot_t *s)
{
    return 0;
}

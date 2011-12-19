#include "vice.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "c64cart.h"
#include "c64mem.h"
#include "c64cartmem.h"
#define CARTRIDGE_INCLUDE_SLOTMAIN_API
#include "c64cartsystem.h"
#undef CARTRIDGE_INCLUDE_SLOTMAIN_API
#include "cartridge.h"
#include "cartio.h"
#include "crt.h"
#include "log.h"
#include "machine.h"
#include "maincpu.h"
#include "resources.h"
#include "types.h"
#include "vicii-phi1.h"

/* FIXME: test and then remove all the old code */
#define USESLOTS /* define to use passthrough code */

#ifdef DEBUGCART
#define DBG(x)  printf x ; fflush(stdout);
#else
#define DBG(x)
#endif

BYTE romh_fake[0x2000];

/* Expansion port signals.  */
export_t export = { 0, 0, 0, 0 }; /* c64 export */
export_t export_slot1 = { 0, 0, 0, 0 };
export_t export_slotmain = { 0, 0, 0, 0 };
export_t export_passthrough = { 0, 0, 0, 0 }; /* slot1 and main combined, goes into slot0 passthrough or c64 export */

/* from c64cart.c */
extern int mem_cartridge_type; /* Type of the cartridge attached. ("Main Slot") */

/*
  mode_phiN:

  bits N..2: bank (currently max 0x3f)

  bits 1,0: !exrom, game

  mode_phiN & 3 = 0 : roml
  mode_phiN & 3 = 1 : roml & romh
  mode_phiN & 3 = 2 : ram
  mode_phiN & 3 = 3 : ultimax

  wflag:

  bit 4  0x10   - trigger nmi after config changed
  bit 3  0x08   - export ram enabled
  bit 2  0x04   - vic phi2 mode (always sees ram if set)
  bit 1  0x02   - release freeze (stop asserting NMI)
  bit 0  0x01   - r/w flag
*/

#ifndef USESLOTS
static void cart_config_changed(int slot, BYTE mode_phi1, BYTE mode_phi2, unsigned int wflag)
{
#ifdef DEBUGCART
    static int old1 = 0, old2 = 0, old3 = 0;
    if ((mode_phi1 != old1) || (mode_phi2 != old2) || (wflag != old3)) {
        DBG(("CARTMEM: cart_config_changed slot %d phi1:%d phi2:%d bank: %d flags:%02x\n", slot,mode_phi1 & 3, mode_phi2 & 3, (mode_phi2 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK, wflag));
    }
    old1 = mode_phi1; old2 = mode_phi2; old3 = wflag;
#endif

    if ((wflag & CMODE_WRITE) == CMODE_WRITE) {
        machine_handle_pending_alarms(maincpu_rmw_flag + 1);
    } else {
        machine_handle_pending_alarms(0);
    }

    export.game = mode_phi2 & 1;
    export.exrom = ((mode_phi2 >> 1) & 1) ^ 1;

    if (slot == 2) {
        cart_romhbank_set_slotmain((mode_phi2 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK);
        cart_romlbank_set_slotmain((mode_phi2 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK);
        export_ram = (wflag >> CMODE_EXPORT_RAM_SHIFT) & 1;
    }

    mem_pla_config_changed();
    if ((wflag & CMODE_RELEASE_FREEZE) == CMODE_RELEASE_FREEZE) {
    }
    export.ultimax_phi1 = (mode_phi1 & 1) & ((mode_phi1 >> 1) & 1);
    export.ultimax_phi2 = export.game & (export.exrom ^ 1) & ((~wflag >> CMODE_PHI2_RAM_SHIFT) & 1);

    /* TODO
    if (slot == 2) {
        cart_romhbank_phi1_set_slotmain((mode_phi1 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK);
        cart_romlbank_phi1_set_slotmain((mode_phi1 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK);
    }
    */

    machine_update_memory_ptrs();

    if ((wflag & CMODE_TRIGGER_FREEZE_NMI_ONLY) == CMODE_TRIGGER_FREEZE_NMI_ONLY) {
    }
}
#endif

void cart_set_port_exrom_slot0(int n)
{
    export.exrom = n;
}

void cart_set_port_game_slot0(int n)
{
    export.game = n;
}

void cart_port_config_changed_slot0(void)
{
    mem_pla_config_changed();
}

void cart_config_changed_slot0(BYTE mode_phi1, BYTE mode_phi2, unsigned int wflag)
{
    assert(((mode_phi2 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK) == 0);
    assert((wflag & CMODE_RELEASE_FREEZE) == 0);
    assert((wflag & CMODE_TRIGGER_FREEZE_NMI_ONLY) == 0);
    assert((wflag & CMODE_PHI2_RAM) == 0);
    assert((wflag & CMODE_EXPORT_RAM) == 0);

#ifndef USESLOTS
    cart_config_changed(0, mode_phi1, mode_phi2, wflag);
#else

    if ((wflag & CMODE_WRITE) == CMODE_WRITE) {
        machine_handle_pending_alarms(maincpu_rmw_flag + 1);
    } else {
        machine_handle_pending_alarms(0);
    }

    export.game = mode_phi2 & 1;
    export.exrom = ((mode_phi2 >> 1) & 1) ^ 1;
    export.ultimax_phi1 = (mode_phi1 & 1) & ((mode_phi1 >> 1) & 1);
    export.ultimax_phi2 = (mode_phi2 & 1) & ((mode_phi2 >> 1) & 1);

    mem_pla_config_changed();
    machine_update_memory_ptrs();

#endif
}

#ifdef USESLOTS
void cart_passthrough_changed(void)
{
    export_passthrough.game = 0;
    export_passthrough.exrom = 0;
    export_passthrough.ultimax_phi1 = 0;
    export_passthrough.ultimax_phi2 = 0;

    export.game = export_passthrough.game;
    export.exrom = export_passthrough.exrom;
    export.ultimax_phi1 = export_passthrough.ultimax_phi1;
    export.ultimax_phi2 = export_passthrough.ultimax_phi2;
}
#endif

void cart_set_port_exrom_slot1(int n)
{
#ifndef USESLOTS
    export.exrom = n;
#else
    export_slot1.exrom = n;
    cart_passthrough_changed();
#endif
}

void cart_set_port_game_slot1(int n)
{
#ifndef USESLOTS
    export.game = n;
#else
    export_slot1.game = n;
    cart_passthrough_changed();
#endif
}

void cart_port_config_changed_slot1(void)
{
    mem_pla_config_changed();
}

void cart_config_changed_slot1(BYTE mode_phi1, BYTE mode_phi2, unsigned int wflag)
{
    assert(((mode_phi2 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK) == 0);
    assert(((wflag >> CMODE_EXPORT_RAM_SHIFT) & 1) == 0);
#ifndef USESLOTS
    cart_config_changed(1, mode_phi1, mode_phi2, wflag);
#else

#ifdef DEBUGCART
    static int old1 = 0, old2 = 0, old3 = 0;
    if ((mode_phi1 != old1) || (mode_phi2 != old2) || (wflag != old3)) {
        DBG(("CARTMEM: cart_config_changed_slot1 phi1:%d phi2:%d bank: %d flags:%02x\n",mode_phi1 & 3, mode_phi2 & 3, (mode_phi2 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK, wflag));
    }
    old1 = mode_phi1; old2 = mode_phi2; old3 = wflag;
#endif

    if ((wflag & CMODE_WRITE) == CMODE_WRITE) {
        machine_handle_pending_alarms(maincpu_rmw_flag + 1);
    } else {
        machine_handle_pending_alarms(0);
    }

    export_slot1.game = mode_phi2 & 1;
    export_slot1.exrom = ((mode_phi2 >> 1) & 1) ^ 1;

    export_slot1.ultimax_phi1 = (mode_phi1 & 1) & ((mode_phi1 >> 1) & 1);
    export_slot1.ultimax_phi2 = export_slot1.game & (export_slot1.exrom ^ 1) & ((~wflag >> CMODE_PHI2_RAM_SHIFT) & 1);

    cart_passthrough_changed();
    mem_pla_config_changed();

    if ((wflag & CMODE_RELEASE_FREEZE) == CMODE_RELEASE_FREEZE) {
    }
    machine_update_memory_ptrs();

    if ((wflag & CMODE_TRIGGER_FREEZE_NMI_ONLY) == CMODE_TRIGGER_FREEZE_NMI_ONLY) {
    }

#endif
}

void cart_set_port_exrom_slotmain(int n)
{
#ifndef USESLOTS
    export.exrom = n;
#else
    export_slotmain.exrom = n;
    cart_passthrough_changed();
#endif
}

void cart_set_port_game_slotmain(int n)
{
#ifndef USESLOTS
    export.game = n;
#else
    export_slotmain.game = n;
    cart_passthrough_changed();
#endif
}

void cart_set_port_phi1_slotmain(int n)
{
#ifndef USESLOTS
    export.ultimax_phi1 = n;
#else
    export_slotmain.ultimax_phi1 = n;
    cart_passthrough_changed();
#endif
}

void cart_set_port_phi2_slotmain(int n)
{
#ifndef USESLOTS
    export.ultimax_phi2 = n;
#else
    export_slotmain.ultimax_phi2 = n;
    cart_passthrough_changed();
#endif
}

void cart_port_config_changed_slotmain(void)
{
    mem_pla_config_changed();
}

void cart_config_changed_slotmain(BYTE mode_phi1, BYTE mode_phi2, unsigned int wflag)
{
#ifndef USESLOTS
    cart_config_changed(2, mode_phi1, mode_phi2, wflag);
#else

#ifdef DEBUGCART
    static int old1 = 0, old2 = 0, old3 = 0;
    if ((mode_phi1 != old1) || (mode_phi2 != old2) || (wflag != old3)) {
        DBG(("CARTMEM: cart_config_changed_slotmain phi1:%d phi2:%d bank: %d flags:%02x\n",mode_phi1 & 3, mode_phi2 & 3, (mode_phi2 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK, wflag));
    }
    old1 = mode_phi1; old2 = mode_phi2; old3 = wflag;
#endif

    if ((wflag & CMODE_WRITE) == CMODE_WRITE) {
        machine_handle_pending_alarms(maincpu_rmw_flag + 1);
    } else {
        machine_handle_pending_alarms(0);
    }

    export_slotmain.game = mode_phi2 & 1;
    export_slotmain.exrom = ((mode_phi2 >> 1) & 1) ^ 1;

    export_slotmain.ultimax_phi1 = (mode_phi1 & 1) & ((mode_phi1 >> 1) & 1);
    export_slotmain.ultimax_phi2 = export_slotmain.game & (export_slotmain.exrom ^ 1) & ((~wflag >> CMODE_PHI2_RAM_SHIFT) & 1);

    /* TODO
    cart_romhbank_phi1_set_slotmain((mode_phi1 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK);
    cart_romlbank_phi1_set_slotmain((mode_phi1 >> CMODE_BANK_SHIFT) & CMODE_BANK_MASK);
    */

    cart_passthrough_changed();
    mem_pla_config_changed();

    if ((wflag & CMODE_RELEASE_FREEZE) == CMODE_RELEASE_FREEZE) {
    }
    machine_update_memory_ptrs();

    if ((wflag & CMODE_TRIGGER_FREEZE_NMI_ONLY) == CMODE_TRIGGER_FREEZE_NMI_ONLY) {
    }

#endif
}

/* ROML read - mapped to 8000 in 8k,16k,ultimax */
static BYTE REGPARM1 roml_read_slot1(WORD addr)
{
    return vicii_read_phi1();
}

/* ROML read - mapped to 8000 in 8k,16k,ultimax */
BYTE REGPARM1 roml_read(WORD addr)
{
    return roml_read_slot1(addr);
}

/* ROML store - mapped to 8000 in ultimax mode */
void REGPARM2 roml_store(WORD addr, BYTE value)
{
}

static BYTE REGPARM1 romh_read_slot1(WORD addr)
{
    return vicii_read_phi1();
}

BYTE REGPARM1 romh_read(WORD addr)
{
    return romh_read_slot1(addr);
}

BYTE REGPARM1 ultimax_romh_read_hirom_slot1(WORD addr)
{
    return vicii_read_phi1();
}

BYTE REGPARM1 ultimax_romh_read_hirom(WORD addr)
{
    return ultimax_romh_read_hirom_slot1(addr);
}

/* ROMH store - mapped to E000 in ultimax mode
   - carts that use "external kernal" mode must wrap to ram_store here
*/
void REGPARM2 romh_store(WORD addr, BYTE value)
{
}

/* ROMH store - A000-BFFF in 16kGame

   normally writes to ROM area would go to RAM an not generate
   a write select. some carts however map RAM here and also
   accept writes in this mode.
*/
void REGPARM2 romh_no_ultimax_store(WORD addr, BYTE value)
{
    mem_store_without_romlh(addr, value);
}

/* ROML store - mapped to 8000-9fff in 8kGame, 16kGame

   normally writes to ROM area would go to RAM and not generate
   a write select. some carts however map ram here and also
   accept writes in this mode.
*/
void REGPARM2 roml_no_ultimax_store(WORD addr, BYTE value)
{
    ram_store(addr, value);
}

/* RAML store (ROML _NOT_ selected) - mapped to 8000-9fff in 8kGame, 16kGame

   WARNING:
      mem_store_without_ultimax(addr, value)
      must NOT be called by any functions called here, as this will cause an
      endless loop
*/
void REGPARM2 raml_no_ultimax_store(WORD addr, BYTE value)
{
    ram_store(addr, value);
}

/* ultimax read - 1000 to 7fff */
BYTE REGPARM1 ultimax_1000_7fff_read_slot1(WORD addr)
{
    return vicii_read_phi1();
}

BYTE REGPARM1 ultimax_1000_7fff_read(WORD addr)
{
    return ultimax_1000_7fff_read_slot1(addr);
}

/* ultimax store - 1000 to 7fff */
void REGPARM2 ultimax_1000_7fff_store(WORD addr, BYTE value)
{
}

/* ultimax read - a000 to bfff */
BYTE REGPARM1 ultimax_a000_bfff_read_slot1(WORD addr)
{
    return vicii_read_phi1();
}

BYTE REGPARM1 ultimax_a000_bfff_read(WORD addr)
{
    return ultimax_a000_bfff_read_slot1(addr);
}

/* ultimax store - a000 to bfff */
void REGPARM2 ultimax_a000_bfff_store(WORD addr, BYTE value)
{
    /* default; no cart, open bus */
}

/* ultimax read - c000 to cfff */
BYTE REGPARM1 ultimax_c000_cfff_read_slot1(WORD addr)
{
    return vicii_read_phi1();
}

BYTE REGPARM1 ultimax_c000_cfff_read(WORD addr)
{
    return ultimax_c000_cfff_read_slot1(addr);
}

/* ultimax store - c000 to cfff */
void REGPARM2 ultimax_c000_cfff_store(WORD addr, BYTE value)
{
}

/* ultimax read - d000 to dfff */
static BYTE REGPARM1 ultimax_d000_dfff_read_slot1(WORD addr)
{
    return read_bank_io(addr);
}

BYTE REGPARM1 ultimax_d000_dfff_read(WORD addr)
{
    return ultimax_d000_dfff_read_slot1(addr);
}

/* ultimax store - d000 to dfff */
void REGPARM2 ultimax_d000_dfff_store(WORD addr, BYTE value)
{
    store_bank_io(addr, value);
}

static int ultimax_romh_phi1_read_slot1(WORD addr, BYTE *value)
{
    *value = ultimax_romh_read_hirom(addr);
    return 1;
}

int ultimax_romh_phi1_read(WORD addr, BYTE *value)
{
    return ultimax_romh_phi1_read_slot1(addr, value);
}

static int ultimax_romh_phi2_read_slot1(WORD addr, BYTE *value)
{
    *value = ultimax_romh_read_hirom(addr);
    return 1;
}

int ultimax_romh_phi2_read(WORD addr, BYTE *value)
{
    return ultimax_romh_phi2_read_slot1(addr, value);
}

static BYTE cartridge_peek_mem_slot1(WORD addr)
{
    return ram_read(addr);
}

BYTE *ultimax_romh_phi1_ptr(WORD addr)
{
     return romh_fake;
}

BYTE *ultimax_romh_phi2_ptr(WORD addr)
{
     return romh_fake;
}

BYTE cartridge_peek_mem(WORD addr)
{
    return cartridge_peek_mem_slot1(addr);
}



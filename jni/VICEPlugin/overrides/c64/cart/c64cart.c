/*
 * c64cart.c - C64 cartridge emulation.
 *
 * Written by
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
#include <stdlib.h>
#include <string.h>

#include "alarm.h"
#include "archdep.h"
#include "c64.h"
#include "c64cart.h"
#define CARTRIDGE_INCLUDE_SLOTMAIN_API
#include "c64cartsystem.h"
#undef CARTRIDGE_INCLUDE_SLOTMAIN_API
#include "c64export.h"
#include "cartridge.h"
#include "cmdline.h"
#include "crt.h"
#include "interrupt.h"
#include "lib.h"
#include "log.h"
#include "machine.h"
#include "maincpu.h"
#include "mem.h"
#include "monitor.h"
#include "resources.h"
#include "translate.h"
#include "util.h"

/* #define DEBUGCART */

#ifdef DEBUGCART
#define DBG(x)  printf x ; fflush(stdout);
#else
#define DBG(x)
#endif

int cartridge_resources_init(void)
{
    return 0;
}

void cartridge_resources_shutdown(void)
{
}

/* ---------------------------------------------------------------------*/
int cart_attach_cmdline(const char *param, void *extra_param)
{
    return 0;
}

int cartridge_cmdline_options_init(void)
{
    return 0;
}

/* ------------------------------------------------------------------------- */

/*
    returns ID of cart in "Main Slot"
*/
int cart_getid_slotmain(void)
{
    return CARTRIDGE_NONE;
}

/* ---------------------------------------------------------------------*/

/*
    get filename of cart with given type
*/
const char *cartridge_get_file_name(int type)
{
    return NULL;
}

/*
    returns 1 if the cartridge of the given type is enabled

    - used by c64iec.c:iec_available_busses
*/
int cartridge_type_enabled(int type)
{
    return 0;
}

/*
    attach cartridge image

    type == -1  NONE
    type ==  0  CRT format

    returns -1 on error, 0 on success
*/
int cartridge_attach_image(int type, const char *filename)
{
    return -1;
}

void cart_power_off(void)
{
}

/*
    Attach cartridge from snapshot

    Sets static variables related to the "Main Slot".
    This is needed for cart_getid_slotmain to return a proper
    value for cart_freeze and such.
*/
void cart_attach_from_snapshot(int type)
{
}

/*
    detach cartridge from "Main Slot"
*/
void cart_detach_slotmain(void)
{
}

/*
    detach a cartridge.
    - carts that are not "main" cartridges can be disabled individually
    - if type is -1, then all carts will get detached
    - if type is 0, then cart in main slot will get detached

    - carts not in "Main Slot" must make sure their detach hook does not
      fail when it is called and the cart is not actually attached.
*/
void cartridge_detach_image(int type)
{
}

/*
    set currently active cart in "Main Slot" as default
*/
void cartridge_set_default(void)
{
}

int cartridge_save_image(int type, const char *filename)
{
    return 0;
}

/* trigger a freeze, but don't trigger the cartridge logic (which might release it). used by monitor */
void cartridge_trigger_freeze_nmi_only(void)
{
}

/* called by individual carts */
void cartridge_release_freeze(void)
{
}

/* called from individual carts */
void cart_trigger_nmi(void)
{
}

void cartridge_trigger_freeze(void)
{
}

void cart_unset_alarms(void)
{
}

void cart_undump_alarms(void)
{
}

/* called by c64.c:machine_specific_init */
void cartridge_init(void)
{
}


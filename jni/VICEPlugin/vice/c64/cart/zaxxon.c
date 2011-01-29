/*
 * zaxxon.c - Cartridge handling, Zaxxon cart.
 *
 * Written by
 *  Andreas Boose <viceteam@t-online.de>
 *  Markus Brenner <markus@brenner.de>
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

#define CARTRIDGE_INCLUDE_SLOTMAIN_API
#include "c64cartsystem.h"
#undef CARTRIDGE_INCLUDE_SLOTMAIN_API
#include "c64export.h"
#include "cartridge.h"
#include "snapshot.h"
#include "types.h"
#include "util.h"
#include "zaxxon.h"

/*
    this cart uses 4Kb mapped in at $8000-$8FFF and mirrored at $9000-$9FFF
    and 2 banks of 8Kb mapped in at $A000-$BFFF.

    the banks at $A000-$BFFF are selected by a read access to either
    $8000-$8FFF (select bank 1 in $A000-$BFFF) or $9000-$9FFF (select bank 2
    at $A000-$BFFF)
 */

static const c64export_resource_t export_res = {
    CARTRIDGE_NAME_ZAXXON, 1, 1, NULL, NULL, CARTRIDGE_ZAXXON
};

BYTE zaxxon_roml_read(WORD addr)
{
    cart_romhbank_set_slotmain((addr & 0x1000) ? 1 : 0);
    return roml_banks[(addr & 0x1fff) + (roml_bank << 13)];
}

void zaxxon_config_init(void)
{
    cart_config_changed_slotmain(1, 1, CMODE_READ);
}

void zaxxon_config_setup(BYTE *rawcart)
{
    memcpy(roml_banks, rawcart, 0x2000);
    memcpy(romh_banks, &rawcart[0x2000], 0x4000);
    cart_config_changed_slotmain(1, 1, CMODE_READ);
}

static int zaxxon_common_attach(void)
{
    if (c64export_add(&export_res) < 0) {
        return -1;
    }

    return 0;
}

/* accept 20k (4k+16k) and 24k (8k+16k) binaries */
int zaxxon_bin_attach(const char *filename, BYTE *rawcart)
{
    if (util_file_load(filename, rawcart, 0x6000, UTIL_FILE_LOAD_SKIP_ADDRESS) < 0) {
        if (util_file_load(filename, rawcart, 0x5000, UTIL_FILE_LOAD_SKIP_ADDRESS) < 0) {
            return -1;
        }
        memmove(&rawcart[0x1000], &rawcart[0x0000], 0x5000);
    }
    return zaxxon_common_attach();
}

int zaxxon_crt_attach(FILE *fd, BYTE *rawcart)
{
    BYTE chipheader[0x10];
    int i;

    /* first CHIP header holds $8000-$a000 data */
    if (fread(chipheader, 0x10, 1, fd) < 1) {
        return -1;
    }

    if (chipheader[0xc] != 0x80 || (chipheader[0xe] != 0x10 && chipheader[0xe] != 0x20) || fread(rawcart, chipheader[0xe] << 8, 1, fd) < 1) {
        return -1;
    }

    /* 4kB ROM is mirrored to $9000 */
    if (chipheader[0xe] == 0x10) {
        memcpy(&rawcart[0x1000], &rawcart[0x0000], 0x1000);
    }

    /* second/third CHIP headers hold $a000-$c000 banked data */
    for (i = 0; i <= 1; i++) {
        if (fread(chipheader, 0x10, 1, fd) < 1) {
            return -1;
        }

        if (chipheader[0xc] != 0xa0 || chipheader[0xe] != 0x20 || fread(&rawcart[0x2000+(chipheader[0xb] << 13)], 0x2000, 1, fd) < 1) {
            return -1;
        }
    }

    return zaxxon_common_attach();
}

void zaxxon_detach(void)
{
    c64export_remove(&export_res);
}

/* ---------------------------------------------------------------------*/

#define CART_DUMP_VER_MAJOR   0
#define CART_DUMP_VER_MINOR   0
#define SNAP_MODULE_NAME  "CARTZAXXON"

int zaxxon_snapshot_write_module(snapshot_t *s)
{
    snapshot_module_t *m;

    m = snapshot_module_create(s, SNAP_MODULE_NAME,
                          CART_DUMP_VER_MAJOR, CART_DUMP_VER_MINOR);
    if (m == NULL) {
        return -1;
    }

    if (0
        || (SMW_BA(m, roml_banks, 0x2000) < 0)
        || (SMW_BA(m, romh_banks, 0x4000) < 0)) {
        snapshot_module_close(m);
        return -1;
    }

    snapshot_module_close(m);
    return 0;
}

int zaxxon_snapshot_read_module(snapshot_t *s)
{
    BYTE vmajor, vminor;
    snapshot_module_t *m;

    m = snapshot_module_open(s, SNAP_MODULE_NAME, &vmajor, &vminor);
    if (m == NULL) {
        return -1;
    }

    if ((vmajor != CART_DUMP_VER_MAJOR) || (vminor != CART_DUMP_VER_MINOR)) {
        snapshot_module_close(m);
        return -1;
    }

    if (0
        || (SMR_BA(m, roml_banks, 0x2000) < 0)
        || (SMR_BA(m, romh_banks, 0x4000) < 0)) {
        snapshot_module_close(m);
        return -1;
    }

    snapshot_module_close(m);

    return zaxxon_common_attach();
}

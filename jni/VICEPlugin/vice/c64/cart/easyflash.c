/*
 * easyflash.c - Cartridge handling of the easyflash cart.
 *
 * Written by
 *  ALeX Kazik <alx@kazik.de>
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
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

#include "archdep.h"
#define CARTRIDGE_INCLUDE_SLOTMAIN_API
#include "c64cartsystem.h"
#undef CARTRIDGE_INCLUDE_SLOTMAIN_API
#include "c64export.h"
#include "c64io.h"
#include "c64mem.h"
#include "cartridge.h"
#include "cmdline.h"
#include "crt.h"
#include "easyflash.h"
#include "flash040.h"
#include "lib.h"
#include "log.h"
#include "maincpu.h"
#include "mem.h"
#include "monitor.h"
#include "resources.h"
#include "snapshot.h"
#include "translate.h"

#define EASYFLASH_N_BANK_BITS 6
#define EASYFLASH_N_BANKS     (1 << (EASYFLASH_N_BANK_BITS))
#define EASYFLASH_BANK_MASK   ((EASYFLASH_N_BANKS) - 1)

/* the 29F040B statemachine */
static flash040_context_t *easyflash_state_low = NULL;
static flash040_context_t *easyflash_state_high = NULL;

/* the jumper */
static int easyflash_jumper;

/* writing back to crt enabled */
static int easyflash_crt_write;

/* backup of the registers */
static BYTE easyflash_register_00, easyflash_register_02;

/* decoding table of the modes */
static const BYTE easyflash_memconfig[] = {
       /* bit3 = jumper, bit2 = mode, bit1 = !exrom, bit0 = game */

       /* jumper off, mode 0, trough 00,01,10,11 in game/exrom bits */
    3, /* exrom high, game low, jumper off */
    3, /* Reserved, don't use this */
    1, /* exrom low, game low, jumper off */
    1, /* Reserved, don't use this */

       /* jumper off, mode 1, trough 00,01,10,11 in game/exrom bits */
    2, 3, 0, 1,

       /* jumper on, mode 0, trough 00,01,10,11 in game/exrom bits */
    2, /* exrom high, game low, jumper on */
    3, /* Reserved, don't use this */
    0, /* exrom low, game low, jumper on */
    1, /* Reserved, don't use this */

       /* jumper on, mode 1, trough 00,01,10,11 in game/exrom bits */
    2, 3, 0, 1,
};

/* extra RAM */
static BYTE easyflash_ram[256];

/* filename when attached */
static char *easyflash_filename = NULL;
static int easyflash_filetype = 0;

static const char STRING_EASYFLASH[] = CARTRIDGE_NAME_EASYFLASH;

/* ---------------------------------------------------------------------*/

static void easyflash_io1_store(WORD addr, BYTE value)
{
    BYTE mem_mode;

    switch (addr & 2) {
        case 0:
            /* bank register */
            easyflash_register_00 = (BYTE)(value & EASYFLASH_BANK_MASK);
            break;
        default:
            /* mode register */
            easyflash_register_02 = value & 0x87; /* we only remember led, mode, exrom, game */
            mem_mode = easyflash_memconfig[(easyflash_jumper << 3) | (easyflash_register_02 & 0x07)];
            cart_config_changed_slotmain(mem_mode, mem_mode, CMODE_READ);
            /* TODO: change led */
            /* (value & 0x80) -> led on if true, led off if false */
    }
    cart_romhbank_set_slotmain(easyflash_register_00);
    cart_romlbank_set_slotmain(easyflash_register_00);
    cart_port_config_changed_slotmain();
}

static BYTE easyflash_io2_read(WORD addr)
{
    return easyflash_ram[addr & 0xff];
}

static void easyflash_io2_store(WORD addr, BYTE value)
{
    easyflash_ram[addr & 0xff] = value;
}

/* ---------------------------------------------------------------------*/

static BYTE easyflash_io1_peek(WORD addr)
{
    return (addr & 2) ? easyflash_register_02 : easyflash_register_00;
}

static int easyflash_io1_dump(void)
{
    mon_out("Mode %i, LED %s, jumper %s\n",
        easyflash_memconfig[(easyflash_jumper << 3) | (easyflash_register_02 & 0x07)],
        (easyflash_register_02 & 0x80) ? "on" : "off",
        easyflash_jumper ? "on" : "off");
    return 0;
}

/* ---------------------------------------------------------------------*/

static io_source_t easyflash_io1_device = {
    CARTRIDGE_NAME_EASYFLASH,
    IO_DETACH_CART,
    NULL,
    0xde00, 0xdeff, 0x03,
    0,
    easyflash_io1_store,
    NULL,
    easyflash_io1_peek,
    easyflash_io1_dump,
    CARTRIDGE_EASYFLASH,
    0
};

static io_source_t easyflash_io2_device = {
    CARTRIDGE_NAME_EASYFLASH,
    IO_DETACH_CART,
    NULL,
    0xdf00, 0xdfff, 0xff,
    1, /* read is always valid */
    easyflash_io2_store,
    easyflash_io2_read,
    easyflash_io2_read, /* same implementation */
    NULL, /* nothing to dump */
    CARTRIDGE_EASYFLASH,
    0
};

static io_source_list_t *easyflash_io1_list_item = NULL;
static io_source_list_t *easyflash_io2_list_item = NULL;

static const c64export_resource_t export_res = {
    CARTRIDGE_NAME_EASYFLASH, 1, 1, &easyflash_io1_device, &easyflash_io2_device, CARTRIDGE_EASYFLASH
};

/* ---------------------------------------------------------------------*/

static int easyflash_check_empty(const BYTE *data)
{
    int i;

    for (i = 0; i < 0x2000; i++) {
        if (data[i] != 0xff) {
            return 0;
        }
    }
    return 1;
}

static int set_easyflash_jumper(int val, void *param)
{
    easyflash_jumper = val;
    return 0;
}

static int set_easyflash_crt_write(int val, void *param)
{
    easyflash_crt_write = val;
    return 0;
}

static int easyflash_write_chip_if_not_empty(FILE* fd, const BYTE* chipheader, const BYTE* data)
{
    if (easyflash_check_empty(data) == 0) {

        if (fwrite(chipheader, 1, 0x10, fd) != 0x10) {
            return -1;
        }

        if (fwrite(data, 1, 0x2000, fd) != 0x2000) {
            return -1;
        }
    }
    return 0;
}

/* ---------------------------------------------------------------------*/

static const resource_int_t resources_int[] = {
    { "EasyFlashJumper", 0, RES_EVENT_STRICT, (resource_value_t)0,
      &easyflash_jumper, set_easyflash_jumper, NULL },
    { "EasyFlashWriteCRT", 0, RES_EVENT_STRICT, (resource_value_t)0,
      &easyflash_crt_write, set_easyflash_crt_write, NULL },
    { NULL }
};

int easyflash_resources_init(void)
{
    return resources_register_int(resources_int);
}

void easyflash_resources_shutdown(void)
{
}

/* ---------------------------------------------------------------------*/

static const cmdline_option_t cmdline_options[] =
{
    { "-easyflashjumper", SET_RESOURCE, 0,
      NULL, NULL, "EasyFlashJumper", (resource_value_t)1,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_ENABLE_EASYFLASH_JUMPER,
      NULL, NULL },
    { "+easyflashjumper", SET_RESOURCE, 0,
      NULL, NULL, "EasyFlashJumper", (resource_value_t)0,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_DISABLE_EASYFLASH_JUMPER,
      NULL, NULL },
    { "-easyflashcrtwrite", SET_RESOURCE, 0,
      NULL, NULL, "EasyFlashWriteCRT", (resource_value_t)1,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_ENABLE_EASYFLASH_CRT_WRITING,
      NULL, NULL },
    { "+easyflashcrtwrite", SET_RESOURCE, 0,
      NULL, NULL, "EasyFlashWriteCRT", (resource_value_t)0,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_DISABLE_EASYFLASH_CRT_WRITING,
      NULL, NULL },
    { NULL }
};

int easyflash_cmdline_options_init(void)
{
    return cmdline_register_options(cmdline_options);
}

/* ---------------------------------------------------------------------*/

BYTE easyflash_roml_read(WORD addr)
{
    return flash040core_read(easyflash_state_low, (easyflash_register_00 * 0x2000) + (addr & 0x1fff));
}

void easyflash_roml_store(WORD addr, BYTE value)
{
    flash040core_store(easyflash_state_low, (easyflash_register_00 * 0x2000) + (addr & 0x1fff), value);
}

BYTE easyflash_romh_read(WORD addr)
{
    return flash040core_read(easyflash_state_high, (easyflash_register_00 * 0x2000) + (addr & 0x1fff));
}

void easyflash_romh_store(WORD addr, BYTE value)
{
    flash040core_store(easyflash_state_high, (easyflash_register_00 * 0x2000) + (addr & 0x1fff), value);
}

/* ---------------------------------------------------------------------*/

void easyflash_config_init(void)
{
    easyflash_io1_store((WORD)0xde00, 0);
    easyflash_io1_store((WORD)0xde02, 0);
}

void easyflash_config_setup(BYTE *rawcart)
{
    easyflash_state_low = lib_malloc(sizeof(flash040_context_t));
    easyflash_state_high = lib_malloc(sizeof(flash040_context_t));

    flash040core_init(easyflash_state_low, maincpu_alarm_context, FLASH040_TYPE_B, roml_banks);
    memcpy(easyflash_state_low->flash_data, rawcart, 0x80000);

    flash040core_init(easyflash_state_high, maincpu_alarm_context, FLASH040_TYPE_B, romh_banks);
    memcpy(easyflash_state_high->flash_data, rawcart + 0x80000, 0x80000);
}

/* ---------------------------------------------------------------------*/

static int easyflash_common_attach(const char *filename)
{
    if (c64export_add(&export_res) < 0) {
        return -1;
    }

    easyflash_io1_list_item = io_source_register(&easyflash_io1_device);
    easyflash_io2_list_item = io_source_register(&easyflash_io2_device);

    easyflash_filename = lib_stralloc(filename);

    return 0;
}

int easyflash_bin_attach(const char *filename, BYTE *rawcart)
{
    FILE *fd;
    unsigned int i;
    BYTE *low;
    BYTE *high;

    easyflash_filetype = 0;
    memset(rawcart, 0xff, 0x100000);

    if (filename == NULL) {
        return -1;
    }

    fd = fopen(filename, MODE_READ);
    if (fd == NULL) {
        return -1;
    }

    low = rawcart;
    high = rawcart + 0x80000;

    for (i = 0; i < EASYFLASH_N_BANKS; i++, low += 0x2000, high += 0x2000) {
        if ((fread(low, 0x2000, 1, fd) < 1) || (fread(high, 0x2000, 1, fd) < 1)) {
            fclose(fd);
            return -1;
        }
    }
    fclose(fd);
    easyflash_filetype = CARTRIDGE_FILETYPE_BIN;
    return easyflash_common_attach(filename);
}

int easyflash_crt_attach(FILE *fd, BYTE *rawcart, BYTE *header, const char *filename)
{
    BYTE chipheader[0x10];
    WORD bank, offset, length;

    easyflash_filetype = 0;
    memset(rawcart, 0xff, 0x100000);

    while (1) {
        if (fread(chipheader, 0x10, 1, fd) < 1) {
            break;
        }

        bank = (chipheader[0xa] << 8) | chipheader[0xb];
        offset = (chipheader[0xc] << 8) | chipheader[0xd];
        length = (chipheader[0xe] << 8) | chipheader[0xf];

        if (length == 0x2000) {
            if (bank >= EASYFLASH_N_BANKS || !(offset == 0x8000 || offset == 0xa000 || offset == 0xe000)) {
                return -1;
            }
            if (fread(&rawcart[(bank << 13) | (offset == 0x8000 ? 0<<19 : 1<<19)], 0x2000, 1, fd) < 1) {
                return -1;
            }
        } else if (length == 0x4000) {
            if (bank >= EASYFLASH_N_BANKS || offset != 0x8000) {
                return -1;
            }
            if (fread(&rawcart[(bank << 13) | (0<<19)], 0x2000, 1, fd) < 1) {
                return -1;
            }
            if (fread(&rawcart[(bank << 13) | (1<<19)], 0x2000, 1, fd) < 1) {
                return -1;
            }
        } else {
            return -1;
        }
    }

    easyflash_filetype = CARTRIDGE_FILETYPE_CRT;
    return easyflash_common_attach(filename);
}

void easyflash_detach(void)
{
    if (easyflash_crt_write) {
        easyflash_flush_image();
    }
    flash040core_shutdown(easyflash_state_low);
    flash040core_shutdown(easyflash_state_high);
    lib_free(easyflash_state_low);
    lib_free(easyflash_state_high);
    lib_free(easyflash_filename);
    easyflash_filename = NULL;
    io_source_unregister(easyflash_io1_list_item);
    io_source_unregister(easyflash_io2_list_item);
    easyflash_io1_list_item = NULL;
    easyflash_io2_list_item = NULL;
    c64export_remove(&export_res);
}

int easyflash_flush_image(void)
{
    if (easyflash_filename != NULL) {
        if (easyflash_filetype == CARTRIDGE_FILETYPE_BIN) {
            return easyflash_bin_save(easyflash_filename);
        } else if (easyflash_filetype == CARTRIDGE_FILETYPE_CRT) {
            return easyflash_crt_save(easyflash_filename);
        }
        return -1;
    }
    return -2;
}

int easyflash_bin_save(const char *filename)
{
    FILE *fd;
    int i;
    BYTE *low;
    BYTE *high;

    if (filename == NULL) {
        return -1;
    }

    fd = fopen(filename, MODE_WRITE);

    if (fd == NULL) {
        return -1;
    }

    low = easyflash_state_low->flash_data;
    high = easyflash_state_high->flash_data;

    for (i = 0; i < EASYFLASH_N_BANKS; i++, low += 0x2000, high += 0x2000) {
        if ((fwrite(low, 1, 0x2000, fd) != 0x2000) || (fwrite(high, 1, 0x2000, fd) != 0x2000)) {
            fclose(fd);
            return -1;
        }
    }

    fclose(fd);
    return 0;
}

int easyflash_crt_save(const char *filename)
{
    FILE *fd;
    BYTE header[0x40], chipheader[0x10];
    BYTE *data;
    int bank;

    if (filename == NULL) {
        return -1;
    }

    fd = fopen(filename, MODE_WRITE);

    if (fd == NULL) {
        return -1;
    }

    memset(header, 0x0, 0x40);
    memset(chipheader, 0x0, 0x10);

    strcpy((char *)header, CRT_HEADER);

    header[0x13] = 0x40;
    header[0x14] = 0x01;
    header[0x17] = CARTRIDGE_EASYFLASH;
    header[0x18] = 0x01;
    strcpy((char *)&header[0x20], STRING_EASYFLASH);
    if (fwrite(header, 1, 0x40, fd) != 0x40) {
        fclose(fd);
        return -1;
    }

    strcpy((char *)chipheader, CHIP_HEADER);
    chipheader[0x06] = 0x20;
    chipheader[0x07] = 0x10;
    chipheader[0x09] = 0x02;
    chipheader[0x0e] = 0x20;

    for (bank = 0; bank < EASYFLASH_N_BANKS; bank++) {
        chipheader[0x0b] = bank;

        data = easyflash_state_low->flash_data + bank * 0x2000;
        chipheader[0x0c] = 0x80;
        if (easyflash_write_chip_if_not_empty(fd, chipheader, data) != 0) {
            fclose(fd);
            return -1;
        }

        data = easyflash_state_high->flash_data + bank * 0x2000;
        chipheader[0x0c] = 0xa0;
        if (easyflash_write_chip_if_not_empty(fd, chipheader, data) != 0) {
            fclose(fd);
            return -1;
        }
    }
    fclose(fd);
    return 0;
}

/* ---------------------------------------------------------------------*/

#define CART_DUMP_VER_MAJOR   0
#define CART_DUMP_VER_MINOR   0
#define SNAP_MODULE_NAME  "CARTEF"
#define FLASH_SNAP_MODULE_NAME  "FLASH040EF"

int easyflash_snapshot_write_module(snapshot_t *s)
{
    snapshot_module_t *m;

    m = snapshot_module_create(s, SNAP_MODULE_NAME,
                          CART_DUMP_VER_MAJOR, CART_DUMP_VER_MINOR);
    if (m == NULL) {
        return -1;
    }

    if (0
        || (SMW_B(m, (BYTE)easyflash_jumper) < 0)
        || (SMW_B(m, easyflash_register_00) < 0)
        || (SMW_B(m, easyflash_register_02) < 0)
        || (SMW_BA(m, easyflash_ram, 256) < 0)
        || (SMW_BA(m, roml_banks, 0x80000) < 0)
        || (SMW_BA(m, romh_banks, 0x80000) < 0)) {
        snapshot_module_close(m);
        return -1;
    }

    snapshot_module_close(m);

    if (0
        || (flash040core_snapshot_write_module(s, easyflash_state_low, FLASH_SNAP_MODULE_NAME) < 0)
        || (flash040core_snapshot_write_module(s, easyflash_state_high, FLASH_SNAP_MODULE_NAME) < 0)) {
        return -1;
    }

    return 0;
}

int easyflash_snapshot_read_module(snapshot_t *s)
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
        || (SMR_B_INT(m, &easyflash_jumper) < 0)
        || (SMR_B(m, &easyflash_register_00) < 0)
        || (SMR_B(m, &easyflash_register_02) < 0)
        || (SMR_BA(m, easyflash_ram, 256) < 0)
        || (SMR_BA(m, roml_banks, 0x80000) < 0)
        || (SMR_BA(m, romh_banks, 0x80000) < 0)) {
        snapshot_module_close(m);
        return -1;
    }

    snapshot_module_close(m);

    easyflash_state_low = lib_malloc(sizeof(flash040_context_t));
    easyflash_state_high = lib_malloc(sizeof(flash040_context_t));

    flash040core_init(easyflash_state_low, maincpu_alarm_context, FLASH040_TYPE_B, roml_banks);
    flash040core_init(easyflash_state_high, maincpu_alarm_context, FLASH040_TYPE_B, romh_banks);

    if (0
        || (flash040core_snapshot_read_module(s, easyflash_state_low, FLASH_SNAP_MODULE_NAME) < 0)
        || (flash040core_snapshot_read_module(s, easyflash_state_low, FLASH_SNAP_MODULE_NAME) < 0)) {
        flash040core_shutdown(easyflash_state_low);
        flash040core_shutdown(easyflash_state_high);
        lib_free(easyflash_state_low);
        lib_free(easyflash_state_high);
        return -1;
    }

    easyflash_common_attach("dummy");

    /* remove dummy filename, set filetype to none */
    lib_free(easyflash_filename);
    easyflash_filename = NULL;
    easyflash_filetype = 0;

    return 0;
}

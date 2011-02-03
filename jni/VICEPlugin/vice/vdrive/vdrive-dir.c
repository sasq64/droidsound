/*
 * vdrive-dir.c - Virtual disk-drive implementation.
 *                Directory specific functions.
 *
 * Written by
 *  Andreas Boose <viceteam@t-online.de>
 *  Ingo Korb <ingo@akana.de>  
 *
 * Based on old code by
 *  Teemu Rantanen <tvr@cs.hut.fi>
 *  Jarkko Sonninen <sonninen@lut.fi>
 *  Jouko Valta <jopi@stekt.oulu.fi>
 *  Olaf Seibert <rhialto@mbfys.kun.nl>
 *  Andr� Fachat <a.fachat@physik.tu-chemnitz.de>
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  pottendo <pottendo@gmx.net>
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

#include "cbmdos.h"
#include "diskconstants.h"
#include "diskimage.h"
#include "lib.h"
#include "log.h"
#include "types.h"
#include "vdrive-bam.h"
#include "vdrive-dir.h"
#include "vdrive.h"


static log_t vdrive_dir_log = LOG_ERR;


void vdrive_dir_init(void)
{
    vdrive_dir_log = log_open("VDriveDIR");
}

/* Returns the interleave for directory sectors of a given image type */
static int vdrive_dir_get_interleave(unsigned int type)
{
    /* Note: Values for all drives determined empirically */
    switch (type) {
    case VDRIVE_IMAGE_FORMAT_1541:
    case VDRIVE_IMAGE_FORMAT_2040:
    case VDRIVE_IMAGE_FORMAT_1571:
    case VDRIVE_IMAGE_FORMAT_8050:
    case VDRIVE_IMAGE_FORMAT_8250:
        return 3;
    case VDRIVE_IMAGE_FORMAT_1581:
        return 1;
    default:
        log_error(LOG_ERR,
                  "Unknown disk type %i.  Using interleave 3.", type);
        return 3;
    }
}

static unsigned int vdrive_dir_name_match(BYTE *slot, BYTE *nslot, int length,
                                          int type)
{
    if (length < 0) {
        if (slot[SLOT_TYPE_OFFSET])
            return 0;
        else
            return 1;
    }

    if (!slot[SLOT_TYPE_OFFSET])
        return 0;

    if (type != CBMDOS_FT_DEL && type != (slot[SLOT_TYPE_OFFSET] & 0x07))
        return 0;

    return cbmdos_parse_wildcard_compare(nslot, &slot[SLOT_NAME_OFFSET]);
}

void vdrive_dir_free_chain(vdrive_t *vdrive, int t, int s)
{
    BYTE buf[256];

    while (t) {
        /* Check for illegal track or sector.  */
        if (disk_image_check_sector(vdrive->image, t, s) < 0)
            break;

        /* Check if this sector is really allocated.  */
        if (!vdrive_bam_free_sector(vdrive->image_format, vdrive->bam, t, s))
            break;

        /* FIXME: This seems to be redundant.  AB19981124  */
        vdrive_bam_free_sector(vdrive->image_format, vdrive->bam, t, s);
        disk_image_read_sector(vdrive->image, buf, t, s);
        t = (int)buf[0];
        s = (int)buf[1];
    }
}

/* Tries to allocate the given track/sector and link it */
/* to the current directory sector of vdrive.           */
/* Returns NULL if the allocation failed.               */
static BYTE *find_next_directory_sector(vdrive_t *vdrive, unsigned int track,
                                        unsigned int sector)
{
    if (vdrive_bam_allocate_sector(vdrive->image_format, vdrive->bam, track,
        sector)) {
        vdrive->Dir_buffer[0] = track;
        vdrive->Dir_buffer[1] = sector;
        disk_image_write_sector(vdrive->image, vdrive->Dir_buffer,
                                vdrive->Curr_track, vdrive->Curr_sector);
#ifdef DEBUG_DRIVE
        log_debug("Found (%d %d) TR = %d SE = %d.",
                  track, sector, vdrive->Curr_track, vdrive->Curr_sector);
#endif
        vdrive->SlotNumber = 0;
        memset(vdrive->Dir_buffer, 0, 256);
        vdrive->Dir_buffer[1] = 0xff;
        vdrive->Curr_sector = sector;
        return vdrive->Dir_buffer;
    }
    return NULL;
}


void vdrive_dir_create_slot(bufferinfo_t *p, char *realname,
                            int reallength, int filetype)
{
    p->slot = lib_calloc(1, 32);
    memset(p->slot + SLOT_NAME_OFFSET, 0xa0, 16);
    memcpy(p->slot + SLOT_NAME_OFFSET, realname, reallength);
#ifdef DEBUG_DRIVE
    log_debug("DIR: Created dir slot. Name (%d) '%s'\n", reallength, realname);
#endif
    p->slot[SLOT_TYPE_OFFSET] = filetype;       /* unclosed */

    p->buffer = lib_calloc(1, 256);
    p->mode = BUFFER_SEQUENTIAL;
    p->bufptr = 2;
    return;
}

/*
 * vdrive_dir_remove_slot() is called from vdrive_open() (in 'save and
 * replace') and from ip_execute() for 'SCRATCH'.
 */

void vdrive_dir_remove_slot(vdrive_t *vdrive, BYTE *slot)
{
    unsigned int tmp;
    int t, s;

    /* Find slot.  */
    for (tmp = 0; (tmp < 16) && slot[SLOT_NAME_OFFSET + tmp] != 0xa0; tmp++);

    vdrive_dir_find_first_slot(vdrive,
                               (char *)&slot[SLOT_NAME_OFFSET], tmp,
                               slot[SLOT_TYPE_OFFSET] & 0x07);

    /* If slot found, remove.  */
    if (vdrive_dir_find_next_slot(vdrive)) {

        /* Free all sector this file is using.  */
        t = (int) vdrive->Dir_buffer[vdrive->SlotNumber * 32
            + SLOT_FIRST_TRACK];
        s = (int) vdrive->Dir_buffer[vdrive->SlotNumber * 32
            + SLOT_FIRST_SECTOR];

        vdrive_dir_free_chain(vdrive, t, s);

        /* Free side sectors.  */
        t = (int) vdrive->Dir_buffer[vdrive->SlotNumber * 32
            + SLOT_SIDE_TRACK];
        s = (int) vdrive->Dir_buffer[vdrive->SlotNumber * 32
            + SLOT_SIDE_SECTOR];

        vdrive_dir_free_chain(vdrive, t, s);

        /* Update bam */
        vdrive_bam_write_bam(vdrive);

        /* Update directory entry */
        vdrive->Dir_buffer[vdrive->SlotNumber * 32 + SLOT_TYPE_OFFSET] = 0;
        disk_image_write_sector(vdrive->image, vdrive->Dir_buffer,
                                vdrive->Curr_track, vdrive->Curr_sector);
    }
}

void vdrive_dir_find_first_slot(vdrive_t *vdrive, const char *name,
                                int length, unsigned int type)
{
    if (length > 0) {
        BYTE *nslot;

        nslot = cbmdos_dir_slot_create(name, length);
        memcpy(vdrive->find_nslot, nslot, CBMDOS_SLOT_NAME_LENGTH);
        lib_free(nslot);
    }

    vdrive->find_length = length;
    vdrive->find_type = type;

    vdrive->Curr_track = vdrive->Dir_Track;
    vdrive->Curr_sector = vdrive->Dir_Sector;
    vdrive->SlotNumber = 0;
    vdrive->SlotNumber--;

    disk_image_read_sector(vdrive->image, vdrive->Dir_buffer,
                           vdrive->Dir_Track, vdrive->Dir_Sector);
}

BYTE *vdrive_dir_find_next_slot(vdrive_t *vdrive)
{
    static BYTE return_slot[32];

    vdrive->SlotNumber++;

    /*
     * Loop all directory blocks starting from track 18, sector 1 (1541).
     */

    do {
        /*
         * Load next(first) directory block ?
         */

        if (vdrive->SlotNumber >= 8) {
            int status;

            if (vdrive->Dir_buffer[0] == 0)
                return NULL;

            vdrive->SlotNumber = 0;
            vdrive->Curr_track  = (int)vdrive->Dir_buffer[0];
            vdrive->Curr_sector = (int)vdrive->Dir_buffer[1];

            status = disk_image_read_sector(vdrive->image, vdrive->Dir_buffer,
                                            vdrive->Curr_track,
                                            vdrive->Curr_sector);
            if (status != 0)
                break;
        }
        while (vdrive->SlotNumber < 8) {
            if (vdrive_dir_name_match(
                                  &vdrive->Dir_buffer[vdrive->SlotNumber * 32],
                                  vdrive->find_nslot, vdrive->find_length,
                                  vdrive->find_type)) {
                memcpy(return_slot,
                       &vdrive->Dir_buffer[vdrive->SlotNumber * 32], 32);
                return return_slot;
            }
            vdrive->SlotNumber++;
        }
    } while (*(vdrive->Dir_buffer));

    /*
     * If length < 0, create new directory-entry if possible
     */

    if (vdrive->find_length < 0) {
        int i, sector;
        BYTE *dirbuf;

        sector = vdrive->Curr_sector +
            vdrive_dir_get_interleave(vdrive->image_format);

        for (i = 0;
             i < vdrive_get_max_sectors(vdrive->image_format,
                                        vdrive->Curr_track);
             i++) {
            dirbuf = find_next_directory_sector(vdrive,
                                                vdrive->Curr_track,
                                                sector);
            if (dirbuf != NULL) {
                return dirbuf;
            }

            sector++;
            if (sector >= vdrive_get_max_sectors(vdrive->image_format,
                                                 vdrive->Curr_track)) {
                sector = 0;
            }
        }
    }
    return NULL;
}

void vdrive_dir_no_a0_pads(BYTE *ptr, int l)
{
    while (l--) {
        if (*ptr == 0xa0)
            *ptr = 0x20;
        ptr++;
    }
}

/*
 * Create directory listing. (called from vdrive_open)
 * If filetype is 0, match for all files.  Return the length in bytes
 * if successful, -1 if the directory is not valid.
 */

int vdrive_dir_create_directory(vdrive_t *vdrive, const char *name,
                                int length, int filetype, BYTE *outputptr)
{
    BYTE *l, *p;
    BYTE *origptr = outputptr;
    int blocks, i;

    if (length) {
        if (*name == '$') {
            ++name;
            --length;
        }
        if (*name == ':') {
            ++name;
            --length;
        }
    }
    if (!*name || length < 1) {
        name = "*\0";
        length = 1;
    }

    /*
     * Start Address, Line Link and Line number 0
     */

    l = outputptr;
    *l++ = 1;
    *l++ = 4;

    l += 2;                     /* Leave space for Next Line Link */
    *l++ = 0;
    *l++ = 0;

    *l++ = (BYTE)0x12;          /* Reverse on */

    *l++ = '"';

    memcpy(l, &vdrive->bam[vdrive->bam_name], 16);
    vdrive_dir_no_a0_pads(l, 16);
    l += 16;
    *l++ = '"';
    *l++ = ' ';
    memcpy(l, &vdrive->bam[vdrive->bam_id], 5);
    vdrive_dir_no_a0_pads(l, 5);
    l += 5;
    *l++ = 0;

    /*
     * Pointer to the next line
     */

    outputptr[2] = 1;
    outputptr[3] = 1;
    outputptr = l;

    /*
     * Now, list files that match the pattern.
     * Wildcards can be used too.
     */

    vdrive_dir_find_first_slot(vdrive, name, length, filetype);

    while ((p = vdrive_dir_find_next_slot(vdrive))) {
        BYTE *tl;

        /* Check whether the directory exceeds the malloced memory.  We make
           sure there is enough space for two lines because we also have to
           add the final ``...BLOCKS FREE'' line.  */
        if ((l - origptr) >= DIR_MAXBUF - 64) {
            log_error(vdrive_dir_log, "Directory too long: giving up.");
            return -1;
        }

        if (p[SLOT_TYPE_OFFSET]) {

            tl = l;
            l += 2;

            /*
             * Length and spaces
             */
            blocks = p[SLOT_NR_BLOCKS] + p[SLOT_NR_BLOCKS + 1] * 256;
            SET_LO_HI(l, blocks);

            if (blocks < 10)
                *l++ = ' ';
            if (blocks < 100)
                *l++ = ' ';
            /*
             * Filename
             */

            *l++ = ' ';
            *l++ = '"';

            memcpy(l, &p[SLOT_NAME_OFFSET], 16);

            for (i = 0; (i < 16) && (p[SLOT_NAME_OFFSET + i] != 0xa0);)
                i++;

            vdrive_dir_no_a0_pads(l, 16);

            l[16] = ' ';
            l[i] = '"';
            l += 17;

            /*
             * Type + End
             * There are 3 spaces or < and 2 spaces after the filetype.
             * Well, not exactly - the whole directory entry is 32 byte long
             * (including nullbyte).
             * Depending on the file size, there are more or less spaces
             */

            sprintf((char *)l, "%c%s%c%c",
                    (p[SLOT_TYPE_OFFSET] & CBMDOS_FT_CLOSED ? ' ' : '*'),
                    cbmdos_filetype_get(p[SLOT_TYPE_OFFSET] & 0x07),
                    (p[SLOT_TYPE_OFFSET] & CBMDOS_FT_LOCKED ? '<' : ' '),
                    0);
            l += 5;
            i = (int)(l - tl);

            while (i < 31) {
                *l++ = ' ';
                i++;
            }
            *l++ = '\0';

            /*
             * New address
             */

            outputptr[0] = 1;
            outputptr[1] = 1;
            outputptr = l;
        }
    }

    blocks = vdrive_bam_free_block_count(vdrive);

    *l++ = 0;
    *l++ = 0;
    SET_LO_HI(l, blocks);
    memcpy(l, "BLOCKS FREE.", 12);
    l += 12;
    memset(l, ' ', 13);
    l += 13;
    *l++ = (char) 0;

    /* Line Address */
    outputptr[0] = 1;
    outputptr[1] = 1;

    /*
     * end
     */
    *l++ = (char) 0;
    *l++ = (char) 0;
    *l   = (char) 0;

    return (int)(l - origptr);
}


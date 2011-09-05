/*
 * vdrive-command.c - Virtual disk-drive implementation. Command interpreter.
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

/* #define DEBUG_DRIVE */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cbmdos.h"
#include "diskimage.h"
#include "lib.h"
#include "log.h"
#include "machine-drive.h"
#include "types.h"
#include "vdrive-bam.h"
#include "vdrive-command.h"
#include "vdrive-dir.h"
#include "vdrive-iec.h"
#include "vdrive-rel.h"
#include "vdrive.h"


#define IP_MAX_COMMAND_LEN 128 /* real 58 */


static log_t vdrive_command_log = LOG_ERR;

static int vdrive_command_block(vdrive_t *vdrive, unsigned char command, char *buffer);
static int vdrive_command_memory(vdrive_t *vdrive, BYTE *buffer,
                                 unsigned int length);
static int vdrive_command_initialize(vdrive_t *vdrive);
static int vdrive_command_copy(vdrive_t *vdrive, char *dest, int length);
static int vdrive_command_rename(vdrive_t *vdrive, BYTE *dest, int length);
static int vdrive_command_scratch(vdrive_t *vdrive, BYTE *name, int length);
static int vdrive_command_position(vdrive_t *vdrive, BYTE *buf,
                                   unsigned int length);

#if 0
const char *vdrive_command_errortext(unsigned int code)
{
    unsigned int count = 0;

    while (floppy_error_messages[count].nr != 255
        && floppy_error_messages[count].nr != code)
        count++;

    if (floppy_error_messages[count].nr != 255)
        return floppy_error_messages[count].text;

    return "UNKNOWN ERROR NUMBER";
}
#endif

void vdrive_command_init(void)
{
    vdrive_command_log = log_open("VDriveCommand");
}

int vdrive_command_execute(vdrive_t *vdrive, const BYTE *buf,
                           unsigned int length)
{
    int status = CBMDOS_IPE_OK;
    BYTE *cmd, *p, *p2;
    char *name;
    BYTE *minus;

    if (!length)
        return CBMDOS_IPE_OK;
    if (length > IP_MAX_COMMAND_LEN) {
        vdrive_command_set_error(vdrive, CBMDOS_IPE_LONG_LINE, 0, 0);
        return CBMDOS_IPE_LONG_LINE;
    }

    cmd = lib_malloc(length + 1);
    memcpy(cmd, buf, length);

    if (cmd[length - 1] == 0x0d) {
        --length; /* chop CR character */
    }
    cmd[length] = 0;

    p = cmd;

    name = (char *)memchr(p, ':', length);
    minus = (BYTE *)memchr(p, '-', length);

    if (name) { /* Fix name length */
        for (p2 = p; *p2 && *p2 != ':' && length > 0; p2++, length--);
    }

#ifdef DEBUG_DRIVE
    log_debug("Command %c.", *p);
#endif

    switch (*p) {
      case 'C': /* Copy command.  */
        status = vdrive_command_copy(vdrive, (char *)name, length);
        break;

      case 'D':         /* Backup unused */
        status = CBMDOS_IPE_INVAL;
        break;

      case 'R':         /* Rename */
        status = vdrive_command_rename(vdrive, (BYTE *)name, length);
        break;

      case 'S':         /* Scratch */
        status = vdrive_command_scratch(vdrive, (BYTE *)name, length);
        break;

      case 'I':
        status = vdrive_command_initialize(vdrive);
        break;

      case 'N':
        /* Skip ":" at the start of the name.  */
        status = vdrive_command_format(vdrive,
                                       (name == NULL) ? NULL : name + 1);
        break;

      case 'V':
        status = vdrive_command_validate(vdrive);
        break;

      case 'B': /* Block, Buffer */
        if (!name)      /* B-x does not require a : */
            name = (char *)(p + 2);
        if (!minus)
            status = CBMDOS_IPE_INVAL;
        else
            status = vdrive_command_block(vdrive, minus[1], name + 1);
        break;

      case 'M': /* Memory */
        /* FIXME: The ":" could be a low address of a read/write/execute */
        if (!minus)     /* M-x does not allow a : */
            status = CBMDOS_IPE_INVAL;
        else
            status = vdrive_command_memory(vdrive, minus + 1, length);
        break;

      case 'P': /* Position */
        status = vdrive_command_position(vdrive, p + 1, length);
        break;

      case 'U': /* User */
        if (!name)
            name = (char *)(p + 1);
        if (p[1] == '0') {
            status = CBMDOS_IPE_OK;
        } else {
            switch ((p[1] - 1) & 0x0f) {
              case 0: /* UA */
                if (name)
                    status = vdrive_command_block(vdrive, (unsigned char)0xd2, name + 1);
                break;

              case 1: /* UB */
                if (name)
                    status = vdrive_command_block(vdrive, (unsigned char)0xd7, name + 1);
                break;

              case 2: /* Jumps */
              case 3:
              case 4:
              case 5:
              case 6:
              case 7:
                status = CBMDOS_IPE_NOT_READY;
                break;

              case 8: /* UI */
                if (p[2] == '-' || p[2] == '+') {
                    status = CBMDOS_IPE_OK;    /* Set IEC bus speed */
                } else {
                    vdrive_close_all_channels(vdrive); /* Warm reset */
                    status = CBMDOS_IPE_DOS_VERSION;
                }
                break;

              case 9: /* UJ */
                vdrive_close_all_channels(vdrive); /* Cold reset */
                status = CBMDOS_IPE_DOS_VERSION;
                break;

              case 10: /* UK..UP */
              case 11:
              case 12:
              case 13:
              case 14:
              case 15:
                status = CBMDOS_IPE_NOT_READY;
                break;
            }
        } /* Un */
        break;

      default:
        status = CBMDOS_IPE_INVAL;
        break;
    } /* commands */

    if (status == CBMDOS_IPE_INVAL) {
        log_error(vdrive_command_log, "Wrong command `%s'.", cmd);
    }

    vdrive_command_set_error(vdrive, status, 0, 0);

    lib_free((char *)cmd);
    return status;
}

static int vdrive_get_block_parameters(char *buf, int *p1, int *p2, int *p3,
                                       int *p4)
{
    int ip;
    char *bp, endsign;
    int *p[4];  /* This is a kludge */
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;

    bp = buf;

    for (ip = 0; ip < 4; ip++) {
        /* 1541 firmware skips 0x20, 0x2c, and 0x1d */
        while (*bp == ' ' || *bp == ')' || *bp == ',' || *bp == '#' || *bp == 0x1d)
            bp++;
        if (*bp == 0)
            break;
        /* Convert and skip over decimal number.  */
        *p[ip] = strtol(bp, &bp, 10);
    }
    endsign = *bp;
    if (isalnum((int)endsign) && (ip == 4))
        return CBMDOS_IPE_SYNTAX;
    return -ip;                 /* negative of # arguments found */
}

static int vdrive_command_block(vdrive_t *vdrive, unsigned char command,
                                char *buffer)
{
    int channel = 0, drive = 0, track = 0, sector = 0, position = 0;
    int l, rc;

#ifdef DEBUG_DRIVE
    log_debug("vdrive_command_block command:%c.", command);
#endif

    switch (command) {
      /* 1581 has u-R (shifted) and u-W (shifted) for block read/write
         without track/sector checking. */
      /* Use this for U1,UA and U2,UB also */
      case 0xd2:
      case 0xd7:
        l = vdrive_get_block_parameters(buffer, &channel, &drive, &track,
                                        &sector);

        if (l < 0) {
#ifdef DEBUG_DRIVE
            log_debug("B-R/W parsed ok. (l=%d) channel %d mode %d, "
                      "drive=%d, track=%d sector=%d.", l, channel,
                      vdrive->buffers[channel].mode, drive, track, sector);
#endif

            if (vdrive->buffers[channel].mode != BUFFER_MEMORY_BUFFER)
                return CBMDOS_IPE_NO_CHANNEL;

            if (command == 0xd7) {
                /* For write */
                if (vdrive->image->read_only || VDRIVE_IMAGE_FORMAT_1992_TEST)
                    return CBMDOS_IPE_WRITE_PROTECT_ON;
                if (disk_image_write_sector(vdrive->image,
                                            vdrive->buffers[channel].buffer,
                                            track, sector) < 0)
                    return CBMDOS_IPE_NOT_READY;
            } else {
                /* For read */
                rc = disk_image_read_sector(vdrive->image,
                                            vdrive->buffers[channel].buffer,
                                            track, sector);
                if (rc > 0)
                    return rc;
                if (rc < 0)
                    return CBMDOS_IPE_NOT_READY;
            }
            vdrive->buffers[channel].bufptr = 0;
        } else {
            log_error(vdrive_command_log, "B-R/W invalid parameter "
                      "C:%i D:%i T:%i S:%i.", channel, drive, track, sector);
        }
        break;
      /* Old style B-R and B-W */
      case 'R':
      case 'W':
        l = vdrive_get_block_parameters(buffer, &channel, &drive, &track,
                                        &sector);

        if (l < 0) {
#ifdef DEBUG_DRIVE
            log_debug("B-R/W parsed ok. (l=%d) channel %d mode %d, "
                      "drive=%d, track=%d sector=%d.", l, channel,
                      vdrive->buffers[channel].mode, drive, track, sector);
#endif

            if (vdrive->buffers[channel].mode != BUFFER_MEMORY_BUFFER)
                return CBMDOS_IPE_NO_CHANNEL;

            if (command == 'W') {
                /* For write */
                if (vdrive->image->read_only || VDRIVE_IMAGE_FORMAT_1992_TEST)
                    return CBMDOS_IPE_WRITE_PROTECT_ON;
                /* Update length of block based on the buffer pointer. */
                l = vdrive->buffers[channel].bufptr - 1;
                vdrive->buffers[channel].buffer[0] = ( l < 1 ? 1 : l );
                if (disk_image_write_sector(vdrive->image,
                                            vdrive->buffers[channel].buffer,
                                            track, sector) < 0)
                    return CBMDOS_IPE_NOT_READY;
                /* after write, buffer pointer is 1. */
                vdrive->buffers[channel].bufptr = 1;
            } else {
                /* For read */
                rc = disk_image_read_sector(vdrive->image,
                                            vdrive->buffers[channel].buffer,
                                            track, sector);
                /* set buffer length base on first value */
                vdrive->buffers[channel].length =
                    vdrive->buffers[channel].buffer[0] + 1;
                /* buffer pointer is 1, not 0. */
                vdrive->buffers[channel].bufptr = 1;
                if (rc > 0)
                    return rc;
                if (rc < 0)
                    return CBMDOS_IPE_NOT_READY;
            }
        } else {
            log_error(vdrive_command_log, "B-R/W invalid parameter "
                      "C:%i D:%i T:%i S:%i.", channel, drive, track, sector);
        }
        break;
      case 'A':
      case 'F':
        l = vdrive_get_block_parameters(buffer, &drive, &track, &sector,
                                        &channel);
        if (l > 0) /* just 3 args used */
            return l;
        if (command == 'A') {
            if (!vdrive_bam_allocate_sector(vdrive->image_format, vdrive->bam,
                track, sector)) {
                /*
                 * Desired sector not free. Suggest another. XXX The 1541
                 * uses an inferior search function that only looks on
                 * higher tracks and can return sectors in the directory
                 * track.
                 */
                if (vdrive_bam_alloc_next_free_sector(vdrive, vdrive->bam,
                    (unsigned int*)&track, (unsigned int *)&sector) >= 0) {
                    /* Deallocate it and merely suggest it */
                    vdrive_bam_free_sector(vdrive->image_format, vdrive->bam,
                                           track, sector);
                } else {
                    /* Found none */
                    track = 0;
                    sector = 0;
                }
                vdrive_command_set_error(vdrive, CBMDOS_IPE_NO_BLOCK, track,
                                         sector);
                return CBMDOS_IPE_NO_BLOCK;
            }
        } else {
            vdrive_bam_free_sector(vdrive->image_format, vdrive->bam,
                                   track, sector);
        }
        break;
      case 'P':
        l = vdrive_get_block_parameters(buffer, &channel, &position, &track,
                                        &sector);
        if (l > 0) /* just 2 args used */
            return l;
        if (vdrive->buffers[channel].mode != BUFFER_MEMORY_BUFFER)
            return CBMDOS_IPE_NO_CHANNEL;
        vdrive->buffers[channel].bufptr = position;
        break;
      case 'E':
        l = vdrive_get_block_parameters(buffer, &channel, &drive, &track, &sector);
        log_message(vdrive_command_log, "Warning - B-E: %d %d %d %d (needs TDE)", channel, drive, track, sector);
        break;
      default:
        return CBMDOS_IPE_INVAL;
    }
    return CBMDOS_IPE_OK;
}

/*
    the buffer pointer passed to this function points to the character
    following '-' in the memory command.

    the buffer pointer passed to the sub functions points to the byte
    after the first argument (address) which is passed seperately.
*/

static int vdrive_command_memory(vdrive_t *vdrive, BYTE *buffer,
                                 unsigned int length)
{
    WORD addr = 0;

    if (length < 3) {
        return CBMDOS_IPE_SYNTAX;
    }

    addr = buffer[1] | (buffer[2] << 8);

    switch (*buffer) {
      case 'W':
        return vdrive_command_memory_write(vdrive, buffer + 3, addr, length);
      case 'R':
        return vdrive_command_memory_read(vdrive, buffer + 3, addr, length);
      case 'E':
        return vdrive_command_memory_exec(vdrive, buffer + 3, addr, length);
      default:
        break;
    }
    return CBMDOS_IPE_SYNTAX;
}

static int vdrive_command_copy(vdrive_t *vdrive, char *dest, int length)
{
    char *name, *files, *p, c;
    int status = 0;

    /* Split command line */
    if (!dest || !(files = (char *)memchr(dest, '=', length)) )
        return CBMDOS_IPE_SYNTAX;

    *files++ = 0;

    if (strchr (dest, ':'))
        dest = strchr(dest, ':') + 1;

#ifdef DEBUG_DRIVE
    log_debug("COPY: dest= '%s', orig= '%s'.", dest, files);
#endif

    if (vdrive_iec_open(vdrive, (BYTE *)dest, (unsigned int)strlen(dest), 1, NULL))
        return CBMDOS_IPE_FILE_EXISTS;

    p = name = files;

    while (*name) { /* Loop for given files.  */
        for (; *p && *p != ','; p++);
        *p++ = 0;

        if (strchr (name, ':'))
            name = strchr (name, ':') +1;

#ifdef DEBUG_DRIVE
        log_debug("searching for file '%s'.", name);
#endif
        if (vdrive_iec_open(vdrive, (BYTE *)name, (unsigned int)strlen(name), 0, NULL)) {
            vdrive_iec_close(vdrive, 1);
            return CBMDOS_IPE_NOT_FOUND;
        }

        do {
            status = vdrive_iec_read(vdrive, (BYTE *)&c, 0);
            if (vdrive_iec_write(vdrive, c, 1)) {
                vdrive_iec_close(vdrive, 0); /* No space on disk.  */
                vdrive_iec_close(vdrive, 1);
                return CBMDOS_IPE_DISK_FULL;
            }
        } while (status == SERIAL_OK);

        vdrive_iec_close(vdrive, 0);
        name = p; /* Next file.  */
    }
    vdrive_iec_close(vdrive, 1);
    return CBMDOS_IPE_OK;
}

static int vdrive_command_rename(vdrive_t *vdrive, BYTE *dest, int length)
{
    BYTE *src;
    BYTE *slot;
    int status = CBMDOS_IPE_OK, rc;
    cbmdos_cmd_parse_t cmd_parse_dst, cmd_parse_src;

    if (!dest || !(src = memchr((char *)dest, '=', length)) )
        return CBMDOS_IPE_SYNTAX;

    *src++ = 0;

    if (strchr((char *)dest, ':'))
        dest = (BYTE *)strchr((char *)dest, ':') + 1;

#ifdef DEBUG_DRIVE
    log_debug("RENAME: dest= '%s', orig= '%s'.", dest, src);
#endif

    cmd_parse_dst.cmd = dest;
    cmd_parse_dst.cmdlength = (unsigned int)strlen((char *)dest);
    cmd_parse_dst.readmode = CBMDOS_FAM_READ;

    rc = cbmdos_command_parse(&cmd_parse_dst);

    if (rc == FLOPPY_ERROR) {
        status = CBMDOS_IPE_SYNTAX;
        goto out1;
    }

    cmd_parse_src.cmd = src;
    cmd_parse_src.cmdlength = (unsigned int)strlen((char *)src);
    cmd_parse_src.readmode = CBMDOS_FAM_READ;

    rc = cbmdos_command_parse(&cmd_parse_src);

    if (rc == FLOPPY_ERROR) {
        status = CBMDOS_IPE_SYNTAX;
        goto out2;
    }

    if (vdrive->image->read_only || VDRIVE_IMAGE_FORMAT_1992_TEST) {
        status = CBMDOS_IPE_WRITE_PROTECT_ON;
        goto out2;
    }

    /* Check if the destination name is already in use.  */

    vdrive_dir_find_first_slot(vdrive, cmd_parse_dst.parsecmd,
                               cmd_parse_dst.parselength,
                               cmd_parse_dst.filetype);

    slot = vdrive_dir_find_next_slot(vdrive);

    if (slot) {
        status = CBMDOS_IPE_FILE_EXISTS;
        goto out2;
    }

    /* Find the file to rename. */

    vdrive_dir_find_first_slot(vdrive, cmd_parse_src.parsecmd,
                               cmd_parse_src.parselength,
                               cmd_parse_src.filetype);

    slot = vdrive_dir_find_next_slot(vdrive);

    if (!slot) {
        status = CBMDOS_IPE_NOT_FOUND;
        goto out2;
    }

    /* Now we can replace the old file name...  */
    /* We write directly to the Dir_buffer.  */

    slot = &vdrive->Dir_buffer[vdrive->SlotNumber * 32];
    memset(slot + SLOT_NAME_OFFSET, 0xa0, 16);
    memcpy(slot + SLOT_NAME_OFFSET, cmd_parse_dst.parsecmd,
           cmd_parse_dst.parselength);

    /* FIXME: is this right? */
    if (cmd_parse_dst.filetype)
        slot[SLOT_TYPE_OFFSET] = cmd_parse_dst.filetype;

    /* Update the directory.  */
    if (disk_image_write_sector(vdrive->image, vdrive->Dir_buffer,
        vdrive->Curr_track, vdrive->Curr_sector) < 0)
        status = CBMDOS_IPE_WRITE_ERROR_VER;

out2:
    lib_free(cmd_parse_src.parsecmd);
out1:
    lib_free(cmd_parse_dst.parsecmd);

    return status;
}

static int vdrive_command_scratch(vdrive_t *vdrive, BYTE *name, int length)
{
    int status, rc;
    BYTE *slot;
    cbmdos_cmd_parse_t cmd_parse;

    /* XXX
     * Wrong name parser - s0:file1,file2 means scratch
     * those 2 files.
     */

    cmd_parse.cmd = name;
    cmd_parse.cmdlength = length;
    cmd_parse.readmode = 0;

    rc = cbmdos_command_parse(&cmd_parse);

    if (rc != SERIAL_OK) {
        status = CBMDOS_IPE_NO_NAME;
    } else if (vdrive->image->read_only || VDRIVE_IMAGE_FORMAT_1992_TEST) {
        status = CBMDOS_IPE_WRITE_PROTECT_ON;
    } else {
/*#ifdef DEBUG_DRIVE*/
        log_debug("remove name= '%s' len=%d (%d) type= %d.",
                  cmd_parse.parsecmd, cmd_parse.parselength,
                  length, cmd_parse.filetype);
/*#endif*/
        vdrive->deleted_files = 0;

        /* Since vdrive_dir_remove_slot() uses
         * vdrive_dir_find_first_slot() too, we cannot find the
         * matching files by simply repeating
         * vdrive_dir find_next_slot() calls alone; we have to re-call
         * vdrive_dir_find_first_slot() each time... EP 1996/04/07
         */

        vdrive_dir_find_first_slot(vdrive, cmd_parse.parsecmd,
                                   cmd_parse.parselength, 0);

        while ((slot = vdrive_dir_find_next_slot(vdrive))) {
            vdrive_dir_remove_slot(vdrive, slot);
            vdrive->deleted_files++;
            vdrive_dir_find_first_slot(vdrive, cmd_parse.parsecmd,
                                       cmd_parse.parselength, 0);
        }

        if (vdrive->deleted_files)
            status = CBMDOS_IPE_DELETED;
        else
            status = CBMDOS_IPE_NOT_FOUND;

        vdrive_command_set_error(vdrive, status, 1, 0);
    }

    lib_free(cmd_parse.parsecmd);

    return status;
}

static int vdrive_command_initialize(vdrive_t *vdrive)
{
    vdrive_close_all_channels(vdrive);

    /* Update BAM in memory.  */
    if (vdrive->image != NULL)
        vdrive_bam_read_bam(vdrive);

    return CBMDOS_IPE_OK;
}

int vdrive_command_validate(vdrive_t *vdrive)
{
    unsigned int t, s;
    int status;
    BYTE *b, oldbam[BAM_MAXSIZE];

    status = vdrive_command_initialize(vdrive);

    if (status != CBMDOS_IPE_OK)
        return status;
    if (vdrive->image->read_only || VDRIVE_IMAGE_FORMAT_1992_TEST)
        return CBMDOS_IPE_WRITE_PROTECT_ON;

    memcpy(oldbam, vdrive->bam, vdrive->bam_size);

    vdrive_bam_clear_all(vdrive->image_format, vdrive->bam);

    for (t = 1; t <= vdrive->num_tracks; t++) {
        int max_sector;
        max_sector = vdrive_get_max_sectors(vdrive, t);
        for (s = 0; s < (unsigned int)max_sector; s++)
            vdrive_bam_free_sector(vdrive->image_format, vdrive->bam, t, s);
    }

    /* First map out the BAM and directory itself.  */
    status = vdrive_bam_allocate_chain(vdrive, vdrive->Bam_Track,
                                       vdrive->Bam_Sector);

    if (status != CBMDOS_IPE_OK) {
        memcpy(vdrive->bam, oldbam, vdrive->bam_size);
        return status;
    }

    switch (vdrive->image_format) {
    case VDRIVE_IMAGE_FORMAT_1571:
        {
            int max_sector;
            max_sector = vdrive_get_max_sectors(vdrive, 53);
            for (s = 0; s < (unsigned int)max_sector; s++)
                vdrive_bam_allocate_sector(vdrive->image_format, vdrive->bam, 53,
                                           s);
            break;
        }
    case VDRIVE_IMAGE_FORMAT_1581:
        vdrive_bam_allocate_sector(vdrive->image_format, vdrive->bam,
                                   vdrive->Bam_Track, vdrive->Bam_Sector + 1);
        vdrive_bam_allocate_sector(vdrive->image_format, vdrive->bam,
                                   vdrive->Bam_Track, vdrive->Bam_Sector + 2);
        break;
    case VDRIVE_IMAGE_FORMAT_1992:
        vdrive_bam_allocate_sector(vdrive->image_format, vdrive->bam, 1, 0);
        for (s = 2; s < 34; s++)
            vdrive_bam_allocate_sector(vdrive->image_format, vdrive->bam, 1, s);
        break;
    }

    vdrive_dir_find_first_slot(vdrive, "*", 1, 0);

    while ((b = vdrive_dir_find_next_slot(vdrive))) {
        char *filetype = (char *)
        &vdrive->Dir_buffer[vdrive->SlotNumber * 32 + SLOT_TYPE_OFFSET];

        if (*filetype & CBMDOS_FT_CLOSED) {
            status = vdrive_bam_allocate_chain(vdrive, b[SLOT_FIRST_TRACK],
                                               b[SLOT_FIRST_SECTOR]);
            if (status != CBMDOS_IPE_OK) {
                memcpy(vdrive->bam, oldbam, vdrive->bam_size);
                return status;
            }
            /* The real drive always validates side sectors even if the file
               type is not REL.  */
            status = vdrive_bam_allocate_chain(vdrive, b[SLOT_SIDE_TRACK],
                                               b[SLOT_SIDE_SECTOR]);
            if (status != CBMDOS_IPE_OK) {
                memcpy(vdrive->bam, oldbam, vdrive->bam_size);
                return status;
            }
        } else {
            *filetype = CBMDOS_FT_DEL;
            if (disk_image_write_sector(vdrive->image, vdrive->Dir_buffer,
                vdrive->Curr_track, vdrive->Curr_sector) < 0)
                return CBMDOS_IPE_WRITE_ERROR_VER;
        }
    }

    /* Write back BAM only if validate was successful.  */
    vdrive_bam_write_bam(vdrive);
    return status;
}

int vdrive_command_format(vdrive_t *vdrive, const char *disk_name)
{
    BYTE tmp[256];
    int status;
    char *name, *comma;
    BYTE id[2];

    if (!disk_name)
        return CBMDOS_IPE_SYNTAX;

    if (vdrive->image->read_only || VDRIVE_IMAGE_FORMAT_1992_TEST)
        return CBMDOS_IPE_WRITE_PROTECT_ON;

    if (vdrive->image->device == DISK_IMAGE_DEVICE_FS) {
        if (disk_image_fsimage_fd_get(vdrive->image) == NULL)
            return CBMDOS_IPE_NOT_READY;
    }

    comma = memchr(disk_name, ',', strlen(disk_name));

    if (comma != NULL) {
        if (comma != disk_name) {
            name = lib_malloc(comma - disk_name + 1);
            memcpy(name, disk_name, comma - disk_name);
            name[comma - disk_name] = '\0';
        } else {
            name = lib_stralloc(" ");
        }
        if (comma[1] != '\0') {
            if (comma[2] != '\0') {
                id[0] = comma[1];
                id[1] = comma[2];
            } else {
                id[0] = comma[1];
                id[1] = ' ';
            }
        } else {
            id[0] = id[1] = ' ';
        }
    } else {
        name = lib_stralloc(disk_name);
        id[0] = id[1] = ' ';
    }

    /* Make the first dir-entry.  */
    memset(tmp, 0, 256);
    tmp[1] = 255;

    if (disk_image_write_sector(vdrive->image, tmp, vdrive->Dir_Track,
        vdrive->Dir_Sector) < 0) {
        lib_free(name);
        return CBMDOS_IPE_WRITE_ERROR_VER;
    }
    vdrive_bam_create_empty_bam(vdrive, name, id);
    vdrive_bam_write_bam(vdrive);

    /* Validate is called to clear the BAM.  */
    status = vdrive_command_validate(vdrive);

    lib_free(name);

    return status;
}

static int vdrive_command_position(vdrive_t *vdrive, BYTE *buf,
                                   unsigned int length)
{
    unsigned int channel, rec_lo, rec_hi, position;

    /* default the position to 1 */
    if (length <= 4)
        buf[3] = 1;
    /* default the high record to 0 */
    if (length <= 3)
        buf[2] = 0;
    /* default the low record to 1 */
    if (length <= 2)
        buf[1] = 1;
    /* if no channel is specified, return NO CHANNEL */
    if (length <= 1)
        return CBMDOS_IPE_NO_CHANNEL;

    /* remove bit 5 & 6 from the channel */
    channel = buf[0] & 15;
    rec_lo = buf[1];
    rec_hi = buf[2];
    position = buf[3];

    if (vdrive->buffers[channel].mode != BUFFER_RELATIVE)
        return CBMDOS_IPE_NO_CHANNEL;

    return vdrive_rel_position(vdrive, channel, rec_lo, rec_hi, position);
}


/* ------------------------------------------------------------------------- */

void vdrive_command_set_error(vdrive_t *vdrive, int code, unsigned int track,
                              unsigned int sector)
{
    const char *message = "";
    static int last_code;
    bufferinfo_t *p = &vdrive->buffers[15];

#ifdef DEBUG_DRIVE
    log_debug("Set error channel: code =%d, last_code =%d, track =%d, "
              "sector =%d.", code, last_code, track, sector);
#endif

    /* Only set an error once per command */
    if (code != CBMDOS_IPE_OK && last_code != CBMDOS_IPE_OK)
        return;

    last_code = code;

    if (code != CBMDOS_IPE_MEMORY_READ) {
        message = cbmdos_errortext(code);

        sprintf((char *)p->buffer, "%02d,%s,%02d,%02d\015",
                code == CBMDOS_IPE_DELETED ? vdrive->deleted_files : code,
                message, track, sector);

        /* Length points to the last byte, and doesn't give the length.  */
        p->length = (unsigned int)strlen((char *)p->buffer) - 1;
    } else {
        memcpy((char *)p->buffer, vdrive->mem_buf, vdrive->mem_length);
        p->length = vdrive->mem_length - 1;
        message = "MEMORY READ";
    }
    p->bufptr = 0;

    if (code && code != CBMDOS_IPE_DOS_VERSION
        && code != CBMDOS_IPE_MEMORY_READ) {
        log_message(vdrive_command_log, "ERR = %02d, %s, %02d, %02d",
                    code == CBMDOS_IPE_DELETED ? vdrive->deleted_files : code,
                    message, track, sector);
    }

    p->readmode = CBMDOS_FAM_READ;
}

/* FIXME: incomplete */
int vdrive_command_memory_write(vdrive_t *vdrive, const BYTE *buf, WORD addr, unsigned int length)
{
    unsigned int len = buf[0];
    log_message(vdrive_command_log, "Warning - M-W %04x %02x (+%02x) (may need TDE)", addr, len, length - 6);
#if 0
        if (length < 5)
            return CBMDOS_IPE_SYNTAX;
        count = buffer[3];
        /* data= buffer[4 ... 4+34]; */

        if (vdrive->buffers[addrlo].mode != BUFFER_MEMORY_BUFFER) {
            return CBMDOS_IPE_SYNTAX;
        memcpy ( ... , buffer + 4, buffer[3]);
        }
#endif
    return CBMDOS_IPE_OK;
}

int vdrive_command_memory_exec(vdrive_t *vdrive, const BYTE *buf, WORD addr, unsigned int length)
{
    log_message(vdrive_command_log, "Warning - M-E %04x (+%02x) (needs TDE)", addr, length - 5);
    return CBMDOS_IPE_OK;
}

/*
    FIXME: machine_drive_rom_read will always return $00 right now, because appearently the
           floppy roms are not loaded when truedrive emulation is disabled.
           this is not really critical, as it rarely makes sense to return the floppy rom on
           memory reads anyway - the more common (and useful) case is to return zeros, or
           whatever else that will make programs notice that they are NOT talking to a drive
           they "know", so they can eg disable their fastloader.
           for this reason, when fixing this, make sure to make it optional!
*/
int vdrive_command_memory_read(vdrive_t *vdrive, const BYTE *buf, WORD addr, unsigned int length)
{
    unsigned int len = buf[0];
    unsigned int i;
    BYTE val;

    log_message(vdrive_command_log, "Warning - M-R %04x %02x (+%02x) (may need TDE)", addr, len, length - 6);

    if (len == 0 || len > IP_MAX_COMMAND_LEN) {
        len = IP_MAX_COMMAND_LEN;
    }

    for (i = 0; i < len; i++) {
        val = 0;

        if (addr >= 0x8000) {
            switch (vdrive->image_format) {
              case VDRIVE_IMAGE_FORMAT_2040:
                if (machine_drive_rom_read(2040, addr, &val) < 0) {
                    val = 0x55;
                }
                break;
              case VDRIVE_IMAGE_FORMAT_1541:
                if (machine_drive_rom_read(1541, addr, &val) < 0) {
                    val = 0x55;
                }
                break;
              case VDRIVE_IMAGE_FORMAT_1571:
                if (machine_drive_rom_read(1571, addr, &val) < 0) {
                    val = 0x55;
                }
                break;
              case VDRIVE_IMAGE_FORMAT_1581:
                if (machine_drive_rom_read(1581, addr, &val) < 0) {
                    val = 0x55;
                }
                break;
              case VDRIVE_IMAGE_FORMAT_8050:
              case VDRIVE_IMAGE_FORMAT_8250:
                if (machine_drive_rom_read(1001, addr, &val) < 0) {
                    val = 0x55;
                }
                break;
            }
        }
        addr++;

        vdrive->mem_buf[i] = val;
    }

    vdrive->mem_length = len;
    return CBMDOS_IPE_MEMORY_READ;
}

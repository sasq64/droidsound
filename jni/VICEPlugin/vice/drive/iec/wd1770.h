/*
 * wd1770.h - WD1770 emulation for the 1571 and 1581 disk drives.
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

#ifndef VICE_WD1770_H
#define VICE_WD1770_H

#include "types.h"

struct disk_image_s;

#define WD1770_BUFFER_SIZE (680 * 10)

typedef struct wd1770_s {
    /* WD1770 register.  */
    BYTE reg[4];

    /* Command type */
    unsigned int type;

    /* Busy bit clock counter.  */
    CLOCK busy_clk;

    /* Busy?  */
    unsigned int busy;

    /* Clock counter to control motor spinup.  */
    CLOCK motor_spinup_clk;

    /* Motor on flag */
    unsigned int motor;

    /* Motor on flag */
    unsigned int motor_ready;

    /* Record not found flag.  */
    unsigned int record_not_found;

    /* Current track of the r/w head.  */
    unsigned int track;

    /* Current disk side.  */
    unsigned int side;

    /* Data register buffer index, can be -1.  */
    int data_buffer_index, data_buffer_offset;

    /* WP bit status.  */
    unsigned int wp_status;

    /* Index pulse count */
    unsigned int index_count;

    /* Write command pending */
    unsigned int write_pending;

    /* LED delay.  */
    CLOCK led_delay_clk;

    /* Interrupt line.  */
    CLOCK set_drq;

    /* Set to drive clock if a disk image is attached.  */
    CLOCK attach_clk;

    /* Pointer to the disk image.  */
    struct disk_image_s *image;

    /* Data register buffer.  */
    BYTE data_buffer[WD1770_BUFFER_SIZE];
} wd1770_t;

extern wd1770_t wd1770[];

struct drive_context_s;

extern void wd1770d_init(struct drive_context_s *drv);
extern void wd1770d_store(struct drive_context_s *drv, WORD addr,
                                   BYTE byte);
extern BYTE wd1770d_read(struct drive_context_s *drv, WORD addr);
extern void wd1770d_reset(struct drive_context_s *drv);

extern void wd1770_handle_job_code(unsigned int dnr);
extern void wd1770_vsync_hook(void);

extern int wd1770_attach_image(struct disk_image_s *image, unsigned int unit);
extern int wd1770_detach_image(struct disk_image_s *image, unsigned int unit);
extern int wd1770_disk_change(struct drive_context_s *drive_context);

#endif 


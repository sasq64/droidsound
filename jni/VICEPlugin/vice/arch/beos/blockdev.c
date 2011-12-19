/*
 * blockdev.c
 *
 * Written by
 *  Andreas Matthies <andreas.matthies@gmx.net>
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

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "blockdev.h"
#include "log.h"
#include "types.h"


/*static log_t blockdev_log = LOG_DEFAULT;*/

int blockdev_open(const char *name, unsigned int *read_only)
{
    return -1;
}

int blockdev_close(void)
{
    return -1;
}

/*-----------------------------------------------------------------------*/

int blockdev_read_sector(BYTE *buf, unsigned int track, unsigned int sector)
{
    return -1;
}

int blockdev_write_sector(BYTE *buf, unsigned int track, unsigned int sector)
{
    return -1;
}

/*-----------------------------------------------------------------------*/

void blockdev_init(void)
{
}

int blockdev_resources_init()
{
    return 0;
}

int blockdev_cmdline_options_init()
{
    return 0;
}

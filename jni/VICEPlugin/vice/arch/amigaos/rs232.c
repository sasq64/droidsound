/*
 * rs232.h - RS232 emulation.
 *
 * Written by
 *  Andr� Fachat <a.fachat@physik.tu-chemnitz.de>
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

/*
 * This is the header for the RS232 emulation.
 *
 * The RS232 emulation captures the bytes sent to the RS232 interfaces
 * available (currently only ACIA 6551, later UART 16550A, std C64,
 * and Daniel Dallmanns fast RS232 with 9600 Baud).
 * The characters captured are displayed in a special terminal window.
 * Characters typed in the terminal window are sent back to the
 * chip emulations.
 */

#include <stdio.h>
#include "rs232drv/rs232.h"

/* Initializes all RS232 stuff */
void rs232_init(void)
{
}

/* Reset for RS232 interfaces */
void rs232_reset(void)
{
}

/* Opens a rs232 window, returns handle to give to functions below. */
int rs232_open(int device)
{
    return -1;
}

/* Closes the rs232 window again */
void rs232_close(int fd)
{
}

/* Sends a byte to the RS232 line */
int rs232_putc(int fd, BYTE b)
{
    return 0;
}

/* Gets a byte to the RS232 line, returns !=1 if byte received, byte in *b. */
int rs232_getc(int fd, BYTE *b)
{
    return 0;
}

/* set the status lines of the RS232 device */
int rs232_set_status(int fd, enum rs232handshake_out status)
{
    return -1;
}

/* get the status lines of the RS232 device */
enum rs232handshake_in rs232_get_status(int fd)
{
    /*! \todo dummy */
    return RS232_HSI_CTS | RS232_HSI_DSR;
}

/* set the bps rate of the physical device */
void rs232_set_bps(int fd, unsigned int bps)
{
}

int rs232_resources_init(void)
{
    return 0;
}

void rs232_resources_shutdown(void)
{
}

int rs232_cmdline_options_init(void)
{
    return 0;
}

#include <stdlib.h>
#include "iecbus.h"

BYTE (*iecbus_callback_read)(CLOCK) = NULL;
void (*iecbus_callback_write)(BYTE, CLOCK) = NULL;
void (*iecbus_update_ports)(void) = NULL;

iecbus_t iecbus;

void debug_iec_drv_write(unsigned int data)
{
}

void debug_iec_drv_read(unsigned int data)
{
}

void debug_iec_bus_write(unsigned int data)
{
}

void debug_iec_bus_read(unsigned int data)
{
}

void iecbus_init(void)
{
    memset(&iecbus, 0xff, sizeof(iecbus_t));
    iecbus.drv_port = IECBUS_DEVICE_READ_DATA
                      | IECBUS_DEVICE_READ_CLK
                      | IECBUS_DEVICE_READ_ATN;
}

void iecbus_cpu_undump(BYTE data)
{
    iec_update_cpu_bus(data);
}

/* No drive is enabled.  */
static BYTE iecbus_cpu_read_conf0(CLOCK clock)
{
    return (iecbus.iec_fast_1541 & 0x30u) << 2;
}

static void iecbus_cpu_write_conf0(BYTE data, CLOCK clock)
{
    iecbus.iec_fast_1541 = data;
}

static void calculate_callback_index(void)
{
    iecbus_callback_read = iecbus_cpu_read_conf0;
    iecbus_callback_write = iecbus_cpu_write_conf0;
}

void iecbus_status_set(unsigned int type, unsigned int unit,
                       unsigned int enable)
{
   calculate_callback_index();
}


BYTE iecbus_device_read(void)
{
  return iecbus.drv_port;
}


int iecbus_device_write(unsigned int unit, BYTE data)
{
  return 0;
}

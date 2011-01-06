#include "vice.h"

#include "c64parallel.h"

void parallel_cable_drive_write(BYTE data, int handshake, unsigned int dnr)
{
}

BYTE parallel_cable_drive_read(int handshake)
{
    return 0xff;
}

void parallel_cable_cpu_execute(void)
{
}

void parallel_cable_cpu_write(BYTE data)
{
}

BYTE parallel_cable_cpu_read(void)
{
    return 0xff;
}

void parallel_cable_cpu_pulse(void)
{
}

void parallel_cable_cpu_undump(BYTE data)
{
}

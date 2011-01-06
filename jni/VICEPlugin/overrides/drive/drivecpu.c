#include <stdlib.h>
#include "drivetypes.h"
#include "drivecpu.h"
#include "monitor.h"
#include "snapshot.h"

monitor_interface_t *drivecpu_monitor_interface_get(unsigned int dnr)
{
    return NULL;
}

void drivecpu_setup_context(struct drive_context_s *drv)
{
}

void drivecpu_reset_clk(drive_context_t *drv)
{
}

void drivecpu_reset(drive_context_t *drv)
{
}

void drivecpu_trigger_reset(unsigned int dnr)
{
}

static void drive_cpu_early_init(drive_context_t *drv)
{
}

void drivecpu_early_init_all(void)
{
}

void drivecpu_shutdown(drive_context_t *drv)
{
}

void drivecpu_init(drive_context_t *drv, int type)
{
}

void drivecpu_prevent_clk_overflow_all(CLOCK sub)
{
}

void drivecpu_execute(drive_context_t *drv, CLOCK clk_value)
{
}

void drivecpu_execute_all(CLOCK clk_value)
{
}

int drivecpu_snapshot_write_module(drive_context_t *drv, snapshot_t *s)
{
    return 0;
}

int drivecpu_snapshot_read_module(drive_context_t *drv, snapshot_t *s)
{
    return 0;
}


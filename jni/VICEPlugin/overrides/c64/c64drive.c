#include "drive.h"
#include "snapshot.h"

int machine_drive_resources_init(void)
{
    return 0;
}

void machine_drive_resources_shutdown(void)
{
}

int machine_drive_cmdline_options_init(void)
{
    return 0;
}

void machine_drive_init(struct drive_context_s *drv)
{
}

void machine_drive_shutdown(struct drive_context_s *drv)
{
}

void machine_drive_reset(struct drive_context_s *drv)
{
}

void machine_drive_mem_init(struct drive_context_s *drv, unsigned int type)
{
}

void machine_drive_setup_context(struct drive_context_s *drv)
{
}

void machine_drive_idling_method(unsigned int dnr)
{
}

void machine_drive_vsync_hook(void)
{
}

void machine_drive_rom_load(void)
{
}

void machine_drive_rom_setup_image(unsigned int dnr)
{
}

int machine_drive_rom_read(unsigned int type, WORD addr, BYTE *data)
{
    return 0;
}

int machine_drive_rom_check_loaded(unsigned int type)
{
    return 0;
}

void machine_drive_rom_do_checksum(unsigned int dnr)
{
}

int machine_drive_snapshot_read(struct drive_context_s *ctxptr, struct snapshot_s *s)
{
    return 0;
}

int machine_drive_snapshot_write(struct drive_context_s *ctxptr, struct snapshot_s *s)
{
    return 0;
}

int machine_drive_image_attach(struct disk_image_s *image, unsigned int unit)
{
    return -1;
}

int machine_drive_image_detach(struct disk_image_s *image, unsigned int unit)
{
    return -1;
}

void machine_drive_port_default(struct drive_context_s *drv)
{
}

void machine_drive_flush(void)
{
}

void machine_drive_stub(void)
{
}

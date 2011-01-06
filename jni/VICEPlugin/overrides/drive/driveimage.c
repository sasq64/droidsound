#include "diskimage.h"
#include "drive.h"
#include "driveimage.h"

void drive_image_init_track_size_d64(drive_t *drive)
{
}

/* Attach a disk image to the true drive emulation. */
int drive_image_attach(disk_image_t *image, unsigned int unit)
{
    return -1;
}

/* Detach a disk image from the true drive emulation. */
int drive_image_detach(disk_image_t *image, unsigned int unit)
{
    return -1;
}

void drive_image_init(void)
{
}

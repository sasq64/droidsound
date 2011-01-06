#include <stdlib.h>
#include "gfxoutput.h"

int gfxoutput_resources_init(void) { return 0; }
int gfxoutput_cmdline_options_init(void) { return 0; }
int gfxoutput_early_init(void) { return 0; }
int gfxoutput_init(void) { return 0; }
void gfxoutput_shutdown(void) {}
int gfxoutput_num_drivers(void) { return 0; }
gfxoutputdrv_t *gfxoutput_drivers_iter_init(void) { return NULL; }
gfxoutputdrv_t *gfxoutput_drivers_iter_next(void) { return NULL; }
gfxoutputdrv_t *gfxoutput_get_driver(const char *drvname) { return NULL; }
int gfxoutput_register(gfxoutputdrv_t *drv) { return 0; }
void gfxoutput_init_gif(void) {}

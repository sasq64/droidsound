#include "fsdevice.h"

int fsdevice_cmdline_options_init(void) { return 0; }
int fsdevice_resources_init(void) { return 0; }
void fsdevice_resources_shutdown(void) {}

void fsdevice_init(void) {}
void fsdevice_shutdown(void) {}

int fsdevice_attach(unsigned int device, const char *name) { return 0; }
void fsdevice_set_directory(char *filename, unsigned int unit) {}

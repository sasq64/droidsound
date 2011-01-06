#include <stdlib.h>
#include "printer.h"

/* Generic interface.  */
int printer_resources_init(void) { return 0; }
void printer_resources_shutdown(void) {}
int printer_cmdline_options_init(void) { return 0; }
void printer_init(void) {}
void printer_reset(void) {}
void printer_formfeed(unsigned int unit) {}
void printer_shutdown(void) {}

int printer_serial_init_resources(void) { return 0; }
int printer_serial_init_cmdline_options(void) { return 0; }
void printer_serial_init(void) {}
int printer_serial_close(unsigned int unit) { return 0; }
int printer_serial_late_init(void) { return 0; }
void printer_serial_shutdown(void) {}

/* Userport interface.  */
int printer_userport_init_resources(void) { return 0; }
int printer_userport_init_cmdline_options(void) { return 0; }
void printer_userport_init(void (*set_busy)(unsigned int)) {}
void printer_userport_write_data(BYTE b) {}
void printer_userport_write_strobe(int s) {}

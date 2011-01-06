#include "parallel.h"
#include "types.h"

int parallel_debug;
void parallel_bus_enable(int enable) {}
void parallel_trap_eof_callback_set(void (*func)(void)) {}
void parallel_trap_attention_callback_set(void (*func)(void)) {}
BYTE parallel_eoi;
BYTE parallel_ndac;
BYTE parallel_nrfd;
BYTE parallel_dav;
BYTE parallel_atn;
BYTE parallel_bus;       /* data lines */
void parallel_set_eoi(BYTE mask) {}
void parallel_set_ndac(BYTE mask) {}
void parallel_set_nrfd(BYTE mask) {}
void parallel_set_dav(BYTE mask) {}
void parallel_set_atn(BYTE mask) {}
void parallel_restore_set_atn(BYTE mask) {}
void parallel_clr_eoi(BYTE mask) {}
void parallel_clr_ndac(BYTE mask) {}
void parallel_clr_nrfd(BYTE mask) {}
void parallel_clr_dav(BYTE mask) {}
void parallel_clr_atn(BYTE mask) {}
void parallel_restore_clr_atn(BYTE mask) {}
void parallel_emu_set_bus(BYTE b) {}
void parallel_cpu_set_atn(char val) {}
void parallel_cpu_set_bus(BYTE b) {}
void parallel_drv0_set_bus(BYTE b) {}
void parallel_drv1_set_bus(BYTE b) {}

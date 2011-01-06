#include <stdlib.h>
#include "drive.h"
#include "drivetypes.h"

drive_context_t *drive_context[DRIVE_NUM];

int drive_init(void) { return 0; }
int drive_enable(struct drive_context_s *drv) { return 0; }
void drive_disable(struct drive_context_s *drv) {}
void drive_move_head(int step, struct drive_s *drive) {}
void drive_reset(void) {}
void drive_shutdown(void) {}
void drive_vsync_hook(void) {}
void drive_update_ui_status(void) {}
void drive_gcr_data_writeback(struct drive_s *drive) {}
void drive_gcr_data_writeback_all(void) {}
void drive_set_active_led_color(unsigned int type, unsigned int dnr) {}
int drive_set_disk_drive_type(unsigned int drive_type, struct drive_context_s *drv) { return 0; }

void drive_set_half_track(int num, drive_t *dptr) {}
void drive_current_track_size_set(drive_t *dptr) {}
void drive_set_machine_parameter(long cycles_per_sec) {}
void drive_set_disk_memory(BYTE *id, unsigned int track, unsigned int sector, struct drive_context_s *drv) {}
void drive_set_last_read(unsigned int track, unsigned int sector, BYTE *buffer, struct drive_context_s *drv) {}
int drive_check_type(unsigned int drive_type, unsigned int dnr) { return 0; }
int drive_check_expansion(int drive_type) { return 0; }
int drive_check_expansion2000(int drive_type) { return 0; }
int drive_check_expansion4000(int drive_type) { return 0; }
int drive_check_expansion6000(int drive_type) { return 0; }
int drive_check_expansion8000(int drive_type) { return 0; }
int drive_check_expansionA000(int drive_type) { return 0; }
int drive_check_parallel_cable(int drive_type) { return 0; }
int drive_check_extend_policy(int drive_type) { return 0; }
int drive_check_idle_method(int drive_type) { return 0; }
int drive_check_profdos(int drive_type) { return 0; }
int drive_num_leds(unsigned int dnr) { return 0; }
void drive_setup_context(void) {}
int drive_resources_type_init(unsigned int default_type) { return 0; }

#include <stdlib.h>
#include "tape.h"

tape_image_t *tape_image_dev1;

int tape_init(const tape_init_t *init) { return 0; }
int tape_reinit(const tape_init_t *init) { return 0; }
void tape_shutdown(void) {}
int tape_deinstall(void) { return 0; }
void tape_get_header(tape_image_t *tape_image, BYTE *name) {}
int tape_find_header_trap(void) { return 0; }
int tape_receive_trap(void) { return 0; }
int tape_find_header_trap_plus4(void) { return 0; }
int tape_receive_trap_plus4(void) { return 0; }
const char *tape_get_file_name(void);
int tape_tap_attched(void) { return 0; }
void tape_traps_install(void) {}
void tape_traps_deinstall(void) {}
tape_file_record_t *tape_get_current_file_record(tape_image_t *tape_image) { return NULL; }
int tape_seek_start(tape_image_t *tape_image) { return 0; }
int tape_seek_to_file(tape_image_t *tape_image, unsigned int file_number) { return 0; }
int tape_seek_to_next_file(tape_image_t *tape_image, unsigned int allow_rewind) { return 0; }
int tape_read(tape_image_t *tape_image, BYTE *buf, size_t size) { return 0; }
int tape_internal_close_tape_image(tape_image_t *tape_image) { return 0; }
tape_image_t *tape_internal_open_tape_image(const char *name, unsigned int read_only) { return NULL; }
int tape_image_detach(unsigned int unit) { return 0; }
int tape_image_detach_internal(unsigned int unit) { return 0; }
int tape_image_attach(unsigned int unit, const char *name) { return 0; }
int tape_image_open(tape_image_t *tape_image) { return 0; }
int tape_image_close(tape_image_t *tape_image);
int tape_image_create(const char *name, unsigned int type) { return 0; }
void tape_image_event_playback(unsigned int unit, const char *filename) {}

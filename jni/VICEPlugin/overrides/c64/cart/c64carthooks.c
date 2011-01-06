#include <stdlib.h>
#include "c64.h"
#include "cartridge.h"
#include "snapshot.h"

int cart_cmdline_options_init(void)
{
    return 0;
}

/* ------------------------------------------------------------------------- */
/*
    resource init and de-init
    - every cart that has an _init hook should also have a _shutdown hook!
*/
int cart_resources_init(void)
{
    return 0;
}

void cart_resources_shutdown(void)
{
}

int cart_is_slotmain(int type)
{
   return 0;
}

int cart_getid_slot0(void)
{
    return CARTRIDGE_NONE;
}

int cart_getid_slot1(void)
{
    return CARTRIDGE_NONE;
}

int cart_type_enabled(int type)
{
    return 0;
}

const char *cart_get_file_name(int type)
{
    return "";
}

void cartridge_setup_context(machine_context_t *machine_context)
{
}

/* ------------------------------------------------------------------------- */

int cart_bin_attach(int type, const char *filename, BYTE *rawcart)
{
    return -1;
}

void cart_attach(int type, BYTE *rawcart)
{
}

void cart_detach_conflicts0(int *list, int type)
{
}

void cart_detach_conflicting(int type)
{
}

/*
    attach a cartridge without setting an image name
*/
int cartridge_enable(int type)
{
    return -1;
}

void cart_detach_all(void)
{
}

void cart_detach(int type)
{
}

/* called once by cartridge_init at machine init */
void cart_init(void)
{
}

void cartridge_ram_init(void)
{
}

void cartridge_shutdown(void)
{
}

void cartridge_init_config(void)
{
}

void cartridge_reset(void)
{
}

void cart_freeze(int type)
{
}

void cart_nmi_alarm(CLOCK offset, void *data)
{
}

int cart_freeze_allowed(void)
{
    return 0;
}

int cartridge_flush_image(int type)
{
    return -1;
}

int cartridge_bin_save(int type, const char *filename)
{
    return -1;
}

int cartridge_crt_save(int type, const char *filename)
{
    return -1;
}

int cartridge_snapshot_write_modules(struct snapshot_s *s)
{
    return 0;
}

int cartridge_snapshot_read_modules(struct snapshot_s *s)
{
    return 0;
}


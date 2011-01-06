#include <stdlib.h>
#include "reu.h"
#include "snapshot.h"

int reu_cart_enabled(void)
{
    return 0;
}

int reu_resources_init(void)
{
    return 0;
}

/*! \brief uninitialize the reu resources */
void reu_resources_shutdown(void)
{
}

int reu_cmdline_options_init(void)
{
    return 0;
}

const char *reu_get_file_name(void)
{
    return NULL;
}

void reu_init(void)
{
}

void reu_config_setup(BYTE *rawcart)
{
}

/*! \brief register the BA low interface */
void reu_ba_register(reu_ba_check_callback_t *ba_check,
                     reu_ba_steal_callback_t *ba_steal,
                     int *ba_var, int ba_mask)
{
}

void reu_reset(void)
{
}

void reu_detach(void)
{
}

int reu_enable(void)
{
    return 0;
}

int reu_bin_attach(const char *filename, BYTE *rawcart)
{
    return -1;
}

int reu_bin_save(const char *filename)
{
    return -1;
}

int reu_flush_image(void)
{
    return 0;
}

void reu_dma(int immediate)
{
}

void reu_dma_start(void)
{
}

int reu_write_snapshot_module(snapshot_t *s)
{
    return 0;
}

/*! \brief read the REU module data from the snapshot
 \param s
    The snapshot data from where to read the information for this module.

 \return
    0 on success, else -1.
 */
int reu_read_snapshot_module(snapshot_t *s)
{
    return 0;
}

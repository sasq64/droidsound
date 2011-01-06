#include "datasette.h"
#include "tap.h"
#include "snapshot.h"

int datasette_resources_init(void)
{
    return 0;
}

int datasette_cmdline_options_init(void)
{
    return 0;
}

void datasette_reset_counter(void)
{
}

void datasette_init(void)
{
}

void datasette_set_tape_image(tap_t *image)
{
}

void datasette_reset(void)
{
}

void datasette_event_playback(CLOCK offset, void *data)
{
}

void datasette_control(int command)
{
}

void datasette_set_motor(int flag)
{
}

void datasette_toggle_write_bit(int write_bit)
{
}

int datasette_write_snapshot(snapshot_t *s)
{
}

int datasette_read_snapshot(snapshot_t *s)
{
}

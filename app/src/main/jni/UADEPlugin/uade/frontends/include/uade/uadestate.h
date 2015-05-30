#ifndef _UADE_STATE_H_
#define _UADE_STATE_H_

#include <sys/types.h>
#include <unistd.h>

#include <uade/eagleplayer.h>
#include <uade/effects.h>
#include <uade/uadeipc.h>
#include <uade/songdb.h>

struct uade_state {
	/* Per song members */
	struct uade_config config;
	struct uade_song *song;
	struct uade_effect effects;
	struct eagleplayer *ep;

	/* Permanent members */
	int validconfig;
    struct uade_config permconfig;
	struct eagleplayerstore *playerstore;
	struct uade_ipc ipc;
	pid_t pid;
    struct uade_songdb songdb;
};

#endif

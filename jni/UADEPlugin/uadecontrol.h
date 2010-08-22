#ifndef _UADE_CONTROL_
#define _UADE_CONTROL_

#include <uadeipc.h>

#include <sys/types.h>

enum {
  UADECORE_INIT_OK = 0,
  UADECORE_INIT_ERROR,
  UADECORE_CANT_PLAY
};

void uade_change_subsong(int subsong, struct uade_ipc *ipc);
int uade_read_request(struct uade_ipc *ipc);
void uade_send_filter_command(int filter_type, int filter_state,
			      int force_filter, struct uade_ipc *ipc);
void uade_send_interpolation_command(const char *mode, struct uade_ipc *ipc);
void uade_set_subsong(int subsong, struct uade_ipc *ipc);
int uade_song_initialization(const char *scorename,
			     const char *playername,
			     const char *modulename,
			     struct uade_ipc *ipc);
void uade_spawn(struct uade_ipc *ipc, pid_t *uadepid, const char *uadename,
		const char *configname, int debug_mode);

#endif

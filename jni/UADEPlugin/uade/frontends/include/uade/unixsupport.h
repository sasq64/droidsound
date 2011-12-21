#ifndef _UADE_UNIXSUPPORT_H_
#define _UADE_UNIXSUPPORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <uade/uadeipc.h>

#define uade_debug(state, fmt, args...) do { if ((state) == NULL || (state)->config.verbose) { fprintf(stderr, fmt, ## args); } } while (0)
#define uade_die(fmt, args...) do { fprintf(stderr, "uade: " fmt, ## args); exit(1); } while(0)
#define uade_die_error(fmt, args...) do { fprintf(stderr, "uade: " fmt ": %s\n", ## args, strerror(errno)); exit(1); } while(0)
#define uade_error(fmt, args...) do { \
    fprintf(stderr, "%s:%d: %s: " fmt, __FILE__, __LINE__, __func__, ## args); \
    abort(); \
  } while (0)
#define uade_warning(fmt, args...) do { fprintf(stderr, "uade warning: " fmt, ## args); } while(0)

char *uade_dirname(char *dst, char *src, size_t maxlen);
int uade_find_amiga_file(char *realname, size_t maxlen, const char *aname, const char *playerdir);

void uade_arch_kill_and_wait_uadecore(struct uade_ipc *ipc, pid_t *uadepid);
int uade_arch_spawn(struct uade_ipc *ipc, pid_t *uadepid, const char *uadename);

int uade_filesize(size_t *size, const char *pathname);

int uade_ipc_get_fd(void *f);

void *uade_ipc_set_input(const char *input);
void *uade_ipc_set_output(const char *output);

char *uade_windows_to_cygwin_path(const char *path);

#endif

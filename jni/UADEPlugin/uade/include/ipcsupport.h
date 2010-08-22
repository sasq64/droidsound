#ifndef _IPC_SUPPORT_H_
#define _IPC_SUPPORT_H_

#include <stdlib.h>
#include <stdio.h>

/* These read and write functions MUST read and write the full size_t amount
   if they are able to. */
ssize_t uade_ipc_read(void *f, const void *buf, size_t count);
ssize_t uade_ipc_write(void *f, const void *buf, size_t count);
void *uade_ipc_set_input(const char *input);
void *uade_ipc_set_output(const char *output);

#endif

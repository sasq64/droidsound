#ifndef _UNIXATOMIC_H_
#define _UNIXATOMIC_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int atomic_close(int fd);
int atomic_dup2(int oldfd, int newfd);
ssize_t atomic_read(int fd, const void *buf, size_t count);
ssize_t atomic_write(int fd, const void *buf, size_t count);

#endif

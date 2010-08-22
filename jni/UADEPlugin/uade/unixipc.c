#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <ipcsupport.h>
#include <unixatomic.h>


static int url_to_fd(const char *url, int flags, mode_t mode)
{
  int fd;
  if (strncmp(url, "fd://", 5) == 0) {
    char *endptr;
    if (url[5] == 0)
      return -1;
    fd = strtol(&url[5], &endptr, 10);
    if (*endptr != 0)
      return -1;
  } else {
    if (flags & O_WRONLY) {
      fd = open(url, flags, mode);
    } else {
      fd = open(url, flags);
    }
  }
  if (fd < 0)
    fd = -1;
  return fd;
}


/* This must read the full size_t count if it can, and therefore we use
   atomic_read() */
ssize_t uade_ipc_read(void *f, const void *buf, size_t count)
{
  int fd = (intptr_t) f;
  return atomic_read(fd, buf, count);
}


/* This must write the full size_t count if it can, and therefore we use
   atomic_write() */
ssize_t uade_ipc_write(void *f, const void *buf, size_t count)
{
  int fd = (intptr_t) f;
  return atomic_write(fd, buf, count);
}


void *uade_ipc_set_input(const char *input)
{
  int fd;
  if ((fd = url_to_fd(input, O_RDONLY, 0)) < 0) {
    fprintf(stderr, "can not open input file %s: %s\n", input, strerror(errno));
    exit(-1);
  }
  return (void *) ((intptr_t) fd);
}


void *uade_ipc_set_output(const char *output)
{
  int fd;
  if ((fd = url_to_fd(output, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
    fprintf(stderr, "can not open output file %s: %s\n", output, strerror(errno));
    exit(-1);
  }
  return (void *) ((intptr_t) fd);
}

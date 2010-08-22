#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <sys/select.h>

#include "uade123.h"

static struct termios old_terminal;


static void uade_restore_terminal(void)
{
  tcsetattr(0, TCSANOW, &old_terminal);
}


void pause_terminal(void)
{
  char c;
  int ret;
  fd_set rfds;
  tprintf("\nPaused. Press any key to continue...\n");
  while (uade_terminated == 0) {
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    ret = select(1, &rfds, NULL, NULL, NULL);
    if (ret < 0) {
      if (errno == EINTR)
	continue;
      perror("\nuade123: poll error");
      exit(-1);
    }
    if (ret == 0)
      continue;
    ret = read(0, &c, 1);
    if (ret < 0) {
      if (errno == EINTR || errno == EAGAIN)
	continue;
    }
    break;
  }
  tprintf("\n");
}


int poll_terminal(void)
{
  fd_set rfds;
  char c = 0;
  int ret;

  FD_ZERO(&rfds);
  FD_SET(0, &rfds);
  ret = select(1, &rfds, NULL, NULL, & (struct timeval) {.tv_sec = 0});

  if (ret > 0) {
    ret = read(0, &c, 1);
    if (ret <= 0)
      c = 0;
  }
  return c;
}


void setup_terminal(void)
{
  struct termios tp;
  if (tcgetattr(0, &old_terminal)) {
    perror("uade123: can't setup interactive mode");
    exit(-1);
  }
  atexit(uade_restore_terminal);
  tp = old_terminal;
  tp.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL);
  if (tcsetattr(0, TCSAFLUSH, &tp)) {
    perror("uade123: can't setup interactive mode (tcsetattr())");
    exit(-1);
  }
}

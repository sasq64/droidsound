#ifndef _UADE_UNIXSUPPORT_H_
#define _UADE_UNIXSUPPORT_H_

#include <stdio.h>

char *uade_dirname(char *dst, char *src, size_t maxlen);
FILE *uade_open_amiga_file(char *aname, const char *playerdir);
void uade_portable_initializations(void);

#endif

#ifndef _UADE_SUPPORT_H_
#define _UADE_SUPPORT_H_

#include <stdio.h>

#define UADE_LINESIZE 1024

char *uade_xbasename(const char *path);
int uade_get_two_ws_separated_fields(char **key, char **value, char *s);
char **uade_read_and_split_lines(size_t *nitems, size_t *lineno, FILE *f, const char *delim);
int uade_skip_and_terminate_word(char *s, int i);

/* Same as fgets(), but guarantees that feof() or ferror() has happened
   when xfgets() returns NULL */
char *uade_xfgets(char *s, int size, FILE *stream);

#endif

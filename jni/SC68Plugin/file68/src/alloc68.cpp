/*
 * @file    alloc68.c
 * @brief   memory management
 * @author  http://sourceforge.net/users/benjihan
 *
 * Copyright (C) 2001-2011 Benjamin Gerard
 *
 * Time-stamp: <2011-10-02 16:04:28 ben>
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "file68_api.h"
#include "alloc68.h"
#include "error68.h"

#ifdef HAVE_STDLIB_H
# include <stdlib.h>
#endif
#ifdef HAVE_STRING_H
# include <string.h>
#endif

/* Default malloc. */
#if defined(HAVE_MALLOC) && !defined(DEFAULT_MALLOC)
# define DEFAULT_MALLOC malloc_uint
static void * malloc_uint(unsigned int sz)
{
  return malloc((size_t)sz);
}
#elif !defined(DEFAULT_MALLOC)
# define DEFAULT_MALLOC 0
#endif
static alloc68_t alloc_f = DEFAULT_MALLOC;

/* Default free. */
# if defined(HAVE_FREE) && !defined(DEFAULT_FREE)
# define DEFAULT_FREE free
#elif !defined(DEFAULT_FREE)
# define DEFAULT_FREE   0
#endif
static free68_t  free_f  = DEFAULT_FREE;

/** Allocate dynamic memory. */
void * alloc68(unsigned int n)
{
  return !alloc_f
    ? 0
    : alloc_f(n);
}

/** Allocate and clean buffer ($$$ OPTIMIZE ME) */
void * calloc68(unsigned int n)
{
  void * buffer = alloc68(n);
  if (buffer) {
#ifdef HAVE_STRING_H
    memset(buffer,0,n);
#else
    char * b = buffer;
    while (n--) {
      *b++ = 0;
    }
#endif
  }
  return buffer;
}

/** Free dynamic memory. */
void free68(void * data)
{
  if (data && free_f) {
    free_f(data);
  }
}

/** Set/get dynamic memory allocation handler. */
alloc68_t alloc68_set(alloc68_t alloc)
{
  alloc68_t old = alloc_f;

  if (alloc) {
    alloc_f = alloc;
  }
  return old;
}

/** Set/get dynamic memory free handler. */
free68_t free68_set(free68_t free)
{
  free68_t old = free_f;

  if (free) {
    free_f = free;
  }
  return old;
}

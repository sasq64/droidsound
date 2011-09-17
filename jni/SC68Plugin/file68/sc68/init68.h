/**
 * @ingroup  file68_lib
 * @file     sc68/init68.h
 * @author   Benjamin Gerard
 * @date     2003-09-26
 * @brief    Initialization.
 *
 */

/* $Id$ */

/* Copyright (C) 1998-2009 Benjamin Gerard */

#ifndef _FILE68_INIT68_H_
#define _FILE68_INIT68_H_

#ifndef FILE68_API
# include "file68_api.h"
#endif

/** @addtogroup  file68_lib
 *  @{
 */

FILE68_API
/** Initialize file68 library.
 *
 *  @param  argc  argument count
 *  @param  argv  argument array (as for main())
 *  @return new argument count
 */
int file68_init(int argc, char **argv);

FILE68_API
/** Shutdown file68 library.
 */
void file68_shutdown(void);

/**
 *  @}
 */

#endif /* #ifndef _FILE68_INIT68_H_ */

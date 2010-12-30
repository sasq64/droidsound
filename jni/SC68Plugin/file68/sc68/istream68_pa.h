/**
 * @ingroup  file68_lib
 * @file     sc68/istream68_pa.h
 * @author   Benjamin Gerard
 * @date     2007-03-08
 * @brief    PortAudio stream header.
 *
 */

/* $Id: istream68_pa.h 102 2009-03-14 17:21:58Z benjihan $ */

/* Copyright (C) 1998-2009 Benjamin Gerard */

#ifndef _FILE68_ISTREAM68_PA_H_
#define _FILE68_ISTREAM68_PA_H_

#include "istream68.h"

/** @name     PortAudio stream
 *  @ingroup  file68_istream
 *
 *    Implements istream68_t for libportaudio (audio input/output).
 *
 *  @{
 */

FILE68_EXTERN
/** Creates a stream for libportaudio.
 *
 *  @param  fname    path of file.
 *  @param  mode     bit#0 : read access, bit#1 : write access.
 *
 *  @return stream
 *  @retval 0 on error
 *
 *  @note    filename is internally copied.
 *  @warning write mode only.
 */
istream68_t * istream68_pa_create(const char * fname, int mode);

/** @} */

#endif /* #define _FILE68_ISTREAM68_PA_H_ */

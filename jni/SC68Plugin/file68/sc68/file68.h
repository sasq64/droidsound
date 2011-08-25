/**
 * @ingroup  file68_lib
 * @file     sc68/file68.h
 * @author   Benjamin Gerard
 * @date     1998-09-03
 * @brief    Music file header.
 *
 */

/* $Id: file68.h 106 2009-05-11 04:58:26Z benjihan $ */

/* Copyright (C) 1998-2009 Benjamin Gerard */

#ifndef _FILE68_FILE68_H_
#define _FILE68_FILE68_H_

#ifndef FILE68_API
# include "file68_api.h"
#endif
#include "istream68.h"

/**
 * @defgroup  file68_file  Music file manipulation
 * @ingroup   file68_lib
 *
 *  Provides various functions for sc68 file manipulation.
 *
 * @{
 */

/**
 * SC68 file identification string definition.
 * @see file68_idstr
 */
#define SC68_IDSTR "SC68 Music-file / (c) (BeN)jamin Gerard / SasHipA-Dev  "

/**
 * SC68 file identification string definition V2.
 * @see file68_idstr_v2
 */
#define SC68_IDSTR_V2 "SC68-V2"

#define SC68_NOFILENAME "N/A"  /**< SC68 unknown filename or author.        */
#define SC68_LOADADDR   0x8000 /**< Default load address in 68K memory.     */
#define SC68_MAX_TRACK  99     /**< Maximum track per disk (display rules). */


/**
 * @name  Features flag definitions for music68_t.
 * @{
 */
#define SC68_YM        1     /**< YM-2149 actif.                  */
#define SC68_STE       2     /**< STE sound actif.                */
#define SC68_AMIGA     4     /**< AMIGA sound actif.              */
#define SC68_STECHOICE 8     /**< Optionnal STF/STE (not tested). */
/**
 * @}
 */

typedef struct
{
  char id[4];   /**< Must be "SC??".            */
  char size[4]; /**< Size in bytes (MSB first). */
} chunk68_t;    /**< SC68 file chunk header.    */


/**
 * @name SC68 file chunk definitions.
 * @{
 */

#define CH68_CHUNK     "SC"    /**< Chunk identifier.            */

#define CH68_BASE      "68"    /**< Start of file.               */
#define CH68_FNAME     "FN"    /**< File name.                   */
#define CH68_DEFAULT   "DF"    /**< Default music.               */

#define CH68_MUSIC     "MU"    /**< Music section start.         */
#define CH68_MNAME     "MN"    /**< Music name.                  */
#define CH68_ANAME     "AN"    /**< Author name.                 */
#define CH68_CNAME     "CN"    /**< Composer name.               */
#define CH68_D0        "D0"    /**< D0 value.                    */
#define CH68_AT        "AT"    /**< Load address.                */
#define CH68_TIME      "TI"    /**< length in seconds.           */
#define CH68_FRAME     "FR"    /**< length in frames.            */
#define CH68_FRQ       "FQ"    /**< Main replay frequency in Hz. */
#define CH68_LOOP      "LP"    /**< Number of loop.              */

#define CH68_TYP       "TY"    /**< Not standard ST file.        */
#define CH68_IMG       "IM"    /**< Picture.                     */
#define CH68_REPLAY    "RE"    /**< External replay.             */

#define CH68_MDATA     "DA"    /**< Music data.                  */

#define CH68_EOF       "EF"    /**< End of file.                 */

/**
 * @}
 */

/**
 * Hardware and features flags.
 */
typedef union {

  struct {
    unsigned ym:1;        /**< Music uses YM-2149 (ST).          */
    unsigned ste:1;       /**< Music uses STE specific hardware. */
    unsigned amiga:1;     /**< Music uses Paula Amiga hardware.  */
    unsigned stechoice:1; /**< Music allow STF/STE choices.      */
  } bit;                  /**< Flags bit field.                  */
  unsigned all;           /**< All flags in one.                 */
} hwflags68_t;

/**
 * SC68 music (track) structure.
 */
typedef struct
{

  /**
   * @name  Music replay parameters.
   * @{
   */
  unsigned int d0;       /**< D0 value to init this music.            */
  unsigned int a0;       /**< A0 Loading address. @see SC68_LOADADDR. */
  unsigned int frq;      /**< Frequency in Hz (default:50).           */
  unsigned int start_ms; /**< Start time in ms from disk 1st track.   */
  unsigned int time_ms;  /**< Duration in ms.                         */
  unsigned int frames;   /**< Number of frame.                        */
  int loop;              /**< Default number of loop (0:infinite).    */
  int track;             /**< Track remapping number (0:default).     */
  hwflags68_t hwflags;   /**< Hardware and features.                  */
  /**
   * @}
   */

  /**
   * @name  Human readable information.
   * @{
   */
  char * name;          /**< Music name.           */
  char * author;        /**< Author name.          */
  char * composer;      /**< Composer name.        */
  char * replay;        /**< External replay name. */
  /* added for XSC and sndh support */
  char * converter;     /**< Converter name.       */
  char * ripper;        /**< Copier name.          */
  /**
   * @}
   */

  /**
   * @name  Music data.
   * @{
   */
  unsigned int datasz;  /**< data size in bytes. */
  char        *data;    /**< Music data.         */
  /**
   * @}
   */

} music68_t;


/**
 * SC68 music disk structure.
 *
 *  The disk68_t structure is the memory representation for an SC68
 *  disk.  Each SC68 file could several music or tracks, in the limit
 *  of a maximum of 99 tracks per file. Each music is independant, but
 *  some information, including music data, could be inherit from
 *  previous track. In a general case, tracks are grouped by theme,
 *  that could be a Demo or a Game.
 *
 */
typedef struct
{
  /**
   * @name  Disk information.
   * @{
   */
  int          default_six; /**< Prefered default music (default is 0).  */
  int          nb_six;      /**< Number of music track in file.          */
  unsigned int time_ms;     /**< Total time for all tracks in ms.        */
  hwflags68_t  hwflags;     /**< All tracks flags ORed.                  */
  char        *name;        /**< Disk name.                              */
  /**
   * @}
   */

  /**
   * @name  Music data.
   * @{
   */
  music68_t mus[SC68_MAX_TRACK]; /**< Information for each music.        */
  char      data[1];             /**< raw data (must be last in struct). */
  /**
   * @}
   */

} disk68_t;

FILE68_API
/**
 * SC68 file identifier string.
 *
 * @see SC68_IDSTR
 */
const char file68_idstr[56];

FILE68_API
/**
 * SC68 file identifier string V2.
 *
 * @see SC68_IDSTR_V2
 */
const char file68_idstr_v2[8];

/**
 * @name  File verify functions.
 * @{
 */

FILE68_API
/**
 * Verify SC68 file from stream.
 *
 *  The file68_verify() function opens, reads and closes given file to
 *  determine if it is a valid SC68 file. This function only checks
 *  for a valid file header, and does not perform any consistent error
 *  checking.
 *
 * @param  is       input stream to verify
 *
 * @return error-code
 * @retval  0  success, seems to be a valid SC68 file
 * @retval <0  failure, file error or invalid SC68 file
 *
 * @see file68_load()
 * @see file68_save()
 * @see file68_diskname()
 */
int file68_verify(istream68_t * is);

FILE68_API
/**
 * Verify SC68 file.
 *
 * @param  url      URL to verify.
 */
int file68_verify_url(const char * url);

FILE68_API
/**
 * Verify SC68 file mapped into memory buffer.
 *
 * @param  buffer   buffer address
 * @param  len      buffer length
 */
int file68_verify_mem(const void * buffer, int len);

FILE68_API
/**
 * Get SC68 disk name.
 *
 *  The file68_diskname() function opens, reads and closes given file
 *  to determine if it is a valid SC68 file. In the same time it tries
 *  to retrieve the stored disk name into the dest buffer with a
 *  maximum length of max bytes.  If the name overflows, the last byte
 *  of the dest buffer will be non zero.
 *
 * @param  is       input stream
 * @param  dest     disk name destination buffer
 * @param  max      number of bytes of dest buffer
 *
 * @return error-code
 * @retval  0  success, found a disk-name
 * @retval <0  failure, file error, invalid SC68 file or disk-name not found
 *
 * @see file68_load()
 * @see file68_save()
 * @see file68_diskname()
 *
 * @deprecated This function needs to be rewritten.
 */
int file68_diskname(istream68_t * is, char * dest, int max);



FILE68_API
/**
 * Check if an URL is a standard sc68 one.
 *
 * @param  url        URL to check.
 * @param  exts       extension list. (0 is default: ".sc68\0.sndh\0.snd\0").
 * @param  is_remote  fill with 0/1 if respectevely URL is a local/remote
 *                     file. May be 0.
 * @return  bool
 * @retval  0  not compatible sc68 file
 * @retval  1  sc68 compatible file
 */
int file68_is_our_url(const char * url, const char * exts, int * is_remote);

/**
 * @}
 */


/**
 * @name  File load functions.
 * @{
 */

FILE68_API
/**
 * Load SC68 file from stream.
 *
 *  The file68_load() function allocates memory and loads an SC68
 *  file.  The function performs all necessary initializations in the
 *  returned disk68_t structure. A single buffer has been allocated
 *  including disk68_t structure followed by music data. It is user
 *  charge to free memory by calling SC68_free() function.
 *
 * @param   is   input stream
 *
 * @return  pointer to allocated disk68_t disk structure
 * @retval  0  failure
 *
 * @see file68_verify()
 * @see file68_save()
 */
disk68_t * file68_load(istream68_t * is);

FILE68_API
/**
 * Load SC68 file.
 *
 * @param  url      URL to load.
 *
 * @return  pointer to allocated disk68_t disk structure
 * @retval  0  failure
 */
disk68_t * file68_load_url(const char * url);

FILE68_API
/**
 * Load SC68 file mapped into memory buffer.
 *
 * @param  buffer   buffer address
 * @param  len      buffer length
 *
 * @return  pointer to allocated disk68_t disk structure
 * @retval  0  failure
 */
disk68_t * file68_load_mem(const void * buffer, int len);

/**
 * @}
 */


/**
 * @name  File save functions.
 * @{
 */

FILE68_API
/**
 * Save SC68 disk into stream.
 *
 * @param  os    output stream (must be seekable)
 * @param  mb    pointer to SC68 disk to save
 * @param  gzip  gzip compression level [0:no-gzip, 1..9 or -1]
 *
 * @return error-code
 * @retval  0  success
 * @retval <0  failure
 *
 * @see file68_load()
 * @see file68_verify()
 * @see file68_diskname()
 */
int file68_save(istream68_t * os, const disk68_t * mb, int gzip);

FILE68_API
/**
 * Save SC68 disk into file.
 *
 * @param  url      URL to save.
 * @param  mb       pointer to SC68 disk to save
 * @param  gzip     gzip compression level [0:no-gzip, 1..9 or -1]
 */
int file68_save_url(const char * url, const disk68_t * mb, int gzip);

FILE68_API
/**
 * Save SC68 disk into memory buffer.
 *
 * @param  buffer   destination buffer.
 * @param  len      size of destination buffer.
 * @param  mb       pointer to SC68 disk to save
 * @param  gzip     gzip compression level [0:no-gzip, 1..9 or -1]
 */
int file68_save_mem(const char * buffer, int len, const disk68_t * mb,
                    int gzip);

/**
 * @}
 */


/**
 * @name  Informative functions.
 * @{
 */

FILE68_API
/**
 * Get package version string.
 *
 * @return "file68 X.Y.Z"
 */
const char * file68_versionstr(void);

FILE68_API
/**
 * Get package version number.
 *
 * @return X*100+Y*10+Z
 */
int file68_version(void);

/**
 * @}
 */

/**
 * @}
 */

#endif /* #ifndef _FILE68_FILE68_H_ */

/**
 * @ingroup   sc68_lib
 * @file      sc68/sc68.h
 * @author    Benjamin Gerard
 * @date      2003/08/07
 * @brief     sc68 API header.
 *
 */

/* $Id$ */

/* Copyright (C) 1998-2009 Benjamin Gerard */

#ifndef _SC68_SC68_H_
#define _SC68_SC68_H_

#ifndef SC68_EXTERN
# ifdef __cplusplus
#  define SC68_EXTERN extern "C"
# else
#  define SC68_EXTERN extern
# endif
#endif

#ifndef SC68_API
/* Building */
# ifdef SC68_EXPORT
#  if defined(DLL_EXPORT) && defined(HAVE_DECLSPEC)
#   define SC68_API __declspec(dllexport)
#  elif defined(HAVE_VISIBILITY)
#   define SC68_API SC68_EXTERN __attribute__ ((visibility("default")))
#  else
#   define SC68_API SC68_EXTERN
#  endif
/* Using */
# else
#  if defined(SC68_DLL)
#   define SC68_API __declspec(dllimport)
#  else
#   define SC68_API SC68_EXTERN
#  endif
# endif
#endif

/**
 *  @defgroup  sc68_lib  sc68 library
 *  @ingroup   api68
 *
 *  This API provides functions to use sc68 libraries efficiently.
 *
 *  @par Multi-threading concern
 *
 *  sc68 should now be thread safe. At least concerning the functions
 *  with a sc68_t parameter. As no torture test has been run against
 *  it this should be considered as quiet experimental.
 *
 *  @par Quick start
 *
 *  Here is a quiet minimalist piece of code to use basics of sc68
 *  library:
 *
 *  @code
 *  #include <sc68/sc68.h>
 *
 *  sc68_t * sc68 = 0;
 *  char buffer[512*4];
 *
 *  // Initialise the library.
 *  // You should consider using sc68_init_t struct.
 *  if (sc68_init(0)) goto error;
 *
 *  // Create an emulator instance.
 *  // You should consider using sc68_create_t struct.
 *  if (sc68 = sc68_create(0), !sc68) goto error;
 *
 *  // Load an sc68 file.
 *  if (sc68_load_url(sc68, fname)) {
 *    goto error;
 *  }
 *
 *  // Set a track (optionnal).
 *  sc68_play(sc68, track, 1);
 *
 *  // Loop until the end of disk. You can use SC68_LOOP to wait the end
 *  // of the track. Notice that SC68_ERROR set all bits and make the loop
 *  // break too.
 *  while ( ! (sc68_process(sc68, buffer, sizeof(buffer) >> 2) & SC68_END)) {
 *    // Do something with buffer[] here.
 *  }
 *
 *  // Close eject the current disk.
 *  sc68_close(sc68);
 *
 * error:
 *
 *  // Destroy sc68 instance.
 *  sc68_destroy(sc68);
 *
 *  // Shutdown sc68 library.
 *  sc68_shutdown();
 *
 * @endcode
 *
 *  @{
 */

#ifndef SC68_API
/** sc68 exported symbol.
 *
 *  Define special atribut for exported symbol.
 *
 *  - empty: static or classic .so library
 *  - __attribute__ (visibility("default"))): gcc support visibility.
 *  - __declspec(dllexport): creating a win32 DLL.
 *  - __declspec(dllimport): using a win32 DLL.
 */
#define SC68_API extern
#endif

/** API information. */
typedef struct _sc68_s sc68_t;

/** API disk. */
typedef void * sc68_disk_t;

/** message function.
 *
 *  @param  cat   @ref msg68_cat_e "message category"
 *  @param  sc68  sc68 instance
 *  @param  fmt   printf like format string
 *  @param  list  variable argument list
 * */
typedef void (*sc68_msg_t)();

/** API initialization parameters.
 *
 *    The sc68_init_t must be properly filled before calling the
 *    sc68_init() function.
 *
 * @code
 * // Minimum code zeroes init structure.
 * sc68_init_t init;
 * memset(&init,0,sizeof(init));
 * sc68_init(&init);
 * @endcode
 */
typedef struct {

  /** message handler. */
  sc68_msg_t msg_handler;

  /** debug mask (set bit to clear in debugmsg68). */
  int debug_clr_mask;

  /** debug mask (set bit to set in debugmsg68). */
  int debug_set_mask;

  /** number of arguments in command line (modified) */
  int argc;

  /** command line arguments */
  char ** argv;

} sc68_init_t;

/** Instance creation parameters.
 */
typedef struct {
  /** sampling rate in hz (non 0 value overrides config default).
   *  The real used value is set by sc68_create() function.
   */
  unsigned int sampling_rate;

  /** short name. */
  const char * name;

  /** 68k memory size (2^log2mem). */
  int log2mem;

  /** Run  68k emulator in debug mode (enable memory access trace). */
  int emu68_debug;

  /** User private data. */
  void * cookie;

} sc68_create_t;

/** Music information.
 *
 * @warning  Most string in this structure point on disk and must not be used
 *           after the sc68_close() call.
 *
 */
typedef struct {
  int track;             /**< Track number (default or current).  */
  int tracks;            /**< Number of track.                    */
  const char * title;    /**< Disk or track title.                */
  const char * author;   /**< Author name.                        */
  const char * composer; /**< Composer name.                      */
  const char * ripper;   /**< Ripper name.                        */
  const char * converter;/**< Converter name.                     */
  const char * replay;   /**< Replay name.                        */
  const char * hwname;   /**< Hardware description.               */
  char time[12];         /**< Time in format TT MM:SS.            */
  /** Hardware used. */
  struct {
    unsigned ym:1;        /**< Music uses YM-2149 (ST).           */
    unsigned ste:1;       /**< Music uses STE specific hardware.  */
    unsigned amiga:1;     /**< Music uses Paula Amiga hardware.   */
  } hw;
  unsigned int time_ms;   /**< Duration in ms.                    */
  unsigned int start_ms;  /**< Absolute start time in disk in ms. */
  unsigned int rate;      /**< Replay rate.                       */
  unsigned int addr;      /**< Load address.                      */
} sc68_music_info_t;


/** @name  Process status (as returned by sc68_process() function)
 *  @{
 */

#define SC68_IDLE_BIT   1 /**< Set if no emulation pass has been runned. */
#define SC68_CHANGE_BIT 2 /**< Set when track has changed.               */
#define SC68_LOOP_BIT   4 /**< Set when track has loop.                  */
#define SC68_END_BIT    5 /**< Set when finish with all tracks.          */

#define SC68_IDLE       (1<<SC68_IDLE_BIT)   /**< @see SC68_IDLE_BIT   */
#define SC68_CHANGE     (1<<SC68_CHANGE_BIT) /**< @see SC68_CHANGE_BIT */
#define SC68_LOOP       (1<<SC68_LOOP_BIT)   /**< @see SC68_LOOP_BIT   */
#define SC68_END        (1<<SC68_END_BIT)    /**< @see SC68_END_BIT    */

#define SC68_OK         0 /**< Ok.              */
#define SC68_ERROR     ~0 /**< Error.           */

#define SC68_MIX_OK     SC68_OK    /**< Backward compatibility. */
#define SC68_MIX_ERROR  SC68_ERROR /**< Backward compatibility. */

/** @} */

/** sc68 sampling rate values in hertz (hz). */
enum sc68_spr_e {
  SC68_SPR_QUERY   = -1, /**< Query default or current sampling rate. */
  SC68_SPR_DEFAULT =  0  /**< Default sampling rate.                  */
};

/** @name API control functions.
 *  @{
 */

SC68_API
/** Get version number
 */
int sc68_version(void);

SC68_API
/** Get version string
 *
 */
const char * sc68_versionstr(void);

SC68_API
/** Initialise sc68 API.
 *
 * @param   init  Initialization parameters.
 *
 * @return  error-code
 * @retval   0  Success
 * @retval  -1  Error
 *
 * @see sc68_shutdown()
 */
int sc68_init(sc68_init_t * init);

SC68_API
/** Destroy sc68 API.
 *
 */
void sc68_shutdown(void);

SC68_API
/** Create sc68 instance.
 *
 * @param   creation  Creation parameters.
 *
 * @return  Pointer to created sc68 instance.
 * @retval  0  Error.
 *
 * @see sc68_destroy()
 */
sc68_t * sc68_create(sc68_create_t * create);

SC68_API
/** Destroy sc68 instance.
 *
 * @param   sc68  sc68 instance to destroy.
 *
 * @see sc68_create()
 * @note  It is safe to call with null api.
 */
void sc68_destroy(sc68_t * sc68);

SC68_API
/** Get instance name.
 *
 * @param   sc68  sc68 instance to destroy.
 * @return  sc68 instance name.
 *
 */
const char * sc68_name(sc68_t * sc68);

SC68_API
/** Get user private data pointer.
 *
 *   The sc68_cookie_ptr() function get a pointer to the user private
 *   data. This pointer can be use to get a modify this sc68 instance
 *   private data.
 *
 * @param   sc68  sc68 instance.
 * @return        a pointer to the user data inside this sc68 instance.
 * @retval  0     on error
 */
void ** sc68_cookie_ptr(sc68_t * sc68);

SC68_API
/** Set/Get sampling rate.
 *
 * @param   sc68  sc68 api or 0 for library default.
 * @param   hz    @ref sc68_spr_e "sampling rate" (in hz).
 *
 * @return  Actual @ref sc68_spr_e "sampling rate"
 * @retval  -1  on error
 * @retval  >0  on success
 */
int sc68_sampling_rate(sc68_t * sc68, int hz);

SC68_API
/** Set share data path.
 *
 * @param   sc68  sc68 instance.
 * @param   path  New shared data path.
 */
void sc68_set_share(sc68_t * sc68, const char * path);

SC68_API
/** Set user data path.
 *
 * @param   sc68  sc68 instance.
 * @param   path  New user data path.
 */
void sc68_set_user(sc68_t * sc68, const char * path);


SC68_API
/** Empty error message stack.
 *
 * @param   sc68   sc68 instance or 0 for library messages.
 */
void sc68_error_flush(sc68_t * sc68);


SC68_API
/** Pop and return last stacked error message.
 *
 * @param   sc68   sc68 instance or 0 for library messages.
 * @return  Error string.
 * @retval  0      No stacked error message.
 */
const char * sc68_error_get(sc68_t * sc68);


SC68_API
/** Stack an error Add Pop and return last stacked error message.
 *
 * @param   sc68   sc68 instance or 0 for library messages.
 * @return  Error string.
 * @retval  0      No stacked error message.
 */
int sc68_error_add(sc68_t * sc68, const char * fmt, ...);


SC68_API
/** Display debug message.
 *
 *  @param  sc68  sc68 instance.
 *  @param  fmt   printf() like format string.
 *
 * @see debugmsg68()
 * @see sc68_t::debug_bit
 */
void sc68_debug(sc68_t * sc68, const char * fmt, ...);

/** @} */


/** @name Music control functions.
 *  @{
 */

SC68_API
/** Fill PCM buffer.
 *
 *    The sc68_process() function fills the PCM buffer with the current
 *    music data. If the current track is finished and it is not the last
 *    the next one is automatically loaded. The function returns status
 *    value that report events that have occured during this pass.
 *
 * @param  sc68  sc68 instance.
 * @param  buf   PCM buffer (must be at least 4*n bytes).
 * @param  n     Number of sample to fill.
 *
 * @return Process status
 *
 */
int sc68_process(sc68_t * sc68, void * buf, int n);

SC68_API
/** Set/Get current track.
 *
 *   The sc68_play() function get or set current track.
 *
 *   If track == -1 and loop == 0 the function returns the current
 *   track or 0 if none.
 *
 *   If track == -1 and loop != 0 the function returns the current
 *   loop counter.
 *
 *   If track >= 0 the function will test the requested track
 *   number. If it is 0, the disk default track will be use. If the
 *   track is out of range, the function fails and returns -1 else it
 *   returns 0.  To avoid multi-threading issus the track is not
 *   changed directly but a change-track event is posted. This event
 *   will be processed at the next call to the sc68_process()
 *   function. If loop is -1 the default music loop is used. If loop
 *   is 0 does an infinite loop.
 *
 * @param  sc68    sc68 instance.
 * @param  track  track number [-1:read current, 0:set disk default]
 * @param  loop   number of loop [-1:default 0:infinite]
 *
 * @return error code or track number.
 * @retval 0  Success or no current track
 * @retval >0 Current track
 * @retval -1 Failure.
 *
 */
int sc68_play(sc68_t * sc68, int track, int loop);

SC68_API
/** Stop playing.
 *
 *     The sc68_stop() function stop current playing track. Like the
 *     sc68_play() function the sc68_stop() function does not really
 *     stop the music but send a stop-event that will be processed by
 *     the next call to sc68_process() function.
 *
 * @param  sc68    sc68 instance.
 * @return error code
 * @retval 0  Success
 * @retval -1 Failure
 */
int sc68_stop(sc68_t * sc68);

SC68_API
/** Set/Get current play position.
 *
 *    The sc68_seek() functions get or set the current play position.
 *
 *    If time_ms == -1 the function returns the current play position
 *    or -1 if not currently playing.
 *
 *    If time_ms >= 0 the function tries to seek to the given position.
 *    If time_ms is out of range the function returns -1.
 *    If time_ms is inside the current playing track the function does not
 *    seek backward.
 *    Else the function changes to the track which time_ms belong to and
 *    returns the time position at the beginning of this track.
 *
 *    The returned time is always the current position in millisecond
 *    (not the goal position).
 *
 * @param  sc68        sc68 instance.
 * @param  time_ms     new time position in ms (-1:read current time).
 * @param  is_seeking  Fill with current seek status (0:not seeking 1:seeking)
 *
 * @return  Current play position (in ms)
 * @retval  >0  Success
 * @retval  -1  Failure
 *
 * @bug  Time position calculation may be broken if tracks have different
 *       loop values. But it should not happen very often.
 */
int sc68_seek(sc68_t * sc68, int time_ms, int * is_seeking);

SC68_API
/** Get disk/track information.
 *
 * @param  sc68   sc68 instance
 * @param  info  track/disk information structure to be filled.
 * @param  track track number (-1:current/default 0:disk-info).
 * @param  disk  disk to get information from (0 means API disk).
 *
 * @return error code
 * @retval 0  Success.
 * @retval -1 Failure.
 *
 * @warning API disk informations are valid as soon as the disk is loaded and
 *          must not be used after api_load() or api_close() function call.
 *          If disk was given the information are valid until the disk is
 *          freed.
 *
 */
int sc68_music_info(sc68_t * sc68, sc68_music_info_t * info, int track,
                    sc68_disk_t disk);

/** @} */


/** @name File functions.
 *  @{
 */


#ifdef _FILE68_ISTREAM68_H_
SC68_API
/** Create a stream from url. */
istream68_t *  sc68_stream_create(const char * url, int mode);
#endif

/** Verify an sc68 disk. */
#ifdef _FILE68_ISTREAM68_H_
SC68_API
int sc68_verify(istream68_t * is);
#endif
SC68_API
int sc68_verify_url(const char * url);
SC68_API
int sc68_verify_mem(const void * buffer, int len);
SC68_API
int sc68_is_our_url(const char * url,
                    const char *exts, int * is_remote);

/** Load an sc68 disk for playing. */
#ifdef _FILE68_ISTREAM68_H_
SC68_API
int sc68_load(sc68_t * sc68, istream68_t * is);
#endif
SC68_API
int sc68_load_url(sc68_t * sc68, const char * url);
SC68_API
int sc68_load_mem(sc68_t * sc68, const void * buffer, int len);

/** Load an sc68 disk outside the API.
 *
 *  @notice Free it with sc68_disk_free() function.
 */
#ifdef _FILE68_ISTREAM68_H_
SC68_API
sc68_disk_t sc68_load_disk(istream68_t * is);
#endif
SC68_API
sc68_disk_t sc68_load_disk_url(const char * url);
SC68_API
sc68_disk_t sc68_disk_load_mem(const void * buffer, int len);
SC68_API
void sc68_disk_free(sc68_disk_t disk);


SC68_API
/** Change current disk.
 *
 * @param  sc68   sc68 instance
 * @param  disk  New disk (0 does a sc68_close())
 *
 * @return error code
 * @retval 0  Success, disk has been loaded.
 * @retval -1 Failure, no disk has been loaded (occurs if disk was 0).
 *
 * @note    Can be safely call with null sc68.
 * @warning After sc68_open() failure, the disk has been freed.
 * @warning Beware not to use disk information after sc68_close() call
 *          because the disk should have been destroyed.
 */
int sc68_open(sc68_t * sc68, sc68_disk_t disk);

SC68_API
/** Close current disk.
 *
 * @param  sc68  sc68 instance
 *
 * @note   Can be safely call with null sc68 or if no disk has been loaded.
 */
void sc68_close(sc68_t * sc68);

SC68_API
/** Get number of tracks.
 *
 * @param  sc68  sc68 instance
 *
 * @return Number of track
 * @retval -1 error
 *
 * @note Could be use to check if a disk is loaded.
 */
int sc68_tracks(sc68_t * sc68);

/** @} */


/** @name Configuration functions
 *  @{
 */

SC68_API
/** Load config.
 *
 * @param  sc68  sc68 instance
 */
int sc68_config_load(sc68_t * sc68);

SC68_API
/** Save config.
 *
 * @param  sc68  sc68 instance
 */
int sc68_config_save(sc68_t * sc68);

#if 0
SC68_API
/** Get config variable idex.
 *
 * @param  sc68   sc68 instance
 * @param  name  name of config variable
 *
 * @return  config index
 * @retval -1 Error
 */
int sc68_config_idx(sc68_t * sc68, const char * name);

SC68_API
/** Get config variable value.
 *
 * @param  sc68  sc68 instance
 * @see config68_get()
 */
config68_type_t sc68_config_get(sc68_t * sc68,
                                int * idx,
                                const char ** name);

SC68_API
/** Get type and range of a config entry.
 *
 * @param  sc68  sc68 instance
 *
 * @see config68_range()
 */
config68_type_t sc68_config_range(sc68_t * sc68, int idx,
                                  int * min, int * max, int * def);

SC68_API
/** Set config variable value.
 *
 * @param  sc68  sc68 instance
 * @see config68_set()
 */
config68_type_t sc68_config_set(sc68_t * sc68,
                                int idx,
                                const char * name,
                                int v,
                                const char * s);
#endif

SC68_API
/** Apply current configuration to sc68.
 *
 * @param  sc68  sc68 instance
 */
void sc68_config_apply(sc68_t * sc68);

/** @} */


/** @name Dynamic memory access.
 *  @{
 */

SC68_API
/** Allocate dynamic memory.
 *
 *   The sc68_alloc() function calls the SC68alloc() function.
 *
 * @param  n  Size of buffer to allocate.
 *
 * @return pointer to allocated memory buffer.
 * @retval 0 error
 *
 * @see SC68alloc()
 *
 */
void * sc68_alloc(/* sc68_t * api,  */unsigned int n);

SC68_API
/** Free dynamic memory.
 *
 *   The sc68_free() function calls the SC68free() function.
 *
 * @param  data  Previously allocated memory buffer.
 *
 */
void sc68_free(/* sc68_t * api,  */void * data);

/** @} */

/**
 *  @}
 */

#endif /* #ifndef _SC68_SC68_H_ */

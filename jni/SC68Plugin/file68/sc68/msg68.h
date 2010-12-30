/**
 * @ingroup  file68_lib
 * @file     sc68/msg68.h
 * @author   Benjamin Gerard
 * @date     2003-08-22
 * @brief    Message header.
 *
 */

/* $Id: msg68.h 126 2009-07-15 08:58:51Z benjihan $ */

/* Copyright (C) 1998-2009 Benjamin Gerard */

#ifndef _FILE68_MSG68_H_
#define _FILE68_MSG68_H_

#ifndef FILE68_API
# include "file68_api.h"
#endif
#include <stdarg.h>


/** @defgroup  file68_msg  Output messages
 *  @ingroup   file68_lib
 *
 *    Provides functions to output text messages.
 *
 *    The output message system defines fixed categories of message:
 *    msg68_CRITICAL, msg68_ERROR, msg68_INFO, msg68_DEBUG and
 *    msg68_TRACE. Each of them can be freely enabled (output) or
 *    disabled (filter out). msg68_TRACE category filters user defined
 *    categories created by the msg68_category() function. Special
 *    value msg68_NEVER always filter out the message. In the contrary
 *    the special value msg68_ALWAYS always output the message. The
 *    last special value msg68_CURRENT would use the category
 *    previously setted by the msg68_category_current() function.
 *
 *  @{
 */

/** Message handler type.
 *
 *  @param  bit        one of the @ref enum_msg68_bit enum value.
 *  @param  user_data  user private data.
 *  @param  format     printf like format string.
 *  @param  va_list    variable argument list.
 */
typedef void (*msg68_t)(int, void*, const char*, va_list);

/** Message category help display function.
 *
 *  @param  user_data    user private data.
 *  @param  bit          one of the @ref enum_msg68_bit enum value.
 *  @param  name         category name.
 *  @param  description  short description.
 */
typedef void (*msg68_help_t)(void*, int, const char*, const char*);

/** Predefined message categories. */
enum msg68_cat_e
{
  msg68_NEVER    = -3, /**< Never printed message.    */
  msg68_ALWAYS   = -2, /**< Always printed message.   */
  msg68_CURRENT  = -1, /**< Current category message. */

  msg68_CRITICAL = 0,  /**< Critical error message.   */
  msg68_ERROR    = 1,  /**< Error message.            */
  msg68_WARNING  = 2,  /**< Warning message.          */
  msg68_INFO     = 3,  /**< Informationnal message.   */
  msg68_DEBUG    = 4,  /**< Debug message.            */
  msg68_TRACE    = 5,  /**< Trace message.            */
};

/** @name  Category manipulation functions.
 *  @{
 */

FILE68_API
/** Modify message category filter mask.
 *
 *    The msg68_cat_filter() function modifies the current message
 *    mask allowing to control message category filter.
 *
 *  @param  clr  bit to clear in the category mask.
 *  @param  set  bit to set in the category mask.
 *  @return modified mask
 */
unsigned int msg68_cat_filter(unsigned int clr, unsigned int set);

FILE68_API
/** Get named categories.
 *
 *  @param  name  name of category.
 *  @return bit number of named category.
 *  @retval -1  on error (category does not exist).
 */
int msg68_cat_bit(const char * name);

FILE68_API
/** Create/Modify a category.
 *
 *  @param  name    category name.
 *  @param  desc    a short description the the category.
 *  @param  filter  0:set to disable the category.
 */
int msg68_cat(const char * name, const char * desc, int filter);

FILE68_API
/** Get/Set current category. */
int msg68_cat_current(int cat);

FILE68_API
/** Free/Destroy a category. */
void msg68_cat_free(int cat);

FILE68_API
/** Set all predefined categories mask according to given level. */
int msg68_cat_level(int cat);

FILE68_API
/** Get info on a category. */
int msg68_cat_info(int cat, const char **name, const char **desc, int * next);

FILE68_API
/** Print defined categories. */
void msg68_cat_help(void * cookie, msg68_help_t fct);

/** @} */


/** @name  Customize functions.
 *  @{
 */

FILE68_API
/** Set message handler.
 *
 *  @param  handler  pointer to a function to display debug messages
 *                   (0 desactive debug message).
 *  @return previous handler
 */
msg68_t msg68_set_handler(msg68_t handler);

FILE68_API
/** Set message handler user-data parameter.
 *
 *  @param  cookie  user parameter that will be sent as first parameter to
 *                  the output handler.
 *
 *  @see msg68_set_handler();
 */
void * msg68_set_cookie(void * cookie);

/** @} */


/** @name  Simple message functions
 *  @{
 *
 *    The msg68_ output functions have no userdata parameter therefore
 *    the value set by the msg68_set_cookie() will be passed to the
 *    message handler function.
 */

FILE68_API
/** Print generic message (variable argument).
 *
 *  @param  cat     message type @ref enum_msg68_bit.
 *  @param  fmt     printf() like format string.
 *  @param  list    variable argument list (stdarg.h)
 */
void msg68_va(int cat, const char * fmt, va_list list);

FILE68_API
/** Print generic message.
 *
 *  @param  cat     message type @ref enum_msg68_bit.
 *  @param  fmt     printf() like format string.
 */
void msg68(int cat, const char * fmt, ...);

FILE68_API
/** Print critical message.
 *
 *  @param  fmt     printf() like format string.
 */
void msg68_critical(const char * fmt, ...);

FILE68_API
/** Print error message.
 *
 *  @param  fmt     printf() like format string.
 */
void msg68_error(const char * fmt, ...);

FILE68_API
/** Print warning message.
 *
 *  @param  fmt     printf() like format string.
 */
void msg68_warning(const char * fmt, ...);

FILE68_API
/** Print info message.
 *
 *  @param  fmt     printf() like format string.
 */
void msg68_info(const char * fmt, ...);

FILE68_API
/** Print debug message.
 *
 *  @param  fmt     printf() like format string.
 */
void msg68_debug(const char * fmt, ...);

FILE68_API
/** Print trace message.
 *
 *  @param  fmt     printf() like format string.
 */
void msg68_trace(const char * fmt, ...);

/** @} */


/** @name  Extended message functions
 *  @{
 *
 *    The msg68x_ output functions are identical to the msg68_ ones
 *    except for an additionnal cookie parameter which will be pass to
 *    the handler function instead of the one set by the
 *    msg68_set_cookie() function.
 */

FILE68_API
/** Print message (eXtended version).
 *
 *  @param  cat     message type @ref enum_msg68_bit.
 *  @param  cookie  user data.
 *  @param  fmt     printf() like format string.
 */
void msg68x(int cat, void * cookie, const char * fmt, ...);

FILE68_API
/** Print message (eXtended version; variable argument).
 *
 *  @param  cat     message type @ref enum_msg68_bit.
 *  @param  cookie  user data.
 *  @param  fmt     printf() like format string.
 *  @param  list    variable argument list (stdarg.h)
 */
void msg68x_va(int cat, void * cookie, const char * fmt, va_list list);

FILE68_API
/** Print critical message (eXtended version).
 *
 *  @param  cookie  user data.
 *  @param  fmt     printf() like format string.
 */
void msg68x_critical(void * cookie, const char * fmt, ...);

FILE68_API
/** Print error message (eXtended version).
 *
 *  @param  cookie  user data.
 *  @param  fmt     printf() like format string.
 */
void msg68x_error(void * cookie, const char * fmt, ...);

FILE68_API
/** Print warning message (eXtended version).
 *
 *  @param  cookie  user data.
 *  @param  fmt     printf() like format string.
 */
void msg68x_warning(void * cookie, const char * fmt, ...);

FILE68_API
/** Print info message (eXtended version).
 *
 *  @param  cookie  user data.
 *  @param  fmt     printf() like format string.
 */
void msg68x_info(void * cookie, const char * fmt, ...);

FILE68_API
/** Print debug message (eXtended version).
 *
 *  @param  cookie  user data.
 *  @param  fmt     printf() like format string.
 */
void msg68x_debug(void * cookie, const char * fmt, ...);

FILE68_API
/** Print trace message (eXtended version).
 *
 *  @param  cookie  user data.
 *  @param  fmt     printf() like format string.
 */
void msg68x_trace(void * cookie, const char * fmt, ...);

/** @} */

/**
 *  @}
 */

#ifdef NDEBUG
# define  TRACE68 while (0) msg68_dummy
# define VTRACE68 while (0) vmsg68_dummy
static inline
void msg68_dummy(int cat, const char * fmt, ...) {}
static inline
void vmsg68_dummy(int cat, const char * fmt, va_list list) {}
#else
# define  TRACE68 msg68
# define VTRACE68 vmsg68
#endif

#ifndef msg68_DEFAULT
# ifndef DEBUG
#  define msg68_DEFAULT msg68_NEVER
# else
#  define msg68_DEFAULT msg68_CURRENT
# endif
#endif


#endif /* #ifndef _FILE68_MSG68_H_ */

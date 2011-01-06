#include "vice.h"

#include <stdlib.h>

#include <android/log.h>
#include "log.h"

int log_verbose_init(int argc, char **argv)
{
}

int log_cmdline_options_init()
{
}

int log_resources_init(void)
{
}

void log_resources_shutdown(void)
{
}

/* ------------------------------------------------------------------------- */

int log_init_with_fd(FILE *f)
{
    return 0;
}

int log_init(void)
{
    return 0;
}

log_t log_open(const char *id)
{
    return 0;
}

int log_close(log_t log)
{
    return 0;
}

void log_close_all(void)
{
}

int log_message(log_t log, const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    __android_log_vprint(ANDROID_LOG_WARN, "VICE", format, ap);
}

int log_warning(log_t log, const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    __android_log_vprint(ANDROID_LOG_WARN, "VICE", format, ap);
}

int log_error(log_t log, const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    __android_log_vprint(ANDROID_LOG_WARN, "VICE", format, ap);
}

int log_debug(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    __android_log_vprint(ANDROID_LOG_WARN, "VICE", format, ap);
}

int log_verbose(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    __android_log_vprint(ANDROID_LOG_WARN, "VICE", format, ap);
}

void log_enable(int on)
{
}


/*
 * archdep_win32.c - Miscellaneous system-specific stuff.
 *
 * Written by
 *  Tibor Biczo <crown@mail.matav.hu>
 *  Andreas Boose <viceteam@t-online.de>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <winsock.h>
#include <tlhelp32.h>
#include <tchar.h>

#include "ui.h"

#ifdef HAVE_DIR_H
#include <dir.h>
#endif

#ifdef HAVE_DIRECT_H
#include <direct.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif

#if defined(HAVE_IO_H) && !defined(WINMIPS)
#include <io.h>
#endif

#ifdef HAVE_PROCESS_H
#include <process.h>
#endif

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "archdep.h"
#include "lib.h"
#include "log.h"
#include "machine.h"
#include "util.h"

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#ifndef O_BINARY
#define O_BINARY 0x8000
#endif

#ifndef _O_BINARY
#define _O_BINARY O_BINARY
#endif

#ifndef _O_WRONLY
#define _O_WRONLY O_WRONLY
#endif

#ifndef _O_TRUNC
#define _O_TRUNC O_TRUNC
#endif

#ifndef _O_CREAT
#define _O_CREAT O_CREAT
#endif

#ifndef S_IWRITE
#define S_IWRITE 0x200
#endif

#ifndef S_IREAD
#define S_IREAD 0x400
#endif

static char *orig_workdir;
static char *argv0;

static size_t system_wcstombs(char *mbs, const char *wcs, size_t len)
{
    strncpy(mbs, wcs, len);
    return strlen(mbs);
}

static size_t system_mbstowcs(char *wcs, const char *mbs, size_t len)
{
    strncpy(wcs, mbs, len);
    return strlen(wcs);
}

static char *system_mbstowcs_alloc(const char *mbs)
{
    char *wcs;

    if (mbs == NULL) {
        return NULL;
    }

    wcs = lib_malloc((strlen(mbs) + 1) * sizeof(char));
    system_mbstowcs(wcs, mbs, strlen(mbs) + 1);

    return wcs;
}

static void system_mbstowcs_free(char *wcs)
{
    lib_free(wcs);
}

static char *system_wcstombs_alloc(const char *wcs)
{
    char *mbs;

    if (wcs == NULL) {
        return NULL;
    }

    mbs = lib_malloc((strlen(wcs) + 1) * sizeof(char));
    system_wcstombs(mbs, wcs, strlen(wcs) + 1);

    return mbs;
}

static void system_wcstombs_free(char *mbs)
{
    lib_free(mbs);
}

int archdep_network_init(void)
{
    WORD wVersionRequested = MAKEWORD(1, 1);
    WSADATA wsaData;

    WSAStartup(wVersionRequested, &wsaData);

    return 0;
}

void archdep_network_shutdown(void)
{
    WSACleanup();
}

static int archdep_init_extra(int *argc, char **argv)
{
    _fmode = O_BINARY;

    _setmode(_fileno(stdin), O_BINARY);
    _setmode(_fileno(stdout), O_BINARY);

    argv0 = lib_stralloc(argv[0]);

    orig_workdir = getcwd(NULL, MAX_PATH);

    return 0;
}

static char *program_name = NULL;

char *archdep_program_name(void)
{
    if (program_name == NULL) {
        char *s, *e;
        int len;

        s = strrchr(argv0, '\\');
        if (s == NULL) {
            s = argv0;
        } else {
            s++;
        }
        e = strchr(s, '.');
        if (e == NULL) {
            e = argv0 + strlen(argv0);
        }
        len = (int)(e - s + 1);
        program_name = lib_malloc(len);
        memcpy(program_name, s, len - 1);
        program_name[len - 1] = 0;
    }

    return program_name;
}

char boot_path[MAX_PATH];

const char *archdep_boot_path(void)
{
    char *checkpath;

    GetModuleFileName(NULL, boot_path, MAX_PATH);

    checkpath=boot_path+strlen(boot_path);

    while (*checkpath != '\\') {
        checkpath--;
    }
    *checkpath = 0;
    
    return boot_path;
}

char *archdep_default_sysfile_pathlist(const char *emu_id)
{
    static char *default_path;

    if (default_path == NULL) {
        const char *boot_path = archdep_boot_path();

        default_path = util_concat(boot_path, "\\", emu_id, ARCHDEP_FINDPATH_SEPARATOR_STRING,
                                   boot_path, "\\DRIVES", ARCHDEP_FINDPATH_SEPARATOR_STRING,
                                   boot_path, "\\PRINTER", NULL);
    }

    return default_path;
}

/* Return a malloc'ed backup file name for file `fname'.  */
char *archdep_make_backup_filename(const char *fname)
{
    char *tmp;

    tmp = util_concat(fname, NULL);
    tmp[strlen(tmp) - 1] = '~';
    return tmp;
}

char *archdep_default_save_resource_file_name(void)
{
    return archdep_default_resource_file_name();
}

char *archdep_default_resource_file_name(void)
{
    return util_concat(archdep_boot_path(), "\\sdl-vice.ini", NULL);
}

char *archdep_default_fliplist_file_name(void)
{
    return util_concat(archdep_boot_path(), "\\fliplist-", 
                       machine_get_name(), ".vfl", NULL);
}

char *archdep_default_autostart_disk_image_file_name(void)
{
    const char *home;

    home = archdep_boot_path();
    return util_concat(home, "\\autostart-", machine_get_name(), ".d64", NULL);
}

char *archdep_default_hotkey_file_name(void)
{
    return util_concat(archdep_boot_path(), "\\sdl-hotkey-", machine_get_name(), ".vkm", NULL);
}

char *archdep_default_joymap_file_name(void)
{
    return util_concat(archdep_boot_path(), "\\sdl-joymap-", machine_get_name(), ".vjm", NULL);
}

FILE *archdep_open_default_log_file(void)
{
    char *fname;
    FILE *f;

    fname = util_concat(archdep_boot_path(), "\\vice.log", NULL);
    f = fopen(fname, "wt");
    lib_free(fname);

    return f;
}

int archdep_num_text_lines(void)
{
    return 25;
}

int archdep_num_text_columns(void)
{
    return 80;
}

int archdep_default_logger(const char *level_string, const char *txt)
{
    TCHAR *st_out;
    char *out = lib_msprintf("*** %s %s\n", level_string, txt);

    st_out = system_mbstowcs_alloc(out);
    OutputDebugString(st_out);
    system_mbstowcs_free(st_out);
    lib_free(out);
    return 0;
}

int archdep_path_is_relative(const char *path)
{
    if (path == NULL) {
        return 0;
    }

    /* `c:\foo', `c:/foo', `c:foo', `\foo' and `/foo' are absolute.  */

    return !((isalpha(path[0]) && path[1] == ':') || path[0] == '/' || path[0] == '\\');
}

#ifndef WATCOM_COMPILE
#ifndef _S_IREAD
#define _S_IREAD S_IREAD
#endif
#ifndef _S_IWRITE
#define _S_IWRITE S_IWRITE
#endif
#endif

int archdep_spawn(const char *name, char **argv, char **pstdout_redir, const char *stderr_redir)
{
#ifndef WATCOM_COMPILE
    int new_stdout, new_stderr;
    int old_stdout_mode, old_stderr_mode;
    int old_stdout, old_stderr;
    int retval;
    char *stdout_redir = NULL;

    if (pstdout_redir != NULL) {
        if (*pstdout_redir == NULL) {
            *pstdout_redir = archdep_tmpnam();
        }
        stdout_redir = *pstdout_redir;
    }

    new_stdout = new_stderr = old_stdout = old_stderr = -1;

    /* Make sure we are in binary mode.  */
    old_stdout_mode = _setmode(STDOUT_FILENO, _O_BINARY);
    old_stderr_mode = _setmode(STDERR_FILENO, _O_BINARY);

    /* Redirect stdout and stderr as requested, saving the old
       descriptors.  */
    if (stdout_redir != NULL) {
        old_stdout = _dup(STDOUT_FILENO);
        new_stdout = _open(stdout_redir, _O_WRONLY | _O_TRUNC | _O_CREAT, _S_IWRITE | _S_IREAD);
        if (new_stdout == -1) {
            log_error(LOG_DEFAULT, "open(\"%s\") failed: %s.", stdout_redir, strerror(errno));
            retval = -1;
            goto cleanup;
        }
        _dup2(new_stdout, STDOUT_FILENO);
    }
    if (stderr_redir != NULL) {
        old_stderr = _dup(STDERR_FILENO);
        new_stderr = _open(stderr_redir, _O_WRONLY | _O_TRUNC | _O_CREAT, _S_IWRITE | _S_IREAD);
        if (new_stderr == -1) {
            log_error(LOG_DEFAULT, "open(\"%s\") failed: %s.", stderr_redir, strerror(errno));
            retval = -1;
            goto cleanup;
        }
        _dup2(new_stderr, STDERR_FILENO);
    }

    /* Spawn the child process.  */
    retval = (int)_spawnvp(_P_WAIT, name, (const char **)argv);

cleanup:
    if (old_stdout >= 0) {
        _dup2(old_stdout, STDOUT_FILENO);
        _close(old_stdout);
    }
    if (old_stderr >= 0) {
        _dup2(old_stderr, STDERR_FILENO);
        _close(old_stderr);
    }
    if (old_stdout_mode >= 0) {
        _setmode(STDOUT_FILENO, old_stdout_mode);
    }
    if (old_stderr_mode >= 0) {
        _setmode(STDERR_FILENO, old_stderr_mode);
    }
    if (new_stdout >= 0) {
        _close(new_stdout);
    }
    if (new_stderr >= 0) {
        _close(new_stderr);
    }

    return retval;
#else
    return -1;
#endif
}

/* return malloc´d version of full pathname of orig_name */
int archdep_expand_path(char **return_path, const char *orig_name)
{
    /*  Win32 version   */
    *return_path = lib_stralloc(orig_name);
    return 0;
}

void archdep_startup_log_error(const char *format, ...)
{
    char *tmp;
    va_list args;

    va_start(args, format);
    tmp = lib_mvsprintf(format, args);
    va_end(args);

    ui_error(tmp);
    lib_free(tmp);
}

char *archdep_quote_parameter(const char *name)
{
    char *a;

    a = util_concat("\"", name, "\"", NULL);
    return a;
}

char *archdep_filename_parameter(const char *name)
{
    char *exp;
    char *a;

    archdep_expand_path(&exp, name);
    a = archdep_quote_parameter(exp);
    lib_free(exp);
    return a;
}

char *archdep_tmpnam(void)
{
    if (getenv("temp")) {
        return util_concat(getenv("temp"), tmpnam(NULL), NULL);
    } else if (getenv("tmp")) {
        return util_concat(getenv("tmp"), tmpnam(NULL), NULL);
    } else {
        return lib_stralloc(tmpnam(NULL));
    }
}

FILE *archdep_mkstemp_fd(char **filename, const char *mode)
{
    char *tmp;
    FILE *fd;

    if (getenv("temp")) {
        tmp = util_concat(getenv("temp"), tmpnam(NULL), NULL);
    } else if (getenv("tmp")) {
        tmp = util_concat(getenv("tmp"), tmpnam(NULL), NULL);
    } else {
        tmp = lib_stralloc(tmpnam(NULL));
    }

    fd = fopen(tmp, mode);

    if (fd == NULL) {
        return NULL;
    }

    *filename = tmp;

    return fd;
}

int archdep_file_is_gzip(const char *name)
{
    size_t l = strlen(name);

    if ((l < 4 || strcasecmp(name + l - 3, ".gz")) && (l < 3 || strcasecmp(name + l - 2, ".z")) && (l < 4 || toupper(name[l - 1]) != 'Z' || name[l - 4] != '.')) {
        return 0;
    }
    return 1;
}

int archdep_file_set_gzip(const char *name)
{
    return 0;
}

int archdep_mkdir(const char *pathname, int mode)
{
    return _mkdir(pathname);
}

int archdep_stat(const char *file_name, unsigned int *len, unsigned int *isdir)
{
    struct stat statbuf;

    if (stat(file_name, &statbuf) < 0) {
        return -1;
    }

    *len = statbuf.st_size;
    *isdir = S_ISDIR(statbuf.st_mode);

    return 0;
}

/* set permissions of given file to rw, respecting current umask */
int archdep_fix_permissions(const char *file_name)
{
    return _chmod(file_name, _S_IREAD | _S_IWRITE);
}

int archdep_file_is_blockdev(const char *name)
{
    return 0;
}

int archdep_file_is_chardev(const char *name)
{
    if (strcmp(name, "/dev/cbm") == 0) {
        return 1;
    }

    return 0;
}

int archdep_require_vkbd(void)
{
    return 0;
}

static void archdep_shutdown_extra(void)
{
    lib_free(argv0);
    lib_free(orig_workdir);
}

void archdep_workaround_nop(const char *otto)
{
}

int archdep_rtc_get_centisecond(void)
{
    SYSTEMTIME t;

    GetSystemTime(&t);
    return (int)(t.wMilliseconds / 10);
}

#if defined(_MSC_VER) && !defined(WATCOM_COMPILE)
#include "dirent.h"

struct _vice_dir {
    WIN32_FIND_DATA find_data;
    HANDLE handle;
    int first_passed;
    char *filter;
};

DIR *opendir(const char *path)
{
    DIR *dir;
    TCHAR *st_filter;

    dir = lib_malloc(sizeof(DIR));
    dir->filter = util_concat(path, "\\*", NULL);

    st_filter = system_mbstowcs_alloc(dir->filter);
    dir->handle = FindFirstFile(st_filter, &dir->find_data);
    system_mbstowcs_free(st_filter);
    if (dir->handle == INVALID_HANDLE_VALUE) {
        return NULL;
    }

    dir->first_passed = 0;
    return dir;
}

struct dirent *readdir(DIR *dir)
{
    static struct dirent ret;

    if (dir->first_passed) {
        if (!FindNextFile(dir->handle, &dir->find_data)) {
            return NULL;
        }
    }

    dir->first_passed = 1;
    ret.d_name = dir->find_data.cFileName;
    ret.d_namlen = (int)strlen(ret.d_name);

    return &ret;
}

void closedir(DIR *dir)
{
    FindClose(dir->handle);
    lib_free(dir->filter);
    lib_free(dir);
}
#endif

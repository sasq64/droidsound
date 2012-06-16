/* UNIX support tools for uadecore.

   Copyright 2000 - 2005 (C) Heikki Orsila <heikki.orsila@iki.fi>
   
   This module is licensed under the GNU GPL.
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#include <uadectl.h>
#include <uade/unixsupport.h>
// #include <strlrep.h>
#include <android/log.h>

static int uade_amiga_scandir(char *real, char *dirname, char *fake, int ml)
{
  DIR *dir;
  struct dirent *direntry;

  __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "scandir: %s %s %s %d\n", real, dirname, fake, ml);


  if (!(dir = opendir(dirname))) {
    __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Can't open dir (%s) (amiga scandir)\n", dirname);
    return 0;
  }
  while ((direntry = readdir(dir))) {
    if (!strcmp(fake, direntry->d_name)) {
      if (((int) strlcpy(real, direntry->d_name, ml)) >= ml) {
    __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: %s does not fit real", direntry->d_name);
    closedir(dir);
    return 0;
      }
      break;
    }
  }
  if (direntry) {
    closedir(dir);
    return 1;
  }
  rewinddir(dir);
  while ((direntry = readdir(dir))) {
    if (!strcasecmp(fake, direntry->d_name)) {
      if (((int) strlcpy(real, direntry->d_name, ml)) >= ml) {
    __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: %s does not fit real", direntry->d_name);
    closedir(dir);
    return 0;
      }
      break;
    }
  }
  closedir(dir);
  return direntry ? 1 : 0;
}

static char *dirname(char *path)
{
    char *p = &path[strlen(path)];

    while((p > path) && (*p != '/') && (*p != '\\'))
        p--;
    *p = 0;

    return path;
}

char *uade_dirname(char *dst, char *src, size_t maxlen)
{
  char *srctemp = strdup(src);
  if (srctemp == NULL)
    return NULL;
  strlcpy(dst, dirname(srctemp), maxlen);
  free(srctemp);
  return dst;
}


/* opens file in amiga namespace */
FILE *uade_open_amiga_file(char *aname, const char *playerdir)
{
    char *separator;
    char *ptr;
    char copy[PATH_MAX];
    char dirname[PATH_MAX];
    char fake[PATH_MAX];
    char real[PATH_MAX];
    int len;
    DIR *dir;
    FILE *file;

    *real = 0;

    __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Looking for %s (%s)\n", aname, playerdir);

    if (strlcpy(copy, aname, sizeof(copy)) >= sizeof(copy)) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Error: Amiga tried to open a very long filename\nplease REPORT THIS!\n");
        return 0;
    }

    ptr = copy;
     __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Opening %s\n", ptr);
    if ((separator = strchr(ptr, (int) ':')))
    {
        len = (int) (separator - ptr);
        memcpy(dirname, ptr, len);
        dirname[len] = 0;
        if (!strcasecmp(dirname, "ENV"))
        {
            snprintf(dirname, sizeof(dirname), "%s/ENV/", playerdir);
        }
        else if (!strcasecmp(dirname, "S"))
        {
            snprintf(dirname, sizeof(dirname), "%s/S/", playerdir);
        }
        else
        {
            snprintf(dirname, sizeof(dirname), "%c:/", *ptr);
            separator++;
        }
        if (!(dir = opendir(dirname))) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Can't open dir (%s) (volume parsing)\n", dirname);
            return 0;
        }
        closedir(dir);
        ptr = separator + 1;
    }
    else
    {
        if (*ptr == '/') {
            /* Absolute path */
            strlcpy(dirname, "/", sizeof(dirname));
            ptr++;
        } else {
            /* Relative path */
            strlcpy(dirname, "./", sizeof(dirname));
        }
    }

    while ((separator = strchr(ptr, (int) '/'))) {
        len = (int) (separator - ptr);
        if (!len) {
            ptr++;
            continue;
        }
        memcpy(fake, ptr, len);
        fake[len] = 0;
        if (uade_amiga_scandir(real, dirname, fake, sizeof(real))) {
            /* found matching entry */
            if (strlcat(dirname, real, sizeof(dirname)) >= sizeof(dirname)) {
                __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Too long dir path (%s + %s)\n", dirname, real);
                return 0;
            }
            if (strlcat(dirname, "/", sizeof(dirname)) >= sizeof(dirname)) {
                __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Too long dir path (%s + %s)\n", dirname, "/");
                return 0;
            }
        } else {
            /* didn't find entry */
            return 0;
        }
        ptr = separator + 1;
    }

    if (!(dir = opendir(dirname))) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Can't open dir (%s) (after dir scanning)\n", dirname);
        return 0;
    }
    closedir(dir);

    // TFMX HACK
    if(strncasecmp(ptr, "smpl.", 5) == 0)
    {
        char *ext = strcasestr(ptr, ".mdat");
        if(ext) {
            strcpy(ext, ".smpl");
            ptr += 5;
        } else {
            ext = strcasestr(ptr, ".tfx");
            if(ext) {
                strcpy(ext, ".sam");
                ptr += 5;
            }
        }
    }
    else if(strncasecmp(ptr, "ins.", 4) == 0)
    {
        char *ext = strcasestr(ptr, ".sng");

        if(!ext)
            ext = strcasestr(ptr, ".dum");

        if(ext) {
            strcpy(ext, ".ins");
            ptr += 4;
        }
    }
    else if(strncasecmp(ptr, "smp.", 4) == 0)
        {
            char *ext = strcasestr(ptr, ".rjp");
            if(!ext)
                ext = strcasestr(ptr, ".jpn");

            if(ext) {
                strcpy(ext, ".smp");
                ptr += 4;
            }
        }
    __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Final name '%s'", ptr);

    if (uade_amiga_scandir(real, dirname, ptr, sizeof(real))) {
        /* found matching entry */
        if (strlcat(dirname, real, sizeof(dirname)) >= sizeof(dirname)) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Too long dir path (%s + %s)\n", dirname, real);
            return 0;
        }
    } else {
        /* didn't find entry */
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: %s not found from %s\n", ptr, dirname);
        return 0;
    }

    __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Became '%s'\n", dirname);

    if (!(file = fopen(dirname, "rb"))) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Couldn't open file (%s) induced by (%s)\n", dirname, aname);
    }
    return file;
}


void uade_portable_initializations(void)
{
}

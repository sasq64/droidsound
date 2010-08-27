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

#include <uade.h>
#include <unixsupport.h>
// #include <strlrep.h>
#include <android/log.h>

static int uade_amiga_scandir(char *real, char *dirname, char *fake, int ml)
{
  DIR *dir;
  struct dirent *direntry;

  __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "scandir: %s %s %s %d\n", real, dirname, fake, ml);


  if (!(dir = opendir(dirname))) {
    __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: can't open dir (%s) (amiga scandir)\n", dirname);
    return 0;
  }
  while ((direntry = readdir(dir))) {
    if (!strcmp(fake, direntry->d_name)) {
      if (((int) strlcpy(real, direntry->d_name, ml)) >= ml) {
	__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: %s does not fit real", direntry->d_name);
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
	__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: %s does not fit real", direntry->d_name);
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
		__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: error: amiga tried to open a very long filename\nplease REPORT THIS!\n");
		return 0;
	}

	ptr = copy;
	 __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: opening %s\n", ptr);
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
			//__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: open_amiga_file: unknown amiga volume (%s)\n", aname);
			//return 0;
		}
		if (!(dir = opendir(dirname))) {
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: can't open dir (%s) (volume parsing)\n", dirname);
			return 0;
		}
		closedir(dir);
		/* __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: opening from dir %s\n", dirname); */
		ptr = separator + 1;
	}
	else
	{
		if (*ptr == '/') {
			/* absolute path */
			strlcpy(dirname, "/", sizeof(dirname));
			ptr++;
		} else {
			/* relative path */
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
				__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: too long dir path (%s + %s)\n", dirname, real);
				return 0;
			}
			if (strlcat(dirname, "/", sizeof(dirname)) >= sizeof(dirname)) {
				__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: too long dir path (%s + %s)\n", dirname, "/");
				return 0;
			}
		} else {
			/* didn't find entry */
			/* __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: %s not found from (%s) (dir scanning)\n", fake, dirname); */
			return 0;
		}
		ptr = separator + 1;
	}
	/* __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: pass 3: (%s) (%s)\n", dirname, ptr); */

	if (!(dir = opendir(dirname))) {
		__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "can't open dir (%s) (after dir scanning)\n", dirname);
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
		}
	} else if(strncasecmp(ptr, "ins.", 4) == 0)
	{
		char *ext = strcasestr(ptr, ".sng");

		if(!ext)
			ext = strcasestr(ptr, ".dum");

		if(ext) {
			strcpy(ext, ".ins");
			ptr += 4;
		}
	}

	if (uade_amiga_scandir(real, dirname, ptr, sizeof(real))) {
		/* found matching entry */
		if (strlcat(dirname, real, sizeof(dirname)) >= sizeof(dirname)) {
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: too long dir path (%s + %s)\n", dirname, real);
			return 0;
		}
	} else {
		/* didn't find entry */
		__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: %s not found from %s\n", ptr, dirname);
		return 0;
	}

	__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Became '%s'\n", dirname);

	if (!(file = fopen(dirname, "rb"))) {
		__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "uade: couldn't open file (%s) induced by (%s)\n", dirname, aname);
	}
	return file;
}


void uade_portable_initializations(void)
{
}

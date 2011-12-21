/* UNIX support tools

   Copyright 2000-2011 (C) Heikki Orsila <heikki.orsila@iki.fi>
   
   This module is licensed under the GNU LGPL.
*/

#include <uade/uadeipc.h>
#include <uade/unixatomic.h>

#include <assert.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int url_to_fd(const char *url, int flags, mode_t mode)
{
	int fd;
	if (strncmp(url, "fd://", 5) == 0) {
		char *endptr;
		if (url[5] == 0)
			return -1;
		fd = strtol(&url[5], &endptr, 10);
		if (*endptr != 0)
			return -1;
	} else {
		if (flags & O_WRONLY) {
			fd = open(url, flags, mode);
		} else {
			fd = open(url, flags);
		}
	}
	if (fd < 0)
		fd = -1;
	return fd;
}

int uade_filesize(size_t *size, const char *pathname)
{
	struct stat st;
	if (stat(pathname, &st))
		return -1;
	if (size)
		*size = st.st_size;
	return 0;
}

int uade_ipc_get_fd(void *f)
{
	return (intptr_t) f;
}

void *uade_ipc_set_input(const char *input)
{
	int fd;
	if ((fd = url_to_fd(input, O_RDONLY, 0)) < 0) {
		fprintf(stderr, "can not open input file %s: %s\n", input, strerror(errno));
		exit(1);
	}
	return (void *) ((intptr_t) fd);
}


void *uade_ipc_set_output(const char *output)
{
	int fd;
	if ((fd = url_to_fd(output, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
		fprintf(stderr, "can not open output file %s: %s\n", output, strerror(errno));
		exit(1);
	}
	return (void *) ((intptr_t) fd);
}


static int uade_amiga_scandir(char *real, char *dirname, char *fake, int ml)
{
	DIR *dir;
	struct dirent *direntry;
	if (!(dir = opendir(dirname))) {
		fprintf(stderr, "uade: can't open dir (%s) (amiga scandir)\n", dirname);
		return 0;
	}
	while ((direntry = readdir(dir))) {
		if (!strcmp(fake, direntry->d_name)) {
			if (((int) strlcpy(real, direntry->d_name, ml)) >= ml) {
				fprintf(stderr, "uade: %s does not fit real", direntry->d_name);
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
				fprintf(stderr, "uade: %s does not fit real", direntry->d_name);
				closedir(dir);
				return 0;
			}
			break;
		}
	}
	closedir(dir);
	return direntry != NULL;
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


/* Find file in amiga namespace */
int uade_find_amiga_file(char *realname, size_t maxlen, const char *aname, const char *playerdir)
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

	if (strlcpy(copy, aname, sizeof(copy)) >= sizeof(copy)) {
		fprintf(stderr, "uade: error: amiga tried to open a very long filename\nplease REPORT THIS!\n");
		return -1;
	}
	ptr = copy;
	if ((separator = strchr(ptr, (int) ':'))) {
		len = (int) (separator - ptr);
		memcpy(dirname, ptr, len);
		dirname[len] = 0;
		if (!strcasecmp(dirname, "ENV")) {
			snprintf(dirname, sizeof(dirname), "%s/ENV/", playerdir);
		} else if (!strcasecmp(dirname, "S")) {
			snprintf(dirname, sizeof(dirname), "%s/S/", playerdir);
		} else {
			fprintf(stderr, "uade: open_amiga_file: unknown amiga volume (%s)\n", aname);
			return -1;
		}
		if (!(dir = opendir(dirname))) {
			fprintf(stderr, "uade: can't open dir (%s) (volume parsing)\n", dirname);
			return -1;
		}
		closedir(dir);
		ptr = separator + 1;
	} else {
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
				fprintf(stderr, "uade: too long dir path (%s + %s)\n", dirname, real);
				return -1;
			}
			if (strlcat(dirname, "/", sizeof(dirname)) >= sizeof(dirname)) {
				fprintf(stderr, "uade: too long dir path (%s + %s)\n", dirname, "/");
				return -1;
			}
		} else {
			/* didn't find entry */
			return -1;
		}
		ptr = separator + 1;
	}

	if (!(dir = opendir(dirname))) {
		fprintf(stderr, "can't open dir (%s) (after dir scanning)\n", dirname);
		return -1;
	}
	closedir(dir);

	if (uade_amiga_scandir(real, dirname, ptr, sizeof(real))) {
		/* found matching entry */
		if (strlcat(dirname, real, sizeof(dirname)) >= sizeof(dirname)) {
			fprintf(stderr, "uade: too long dir path (%s + %s)\n", dirname, real);
			return -1;
		}
	} else {
		/* didn't find entry */
		return -1;
	}

	file = fopen(dirname, "rb");
	if (file == NULL) {
		fprintf (stderr, "uade: couldn't open file (%s) induced by (%s)\n", dirname, aname);
		return -1;
	}
	fclose(file);
	strlcpy(realname, dirname, maxlen);
	return 0;
}

void uade_arch_kill_and_wait_uadecore(struct uade_ipc *ipc, pid_t *uadepid)
{
	if (*uadepid == 0)
		return;

	if (kill(*uadepid, SIGKILL)) {
		fprintf(stderr, "uade_arch_kill_and_wait_uadecore(): uadecore has already terminated\n");
		*uadepid = 0;
		return;
	}

	/*
	 * Wait until one of two happens:
	 * 1. uadepid is successfully handled (waitpid() returns uadepid)
	 * 2. someone else has processed uadepid (waitpid() returns -1)
	 */
	while (waitpid(*uadepid, NULL, 0) == -1 && errno == EINTR);

	*uadepid = 0;
}

int uade_arch_spawn(struct uade_ipc *ipc, pid_t *uadepid, const char *uadename)
{
	int fds[2];
	char input[32], output[32];

	if (socketpair(AF_UNIX, SOCK_STREAM, 0, fds)) {
		fprintf(stderr, "Can not create socketpair: %s\n", strerror(errno));
		return -1;
	}

	*uadepid = fork();
	if (*uadepid < 0) {
		fprintf(stderr, "Fork failed: %s\n", strerror(errno));
		return -1;
	}

	/* The child (*uadepid == 0) will execute uadecore */
	if (*uadepid == 0) {
		int fd;
		int maxfds;
		sigset_t sigset;

		/* Unblock SIGTERM in the child, we might need it */
		sigemptyset(&sigset);
		sigaddset(&sigset, SIGTERM);
		sigprocmask(SIG_UNBLOCK, &sigset, NULL);

		if ((maxfds = sysconf(_SC_OPEN_MAX)) < 0) {
			maxfds = 1024;
			fprintf(stderr, "Getting max fds failed. Using %d.\n", maxfds);
		}

		/* close everything else but stdin, stdout, stderr, and in/out fds */
		for (fd = 3; fd < maxfds; fd++) {
			if (fd != fds[1])
				uade_atomic_close(fd);
		}

		/* give in/out fds as command line parameters to the uade process */
		snprintf(input, sizeof(input), "fd://%d", fds[1]);
		snprintf(output, sizeof(output), "fd://%d", fds[1]);

		execlp(uadename, uadename, "-i", input, "-o", output, (char *) NULL);
		fprintf(stderr, "uade execlp (%s) failed: %s\n", uadename, strerror(errno));
		abort();
	}

	/* Close fds that the uadecore uses */
	if (uade_atomic_close(fds[1]) < 0) {
		fprintf(stderr, "Could not close uadecore fds: %s\n", strerror(errno));
		kill (*uadepid, SIGKILL);
		return -1;
	}

	snprintf(output, sizeof output, "fd://%d", fds[0]);
	snprintf(input, sizeof input, "fd://%d", fds[0]);
	uade_set_peer(ipc, 1, input, output);

	return 0;
}

/*
 * A hack that converts X:\something style windows names into cygwin style name
 * /cygdrive/X/something. All '\\' characters are converted into '/'
 * characters.
 */
char *uade_windows_to_cygwin_path(const char *path)
{
	size_t i;
	char *s;
	size_t len = strlen(path);

	if (len == 0)
		return calloc(1, 1);

	if (len >= 2 && isalpha(path[0]) && path[1] == ':') {
		/* uses windows drive names */
		size_t newlen = len + 32;
		s = malloc(newlen);
		if (s != NULL)
			snprintf(s, newlen, "/cygdrive/%c/%s", path[0], &path[2]);
	} else {
		s = strdup(path);
	}
	if (s == NULL)
		return NULL;

	for (i = 0; s[i] != 0; i++) {
		if (s[i] == '\\')
			s[i] = '/';
	}

	return s;
}

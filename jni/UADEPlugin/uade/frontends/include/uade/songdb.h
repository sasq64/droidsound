#ifndef _UADE_SONGDB_H_
#define _UADE_SONGDB_H_

#include <uade/eagleplayer.h>
#include "vplist.h"

struct uade_content {
	char md5[33];
	uint32_t playtime;	/* in milliseconds */
	struct vplist *subs;
};

struct eaglesong {
	int flags;
	char md5[33];
	struct uade_attribute *attributes;
};

struct persub {
	int sub;
	char *normalisation;
};

struct uade_songdb {
	struct uade_content *contentchecksums;
	size_t nccused;	      /* number of valid entries in content db */
	size_t nccalloc;      /* number of allocated entries for content db */
	int ccmodified;
	int cccorrupted;

	size_t nsongs;
	struct eaglesong *songstore;
};

struct uade_state;

struct uade_content *uade_add_playtime(struct uade_state *state, const char *md5, uint32_t playtime);
int uade_alloc_song(struct uade_state *state, const char *filename);
void uade_lookup_volume_normalisation(struct uade_state *state);
int uade_read_content_db(const char *filename, struct uade_state *state);
int uade_read_song_conf(const char *filename, struct uade_state *state);
void uade_save_content_db(const char *filename, struct uade_state *state);
int uade_test_silence(void *buf, size_t size, struct uade_state *state);
void uade_unalloc_song(struct uade_state *state);
int uade_update_song_conf(const char *songconfin, const char *songconfout, const char *songname, const char *options);

#endif

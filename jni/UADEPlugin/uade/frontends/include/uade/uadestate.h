#ifndef _UADE_STATE_H_
#define _UADE_STATE_H_

#include <uade/eagleplayer.h>
#include <uade/effects.h>
#include <uade/uadeipc.h>
#include <uade/songdb.h>
#include <uade/uadeutils.h>

#include <bencodetools/bencode.h>

#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>

enum uade_event_type {
	UADE_EVENT_INVALID = 0,  /* Very bad! Terminate playback! */
	UADE_EVENT_DATA,         /* Sample data for player */

	/*
	 * Call uade_get_event() again when there is data available on file
	 * descriptor returned by uade_get_fd()
	 */
	UADE_EVENT_EAGAIN,

	UADE_EVENT_FORMAT_NAME,  /* You shouldn't get this event (internal) */
	UADE_EVENT_MESSAGE,      /* Arbitrary debug message from Amiga */
	UADE_EVENT_MODULE_NAME,  /* You shouldn't get this event (internal) */
	UADE_EVENT_PLAYER_NAME,  /* You shouldn't get this event (internal) */
	UADE_EVENT_READY,        /* You shouldn't get this event (internal) */
	UADE_EVENT_REQUEST_AMIGA_FILE, /* uadecore requests a file (internal) */
	UADE_EVENT_SONG_END,     /* (sub)song ends */
	UADE_EVENT_SUBSONG_INFO, /* You shouldn't get this event (internal) */
};

struct uade_event_data {
	size_t size;
	uint8_t data[UADE_MAX_MESSAGE_SIZE];
};

struct uade_event_songend {
	int happy;
	int stopnow; /* non-zero iff playing should be stopped now */
	int tailbytes;
	char reason[256];
};

struct uade_event_subsongs {
	int cur; /* current subsong */
	int min;
	int def; /* default subsong */
	int max;
};

struct uade_event {
	enum uade_event_type type;
	union {
		struct uade_event_data data;
		char msg[1024];
		struct uade_event_songend songend;
		struct uade_event_subsongs subsongs;
	};
};

/* Maximum number of bytes, including '\0', in file name extension */
#define UADE_MAX_EXT_LEN 16

struct uade_detection_info {
	int custom;
	int content;
	char ext[UADE_MAX_EXT_LEN];
	struct eagleplayer *ep;
};

struct uade_song_info {
	struct uade_event_subsongs subsongs;
	char modulefname[PATH_MAX];
	size_t modulefsize;
	char modulemd5[33];         /* hexadecimal string of song content */
	char playerfname[PATH_MAX];
	int playtime;         /* In milliseconds. -1 if unknown. */
	char formatname[256];
	char modulename[256];
	char playername[256];

	int64_t subsongbytes;
	int64_t songbytes;
	int bytespersecond;

	/*
	 * Should we record playing time? For example, we don't record the play
	 * time if playback was ended prematurely or subsong seeking was done.
	 */
	int recordsongtime;
	int recordsubsongtime;

	struct uade_detection_info detectioninfo;
};

enum uade_state_symbol {
	UADE_STATE_INVALID = 0,
	UADE_STATE_INITIALIZED,
	UADE_STATE_RECEIVE_MSGS,
	UADE_STATE_SONG_END_PENDING,
	UADE_STATE_WAIT_SUBSONG_CHANGE,
	UADE_STATE_ERROR,
};

struct uade_song_state {
	enum uade_state_symbol state;

	int seekmode;      /* non-zero if in seek state */
	uint64_t seekoffs; /* byte offset to seek to */

	unsigned int bytesrequested; /* bytes requested from uadecore */

	struct uade_event endevent;

	int newsubsong; /* Non-negative for subsong change */
	uint64_t newsubsongseek; /* Positive value for seeking */

	struct uade_song_info info;

	int64_t silencecount;

	struct uade_ep_options ep_options;
	int flags;
	struct uade_attribute *songattributes;
};

struct uade_state {
	/* Per song members */
	struct uade_config config;
	struct uade_effect_state effectstate;
	struct uade_song_state song;
	struct bencode *rmc;

	/* Permanent members */
	int validconfig;
	struct uade_config permconfig;
	char permconfigname[PATH_MAX];
	int setdebug; /* non-zero if going to break execution into debug mode */

	/* extra config, such as config options from the command line */
	struct uade_config extraconfig;

	struct eagleplayerstore *playerstore;
	struct uade_ipc ipc;
	pid_t pid;

	struct uade_songdb songdb;
	char songdbname[PATH_MAX];

	struct uade_file *(*amigaloader)(const char *name, const char *playerdir, void *context, struct uade_state *state);
	void *amigaloadercontext;
};

#endif

#include <uade/uade.h>
#include <uade/uadeutils.h>
#include <uade/unixatomic.h>
#include <uade/rmc.h>

#include <assert.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

static void load_content_db(struct uade_state *state)
{
	struct stat st;
	char name[PATH_MAX];

	/* Try to read global database, this does not override any data
	   from user database */
	snprintf(name, sizeof name, "%s/contentdb", state->config.basedir.name);
	if (stat(name, &st) == 0)
		uade_read_content_db(name, state);

	char *home = uade_open_create_home();
	if (!home)
		return;

	snprintf(name, sizeof name, "%s/.uade2/contentdb", home);
	snprintf(state->songdb.ccfilename, sizeof(state->songdb.ccfilename), "%s", name);

	if (stat(name, &st) == 0) {
		if (uade_read_content_db(name, state))
			return;
	} else {
		/* We create an empty file on the first run */
		FILE *f = fopen(name, "w");
		if (f)
			fclose(f);
		uade_read_content_db(name, state);
	}
}


static void save_content_db(struct uade_state *state)
{
	struct stat st;
	const char *fname = state->songdb.ccfilename;

	if (!fname[0] || stat(fname, &st))
		return;

	if (state->songdb.ccloadtime < st.st_mtime)
		uade_read_content_db(fname, state);

	uade_save_content_db(fname, state);
}

static void prepare_configs(struct uade_state *state)
{
	state->config = state->permconfig;
	uade_merge_configs(&state->config, &state->extraconfig);
}

static int get_bytes_per_second(const struct uade_state *state)
{
	return UADE_BYTES_PER_FRAME * state->config.frequency;
}

void uade_cleanup_state(struct uade_state *state)
{
	if (state == NULL)
		return;

	uade_stop(state);

	save_content_db(state);

	uade_arch_kill_and_wait_uadecore(&state->ipc, &state->pid);

	memset(state, 0, sizeof(*state));

	free(state);
}

static void get_string(struct uade_event *event, struct uade_msg *um)
{
	uade_check_fix_string(um, 256);
	strlcpy(event->msg, (char *) um->data, sizeof event->msg);
}

static void set_end_event(struct uade_event *event, int tailbytes,
			  int happy, int stopnow,
			  const char *reason, struct uade_state *state)
{
	struct uade_event_subsongs *subs = &state->song.info.subsongs;
	int lastsubsong = (subs->cur >= subs->max) || (subs->cur < subs->min);

	event->type = UADE_EVENT_SONG_END;
	event->songend.tailbytes = tailbytes;
	event->songend.happy = happy;
	event->songend.stopnow = (!happy || stopnow || lastsubsong);

	strlcpy(event->songend.reason, reason, sizeof event->songend.reason);

	state->song.endevent = *event;
}

static void set_state(enum uade_state_symbol newstate, struct uade_state *state)
{
	state->song.state = newstate;
}

static int error_state(struct uade_state *state)
{
	set_state(UADE_STATE_ERROR, state);
	return -1;
}

static int receive_message(struct uade_event *event, struct uade_state *state)
{
	uint8_t space[UADE_MAX_MESSAGE_SIZE];
	struct uade_msg *um = (struct uade_msg *) space;
	uint16_t *data;
	uint16_t *sm;
	unsigned int u;
	int i;
	char *reason;
	int tailbytes;
	int happy;
	int minsubsong, cursubsong, maxsubsong;

	if (uade_receive_message(um, sizeof space, &state->ipc) <= 0)
		goto error;

	switch (um->msgtype) {
	case UADE_COMMAND_TOKEN:
		event->type = UADE_EVENT_READY;
		break;

	case UADE_COMMAND_REQUEST_AMIGA_FILE:
		event->type = UADE_EVENT_REQUEST_AMIGA_FILE;
		get_string(event, um);
		break;

	case UADE_REPLY_DATA:
		event->type = UADE_EVENT_DATA;
		data = (uint16_t *) event->data.data;

		assert(um->size == state->song.bytesrequested);
		assert(um->size % 2 == 0);
		assert(sizeof event->data.data >= um->size);
		event->data.size = um->size;

		sm = (uint16_t *) um->data;
		for (u = 0; u < um->size; u += 2) {
			*data = ntohs(*sm);
			sm++;
			data++;
		}

		break;

	case UADE_REPLY_FORMATNAME:
		event->type = UADE_EVENT_FORMAT_NAME;
		get_string(event, um);
		break;
	
	case UADE_REPLY_MODULENAME:
		event->type = UADE_EVENT_MODULE_NAME;
		get_string(event, um);
		break;

	case UADE_REPLY_MSG:
		event->type = UADE_EVENT_MESSAGE;
		get_string(event, um);
		break;
		
	case UADE_REPLY_PLAYERNAME:
		event->type = UADE_EVENT_PLAYER_NAME;
		get_string(event, um);
		break;

	case UADE_REPLY_SONG_END:
		if (um->size < 9) {
			uade_warning("Invalid song end reply: too short\n");
			goto error;
		}
		tailbytes = read_be_u32(um->data);
		if (tailbytes > sizeof event->data.data) {
			uade_warning("Too long a tail data\n");
			goto error;
		}
		happy = (read_be_u32(um->data + 4) == 0);
		reason = (char *) &um->data[8];
		for (i = 0; reason[i] && i < (um->size - 8); i++);
		if (reason[i] != 0 || (i != (um->size - 9))) {
			uade_warning("Broken reason string with song end notice\n");
			goto error;
		}
		set_end_event(event, tailbytes, happy, 0, reason, state);
		break;

	case UADE_REPLY_SUBSONG_INFO:
		if (um->size != 12) {
			uade_warning("\nsubsong info: too short a message\n");
			goto error;
		}

		minsubsong = read_be_u32(um->data);
		maxsubsong = read_be_u32(um->data + 4);
		cursubsong = read_be_u32(um->data + 8);

		/*
		 * Use cursubsong as the reference value, but do check it
		 * to be non-negative.
		 */
		if (cursubsong < 0) {
			uade_warning("\ncursubsong = %d\n", cursubsong);
			cursubsong = 0;
		}
		if (minsubsong < 0) {
			uade_warning("\nminsubsong = %d\n", minsubsong);
			minsubsong = cursubsong;
		}
		if (maxsubsong < 0) {
			uade_warning("\nmaxsubsong = %d\n", maxsubsong);
			maxsubsong = cursubsong;
		}

		if (!(0 <= minsubsong && minsubsong <= cursubsong && cursubsong <= maxsubsong)) {
			uade_warning("\nThe eagleplayer is broken. Subsong info does not match in %s\n", state->song.info.modulefname);
			if (minsubsong > cursubsong)
				minsubsong = cursubsong;
			if (maxsubsong < cursubsong)
				maxsubsong = cursubsong;
		}

		uade_debug(state, "\nsubsong: %d from range [%d, %d]\n", cursubsong, minsubsong, maxsubsong);

		event->type = UADE_EVENT_SUBSONG_INFO;
		event->subsongs.min = minsubsong;
		event->subsongs.cur = cursubsong;
		event->subsongs.def = cursubsong;
		event->subsongs.max = maxsubsong;
		break;
	
	default:
		uade_warning("Bad message type from uadecore: %u.\n", (unsigned int) um->msgtype);
		goto error;
	}

	return 0;

error:
	event->type = UADE_EVENT_INVALID;
	return -1;
}

struct uade_file *uade_load_amiga_file(const char *name, const char *playerdir,
				       struct uade_state *state)
{
	char fname[PATH_MAX];

	/* Do not load file names that contain ':' from rmc container */
	if (strchr(name, ':') == NULL && state->rmc != NULL)
		return uade_rmc_get_file(state->rmc, name);

	if (uade_find_amiga_file(fname, sizeof fname, name, playerdir))
		return NULL;

	return uade_file_load(fname);
}

void uade_set_amiga_loader(struct uade_file * (*amigaloader)(const char *name, const char *playerdir, void *context, struct uade_state *state),
			   void *context, struct uade_state *state)
{
	state->amigaloader = amigaloader;
	state->amigaloadercontext = context;
}

static int send_file_back(struct uade_file *f, const char *name,
			  struct uade_state *state)
{
	/* Hack, force us to send state */
	assert(state->ipc.state == UADE_R_STATE);
	state->ipc.state = UADE_S_STATE;
	if (f != NULL)
		uade_debug(state, "Sending file: %s\n", f->name);
	else
		uade_debug(state, "Can not send file: %s\n", name);
	if (uade_send_file(f, &state->ipc)) {
		uade_warning("IPC failed: Can not send file: %s\n", name);
		uade_file_free(f);
		return -1;
	}
	state->ipc.state = UADE_R_STATE;
	uade_file_free(f);
	return 0;
}

static int handle_request_amiga_file(const char *name, struct uade_state *state)
{
	struct uade_file *f = NULL;
	char playerdir[PATH_MAX];
	uade_debug(state, "Amiga requests file: %s\n", name);
	if (state->song.info.playerfname[0] == 0)
		goto sendfile;
	if (uade_dirname(playerdir, state->song.info.playerfname, sizeof playerdir) == NULL) {
		uade_warning("Can not get playerdir for %s\n", state->song.info.playerfname);
		goto sendfile;
	}

	if (state->amigaloader)
		f = state->amigaloader(name, playerdir, state->amigaloadercontext, state);
	else
		f = uade_load_amiga_file(name, playerdir, state);

sendfile:
	return send_file_back(f, name, state);
}

const char *uade_event_name(const struct uade_event *event)
{
#define EVENT_CASE(t) case t: return # t
	switch(event->type) {
	EVENT_CASE(UADE_EVENT_DATA);
	EVENT_CASE(UADE_EVENT_EAGAIN);
	EVENT_CASE(UADE_EVENT_FORMAT_NAME);
	EVENT_CASE(UADE_EVENT_MESSAGE);
	EVENT_CASE(UADE_EVENT_MODULE_NAME);
	EVENT_CASE(UADE_EVENT_PLAYER_NAME);
	EVENT_CASE(UADE_EVENT_READY);
	EVENT_CASE(UADE_EVENT_SONG_END);
	EVENT_CASE(UADE_EVENT_SUBSONG_INFO);
	default:
		return "UADE_EVENT_INVALID";
	}
}

static int send_token(struct uade_state *state)
{
	if (uade_send_short_message(UADE_COMMAND_TOKEN, &state->ipc)) {
		uade_warning("Can not send token!\n");
		return -1;
	}
	return 0;
}

static int read_request(struct uade_state *state)
{
	state->song.bytesrequested = uade_read_request(state);
	if (!state->song.bytesrequested || send_token(state)) {
		uade_warning("Can not send read request!\n");
		return -1;
	}
	return 0;
}

/*
 * This function directly commands the uadecore to change subsong,
 * and uade_state does a transition to a new subsong.
 */
static int set_subsong(struct uade_state *state)
{
	int cmd = (state->song.state == UADE_STATE_INITIALIZED) ? UADE_COMMAND_SET_SUBSONG : UADE_COMMAND_CHANGE_SUBSONG;

	assert(state->song.newsubsong >= 0);
	assert(state->ipc.state == UADE_S_STATE);

	state->song.silencecount = 0;
	state->song.info.subsongbytes = 0;

	state->song.info.recordsubsongtime = 1;

	memset(&state->song.endevent, 0, sizeof state->song.endevent);

	uade_subsong_control(state->song.newsubsong, cmd, &state->ipc);

	state->song.info.subsongs.cur = state->song.newsubsong;

	if (state->song.newsubsongseek > 0) {
		state->song.seekmode = 1;
		state->song.seekoffs = state->song.newsubsongseek;
	} else {
		state->song.seekmode = 0;
		state->song.seekoffs = 0;
	}

	state->song.newsubsong = -1;
	state->song.newsubsongseek = 0;

	return 0;
}

int uade_next_subsong(struct uade_state *state)
{
	/* Called after getting song end event */
	if (state->song.info.subsongs.cur < 0)
		return -1;
	return uade_set_subsong(state->song.info.subsongs.cur + 1, state);
}

static void dont_record_playtime(struct uade_state *state)
{
	state->song.info.recordsongtime = 0;
	state->song.info.recordsubsongtime = 0;
}

int uade_set_subsong(int subsong, struct uade_state *state)
{
	struct uade_event_subsongs *subs = &state->song.info.subsongs;

	if (subs->cur < 0)
		return -1;
	if (subsong < 0)
		subsong = subs->def;
	if (subsong > subs->max)
		return -1;

	if (state->song.state != UADE_STATE_WAIT_SUBSONG_CHANGE || subsong != (subs->cur + 1)) {
		/*
		 * Subsong switched manually, or a subsong other than the
		 * next one was requested
		 */
		dont_record_playtime(state);
	}

	state->song.newsubsong = subsong;
	return 0;
}

int set_subsong_and_seek(int subsong, int64_t seekoffs,
			 struct uade_state *state)
{
	if (uade_set_subsong(subsong, state))
		return -1;

	state->song.newsubsongseek = seekoffs;
	return 0;
}

int uade_seek(int msecs, int subsong, struct uade_state *state)
{
	int cursub = state->song.info.subsongs.cur;
	int relative = (subsong < 0);
	const int framesize = UADE_BYTES_PER_FRAME;
	int64_t seekoffs = (((int64_t) msecs) * get_bytes_per_second(state)) / 1000;
	seekoffs = (seekoffs / framesize) * framesize;

	if (!relative && msecs < 0) {
		uade_warning("Time value must be set to a non-negative value for absolute time seeking.\n");
		return -1;
	}

	if (relative) {
		subsong = cursub;

		if (state->song.seekmode)
			seekoffs += state->song.seekoffs;
		else
			seekoffs += state->song.info.subsongbytes;

		if (seekoffs < 0)
			seekoffs = 0;
	}

	/*
	 * We do seeking backwards and seeking to another subsong by restarting
	 * the subsong, and later put us into seekmode.
	 */
	if (!relative || seekoffs < state->song.info.subsongbytes)
		return set_subsong_and_seek(subsong, seekoffs, state);

	state->song.seekoffs = seekoffs;
	state->song.seekmode = 1;
	return 0;
}

const struct uade_song_info *uade_get_song_info(const struct uade_state *state)
{
	return &state->song.info;
}

int uade_get_sampling_rate(const struct uade_state *state)
{
	int frequency = state->config.frequency;
	assert(frequency > 0);
	return frequency;
}

static int get_pending_events(struct uade_state *state)
{
	uint8_t space[UADE_MAX_MESSAGE_SIZE];
	struct uade_msg *um = (struct uade_msg *) space;
	int ret;

	while (state->ipc.state == UADE_R_STATE) {
		ret = uade_receive_message(um, sizeof space, &state->ipc);
		if (ret <= 0) {
			uade_warning("uadeipc error: can not get pending messages\n");
			return error_state(state);
		}
		if (um->msgtype == UADE_COMMAND_REQUEST_AMIGA_FILE) {
			if (send_file_back(NULL, "invalid", state)) {
				uade_warning("Can not flush send file\n");
				return error_state(state);
			}
		}
	}

	return 0;
}

static int handle_seek(struct uade_event *event, struct uade_state *state)
{
	ssize_t diff;
	ssize_t skipfrombuffer;

	if (!state->song.seekmode)
		return 0;

	diff = state->song.info.subsongbytes - state->song.seekoffs;
	if (diff < 0)
		return -1; /* Not reached seek place yet */

	state->song.seekmode = 0;
	state->song.seekoffs = 0;

	if (diff == 0)
		return -1;

	/* We have diff bytes in buffer to play, and the rest is skipped */
	skipfrombuffer = event->data.size - diff;
	assert(skipfrombuffer >= 0);

	memmove(event->data.data, event->data.data + skipfrombuffer, diff);

	event->data.size = diff;
	return 0;
}

static int test_timeouts(struct uade_event *event, struct uade_state *state)
{
	int bytespersec = get_bytes_per_second(state);

	if (uade_test_silence(event->data.data, event->data.size, state)) {
		set_end_event(event, 0, 1, 0, "silence", state);
		return 1;
	}

	if (!state->config.use_timeouts)
		return 0;

	if (state->config.timeout >= 0 &&
	    (state->song.info.songbytes / bytespersec) >= state->config.timeout) {
		dont_record_playtime(state);
		set_end_event(event, 0, 1, 1, "song timeout", state);
		return 1;
	}

	if (state->config.subsong_timeout >= 0 &&
	    (state->song.info.subsongbytes / bytespersec) >= state->config.subsong_timeout) {
		dont_record_playtime(state);
		set_end_event(event, 0, 1, 0, "subsong timeout", state);
		return 1;
	}

	return 0;
}

static int handle_data(struct uade_event *event, struct uade_state *state)
{
	int isend = (state->song.state == UADE_STATE_SONG_END_PENDING);
	int nframes;

	/* The last batch of sound data is only partial */
	if (isend)
		event->data.size = state->song.endevent.songend.tailbytes;

	state->song.info.subsongbytes += event->data.size;
	state->song.info.songbytes += event->data.size;

	if (!isend && test_timeouts(event, state))
		return 0;

	if (handle_seek(event, state)) {
		/*
		 * We don't return -1 on a song end situation, because
		 * the application must see the song end despite skipping
		 */
		if (!isend)
			return -1;
	}

	nframes = event->data.size / UADE_BYTES_PER_FRAME;
	uade_effect_run(&state->effectstate, (int16_t *) event->data.data, nframes);

	return 0;
}

static int test_set_debug(struct uade_state *state)
{
	if (!state->setdebug)
		return 0;
	state->setdebug = 0;
	return uade_send_short_message(UADE_COMMAND_ACTIVATE_DEBUGGER, &state->ipc);
}

static int receive_messages(struct uade_event *event, struct uade_state *state)
{
	while (1) {
		if (receive_message(event, state)) {
			uade_warning("Invalid event\n");
			return error_state(state);
		}

		switch (event->type) {
		case UADE_EVENT_SONG_END:
			state->song.endevent = *event;
			set_state(UADE_STATE_SONG_END_PENDING, state);
			/*
			 * Continue event loop until the last data comes.
			 * In practice, we quit this loop the next time
			 * UADE_EVENT_DATA comes.
			 */
			break;

		case UADE_EVENT_DATA:
			if (handle_data(event, state))
				break;
			return 0;

		case UADE_EVENT_READY:
			assert(state->ipc.state == UADE_S_STATE);

			if (test_set_debug(state))
				return error_state(state);

			if (state->song.newsubsong >= 0) {
				if (set_subsong(state)) {
					set_end_event(event, 0, 0, 0, "Invalid subsong change", state);
					return 0;
				}
			}

			if (read_request(state))
				return error_state(state);

			event->type = UADE_EVENT_EAGAIN;
			return 0;

		case UADE_EVENT_REQUEST_AMIGA_FILE:
			if (handle_request_amiga_file(event->msg, state))
				return error_state(state);
			break;

		default:
			if (state->song.state != UADE_STATE_SONG_END_PENDING)
				return 0;
			break;
		}
	}
	assert(0);
}

int uade_get_event(struct uade_event *event, struct uade_state *state)
{
	event->type = UADE_EVENT_INVALID;

	while (1) {
		switch (state->song.state) {
		case UADE_STATE_INITIALIZED:
			/* The first call to uade_get_event() */

			assert(state->ipc.state == UADE_S_STATE);

			if (state->song.newsubsong >= 0) {
				if (set_subsong(state)) {
					set_end_event(event, 0, 0, 0, "Can not set starting subsong", state);
					return 0;
				}
			}

			if (read_request(state))
				return error_state(state);
			/*
			 * We continue with event loop and block until there is
			 * song data. Normally we don't block.
			 */
			set_state(UADE_STATE_RECEIVE_MSGS, state);
			break;

		case UADE_STATE_RECEIVE_MSGS:
			return receive_messages(event, state);

		case UADE_STATE_SONG_END_PENDING:
			assert(state->ipc.state == UADE_R_STATE);
			set_state(UADE_STATE_WAIT_SUBSONG_CHANGE, state);
			*event = state->song.endevent;
			return 0;

		case UADE_STATE_WAIT_SUBSONG_CHANGE:
			assert(state->ipc.state == UADE_R_STATE);
			if (state->song.endevent.songend.stopnow) {
				uade_warning("uade player should have discontinued processing events after song end event that ordered stop-now directive.\n");
				return -1;
			}

			if (state->song.newsubsong < 0) {
				if (uade_next_subsong(state)) {
					set_end_event(event, 0, 1, 0, "No more subsongs left", state);
					return 0;
				}
			}
			state->song.state = UADE_STATE_RECEIVE_MSGS;
			break;

		default:
			uade_warning("Bad state: %d\n", state->song.state);
			return -1;
		}
	}
	assert(0);
}

int uade_get_fd(const struct uade_state *state)
{
	return uade_ipc_get_fd(state->ipc.input);
}

struct uade_state *uade_new_state(const struct uade_config *extraconfig,
				  const char *basedir)
{
	struct uade_state *state;
	DIR *bd;
	char path[PATH_MAX];

	state = calloc(1, sizeof *state);
	if (!state)
		return NULL;

	if (!uade_load_initial_config(state, basedir))
		fprintf(stderr, "uadeconfig not loaded\n");

	if (extraconfig)
		state->extraconfig = *extraconfig;
	else
		uade_config_set_defaults(&state->extraconfig);

	prepare_configs(state);

	uade_load_initial_song_conf(state);
	load_content_db(state);

	bd = opendir(state->config.basedir.name);
	if (bd == NULL) {
		uade_warning("Could not access dir %s\n", state->config.basedir.name);
		goto error;
	}
	closedir(bd);

	uade_config_set_option(&state->config, UC_UADECORE_FILE, UADE_CONFIG_UADE_CORE);

	snprintf(path, sizeof path, "%s/uaerc", state->config.basedir.name);
	uade_config_set_option(&state->config, UC_UAE_CONFIG_FILE, path);

	uade_merge_configs(&state->config, &state->extraconfig);

	if (access(state->config.uadecore_file.name, X_OK)) {
		uade_warning("Could not execute %s\n", state->config.uadecore_file.name);
		goto error;
	}
	if (access(state->config.uae_config_file.name, R_OK)) {
		uade_warning("Could not read uae config file: %s\n", state->config.uae_config_file.name);
		goto error;
	}

	if (uade_arch_spawn(&state->ipc, &state->pid, state->config.uadecore_file.name)) {
		fprintf(stderr, "Can not spawn uade: %s\n", state->config.uadecore_file.name);
		goto error;
	}

	if (uade_send_string(UADE_COMMAND_CONFIG, state->config.uae_config_file.name, &state->ipc)) {
		fprintf(stderr, "Can not send config name: %s\n", strerror(errno));
		goto error;
	}

	return state;

error:
	uade_cleanup_state(state);
	return NULL;
}

int uade_is_our_file(const char *fname, struct uade_state *state)
{
	char buf[8192];
	size_t bufsize;
	struct stat st;
	struct uade_detection_info detectioninfo;

	FILE *f = fopen(fname, "rb");
	if (f == NULL) {
		uade_debug(state, "uade_is_our_file(): Can not open %s\n", fname);
		return 0;
	}
	if (fstat(fileno(f), &st)) {
		uade_debug(state, "uade_is_our_file(): Can not stat() %s\n", fname);
		fclose(f);
		return 0;
	}
	bufsize = uade_atomic_fread(buf, 1, sizeof buf, f);
	fclose(f);

	if (uade_is_rmc(buf, bufsize))
		return 1;

	uade_analyze_eagleplayer(&detectioninfo, buf, bufsize, fname, st.st_size, state);
	return detectioninfo.ep != NULL;
}

int uade_is_our_file_from_buffer(const char *fname, const void *buf,
				 size_t size, struct uade_state *state)
{
	size_t fullsize = size;
	struct uade_detection_info detectioninfo;

	if (uade_is_rmc(buf, size))
		return 1;

	if (fname) {
		/* may fail, but the given size is still in fullsize */
		uade_filesize(&fullsize, fname);
	}

	uade_analyze_eagleplayer(&detectioninfo, buf, size, fname, fullsize, state);
	return detectioninfo.ep != NULL;
}

struct bencode *uade_get_rmc_from_state(const struct uade_state *state)
{
	return state->rmc;
}

static struct eagleplayer *get_eagleplayer(struct uade_file *module,
					   struct uade_state *state)
{
	struct uade_detection_info *detectioninfo;
	detectioninfo = &state->song.info.detectioninfo;
	if (uade_analyze_eagleplayer(detectioninfo, module->data, module->size, module->name, module->size, state))
		return NULL;

	if (detectioninfo->content)
		return detectioninfo->ep;

	if (state->config.content_detection && detectioninfo->content == 0)
		return NULL;

	if (detectioninfo->ep->flags & ES_CONTENT_DETECTION)
		return NULL;

	return detectioninfo->ep;
}

static int uade_play_internal(struct uade_file *module, int subsong, struct uade_state *state)
{
	struct eagleplayer *ep;
	char playername[PATH_MAX];
	char path[PATH_MAX];
	struct uade_event event;
	struct uade_song_info *info;
	struct uade_file *player = NULL;

	memset(&state->song, 0, sizeof state->song);
	state->song.state = UADE_STATE_INVALID;

	if (module == NULL)
		return -1;

	state->song.info.recordsongtime = 1;
	state->song.info.recordsubsongtime = 1;
	state->song.newsubsong = subsong;

	if (uade_is_rmc(module->data, module->size)) {
		state->rmc = uade_rmc_decode(module->data, module->size);
		if (state->rmc == NULL)
			goto recoverableerror;
		uade_file_free(module);
		module = NULL;
		if (uade_rmc_get_module(&module, state->rmc))
			goto recoverableerror;
	}

	info = &state->song.info;
	info->playtime = -1;
	info->modulefsize = module->size;
	if (module->name != NULL)
		strlcpy(info->modulefname, module->name, sizeof info->modulefname);

	prepare_configs(state);

	if (uade_lookup_song(module, state))
		goto recoverableerror;

	ep = get_eagleplayer(module, state);
	if (ep == NULL)
		return 0;

	uade_debug(state, "Player candidate: %s\n", ep->playername);

	if (state->config.player_file.name[0]) {
		player = uade_file_load(state->config.player_file.name);
	} else if (strcmp(ep->playername, "custom") == 0) {
		player = module;
		module = NULL;
	} else {
		char playername[PATH_MAX];
		snprintf(playername, sizeof playername, "%s/players/%s", state->config.basedir.name, ep->playername);
		player = uade_file_load(playername);
	}

	if (player == NULL) {
		fprintf(stderr, "Error: Could not load player\n");
		goto recoverableerror;
	}

	/* Player dir may not exist (custom song without filename was passed) */
	if (player->name != NULL)
		strlcpy(info->playerfname, player->name, sizeof info->playerfname);

	/*
	 * The order of parameter processing is important:
	 * 1. set eagleplayer attributes
	 * 2. set song attributes
	 * 3. merge options and configs
	 */

	uade_set_ep_attributes(state);

	if (uade_set_song_attributes(state, playername, sizeof playername)) {
		uade_debug(state, "Song rejected based on attributes: %s\n", state->song.info.modulefname);
		goto recoverableerror;
	}

	snprintf(path, sizeof path, "%s/score", state->config.basedir.name);
	uade_config_set_option(&state->config, UC_SCORE_FILE, path);

	uade_merge_configs(&state->config, &state->extraconfig);

	/* Now we have the final configuration in state->config */

	info->bytespersecond = get_bytes_per_second(state);

	uade_set_effects(state);

	switch (uade_song_initialization(player, module, state)) {
	case UADECORE_INIT_OK:
		break; /* This is the successfull path */
	case UADECORE_INIT_ERROR:
		goto fatalerror;
	case UADECORE_CANT_PLAY:
		uade_debug(state, "Uadecore refuses to play the song.\n");
		goto recoverableerror;
	default:
		uade_die("Unknown error from uade_song_initialization()\n");
	}

	uade_file_free(player);
	uade_file_free(module);
	player = module = NULL;

	state->song.state = UADE_STATE_INITIALIZED;

	if (test_set_debug(state)) {
		uade_warning("Can not enter debug mode\n");
		goto fatalerror;
	}

	while (1) {
		if (uade_get_event(&event, state)) {
			uade_warning("uade event loop terminated before playloop\n");
			goto fatalerror;
		}

		switch (event.type) {
		case UADE_EVENT_MESSAGE:
			uade_debug(state, "Got Amiga message before playloop: %s\n", event.msg);
			break;
		case UADE_EVENT_PLAYER_NAME:
			strlcpy(info->playername, event.msg, sizeof info->playername);
			break;
		case UADE_EVENT_FORMAT_NAME:
			strlcpy(info->formatname, event.msg, sizeof info->formatname);
			break;
		case UADE_EVENT_MODULE_NAME:
			strlcpy(info->modulename, event.msg, sizeof info->modulename);
			break;
		case UADE_EVENT_SUBSONG_INFO:
			/*
			 * Subsong info is the last info needed. This should
			 * come after the other info. Return successfully.
			 */
			info->subsongs = event.subsongs;
			return 1;
		case UADE_EVENT_SONG_END:
			uade_warning("Song ended prematurely due to error: %s\n", event.songend.reason);
			goto recoverableerror;
		case UADE_EVENT_DATA:
			/*
			 * This can happen only if song will not be played.
			 * e.g. score died.
			 */
			break;
		default:
			uade_warning("uade_get_event returned %s which is not handled before playloop.\n", uade_event_name(&event));
			goto fatalerror;
		}
	}

fatalerror:
	uade_file_free(module);
	uade_file_free(player);
	uade_debug(state, "uade_play_internal(): Fatal error\n");
	uade_stop(state);
	return -1;

recoverableerror:
	uade_file_free(module);
	uade_file_free(player);
	return uade_stop(state);
}

int uade_play(const char *fname, int subsong, struct uade_state *state)
{
	return uade_play_internal(uade_file_load(fname), subsong, state);
}

int uade_play_from_buffer(const char *fname, const void *data, size_t size, int subsong, struct uade_state *state)
{
	return uade_play_internal(uade_file(fname, data, size), subsong, state);
}

void uade_set_debug(struct uade_state *state)
{
	state->setdebug = 1;
}

int uade_set_song_options(const char *songfile, const char *songoptions, struct uade_state *state)
{
	char homesongconfname[PATH_MAX];
	char *home;

	home = uade_open_create_home();
	if (home == NULL)
		uade_die("No $HOME for song.conf :(\n");

	snprintf(homesongconfname, sizeof homesongconfname, "%s/.uade2/song.conf", home);

	if (state->songdbname[0] == 0)
		strlcpy(state->songdbname, homesongconfname, sizeof(state->songdbname));

	if (!uade_update_song_conf(homesongconfname, songfile, songoptions)) {
		fprintf(stderr, "Could not update song.conf entry for %s\n", songfile);
		return 0;
	}
	return 1;
}

int uade_stop(struct uade_state *state)
{
	if (state->rmc != NULL) {
		ben_free(state->rmc);
		state->rmc = NULL;
	}

	if (state->song.state == UADE_STATE_INVALID)
		return 0;

	/*
	 * Ignore the rest of the messages so that the next song can be
	 * played without additional bureaucracy. And RESET.
	 */
	if (get_pending_events(state))
		return -1;
	if (uade_send_short_message(UADE_COMMAND_REBOOT, &state->ipc)) {
		uade_warning("Can not send reboot\n");
		return error_state(state);
	}
	if (send_token(state))
		return error_state(state);
	if (get_pending_events(state))
		return -1;

	if (state->song.info.recordsongtime && 
	    state->song.state == UADE_STATE_WAIT_SUBSONG_CHANGE) {
		uint32_t playtime = (state->song.info.songbytes * 1000) / get_bytes_per_second(state);
		uade_add_playtime(state, state->song.info.modulemd5, playtime);
	}

	memset(&state->song, 0, sizeof state->song);

	set_state(UADE_STATE_INVALID, state);
	return 0;
}

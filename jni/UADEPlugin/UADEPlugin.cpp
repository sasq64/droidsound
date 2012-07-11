#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <pthread.h>

#include <android/log.h>
#include "com_ssb_droidsound_plugins_UADEPlugin.h"

extern "C" {
#include <uade/eagleplayer.h>
#include <uade/uadeipc.h>
#include <uade/uadecontrol.h>
#include <uade/uadeconf.h>
#include <uade/songdb.h>

// int uade_init();
// void uade_go();
int uade_main (int argc, char **argv);
void uae_quit(void);
}

#define INFO_TITLE 0
#define INFO_AUTHOR 1
#define INFO_LENGTH 2
#define INFO_TYPE 3
#define INFO_COPYRIGHT 4
#define INFO_GAME 5
#define INFO_SUBTUNES 6
#define INFO_STARTTUNE 7


/// UADE STUFF

//static struct eagleplayerstore *eaglestore = NULL;
int eaglestore = 0;
struct eagleplayer *lastplayer = NULL;
char lastext[16] = "";
char current_format[80] = "";


static struct uade_ipc uadeipc;

static struct uade_config uadeconf;

static uint8_t space[UADE_MAX_MESSAGE_SIZE];
static struct uade_msg *um = (struct uade_msg *) space;
static int left = 0;
static int next_song = 0;
static int tailbytes = 0;
static int playbytes;

static int uade_song_end_trigger = 0;
static int subsong_end = 0;

static pthread_t thread = 0;

char baseDir[256] = "";
struct uade_state state;

int uadeconf_loaded;
char uadeconfname[256];

char format[128];

//enum uade_control_state state = UADE_S_STATE;

int new_subsong = -1;

struct Player
{

};

//int totalSongs = -1;
int startSong = -1;

/*
struct eagleplayer *get_player(const char *name)
{
	const char *sext = strrchr(name, '.');
	char prefix[128];
	if(!sext)
		sext = "";
	else
		sext++;

	__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "extcheck %s \n", sext);

	//if(lastplayer && strcasecmp(sext, lastext) == 0)
	//{
		//__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "=> %s\n", lastplayer->playername);
		//return lastplayer;
	//}
	//else
	//{
		struct eagleplayer *plr = uade_get_eagleplayer(sext, eaglestore);
		if(plr)
		{
			lastplayer = plr;
			strcpy(lastext, sext);
			//__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "=> %s\n", lastplayer->playername);
		}
		return plr;
	//}

}
*/

//#if (defined _WIN32 || defined GP2X)
//unsigned int htonl(unsigned int l)
//{
//	return ((l>>24) & 0xff) | ((l>>8) & 0xFF00) | ((l<<8) & 0xFF0000) | (l<<24);
//}



short *soundBuffer = NULL;
short *soundPtr = NULL;

enum uade_control_state ctrlstate = UADE_S_STATE;

#define MAX_LEN 256

static int run_client()
{

	// __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE STATE %d", ctrlstate);

	if(ctrlstate == UADE_S_STATE)
	{
		if(uade_song_end_trigger) {
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "song_end_trigger");
			return -1;
		}
		/*if(uade_song_end_trigger)
		{
			next_song = 1;
			if(uade_send_short_message(UADE_COMMAND_REBOOT, &uadeipc))
			{
				__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "\nCan not send reboot\n");
				return 0;
			}
		}
		else */

		if(new_subsong >= 0)
		{
			state.song->cur_subsong = state.song->min_subsong + new_subsong;
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "New subsong %d", state.song->cur_subsong);
			uade_change_subsong(&state);
			//uade_change_subsong(new_subsong, &uadeipc);
			new_subsong = -1;
		}

		if(state.config.no_filter_set) {
			uade_send_filter_command(&state);
			state.config.no_filter_set = 0;
		}

		if(state.config.panning_enable_set || state.config.panning_set) {
			uade_set_effects(&state);
			state.config.no_filter_set = 0;
			state.config.panning_set = 0;
			state.config.panning_enable_set = 0;
		}

		//if(state.config.use_ntsc_set) {
		//	uade_set_effects(&state);
		//	state.config.use_ntsc_set = 0;
		//}


		left = uade_read_request(&uadeipc); /* Request another batch of sample data from uadecore */

		if(uade_send_short_message(UADE_COMMAND_TOKEN, &uadeipc))
		{
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "\nCan not send token\n");
			return 0;
		}
		ctrlstate = UADE_R_STATE;
	}

	/* receive ctrlstate */
	if(ctrlstate == UADE_R_STATE)
	{
		uint16_t *sm;

		if (uade_receive_message(um, sizeof(space), &uadeipc) <= 0)
		{
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "\nCan not receive events from uade\n");
			return 0;
		}

		//__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Got msg %d", um->msgtype);

		switch (um->msgtype)
		{
		case UADE_COMMAND_TOKEN:
			ctrlstate = UADE_S_STATE;
			//__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Got token");
			break;

		case UADE_REPLY_DATA:
			sm = (uint16_t *)um->data;

			if(!soundPtr) {
				__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "No soundPtr");
				return -1;
			}

			if(subsong_end)
			{
				playbytes = tailbytes; /* Determined by UADE_REPLY_SONG_END */
				tailbytes = 0;
			}
			else
				playbytes = um->size;


			if(1) //plugin.freq == 44100)
			{
				for (int i = 0; i < um->size/2; i++)
					soundPtr[i] = ntohs(sm[i]);

				soundPtr += (playbytes/2);
			}
			else
			if(0) // plugin.freq == 22050)
			{
				for (int i = 0; i < um->size/2; i+=4)
				{
					soundPtr[i/2] = (ntohs(sm[i]) + ntohs(sm[i+2])) / 2;
					soundPtr[i/2+1] = (ntohs(sm[i+1]) + ntohs(sm[i+3])) / 2;
				}

				soundPtr += (playbytes/4);
			}

			//dbprintf("Got %d bytes sampledata\n", playbytes);
			//__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Got %d bytes sampledata\n", playbytes);

//			time_bytes += playbytes;
			//assert(left >= um->size);
			left -= um->size;

			return 1;

			break;

		case UADE_REPLY_FORMATNAME:
			uade_check_fix_string(um, MAX_LEN);
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Format name: %s\n", (char*) um->data);
			strcpy(current_format, (char *)um->data);
			break;

		case UADE_REPLY_MODULENAME:
			uade_check_fix_string(um, MAX_LEN);
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Module name: %s\n", (char*) um->data);
			break;

		case UADE_REPLY_MSG:
			uade_check_fix_string(um, MAX_LEN);
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Message: %s\n", (char *) um->data);
			break;

		case UADE_REPLY_PLAYERNAME:
			uade_check_fix_string(um, MAX_LEN);
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Player name: %s\n", (char*) um->data);
			strcpy(current_format, (char *)um->data);
			break;

		case UADE_REPLY_SONG_END:
			if (um->size < 9)
			{
				__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Invalid song end reply\n");
				//exit(-1);
				return -1;
			}

			tailbytes = ntohl(((uint32_t *) um->data)[0]);
			uade_song_end_trigger = 1;
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Song end: %s", (char*)um->data+8);
			break;

		case UADE_REPLY_SUBSONG_INFO:
			if(um->size != 12)
			{
				__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "subsong info: too short a message\n");
			}
			{
				unsigned int *u32ptr = (unsigned int *)um->data;
				int min_sub = ntohl(u32ptr[0]);
				int max_sub = ntohl(u32ptr[1]);
				int cur_sub = ntohl(u32ptr[2]);

				state.song->min_subsong = min_sub;
				state.song->max_subsong = max_sub;
				state.song->cur_subsong = cur_sub;
				startSong = cur_sub - min_sub;

				__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "subsong: %d from range [%d, %d]\n", cur_sub, min_sub, max_sub);
			}
			break;
		case UADE_REPLY_CANT_PLAY:
		case UADE_REPLY_CAN_PLAY:
		default:
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Expected sound data. got %d.\n", um->msgtype);
			return 0;
		}
	}
	return 0;
}




static void *threadProc(void *arg) {
	__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Starting thread");

	const char *argv[5] = {"uadecore", "-i", "server", "-o", "client"};
	uade_main(5, (char**)argv);

	//uade_init();
	//uade_go();
	__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Thread ended");
	return NULL;
}

void exit() {

	uae_quit();

	if(ctrlstate == UADE_R_STATE) {
		__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "We are in R STATE ?!");
		if (uade_receive_message(um, sizeof(space), &uadeipc) <= 0)
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Can not receive events from uade");
		else
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Got msg %d", um->msgtype);
	}

	 if (uade_send_short_message(UADE_COMMAND_REBOOT, &state.ipc)) {
		 __android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Send reboot failed");
	 }
	__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Waiting for UAE to exit");
	int rc = pthread_join(thread, NULL);
	__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Exit with %d", rc);
	thread = 0;

	if(soundBuffer)
		free(soundBuffer);
	soundBuffer = 0;

}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1exit(JNIEnv *env, jobject obj)
{
	exit();
}

int init()
{
	char temp[256];


    //uadeconf_loaded = uade_load_initial_config(uadeconfname,
		//			       sizeof uadeconfname,
			//		       &state.config, NULL);


	if(eaglestore == 0) {

	   memset(&state, 0, sizeof state);
	    __android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "baseDir os '%s'", baseDir);

		uadeconf_loaded = uade_load_initial_config(&state, uadeconfname, sizeof(uadeconfname), baseDir);

		strcpy(state.permconfig.basedir.name, baseDir);

		state.config = state.permconfig;

		// state.config.no_filter = 1;

		uade_set_peer(&uadeipc, 1, "client", "server");
		state.ipc = uadeipc;
		eaglestore = 1;

	}

	if(thread == 0) {
		__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Creating thread");
	    pthread_create(&thread, NULL, threadProc, NULL);

		sprintf(temp, "%s/uaerc", baseDir);
		if(uade_send_string(UADE_COMMAND_CONFIG, temp, &uadeipc)) {
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Can not send config name\n");
		}
	}

	if(!soundBuffer)
		soundBuffer = (short*)malloc(44100 * 8);


	return 0;
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1init(JNIEnv *env, jobject obj, jstring basedir)
{
	jboolean iscopy;
	const char *s = env->GetStringUTFChars(basedir, &iscopy);
	strcpy(baseDir, s);
	env->ReleaseStringUTFChars(basedir, s);

	init();
}



extern "C" {

void client_sleep(void)
{
	//pthread_yield();
	//__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Sleeping in %d", pthread_self());
	usleep(100);
}


int get_write_mutex(void **m)
{
	if(!*m) {
		pthread_mutex_t *mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		memset(mutex, 0, sizeof(pthread_mutex_t));
		*m = (void*)mutex;
		__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Creating write mutex in ptr %p", m);
	}
	return (pthread_mutex_lock((pthread_mutex_t*)*m) == 0);
}

int release_write_mutex(void **m)
{
	return (pthread_mutex_unlock((pthread_mutex_t*)*m) == 0);
}

int get_read_mutex(void **m)
{


	if(!*m) {
		pthread_mutex_t *mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		//*mutex = PTHREAD_MUTEX_INITIALIZER;
		memset(mutex, 0, sizeof(pthread_mutex_t));
		*m = (void*)mutex;
		__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Creating read mutex in ptr %p", m);
	}
	return (pthread_mutex_lock((pthread_mutex_t*)*m) == 0);
}

int release_read_mutex(void **m)
{
	return (pthread_mutex_unlock((pthread_mutex_t*)*m) == 0);
}

}

static jstring NewString(JNIEnv *env, const char *str)
{
	static jchar *temp, *ptr;

	temp = (jchar *) malloc((strlen(str) + 1) * sizeof(jchar));

	ptr = temp;
	while(*str) {
		unsigned char c = (unsigned char)*str++;
		*ptr++ = (c < 0x7f && c >= 0x20) || c >= 0xa0 || c == 0xa ? c : '?';
	}
	//*ptr++ = 0;
	jstring j = env->NewString(temp, ptr - temp);

	free(temp);

	return j;
}




JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1canHandle(JNIEnv *, jobject, jstring)
{
	return true;
}

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1loadFile(JNIEnv *env, jobject obj, jstring fname)
{
	__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "in load()");

	jboolean iscopy;
	const char *filename = env->GetStringUTFChars(fname, &iscopy);

	__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Getting player for %s", filename);

	state.config = state.permconfig;
	state.song = NULL;
	state.ep = NULL;

	if(!uade_is_our_file(filename, 0, &state)) {
		__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Failed %s", filename);
		return 0;
	}

	__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Player candidate: %s\n", state.ep->playername);

	//if(strcmp(state.ep->playername, "TFMX") == 0) {
	//	state.ep->playername = "TFMX-Pro";
	//}

	struct eagleplayer *player = state.ep;

	if(!player) {
		env->ReleaseStringUTFChars(fname, filename);
		return 0;
	}

	char plname[256];
	char score[256];

	sprintf(plname, "%s/players/%s", baseDir, player->playername);
	sprintf(score, "%s/score", baseDir);

	int rc;

	strcpy(current_format, "");

	FILE *fp = fopen(filename, "rb");
	if(fp) {
		fclose(fp);
	} else {
		__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "!! Could not open '%s'", filename);
	}

	//if(strcmp(state.ep->playername, "custom") == 0) {
	//	strcpy(plname, filename);
	//}


	if (!uade_alloc_song(&state, filename)) {
		__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "alloc song failed '%s'", filename);
	}
	// state.song = (uade_song*)malloc(sizeof(uade_song));
	// state.song->buf = 0;
	// strcpy(state.song->module_filename, filename);


	if (state.ep != NULL)
	    uade_set_ep_attributes(&state);

	// Now we have the final configuration in "uc".
	uade_set_effects(&state);


	__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "PLAYING '%s' with %s\n", filename, plname);

	char *slash = strrchr(plname, '/');
	if(slash)
		strcpy(current_format, slash+1);
	else
		strcpy(current_format, plname);

	if(strcmp("custom", player->playername) == 0) {
		rc = uade_song_initialization(score, filename, "", &state);
	} else {
		rc = uade_song_initialization(score, plname, filename, &state);
	}
	uade_song_end_trigger = 0;

	__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "RES %d", rc);


	soundPtr = soundBuffer;

	rc = 0;
	while(rc <= 0) {
		rc = run_client();
	}

	env->ReleaseStringUTFChars(fname, filename);

	return 1;
}


static int wait_token()
{
	do
	{
		int ret = uade_receive_message(um, sizeof(space), &uadeipc);
		if(ret < 0)
		{
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "\nCan not receive events (TOKEN) from uade.\n");
			return 0;
		}
		if (ret == 0)
		{
			__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "\nEnd of input after reboot.\n");
			return 0;
		}
	} while (um->msgtype != UADE_COMMAND_TOKEN);
	return 1;
}

JNIEXPORT void Java_com_ssb_droidsound_plugins_UADEPlugin_N_1unload(JNIEnv *env, jobject obj, jlong song)
{
	Player *player = (Player*)song;
	//delete player;

	if(ctrlstate == UADE_R_STATE)
		wait_token();

	__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "close2\n");
	if(uade_send_short_message(UADE_COMMAND_REBOOT, &uadeipc))
	{
		__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "\nCan not send reboot\n");
		return;
	}
	__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "close3\n");
    if (uade_send_short_message(UADE_COMMAND_TOKEN, &uadeipc))
	{
		__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "\nCan not send token\n");
		return;
	}
 	__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "close4\n");

	wait_token();

	ctrlstate = UADE_S_STATE;

}


JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray sArray, jint size)
{
	Player *player = (Player*)song;

	jshort *dest = env->GetShortArrayElements(sArray, NULL);


	//__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "getSoundData");

	//if(run_client() < 0)
	//	return 0;

	soundPtr = dest;
	int rc = 0;
	while(rc <= 0) {
		rc = run_client();
		if(rc < 0) {
			env->ReleaseShortArrayElements(sArray, dest, 0);
			return -1;
		}
	}

	uade_effect_run(&state.effects, dest, (soundPtr - dest)/2);


	env->ReleaseShortArrayElements(sArray, dest, 0);

	return soundPtr - dest;


/*
	int filled = (soundPtr - soundBuffer);
	int len = size;

	while(filled < len)
	{
		if(run_client() < 0)
			return 0;
		filled = (soundPtr - soundBuffer);
	}

	memcpy(dest, soundBuffer, len*2);
	memmove(soundBuffer, soundBuffer+len, (filled-len)*2);
	soundPtr -= len;
    env->ReleaseShortArrayElements(sArray, dest, 0);
	return len;
*/
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1seekTo(JNIEnv *, jobject, jlong, jint)
{
	uade_song_end_trigger = 0;
	return false;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1setTune(JNIEnv *env, jobject obj, jlong song, jint tune)
{
	Player *player = (Player*)song;
	uade_song_end_trigger = 0;
	__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "setTune %d", tune);
	new_subsong = tune;
/*
	soundPtr = soundBuffer;
	int rc = 0;
	while(rc <= 0) {
		rc = run_client();
	}
*/

	return true;
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1getStringInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	Player *player = (Player*)song;
	switch(what)
	{
	// case INFO_TITLE:
// 		return NewString(env, "");
	// case INFO_AUTHOR:
		// return NewString(env, "");
	// case INFO_COPYRIGHT:
		// return NewString(env, "");
	case INFO_TYPE:
		return NewString(env, current_format);
		//return player->sidInfo.
	}
	return NewString(env, "");
}

#define OPT_FILTER 1
#define OPT_RESAMPLING 2
#define OPT_NTSC 3
#define OPT_SPEEDHACK 4
#define OPT_PANNING 5


JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1setOption(JNIEnv *env, jclass cl, jint what, jint val)
{

	switch(what) {
	case OPT_FILTER:
		state.config.no_filter = (val ? 0 : 1);
		state.config.no_filter_set = 1;
		state.permconfig.no_filter = state.config.no_filter;
		break;
	case OPT_NTSC:
		state.config.use_ntsc = (val ? 1 : 0);
		state.config.use_ntsc_set = true;
		state.permconfig.use_ntsc = state.config.use_ntsc;
		break;
	case OPT_RESAMPLING:
		state.config.resampler = "none";
		if(val == 1)
			state.config.resampler = "default";
		else if(val == 2)
			state.config.resampler = "sinc";
		state.config.resampler_set = true;
		state.permconfig.resampler = state.config.resampler;
		break;
	//case OPT_SPEEDHACK:
	//	state.config.speed_hack = (val ? 1 : 0);
	//	state.config.speed_hack_set = 1;
	//	break;
	case OPT_PANNING:
		if(val == 4) {
			state.config.panning_enable = 0;
		} else {
			state.config.panning = 0.25 * (4-val);
			state.config.panning_enable = 1;
		}
		state.config.panning_enable_set = 1;
		state.config.panning_set = 1;
		state.permconfig.panning = state.config.panning;
		state.permconfig.panning_enable = state.config.panning_enable;
		__android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Panning now %1.2f", state.config.panning);
		break;
	}
}





JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1getIntInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	Player *player = (Player*)song;
	switch(what)
	{
	case INFO_LENGTH:
		return -1;
	case INFO_SUBTUNES:
		return state.song->max_subsong - state.song->min_subsong + 1;
	case INFO_STARTTUNE:
		return startSong;
	}
	return -1;
}


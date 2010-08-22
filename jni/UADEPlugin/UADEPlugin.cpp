#include <stdlib.h>
#include <stdio.h>

#include <arpa/inet.h>
#include <netinet/in.h>

#include <android/log.h>
#include "com_ssb_droidsound_plugins_UADEPlugin.h"

extern "C" {
#include "eagleplayer.h"
#include "uadeipc.h"
#include "uadecontrol.h"

#include "uadecontrol.h"
#include "uadeconf.h"

int uade_init();
void uade_go();
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

static struct eagleplayerstore *eaglestore;
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

enum uade_control_state state = UADE_S_STATE;

int new_subsong = -1;

struct eagleplayer *get_player(const char *name)
{
	const char *sext = strrchr(name, '.');
	if(!sext)
		sext = "";
	else
		sext++;

	//fprintf(stderr, "extcheck %s \n", sext);

	if(lastplayer && strcasecmp(sext, lastext) == 0)
	{
		//fprintf(stderr, "=> %s\n", lastplayer->playername);
		return lastplayer;
	}
	else
	{
		struct eagleplayer *plr = uade_get_eagleplayer(sext, eaglestore);
		if(plr)
		{
			lastplayer = plr;
			strcpy(lastext, sext);
			//fprintf(stderr, "=> %s\n", lastplayer->playername);
		}
		return plr;
	}

}


//#if (defined _WIN32 || defined GP2X)
//unsigned int htonl(unsigned int l)
//{
//	return ((l>>24) & 0xff) | ((l>>8) & 0xFF00) | ((l<<8) & 0xFF0000) | (l<<24);
//}


static int run_client(short *soundptr)
{
	short *op = soundptr;

	if(state == UADE_S_STATE)
	{
		if(uade_song_end_trigger)
			return -1;
		/*if(uade_song_end_trigger)
		{
			next_song = 1;
			if(uade_send_short_message(UADE_COMMAND_REBOOT, &uadeipc))
			{
				fprintf(stderr, "\nCan not send reboot\n");
				return 0;
			}
		}
		else */

		if(new_subsong >= 0)
		{
			uade_change_subsong(new_subsong, &uadeipc);
			new_subsong = -1;
		}

		left = uade_read_request(&uadeipc); /* Request another batch of sample data from uadecore */

		if(uade_send_short_message(UADE_COMMAND_TOKEN, &uadeipc))
		{
			fprintf(stderr, "\nCan not send token\n");
			return 0;
		}
		state = UADE_R_STATE;
	}

	/* receive state */
	if(state == UADE_R_STATE)
	{
		uint16_t *sm;

		if (uade_receive_message(um, sizeof(space), &uadeipc) <= 0)
		{
			fprintf(stderr, "\nCan not receive events from uade\n");
			return 0;
		}

		switch (um->msgtype)
		{
		case UADE_COMMAND_TOKEN:
			state = UADE_S_STATE;
			break;

		case UADE_REPLY_DATA:
			sm = (uint16_t *)um->data;

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
					soundptr[i] = ntohs(sm[i]);

				soundptr += (playbytes/2);
			}
			else
			if(0) // plugin.freq == 22050)
			{
				for (int i = 0; i < um->size/2; i+=4)
				{
					soundptr[i/2] = (ntohs(sm[i]) + ntohs(sm[i+2])) / 2;
					soundptr[i/2+1] = (ntohs(sm[i+1]) + ntohs(sm[i+3])) / 2;
				}

				soundptr += (playbytes/4);
			}

			//dbprintf("Got %d bytes sampledata\n", playbytes);
			__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "Got %d bytes sampledata\n", playbytes);

//			time_bytes += playbytes;
			//assert(left >= um->size);
			left -= um->size;

			return (op - soundptr);

			break;

		case UADE_REPLY_FORMATNAME:
			uade_check_fix_string(um, 128);
			fprintf(stderr, "\nFormat name: %s\n", (char*) um->data);
			strcpy(current_format, (char *)um->data);
			break;

		case UADE_REPLY_MODULENAME:
			uade_check_fix_string(um, 128);
			fprintf(stderr, "\nModule name: %s\n", (char*) um->data);
			break;

		case UADE_REPLY_MSG:
			uade_check_fix_string(um, 128);
			fprintf(stderr, "\nMessage: %s\n", (char *) um->data);
			break;

		case UADE_REPLY_PLAYERNAME:
			uade_check_fix_string(um, 128);
			fprintf(stderr, "Player name: %s\n", (char*) um->data);
			strcpy(current_format, (char *)um->data);
			break;

		case UADE_REPLY_SONG_END:
			if (um->size < 9)
			{
				fprintf(stderr, "\nInvalid song end reply\n");
				exit(-1);
			}
			tailbytes = ntohl(((uint32_t *) um->data)[0]);
			uade_song_end_trigger = 1;
			fprintf(stderr, "\nSong end\n");
			break;

		case UADE_REPLY_SUBSONG_INFO:
			if(um->size != 12)
			{
				fprintf(stderr, "\nsubsong info: too short a message\n");
			}
			{
				unsigned int *u32ptr = (unsigned int *)um->data;
				int min_sub = ntohl(u32ptr[0]);
				int max_sub = ntohl(u32ptr[1]);
				int cur_sub = ntohl(u32ptr[2]);
				/// plugin.subtunes = max_sub;
				/// plugin.tune = cur_sub;
				fprintf(stderr, "\nsubsong: %d from range [%d, %d]\n", cur_sub, min_sub, max_sub);
			}
			break;
		case UADE_REPLY_CANT_PLAY:
		case UADE_REPLY_CAN_PLAY:
		default:
			fprintf(stderr, "\nExpected sound data. got %d.\n", um->msgtype);
			return 0;
		}
	}

}




void *init()
{
	eaglestore = uade_read_eagleplayer_conf("eagleplayer.conf");

	if(!eaglestore)
		return NULL;

	// fprintf(stderr, "%d eagleplayer extentions\n", eaglestore->nextensions);
	uade_set_peer(&uadeipc, 1, "client", "server");
}










static jstring NewString(JNIEnv *env, const char *str)
{
	static jchar temp[256];
	jchar *ptr = temp;
	while(*str) {
		unsigned char c = (unsigned char)*str++;
		*ptr++ = (c < 0x7f && c >= 0x20) || c >= 0xa0 ? c : '?';
	}
	//*ptr++ = 0;
	jstring j = env->NewString(temp, ptr - temp);
	return j;
}


JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1canHandle(JNIEnv *, jobject, jstring)
{
	return true;
}


struct Player
{
};




JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1load(JNIEnv *env, jobject obj, jbyteArray bArray, jint size)
{

	__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "in load()");

	jbyte *ptr = env->GetByteArrayElements(bArray, NULL);


	env->ReleaseByteArrayElements(bArray, ptr, 0);
	return 0;
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1unload(JNIEnv *, jobject, jlong song)
{
	Player *player = (Player*)song;
	delete player;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray sArray, jint size)
{

	Player *player = (Player*)song;

	jshort *ptr = env->GetShortArrayElements(sArray, NULL);
	int orgsize = size;
	jshort *orgptr = ptr;

    env->ReleaseShortArrayElements(sArray, ptr, 0);
	return orgsize;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1seekTo(JNIEnv *, jobject, jlong, jint)
{
	return false;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1setTune(JNIEnv *env, jobject obj, jlong song, jint tune)
{
	Player *player = (Player*)song;
	return true;
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1getStringInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	Player *player = (Player*)song;
	switch(what)
	{
	case INFO_TITLE:
		return NewString(env, "");
	case INFO_AUTHOR:
		return NewString(env, "");
	case INFO_COPYRIGHT:
		return NewString(env, "");
		//return player->sidInfo.
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1getIntInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	Player *player = (Player*)song;
	switch(what)
	{
	case INFO_LENGTH:
		return-1;
	case INFO_SUBTUNES:
		return 0;
	case INFO_STARTTUNE:
		return 0;
	}
	return -1;
}

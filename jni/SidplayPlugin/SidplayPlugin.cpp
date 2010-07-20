#include <stdlib.h>
#include <stdio.h>

#include <android/log.h>
#include "com_ssb_droidsound_plugins_SidplayPlugin.h"

#include "SidTune.h"
#include "builders/resid.h"
#include "sidplay2.h"


#define INFO_TITLE 0
#define INFO_AUTHOR 1
#define INFO_LENGTH 2
#define INFO_TYPE 3
#define INFO_COPYRIGHT 4
#define INFO_GAME 5
#define INFO_SUBTUNES 6
#define INFO_STARTTUNE 7

//extern void synth_render (word *buffer, dword len);
///extern void c64Init(void);
//extern word c64SidLoad(char *filename, word *init_addr, word *play_addr, byte *sub_song_start, byte *max_sub_songs, byte *speed, char *name, char *author, char *copyright);

static jstring NewString(JNIEnv *env, const char *str)
{
	static char temp[256];
	char *ptr = temp;
	while(*str) {
		char c = *str++;
		*ptr++ = (c < 0x7f) && (c >= 0x20) ? c : '?';
	}
	*ptr++ = 0;
	jstring j = env->NewStringUTF(temp);
	return j;
}


JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1canHandle(JNIEnv *, jobject, jstring)
{
	return true;
}

static char song_name[33], song_author[33], song_copyright[33];
static unsigned short load_addr, init_addr, play_addr;
static unsigned char subsongs, startsong, play_speed;

struct Player
{
	SidTune *sidtune;
	ReSIDBuilder *sidbuilder;
	sidplay2 *sidemu;
};

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1load(JNIEnv *env, jobject obj, jbyteArray bArray, jint size)
{

	__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "in load()");

	jbyte *ptr = env->GetByteArrayElements(bArray, NULL);
//	unsigned short LoadSIDFromMemory(void *pSidData, unsigned short *load_addr, unsigned short *init_addr, unsigned short *play_addr, unsigned char *subsongs, unsigned char *startsong, unsigned char *speed, unsigned short size);

	//if(strncmp((char*)ptr, "PSID", 4) == 0)
	{
		//c64Init();
		//synth_init(44100);

		Player *player = new Player();

		player->sidtune = new SidTune((uint_least8_t*)ptr, size);

		if(!player->sidtune->getStatus()) {
			__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "FAILED!");
			return -1;
		}

		__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "INIT");


		player->sidtune->selectSong(0);

		player->sidemu = new sidplay2;

		sid2_config_t cfg = player->sidemu->config();
		cfg.clockForced  = false;
		cfg.clockSpeed   = SID2_CLOCK_CORRECT;
		cfg.clockDefault = SID2_CLOCK_PAL;
		cfg.frequency    = 44100;
		cfg.playback     = sid2_stereo;
		cfg.precision    = 16;
		//cfg.sidModel     = SID2_MODEL_CORRECT;
		cfg.sidDefault   = SID2_MOS6581;
		cfg.sidSamples   = true;
		//cfg.optimisation  = 2;

		player->sidbuilder = new ReSIDBuilder("ReSID");
		//ASSERT(player->sidbuilder != NULL);
		cfg.sidEmulation  = player->sidbuilder;

		player->sidbuilder->create(1);
		player->sidbuilder->filter(false);
		//player->sidbuilder->filter((void*)0);

		int rc = player->sidemu->load(player->sidtune);
		//ASSERT(rc == 0);

		player->sidemu->config(cfg);

		memcpy(song_name, ptr + 0x16, 32);
		memcpy(song_author, ptr + 0x36, 32);
		memcpy(song_copyright, ptr + 0x56, 32);

		song_name[32] = song_author[32] = song_copyright[32] = 0;

		__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "load sid");

		//LoadSIDFromMemory(ptr, &load_addr, &init_addr, &play_addr, &subsongs, &startsong, &play_speed, size);
		//cpuJSR(init_addr, startsong);
		env->ReleaseByteArrayElements(bArray, ptr, 0);
		return (long)player;
	}
	env->ReleaseByteArrayElements(bArray, ptr, 0);
	return 0;
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1unload(JNIEnv *, jobject, jlong song)
{
	Player *player = (Player*)song;
	delete player->sidemu;
	delete player->sidbuilder;
	delete player->sidtune;
	delete player;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray sArray, jint size)
{

	Player *player = (Player*)song;

	jshort *ptr = env->GetShortArrayElements(sArray, NULL);
	int orgsize = size;
	jshort *orgptr = ptr;

	size = player->sidemu->play(ptr, size*2);

    env->ReleaseShortArrayElements(sArray, ptr, 0);
	return orgsize;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1seekTo(JNIEnv *, jobject, jlong, jint)
{
	return false;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1setTune(JNIEnv *env, jobject obj, jlong song, jint tune)
{
	Player *player = (Player*)song;

	player->sidtune->selectSong(tune);
	player->sidemu->load(player->sidtune);
	//cpuJSR(init_addr, song);
	return true;
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1getStringInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	switch(what)
	{
	case INFO_TITLE:
		return NewString(env, song_name);
	case INFO_AUTHOR:
		return NewString(env, song_author);
	case INFO_COPYRIGHT:
		return NewString(env, song_copyright);
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1getIntInfo(JNIEnv *, jobject, jlong, jint what)
{
	switch(what)
	{
	case INFO_LENGTH:
		return 5*60*1000;
	case INFO_SUBTUNES:
		return subsongs+1;
	case INFO_STARTTUNE:
		return startsong;
	}
	return -1;
}

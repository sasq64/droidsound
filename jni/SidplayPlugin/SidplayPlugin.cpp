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

#define INFO_SILENCE 100
#define INFO_SIDMODEL 101

//extern void synth_render (word *buffer, dword len);
///extern void c64Init(void);
//extern word c64SidLoad(char *filename, word *init_addr, word *play_addr, byte *sub_song_start, byte *max_sub_songs, byte *speed, char *name, char *author, char *copyright);

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

#define OPT_FILTER 1
#define OPT_RESAMPLING 2
#define OPT_NTSC 3
#define OPT_MODEL 4

struct Player
{
	SidTune *sidtune;
	ReSIDBuilder *sidbuilder;
	sidplay2 *sidemu;
	SidTuneInfo sidInfo;
	bool silent;
};

static bool filter_cfg = true;
static bool filter_set = false;
static int ntsc_cfg = false;
static bool ntsc_set = false;
static bool override_cfg = false;
static bool use_6581 = false;



//JNICALL
JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1setOption(JNIEnv *env, jclass cl, jint what, jint val)
{

	__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "Setting %d to %d", what, val);
	switch(what) {
	case OPT_FILTER:
		filter_cfg = val ? true : false;
		filter_set = true;
		break;
	case OPT_NTSC:
		ntsc_cfg = val;
		__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "NTSC %d", ntsc_cfg);
		ntsc_set = true;
		break;
	case OPT_MODEL:
		break;
	}
}



JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1canHandle(JNIEnv *, jobject, jstring)
{
	return true;
}

//static char song_name[33], song_author[33], song_copyright[33];
//static unsigned short load_addr, init_addr, play_addr;
//static unsigned char subsongs, startsong, play_speed;

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
		//player->silent = false;

		player->sidtune = new SidTune((uint_least8_t*)ptr, size);

		if(!player->sidtune->getStatus()) {
			__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "FAILED!");
			delete player->sidtune;
			delete player;
			return 0;
		}

		__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "INIT");


		player->sidtune->selectSong(0);

		player->sidtune->getInfo(player->sidInfo);

		SidTuneInfo &i = player->sidInfo;

		__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "INFO CL %x SP %x / I %x L %x NO %x LEN %d", i.clockSpeed, i.songSpeed, i.initAddr, i.loadAddr, i.songs, i.c64dataLen);

		player->sidemu = new sidplay2;

		__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "INIT 2");

		sid2_config_t cfg = player->sidemu->config();
		cfg.clockForced  = false;

		//videomode_is_ntsc = (val & 1) != 0;
		//videomode_is_forced = (val & 2) != 0;

		cfg.clockSpeed   = (ntsc_cfg & 2) ? SID2_CLOCK_NTSC : SID2_CLOCK_CORRECT;
		cfg.clockDefault = (ntsc_cfg  & 1) ? SID2_CLOCK_NTSC : SID2_CLOCK_PAL;
		cfg.frequency    = 44100;
		cfg.playback     = sid2_stereo;
		cfg.precision    = 16;
		//cfg.sidModel     = SID2_MODEL_CORRECT;

		sid2_model_t model = use_6581 ? SID2_MOS6581 : SID2_MOS8580;

		cfg.sidModel = override_cfg ? model : SID2_MODEL_CORRECT;
		cfg.sidDefault = model;

		cfg.sidSamples   = true;
		//cfg.optimisation  = 2;

		 //cfg.clockForced  = true;
		  cfg.environment  = sid2_envR;
		  cfg.forceDualSids= false;
		  cfg.emulateStereo= false;

		//x  cfg.clockSpeed   = SID2_CLOCK_CORRECT;
		//x  cfg.clockDefault = SID2_CLOCK_PAL;
		  cfg.frequency    = 44100;

		  //cfg.playback     = sid2_mono;

		  cfg.precision    = 16;
		  //cfg.sidModel     = SID2_MODEL_CORRECT;
		  //cfg.sidDefault   = SID2_MOS6581;
		  cfg.sidSamples   = true;
		  cfg.optimisation  = SID2_MAX_OPTIMISATION;




		//cfg.environment = sid2_envR;

		__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "INIT 3");

		player->sidbuilder = new ReSIDBuilder("ReSID");
		//ASSERT(player->sidbuilder != NULL);
		cfg.sidEmulation  = player->sidbuilder;

		player->sidbuilder->create(1);
		player->sidbuilder->filter(filter_cfg);
		//player->sidbuilder->filter((void*)0);


		__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "INIT 4 %p %p", player->sidemu, player->sidtune);




		int rc = player->sidemu->load(player->sidtune);

		__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "DONE %d", rc);
		//ASSERT(rc == 0);
		if(rc != 0) {
			delete player->sidemu;
			delete player->sidbuilder;
			delete player->sidtune;
			delete player;
			return 0;
		}

		player->sidemu->config(cfg);

		//memcpy(song_name, ptr + 0x16, 32);
		//memcpy(song_author, ptr + 0x36, 32);
		//memcpy(song_copyright, ptr + 0x56, 32);

		//song_name[32] = song_author[32] = song_copyright[32] = 0;

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

	if(filter_set) {
		player->sidbuilder->filter(filter_cfg);
		filter_set = false;
	}

	size = player->sidemu->play(ptr, size*2);

	//int i = 0;
	//while(i<size && orgptr[i] < 140 && orgptr[i] > -140)
	//	i++;

	//__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "%d %d", i, orgptr[i]);

	//player->silent = (i == size);

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

	player->sidtune->selectSong(tune+1);
	player->sidemu->load(player->sidtune);
	//cpuJSR(init_addr, song);
	return true;
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1getStringInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	Player *player = (Player*)song;
	switch(what)
	{
	case INFO_TITLE:
		return NewString(env, player->sidInfo.infoString[0]);
	case INFO_AUTHOR:
		return NewString(env, player->sidInfo.infoString[1]);
	case INFO_COPYRIGHT:
		return NewString(env, player->sidInfo.infoString[2]);
		//return player->sidInfo.
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_SidplayPlugin_N_1getIntInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	Player *player = (Player*)song;
	switch(what)
	{
	case INFO_LENGTH:
		return-1;
	case INFO_SUBTUNES:
		return player->sidInfo.songs;
	case INFO_STARTTUNE:
		return player->sidInfo.startSong-1;
	case INFO_SIDMODEL:
		return player->sidInfo.sidModel;

	case INFO_SILENCE :
		//__android_log_print(ANDROID_LOG_VERBOSE, "SidplayPlugin", "SILENT %d", player->silent ? 1 : 0);
		//return player->silent ? 1 : 0;
		return 0;
	}
	return -1;
}

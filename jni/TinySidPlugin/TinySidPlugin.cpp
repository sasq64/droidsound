#include <stdlib.h>
#include <stdio.h>

#include <android/log.h>
#include "com_ssb_droidsound_plugins_TinySidPlugin.h"
#include "tiny/tinysid.h"

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


JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_TinySidPlugin_N_1canHandle(JNIEnv *, jobject, jstring)
{
	return true;
}

static char song_name[33], song_author[33], song_copyright[33];
static unsigned short load_addr, init_addr, play_addr;
static unsigned char subsongs, startsong, play_speed;

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_TinySidPlugin_N_1load(JNIEnv *env, jobject obj, jbyteArray bArray, jint size)
{

	__android_log_print(ANDROID_LOG_VERBOSE, "TinySidPlugin", "in load()");

	jbyte *ptr = env->GetByteArrayElements(bArray, NULL);
//	unsigned short LoadSIDFromMemory(void *pSidData, unsigned short *load_addr, unsigned short *init_addr, unsigned short *play_addr, unsigned char *subsongs, unsigned char *startsong, unsigned char *speed, unsigned short size);

	if(strncmp((char*)ptr, "PSID", 4) == 0)
	{
		c64Init();
		synth_init(44100);

		__android_log_print(ANDROID_LOG_VERBOSE, "TinySidPlugin", "INIT");


		memcpy(song_name, ptr + 0x16, 32);
		memcpy(song_author, ptr + 0x36, 32);
		memcpy(song_copyright, ptr + 0x56, 32);

		song_name[32] = song_author[32] = song_copyright[32] = 0;

		__android_log_print(ANDROID_LOG_VERBOSE, "TinySidPlugin", "load sid");

		LoadSIDFromMemory(ptr, &load_addr, &init_addr, &play_addr, &subsongs, &startsong, &play_speed, size);
		cpuJSR(init_addr, startsong);
		env->ReleaseByteArrayElements(bArray, ptr, 0);
		return 1;
	}
	env->ReleaseByteArrayElements(bArray, ptr, 0);
	return 0;
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_TinySidPlugin_N_1unload(JNIEnv *, jobject, jlong song)
{
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_TinySidPlugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray sArray, jint size)
{
	jshort *ptr = env->GetShortArrayElements(sArray, NULL);
	int orgsize = size;
	jshort *orgptr = ptr;


    if(play_speed == 0)
    {
		// Single Speed (50Hz)
		// Render 16*50Hz buffer
    	while(size > 882)
		{
			cpuJSR(play_addr, 0);
			synth_render((word*)ptr, 882);
			for(int i=881; i>=0; i--)
				ptr[i*2] = ptr[i*2+1] = ptr[i];

			ptr += 882*2;
			size -= 882*2;
		}
    }
    else
    {
    	// Double Speed (100Hz)
    	// Render 16*50Hz buffer
		while(size > 441)
		{
			cpuJSR(play_addr, 0);
			synth_render((word*)ptr, 441);
			for(int i=440; i>=0; i--)
				ptr[i*2] = ptr[i*2+1] = ptr[i];
			ptr += 441*2;
			size -= 441*2;
		}
    }

    env->ReleaseShortArrayElements(sArray, ptr, 0);
	return orgsize - size;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_TinySidPlugin_N_1seekTo(JNIEnv *, jobject, jlong, jint)
{
	return false;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_TinySidPlugin_N_1setTune(JNIEnv *env, jobject obj, jlong song, jint tune)
{
	cpuJSR(init_addr, song);
	return true;
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_TinySidPlugin_N_1getStringInfo(JNIEnv *env, jobject obj, jlong song, jint what)
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

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_TinySidPlugin_N_1getIntInfo(JNIEnv *, jobject, jlong, jint what)
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

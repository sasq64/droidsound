#include <stdlib.h>
#include <stdio.h>
#include <jni.h>
#include <android/log.h>
 #include "com_ssb_droidsound_plugins_TFMXPlugin.h"
#include "tfmx/tfmx_iface.h"

#define INFO_TITLE 0
#define INFO_AUTHOR 1
#define INFO_LENGTH 2
#define INFO_TYPE 3
#define INFO_COPYRIGHT 4
#define INFO_GAME 5
#define INFO_SUBTUNES 6
#define INFO_STARTTUNE 7

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

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_TFMXPlugin_N_1load(JNIEnv *env, jobject obj,  jbyteArray mDat, jbyteArray sDat)
{

	__android_log_print(ANDROID_LOG_VERBOSE, "TFMXPlugin", "in load()");

	jbyte *mPtr = env->GetByteArrayElements(mDat, NULL);
	jbyte *sPtr = env->GetByteArrayElements(sDat, NULL);

	int mlen = env->GetArrayLength(mDat);
	int slen = env->GetArrayLength(sDat);

	__android_log_print(ANDROID_LOG_VERBOSE, "TFMXPlugin", "%p %p %d %d HEADER %s", mPtr, sPtr, mlen, slen, (char*)mPtr);

	int rc = LoadTFMXFile((char*)mPtr, mlen, (char*)sPtr, slen);

//	unsigned short LoadSIDFromMemory(void *pSidData, unsigned short *load_addr, unsigned short *init_addr, unsigned short *play_addr, unsigned char *subsongs, unsigned char *startsong, unsigned char *speed, unsigned short size);

	__android_log_print(ANDROID_LOG_VERBOSE, "TFMXPlugin", "LOAD %d", rc);

	if(rc == 0)
	{
		TFMXSetSubSong(0);
		TFMXRewind();

		env->ReleaseByteArrayElements(mDat, mPtr, 0);
		env->ReleaseByteArrayElements(sDat, sPtr, 0);
		return 1;
	}
	env->ReleaseByteArrayElements(mDat, mPtr, 0);
	env->ReleaseByteArrayElements(sDat, sPtr, 0);
	return 0;
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_TFMXPlugin_N_1unload(JNIEnv *, jobject, jlong song)
{
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_TFMXPlugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray sArray, jint size)
{
	jshort *ptr = env->GetShortArrayElements(sArray, NULL);
	int orgsize = size;
	jshort *orgptr = ptr;

	int bsize = tfmx_get_block_size();

	int rc = tfmx_try_to_make_block();
	//printf("RC %d\n", rc);
	rc = tfmx_get_block(ptr);

    env->ReleaseShortArrayElements(sArray, ptr, 0);
	return bsize / 2;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_TFMXPlugin_N_1seekTo(JNIEnv *, jobject, jlong, jint)
{
	return false;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_TFMXPlugin_N_1setTune(JNIEnv *env, jobject obj, jlong song, jint tune)
{
	TFMXSetSubSong(tune);
	return true;
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_TFMXPlugin_N_1getStringInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	switch(what)
	{
	case INFO_TITLE:
		return 0;
	case INFO_AUTHOR:
		return 0;
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_TFMXPlugin_N_1getIntInfo(JNIEnv *, jobject, jlong, jint what)
{
	switch(what)
	{
	case INFO_LENGTH:
		return 5*60*1000;
	case INFO_SUBTUNES:
		return TFMXGetSubSongs();
	case INFO_STARTTUNE:
		return 0;
	}
	return -1;
}

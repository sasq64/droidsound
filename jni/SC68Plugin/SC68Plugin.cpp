
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <ctype.h>

#include <android/log.h> 
#include <jni.h>

#include <config68.h>
/* sc68 includes */
#include "api68/api68.h"

#include "com_ssb_droidsound_plugins_SC68Plugin.h"


#define INFO_TITLE 0
#define INFO_AUTHOR 1
#define INFO_LENGTH 2
#define INFO_TYPE 3
#define INFO_COPYRIGHT 4
#define INFO_GAME 5
#define INFO_SUBTUNES 6
#define INFO_STARTTUNE 7

#define INFO_INSTRUMENTS 100
#define INFO_CHANNELS 101
#define INFO_PATTERNS 102

//static jfieldID refField;
static char data_dir[1024];

static jstring NewString(JNIEnv *env, const char *str)
{
	static jchar temp[256];
	jchar *ptr = temp;
	while(*str) {
		unsigned char c = (unsigned char)*str++;
		*ptr++ = (c < 0x7f && c >= 0x20) || c >= 0xa0 || c == 0xa ? c : '?';
	}
	//*ptr++ = 0;
	jstring j = env->NewString(temp, ptr - temp);
	return j;
}

struct PlayData {
	api68_t *sc68;
	api68_music_info_t info;
	int currentTrack;
	int defaultTrack;
	bool trackChanged;
};

static void write_debug(void * cookie, const char * fmt, va_list list) {

	static char temp[1024];
	vsprintf(temp, fmt, list);
	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Debug", temp);
}

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1load(JNIEnv *env, jobject obj, jbyteArray bArray, jint size)
{
	api68_init_t init68;
	memset(&init68, 0, sizeof(init68));
	init68.alloc = malloc;
	init68.free = free;
#ifdef _DEBUG
	init68.debug = vfprintf;
	init68.debug_cookie = stderr;
#endif

	debugmsg68_set_handler(write_debug);

	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "INIT");

	api68_t *sc68 = api68_init(&init68);
	if(sc68 == NULL) {
		__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "!!!!!!!!! INIT FAILED");
		return 0;
	}

	api68_set_user(sc68, data_dir);

	jboolean iscopy;
	jbyte *ptr = env->GetByteArrayElements(bArray, NULL);

	int alen = env->GetArrayLength(bArray);

	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "SIZE %d ARRAYLEN %d", size, alen);

	//api68_t *sc68 = (api68_t*)env->GetLongField(obj, refField);

	if (api68_verify_mem(ptr, size) < 0) {
		env->ReleaseByteArrayElements(bArray, ptr, 0);
		api68_shutdown(sc68);
		return 0;
	}

	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "STEP");
	if (api68_load_mem(sc68, ptr, size)) {
		env->ReleaseByteArrayElements(bArray, ptr, 0);
		api68_shutdown(sc68);
		return 0;
	}
	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "STEP");

	PlayData *pd = (PlayData*)malloc(sizeof(PlayData));
	pd->sc68 = sc68;
	pd->trackChanged = false;

	api68_play(pd->sc68, 0);
	api68_process(pd->sc68, NULL, 0);
	pd->defaultTrack = api68_play(pd->sc68, -1);

	if(pd->defaultTrack == 0)
		pd->defaultTrack = 1;

	pd->currentTrack = pd->defaultTrack;

	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "Default track is %d", pd->defaultTrack);

	env->ReleaseByteArrayElements(bArray, ptr, 0);
	return (long)pd;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray bArray, jint size)
{
	PlayData *pd = (PlayData*)song;

	const char *err = "";
	err = api68_error();
	while(err) {
		__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "ERROR:%s", err);
		err = api68_error();
	}

	/* Set track number : command line is prior to config force-track */
	if(pd->currentTrack < 0) {
		pd->currentTrack = 0;
		if(api68_play(pd->sc68, pd->currentTrack)) {
			return -1;
		}
	}

	jshort *ptr = (jshort*)env->GetShortArrayElements(bArray, NULL);

	 int code = api68_process(pd->sc68, ptr, size/2);

	 if(code) {
		 __android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "CODE: 0x%x", code);
	 }


	 unsigned short *ptr2 = (unsigned short*)ptr;
	 //for(int i=0; i<size; i++) {
		 //ptr[i] = ((ptr[i]>>8)&0xff) | (ptr[i]<<8);
		 //ptr[i] = ptr2[i] - 0x8000;
	 //}

	 env->ReleaseShortArrayElements(bArray, (jshort*)ptr, 0);

	 if(!pd->trackChanged && (code & API68_CHANGE)) {
		 __android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "Ending track");
		 return -1;
	 }

	 pd->trackChanged = false;

	 if (code == API68_MIX_ERROR) {
		 return -1;
	 }
	 return size;
}

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1loadInfo(JNIEnv *env, jobject obj, jbyteArray data, jint size)
{
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1unload(JNIEnv *env, jobject obj, jlong song)
{
	PlayData *pd = (PlayData*)song;
	api68_shutdown(pd->sc68);
	free(pd);
}


JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1seekTo(JNIEnv *env, jobject obj, jlong song, jint msec)
{
	PlayData *pd = (PlayData*)song;
	api68_seek(pd->sc68, msec);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1setTune(JNIEnv *env, jobject obj, jlong song, jint tune)
{
	PlayData *pd = (PlayData*)song;
	pd->currentTrack = tune+1;
	if(api68_play(pd->sc68, pd->currentTrack)) {
		pd->currentTrack = -1;
		return false;
	}
	pd->trackChanged = true;
	return true;
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1getStringInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	PlayData *pd = (PlayData*)song;
	int track = pd->currentTrack;
	if(track < 0) track = 1;
	if (!api68_music_info(pd->sc68, &pd->info, track, 0)) {
	}
	api68_music_info_t &info = pd->info;

	switch(what) {
	case INFO_AUTHOR:
		return NewString(env, info.composer);
	case INFO_TITLE:
		return NewString(env, info.title);
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1getIntInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	PlayData *pd = (PlayData*)song;
	int track = pd->currentTrack;
	if(track < 0) track = 1;
	if (!api68_music_info(pd->sc68, &pd->info, track, 0)) {
	}
	api68_music_info_t &info = pd->info;


	switch(what) {
	case INFO_LENGTH:
		return info.time_ms;
	case INFO_SUBTUNES:
		return info.tracks;
	case INFO_STARTTUNE:
		return pd->defaultTrack-1;
	}
	return -1;
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1setDataDir(JNIEnv *env, jobject obj, jstring dataDir)
{

	//jclass cl = env->GetObjectClass(obj);
	//refField = env->GetFieldID(cl, "pluginRef", "J");
	//env->SetLongField(obj, refField, (jlong)sc68);

	jboolean iscopy;
	const char *filename = env->GetStringUTFChars(dataDir, &iscopy);

	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "DataDir:%s", filename);
	strcpy(data_dir, filename);

	env->ReleaseStringUTFChars(dataDir, filename);
}

extern "C" {
int unice68_depacker(void * dest, const void * src);
int unice68_get_depacked_size(const void * buffer, int * p_csize);
}
JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1unice(JNIEnv *env, jobject obj, jbyteArray src, jbyteArray dest)
{
	jbyte *sptr = env->GetByteArrayElements(src, NULL);
	jbyte *dptr = env->GetByteArrayElements(dest, NULL);
	int rc = 0;
	int ssize = env->GetArrayLength(src);
	int dsize = env->GetArrayLength(dest);

	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "Unpacking %d bytes (%s)", ssize, sptr);

	int size = unice68_get_depacked_size(sptr, NULL);

	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "Dest size %d, Packed size %d", dsize, size);

	if(dsize < size)
		rc = -2;

	if(size < 0)
		rc = -1;

	if(rc == 0) {
		int res = unice68_depacker(dptr, sptr);
		if(res != 0)
			rc = -3;
	}

	env->ReleaseByteArrayElements(src, sptr, 0);
	env->ReleaseByteArrayElements(dest, dptr, 0);

	return rc;
}


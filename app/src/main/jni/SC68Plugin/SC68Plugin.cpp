
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <ctype.h>

#include <android/log.h> 
#include <jni.h>

/* sc68 includes */
#include <sc68/sc68.h>
#include <sc68/msg68.h>

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

struct PlayData {
	sc68_t *sc68;
	sc68_music_info_t info;
	int currentTrack;
	int defaultTrack;
	bool trackChanged;
};

static void write_debug(int level, void * cookie, const char * fmt, va_list list) {

	static char temp[1024];
	vsprintf(temp, fmt, list);
	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Debug", temp);
}

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1load(JNIEnv *env, jobject obj, jbyteArray bArray, jint size)
{
	sc68_init_t init68;
	memset(&init68, 0, sizeof(init68));
//	init68.alloc = malloc;
//	init68.free = free;
	init68.msg_handler = (sc68_msg_t)write_debug;
#ifdef _DEBUG
	init68.debug = vfprintf;
	init68.debug_cookie = stderr;
#endif


	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "INIT");

	if (sc68_init(&init68) != 0) {
		__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "!!!!!!!!! INIT FAILED");
		return 0;
	}

	//msg68_set_handler(write_debug);
	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "Create");
	sc68_t *sc68 = sc68_create(NULL);

	sc68_set_user(sc68, data_dir);

	jboolean iscopy;
	jbyte *ptr = env->GetByteArrayElements(bArray, NULL);

	int alen = env->GetArrayLength(bArray);

	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "SIZE %d ARRAYLEN %d", size, alen);

	//sc68_t *sc68 = (sc68_t*)env->GetLongField(obj, refField);

	if (sc68_verify_mem(ptr, size) < 0) {
		env->ReleaseByteArrayElements(bArray, ptr, 0);
		sc68_destroy(sc68);
		sc68_shutdown();
		return 0;
	}

	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "STEP");
	if (sc68_load_mem(sc68, ptr, size)) {
		env->ReleaseByteArrayElements(bArray, ptr, 0);
		sc68_destroy(sc68);
		sc68_shutdown();
		return 0;
	}
	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "STEP");

	PlayData *pd = (PlayData*)malloc(sizeof(PlayData));
	pd->sc68 = sc68;
	pd->trackChanged = false;

	sc68_play(pd->sc68, 0, 0);
	if(sc68_process(pd->sc68, NULL, 0) < 0) {
		env->ReleaseByteArrayElements(bArray, ptr, 0);
		free(pd);
		sc68_destroy(sc68);
		sc68_shutdown();
		return 0;
	}

	pd->defaultTrack = sc68_play(pd->sc68, -1, 0);

	if(pd->defaultTrack == 0)
		pd->defaultTrack = 1;

	pd->currentTrack = pd->defaultTrack;

	__android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "Default track is %d", pd->defaultTrack);

	env->ReleaseByteArrayElements(bArray, ptr, 0);
	return (long)pd;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray sArray, jint size)
{
    PlayData *pd = (PlayData*)song;

    const char *err = "";
    while (NULL != (err = sc68_error_get(pd->sc68))) {
        __android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "ERROR:%s", err);
    }

    /* Set track number : command line is prior to config force-track */
    if(pd->currentTrack < 0) {
        pd->currentTrack = 0;
        if(sc68_play(pd->sc68, pd->currentTrack, 0)) {
            return -1;
        }
    }

    jshort *ptr = (jshort*)env->GetShortArrayElements(sArray, NULL);

    jint n = size/2;
    int code = sc68_process(pd->sc68, ptr, &n);

    if(code) {
        __android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "CODE: 0x%x", code);
    }

    unsigned short *ptr2 = (unsigned short*)ptr;

    env->ReleaseShortArrayElements(sArray, (jshort*)ptr, 0);

    if(!pd->trackChanged && (code & SC68_CHANGE)) {
        __android_log_print(ANDROID_LOG_VERBOSE, "SC68Plugin", "Ending track");
        return -1;
    }

    pd->trackChanged = false;

    if (code == SC68_ERROR) {
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
	sc68_destroy(pd->sc68);
	sc68_shutdown();
	free(pd);
}


JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1seekTo(JNIEnv *env, jobject obj, jlong song, jint msec)
{
	PlayData *pd = (PlayData*)song;
	int status;
	sc68_seek(pd->sc68, msec, &status);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1setTune(JNIEnv *env, jobject obj, jlong song, jint tune)
{
	PlayData *pd = (PlayData*)song;
	pd->currentTrack = tune+1;
	if(sc68_play(pd->sc68, pd->currentTrack, 0)) {
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
	if (!sc68_music_info(pd->sc68, &pd->info, track, 0)) {
	}
	sc68_music_info_t &info = pd->info;

	switch(what) {
	case INFO_AUTHOR:
		return NewString(env, info.artist);
	case INFO_TITLE:
		return NewString(env, info.title);
	case 51:
		return  NewString(env, pd->info.trk.hw);
	case 52:
		return  NewString(env, pd->info.replay);
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_SC68Plugin_N_1getIntInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	PlayData *pd = (PlayData*)song;
	int track = pd->currentTrack;
	if(track < 0) track = 1;
	if (!sc68_music_info(pd->sc68, &pd->info, track, 0)) {
	}
	sc68_music_info_t &info = pd->info;


	switch(what) {
	case INFO_LENGTH:
		return info.trk.time_ms;
	case INFO_SUBTUNES:
		return info.tracks;
	case INFO_STARTTUNE:
		return pd->defaultTrack-1;
	case 50:
		return (pd->info.trk.amiga << 2) | (pd->info.trk.ste << 1) | (pd->info.trk.ym);
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


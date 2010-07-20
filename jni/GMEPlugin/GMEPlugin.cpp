
#include <stdlib.h>
#include <stdio.h>

#include <jni.h>

#include <android/log.h>

#include "com_ssb_droidsound_plugins_GMEPlugin.h"

#define INFO_TITLE 0
#define INFO_AUTHOR 1
#define INFO_LENGTH 2
#define INFO_TYPE 3
#define INFO_COPYRIGHT 4
#define INFO_GAME 5
#define INFO_SUBTUNES 6
#define INFO_STARTTUNE 7

#include "gme/gme.h"

//#include "log.h"

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1canHandle(JNIEnv *env, jobject obj, jstring name)
{
	return true;
}

struct GMEInfo {
	 Music_Emu *emu;
	 int currentSong;
	 track_info_t lastTrack;
};

//static Music_Emu *emu = NULL;
//static int currentSong = 0;
//static track_info_t lastTrack;

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1load(JNIEnv *env, jobject obj, jbyteArray bArray, int size)
{
	jbyte *ptr = env->GetByteArrayElements(bArray, NULL);
	Music_Emu *emu = NULL;


	__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "open %p %d", ptr, size);


	gme_err_t err = gme_open_data(ptr, size, &emu, 44100);

	__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "Done ERR '%s'", err);

	if(!err) {
		err = gme_start_track(emu, 0);

		track_info_t track;
		err = gme_track_info(emu, &track, 0);


		if(!err) {

			GMEInfo *info = new GMEInfo();
			info->emu = emu;
			info->currentSong = 0;
			info->lastTrack = track;
			env->ReleaseByteArrayElements(bArray, ptr, 0);
			return (jlong)info;
		}
	}

	env->ReleaseByteArrayElements(bArray, ptr, 0);
	return NULL;
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1unload(JNIEnv *env, jobject obj, jlong song)
{
	GMEInfo *info = (GMEInfo*)song;
	if(info->emu)
		gme_delete(info->emu);
	delete info;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1setTune(JNIEnv *env, jobject obj, jlong song, jint tune)
{
	GMEInfo *info = (GMEInfo*)song;
	gme_err_t err = gme_start_track(info->emu, tune);
	info->currentSong = tune;
	return true;
}


JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray bArray, int size)
{
	GMEInfo *info = (GMEInfo*)song;
	jshort *ptr = env->GetShortArrayElements(bArray, NULL);
	//__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "Getting %d shorts from %p", size, emu);
	gme_err_t err = gme_play(info->emu, size, ptr);
	//__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "Result %d", err);
	env->ReleaseShortArrayElements(bArray, ptr, 0);
	return size;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1seekTo(JNIEnv *env, jobject obj, jlong song, int where)
{
	GMEInfo *info = (GMEInfo*)song;
	gme_seek(info->emu, where);
	return true;
}


JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1getStringInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	GMEInfo *info = (GMEInfo*)song;
	switch(what)
	{
	case INFO_TITLE:
		return env->NewStringUTF(info->lastTrack.song);
	case INFO_AUTHOR:
		return env->NewStringUTF(info->lastTrack.author);
	case INFO_COPYRIGHT:
		return env->NewStringUTF(info->lastTrack.copyright);
	case INFO_TYPE:
		return env->NewStringUTF(info->lastTrack.system);
	case INFO_GAME:
		return env->NewStringUTF(info->lastTrack.game);
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1getIntInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	GMEInfo *info = (GMEInfo*)song;
	switch(what)
	{
	case INFO_LENGTH:
		return info->lastTrack.length;
	case INFO_SUBTUNES:
		return info->lastTrack.track_count;
	case INFO_STARTTUNE:
		return 0;
	}
	return -1;

}

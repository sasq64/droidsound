
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
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
#define INFO_SUBTUNE_TITLE 8

#include "gme/gme.h"

//#include "log.h"
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



JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1canHandle(JNIEnv *env, jobject obj, jstring name)
{
	return true;
}

struct GMEInfo {
	 Music_Emu *emu;
	 int currentSong;
	 int trackCount;
	 gme_info_t* lastTrack;
	 char mainTitle[256];
	 bool started;
};

//static Music_Emu *emu = NULL;
//static int currentSong = 0;
//static track_info_t lastTrack;

jlong setUp(Music_Emu *emu)
{
	gme_err_t err;

    gme_info_t* track0;
    gme_info_t* track1;
	err = gme_track_info(emu, &track0, 0);

	int track_count = gme_track_count(emu);


	//info->gme_track_count();

	__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "(RC %s) -> SONG '%s' GAME '%s' LEN '%d' COUNT '%d'", err, track0->song, track0->game, track0->length, track_count);

	if(!err) {
		GMEInfo *info = new GMEInfo();


		if(!strlen(track0->song)) {
			bool nameOk = false;
			// If name is all upper case it is most likely a rom name
			for(int i=0; i<strlen(track0->game); i++) {
				char c = track0->game[i];
				if(isalpha(c) && !isupper(c)) {
					nameOk = true;
				}
			}
			if(nameOk) {
				strcpy(info->mainTitle, track0->game);
			} else {
				info->mainTitle[0] = 0;
			}
		} else {
			strcpy(info->mainTitle, track0->song);

			if(track_count > 1) {
				err = gme_track_info(emu, &track1, 1);

				__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "'%s' vs '%s'", track0->song, track1->song);

				if(!err && strcmp(track0->song, track1->song) != 0) {
					// We have more than one subsong, and their names differ
					strcpy(info->mainTitle, track0->game);
				}
			}
		}

		info->started = false;
		info->emu = emu;
		info->currentSong = 0;
		//info->emu->ignore_silence(true);
		info->lastTrack = track0;
		info->trackCount = track_count;
		return (jlong)info;
	}
	return 0;
}

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1loadFile(JNIEnv *env, jobject obj, jstring fname)
{
	jboolean iscopy;
	const char *s = env->GetStringUTFChars(fname, &iscopy);
	Music_Emu *emu = NULL;
	jlong rc = 0;
	gme_err_t err = gme_open_file(s, &emu, 44100);

	__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "Loading from file '%s' => %s", s, err ? err : "OK");

	if(!err) {
		rc = setUp(emu);
	}
	env->ReleaseStringUTFChars(fname, s);

	return rc;

}

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1load(JNIEnv *env, jobject obj, jbyteArray bArray, int size)
{
	jbyte *ptr = env->GetByteArrayElements(bArray, NULL);
	Music_Emu *emu = NULL;
	jlong rc = 0;

	__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "Open %p %d", ptr, size);


	gme_err_t err = gme_open_data(ptr, size, &emu, 44100);

	__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "Done ERR '%s'", err);

	if(!err) {
		rc = setUp(emu);
	}

	env->ReleaseByteArrayElements(bArray, ptr, 0);
	return rc;
}


JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1unload(JNIEnv *env, jobject obj, jlong song)
{
	GMEInfo *info = (GMEInfo*)song;
    if (info->currentSong) {
        gme_free_info(info->lastTrack);
    }
    
	if(info->emu) {
		gme_delete(info->emu);
    }
    
	delete info;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1setTune(JNIEnv *env, jobject obj, jlong song, jint tune)
{
	GMEInfo *info = (GMEInfo*)song;
	gme_err_t err = gme_start_track(info->emu, tune);
	info->started = true;

	gme_info_t* track;
	err = gme_track_info(info->emu, &track, tune);
    gme_free_info(info->lastTrack);
	info->lastTrack = track;

	__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "SetTune '%s' -> %s %d", err, track->song, track->length);

	info->currentSong = tune;
	return true;
}


JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray sArray, int size)
{
	GMEInfo *info = (GMEInfo*)song;

	if(!info->started) {
		gme_err_t err = gme_start_track(info->emu, 0);
		info->started = true;
	}

	if(gme_track_ended(info->emu)) {
		return -1;
	}

	jshort *ptr = env->GetShortArrayElements(sArray, NULL);
	//__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "Getting %d shorts from %p", size, info->emu);
	gme_err_t err = gme_play(info->emu, size, ptr);
	//__android_log_print(ANDROID_LOG_VERBOSE, "GMEPlugin", "Result %d", err);
	env->ReleaseShortArrayElements(sArray, ptr, 0);
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
    int track_count = gme_track_count(info->emu);
    
	switch(what)
	{
	case INFO_TITLE:
		return NewString(env, info->mainTitle);
	case INFO_SUBTUNE_TITLE:
		if(track_count > 1) {
			return NewString(env, info->lastTrack->song);
		} else {
			return 0;
		}
	case INFO_AUTHOR:
		return NewString(env, info->lastTrack->author);
	case INFO_COPYRIGHT:
		return NewString(env, info->lastTrack->copyright);
	case INFO_TYPE:
		return NewString(env, info->lastTrack->system);
	case INFO_GAME:
		return NewString(env, info->lastTrack->game);
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1getIntInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	GMEInfo *info = (GMEInfo*)song;
	switch(what)
	{
	case INFO_LENGTH:
		return info->lastTrack->length;
	case INFO_SUBTUNES:
		return info->trackCount;
	case INFO_STARTTUNE:
		return 0;
	}
	return -1;

}

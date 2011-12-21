#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <android/log.h>

#include <uade/uade.h>
#include "com_ssb_droidsound_plugins_UADEPlugin.h"

#define INFO_TITLE 0
#define INFO_AUTHOR 1
#define INFO_LENGTH 2
#define INFO_TYPE 3
#define INFO_COPYRIGHT 4
#define INFO_GAME 5
#define INFO_SUBTUNES 6
#define INFO_STARTTUNE 7

static char baseDir[256] = "";
static struct uade_config config;
static struct uade_state *state;
static const struct uade_song_info *info;
static int startSong;

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1init(JNIEnv *env, jobject obj, jstring basedir)
{
	jboolean iscopy;
	const char *s = env->GetStringUTFChars(basedir, &iscopy);
	strcpy(baseDir, s);
	env->ReleaseStringUTFChars(basedir, s);

        uade_config_set_defaults(&config);
}

static jstring NewString(JNIEnv *env, const char *str)
{
	static jchar temp[256];
	jchar *ptr = temp;
	while(*str) {
		unsigned char c = (unsigned char)*str++;
		*ptr++ = (c < 0x7f && c >= 0x20) || c >= 0xa0 ? c : '?';
	}
	jstring j = env->NewString(temp, ptr - temp);
	return j;
}

JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1loadFile(JNIEnv *env, jobject obj, jstring fname)
{
	jboolean iscopy;
	const char *filename = env->GetStringUTFChars(fname, &iscopy);

        if (state == NULL) {
                state = uade_new_state(&config, baseDir);
                if (state == NULL) {
                        __android_log_print(ANDROID_LOG_ERROR, "UADEPlugin", "Unable to construct UADE state.");
                        return 0;
                }
        }

        int rc;
	if ((rc = uade_is_our_file(filename, state)) == 0) {
		__android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "uade_is_our_file(): rejected %s (code %d)", filename, rc);
		return 0;
	}

        if ((rc = uade_play(filename, 0, state)) != 1) {
                __android_log_print(ANDROID_LOG_VERBOSE, "UADEPlugin", "uade_play(): failed %s (code %d)", filename, rc);
                return 0;
        }

        info = uade_get_song_info(state);
        startSong = info->subsongs.cur;

	env->ReleaseStringUTFChars(fname, filename);

	return 1;
}

JNIEXPORT void Java_com_ssb_droidsound_plugins_UADEPlugin_N_1unload(JNIEnv *env, jobject obj, jlong song)
{
        if (state != NULL) {
                uade_cleanup_state(state);
                state = NULL;
                info = NULL;
        }
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray sArray, jint size)
{
	jshort *dest = env->GetShortArrayElements(sArray, NULL);

        struct uade_event event;
        jint rc = -1;

        if (! uade_get_event(&event, state)) {
                switch (event.type) {
                case UADE_EVENT_EAGAIN:
                        break;

                case UADE_EVENT_DATA: {
                        int i;
                        /* We just hope that we run out of event.data.size before size! */
                        for (i = 0; i < event.data.size && i < size; i ++) {
                                dest[i] = event.data.data[i];
                        }
                        if (i != event.data.size) {
                                __android_log_print(ANDROID_LOG_WARN, "UADEPlugin", "UADE generated %d samples, but we only could read %d samples", event.data.size, size);
                        }
                        rc = i;
                        break;
                }

                case UADE_EVENT_MESSAGE:
                        __android_log_print(ANDROID_LOG_INFO, "UADEPlugin", "Message from native code: %s", event.msg);
                        break;

                case UADE_EVENT_SONG_END:
                        __android_log_print(ANDROID_LOG_INFO, "UADEPlugin", "%s: %s", event.songend.happy ? "Song end" : "Bad song end", event.songend.reason);
                        break;

                default:
                        __android_log_print(ANDROID_LOG_ERROR, "UADEPlugin", "uade_get_event() returned unhandled event %s", uade_event_name(&event));
                        break;
                }
        }

	env->ReleaseShortArrayElements(sArray, dest, 0);
	return rc;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1seekTo(JNIEnv *, jobject, jlong, jint)
{
	return false;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1setTune(JNIEnv *env, jobject obj, jlong song, jint tune)
{
        uade_set_subsong(tune, state);
	return true;
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1getStringInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	switch(what) {
	case INFO_TYPE:
		return NewString(env, info->formatname);
	}
	return NewString(env, "");
}

#define OPT_FILTER 1
#define OPT_RESAMPLING 2
#define OPT_NTSC 3
#define OPT_PANNING 5

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1setOption(JNIEnv *env, jclass cl, jint what, jint val)
{
	switch(what) {
	case OPT_FILTER:
                uade_config_set_option(&config, UC_FILTER_TYPE, val ? "a500" : "none");
		break;

	case OPT_NTSC:
                uade_config_set_option(&config, val ? UC_NTSC : UC_PAL, NULL);
		break;

	case OPT_RESAMPLING: {
                const char *options[] = { "none", "default", "sinc" };
                if (val >= 0 && val <= 2) {
                    uade_config_set_option(&config, UC_RESAMPLER, options[val]);
                }
		break;
        }

	case OPT_PANNING: {
                const char *options[] = { "0", "0.25", "0.5", "0.75", "1" };
                if (val >= 0 && val <= 4) {
                    uade_config_set_option(&config, UC_PANNING_VALUE, options[val]);
                    if (val == 4) {
                        uade_effect_disable(&state->effectstate, UADE_EFFECT_PAN);
                    } else {
                        uade_effect_enable(&state->effectstate, UADE_EFFECT_PAN);
                    }
                }
		break;
        }
	}
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_UADEPlugin_N_1getIntInfo(JNIEnv *env, jobject obj, jlong song, jint what)
{
	switch(what)
	{
	case INFO_LENGTH:
		return -1;
	case INFO_SUBTUNES:
		return info->subsongs.max - info->subsongs.min + 1;
	case INFO_STARTTUNE:
		return startSong;
	}
	return -1;
}


#include <stdlib.h>
#include <stdio.h>

#include <android/log.h>
#include "com_ssb_droidsound_plugins_VICEPlugin.h"

extern "C" {

#include "archdep.h"
#include "drive.h"
#include "gfxoutput.h"
#include "init.h"
#include "initcmdline.h"
#include "lib.h"
#include "machine.h"
#include "maincpu.h"
#include "psid.h"
#include "resources.h"
#include "sound.h"
#include "sysfile.h"

/* In our overridden maincpu.c */
extern void psid_play(short *buf, int size);

}

static jstring NewString(JNIEnv *env, unsigned char *str)
{
	static jchar temp[256];
	jchar *ptr = temp;
	while (*str) {
		unsigned char c = *str++;
		*ptr++ = (c < 0x7f && c >= 0x20) || c >= 0xa0 ? c : '?';
	}
	//*ptr++ = 0;
	jstring j = env->NewString(temp, ptr - temp);
	return j;
}

static bool videomode_is_ntsc;
static bool videomode_is_forced;

static void c64_song_init()
{
	/* Set default, potentially overridden by reset. */
	resources_set_int("MachineVideoStandard", videomode_is_ntsc ? MACHINE_SYNC_NTSC : MACHINE_SYNC_PAL);
	/* Default to 6581 in case tune doesn't specify. */
	resources_set_int("SidModel", 0);

	/* Reset C64, which also initializes PSID for us. */
	machine_trigger_reset(MACHINE_RESET_MODE_SOFT);

	/* Now force video mode if we are asked to. */
	if (videomode_is_forced) {
		resources_set_int("MachineVideoStandard", videomode_is_ntsc ? MACHINE_SYNC_NTSC : MACHINE_SYNC_PAL);
	}
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_VICEPlugin_N_1setOption(JNIEnv *env, jclass cl, jint what, jint val)
{
	__android_log_print(ANDROID_LOG_VERBOSE, "VICEPlugin", "Setting %d to %d", what, val);
	switch(what) {
	case com_ssb_droidsound_plugins_VICEPlugin_OPT_FILTER:
		resources_set_int("SidFilters", val);
		break;
	case com_ssb_droidsound_plugins_VICEPlugin_OPT_NTSC:
		videomode_is_ntsc = (val & 1) != 0;
		videomode_is_forced = (val & 2) != 0;
		break;
	case com_ssb_droidsound_plugins_VICEPlugin_OPT_RESAMPLING:
		resources_set_int("SidResidSampling", val);
		break;
	}
}

int console_mode = 1;
int vsid_mode = 1;
int video_disabled_mode = 1;

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_VICEPlugin_N_1loadFile(JNIEnv *env, jclass cl, jstring name)
{
	__android_log_print(ANDROID_LOG_VERBOSE, "VICEPlugin", "in load()");

	const char* cname = env->GetStringUTFChars(name, 0);
	int ret = psid_load_file(cname);
	env->ReleaseStringUTFChars(name, cname);
        if (ret != 0) {
	    return NewString(env, (unsigned char *) "failure code from psid_load_file()");
        }

        c64_song_init();

        return 0;
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_VICEPlugin_N_1unload(JNIEnv *env, jclass cl)
{
	/* Selecting this tune unloads some psid-related structures.
	 * Unfortunately to us, there are a large number of other things
	 * that are statically allocated in VICE codebase. */
	psid_set_tune(-1);
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_VICEPlugin_N_1getSoundData(JNIEnv *env, jclass cl, jshortArray sArray, jint size)
{
	jshort *ptr = env->GetShortArrayElements(sArray, NULL);
	psid_play(ptr, size);
    	env->ReleaseShortArrayElements(sArray, ptr, 0);
	return size;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_VICEPlugin_N_1setTune(JNIEnv *env, jclass cl, jint tune)
{
	psid_set_tune(tune);
        c64_song_init();
	return true;
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_VICEPlugin_N_1setDataDir(JNIEnv *env, jclass cl, jstring path)
{
	const char* cpath = env->GetStringUTFChars(path, 0);

	__android_log_print(ANDROID_LOG_VERBOSE, "VICEPlugin", "setRootDir() to %s", cpath);
	maincpu_early_init();
	machine_setup_context();
	drive_setup_context();
	machine_early_init();
	sysfile_init("C64");

	gfxoutput_early_init();

	if (init_resources() < 0) {
		archdep_startup_log_error("Failed to init resources");
		return;
        }

	/* Set factory defaults.  */
	if (resources_set_defaults() < 0) {
		archdep_startup_log_error("Cannot set defaults.\n");
		return;
	}

	resources_set_int("SidResidSampling", 0);
	resources_set_int("VICIIVideoCache", 0);
	resources_set_string("Directory", cpath);

	if (init_main() < 0) {
		archdep_startup_log_error("Failed to init main");
		return;
	}

	env->ReleaseStringUTFChars(path, cpath);
}


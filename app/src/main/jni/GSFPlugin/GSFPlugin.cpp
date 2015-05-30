
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <jni.h>
#include <android/log.h>

#include <types.h>

extern "C" {
#include "VBA/psftag.h"
#include "gsf.h"
}

#include "com_ssb_droidsound_plugins_GSFPlugin.h"

#include "../common/Fifo.h"
#include "../common/Misc.h"

extern "C" {
int defvolume=1000;
int relvolume=1000;
int TrackLength=0;
int FadeLength=0;
int IgnoreTrackLength, DefaultLength=150000;
int playforever=0;
int fileoutput=0;
int TrailingSilence=1000;
int DetectSilence=0, silencedetected=0, silencelength=5;
}

int cpupercent=0, sndSamplesPerSec, sndNumChannels;
int sndBitsPerSample=16;

int deflen=120,deffade=4;

int decode_pos_ms; // current decoding position, in milliseconds

extern unsigned short soundFinalWave[2304];

extern int soundBufferLen;

/*
extern char soundEcho;
extern char soundLowPass;
extern char soundReverse;
extern char soundQuality;*/

static Fifo *fifo = NULL;

extern "C" void end_of_track()
{

	__android_log_print(ANDROID_LOG_VERBOSE, "GSF", "END OF TRACK");
}

extern "C" void writeSound(void)
{
	int tmp;
	//int ret = soundBufferLen;
	//ao_play(snd_ao, (char*)soundFinalWave, ret);
	//decode_pos_ms += (ret/(2*sndNumChannels) * 1000)/(float)sndSamplesPerSec;

	//__android_log_print(ANDROID_LOG_VERBOSE, "GSF", "%d/%d", sndNumChannels, sndSamplesPerSec);


	fifo->putShorts((short*)soundFinalWave, soundBufferLen/2);

	decode_pos_ms += (soundBufferLen/(2*sndNumChannels) * 1000)/sndSamplesPerSec;

}




JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_GSFPlugin_N_1loadFile(JNIEnv *env, jobject obj, jstring fname)
{

	decode_pos_ms = 0;
	//seek_needed = -1;
	TrailingSilence=1000;
	IgnoreTrackLength=1;
	DetectSilence=1;
	silencedetected=0;
	playforever=0;

	const char *file_name = env->GetStringUTFChars(fname, NULL);

	if(fifo == NULL)
		fifo = new Fifo(128 * 1024);

	int r = GSFRun((char*)file_name);

	__android_log_print(ANDROID_LOG_VERBOSE, "GSF", "LOAD: %d, bufSize: %d", r, soundBufferLen);

	return 1;
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_GSFPlugin_N_1unload(JNIEnv *, jobject, jlong)
{
	GSFClose();
	if(fifo != NULL)
		delete fifo;
	fifo = NULL;
}


JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_GSFPlugin_N_1getSoundData(JNIEnv *env, jobject obj, jlong song, jshortArray sArray, jint size)
{
	int lastTL = TrackLength;
	while(fifo->filled() < size*2) {
		EmulationLoop();
		//if(silencedetected != 0 || TrackLength != lastTL)
		//	break;
	}

	//__android_log_print(ANDROID_LOG_VERBOSE, "GSF", "TL: %d, SILENCE: %d, decode_pos_ms %d", TrackLength, silencedetected, decode_pos_ms);

	//if(silencedetected > 100000)
	//	return -1;

	if(decode_pos_ms > TrackLength)
		return -1;

	if(fifo->filled() == 0)
		return 0;



	jshort *dest = env->GetShortArrayElements(sArray, NULL);
	int len = fifo->getShorts(dest, size);
	env->ReleaseShortArrayElements(sArray, dest, 0);



	return len;
}


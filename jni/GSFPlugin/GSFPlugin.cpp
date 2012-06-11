
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

//#include "com_ssb_droidsound_plugins_SexyPSFPlugin.h"

#define INFO_TITLE 0
#define INFO_AUTHOR 1
#define INFO_LENGTH 2
#define INFO_TYPE 3
#define INFO_COPYRIGHT 4
#define INFO_GAME 5
#define INFO_SUBTUNES 6
#define INFO_STARTTUNE 7
#define INFO_SUBTUNE_TITLE 8

unsigned char *outBuffer;
unsigned char *outPtr;

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

double decode_pos_ms; // current decoding position, in milliseconds

extern unsigned short soundFinalWave[2304];

extern int soundBufferLen;
extern char soundEcho;
extern char soundLowPass;
extern char soundReverse;
extern char soundQuality;

extern "C" void end_of_track()
{
	//g_playing = 0;
}

extern "C" void writeSound(void)
{
	int tmp;
	//int ret = soundBufferLen;
	//ao_play(snd_ao, (char*)soundFinalWave, ret);
	//decode_pos_ms += (ret/(2*sndNumChannels) * 1000)/(float)sndSamplesPerSec;
}


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


void play()
{

	decode_pos_ms = 0;
	//seek_needed = -1;
	TrailingSilence=1000;

	int r = GSFRun("file.gsf");

	while(true) {
		EmulationLoop();
	}
}


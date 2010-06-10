
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <ctype.h>

#include <android/log.h> 
#include <jni.h>

#include "ModPlugin.h"
#include "modplug/modplug.h"
//#include "modplug/libmodplug/it_defs.h"
//#include "modplug/libmodplug/sndfile.h"

#define INFO_TITLE 1
#define INFO_AUTHOR 2
#define INFO_LENGTH 3
#define INFO_TYPE 4
#define INFO_COPYRIGHT 5
#define INFO_SUBSONGS 6
#define INFO_STARTSONG 7


jstring NewString(JNIEnv *env, const char *str)
{
	static char temp[256];
	char *ptr = temp;
	while(*str) {
		char c = *str++;
		*ptr++ = c < 0xf0 ? c : '?';
	}
	*ptr++ = 0;
	jstring j = env->NewStringUTF(temp);
	return j;
}



JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_ModPlugin_N_1canHandle(JNIEnv *env, jobject obj, jstring name)
{
	const char spaces[] = "      ";
	unsigned int ext = 0;
	jboolean iscopy;
	const char *fname = env->GetStringUTFChars(name, &iscopy);
	bool ok = false;

	if(strncasecmp(fname, "MOD.", 4) == 0)
		ok = true;
	else
	{
		const char *ptr = strrchr(fname, '.');
		if(ptr) {
			for(int i=0; i<4; i++)
			{
				ext <<= 8;
				if(!ptr[i+1])
					ptr = spaces;
				ext |= toupper(ptr[i+1]);
			}


			switch(ext)
			{
			case 'MOD ':
			case 'IT  ':
			case 'S3M ':
			case 'XM  ':
			case 'MTM ':
			case 'STM ':
			case '669 ':
			case 'FT  ':
				ok = true;
				break;
			}
		}
	}

	return ok;
}

ModPlugFile *mod = 0;
const char *modType = "MOD";
char author[128];

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_ModPlugin_N_1load(JNIEnv *env, jobject obj, jbyteArray bArray, int size)
{
	jboolean iscopy;
	jbyte *ptr = env->GetByteArrayElements(bArray, NULL);

	ModPlug_Settings settings;
	ModPlug_GetSettings(&settings);
	settings.mChannels = 2;
	settings.mFrequency = 44100;
	settings.mBits = 16;
	ModPlug_SetSettings(&settings);

	mod = ModPlug_Load(ptr, size);

	if(mod)
	{
		char temp[256];
		int c = ModPlug_NumSamples(mod);
		bool getNext = false;
		*author = 0;
		int noOf = -1;
		int noSlash = -1;
		int noCopy = -1;

		for(int i=0; i<c; i++)
		{
			ModPlug_SampleName(mod, i, temp);

			//__android_log_print(ANDROID_LOG_VERBOSE, "ModPlugin", "Instrument '%s'", temp);

			if(noSlash<0 && strchr(temp, '/') != NULL)
			{
				noSlash = i;
			}

			char *w = strtok(temp, " :");
			while(w) {

				if(getNext)
				{
					ModPlug_SampleName(mod, i, temp);
					strcpy(author, w);
					getNext = false;
					break;
				}

				if(noCopy<0 && strcasecmp(w, "(C)") == 0)
				{
					noCopy = i;
				}

				if(noOf<0 && strcasecmp(w, "OF") == 0)
				{
					noOf = i;
				}


				if(strcasecmp(w, "BY") == 0)
					getNext = true;
				w = strtok(NULL, " :");
			}
			if(*author != 0)
				break;
		}

		if(*author == 0)
		{
			if(noSlash >= 0)
			{
				ModPlug_SampleName(mod, noSlash, temp);
				strcpy(author, temp);
			}
			else
			if(noCopy >= 0)
			{
				ModPlug_SampleName(mod, noCopy, temp);
				strcpy(author, temp);
			}
			else
			if(noOf >= 0)
			{
				ModPlug_SampleName(mod, noOf, temp);
				strcpy(author, temp);
			}
		}

	}

	env->ReleaseByteArrayElements(bArray, ptr, 0);
	return (mod != 0);
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_ModPlugin_N_1unload(JNIEnv *env, jobject obj)
{
	if(mod)
		ModPlug_Unload(mod);
	mod = NULL;
}


JNIEXPORT jint JNICALL Java_com_ssb_droidsound_ModPlugin_N_1getSoundData(JNIEnv *env, jobject obj, jshortArray bArray, int size)
{
	//unsigned char *ptr = (unsigned char *)env->GetDirectBufferAddress(buffer);
	//int size = env->GetDirectBufferCapacity(buffer);

	jbyte *ptr = (jbyte*)env->GetShortArrayElements(bArray, NULL);

	fprintf(stderr, "ptr %p, size %d\n", ptr, size);
	int rc = ModPlug_Read(mod, (void*)ptr, size*2);
	/*for(int i=0; i<size; i++)
	{
		unsigned char x = ptr[i*2];
		ptr[i*2] = ptr[i*2+1];
		ptr[i*2+1] = x;
	}*/

	//fprintf(stderr, "(%d) %d %d %d %d\n", rc, ptr[size/2], ptr[size/2+1], ptr[size-10], ptr[size-9]);

	env->ReleaseShortArrayElements(bArray, (jshort*)ptr, 0);

	return rc / 2;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_ModPlugin_N_1seekTo(JNIEnv *env, jobject obj, int where)
{
	ModPlug_Seek(mod, where);
	return true;
}


JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_ModPlugin_N_1getStringInfo(JNIEnv *env, jobject obj, jint what)
{
	switch(what)
	{
	case INFO_AUTHOR:
		if(mod)
			return NewString(env, author);
		break;
	case INFO_TITLE:
		if(mod)
			return NewString(env, ModPlug_GetName(mod));
		break;
	case INFO_TYPE:
		if(mod)
			return NewString(env, modType);
		break;
	}
	return 0;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_ModPlugin_N_1getIntInfo(JNIEnv *env, jobject obj, jint what)
{
	switch(what)
	{
	case INFO_LENGTH:
		if(mod)
			return  ModPlug_GetLength(mod);
	case INFO_SUBSONGS:
		return 0;
	case INFO_STARTSONG:
		return 0;
	}
	return -1;

}

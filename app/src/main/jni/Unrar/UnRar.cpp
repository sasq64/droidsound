
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <ctype.h>

#include <android/log.h> 
#include <jni.h>

#define _UNIX
///#define  RARDLL
#include  "unrar/dll.hpp"

#include "com_ssb_droidsound_utils_UnRar.h"

/*
static int CALLBACK CallbackProc(unsigned int msg, long myBufferPtr, long rarBuffer, long bytesProcessed) {
  switch(msg) {
    case UCM_CHANGEVOLUME:
      return -1;
      break;
    case UCM_PROCESSDATA:
      memcpy(*(char**)myBufferPtr, (char*)rarBuffer, bytesProcessed);
      *(char**)myBufferPtr += bytesProcessed;
      return 1;
      break;
    case UCM_NEEDPASSWORD:
      return -1;
      break;
  }
  return 0;
} */

static jfieldID refField;

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_UnRar_N_1extractAll(JNIEnv *env, jobject obj, jstring archive, jstring target) {


	const char *targetDir = env->GetStringUTFChars(target, NULL);
	const char *rarName = env->GetStringUTFChars(archive, NULL);

	RAROpenArchiveDataEx archiveInfo;

	memset(&archiveInfo, 0, sizeof(archiveInfo));
	archiveInfo.CmtBuf = NULL;
	//archiveInfo.OpenMode = RAR_OM_LIST;
	archiveInfo.OpenMode = RAR_OM_EXTRACT;
	archiveInfo.ArcName = (char*)rarName;

	HANDLE rarFile = RAROpenArchiveEx(&archiveInfo);

	RARHeaderDataEx fileInfo;

	while(true) {
	    int RHCode = RARReadHeaderEx(rarFile, &fileInfo);
	    if(RHCode != 0) break;

	    __android_log_print(ANDROID_LOG_VERBOSE, "UnRar", "Extracting %s (%d => %d)", fileInfo.FileName, fileInfo.PackSize, fileInfo.UnpSize);

	    //RARSetCallback(rarFile, CallbackProc, NULL);
	    int PFCode = RARProcessFile(rarFile, RAR_EXTRACT, (char*)targetDir, NULL);
	}

	env->ReleaseStringUTFChars(archive, rarName);
	env->ReleaseStringUTFChars(target, targetDir);

	return 0;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_UnRar_N_1open(JNIEnv *env, jobject obj, jstring archive)
{

	const char *rarName = env->GetStringUTFChars(archive, NULL);
	RAROpenArchiveDataEx archiveInfo;

	memset(&archiveInfo, 0, sizeof(archiveInfo));
	archiveInfo.CmtBuf = NULL;
	archiveInfo.OpenMode = RAR_OM_EXTRACT;
	archiveInfo.ArcName = (char*)rarName;
	HANDLE rarFile = RAROpenArchiveEx(&archiveInfo);

	//int RHCode = RARReadHeaderEx(rarFile, &fileInfo);

	env->ReleaseStringUTFChars(archive, rarName);

	jclass cl = env->GetObjectClass(obj);
	refField = env->GetFieldID(cl, "rarRef", "J");
	env->SetLongField(obj, refField, (jlong)rarFile);


}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_UnRar_N_1skip(JNIEnv *env, jobject obj)
{
	HANDLE rarFile = (HANDLE)env->GetLongField(obj, refField);
	int PFCode = RARProcessFile(rarFile, RAR_SKIP, NULL, NULL);
	return PFCode;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_UnRar_N_1extract(JNIEnv *env, jobject obj, jstring target)
{
	const char *targetDir = env->GetStringUTFChars(target, NULL);
	HANDLE rarFile = (HANDLE)env->GetLongField(obj, refField);
	int PFCode = RARProcessFile(rarFile, RAR_EXTRACT, (char*)targetDir, NULL);
	env->ReleaseStringUTFChars(target, targetDir);
	return PFCode;
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_utils_UnRar_N_1getFileName(JNIEnv *env, jobject obj)
{
	HANDLE rarFile = (HANDLE)env->GetLongField(obj, refField);
	RARHeaderDataEx fileInfo;
	int RHCode = RARReadHeaderEx(rarFile, &fileInfo);
	if(RHCode != 0) return NULL;
	return env->NewStringUTF(fileInfo.FileName);
}


JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_UnRar_N_1getFileSize(JNIEnv *env, jobject obj)
{
	HANDLE rarFile = (HANDLE)env->GetLongField(obj, refField);
	RARHeaderDataEx fileInfo;
	int RHCode = RARReadHeaderEx(rarFile, &fileInfo);
	if(RHCode != 0) return -1;
	return fileInfo.UnpSize;
}

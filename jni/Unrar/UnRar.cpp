
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


	return 0;
}

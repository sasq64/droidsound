
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <ctype.h>

#include <android/log.h> 
#include <jni.h>

#include "ziplib/zip.h"

#include "com_ssb_droidsound_NativeZipFile.h"

jstring NewString(JNIEnv *env, const char *str)
{
	static char temp[256];
	char *ptr = temp;
	while(*str) {
		char c = *str++;
		*ptr++ = (c < 0x7f) && (c >= 0x20) ? c : '?';
	}
	*ptr++ = 0;
	jstring j = env->NewStringUTF(temp);
	return j;
}

static struct zip *zipFile;

JNIEXPORT void JNICALL Java_com_ssb_droidsound_NativeZipFile_NativeZipFile(JNIEnv *env, jobject obj, jstring fileName)
{
	jboolean iscopy;
	const char *fname = env->GetStringUTFChars(fileName, &iscopy);
	zipFile = zip_open(fname, 0, NULL);
	env->ReleaseStringUTFChars(fileName, fname);
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_NativeZipFile_getCount(JNIEnv *env, jobject obj)
{
	return zip_get_num_files(zipFile);
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_NativeZipFile_getEntry(JNIEnv *env, jobject obj, jint e)
{
	const char *name = zip_get_name(zipFile, e, 0 /* ZIP_FL_UNCHANGED */ );
	return NewString(env, name);
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_NativeZipFile_getSize(JNIEnv *env, jobject obj, jint e)
{
	struct zip_stat sz;
	zip_stat_index(zipFile, e, 0, &sz);
	return sz.size;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_NativeZipFile_findEntry(JNIEnv *env, jobject obj, jstring name)
{
	jboolean iscopy;
	const char *fname = env->GetStringUTFChars(name, &iscopy);
	int e = zip_name_locate(zipFile, fname, 0);
	env->ReleaseStringUTFChars(name, fname);
	return e;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_NativeZipFile_readData(JNIEnv *env, jobject obj, jint e, jbyteArray target)
{
	jboolean iscopy;
	jbyte *ptr = env->GetByteArrayElements(target, NULL);
	int len = env->GetArrayLength(target);
	int rc = -1;
	struct zip_file *zf = zip_fopen_index(zipFile, e, 0);
	if(zf) {
		rc = zip_fread(zf, ptr, len);
		zip_fclose(zf);
	}

	env->ReleaseByteArrayElements(target, ptr, 0);
	return rc;
}

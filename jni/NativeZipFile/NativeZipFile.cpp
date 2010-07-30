
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <ctype.h>

#include <android/log.h> 
#include <jni.h>

#include "ziplib/zip.h"

#include "com_ssb_droidsound_utils_NativeZipFile.h"

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

//static struct zip *zipFile;
static jfieldID refField;

JNIEXPORT void JNICALL Java_com_ssb_droidsound_utils_NativeZipFile_openZipFile(JNIEnv *env, jobject obj, jstring fileName)
{
	jboolean iscopy;
	const char *fname = env->GetStringUTFChars(fileName, &iscopy);
	struct zip *zipFile = zip_open(fname, 0, NULL);

	jclass cl = env->GetObjectClass(obj);
	refField = env->GetFieldID(cl, "zipRef", "J");
	env->SetLongField(obj, refField, (jlong)zipFile);

	__android_log_print(ANDROID_LOG_VERBOSE, "TinySidPlugin", "ZIPFile %p", zipFile);

	env->ReleaseStringUTFChars(fileName, fname);
}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_utils_NativeZipFile_closeZipFile(JNIEnv *env, jobject obj)
{
	struct zip *zipFile = (struct zip*)env->GetLongField(obj, refField);
	zip_close(zipFile);
	env->SetLongField(obj, refField, 0);
}


JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_NativeZipFile_getCount(JNIEnv *env, jobject obj)
{
	struct zip *zipFile = (struct zip*)env->GetLongField(obj, refField);

	return zip_get_num_files(zipFile);
}

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_utils_NativeZipFile_getEntry(JNIEnv *env, jobject obj, jint e)
{
	struct zip *zipFile = (struct zip*)env->GetLongField(obj, refField);

	const char *name = zip_get_name(zipFile, e, 0 /* ZIP_FL_UNCHANGED */ );
	return NewString(env, name);
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_NativeZipFile_getSize(JNIEnv *env, jobject obj, jint e)
{
	struct zip *zipFile = (struct zip*)env->GetLongField(obj, refField);

	struct zip_stat sz;
	zip_stat_index(zipFile, e, 0, &sz);
	return sz.size;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_NativeZipFile_findEntry(JNIEnv *env, jobject obj, jstring name)
{
	struct zip *zipFile = (struct zip*)env->GetLongField(obj, refField);

	jboolean iscopy;
	const char *fname = env->GetStringUTFChars(name, &iscopy);
	int e = zip_name_locate(zipFile, fname, 0);
	env->ReleaseStringUTFChars(name, fname);
	return e;
}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_NativeZipFile_readData(JNIEnv *env, jobject obj, jint e, jbyteArray target)
{
	struct zip *zipFile = (struct zip*)env->GetLongField(obj, refField);

	jboolean iscopy;
	jbyte *ptr = env->GetByteArrayElements(target, NULL);
	int len = env->GetArrayLength(target);
	int rc = -1;
	struct zip_file *zf = zip_fopen_index(zipFile, e, 0);

	//__android_log_print(ANDROID_LOG_VERBOSE, "TinySidPlugin", "Reading %d bytes from %p", len, zf);

	if(zf) {
		rc = zip_fread(zf, ptr, len);
		zip_fclose(zf);
	}

	env->ReleaseByteArrayElements(target, ptr, 0);
	return rc;
}

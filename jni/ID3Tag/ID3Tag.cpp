
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <ctype.h>

#include <android/log.h> 

#include <jni.h>

#include "libid3tag/id3tag.h"

#include "com_ssb_droidsound_utils_ID3Tag.h"

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

static jfieldID refField = NULL;
static jfieldID tagRefField = NULL;


JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_utils_ID3Tag_openID3Tag(JNIEnv *env, jobject obj, jstring fileName)
{

	jboolean iscopy;
	const char *fname = env->GetStringUTFChars(fileName, &iscopy);

	struct id3_file *id3file = id3_file_open(fname, ID3_FILE_MODE_READONLY);

	__android_log_print(ANDROID_LOG_VERBOSE, "ID3Tag", "id3 %p", id3file);


	jclass cl = env->GetObjectClass(obj);
	refField = env->GetFieldID(cl, "id3Ref", "J");
	env->SetLongField(obj, refField, (jlong)id3file);

	cl = env->GetObjectClass(obj);
	tagRefField = env->GetFieldID(cl, "tagRef", "J");



	__android_log_print(ANDROID_LOG_VERBOSE, "ID3Tag", "id3 %p", id3file);

	env->ReleaseStringUTFChars(fileName, fname);

	return true;

}

JNIEXPORT void JNICALL Java_com_ssb_droidsound_utils_ID3Tag_closeID3Tag(JNIEnv *env, jobject obj)
{

	struct id3_file *id3file = 0;
	struct id3_tag *tag = 0;

	if(refField != 0)
		id3file = (struct id3_file*)env->GetLongField(obj, refField);
	if(tagRefField != 0)
		tag = (struct id3_tag*)env->GetLongField(obj, tagRefField);

	if(tag)
		id3_tag_delete(tag);
	if(id3file)
		id3_file_close(id3file);

}

#define INFO_TITLE 0
#define INFO_AUTHOR 1
#define INFO_LENGTH 2
#define INFO_TYPE 3
#define INFO_COPYRIGHT 4
#define INFO_GAME 5
#define INFO_SUBTUNES 6
#define INFO_STARTTUNE 7

#define ID3INFO_GENRE 100
#define ID3INFO_COMMENT 101
#define ID3INFO_ALBUM 102
#define ID3INFO_TRACK 103

JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_utils_ID3Tag_getStringInfo(JNIEnv *env, jobject obj, jint what)
{
	struct id3_file *id3file = (struct id3_file*)env->GetLongField(obj, refField);
	struct id3_tag *tag = (struct id3_tag*)env->GetLongField(obj, tagRefField);

	__android_log_print(ANDROID_LOG_VERBOSE, "ID3Tag", "Get String Info %p %p", id3file, tag);


	if(!tag && id3file)
		tag = id3_file_tag(id3file);

	if(!tag) return 0;

	const id3_ucs4_t *title = NULL;
	struct id3_frame *frame = NULL;

	__android_log_print(ANDROID_LOG_VERBOSE, "ID3Tag", "id3tag %p", tag);

	switch(what) {
	case INFO_TITLE:
		frame = id3_tag_findframe(tag, ID3_FRAME_TITLE, 0);
		break;
	case INFO_AUTHOR:
		frame = id3_tag_findframe(tag, ID3_FRAME_ARTIST, 0);
		break;
	case INFO_COPYRIGHT:
		frame = id3_tag_findframe(tag, ID3_FRAME_YEAR, 0);
		break;
	case ID3INFO_GENRE:
		frame = id3_tag_findframe(tag, ID3_FRAME_GENRE, 0);
		if(frame) {
			title = id3_field_getstrings(&frame->fields[1], 0);
			title = id3_genre_name(title);
		}
		break;
	case ID3INFO_ALBUM:
		frame = id3_tag_findframe(tag, ID3_FRAME_ALBUM, 0);
		break;
	case ID3INFO_TRACK:
		frame = id3_tag_findframe(tag, ID3_FRAME_TRACK, 0);
		break;
	case ID3INFO_COMMENT:
		frame = id3_tag_findframe(tag, ID3_FRAME_COMMENT, 0);
		if(frame) {
			__android_log_print(ANDROID_LOG_VERBOSE, "ID3Tag", "COMMENT %d fields", frame->nfields);
			if(frame->nfields >= 4)
				title = id3_field_getfullstring(&frame->fields[3]);
		}
		break;
	}

	if(frame) {

		__android_log_print(ANDROID_LOG_VERBOSE, "ID3Tag", "frame %p %d", frame, what);

		if(title == NULL)
			title = id3_field_getstrings(&frame->fields[1], 0);
		if(title) {
			__android_log_print(ANDROID_LOG_VERBOSE, "ID3Tag", "title %p", title);
			id3_utf8_t *titleu8 = id3_ucs4_utf8duplicate(title);
			jstring j = env->NewStringUTF((const char *)titleu8);
			return j;
		}
	}

	return NULL;

}

JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_ID3Tag_getIntInfo(JNIEnv *env, jobject obj, jint what)
{
	struct id3_file *id3file = (struct id3_file*)env->GetLongField(obj, refField);
	struct id3_tag *tag = (struct id3_tag*)env->GetLongField(obj, tagRefField);

	__android_log_print(ANDROID_LOG_VERBOSE, "ID3Tag", "Get String Int %p %p", id3file, tag);

	return 0;
}


JNIEXPORT jint JNICALL Java_com_ssb_droidsound_utils_ID3Tag_checkForTag(JNIEnv *env, jobject obj, jbyteArray bArray, jint offset, jint size)
{
	jbyte *ptr = env->GetByteArrayElements(bArray, NULL);
	int len = id3_tag_query((const id3_byte_t*)(ptr + offset), size);
	env->ReleaseByteArrayElements(bArray, ptr, 0);
	return len;
}

JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_utils_ID3Tag_parseTag(JNIEnv *env, jobject obj, jbyteArray bArray, jint offset, jint size)
{

	if(tagRefField != 0) {
		struct id3_tag *tag = (struct id3_tag*)env->GetLongField(obj, tagRefField);
		if(tag)
			id3_tag_delete(tag);
	}

	jbyte *ptr = env->GetByteArrayElements(bArray, NULL);

	const id3_byte_t*cptr = (const id3_byte_t*)(ptr + offset);

	__android_log_print(ANDROID_LOG_VERBOSE, "ID3Tag", "Checking at %p (%c %c)", cptr, cptr[0], cptr[1]);

	struct id3_tag *tag = id3_tag_parse(cptr, size);


	__android_log_print(ANDROID_LOG_VERBOSE, "ID3Tag", "DONE");

	jclass cl = env->GetObjectClass(obj);
	tagRefField = env->GetFieldID(cl, "tagRef", "J");
	env->SetLongField(obj, tagRefField, (jlong)tag);

	cl = env->GetObjectClass(obj);
	refField = env->GetFieldID(cl, "id3Ref", "J");
	env->SetLongField(obj, refField, (jlong)0);

	env->ReleaseByteArrayElements(bArray, ptr, 0);

	return tag != NULL;
}


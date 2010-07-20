/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_ssb_droidsound_plugins_GMEPlugin */

#ifndef _Included_com_ssb_droidsound_plugins_GMEPlugin
#define _Included_com_ssb_droidsound_plugins_GMEPlugin
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_ssb_droidsound_plugins_GMEPlugin
 * Method:    N_canHandle
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1canHandle
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_ssb_droidsound_plugins_GMEPlugin
 * Method:    N_load
 * Signature: ([BI)J
 */
JNIEXPORT jlong JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1load
  (JNIEnv *, jobject, jbyteArray, jint);

/*
 * Class:     com_ssb_droidsound_plugins_GMEPlugin
 * Method:    N_unload
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1unload
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_ssb_droidsound_plugins_GMEPlugin
 * Method:    N_getSoundData
 * Signature: (J[SI)I
 */
JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1getSoundData
  (JNIEnv *, jobject, jlong, jshortArray, jint);

/*
 * Class:     com_ssb_droidsound_plugins_GMEPlugin
 * Method:    N_seekTo
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1seekTo
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     com_ssb_droidsound_plugins_GMEPlugin
 * Method:    N_setTune
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1setTune
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     com_ssb_droidsound_plugins_GMEPlugin
 * Method:    N_getStringInfo
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1getStringInfo
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     com_ssb_droidsound_plugins_GMEPlugin
 * Method:    N_getIntInfo
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_ssb_droidsound_plugins_GMEPlugin_N_1getIntInfo
  (JNIEnv *, jobject, jlong, jint);

#ifdef __cplusplus
}
#endif
#endif

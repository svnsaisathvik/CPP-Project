/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class BookYourShow */

#ifndef _Included_BookYourShow
#define _Included_BookYourShow
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     BookYourShow
 * Method:    handleExistingCustomer
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_BookYourShow_handleExistingCustomer
  (JNIEnv *, jobject);

/*
 * Class:     BookYourShow
 * Method:    addNewCustomer
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_BookYourShow_addNewCustomer
  (JNIEnv *, jobject);

/*
 * Class:     BookYourShow
 * Method:    addTheatre
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_BookYourShow_addTheatre
  (JNIEnv *, jobject, jstring, jstring, jstring, jint, jstring, jint, jint);

/*
 * Class:     BookYourShow
 * Method:    addShow
 * Signature: (Ljava/lang/String;Ljava/lang/String;IIIIIIILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;D)V
 */
JNIEXPORT void JNICALL Java_BookYourShow_addShow
  (JNIEnv *, jobject, jstring, jstring, jint, jint, jint, jint, jint, jint, jint, jstring, jstring, jstring, jstring, jdouble);

/*
 * Class:     BookYourShow
 * Method:    deleteTheatre
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_BookYourShow_deleteTheatre
  (JNIEnv *, jobject, jstring);

/*
 * Class:     BookYourShow
 * Method:    deleteMovie
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_BookYourShow_deleteMovie
  (JNIEnv *, jobject, jstring);

/*
 * Class:     BookYourShow
 * Method:    deleteShow
 * Signature: (Ljava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_BookYourShow_deleteShow
  (JNIEnv *, jobject, jstring, jint, jint);

/*
 * Class:     BookYourShow
 * Method:    save
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_BookYourShow_save
  (JNIEnv *, jobject);

/*
 * Class:     BookYourShow
 * Method:    start
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_BookYourShow_start
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
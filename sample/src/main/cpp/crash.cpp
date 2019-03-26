#include <stdio.h>
#include <jni.h>
#include <android/log.h>

#define LOG "Crash_test"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG,__VA_ARGS__)

/**
 * 引起 crash
 */
void Crash() {
    char ch[20] = "hello,world!";
    LOGE("%s",ch);
    int num = 0;
    num = 1 / num;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_dodola_breakpad_MainActivity_crash(JNIEnv *env, jobject obj) {
    Crash();
}
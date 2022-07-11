#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <stdlib.h>

#include <jvmti.h>
#include <jni.h>

using namespace std;

class CIA
{
public:
    CIA();

    void classLoop();

    jclass awaitForClassUntil(const char *, int);

    void startTerminal();

private:
    JavaVM *jvm;
    JNIEnv *env;
};
#include "CIA.h"

CIA::CIA()
{
    CIA::startTerminal();

    jvm = nullptr;
    env = nullptr;

    jsize count;
    if (JNI_GetCreatedJavaVMs(&jvm, 1, &count) != JNI_OK || count == 0)
        return;

    jint res = jvm->GetEnv((void **)&env, JNI_VERSION_1_6);
    if (res == JNI_EDETACHED)
        res = jvm->AttachCurrentThread((void **)&env, nullptr);
    if (res != JNI_OK)
        return;

    system("cls");
    CIA::classLoop();
}

void CIA::classLoop()
{
    while (true)
    {
        string clazz;
        cout << "Try to find class: ";
        cin >> clazz;
        system("cls");
        cout << "Searching for " << clazz << endl;

		const char *charClass = &clazz[0];

        jclass awaitClass = CIA::awaitForClassUntil(charClass, 1000);
        if (awaitClass == nullptr)
        {
            cout << "Failed to find class" << endl;
        }
        else
        {
            cout << "Found class" << endl;
        }
        system("pause");
        system("cls");
    }
}

jclass CIA::awaitForClassUntil(const char *clazz, int maxAttempts)
{
    bool hasFound = 0;
    int currentAttempts = 0;
    jclass _clazz;

    while (!hasFound)
    {
        _clazz = env->FindClass(clazz);
        if (_clazz != nullptr)
        {
            hasFound = true;
            return _clazz;
        }
        currentAttempts++;
        if (currentAttempts == maxAttempts)
            return nullptr;
    }
    return nullptr;
}

void CIA::startTerminal()
{
    AllocConsole();
    SetConsoleCtrlHandler(NULL, true);
    FILE *fIn;
    FILE *fOut;
    freopen_s(&fIn, "conin$", "r", stdin);
    freopen_s(&fOut, "conout$", "w", stdout);
    freopen_s(&fOut, "conout$", "w", stderr);
}
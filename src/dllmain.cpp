#include <Windows.h>
#include <iostream>

#include "CIA/CIA.h"

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)(new CIA()), nullptr, 0, nullptr);
    }
    return true;
}
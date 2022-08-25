// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "Utils.h"
#include "Library.h"

#include <iostream>
#include <thread>

/*
    #################################
    #        EE DLL Template        #
    #################################

    YOU SHOULD NOT CHANGE THIS FILE
    EXCEPT IF YOU KNOW WHAT YOU ARE DOING!

*/

static Library* lib = nullptr;

bool __stdcall Attach()
{
    // Instant create mutex to avoid multiple load if the DLL stop for some reasons during game startup
    HANDLE handleMutex = CreateMutex(NULL, TRUE, (utf8ToUtf16(PROJECT_NAME_STR) + L"_" + std::to_wstring(GetCurrentProcessId())).c_str());
    if (GetLastError() == ERROR_ALREADY_EXISTS)
        return false;

    FILE* f;

#ifdef _DEBUG
    if (!GetConsoleWindow()) // Already Allocated
        AllocConsole();
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONOUT$", "w", stderr); // Not required technically, but required for cURL verbose
#else
    // Delete log after a given size
    LPCWSTR log = (utf8ToUtf16(PROJECT_NAME_STR) + L".log").c_str();
    if (doesFileExist(log) && fileSize(log) > 2 /*Mo*/ * 100 * 100 * 100)
        DeleteFile(log);
    freopen_s(&f, utf16ToUtf8(log).c_str(), "a", stdout);
#endif // DEBUG

    showMessage("Attach!", "DllMain");

    showMessage("Init Library...", "DllMain");

    if (lib) {
        showMessage("Library Already Initialized...", "DllMain");
        return false;
    }

    auto initLamda = [](void* data) -> unsigned int
    {
        try {
            lib = new Library();
        }
        catch (std::exception ex) {
            showMessage(std::string(ex.what()), "DllMain", 1);
            return 0;
        }
        showMessage("Library Initialized!", "DllMain");
        lib->StartLibraryThread();
        return 1;
    };

    showMessage("Starting Thread!", "DllMain");
    HANDLE initThreadHandle = (HANDLE)_beginthreadex(0, 0, initLamda, 0, 0, 0);

    return true;
}

// Be really REALLY fast here, the game don't fk care if it take more than <random time...> it just kill it
bool __stdcall Detach()
{
    showMessage("Detach!", "DllMain");
    if (lib != nullptr) {
        lib->getProject()->onStop();
        delete lib;
        if (GetConsoleWindow())
            FreeConsole();
#ifdef _DEBUG
        // Sleep(5000); // Keep the console open for 5s (if not killed before) to read output if required
#endif
        return true;
    }
    return false;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
        return Attach();
    }
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH: {
        return Detach();
    }
    }
    return TRUE;
}

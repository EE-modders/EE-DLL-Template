#pragma once

#include "Project.h"

#include <string>
#include <iostream>
#include <windef.h>


/*
    #################################
    #        EE DLL Template        #
    #################################

    YOU SHOULD NOT CHANGE THIS FILE
    EXCEPT IF YOU KNOW WHAT YOU ARE DOING!

*/


static const std::string TEMPLATE_VERSION_STR = "1.0.0";
static const unsigned int TEMPLATE_VERSION_MAJOR = 1;
static const unsigned int TEMPLATE_VERSION_MINOR = 0;
static const unsigned int TEMPLATE_VERSION_PATCH = 0;

class Library
{
private:
    Project* _project = nullptr;
    std::wstring _dllPath;

public:
    Library() {
        showMessage("Loading...", "Library");
        showMessage("Based on EE DLL Template " + TEMPLATE_VERSION_STR + "...");

        // Project
        _project = new Project();

        // Dll Name
        TCHAR dllPath[MAX_PATH];
        HMODULE hModule;
        // Passing a static function to recover the DLL Module Handle
        if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
            GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            (LPWSTR)&showMessage, &hModule)) {
            throw std::exception("Unable to get module handle of an internal function");
        }
        else {
            GetModuleFileName(hModule, dllPath, MAX_PATH);
            _dllPath = dllPath;
            showMessage("DLL Path: " + utf16ToUtf8(_dllPath), "Library");
        }
        showMessage("Loaded!", "Library");
    }

    ~Library() {
        showMessage("Unloading...", "Library");
        delete _project;
        showMessage("Unloaded!", "Library");
    }

    void StartLibraryThread()
    {
        showMessage("Enter Thread!", "LibraryThread");
        _project->onStart();

        while (KEEP_ALIVE)
            Sleep(10000);
    }

    Project* getProject() {
        return _project;
    }

    std::wstring getDllPath()
    {
        return _dllPath;
    }
};
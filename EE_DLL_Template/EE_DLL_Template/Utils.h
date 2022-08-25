#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <mutex>
#include <codecvt>

static std::mutex mtx;

static LONGLONG fileSize(const wchar_t* name)
{
    WIN32_FILE_ATTRIBUTE_DATA fad;
    if (!GetFileAttributesEx(name, GetFileExInfoStandard, &fad))
        return -1; // error condition, could call GetLastError to find out more
    LARGE_INTEGER size;
    size.HighPart = fad.nFileSizeHigh;
    size.LowPart = fad.nFileSizeLow;
    return size.QuadPart;
}

static bool doesFileExist(LPCWSTR lpszFilename)
{
    DWORD attr = GetFileAttributes(lpszFilename);
    return ((attr != INVALID_FILE_ATTRIBUTES) && !(attr & FILE_ATTRIBUTE_DIRECTORY));
}

static bool doesFolderExist(LPCWSTR lpszFoldername)
{
    DWORD attr = GetFileAttributes(lpszFoldername);
    return ((attr != INVALID_FILE_ATTRIBUTES) && (attr & FILE_ATTRIBUTE_DIRECTORY));
}

static const std::string currentDateTime(std::string format) {
    time_t now = time(0);
    struct tm tstruct;
    char buf[256];
    localtime_s(&tstruct, &now);
    strftime(buf, sizeof(buf), format.c_str(), &tstruct);
    return buf;
}

static void showMessage(std::string msg, std::string scope = "", bool error = false, bool show_time = true)
{
    std::unique_lock<std::mutex> lck(mtx);
    std::stringstream ss;

    if (show_time)
        ss << "[" << currentDateTime("%H:%M:%S %d/%m/%Y") << "] ";

    if (error)
        ss << "[ERR] ";
    else
        ss << "[INF] ";

    if (!scope.empty())
        ss << "(" << scope << ") ";
    ss << msg;

    if (error) {
        // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        std::cout << ss.str() << std::endl;
        // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else {
        // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        std::cout << ss.str() << std::endl;
        // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}

static std::wstring utf8ToUtf16(const std::string& utf8Str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
    return conv.from_bytes(utf8Str);
}

static std::string utf16ToUtf8(const std::wstring& utf16Str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
    return conv.to_bytes(utf16Str);
}
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <conio.h>

void enableAnsiCodes() {
    DWORD l_mode;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(hStdout, &l_mode);
    SetConsoleMode(hStdout, l_mode | 0x0004 | 0x0008);
}

void disableCloseButton() {
    HWND hwnd = GetConsoleWindow();
    HMENU hmenu = GetSystemMenu(hwnd, FALSE);
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
}

void setWindowName(std::string name) {
    char consoleTitle[256];
    wsprintf(consoleTitle, name.c_str());
    SetConsoleTitle((LPCTSTR)consoleTitle);
}
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

#include "common.h"
#include "config.h"
#include "setup.h"

#define debug false

int main(int argc, char **argv) {
    std::string serverUri = "https://launcher.mojang.com/v1/objects/1b557e7b033b583cd9f66746b7a9ab1ec1673ced/server.jar";
    std::string folder = "Server";
    std::string tmp;
    DWORD l_mode;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(hStdout, &l_mode);
    SetConsoleMode(hStdout, l_mode | 0x0004 | 0x0008);
    debugPrint("\x1B[1;32m[*] Welcome to Basicprogrammer10's Easy Minecraft Deploy! \x1B[35mV0.1.2", 32);
    debugPrint("[*] Just press Enter to use the default option!\n", 34);

    if (argv[1] != nullptr)
        folder = argv[1];
    if (!exists(folder)) {
        setup::simple(folder, serverUri);

        debugPrint("[*] Start Server? [ y / N ] ", 33, "");
        std::getline(std::cin, tmp);
        if (stringToLower(tmp) != "y") {
            std::cout << "\n\x1B[33m";
            system("pause");
            return 0;
        }
    }

    debugPrint("[*] Starting Server", 32);
    std::cout << "\x1B[35m";
    const std::string runCommand = "cd " + folder + " && java -jar server.jar --nogui";
    if (!debug) system(runCommand.c_str());

    std::cout << "\x1B[33m";
    system("pause");
    std::cout << "\033[0m";
    return 0;
}

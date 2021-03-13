#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

#include "common.h"
#include "config.h"

#define debug true

int main(int argc, char **argv) {
    std::string serverUri = "https://launcher.mojang.com/v1/objects/1b557e7b033b583cd9f66746b7a9ab1ec1673ced/server.jar";
    std::string folder = "Server";
    std::string advancedConfig;
    DWORD l_mode;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(hStdout, &l_mode);
    SetConsoleMode(hStdout, l_mode | 0x0004 | 0x0008);

    debugPrint("\x1B[1;32m[*] Welcome to Basicprogrammer10's Easy Minecraft Deploy!\n", 32);

    if (!exists("Server")) {
        debugPrint("[*] Creating folder \x1B[34m" + folder, 36);
        makeDir(folder.c_str());
        debugPrint("[*] Folder Created", 32);
        debugPrint("[*] Starting Download of Server.jar", 36);
        const std::string command = "curl " + serverUri + " -o " + folder + "/server.jar >nul 2>&1";
        int status = system(command.c_str());
        if (status != 0)
            errorPrint("[*] Error Downloading \x1B[34mServer.jar", 31, -1);

        debugPrint("[*] Download Complete", 32);
        debugPrint("[*] Accepting EULA", 36);
        saveFile(folder + "/eula.txt",
                 "#Genarated with https://github.com/Basicprogrammer10/EasyMinecraftDeploy\neula=TRUE");
        debugPrint("[*] Complete\n", 32);

        debugPrint("[*] Enter Advanced Config Mode? [ y / N ] ", 33, "");
        std::getline(std::cin, advancedConfig);
        std::cout << std::endl;
        if (stringToLower(advancedConfig) == "y") {
            std::string fullConfig = configSet::all();
            if (saveFile(folder + "/server.properties", fullConfig))
                errorPrint("[*] Error Saving Config file :/", 31, -1);
        }

        std::cout << "\n\x1B[33m";
        system("pause");
        return 0;
    }

    debugPrint("[*] Starting Server", 32);
    std::cout << "\x1B[35m";
    const std::string runCommand = "cd " + folder + " && java -jar server.jar --nogui";
    if (!debug) system(runCommand.c_str());

    std::cout << "\x1B[33m";
    system("pause");

    return 0;
}

#include <iostream>
#include <string>
#include <sstream>

#include "console.hpp"
#include "common.hpp"
#include "config.hpp"
#include "setup.hpp"

int main(int argc, char **argv) {
    std::string serverUri = "https://launchermeta.mojang.com/mc/game/version_manifest.json";
    std::string folder = "Server";
    std::string tmp, jarVersion;

    enableAnsiCodes();
    disableCloseButton();
    setWindowName("Easy Minecraft Deploy");

    debugPrint("\x1B[1;32m[*] Welcome to Basicprogrammer10's Easy Minecraft Deploy! \x1B[35mV0.2.1", 32);
    debugPrint("[*] Just press Enter to use the default option!\n", 34);

    if (argv[1] != nullptr)
        folder = argv[1];
    if (!exists(folder)) {
        std::string newVersionString = getNewVersionAsString(serverUri);
        debugPrint("[*] Server Version [ " + newVersionString + " ] ", 33, "");
        std::getline(std::cin, tmp);
        if (stringToLower(tmp) != newVersionString) {
            newVersionString = stringToLower(tmp);
        }

        std::string serverJar = setup::getServerJar(serverUri, newVersionString);
        setup::simple(folder, serverJar);

        debugPrint("[*] Start Server? [ y / N ] ", 33, "");
        std::getline(std::cin, tmp);
        if (stringToLower(tmp) != "y") {
            std::cout << "\n\x1B[33m";
            waitForKeypress("\n\nPress any key to Exit...", 33);
            return 0;
        }
    }

    debugPrint("[*] Starting Server", 32);
    std::cout << "\x1B[35m";
    const std::string runCommand = "cd " + folder + " && java -jar server.jar --nogui 2> nul";
    int result = system(runCommand.c_str());
    if (result != 0) std::cout << std::endl;
    if (result == 1) errorPrint("[*] Java not found :/ Make sure Java is installed", 31, -1);

    waitForKeypress("\n\nPress any key to Exit...", 33);
    return 0;
}

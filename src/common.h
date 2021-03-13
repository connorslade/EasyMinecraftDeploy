#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <sstream>
#include <windows.h>
#include <algorithm>

void debugPrint(std::string text, int colorcode, std::string stringEnd = "\n") {
    std::cout << "\x1B[" << colorcode << "m" << text << "\033[0m" << stringEnd;
}

void errorPrint(std::string text, int colorcode, int exitCode){
    debugPrint(text, colorcode);
    exit(exitCode);
}

bool saveFile(std::string filePath, std::string content) {
    std::fstream file;
    file.open(filePath, std::ios::out);
    if (!file) {
        return false;
    }
    file << content;
    file.close();
    return true;
}

bool makeDir(const char *filePath) {
    int check;
    check = mkdir(filePath);
    if (check)
        return false;
    return true;
}

inline bool exists(const std::string &name) {
    struct stat buffer{};
    return (stat(name.c_str(), &buffer) == 0);
}

std::string stringToLower(std::string data){
    std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
    return data;
}

std::string getConfig(std::string configOption, std::string defult, std::string defultPrint) {
    std::string config;
    debugPrint("\033[F\033[2K    [*] " + configOption + " " + defultPrint + " ", 33, "");
    std::getline(std::cin, config);
    if (config.empty())
        return configOption + "=" + defult + "\n";
    return configOption + "=" + config + "\n";
}
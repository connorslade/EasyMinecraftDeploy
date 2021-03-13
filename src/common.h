#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <sstream>
#include <windows.h>
#include <algorithm>
#include <array>
#include <memory>
#include <vector>

void debugPrint(std::string text, int colorcode, std::string stringEnd = "\n") {
    std::cout << "\x1B[" << colorcode << "m" << text << "\033[0m" << stringEnd;
}

void errorPrint(std::string text, int colorcode, int exitCode){
    debugPrint(text, colorcode);
    std::cout << "\x1B[33m";
    system("pause");
    std::cout << "\033[0m";
    exit(exitCode);
}

void tokenize(std::string const &str, const char delim,
              std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

auto read_file(std::string path) -> std::string {
    constexpr auto read_size = std::size_t{4096};
    auto stream = std::ifstream{path.data()};
    stream.exceptions(std::ios_base::badbit);

    auto out = std::string{};
    auto buf = std::string(read_size, '\0');
    while (stream.read(& buf[0], read_size)) {
        out.append(buf, 0, stream.gcount());
    }
    out.append(buf, 0, stream.gcount());
    return out;
}

std::string getNewVersion(std::string baseUri, std::string name){
    std::string fileName = ".easyMinecraftDeploy.tmp";
    std::string command = "curl " + baseUri + " -f -A EasyMinecraftDeploy -o " + fileName + " >nul 2>&1";
    int status = system(command.c_str());
    if (status != 0)
        errorPrint("[*] Error Downloading \x1B[34m" + name, 31, -1);
    std::string manifest = read_file(fileName);
    remove(fileName.c_str());
    return manifest;
}

std::string getNewVersionAsString(std::string serverUri){
    std::string s = getNewVersion(serverUri, "Version Manifest");
    std::vector<std::string> out;
    tokenize(s, '"', out);
    return out[5];
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
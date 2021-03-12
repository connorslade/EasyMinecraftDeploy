#include <iostream>
#include<string>
#include <fstream>
#include <sys/stat.h>
#include <sstream>
#include <windows.h>

void debugPrint(std::string text, int colorcode) {
    std::cout << "\x1B[" << colorcode << "m" << text << "\033[0m" << std::endl;
}

bool saveFile(std::string filePath, std::string content){
    std::fstream file;
    file.open(filePath, std::ios::out);
    if (!file) {
        return false;
    }
    file << content;
    file.close();
    return true;
}

bool makeDir(const char *filePath){
    int check;
    check = mkdir(filePath);
    if (check)
        return false;
    return true;
}

inline bool exists (const std::string& name) {
    struct stat buffer{};
    return (stat (name.c_str(), &buffer) == 0);
}

int main(){
    DWORD l_mode;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(hStdout,&l_mode);
    SetConsoleMode( hStdout, l_mode | 0x0004 | 0x0008 );

    if (!exists("Server")) {
        debugPrint("[*] Creating folder \x1B[34mServer", 31);
        makeDir("Server");
        debugPrint("[*] Folder Created", 32);
        debugPrint("[*] Starting Download of Server.jar", 36);
        int status = system("curl https://launcher.mojang.com/v1/objects/1b557e7b033b583cd9f66746b7a9ab1ec1673ced/server.jar -o Server/server.jar >nul 2>&1");
        if (status != 0){
            debugPrint("[*] Error Downloading \x1B[34mServer.jar", 31);
            return -1;
        }
        debugPrint("[*] Download Complete", 32);
        debugPrint("[*] Accepting ELUA", 36);
        saveFile("Server/eula.txt", "eula=TRUE");
        debugPrint("[*] Complete", 32);
        return 0;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

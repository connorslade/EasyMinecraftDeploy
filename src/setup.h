namespace setup{
    void simple(std::string folder, std::string serverUri){
        std::string advancedConfig, tmp;
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
        if (stringToLower(advancedConfig) == "y") {
            std::string fullConfig = configSet::all();
            if (saveFile(folder + "/server.properties", fullConfig))
                errorPrint("[*] Error Saving Config file :/", 31, -1);
        }
    }
}
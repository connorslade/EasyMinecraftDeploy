namespace setup{
    std::string getServerJar(std::string serverUri, std::string versionName = ""){
        std::string serverJar, versionMeta;
        std::string version = versionName;
        std::vector<std::string> out;
        std::string s = getNewVersion(serverUri, "Version Manifest");

        tokenize(s, '"', out);
        if (versionName == "")
            version = out[5];

        for(std::size_t i = 6, e = out.size(); i != e; ++i){
            if (out[i] != version)
                continue;
            versionMeta = out[i + 8];
            break;
        }

        s =  getNewVersion(versionMeta, "Version Meta");
        tokenize(s, '"', out);

        for(std::size_t i = 6, e = out.size(); i != e; ++i){
            if (out[i] != "server")
                continue;
            serverJar = out[i + 10];
            break;
        }

        return serverJar;
    }

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
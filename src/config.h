#include <iostream>
#include <string>

namespace configSet {
    std::string getConfig(std::string configOption, std::string defult, std::string defultPrint) {
        std::string config;
        debugPrint("\033[F\033[2K    [*] " + configOption + " " + defultPrint + " ", 33, "");
        std::getline(std::cin, config);
        if (config.empty())
            return configOption + "=" + defult + "\n";
        return configOption + "=" + config + "\n";
    }

    std::string all() {
        std::string fullConfig = "#Genarated with https://github.com/Basicprogrammer10/EasyMinecraftDeploy\n";
        fullConfig += getConfig("enable-jmx-monitoring", "false", "[ true / FALSE ]");
        fullConfig += getConfig("rcon.port", "25575", "[ 25575 ]");
        fullConfig += getConfig("level-seed", "", "[  ]");
        fullConfig += getConfig("gamemode", "survival", "[ survival ]");
        fullConfig += getConfig("enable-command-block", "false", "[ true / FALSE ]");
        fullConfig += getConfig("enable-query", "false", "[ true / FALSE ]");
        fullConfig += getConfig("generator-settings", "", "[  ]");
        fullConfig += getConfig("level-name", "world", "[ world ]");
        fullConfig += getConfig("motd", "A Minecraft Server", "[ A Minecraft Server ]");
        fullConfig += getConfig("query.port", "25565", "[ 25565 ]");
        fullConfig += getConfig("pvp", "true", "[ TRUE / false ]");
        fullConfig += getConfig("generate-structures", "true", "[ TRUE / false ]");
        fullConfig += getConfig("difficulty", "easy", "[ easy ]");
        fullConfig += getConfig("network-compression-threshold", "256", "[ 256 ]");
        fullConfig += getConfig("max-tick-time", "60000", "[ 60000 ]");
        fullConfig += getConfig("use-native-transport", "true", "[ TRUE / false ]");
        fullConfig += getConfig("max-players", "20", "[ 20 ]");
        fullConfig += getConfig("online-mode", "true", "[ TRUE / false ]");
        fullConfig += getConfig("enable-status", "true", "[ TRUE / false ]");
        fullConfig += getConfig("allow-flight", "false", "[ true / FALSE ]");
        fullConfig += getConfig("broadcast-rcon-to-ops", "true", "[ TRUE / false ]");
        fullConfig += getConfig("view-distance", "10", "[ 10 ]");
        fullConfig += getConfig("max-build-height", "256", "[ 256 ]");
        fullConfig += getConfig("server-ip", "", "[  ]");
        fullConfig += getConfig("allow-nether", "true", "[ TRUE / false ]");
        fullConfig += getConfig("server-port", "25565", "[ 25565 ]");
        fullConfig += getConfig("enable-rcon", "false", "[ true / FALSE ]");
        fullConfig += getConfig("sync-chunk-writes", "true", "[ TRUE / false ]");
        fullConfig += getConfig("op-permission-level", "4", "[ 4 ]");
        fullConfig += getConfig("prevent-proxy-connections", "false", "[ true / FALSE ]");
        fullConfig += getConfig("resource-pack", "", "[  ]");
        fullConfig += getConfig("entity-broadcast-range-percentage", "100", "[ 100 ]");
        fullConfig += getConfig("rcon.password", "", "[  ]");
        fullConfig += getConfig("player-idle-timeout", "0", "[ 0 ]");
        fullConfig += getConfig("force-gamemode", "false", "[ true / FALSE ]");
        fullConfig += getConfig("rate-limit", "0", "[ 0 ]");
        fullConfig += getConfig("hardcore", "false", "[ true / FALSE ]");
        fullConfig += getConfig("white-list", "false", "[ true / FALSE ]");
        fullConfig += getConfig("broadcast-console-to-ops", "true", "[ TRUE / false ]");
        fullConfig += getConfig("spawn-npcs", "true", "[ TRUE / false ]");
        fullConfig += getConfig("spawn-animals", "true", "[ TRUE / false ]");
        fullConfig += getConfig("snooper-enabled", "true", "[ TRUE / false ]");
        fullConfig += getConfig("function-permission-level", "2", "[ 2 ]");
        fullConfig += getConfig("level-type", "default", "[ default ]");
        fullConfig += getConfig("text-filtering-config", "", "[  ]");
        fullConfig += getConfig("spawn-monsters", "true", "[ TRUE / false ]");
        fullConfig += getConfig("enforce-whitelist", "false", "[ true / FALSE ]");
        fullConfig += getConfig("resource-pack-sha1", "", "[  ]");
        fullConfig += getConfig("spawn-protection", "16", "[ 16 ]");
        fullConfig += getConfig("max-world-size", "29999984", "[ 29999984 ]");
        return fullConfig;
    }
}
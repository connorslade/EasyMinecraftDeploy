cmake_minimum_required(VERSION 3.17)
project(EasyMinecraftDeploy)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        EasyMinecraftDeploy
        src/main.cpp
        src/config.hpp
        src/common.hpp
        src/setup.hpp
        res/res.rc
        src/common.cpp src/config.cpp src/setup.cpp src/console.cpp src/console.hpp)

target_link_libraries(EasyMinecraftDeploy -static)
cmake_minimum_required(VERSION 3.17)
project(EasyMinecraftDeploy)

set(CMAKE_CXX_STANDARD 14)

add_executable(EasyMinecraftDeploy src/main.cpp src/config.h src/common.h)

target_link_libraries(EasyMinecraftDeploy -static)
#target_include_directories(EasyMinecraftDeploy PRIVATE include)
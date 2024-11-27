cmake_minimum_required(VERSION 3.0)


#project name and version
project(TopDownGame VERSION 1.0)


#set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


#include Raylib
find_package(raylib REQUIRED)


#add source file
set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Enemy.cpp
    src/Bullet.cpp
)

#include directories
include_directories(include)


#add executable
add_executable(TopDownGame ${SOURCES})


#link Raylib
target_link_libraries(TopDownGame raylib)

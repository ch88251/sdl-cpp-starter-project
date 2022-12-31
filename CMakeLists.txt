cmake_minimum_required(VERSION 3.22)
project(sdl_cpp_starter)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include)
include_directories(src/main/cpp)
include_directories(src/main/headers)

add_executable(sdl_cpp_starter
        src/main/cpp/Game.cpp
        src/main/cpp/Game.h
        src/main/cpp/Main.cpp
        src/main/headers/app.h)

target_link_directories(sdl_cpp_starter PRIVATE lib)
target_link_libraries(sdl_cpp_starter PRIVATE SDL2 SDL2main)

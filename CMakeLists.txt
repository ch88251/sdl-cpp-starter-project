cmake_minimum_required(VERSION 3.22)
project(archery)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include)
include_directories(src/main/cpp)
include_directories(src/main/headers)

add_executable(archery
        src/main/cpp/Game.cpp
        src/main/cpp/Main.cpp
        src/main/headers/Game.h)

target_link_directories(archery PRIVATE /usr/local/lib)
target_link_libraries(archery PRIVATE SDL2 SDL2main)

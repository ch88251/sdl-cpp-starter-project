cmake_minimum_required(VERSION 3.22)
project(sample)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include)
include_directories(src/main/cpp)
include_directories(src/main/headers)

add_executable(sample
        src/main/cpp/Game.cpp
        src/main/cpp/Main.cpp
        src/main/headers/Game.h)

target_link_directories(sample PRIVATE /usr/local/lib)
target_link_libraries(sample PRIVATE SDL2 SDL2main)

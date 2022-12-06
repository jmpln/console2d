cmake_minimum_required(VERSION 3.18)

project(figure-draw)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W --std=c++11")

set(SOURCE_FILES main.cpp
                 display.cpp
                 point2d.cpp)

add_executable(figure-draw ${SOURCE_FILES})

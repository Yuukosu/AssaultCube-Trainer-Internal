cmake_minimum_required(VERSION 3.22)
project(AssaultInternal)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} SHARED dllmain.cpp Memory.cpp Memory.h)

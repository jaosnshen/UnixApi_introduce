cmake_minimum_required(VERSION 3.13)
project(UnixApi)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/apue.h)

add_executable(UnixApi main.cpp FIleSystem/FileDemo.cpp FIleSystem/FileDemo.h Process/ProcessDemo.cpp Process/ProcessDemo.h)
cmake_minimum_required(VERSION 3.3)
project(UGMS)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(SOURCE_FILES main.c)
add_executable(UGMS ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.3)
set(PROJECT_VERSION 0.1)
project(UGMS)

#--- Compiler options
if(CMAKE_COMPILER_IS_GNUCC)
    add_definitions(-Wall -Werror -pedantic -std=c99)
endif(CMAKE_COMPILER_IS_GNUCC)

set(SOURCE_FILES main.c dlink.c dlink.h)
add_executable(UGMS ${SOURCE_FILES})
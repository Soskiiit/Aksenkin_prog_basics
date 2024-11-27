cmake_minimum_required(VERSION 3.29.6)

SET(CMAKE_CXX_STANDARD 20)

project(prog_basics)

SET(PROJECT_SOURCES
        src/main.cpp
        src/mprinter.cpp
)

SET(PROJECT_HEADERS
        include/mprinter.h
)

add_executable(prog_basics
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

target_include_directories(prog_basics PRIVATE include)

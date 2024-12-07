cmake_minimum_required(VERSION 3.29)

project(prog_basics)

set(CMAKE_CXX_STANDARD )

set(PROJECT_SOURCES
        src/main.cpp
        src/dictionary.cpp
)

set(PROJECT_HEADERS
        include/dictionary.h
        include/utils.h
)

add_executable(prog_basics
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

target_include_directories(prog_basics PRIVATE include)

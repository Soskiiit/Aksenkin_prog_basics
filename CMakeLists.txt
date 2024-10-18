cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)

project(prog_basics)

SET(PROJECT_SOURCES
        src/main.cpp
        src/calculations.cpp
        src/methods.cpp
)

SET(PROJECT_HEADERS
        include/calculations.h
        include/methods.h
)

add_executable(prog_basics
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

target_include_directories(prog_basics PRIVATE include)

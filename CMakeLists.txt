cmake_minimum_required(VERSION 3.29.6)
set(CMAKE_CXX_STANDARD 20)

project(prog_basics)


set(PROJECT_SOURCES
        src/main.cpp
        src/sorts.cpp
        src/utils.cpp
        src/benchmark.cpp
)

set(PROJECT_HEADERS
        include/sorts.h
        include/utils.h
        include/benchmark.h

)

add_executable(prog_basics
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

target_include_directories(prog_basics PRIVATE include)

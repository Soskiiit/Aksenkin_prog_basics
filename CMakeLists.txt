cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)

project(prog_basics)

SET(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/calculations.cpp
)

SET(PROJECT_HEADERS )

add_executable(prog_basics
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

target_include_directories(prog_basics PRIVATE include)

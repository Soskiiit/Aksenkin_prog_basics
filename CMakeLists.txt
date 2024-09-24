cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)

project(prog_basics)

SET(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/task1.cpp
        ${PROJECT_SOURCE_DIR}/src/task2.cpp
        ${PROJECT_SOURCE_DIR}/src/task3.cpp
        ${PROJECT_SOURCE_DIR}/src/task4.cpp
)

SET(PROJECT_HEADERS
        ${PROJECT_SOURCE_DIR}/include/main.h
)

add_executable(prog_basics
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

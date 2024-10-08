cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)

project(prog_basics)

set(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/src/task1.cpp
        ${PROJECT_SOURCE_DIR}/src/task2.cpp
        ${PROJECT_SOURCE_DIR}/src/task3.cpp
        ${PROJECT_SOURCE_DIR}/src/task4.cpp
        ${PROJECT_SOURCE_DIR}/src/main.cpp
)

set(PROJECT_HEADERS
        include/task2.h
        include/task3.h
        include/task4.h
        include/task1.h
)

add_executable(prog_basics
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)

target_include_directories(prog_basics PRIVATE include)

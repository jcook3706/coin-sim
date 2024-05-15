cmake_minimum_required(VERSION 3.0)
project(cpp_test)

# Include directories for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Source files
set(SOURCE_FILES main.c)

# Add executable
add_executable(program ${SOURCE_FILES})

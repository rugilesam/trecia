cmake_minimum_required(VERSION 3.24.3)
set(CMAKE_CXX_STANDARD 11)
project(trecia.v3.0)

# Include directories
include_directories(include)

# Add your source files
file(GLOB SOURCES "src/*.cpp")

# Create an executable
add_executable(trecia.v3.0 ${SOURCES})
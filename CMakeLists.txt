cmake_minimum_required(VERSION 3.20)
project(raytracing CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Create executable (main.cpp is in project root)
add_executable(raytracing main.cpp)
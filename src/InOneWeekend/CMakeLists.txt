cmake_minimum_required(VERSION 3.20)
project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # generates compile_commands.json for clangd/LSP

# Default to Release if not specified — raytracing is CPU-heavy and
# unoptimized debug builds will be painfully slow
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(raytracer src/main.cpp)

# Reasonable warning flags — catches real bugs without being obnoxious
target_compile_options(raytracer PRIVATE
    -Wall -Wextra -Wpedantic
)

# Optional: extra optimization for Release builds specifically
target_compile_options(raytracer PRIVATE
    $<$<CONFIG:Release>:-O3>
)

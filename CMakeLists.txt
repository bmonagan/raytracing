cmake_minimum_required(VERSION 3.15)

project(raytracing VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# sources: main.cpp in project root plus any .cpp under src/
file(GLOB_RECURSE PROJECT_SRC CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

add_executable(raytracing ${PROJECT_SRC})

target_include_directories(raytracing PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
)

# link Threads on platforms that need it
find_package(Threads QUIET)
if(Threads_FOUND)
    target_link_libraries(raytracing PRIVATE Threads::Threads)
endif()

# Recommended: enable useful warnings
if(MSVC)
    target_compile_options(raytracing PRIVATE /W4 /permissive-)
else()
    target_compile_options(raytracing PRIVATE -Wall -Wextra -Wpedantic -Wconversion)
endif()
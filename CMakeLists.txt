cmake_minimum_required(VERSION 3.21)
project(curl_playground)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    include(conanfiles/release/conanbuildinfo.cmake)
else()
    include(conanfiles/debug/conanbuildinfo.cmake)
endif()

conan_basic_setup()

add_subdirectory(src)
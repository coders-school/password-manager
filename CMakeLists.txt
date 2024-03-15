cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER g++-13)

project(PasswordManager)

set(FLAGS -Wall -Werror -Wpedantic -Wextra)

set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(HEADERS_DIR ${PROJECT_SOURCE_DIR}/headers)

enable_testing()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Release/)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Release/)
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Debug/)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Debug/)
endif()

include_directories(headers)
add_subdirectory(source)
add_subdirectory(lib)

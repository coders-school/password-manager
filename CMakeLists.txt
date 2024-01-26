cmake_minimum_required(VERSION 3.22.1)

project(password-manager)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/build)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/build/include)
set(BIN_DIR ${PROJECT_SOURCE_DIR}/build/bin)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/build/lib)

add_subdirectory(src)
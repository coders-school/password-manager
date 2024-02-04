cmake_minimum_required(VERSION 3.14)

# # Basic Files
file(GLOB project_src
    "symCrypt/*.cpp"
)

project(encrpyt)

option(ENCRPYT_CPP_BUILD_STANDALONE "Set if you wish to fetch all dependencies and build standalone unit tests." OFF)
option(USE_SYSTEM_OPENSSL "Use the system's OpenSSL if available" OFF)

include(FindPackageHandleStandardArgs)
find_package(OpenSSL QUIET)
if(NOT OpenSSL_FOUND)
    if(USE_SYSTEM_OPENSSL)
        message(FATAL_ERROR "System OpenSSL not found. Set USE_SYSTEM_OPENSSL to OFF or install OpenSSL.")
    else()
        set(OPENSSL_SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/openssl-src) # default path by CMake
        set(OPENSSL_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/openssl)
        set(OPENSSL_INCLUDE_DIR ${OPENSSL_INSTALL_DIR}/include)
        set(OPENSSL_CONFIGURE_COMMAND ${OPENSSL_SOURCE_DIR}/config)
        include(ExternalProject)
        ExternalProject_Add(
            OpenSSL
            SOURCE_DIR ${OPENSSL_SOURCE_DIR}
            GIT_REPOSITORY https://github.com/openssl/openssl.git
            GIT_TAG openssl-3.2.1
            USES_TERMINAL_DOWNLOAD TRUE
            CONFIGURE_COMMAND
            ${OPENSSL_CONFIGURE_COMMAND}
            --prefix=${OPENSSL_INSTALL_DIR}
            --openssldir=${OPENSSL_INSTALL_DIR}
            BUILD_COMMAND make
            TEST_COMMAND ""
            INSTALL_COMMAND make install
            INSTALL_DIR ${OPENSSL_INSTALL_DIR}
        )

        file(MAKE_DIRECTORY ${OPENSSL_INCLUDE_DIR})

        add_library(OpenSSL::SSL STATIC IMPORTED GLOBAL)
        set_property(TARGET OpenSSL::SSL PROPERTY IMPORTED_LOCATION ${OPENSSL_INSTALL_DIR}/lib/libssl.${OPENSSL_LIBRARY_SUFFIX})
        set_property(TARGET OpenSSL::SSL PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${OPENSSL_INCLUDE_DIR})
        add_dependencies(OpenSSL::SSL OpenSSL)

        add_library(OpenSSL::Crypto STATIC IMPORTED GLOBAL)
        set_property(TARGET OpenSSL::Crypto PROPERTY IMPORTED_LOCATION ${OPENSSL_INSTALL_DIR}/lib/libcrypto.${OPENSSL_LIBRARY_SUFFIX})
        set_property(TARGET OpenSSL::Crypto PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${OPENSSL_INCLUDE_DIR})
        add_dependencies(OpenSSL::Crypto OpenSSL)
    endif()
endif()

add_library(encrpyt ${project_src})
target_link_libraries(encrpyt PUBLIC OpenSSL::SSL OpenSSL::Crypto)
target_include_directories(encrpyt PUBLIC "../")
target_compile_options(encrpyt PRIVATE -Wall -Wextra -Wpedantic -Werror)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND(BUILD_TESTING))
    enable_testing()
    add_subdirectory(uTests)
endif()

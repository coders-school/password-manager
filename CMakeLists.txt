cmake_minimum_required(VERSION 3.22.1)

project(password-manager)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/build)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/build/include)
set(BIN_DIR ${PROJECT_SOURCE_DIR}/build/bin)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/build/lib)

add_subdirectory(src)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


add_executable(${PROJECT_NAME}-ut src/test.cpp)
target_link_libraries(${PROJECT_NAME}-ut gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)
install(TARGETS ${PROJECT_NAME}-ut DESTINATION ${BIN_DIR})
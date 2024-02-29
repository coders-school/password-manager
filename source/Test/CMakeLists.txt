include(FetchContent)

set(TEST_NAME ${PROJECT_NAME}-UT)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)

add_executable(${TEST_NAME} test.cpp)
target_link_libraries(${TEST_NAME} gtest_main)
set_target_properties(${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Test")

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})

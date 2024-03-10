include(FetchContent)

set(TEST_NAME ${PROJECT_NAME}-UT)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE test_src
    "*.cpp"
)

add_executable(${TEST_NAME} ${test_src})
target_link_libraries(${TEST_NAME} gtest_main ${PROJECT_NAME})
set_target_properties(${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test")

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})

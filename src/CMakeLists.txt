add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -std=c++20 -O3 -Wall -Wextra -Wpedantic -Werror)

install(TARGETS ${PROJECT_NAME} DESTINATION ${BIN_DIR})
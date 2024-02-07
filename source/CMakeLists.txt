project(PasswordManager)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(passwordManager main.cpp PasswordManager.cpp)
add_subdirectory(test)

target_link_libraries(passwordManager ${OPENSSL_LIBRARIES})

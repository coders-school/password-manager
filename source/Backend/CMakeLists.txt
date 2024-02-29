project(PasswordManager)

add_library(sqlite3 STATIC ${LIB_DIR}/sqlite3.c)
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(passwordManager
    main.cpp
    PasswordManager.cpp
    Common/Logger.cpp)

target_include_directories(sqlite3 PUBLIC ${LIB_DIR})
target_link_libraries(passwordManager PRIVATE sqlite3 ${OPENSSL_LIBRARIES})

add_subdirectory(DataBase)

target_include_directories(passwordManager PRIVATE ${HEADERS_DIR})

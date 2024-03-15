project(PasswordManager)

set(SQLITE_DIR ${LIB_DIR}/sqlite)

find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED)

add_executable(passwordManager
    main.cpp
    PasswordManager.cpp
    Common/Logger.cpp)

target_link_libraries(passwordManager PRIVATE SQLite3 ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})

add_subdirectory(DataBase)

target_include_directories(passwordManager PRIVATE
    ${SQLITE_DIR}
    ${HEADERS_DIR}
    ${Boost_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR})

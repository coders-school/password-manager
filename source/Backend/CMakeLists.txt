project(PasswordManager)

add_library(sqlite3 STATIC ${LIB_DIR}/sqlite3.c)

find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED)

add_executable(passwordManager
    main.cpp
    PasswordManager.cpp
    Common/Logger.cpp)

target_include_directories(sqlite3 PUBLIC ${LIB_DIR})
target_link_libraries(passwordManager PRIVATE sqlite3 ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})

add_subdirectory(DataBase)

target_include_directories(passwordManager PRIVATE
    ${HEADERS_DIR}
    ${Boost_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR})

project(PasswordManager)

add_library(sqlite3 STATIC ../lib/sqlite3.c)
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(passwordManager
    main.cpp
    PasswordManager.cpp
    Common/Logger.cpp)

target_include_directories(sqlite3 PUBLIC ../lib)
target_link_libraries(passwordManager PRIVATE sqlite3 ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})

add_subdirectory(test)
add_subdirectory(DataBase)

target_include_directories(passwordManager PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)

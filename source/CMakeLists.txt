project(PasswordManager)

add_library(sqlite3 STATIC ../lib/sqlite3.c)

find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED)

add_executable(passwordManager
    main.cpp
    PasswordManager.cpp
    Common/Logger.cpp)

target_include_directories(sqlite3 PUBLIC ../lib)
target_link_libraries(passwordManager PRIVATE sqlite3 ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})

add_subdirectory(test)
add_subdirectory(DataBase)
add_subdirectory(Frontend)

target_include_directories(passwordManager PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
    ${Boost_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR})

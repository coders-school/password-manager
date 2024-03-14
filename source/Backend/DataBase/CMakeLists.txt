project(PasswordManager)

target_include_directories(passwordManager PRIVATE DataBase/interface)
target_include_directories(passwordManager PRIVATE DataBase/common)

target_sources(passwordManager PRIVATE
   DataBaseConnection.cpp DataBaseManager.cpp QueryOperationBuilder.cpp)

#include <string>

#include "DataBase/DataBaseHandler.hpp"
#include "DataBase/common/DataBaseCommon.hpp"
#include "PasswordManager.h"

int main() {
  std::string password = "haslo";
  PasswordManager passwordManager(password);
  const std::vector<std::string> passwordValues{"1",    "test", "test", "test",
                                                "test", "test", "test"};
  try {
    dataBase::DataBaseHandler dataBaseHandler(dataBase::common::dataBasePath);
    dataBaseHandler.insertData(dataBase::common::passwords,
                               dataBase::common::passwordRecords,
                               passwordValues);
    std::cout << "dataBase is working" << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Error occured" << std::endl;
    std::cerr << "Error: " << e.what() << std::endl;
  }

    return 0;
}

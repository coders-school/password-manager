#include <map>
#include <string>

#include "DataBase/DataBaseConnection.hpp"
#include "DataBase/DataBaseManager.hpp"
#include "DataBase/QueryOperationBuilder.hpp"
#include "DataBase/common/DataBaseCommon.hpp"
#include "DataBase/common/DataBaseRequest.hpp"
#include "PasswordManager.h"

int main() {
  std::string password = "haslo";
  PasswordManager passwordManager(password);
  return 0;
}

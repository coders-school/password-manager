
#include "DataBaseCommon.hpp"

const std::vector<std::string> DataBaseCommon::PasswordRecords{"User_Id", "Category", "Username", "Password", "Url", "Expire_Time"};
const std::vector<std::string> DataBaseCommon::UserRecord{"Username", "Password"};

const std::string DataBaseCommon::dataBasePath{"../../../source/DataBase/password-manager.db"};
const std::string DataBaseCommon::Users{"Users"};
const std::string DataBaseCommon::Passwords{"Passwords"};
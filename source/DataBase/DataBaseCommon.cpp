
#include "DataBaseCommon.hpp"

const std::vector<std::string> DataBaseCommon::passwordRecords{
    "User_Id", "Title", "Category", "Username", "Password", "Note", "Url", "Creation_Time", "Modify_Time", "Expiry_Time"};
const std::vector<std::string> DataBaseCommon::userRecords{"Username", "Password"};

const std::string DataBaseCommon::dataBasePath{"../../../source/DataBase/password-manager.db"};
const std::string DataBaseCommon::users{"Users"};
const std::string DataBaseCommon::passwords{"Passwords"};

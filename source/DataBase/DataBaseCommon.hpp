#pragma once

#include <vector>
#include <string>
struct DataBaseCommon
{
    static const std::vector<std::string> userRecordsRecords;
    static const std::vector<std::string> categoriesRecords;
    static const std::vector<std::string> passwordHistoryRecords;
    static const std::vector<std::string> passwordRecords;

    static const std::string dataBasePath;

    static const std::string users;
    static const std::string passwords;
    static const std::string passwordHistory;
    static const std::string categories;
};

const std::vector<std::string> DataBaseCommon::userRecordsRecords{"Username", "Password"};
const std::vector<std::string> DataBaseCommon::categoriesRecords{"Category"};
const std::vector<std::string> DataBaseCommon::passwordHistoryRecords{"Creation_Time", "Modify_Time", "Expiry_Time"};
const std::vector<std::string> DataBaseCommon::passwordRecords{
    "User_Id", "Category_Id", "Title", "Username", "Password", "Note", "Url"};

const std::string DataBaseCommon::dataBasePath{"../../../source/dataBase/password-manager.db"};

const std::string DataBaseCommon::users{"Users"};
const std::string DataBaseCommon::passwords{"Passwords"};
const std::string DataBaseCommon::passwordHistory{"PasswordHistory"};
const std::string DataBaseCommon::categories{"Categories"};
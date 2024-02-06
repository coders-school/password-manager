#pragma once

#include <vector>
#include <string>
struct DataBaseCommon
{
    static constexpr std::vector<std::string> userRecordsRecords{"Username", "Password"};
    static constexpr std::vector<std::string> categoriesRecords{"Category"};
    static constexpr std::vector<std::string> passwordHistoryRecords{"Creation_Time", "Modify_Time", "Expiry_Time"};
    static constexpr std::vector<std::string> passwordRecords{
        "User_Id", "Category_Id", "Title", "Username", "Password", "Note", "Url"};

    static constexpr std::string dataBasePath{"../../../source/dataBase/password-manager.db"};

    static constexpr std::string users{"Users"};
    static constexpr std::string passwords{"Passwords"};
    static constexpr std::string passwordHistory{"PasswordHistory"};
    static constexpr std::string categories{"Categories"};
};

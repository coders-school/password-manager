#pragma once

#include <vector>
#include <string>

namespace dataBase::common
{

    static constexpr char dataBasePath[] = "../../../source/dataBase/password-manager.db";
    static constexpr char users[] = "Users";
    static constexpr char passwords[] = "Passwords";
    static constexpr char passwordHistory[] = "PasswordHistory";
    static constexpr char categories[] = "Categories";

    static const std::vector<std::string> userRecordsRecords{"Username", "Password"};
    static const std::vector<std::string> categoriesRecords{"Category"};
    static const std::vector<std::string> passwordHistoryRecords{"Creation_Time", "Modify_Time", "Expiry_Time"};
    static const std::vector<std::string> passwordRecords{
        "User_Id", "Category_Id", "Title", "Username", "Password", "Note", "Url"};
};

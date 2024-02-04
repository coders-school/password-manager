#pragma once

#include <iostream>
#include <vector>

struct DataBaseCommon
{
    static const std::vector<std::string> UserRecord;
    static const std::vector<std::string> PasswordRecords;

    static const std::string dataBasePath;
    static const std::string Users;
    static const std::string Passwords;
};

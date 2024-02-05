#pragma once

#include <iostream>
#include <vector>

struct DataBaseCommon
{
    static const std::vector<std::string> userRecords;
    static const std::vector<std::string> passwordRecords;

    static const std::string dataBasePath;
    static const std::string users;
    static const std::string passwords;
};

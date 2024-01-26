#pragma once

#include <string>

class PasswordManager {
public:
    PasswordManager();
    PasswordManager(std::string password);

    ~PasswordManager();


private:
    std::string password_;
};

#include <iostream>

#include "PasswordManager.h"

PasswordManager::PasswordManager(const std::string &password)
    : password_(password)
{
    std::cout << "Password is: " << password_ << '\n';
}

PasswordManager::~PasswordManager()
{
    std::cout << "Password manager destructor\n";
}

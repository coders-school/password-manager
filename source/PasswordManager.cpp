#include <iostream>

#include "../headers/PasswordManager.h"

PasswordManager::PasswordManager() {}

PasswordManager::PasswordManager(std::string password)
    :  password_(password)
{
    std::cout << "Password is: " << password_ << '\n';
}

PasswordManager::~PasswordManager() {
    std::cout << "Password manager destructor\n";
}

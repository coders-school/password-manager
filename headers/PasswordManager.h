#pragma once

#include <string>

class PasswordManager {
 public:
  PasswordManager() = default;
  PasswordManager(const std::string& password);

  ~PasswordManager();

 private:
  std::string password_;
};

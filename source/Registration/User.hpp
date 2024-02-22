#pragma once

#include "string"

class User 
{
 public:
  User();
  ~User() {}

  std::string getName() { return name_; }
  std::string getPassword() { return password_; }
  std::string getEmail() { return email_; }

 private:
  std::string name_;
  std::string password_;
  std::string email_;
};

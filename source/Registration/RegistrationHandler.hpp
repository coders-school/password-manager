#pragma once

#include <string>

#include "User.hpp"

class RegistrationHandler {
 public:
  RegistrationHandler();
  ~RegistrationHandler();

  bool checkUser();
  void addUser();

 private:
  User user_;
};

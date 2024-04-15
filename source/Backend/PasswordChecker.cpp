#include "PasswordChecker.hpp"

#include <regex>

PasswordChecker::PasswordChecker(const std::string& password)
    : password(password) {}

bool PasswordChecker::isSafe() {
  bool hasMinimumLength_ = hasMinimumLength();
  bool hasMinimumUppercase_ = hasMinimumUppercase();
  bool hasMinimumLowercase_ = hasMinimumLowercase();
  bool hasMinimumDigit_ = hasMinimumDigit();
  bool hasMinimumSpecialChar_ = hasMinimumSpecialChar();

  return hasMinimumLength_ && hasMinimumUppercase_ && hasMinimumLowercase_ &&
         hasMinimumDigit_ && hasMinimumSpecialChar_;
}

bool PasswordChecker::hasMinimumLength() const {
  return password.length() >= 8;
}

bool PasswordChecker::hasMinimumUppercase() const {
  return std::regex_search(password, std::regex("[A-Z]"));
}

bool PasswordChecker::hasMinimumLowercase() const {
  return std::regex_search(password, std::regex("[a-z]"));
}

bool PasswordChecker::hasMinimumDigit() const {
  return std::regex_search(password, std::regex("[0-9]"));
}

bool PasswordChecker::hasMinimumSpecialChar() const {
  return std::regex_search(password, std::regex("[^a-zA-Z0-9]"));
}

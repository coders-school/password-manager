#include <string>

class PasswordChecker {
public:
    PasswordChecker(const std::string& password);

    bool isSafe();

private:
    std::string password;

    bool hasMinimumLength_;
    bool hasMinimumUppercase_;
    bool hasMinimumLowercase_;
    bool hasMinimumDigit_;
    bool hasMinimumSpecialChar_;

    bool hasMinimumLength() const;
    bool hasMinimumUppercase() const;
    bool hasMinimumLowercase() const;
    bool hasMinimumDigit() const;
    bool hasMinimumSpecialChar() const;
};

#pragma once
#include "ISymCipher.hpp"

namespace encrypt {
class AES256CBC : public ISymCipher {
 public:
  explicit AES256CBC(std::span<const unsigned char> iv);

  void encrypt(const std::string& key, std::span<const unsigned char> plainText,
               std::span<unsigned char>& secret) const override;

  void decrypt(const std::string& key, std::span<const unsigned char> secret,
               std::span<unsigned char>& plainText) const override;

 private:
  std::span<const unsigned char> iv;
};
}  // namespace encrypt

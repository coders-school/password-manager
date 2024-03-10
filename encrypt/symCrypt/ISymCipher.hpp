#pragma once

#include <span>
#include <string>

namespace encrypt {
struct ISymCipher {
  virtual ~ISymCipher() = default;
  virtual void encrypt(const std::string &key,
                       std::span<const unsigned char> plainText,
                       std::span<unsigned char> &cipherText) const = 0;

  virtual void decrypt(const std::string &key,
                       std::span<const unsigned char> cipherText,
                       std::span<unsigned char> &plainText) const = 0;
};
}  // namespace encrypt

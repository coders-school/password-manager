#pragma once
#include "ISymCipher.hpp"

namespace encrypt {
class FakeSymCipher : public ISymCipher {
 public:
  void encrypt(const std::string& key, std::span<const unsigned char> plainText,
               std::span<unsigned char>& secret) const override;

  void decrypt(const std::string& key, std::span<const unsigned char> secret,
               std::span<unsigned char>& plainText) const override;
};
}  // namespace encrypt

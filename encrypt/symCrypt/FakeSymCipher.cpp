#include "FakeSymCipher.hpp"

#include <algorithm>
#include <stdexcept>

using namespace encrypt;

void FakeSymCipher::encrypt(const std::string& /* key */,
                            std::span<const unsigned char> plainText,
                            std::span<unsigned char>& cipherText) const {
  if (cipherText.size() < plainText.size()) {
    throw std::runtime_error("cipherText buffer is too small");
  }
  std::copy(plainText.begin(), plainText.end(), cipherText.begin());
}

void FakeSymCipher::decrypt(const std::string& /* key */,
                            std::span<const unsigned char> cipherText,
                            std::span<unsigned char>& plainText) const {
  if (plainText.size() < cipherText.size()) {
    throw std::runtime_error("plainText buffer is too small");
  }
  std::copy(cipherText.begin(), cipherText.end(), plainText.begin());
}

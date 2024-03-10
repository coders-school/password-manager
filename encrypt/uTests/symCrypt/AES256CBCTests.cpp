#include <openssl/rand.h>

#include "encrypt/symCrypt/AES256CBC.hpp"
#include "gtest/gtest.h"

using namespace encrypt;

void generateAESKeyAndIV(std::vector<unsigned char> &key,
                         std::vector<unsigned char> &iv) {
  key.resize(32);  // AES 256-bit key size
  if (RAND_bytes(key.data(), key.size()) != 1) {
    throw std::runtime_error("Error generating AES key");
  }

  iv.resize(16);  // IV size for AES CBC mode
  if (RAND_bytes(iv.data(), iv.size()) != 1) {
    throw std::runtime_error("Error generating IV");
  }
}

TEST(AES256CBCTests, simpleEncryptDecrypt) {
  std::vector<unsigned char> aesKey, iv;
  generateAESKeyAndIV(aesKey, iv);
  AES256CBC aes({iv.data(), iv.size()});
  std::string plainText{"Hello word!"};

  std::vector<unsigned char> cipherText(16);
  std::span cipherBuff = {cipherText.data(), cipherText.size()};
  aes.encrypt(
      {aesKey.begin(), aesKey.end()},
      {reinterpret_cast<unsigned char *>(plainText.data()), plainText.size()},
      cipherBuff);

  std::vector<unsigned char> decryptVec(16);
  std::span decryptBuff = {decryptVec.data(), decryptVec.size()};

  aes.decrypt({aesKey.begin(), aesKey.end()}, cipherBuff, decryptBuff);

  EXPECT_EQ(plainText, std::string(decryptBuff.data(),
                                   decryptBuff.data() + decryptBuff.size()));
}

#include "AES256CBC.hpp"

#include <openssl/aes.h>
#include <openssl/evp.h>

#include <memory>

using namespace encrypt;

using EVP_CIPHER_CTX_t =
    std::unique_ptr<EVP_CIPHER_CTX, decltype(&::EVP_CIPHER_CTX_free)>;

AES256CBC::AES256CBC(std::span<const unsigned char> iv) : iv(iv) {}

void AES256CBC::encrypt(const std::string &key,
                        std::span<const unsigned char> plainText,
                        std::span<unsigned char> &cipherText) const {
  size_t blockSize = EVP_CIPHER_block_size(EVP_aes_256_cbc());
  size_t paddingSize = blockSize - (plainText.size() % blockSize);
  size_t expectedSize = plainText.size() + paddingSize;
  if (cipherText.size() < expectedSize) {
    throw std::runtime_error("cipherText buffer is too small");
  }
  EVP_CIPHER_CTX_t ctx(EVP_CIPHER_CTX_new(), ::EVP_CIPHER_CTX_free);
  int res{}, outlen{};
  size_t totalOut{0};
  res = EVP_EncryptInit(ctx.get(), EVP_aes_256_cbc(),
                        reinterpret_cast<const unsigned char *>(key.c_str()),
                        iv.data());
  if (res != 1) {
    throw std::runtime_error("Error in EVP_EncryptInit");
  }
  res = EVP_EncryptUpdate(ctx.get(), cipherText.data(), &outlen,
                          plainText.data(), plainText.size());
  if (res != 1) {
    throw std::runtime_error("Error in EVP_EncryptUpdate");
  }
  totalOut += outlen;
  res = EVP_EncryptFinal(ctx.get(), cipherText.data() + totalOut, &outlen);
  if (res != 1) {
    throw std::runtime_error("Error in EVP_EncryptFinal");
  }
  totalOut += outlen;
  cipherText = cipherText.first(totalOut);
}

void AES256CBC::decrypt(const std::string &key,
                        std::span<const unsigned char> cipherText,
                        std::span<unsigned char> &plainText) const {
  size_t expectedSize = cipherText.size();
  if (plainText.size() < expectedSize) {
    throw std::runtime_error("plainText buffer is too small");
  }
  EVP_CIPHER_CTX_t ctx(EVP_CIPHER_CTX_new(), ::EVP_CIPHER_CTX_free);
  int res{}, outlen{};
  size_t totalOut{0};
  res = EVP_DecryptInit(ctx.get(), EVP_aes_256_cbc(),
                        reinterpret_cast<const unsigned char *>(key.c_str()),
                        iv.data());
  if (res != 1) {
    throw std::runtime_error("Error in EVP_DecryptInit");
  }
  res = EVP_DecryptUpdate(ctx.get(), plainText.data(), &outlen,
                          cipherText.data(), cipherText.size());
  if (res != 1) {
    throw std::runtime_error("Error in EVP_DecryptUpdate");
  }
  totalOut += outlen;

  res = EVP_DecryptFinal(ctx.get(), plainText.data() + totalOut, &outlen);
  if (res != 1) {
    throw std::runtime_error("Error in EVP_DecryptFinal");
  }
  totalOut += outlen;
  plainText = plainText.first(totalOut);
}

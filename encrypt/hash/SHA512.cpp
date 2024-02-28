#include "SHA512.hpp"

#include <openssl/evp.h>
#include <openssl/sha.h>

#include <memory>
#include <stdexcept>
#include <vector>

using namespace encrypt;

using EVP_MD_CTX_ptr =
    std::unique_ptr<EVP_MD_CTX, decltype(&::EVP_MD_CTX_free)>;

std::string SHA512::hash(std::span<const unsigned char> input) const {
  EVP_MD_CTX_ptr ctx(EVP_MD_CTX_new(), ::EVP_MD_CTX_free);
  if (!ctx) {
    throw std::runtime_error("Error creating EVP_MD_CTX");
  }
  if (!EVP_DigestInit_ex(ctx.get(), EVP_sha512(), nullptr)) {
    throw std::runtime_error("Error initializing SHA-512 digest");
  }
  if (!EVP_DigestUpdate(ctx.get(), input.data(), input.size())) {
    throw std::runtime_error("Error updating SHA-512 digest");
  }
  std::vector<unsigned char> hash(SHA512_DIGEST_LENGTH);
  if (!EVP_DigestFinal_ex(ctx.get(), hash.data(), nullptr)) {
    throw std::runtime_error("Error finalizing SHA-512 digest");
  }
  return std::string(hash.begin(), hash.end());
}

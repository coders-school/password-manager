#include <openssl/rand.h>

#include "encrypt/hash/SHA512.hpp"
#include "gtest/gtest.h"

using namespace encrypt;

TEST(SHA512Tests, simpleHash) {
  std::vector<unsigned char> input(1024);
  if (RAND_bytes(input.data(), input.size()) != 1) {
    throw std::runtime_error("Error generating");
  }
  SHA512 hash;

  auto s1 = hash.hash({input.data(), input.size()});
  auto s2 = hash.hash({input.data(), input.size()});
  auto s3 = hash.hash({input.data(), input.size()});
  EXPECT_EQ(s1, s2);
  EXPECT_EQ(s1, s3);
  EXPECT_NE(s1, std::string(input.begin(), input.end()));
}

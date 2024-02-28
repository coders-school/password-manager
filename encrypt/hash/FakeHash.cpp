#include "FakeHash.hpp"
using namespace encrypt;

std::string FakeHash::hash(std::span<const unsigned char> input) const {
  return std::string(input.begin(), input.end());
}

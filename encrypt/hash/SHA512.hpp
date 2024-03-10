#pragma once

#include "IHash.hpp"

namespace encrypt {
class SHA512 : public IHash {
 public:
  std::string hash(std::span<const unsigned char> input) const override;
};
}  // namespace encrypt

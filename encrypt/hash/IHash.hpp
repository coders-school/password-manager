#pragma once
#include <span>
#include <string>

namespace encrypt {
class IHash {
 public:
  virtual ~IHash() = default;
  virtual std::string hash(std::span<const unsigned char> input) const = 0;
};
}  // namespace encrypt

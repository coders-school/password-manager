#pragma once

#include <map>

#include "../common/DataBaseCommon.hpp"
#include "../common/DataBaseRequest.hpp"

namespace dataBase::interface {
class IQueryOperationBuilder {
 public:
  using Data = const std::map<std::string, std::string> &;

  virtual ~IQueryOperationBuilder() = default;

  virtual std::string buildQuery(
      const common::DataBaseRequest &requestData) = 0;
};
}  // namespace dataBase::interface

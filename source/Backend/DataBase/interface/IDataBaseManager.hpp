#pragma once

#include <map>
#include <memory>
#include <vector>

#include "../common/DataBaseRequest.hpp"

namespace dataBase::interface {
class IDataBaseManager {
 public:
  virtual ~IDataBaseManager() = default;

  virtual void executeOperation(const common::DataBaseRequest &requestData) = 0;
  virtual std::vector<std::string> executeAndGetOperation(
      const common::DataBaseRequest &requestData) = 0;
};
}  // namespace dataBase::interface

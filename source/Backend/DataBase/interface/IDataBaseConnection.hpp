#pragma once

#include <string>
#include <vector>

#include "sqlite3.h"

namespace dataBase::interface {
class IDataBaseConnection {
 public:
  virtual ~IDataBaseConnection() = default;

  virtual void executeQuery(const std::string &query) = 0;
  virtual std::vector<std::string> executeQueryAndGetData(
      const std::string &query) = 0;
};
};  // namespace dataBase::interface

#pragma once

#include <map>
#include <string>

namespace dataBase::common {
using RequestData = std::map<std::string, std::string>;
using PrimaryKey = std::pair<std::string, std::string>;

struct DataBaseRequest {
  enum class TableType { Users, Passwords, PasswordHistory, Categories };

  enum class OperationType { Insert, Delete, Update, Select };

  OperationType operationType_;
  TableType tableType_;
  RequestData data_;
  PrimaryKey primaryKey_;
};

}  // namespace dataBase::common

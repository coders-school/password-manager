#pragma once

#include <stdexcept>
#include <string>

#include "interface/IDataBaseConnection.hpp"
#include "sqlite3.h"

namespace dataBase {
class DataBaseConnection : public interface::IDataBaseConnection {
 public:
  DataBaseConnection(const char *dbName);

  ~DataBaseConnection();

  void executeQuery(const std::string &query) override;
  std::vector<std::string> executeQueryAndGetData(
      const std::string &query) override;

 private:
  sqlite3 *database_;
};

}  // namespace dataBase

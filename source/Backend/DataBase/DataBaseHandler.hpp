#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

#include "sqlite3.h"

namespace dataBase {

class DataBaseHandler {
 public:
  DataBaseHandler(const char *dbName);
  ~DataBaseHandler();

  void createTable(const std::string &tableName, const std::string &columns);
  void insertData(const std::string &tableName,
                  const std::vector<std::string> &columns,
                  const std::vector<std::string> &values);
  void deleteData(const std::string &tableName, const std::string &columns,
                  const std::string &value);

  void updateData(const std::string &tableName, const std::string &setRecord,
                  const std::string &setValue, const std::string &findRecord,
                  const std::string &findValue);

  void selectData(const std::string &tableName, const std::string &findRecord,
                  const std::string &findValue);

 private:
  void executeQuery(const char *query);
  sqlite3 *database_;
};

}  // namespace dataBase

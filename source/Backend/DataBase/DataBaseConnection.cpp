#include "DataBaseConnection.hpp"

#include "sqlite3.h"

namespace dataBase {
namespace {
void checkResult(sqlite3 *database, int result, char *errMsg) {
  if (result != SQLITE_OK) {
    std::string error_msg = errMsg ? errMsg : sqlite3_errmsg(database);
    sqlite3_free(errMsg);
    throw std::runtime_error("Failed to execute query: " + error_msg);
  }
}
}  // namespace
DataBaseConnection::DataBaseConnection(const char *dbName)
    : database_(nullptr) {
  int result = sqlite3_open(dbName, &database_);
  if (result != SQLITE_OK) {
    throw std::runtime_error("Failed to open database: " +
                             std::string(sqlite3_errmsg(database_)));
  }
}

DataBaseConnection::~DataBaseConnection() {
  if (database_ != nullptr) {
    sqlite3_close(database_);
  }
}

void DataBaseConnection::executeQuery(const std::string &query) {
  char *errMsg = nullptr;

  int result =
      sqlite3_exec(database_, query.c_str(), nullptr, nullptr, &errMsg);
  checkResult(database_, result, errMsg);
}

std::vector<std::string> DataBaseConnection::executeQueryAndGetData(
    const std::string &query) {
  char *errMsg = nullptr;

  auto callback = [](void *data, int argc, char **argv,
                     char **azColName) -> int {
    auto records = reinterpret_cast<std::vector<std::string> *>(data);
    for (int i = 0; i < argc; i++) {
      records->push_back(argv[i] ? argv[i] : "");
    }
    return 0;
  };

  std::vector<std::string> records;
  int result =
      sqlite3_exec(database_, query.c_str(), callback, &records, &errMsg);

  checkResult(database_, result, errMsg);
  return records;
}

}  // namespace dataBase

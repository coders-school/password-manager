
#include "QueryOperationBuilder.hpp"

#include <format>

#include "common/DataBaseCommon.hpp"
namespace dataBase {
namespace {
using OperationType = common::DataBaseRequest::OperationType;
using TableType = common::DataBaseRequest::TableType;
using QueryBuilders = std::unordered_map<
    OperationType, std::function<std::string(const common::DataBaseRequest &,
                                             const std::string &)>>;
using TableNameBuilders = std::unordered_map<TableType, std::string>;
bool isPrimaryKeyEmpty(const common::PrimaryKey &primaryKey) {
  return (primaryKey.first.empty() || primaryKey.second.empty());
}

std::string buildInsertQuery(const common::DataBaseRequest &requestData,
                             const std::string &tableName) {
  std::string columns;
  std::string values;
  for (auto it = requestData.data_.begin(); it != requestData.data_.end();
       ++it) {
    columns += it->first;
    values += std::format("'{}'", it->second);
    if (std::next(it) != requestData.data_.end()) {
      columns += ", ";
      values += ", ";
    }
  }

  return std::format("INSERT INTO {} ({}) VALUES ({});", tableName, columns,
                     values);
}

std::string buildUpdateQuery(const common::DataBaseRequest &requestData,
                             const std::string &tableName) {
  std::string values;

  for (auto it = requestData.data_.begin(); it != requestData.data_.end();
       ++it) {
    values += std::format("{}='{}'", it->first, it->second);
    if (std::next(it) != requestData.data_.end()) {
      values += ", ";
    }
  }

  return std::format("UPDATE {} SET {} WHERE {}='{}';", tableName, values,
                     requestData.primaryKey_.first,
                     requestData.primaryKey_.second);
}

std::string buildDeleteQuery(const common::DataBaseRequest &requestData,
                             const std::string &tableName) {
  return std::format("DELETE FROM {} WHERE {}='{}';", tableName,
                     requestData.primaryKey_.first,
                     requestData.primaryKey_.second);
}

std::string buildSelectQuery(const common::DataBaseRequest &requestData,
                             const std::string &tableName) {
  return std::format("SELECT * FROM {} WHERE {}='{}';", tableName,
                     requestData.primaryKey_.first,
                     requestData.primaryKey_.second);
}
TableNameBuilders tableNames = {
    {TableType::Users, common::users},
    {TableType::Passwords, common::passwords},
    {TableType::PasswordHistory, common::passwordHistory},
    {TableType::Categories, common::categories}};

std::string getTableName(const TableType &table) {
  if (auto it = tableNames.find(table); it != tableNames.end())
    return it->second;

  return {};
}

QueryBuilders queryBuilders = {{OperationType::Insert, buildInsertQuery},
                               {OperationType::Update, buildUpdateQuery},
                               {OperationType::Delete, buildDeleteQuery},
                               {OperationType::Select, buildSelectQuery}};

std::string getOperationQuery(const common::DataBaseRequest &requestData,
                              const std::string &tableName) {
  if (auto it = queryBuilders.find(requestData.operationType_);
      it != queryBuilders.end())
    return it->second(requestData, tableName);

  return {};
}
}  // namespace

std::string QueryOperationBuilder::buildQuery(
    const common::DataBaseRequest &requestData) {
  if (requestData.operationType_ != OperationType::Insert &&
      isPrimaryKeyEmpty(requestData.primaryKey_))
    return {};

  if (requestData.operationType_ != OperationType::Select &&
      requestData.data_.empty())
    return {};

  auto tableName = getTableName(requestData.tableType_);
  if (tableName.empty()) return {};

  return getOperationQuery(requestData, tableName);
}

}  // namespace dataBase

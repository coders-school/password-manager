
#include "DataBaseManager.hpp"

#include "QueryOperationBuilder.hpp"
namespace dataBase {
DataBaseManager::DataBaseManager(
    std::shared_ptr<interface::IDataBaseConnection> dataBaseConnection,
    std::shared_ptr<interface::IQueryOperationBuilder> queryOperationBuilder)
    : dataBaseConnection_(std::move(dataBaseConnection)),
      queryOperationBuilder_(std::move(queryOperationBuilder)) {}

void DataBaseManager::executeOperation(
    const common::DataBaseRequest &requestData) {
  std::string query = queryOperationBuilder_->buildQuery(requestData);

  if (requestData.operationType_ !=
          common::DataBaseRequest::OperationType::Select &&
      !query.empty())

    try {
      dataBaseConnection_->executeQuery(query);
    } catch (const std::runtime_error &e) {
      std::cerr << "Error executing query: " << e.what() << std::endl;
    }
}

std::vector<std::string> DataBaseManager::executeAndGetOperation(
    const common::DataBaseRequest &requestData) {
  std::string query = queryOperationBuilder_->buildQuery(requestData);

  try {
    if (requestData.operationType_ ==
            common::DataBaseRequest::OperationType::Select &&
        !query.empty())
      return dataBaseConnection_->executeQueryAndGetData(query);

    return {};
  } catch (const std::runtime_error &e) {
    std::cerr << "Error executing query: " << e.what() << std::endl;
    return {};
  }
}
}  // namespace dataBase

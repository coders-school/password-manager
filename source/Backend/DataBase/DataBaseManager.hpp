#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>

#include "common/DataBaseRequest.hpp"
#include "interface/IDataBaseConnection.hpp"
#include "interface/IDataBaseManager.hpp"
#include "interface/IQueryOperationBuilder.hpp"

namespace dataBase {
class DataBaseManager : public interface::IDataBaseManager {
 public:
  DataBaseManager(
      std::shared_ptr<interface::IDataBaseConnection> dataBaseConnection,
      std::shared_ptr<interface::IQueryOperationBuilder> queryOperationBuilder);
  ~DataBaseManager() = default;

  void executeOperation(const common::DataBaseRequest &requestData) override;
  std::vector<std::string> executeAndGetOperation(
      const common::DataBaseRequest &requestData) override;

 private:
  std::shared_ptr<interface::IDataBaseConnection> dataBaseConnection_;
  std::shared_ptr<interface::IQueryOperationBuilder> queryOperationBuilder_;
};
}  // namespace dataBase

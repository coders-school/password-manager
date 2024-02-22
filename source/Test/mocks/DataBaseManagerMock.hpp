#pragma once

#include "../../Backend/DataBase/interface/IDataBaseManager.hpp"
#include "gmock/gmock.h"

namespace dataBase::mock {
class DataBaseManagerMock : public interface::IDataBaseManager {
 public:
  MOCK_METHOD(void, executeOperation, (const common::DataBaseRequest &),
              (override));
  MOCK_METHOD(std::vector<std::string>, executeAndGetOperation,
              (const common::DataBaseRequest &), (override));
};
}  // namespace dataBase::mock

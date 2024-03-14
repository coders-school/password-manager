#pragma once

#include "../../Backend/DataBase/interface/IDataBaseConnection.hpp"
#include "gmock/gmock.h"

namespace dataBase::mock {
class DataBaseConnectionMock : public interface::IDataBaseConnection {
 public:
  MOCK_METHOD(void, executeQuery, (const std::string &), (override));
  MOCK_METHOD(std::vector<std::string>, executeQueryAndGetData,
              (const std::string &), (override));
};
}  // namespace dataBase::mock

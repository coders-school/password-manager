#pragma once

#include "../../Backend/DataBase/interface/IQueryOperationBuilder.hpp"
#include "gmock/gmock.h"

namespace dataBase::mock {
class QueryOperationBuilderMock : public interface::IQueryOperationBuilder {
 public:
  MOCK_METHOD(std::string, buildQuery,
              (const common::DataBaseRequest &requestData), (override));
};
}  // namespace dataBase::mock

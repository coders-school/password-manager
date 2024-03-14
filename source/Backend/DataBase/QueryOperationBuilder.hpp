#pragma once

#include <format>
#include <functional>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>

#include "common/DataBaseCommon.hpp"
#include "common/DataBaseRequest.hpp"
#include "interface/IQueryOperationBuilder.hpp"

namespace dataBase {

class QueryOperationBuilder : public interface::IQueryOperationBuilder {
 public:
  QueryOperationBuilder() = default;
  ~QueryOperationBuilder() = default;
  std::string buildQuery(const common::DataBaseRequest &requestData) override;
};

}  // namespace dataBase

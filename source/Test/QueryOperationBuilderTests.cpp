#include <memory>

#include "../Backend/DataBase/QueryOperationBuilder.hpp"
#include "../Backend/DataBase/common/DataBaseRequest.hpp"
#include "gtest/gtest.h"
namespace dataBase::ut {
TEST(QueryOperationBuilderTest, shouldBuildInsertQuery) {
  auto sut = std::make_shared<dataBase::QueryOperationBuilder>();
  std::map<std::string, std::string> data{{"Username", "exampleLogin"},
                                          {"Password", "examplePassword"}};
  std::string expectedResult{
      "INSERT INTO Users (Password, Username) VALUES ('examplePassword', "
      "'exampleLogin');"};
  dataBase::common::DataBaseRequest request{
      dataBase::common::DataBaseRequest::OperationType::Insert,
      dataBase::common::DataBaseRequest::TableType::Users, data};

  ASSERT_EQ(sut->buildQuery(request), expectedResult);
}

TEST(QueryOperationBuilderTest, shouldBuildUpdateQuery) {
  auto sut = std::make_shared<dataBase::QueryOperationBuilder>();
  std::map<std::string, std::string> data{{"Username", "exampleLogin"},
                                          {"Password", "examplePassword"}};
  std::pair<std::string, std::string> primaryKey{"User_Id", "1"};
  std::string expectedResult{
      "UPDATE Users SET Password='examplePassword', Username='exampleLogin' "
      "WHERE User_Id='1';"};
  dataBase::common::DataBaseRequest request{
      dataBase::common::DataBaseRequest::OperationType::Update,
      dataBase::common::DataBaseRequest::TableType::Users, data, primaryKey};

  ASSERT_EQ(sut->buildQuery(request), expectedResult);
}

TEST(QueryOperationBuilderTest, shouldBuildDeleteQuery) {
  auto sut = std::make_shared<dataBase::QueryOperationBuilder>();
  std::map<std::string, std::string> data{{"Username", "exampleLogin"},
                                          {"Password", "examplePassword"}};
  std::pair<std::string, std::string> primaryKey{"User_Id", "1"};

  std::string expectedResult{"DELETE FROM Users WHERE User_Id='1';"};
  dataBase::common::DataBaseRequest request{
      dataBase::common::DataBaseRequest::OperationType::Delete,
      dataBase::common::DataBaseRequest::TableType::Users, data, primaryKey};

  ASSERT_EQ(sut->buildQuery(request), expectedResult);
}

TEST(QueryOperationBuilderTest, shouldBuildSelectQuery) {
  auto sut = std::make_shared<dataBase::QueryOperationBuilder>();
  std::map<std::string, std::string> data{{"Username", "exampleLogin"},
                                          {"Password", "examplePassword"}};
  std::pair<std::string, std::string> primaryKey{"User_Id", "1"};
  std::string expectedResult{"SELECT * FROM Users WHERE User_Id='1';"};
  dataBase::common::DataBaseRequest request{
      dataBase::common::DataBaseRequest::OperationType::Select,
      dataBase::common::DataBaseRequest::TableType::Users, data, primaryKey};

  ASSERT_EQ(sut->buildQuery(request), expectedResult);
}

TEST(QueryOperationBuilderTest,
     shouldNotBuildQueryWhenInvalidPrimaryKeyIsInvalid) {
  auto sut = std::make_shared<dataBase::QueryOperationBuilder>();

  std::map<std::string, std::string> data{{"Username", "exampleLogin"},
                                          {"Password", "examplePassword"}};
  dataBase::common::DataBaseRequest request{
      dataBase::common::DataBaseRequest::OperationType::Select,
      dataBase::common::DataBaseRequest::TableType::Users, data};

  ASSERT_EQ(sut->buildQuery(request), "");
}

TEST(QueryOperationBuilderTest, shouldNotBuildQueryWhenDataIsEmpty) {
  auto sut = std::make_shared<dataBase::QueryOperationBuilder>();

  std::pair<std::string, std::string> primaryKey{"User_Id", "1"};

  dataBase::common::DataBaseRequest request;
  request.operationType_ =
      dataBase::common::DataBaseRequest::OperationType::Insert,
  request.tableType_ = dataBase::common::DataBaseRequest::TableType::Users;
  request.primaryKey_ = primaryKey;

  ASSERT_EQ(sut->buildQuery(request), "");
}

TEST(QueryOperationBuilderTest, shouldNotBuildQueryWhenTableNameIsInvalid) {
  auto sut = std::make_shared<dataBase::QueryOperationBuilder>();

  std::map<std::string, std::string> data{{"Username", "exampleLogin"},
                                          {"Password", "examplePassword"}};
  std::pair<std::string, std::string> primaryKey{"User_Id", "1"};

  dataBase::common::DataBaseRequest request;
  request.operationType_ =
      dataBase::common::DataBaseRequest::OperationType::Select;
  request.data_ = data;
  request.primaryKey_ = primaryKey;

  ASSERT_EQ(sut->buildQuery(request), "");
}

TEST(QueryOperationBuilderTest, shouldNotBuildQueryWhenOperationTypeIsInvalid) {
  auto sut = std::make_shared<dataBase::QueryOperationBuilder>();

  std::map<std::string, std::string> data{{"Username", "exampleLogin"},
                                          {"Password", "examplePassword"}};
  std::pair<std::string, std::string> primaryKey{"User_Id", "1"};

  dataBase::common::DataBaseRequest request;
  request.tableType_ = dataBase::common::DataBaseRequest::TableType::Users;
  request.data_ = data;
  request.primaryKey_ = primaryKey;

  ASSERT_EQ(sut->buildQuery(request), "");
}

}  // namespace dataBase::ut

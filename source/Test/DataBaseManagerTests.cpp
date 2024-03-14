#include "../Backend/DataBase/DataBaseManager.hpp"
#include "../Backend/DataBase/common/DataBaseRequest.hpp"
#include "gtest/gtest.h"
#include "mocks/DataBaseConnectionMock.hpp"
#include "mocks/QueryOperationBuilderMock.hpp"

namespace dataBase::ut {
using namespace dataBase::mock;
using namespace dataBase::common;
using namespace testing;

class DataBaseManagerTest : public Test {
 protected:
  void SetUp() override {
    dataBaseConnectionMock_ = std::make_shared<DataBaseConnectionMock>();
    queryOperationBuilderMock_ = std::make_shared<QueryOperationBuilderMock>();

    sut_ = std::make_shared<DataBaseManager>(dataBaseConnectionMock_,
                                             queryOperationBuilderMock_);
  }

 protected:
  std::shared_ptr<DataBaseConnectionMock> dataBaseConnectionMock_;
  std::shared_ptr<QueryOperationBuilderMock> queryOperationBuilderMock_;
  std::shared_ptr<DataBaseManager> sut_;
};

TEST_F(DataBaseManagerTest, shouldExecuteOperation) {
  DataBaseRequest request{DataBaseRequest::OperationType::Insert};

  EXPECT_CALL(*queryOperationBuilderMock_, buildQuery(_))
      .WillOnce(Return("expected_query"));
  EXPECT_CALL(*dataBaseConnectionMock_, executeQuery("expected_query"))
      .Times(1);

  sut_->executeOperation(request);
}

TEST_F(DataBaseManagerTest, shouldNotExecuteOperationWhenSelectOperationType) {
  DataBaseRequest request{DataBaseRequest::OperationType::Select};

  EXPECT_CALL(*queryOperationBuilderMock_, buildQuery(_))
      .WillOnce(Return("expected_query"));
  EXPECT_CALL(*dataBaseConnectionMock_, executeQuery(_)).Times(0);

  sut_->executeOperation(request);
}

TEST_F(DataBaseManagerTest, shouldNotExecuteOperationWhenQueryIsEmpty) {
  DataBaseRequest request{DataBaseRequest::OperationType::Insert};

  EXPECT_CALL(*queryOperationBuilderMock_, buildQuery(_)).WillOnce(Return(""));
  EXPECT_CALL(*dataBaseConnectionMock_, executeQuery(_)).Times(0);

  sut_->executeOperation(request);
}

TEST_F(DataBaseManagerTest, shouldExecuteAndGetOperation) {
  DataBaseRequest request{DataBaseRequest::OperationType::Select};
  std::vector<std::string> expectedResult{"UserName", "UserPassword"};
  EXPECT_CALL(*queryOperationBuilderMock_, buildQuery(_))
      .WillOnce(Return("expected_query"));
  EXPECT_CALL(*dataBaseConnectionMock_,
              executeQueryAndGetData("expected_query"))
      .WillOnce(Return(expectedResult));

  auto result = sut_->executeAndGetOperation(request);

  EXPECT_EQ(result, expectedResult);
}

TEST_F(DataBaseManagerTest,
       shouldNotExecuteAndGetOperationWhenOperationTypeIsNotEquelSelect) {
  DataBaseRequest request{DataBaseRequest::OperationType::Insert};

  EXPECT_CALL(*queryOperationBuilderMock_, buildQuery(_))
      .WillOnce(Return("expected_query"));
  EXPECT_CALL(*dataBaseConnectionMock_,
              executeQueryAndGetData("expected_query"))
      .Times(0);

  auto result = sut_->executeAndGetOperation(request);

  EXPECT_TRUE(result.empty());
}

TEST_F(DataBaseManagerTest, shouldNotExecuteAndGetOperationWhenQueryIsEmpty) {
  DataBaseRequest request{DataBaseRequest::OperationType::Select};

  EXPECT_CALL(*queryOperationBuilderMock_, buildQuery(_)).WillOnce(Return(""));
  EXPECT_CALL(*dataBaseConnectionMock_,
              executeQueryAndGetData("expected_query"))
      .Times(0);

  auto result = sut_->executeAndGetOperation(request);

  EXPECT_TRUE(result.empty());
}

}  // namespace dataBase::ut

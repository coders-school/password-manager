#pragma once

#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>

#include "sqlite3.h"

class DataBaseHandler
{
public:
    DataBaseHandler(const std::string &dbName);
    ~DataBaseHandler();

    void createTable(const std::string &tableName, const std::string &columns);
    void insertData(const std::string &tableName, const std::vector<std::string> &columns, const std::vector<std::string> &values);

    void updateData(
        const std::string &tableName,
        const std::string &setRecord,
        const std::string &setValue,
        const std::string &findRecord,
        const std::string &findValue);

    void selectData(
        const std::string &tableName,
        const std::string &findRecord,
        const std::string &findValue);

private:
    void executeQuery(const std::string &query);

    sqlite3 *database_;
};
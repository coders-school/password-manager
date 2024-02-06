#include <iostream>
#include <memory>
#include <sstream>

#include "DataBaseHandler.hpp"
namespace dataBase
{

    DataBaseHandler::DataBaseHandler(const char *dbName)
        : database_(nullptr)
    {
        int result = sqlite3_open(dbName, &database_);
        if (result != SQLITE_OK)
        {
            throw std::runtime_error("Failed to open database: " + std::string(sqlite3_errmsg(database_)));
        }
    }

    DataBaseHandler::~DataBaseHandler()
    {
        if (database_ != nullptr)
        {
            sqlite3_close(database_);
        }
    }

    void DataBaseHandler::executeQuery(const char *query)
    {
        char *errMsg = nullptr;
        int result = sqlite3_exec(database_, query, nullptr, nullptr, &errMsg);
        if (result != SQLITE_OK)
        {
            throw std::runtime_error("Query execution failed: " + std::string(errMsg));
        }
    }

    void DataBaseHandler::createTable(const std::string &tableName, const std::string &columns)
    {
        std::string query = "CREATE TABLE IF NOT EXISTS " + tableName + " (" + columns + ");";
        executeQuery(query.c_str());
    }

    void DataBaseHandler::insertData(const std::string &tableName, const std::vector<std::string> &columns, const std::vector<std::string> &values)
    {
        if (columns.size() != values.size())
        {
            throw std::invalid_argument("Columns and values sizes do not match.");
        }

        std::ostringstream queryStream;
        queryStream << "INSERT INTO " << tableName << " (";
        for (size_t i = 0; i < columns.size(); ++i)
        {
            queryStream << columns[i];
            if (i < columns.size() - 1)
            {
                queryStream << ", ";
            }
        }
        queryStream << ") VALUES (";
        for (size_t i = 0; i < values.size(); ++i)
        {
            queryStream << "'" << values[i] << "'";
            if (i < values.size() - 1)
            {
                queryStream << ", ";
            }
        }
        queryStream << ");";

        std::string query = queryStream.str();
        executeQuery(query.c_str());
    }

    void DataBaseHandler::deleteData(const std::string &tableName, const std::string &columns, const std::string &value)
    {
        std::string query = "DELETE FROM " + tableName + " WHERE " + columns + " = '" + value + "';";
        executeQuery(query.c_str());
    }

    void DataBaseHandler::updateData(
        const std::string &tableName,
        const std::string &setRecord,
        const std::string &setValue,
        const std::string &findRecord,
        const std::string &findValue)
    {
        std::string query = "UPDATE " + tableName + " SET " + setRecord + " ='" + setValue + "' WHERE " + findRecord + " = '" + findValue + "';";
        executeQuery(query.c_str());
    }

    void DataBaseHandler::selectData(
        const std::string &tableName,
        const std::string &findRecord,
        const std::string &findValue)
    {
        std::string query = "SELECT " + findRecord + " FROM " + tableName + " WHERE " + findValue;

        executeQuery(query.c_str());
    }

}

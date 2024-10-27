#ifndef DATABASEHANDLER_HPP
#define DATABASEHANDLER_HPP


#include <string>
#include <sqlite3.h>
#include <vector>
#include <filesystem>
#include <iostream>
#include <dbStatement.hpp>
#include <memory>

class DatabaseHandler
{
private:
    std::string filename;
    std::filesystem::path pth;
    sqlite3* db;
    std::vector<std::string> tables;

public:
    DatabaseHandler(std::string fileName);
    // database init
    int database_open();

    // transaction begin
    bool begin_transaction();
    // transaction commit
    bool commit_transaction();
    // transaction rollback

    // insert score

    // fetch score

    // create a statement
    std::unique_ptr<dbStatement> make_statement(std::string query);

    // destructor
    ~DatabaseHandler();
};

#endif // DATABASEHANDLER_HPP
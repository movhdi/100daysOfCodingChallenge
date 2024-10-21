#ifndef DATABASEHANDLER_HPP
#define DATABASEHANDLER_HPP


#include <string>
#include <sqlite3.h>
#include <vector>
#include <filesystem>
#include <iostream>


class DatabaseHandler
{
private:
    std::string filename;
    std::filesystem::path pth;
    sqlite3* db;
public:
    DatabaseHandler(std::string fileName);
    // database init
    int database_open();
    // open a connection to database

    // create a statement

    // finilize the statement

    // close the database

    // destructor
    ~DatabaseHandler();
};

#endif // DATABASEHANDLER_HPP
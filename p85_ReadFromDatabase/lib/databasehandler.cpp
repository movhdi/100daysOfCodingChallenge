#include <databasehandler.hpp>
#include <logging.hpp>

DatabaseHandler::DatabaseHandler(std::string fileName) : pth(fileName)
{
    if (pth.has_filename())
    {
        LOG_info << "database file path set";
    }
    tables.emplace_back("movies","persons");
    
}

int DatabaseHandler::database_open() {
    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc == SQLITE_OK)
    {
        LOG_info << "database opened successfully";
        return 0;
    }else
    {
        LOG_error << sqlite3_errmsg(db);
        return rc;
    }
}

bool DatabaseHandler::begin_transaction()
{
    this->make_statement("BEGIN TRANSACTION");
    return false;
}

std::unique_ptr<dbStatement> DatabaseHandler::make_statement(std::string query)
{
    return std::make_unique<dbStatement>(this->db,query);
}

DatabaseHandler::~DatabaseHandler()
{
    sqlite3_close(this->db);
}

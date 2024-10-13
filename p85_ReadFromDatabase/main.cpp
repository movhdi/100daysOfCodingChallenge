#define sqlite3_api
// #define SQLiteCPP


#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#ifdef sqlite3_api
#include <sqlite3.h>
#endif

#ifdef SQLiteCPP
#include <SQLiteCpp/SQLiteCpp.h>
#endif

struct movie
{
    std::string name;
    int year;
    int length;
};


int main() {

    std::vector<movie> movies;

#ifdef SQLiteCPP // using SQLiteCpp wrapper api
    std::cout << "\n\nbuilt and runned successfully" << std::endl;
    std::cout << "SQlite3 version " << SQLite::VERSION << " ("
                << SQLite::getLibVersion() << ")" << std::endl;
    std::cout << "SQliteC++ version " << SQLITECPP_VERSION << std::endl;
    
    try {
        SQLite::Database db("../moviedatabase",
                            SQLite::OPEN_READWRITE);
        std::cout << "SQLite database file '" << db.getFilename().c_str() << "' opened successfully" << std::endl;
        std::string queryText = "SELECT * FROM";
        SQLite::Statement query(db, "SELECT * FROM movies"); 
        
        while(query.executeStep())
        {
            std::cout << "row : " << query.getColumn(0) << "\\" << query.getColumn(1) << "\\" << query.getColumn(2) << std::endl;
            movie temp;
            std::stringstream ss;
            ss << query.getColumn(0);
            temp.name = ss.str();
            temp.year = query.getColumn(1);
            temp.length = query.getColumn(2);
            movies.emplace_back(std::move(temp));
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
#endif

#ifdef sqlite3_api // using sqlite3 direct api
    
    sqlite3 *db;
    if (SQLITE_OK==sqlite3_open("/home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/moviedatabase",&db))
    {
        std::cout << "database opened successfully!" << std::endl;
    }
    std::string queryText = "SELECT * FROM movies";
    int rowNO{2};
    int coloumnNo{3};
    char ***result;
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, queryText.c_str(), queryText.size(), &stmt, NULL);
    
    auto count = sqlite3_column_count(stmt);
    try
    {
        while(SQLITE_DONE != sqlite3_step(stmt))
        {
            std::cout << "the first coloumn [name] is: " << sqlite3_column_text(stmt, 0) << std::endl;
            std::cout << "the second coloumn [year] is: " << sqlite3_column_text(stmt, 1) << std::endl;
            std::cout << "the third coloumn [length] is: " << sqlite3_column_text(stmt, 2) << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "exception happend!\n";
    }
    

    sqlite3_close(db);
#endif

    for (const auto item : movies)
    {
        std::cout << "\nname of movie: " << item.name << "\nyear :" << item.year << "\nlength: " << item.length << std::endl; 
    }
  return 0;
}
#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include <string>
#include <vector>
#include <sstream>

struct movie
{
    std::string name;
    int year;
    int length;
};


int main() {
    std::cout << "\n\nbuilt and runned successfully" << std::endl;
    std::cout << "SQlite3 version " << SQLite::VERSION << " ("
                << SQLite::getLibVersion() << ")" << std::endl;
    std::cout << "SQliteC++ version " << SQLITECPP_VERSION << std::endl;
    std::vector<movie> movies;
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
    

    for (const auto item : movies)
    {
        std::cout << "\nname of movie: " << item.name << "\nyear :" << item.year << "\nlength: " << item.length << std::endl; 
    }
    
  return 0;
}
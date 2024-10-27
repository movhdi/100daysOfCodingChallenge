#define sqlite3_api
// #define SQLiteCPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


#ifdef sqlite3_api
#include <sqlite3.h>
#endif

#ifdef SQLiteCPP
#include <SQLiteCpp/SQLiteCpp.h>
#endif

struct movie {
  std::string name;
  int year;
  int length;
};


int main() {

  std::vector<movie> movies;

#ifdef sqlite3_api // using sqlite3 direct api

  sqlite3 *db;

  if (SQLITE_OK == sqlite3_open("/home/med/100daysOfCodingChallenge/"
                                "p85_ReadFromDatabase/moviedatabase",
                                &db)) {
    std::cout << "\033[32mdatabase opened successfully!\033[0m\n" << std::endl;
  }

  std::vector<std::string> tables{"movies", "persons"};
  try {
    sqlite3_stmt *stmt;
    for (const auto &tablename : tables) {
      std::cout << "----------" + tablename << std::endl;
      std::string queryText;
      if (tablename == "movies") {
        queryText = "SELECT title FROM " + tablename + ";";
      } else {
        queryText = "SELECT * FROM " + tablename + ";";
      }

      auto rc1 = sqlite3_prepare_v2(db, queryText.c_str(), -1, &stmt, nullptr);
      if (rc1 != SQLITE_OK) {
        std::cout << "Failed to prepare the statement : " << sqlite3_errmsg(db)
                  << std::endl;
        sqlite3_close(db);
        return rc1;
      }
      while (SQLITE_DONE != sqlite3_step(stmt)) {
        std::cout << "the first coloumn [\033[31mname\033[0m] is: "
                  << sqlite3_column_text(stmt, 0) << std::endl;
        // std::cout << "the second coloumn [\033[32myear\033[0m] is: " <<
        // sqlite3_column_text(stmt, 1) << std::endl; std::cout << "the third
        // coloumn [\033[32mlength\033[0m] is: " << sqlite3_column_text(stmt, 2)
        // << std::endl;
      }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    std::cout << "exception happend!\n";
  }

try
{
  sqlite3_stmt * stmt = nullptr;
  std::string sql;
  sql = "SELECT * FROM movies WHERE title = @moviename;";
  sqlite3_prepare_v2(db, sql.c_str(),sql.size(), &stmt, nullptr);
  std::cout << "Error prepare:" << sqlite3_errmsg(db) <<"\n";
  std::string paramName = "@moviename";
  std::string valueName = "Forrest Gump";
  
  int index = sqlite3_bind_parameter_index(stmt, paramName.c_str());
  std::cout << "Error param index:" << sqlite3_errmsg(db)<< "\n";
  std::cout << "index is : " << index << "\n";
  
  sqlite3_bind_text(stmt, index, valueName.c_str(),valueName.length(), SQLITE_TRANSIENT);
  std::cout << "Error bind:" << sqlite3_errmsg(db)<< "\n";
  
  sqlite3_step(stmt);
  std::cout << "Error step:" << sqlite3_errmsg(db)<< "\n";
  
  std::cout << sqlite3_column_int(stmt,1) << "\n";
  std::cout << "Error column:" << sqlite3_errmsg(db)<< "\n";
}
catch(const std::exception& e)
{
  std::cerr << e.what() << '\n';
}

#endif  
    

  return 0;
}
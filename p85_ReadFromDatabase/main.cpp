#define sqlite3_api
// #define SQLiteCPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <logging.hpp>
#include <SystemInit.hpp>


#ifdef sqlite3_api
#include <databasehandler.hpp>
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
    static sqlite3_stmt *stmt;
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
      // sqlite3_reset(stmt);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    std::cout << "exception happend!\n";
  }

#endif
  SystemInit::getInstance().initializeSystem();
  update_process_name("PerformanceEValuationModule");
  LOG_error << "Fabricated Error";
  for (const auto item : movies) {
    std::cout << "\nname of movie: " << item.name << "\nyear :" << item.year
              << "\nlength: " << item.length << std::endl;
  }
  DatabaseHandler dbM("Mahdi");
  dbM.database_open();
  
    

  return 0;
}
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/name_generator.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

// Objectives of the class
// a. constructor that creats a text file in a temporary directory and opens it for writing
// b. during destruction if the file still exists, close and delete it
// c. have a method for closing the file and moving it to another dir.
// d. operator overload forwriting a message to the output file
namespace fs = std::filesystem;

class logger
{
    fs::path logpath;
    std::ofstream logfile;

public:
    logger()
    {
        auto name = boost::lexical_cast<std::string>(boost::uuids::random_generator()());
        logpath = fs::current_path() / (name + ".tmp");
        logfile.open(logpath.c_str(), std::ios::out | std::ios::trunc);
    }

    ~logger() noexcept
    {
        try
        {
            if (logfile.is_open())
            {
                logfile.close();
            }
            if (!logpath.empty())
            {
                fs::remove(logpath);
            }
        }
        catch (...)
        {
        }
    }
    void persist(fs::path const &path)
    {
        logfile.close();
        fs::rename(logpath, path);
        logpath.clear();
    }
    logger &operator<<(std::string_view message)
    {
        logfile << message.data() << '\n';
        return *this;
    }
};

int main()
{
    logger log;
    try
    {
        log << "This is a line "
            << "And this is another one";
        throw std::runtime_error("Error");
    }
    catch (...)
    {
        log.persist(R"(lastlog.txt)");
    }
    return 0;
}

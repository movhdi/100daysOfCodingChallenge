#include <iostream>
#include <regex>
#include <filesystem>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
using namespace filesystem;

static vector<pair<size_t, string>> matches(const path &p, const regex &re)
{
    vector<pair<size_t, string>> results;
    ifstream inputstream {p.c_str()};
    string s;
    for (size_t line = 1; getline(inputstream,s); ++line)
    {
        if (regex_search(s, re))
        {
            results.emplace_back(pair{line,s});
        }
    }
    return results;
}


int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " <<  argv[0] <<" <pattern>" << std::endl;
        return 1;
    }
    std::regex pattern;
    try
    {
        pattern = regex(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cout << "Invalid regular expression provided." << '\n';
        return 1;
    }

    for (const auto &entry : std::filesystem::recursive_directory_iterator{current_path().append( "../..")})
    {
        auto ms(matches(entry.path(), pattern));
        for (const auto & [lineNo, content] : ms)
        {
            std::cout << entry.path().c_str() << ": " << lineNo << " - " << content << std::endl;
        }
    }

    return 0;
}

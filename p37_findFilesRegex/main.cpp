#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <vector>


std::vector<std::filesystem::directory_entry> find_file(std::filesystem::path const &path, const std::regex &re)
{
    std::vector<std::filesystem::directory_entry> db;
    for (const auto &entry : std::filesystem::recursive_directory_iterator{path})
    {
        if (std::regex_search(entry.path().filename().string(), re))
        {
            db.emplace_back(entry);
        }
    }
    return db;
}


int main(int argc, char *argv[])
{
    namespace fs = std::filesystem;
    auto dir = fs::temp_directory_path();
    auto pattern = R"(wct[0-9a-zA-Z]{3}\.tmp)";
    const auto path = std::filesystem::current_path();


    auto files = find_file(path, std::regex{"jpg"});
    // auto files = find_file(dir, std::regex(pattern));

    for (auto const &entry : files)
    {
        std::cout << entry.path().string() << std::endl;
    }


    (void)argc;
    (void)argv;
    return 0;
}

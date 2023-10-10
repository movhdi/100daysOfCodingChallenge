#include <algorithm>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

// Each replacement consists of the pattern and its replacements

template <typename T>
static std::string replace(std::string s, const T &replacements)
{
    for (const auto &[pattern, replacement] : replacements)
    {
        s = std::regex_replace(s, pattern, replacement);
    }
    return s;
}

int main(int argc, char *argv[])
{
    if (argc < 3 || argc % 2 != 1)
    {
        std::cout << "Usage: " << argv[0] << " <pattern> <replacement> ...\n";
        return 1;
    }
    std::vector<std::pair<std::regex, std::string>> db;
    for (int i = 1; i < argc; i += 2)
    {
        db.emplace_back(std::make_pair(argv[i], argv[i + 1]));
    }
    for (const auto &entry : std::filesystem::recursive_directory_iterator{std::filesystem::current_path()})
    {
        std::filesystem::path opath(entry.path());
        std::string rname{replace(opath.filename(), db)};
        std::filesystem::path rpath(opath);
        rpath.replace_filename(rname);
        if (opath != rpath)
        {
            std::cout << opath.c_str() << "-->" << rpath.c_str() << std::endl;
            if (std::filesystem::exists(rpath))
            {
                std::cout << "Can not rename, the file already exists." << '\n';
            }
            else
            {
                std::filesystem::rename(opath, rpath);
            }
        }
    }
    return 0;
}

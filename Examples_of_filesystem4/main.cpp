#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>

// this function is recursive from inside accumulate
static size_t entry_size(const std::filesystem::directory_entry &entry)
{
    if (!entry.is_directory())
    {
        return entry.file_size();
    }
    return std::accumulate(
        std::filesystem::directory_iterator(entry),
        std::filesystem::directory_iterator(),
        0ul,
        [](size_t accum, const std::filesystem::directory_entry &e) { return accum + entry_size(e);});
}

static std::string size_string(size_t size)
{
    std::stringstream ss;
    if (size >= 1000000000)
    {
        ss << size / 1000000000 << 'G';
    }
    else if (size >= 1000000)
    {
        ss << size / 1000000 << 'M';
    }
    else if (size >= 1000)
    {
        ss << size / 1000 << 'K';
    }
    else
    {
        ss << size << 'B';
    }
    return ss.str();
}
//Disk usage counter
int main(int argc, char *argv[])
{
    auto en = std::filesystem::directory_entry(std::filesystem::current_path());
    // std::cout << en.path() << std::endl;
    // std::cout << "The size of this exercise directory is: " << entry_size(en) << std::endl;
    for (auto const &entry : std::filesystem::directory_iterator{std::filesystem::current_path()})
    {
        std::cout << std::setw(5) << std::right << size_string(entry_size(entry)) << ' ' << entry.path().filename().c_str() << std::endl;
    }

    (void)argc;
    (void)argv;
    return 0;
}

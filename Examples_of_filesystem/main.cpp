#include <algorithm>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

static std::tuple<fs::path, fs::file_status, size_t> fileinfo(const fs::directory_entry &entry)
{
    const auto fstatus(fs::status(entry));
    return {entry.path(), fstatus, !fs::is_directory(entry.path()) ? fs::file_size(entry.path()) : 0};
}

static char type_char(fs::file_status fstatus)
{
    if (fs::is_directory(fstatus))
    {
        return 'd';
    }
    else if (fs::is_symlink(fstatus))
    {
        return 'l';
    }
    else if (fs::is_character_file(fstatus))
    {
        return 'c';
    }
    else if (fs::is_block_file(fstatus))
    {
        return 'b';
    }
    else if (fs::is_fifo(fstatus))
    {
        return 'f';
    }
    else if (fs::is_socket(fstatus))
    {
        return 's';
    }
    else if (fs::is_other(fstatus))
    {
        return 'o';
    }
    else if (fs::is_regular_file(fstatus))
    {
        return 'f';
    }
    return 'f';
}


static std::string rwx(fs::perms p)
{
    auto check([p](fs::perms bit, char c) { return ((p & bit) == fs::perms::none ? '-' : c); });
    return {check(fs::perms::owner_read, 'r'),
            check(fs::perms::owner_write, 'w'),
            check(fs::perms::owner_exec, 'x'),
            check(fs::perms::group_read, 'r'),
            check(fs::perms::group_write, 'w'),
            check(fs::perms::group_exec, 'x'),
            check(fs::perms::others_read, 'r'),
            check(fs::perms::others_write, 'w'),
            check(fs::perms::others_exec, 'x')};
}

static std::string size_string(size_t size)
{
    std::stringstream ss;
    if (size >= 1000000000ul)
    {
        ss << size / 1000000000ul << 'G';
    }
    else if (size >= 1000000ul)
    {
        ss << size / 1000000ul << 'M';
    }
    else
    {
        ss << size / 1000 << 'K';
    }
    return ss.str();
}


int main(int argc, char * argv[])
{
    fs::path dir;
    if(argc > 1 )
    {
        dir = argv[1];
    }else
    {
        dir = ".";
    }

    if (!fs::exists(dir))
    {
        std::cout << "The path does not exist" << std::endl;
        return 1;
    }
    std::vector<std::tuple<fs::path, fs::file_status, size_t>> fileInfoBank;
    // Transform: applies an operation sequentially (here "fileinfo" function) and stores the value returned
    // by each operation in the range that begins at result
    std::transform(fs::begin(fs::directory_iterator(dir)),fs::end(fs::directory_iterator(dir)), std::back_inserter(fileInfoBank),fileinfo);
    for (const auto &[path, status, size] : fileInfoBank)
    {
        std::cout << type_char(status) << rwx(status.permissions()) << " " << std::setw(4) << std::right
                  << size_string(size) << " " << path.filename().c_str() << '\n';
    }

    return 0;
}

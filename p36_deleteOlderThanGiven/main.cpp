#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <mutex>
#include <numeric>
#include <string>

namespace fs = std::filesystem;
namespace ch = std::chrono;
/*
    These two functions are meant to take an int representing hour as input!
*/
bool is_younger_than(fs::path const &path, int const duration)
{
    bool is_older{false};
    auto now = fs::file_time_type::clock::now();
    is_older = (ch::duration_cast<ch::hours>(now - fs::last_write_time(path))).count() < duration;
    return is_older;
}

template <typename Duration>
bool is_older_than(fs::path const &path, Duration const duration)
{
    auto ftimeduration = fs::last_write_time(path).time_since_epoch();
    auto nowduration = (ch::system_clock::now() - duration).time_since_epoch();
    return ch::duration_cast<Duration>(nowduration - ftimeduration).count() > 0;
}

template <typename Duration>
void remove_files_older_than(fs::path const & path,Duration const duration)
{
    try
    {
        if (fs::exists(path))
        {
            if (is_older_than(path, duration))
            {
                fs::remove(path);
            }
            else if (fs::is_directory(path))
            {
                for (auto const &entry : fs::directory_iterator(path))
                {
                    remove_files_older_than(entry.path(), duration);
                }
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}


int main()
{
    using namespace std::chrono_literals;
    auto tmp = fs::temp_directory_path();
    fs::create_directories(tmp / "abeC/example/mahdi");
    remove_files_older_than(tmp / "abeC/", 1min);
    return 0;
}

#include <filesystem>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>


using namespace std;
using namespace filesystem;

static string string_size(size_t size)
{
    stringstream ss;
    if (size >= 1000000000ul)
    {
        ss << size / 1000000000 << 'G';
    }
    else if (size >= 1000000)
    {
        ss << size / 1000000ul << 'M';
    }
    else if (size >= 1000ul)
    {
        ss << size / 1000 << 'K';
    }
    else
    {
        ss << size << 'B';
    }
    return ss.str();
}

static map<string, pair<size_t, size_t>> ext_stats(path dir)
{
    map<string, pair<size_t, size_t>> result;
    for (auto const &entry : recursive_directory_iterator{dir})
    {
        if (!entry.is_directory())
        {
            if (!entry.path().has_extension())
            {
                continue;
            }

            auto size = entry.file_size();
            auto ext = entry.path().extension().string();
            auto mem = result[ext];
            result[ext] = {get<0>(mem) + size, get<1>(mem) + 1};
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    for (auto const &entry : ext_stats(current_path()))
    {
        cout << "Extension: " << setw(6) << right << entry.first << "  has total size of: " << setw(8) << right
             << string_size(entry.second.first) << "  with a number of: " << entry.second.second << " files" << endl;
    }

    (void)argc;
    (void)argv;
    return 0;
}

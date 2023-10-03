#include <algorithm>
#include <fstream>
#include <filesystem>
#include <string>
#include <streambuf>
#include <cassert>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <array>
#include <mutex>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <iterator>
/*
        The objective is to calculate the size of a directory.
        note: There is a subtle difference between the two method when calculating the directory of this same excersie
        This is because the volume of the code itself differes in fact!!
*/
// #define Mymethod

namespace fs = std::filesystem;

size_t calculate_size(fs::path const & directory)
{
    fs::recursive_directory_iterator it(directory);
#ifdef Mymethod
    size_t size{0};
    for (; it != fs::recursive_directory_iterator(); it++)
    {
        // std::cout << *it << '\n';
        if (!fs::is_directory(*it))
        {
            size += fs::file_size(*it);
        }
        // std::cout << "accumulated size: " << size << " B" << std::string(2,'\n');
    }
    return size;
#else
    // we use accumulate algorithm here
    return std::accumulate(fs::begin(it),
                           fs::end(it),
                           (size_t) 0,
                           [](size_t total, fs::directory_entry entry) {
                               return total + (!fs::is_directory(entry) ? fs::file_size(entry.path()) : 0);
                           });
#endif
}

int main()
{
    fs::path path("/home/med/100daysOfCodingChallenge");
    auto size = calculate_size(path);
    std::cout << "the final size is: "<< size << " Bytes" << std::endl;

    return 0;
}

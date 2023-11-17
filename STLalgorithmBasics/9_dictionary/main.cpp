#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>

using dict_entry = std::pair<std::string, std::string>;


namespace std
{
std::ostream &operator<<(std::ostream &os, const dict_entry a)
{
    return os << a.first << " " << a.second;
}

std::istream &operator>>(std::istream &is, dict_entry &a)
{
    return is >> a.first >> a.second;
}
} // namespace std


template <typename IS>
std::deque<dict_entry> from_instream(IS &&is)
{
    std::deque<dict_entry> result{std::istream_iterator<dict_entry>{is}, {}};
    std::sort(std::begin(result), std::end(result));
    return result;
}


int main()
{
    const auto dict1(from_instream(std::ifstream{"dict.txt"}));
    const auto dict2(from_instream(std::cin));
    std::merge(std::begin(dict1),
               std::end(dict1),
               std::begin(dict2),
               std::end(dict2),
               std::ostream_iterator<dict_entry>{std::cout, "\n"});

    return 0;
}

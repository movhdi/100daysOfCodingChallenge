// #include <iostream>
// #include <fstream>
// #include <deque>
// #include <algorithm>
// #include <iterator>

// namespace MyCustomNamespace {
//     struct dict_entry {
//         std::string first;
//         std::string second;

//         // Define a custom comparison operator for sorting
//         bool operator<(const dict_entry& other) const {
//             return std::tie(first, second) < std::tie(other.first, other.second);
//         }
//     };

//     std::ostream &operator<<(std::ostream &os, const dict_entry &a) {
//         return os << a.first << " " << a.second;
//     }

//     std::istream &operator>>(std::istream &is, dict_entry &a) {
//         return is >> a.first >> a.second;
//     }
// }

// using namespace MyCustomNamespace;

// template <typename IS>
// std::deque<dict_entry> from_instream(IS &&is) {
//     std::deque<dict_entry> result{std::istream_iterator<dict_entry>{is}, {}};
//     std::sort(std::begin(result), std::end(result));
//     return result;
// }

// int main() {
//     const auto dict1(from_instream(std::ifstream{"dict.txt"}));
//     const auto dict2(from_instream(std::cin));
//     std::merge(std::begin(dict1),
//                std::end(dict1),
//                std::begin(dict2),
//                std::end(dict2),
//                std::ostream_iterator<dict_entry>{std::cout});

//     return 0;
// }
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


std::ostream &operator<<(std::ostream &os, const dict_entry &a)
{
    return os << a.first << " " << a.second;
}

std::istream &operator>>(std::istream &is, dict_entry &a)
{
    return is >> a.first >> a.second;
}
bool operator<(const dict_entry &lhs, const dict_entry &rhs)
{
    return lhs.first < rhs.first;
}
bool operator>(const dict_entry &lhs, const dict_entry &rhs)
{
    return lhs.first > rhs.first;
}
bool operator!=(const dict_entry &lhs, const dict_entry &rhs)
{
    return (lhs.first != rhs.first && lhs.second != rhs.second);
}
bool operator==(const dict_entry &lhs, const dict_entry &rhs)
{
    return !(lhs != rhs);
}

} // namespace myCustomNamespace
// using namespace myCustomNamespace;
template <typename IS>
std::deque<dict_entry> from_instream(IS &&is)
{
    std::deque<dict_entry> result{std::istream_iterator<dict_entry>{is}, {}};
    std::sort(std::begin(result), std::end(result), [&](const dict_entry &lhs, const dict_entry &rhs) -> bool {
        return lhs.first < rhs.first;
    });
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

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <tuple>
#include <vector>


namespace std
{
std::ostream &operator<<(std::ostream &os, const std::pair<int, std::string> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

} // namespace std


int main()
{
    std::vector<std::pair<int, std::string>> v{{1, "one"},
                                               {2, "two"},
                                               {3, "three"},
                                               {4, "four"},
                                               {5, "five"},
                                               {6, "six"}};
    std::map<int, std::string> m;
    std::copy_n(std::begin(v), 3, std::inserter(m, std::begin(m)));
    std::copy(std::begin(m), std::end(m), std::ostream_iterator<std::pair<int, std::string>>{std::cout, ", "});
    std::cout << std::endl;
    m.clear();
    std::move(std::begin(v),std::end(v), std::inserter(m, std::begin(m)));
    std::copy(std::begin(m),std::end(m), std::ostream_iterator<std::pair<int, std::string>>{std::cout , ", "});
    std::cout << std::endl;
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<std::pair<int, std::string>>{std::cout , ", "});
    std::cout << std::endl;
    return 0;
}

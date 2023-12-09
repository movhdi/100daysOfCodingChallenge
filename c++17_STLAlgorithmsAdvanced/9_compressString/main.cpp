#include <string>
#include <string_view>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <tuple>

// occurrence
template <typename It>
std::tuple<It, char, size_t> occurrence(It it, It end)
{
    if (it == end)
    {
        return {it, '?', 0};
    }
    char c{*it};
    const auto diff(std::find_if(it, end, [c](char x){
        return x != c;
    }));
    return {diff, c, std::distance(it, diff)};
}

// compress
std::string compress(const std::string &s)
{
    const auto end_it(std::end(s));
    std::stringstream r;

    for (auto it(std::begin(s)); it != end_it;)
    {
        const auto [diff, c, n] = occurrence(it, end_it);
        r << c << n;
        it = diff;
    }
    return r.str();
}

// decompress
std::string decompress(std::string &s)
{
    std::stringstream ss{s.data()};
    char c;
    size_t n;
    std::string result{};
    while (ss >> c >> n)
    {
        result = result + std::string(n,c);
    }
    return result;
}

int main()
{
    std::string s {"a7b8c2q10d12"};
    std::cout << decompress(s) << std::endl;
    std::cout << compress(decompress(s)) << '\n';
}

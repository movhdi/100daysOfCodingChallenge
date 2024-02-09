#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <map>
#include <algorithm>
#include <numeric>

std::map<char, double> analyze_text(std::string_view str)
{
    std::map<char, double> result;
    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        result[ch] = 0;
    }

    for (const auto &ch : str)
    {
        if (std::isalpha(ch))
        {
            ++result[std::tolower(ch)];
        }
    }
    auto totalCount = std::accumulate(std::begin(result), std::end(result), 0.0, [](double total, std::pair<char, double> const &p)
                                      { return total + static_cast<double>(p.second); });
    std::for_each(std::begin(result), std::end(result),
                  [totalCount](std::pair<const char, double> &p) { // I do not why, but if I remove const before char, does not compile
                      p.second = (100.0 * p.second) / totalCount;
                  });
    return result;
}

using namespace std::string_literals;
int main()
{
    auto result = analyze_text(R"(Lorem ipsum dolor sit amet, consectetur adipiscing elit,
                                  sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.))");
    for (auto const &kvp : result)
    {
        std::cout << kvp.first << " : "
                  << std::fixed
                  << std::setw(5) << std::setfill(' ')
                  << std::setprecision(2) << kvp.second << std::endl;
    }
}
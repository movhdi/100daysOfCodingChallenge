#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

struct billionaire
{
    std::string name;
    double dollars;
    std::string country;
};

int main()
{
    std::list<billionaire> billionaires{{"Bill Gates", 86.0, "USA"},
                                        {"Warren Buffet", 75.6, "USA"},
                                        {"Jeff Bezos", 72.8, "USA"},
                                        {"Amancio Ortega", 71.3, "Spain"},
                                        {"Mark Zuckerberg", 56.0, "USA"},
                                        {"Carlos Slim", 54.5, "Mexico"},
                                        {"Bernard Alrnault", 41.5, "France"},
                                        {"Lillian Bettencourt", 39.5, "France"},
                                        {"Wang Jianlin", 31.3, "China"},
                                        {"Li ka-shing", 31.2, "Hong Kong"}};
    std::map<std::string, std::pair<const billionaire, size_t>> m;
    for (const auto &b : billionaires)
    {
        auto [iterator, success] = m.try_emplace(b.country, b, 1);
        if (!success)
        {
            iterator->second.second += 1;
        }
    }

    for (const auto &[key, value] : m)
    {
        const auto &[b, count] = value;
        std::cout << b.country << " : " << count << " Billionaires. richest is " << b.name << " with " << b.dollars
                  << "b$\n";
    }

    return 0;
}

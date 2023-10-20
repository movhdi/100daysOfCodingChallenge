#include <iostream>
#include <map>
#include <numeric>
#include <algorithm>
#include <list>
#include <string>

int main()
{
    std::map<std::string, size_t> m{{"b",1},{"c",2},{"d",3}};
    auto insert_it = m.end();
    for (const auto &s : {"z","y","x", "w"})
    {
        insert_it = m.insert(insert_it, {s, 1});
    }

    m.insert(std::end(m), {"a",1});

    for (const auto &s : m)
    {
        std::cout << "\"" << s.first << "\": " << s.second << "," ;
    }

    std::cout << std::endl;
    // or
    for (const auto &[letter, count] : m)
    {
        std::cout << "\"" << letter << "\": " << count << ",";
    }

    std::cout << std::endl;

    return 0;
}

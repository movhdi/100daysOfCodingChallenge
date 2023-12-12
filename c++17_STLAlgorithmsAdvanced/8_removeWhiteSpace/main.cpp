#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

template <typename It>
It remove_whiteSpace(It it, It end)
{
    return std::unique(it, end, [](char a, char b){return std::isspace(a) && std::isspace(b);});
}

int main()
{
    std::string s{"foo        bar    \t       baz"};
    std::cout << s << '\n';
    s.erase(remove_whiteSpace(std::begin(s), std::end(s)), std::end(s));
    std::cout << s << '\n';
    return 0;
}

#include <algorithm>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>

std::optional<std::string> trim_whitespace_surrounding(const std::string &s)
{
    std::string whitspace{" \t\n"};
    const auto first(s.find_first_not_of(whitspace));
    if (first == std::string::npos)
    {
        return {};
    }

    const auto last(s.find_last_not_of(whitspace));
    return s.substr(first, (last - first) + 1);
}
std::ostream &operator<<(std::ostream &os, std::optional<std::string> const &s)
{
    return s.has_value() ? os << s.value() : os;
}

int main()
{
    std::string s{" \t\n string surrounded by ugly"
                  " whitespace \t\n"};
    std::cout << "{" << s << "}" << '\n';
    std::cout << "{" << trim_whitespace_surrounding(s) << "}\n";
    std::cout << "{" << trim_whitespace_surrounding("") << "}\n";
    return 0;
}

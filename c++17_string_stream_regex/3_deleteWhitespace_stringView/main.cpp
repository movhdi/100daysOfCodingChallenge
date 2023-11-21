#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>

void print(std::string_view sv)
{
    std::string whitspace{" \t\n"};
    const auto first(sv.find_first_not_of(whitspace));
    sv.remove_prefix(first == std::string_view::npos ? 0 : first); // the main solution was std::min(first, sv.size())
                                                                   // I made up my own solution! it seems odd!
    const auto last(sv.find_last_not_of(whitspace));
    if (last != std::string_view::npos)
    {
        sv.remove_suffix(sv.size() - last -1);
    }
    std::cout << "length:" << sv.length() << " [" << sv << "]" << '\n';
}


int main(int argc, char * argv[])
{
    using std::string_literals::operator""s;
    using std::string_view_literals::operator""sv;
    print(argv[0]);
    print({});
    print("a const char * array");
    print("an std::string_view literal"sv);
    print("an std::string instance"s);
    print(" \t\n foobar \n \t ");
    char c_str[] {'a', 'b' , 'c'};
    print(std::string_view(c_str, sizeof(c_str)));
    (void) argc;
    return 0;
}

#include <regex>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>


template <typename InputIt>
void print(InputIt it, InputIt endIt)
{
    for (;it != endIt;it++)
    {
        const std::string link {*it};
        const std::string desc {*++it};
        if (it == endIt)
        {
            break;
        }
        std::cout << std::left << std::setw(28) << desc << " : "<< link << '\n';
    }
}


int main()
{
    std::cin >> std::noskipws;
    const std::string in{std::istream_iterator<char>{std::cin} , {}};
    const std::regex link_re {"<a href=\"([^\"]*)\"[^<]*>([^<]*)</a>"};
    std::sregex_token_iterator it{std::begin(in), std::end(in), link_re, {1,2}};
    print(it, {});
}
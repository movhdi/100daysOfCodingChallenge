#include <regex>
#include <mutex>
#include <string>
#include <streambuf>
#include <iomanip>
#include <iostream>
#include <cassert>
#include <string_view>
#include <cmath>

std::string convert_date(std::string_view text)
{
        std::regex rx("(\\d{1,2})(\\.|-|\\/)(\\d{1,2})(\\.|-|\\/)(\\d{4})");
        return std::regex_replace(text.data(), rx, "$5-$3-$1");
}

int main()
{
    using namespace std::string_literals;

    std::cout << convert_date("today is 31.02.2005!"s) << std::endl;
    assert(convert_date("today is 31.02.2005!"s) == "today is 2005-02-31!"s);
    return 0;
}

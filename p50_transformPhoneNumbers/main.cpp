#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iomanip>
#include <string>
#include <string_view>
#include <cctype>


bool starts_with(std::string_view str, std::string_view prefix)
{
    return str.find(prefix) == 0;
}

std::vector<std::string> normalize_phone_numbers(std::vector<std::string> &numbers, std::string const &countryCode)
{
    std::transform(std::cbegin(numbers), std::cend(numbers), std::begin(numbers), [&countryCode](std::string str){
        str.erase(std::remove_if(std::begin(str), std::end(str), [](char const &ch){
            return std::isspace(ch);
        }),std::end(str));
        if (starts_with(str, countryCode))
        {
            return '+' + str;
        }
        else if (starts_with(str, '+' + countryCode))
        {
            return str;
        }
        else if (starts_with(str,std::to_string(0)))
        {
            return '+' + countryCode + str.substr(1,std::string::npos);
        } 
        else
        {
            return '+' + countryCode + str;
        }
    });
    return numbers;
}


int main()
{
    std::vector<std::string> numbers{
        "07555 123456",
        "07555123456",
        "+44 7555 123456",
        "44 7555 123456",
        "7555 123456"};
    normalize_phone_numbers(numbers, "44");
    for (auto const &number : numbers)
    {
        std::cout << number << std::endl;
    }
}
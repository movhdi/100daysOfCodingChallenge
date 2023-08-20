#include <regex>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cassert>
#include <string_view>

std::string longest_palindrome(std::string_view text)
{
    size_t const len = text.size();
    std::vector<bool> table;
    // setting all [i,i] elements true
    for(size_t i{}; i < len ; i++)
    {
        table.push_back(true);
    }
    // setting elements [i,i+1] true for two character palindromes (consecutive two identical characters)
    for(size_t i{}; i < len - 1 ; i++)
    {
        if(text[i] == text[i+1])
        {
            table[i*len + i + 1] = true;
        }
    }

    return std::string(text.substr(1,2));
}

int main()
{
    using namespace std::string_literals;
    assert(longest_palindrome("sahararahnide") == "hararah");
    assert(longest_palindrome("level") == "level");
    assert(longest_palindrome("s") == "s");
}

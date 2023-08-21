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
    size_t maxlen = 1;
    size_t longestbegin{};
    // the element at [i, j] indicates whether the substring from position i to j is a palindrome.
    std::vector<bool> table(len*len,false);

    // Requirement 1
    // setting all [i,i] elements true
    for(size_t i{}; i < len ; i++)
    {
        table[ i*len + i ] = true;
    }
    // Requirement 2
    // setting elements [i,i+1] true for two character palindromes (consecutive two identical characters)
    for(size_t i{}; i < len - 1 ; i++)
    {
        if(text[i] == text[i+1])
        {
            table[i*len + i + 1] = true;
            if(maxlen < 2 )
            {
                longestbegin = i;
                maxlen = 2;
            }
        }
    }
    // Requirement 3
    // setting the element at [i,j] to true if the
    // element at [i+1,j-1] is true and the characters on the positions i and j in the string are
    // also equal.
    for(size_t k{3}; k <= len ; k++ )
    {
        for(size_t j{}; j <= len - k ; j++)
        {
            size_t i = j + k -1;
            if(text[i] == text[j] && table[(j+1)*len + i - 1])
            {
                table[j*len + i] = true;
                if(maxlen < k)
                {
                    longestbegin = j;
                    maxlen = k;
                }
            }
        }
    }
    // returning garbage but without error (for now)
    return std::string(text.substr(longestbegin,maxlen));
}

int main()
{
    using namespace std::string_literals;
    assert(longest_palindrome("sahararahnide") == "hararah");
    assert(longest_palindrome("level") == "level");
    assert(longest_palindrome("s") == "s");
}

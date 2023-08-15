#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <set>
#include <iterator>
#include <algorithm>
#include <cassert>
/*
p24: Write a function that, given a string containing hexadecimal digits as the input argument,
returns a vector of 8-bit integers that represent the numerical deserialization of the string
content. The following are examples:
Input: "BAADF00D" or "baadF00D" , output: {0xBA, 0xAD, 0xF0, 0x0D}
Input "010203040506" , output: {1, 2, 3, 4, 5, 6}
*/
unsigned char char_to_int(char const a)
{
    if(a >= '0' && a <= '9')
    {
        return a - '0';
    }
    if(a >= 'A' && a <= 'F')
    {
        return a - 'A' + 10;
    }
    if(a >= 'a' && a <= 'f')
    {
        return a - 'a' + 10;
    }
    throw std::invalid_argument("Invalid Argument inserted!\n");
}
std::vector<unsigned char> string_to_bytes(std::string str)
{
    std::vector<unsigned char> vec;
    size_t i = 0;
    for(;i < str.size(); i=i+2)
    {
        vec.emplace_back(
            (char_to_int(str[i]) << 4) | char_to_int(str[i+1]));
    }
    return vec;
}
int main()
{
    std::vector<unsigned char> expected{ 0xBA, 0xAD, 0xF0, 0x0D, 0x42 };
    assert(string_to_bytes("BAADF00D42") == expected);
    assert(string_to_bytes("BaaDf00d42") == expected);
    return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cassert>

std::string join_strings(std::vector<std::string> const & text, std::string const & delimiter)
{
    std::string result;
    for(auto it : text)
    {
        result += it;
        result += delimiter;
    }
    return result;
}
int main()
{
    using namespace std::string_literals;
    std::vector<std::string> v1{ "this","is","an","example" };
    std::vector<std::string> v2{ "example" };
    std::vector<std::string> v3{ };
    std::cout << join_strings(v1, " ") << std::endl;
    std::cout << join_strings(v2, " ") << std::endl; 
    std::cout << join_strings(v3, " ") << std::endl; 

    assert(join_strings(v1, " ") == "this is an example");
    assert(join_strings(v2, " ") == "example");
    assert(join_strings(v3, " ") == "");
    return 0;
}
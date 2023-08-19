#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cassert>


std::vector<std::string> tokenize(std::string text, std::string const & delimiters)
{
    std::vector<std::string> result;
    size_t pos{};
    while((pos = text.find_first_of(delimiters)) != std::string::npos)
    {
        if(pos > 0)
        {
            result.push_back(static_cast<std::string> (text.substr(0,pos)));
        }
        text.erase(0,pos+1);
    }
    if(text.size())
    {
        result.push_back(text);
    }
    
    return result;
}


int main()
{
    using namespace std::string_literals;
    std::vector<std::string> expected{"this", "is", "a", "sample"};
    std::vector<std::string> diff;
    auto a = tokenize("this is a sample"s, " "s);
    for(auto it : a)
    {
        std::cout << it << " "; 
    }
    std::cout << std::endl;

    auto b = tokenize("this,is a.sample!!"s, ",.! "s);
    for(auto it : b)
    {
        std::cout << it << " "; 
    }
    std::cout << std::endl;
    std::cout << expected.size() << " " << a.size() << " " << b.size() << std::endl;
    std::cout << std::endl;
    std::set_difference(b.begin(), b.end(), expected.begin(), expected.end(), std::inserter(diff, diff.begin()));
    std::cout << diff.size() << std::endl;
    for(auto it : diff)
    {
        std::cout << static_cast<int> (it[2]) << "///"s; 
    }

    assert(expected == tokenize("this is a sample"s, " "s));
    assert(expected == tokenize("this,is a.sample!!"s, ",.! "s));
    return 0;
}
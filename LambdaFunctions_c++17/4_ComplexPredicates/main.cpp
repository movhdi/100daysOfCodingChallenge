#include <iostream>
#include <functional>
#include <string>
#include <iterator>
#include <algorithm>

static bool begins_with_a(const std::string &str)
{
    return str.find("a") == 0;
}
static bool ends_with_b(const std::string &str)
{
    return str.rfind("b") == str.length() - 1;
}

template<typename A, typename B, typename F>
auto combine(F binary_Function, A a, B b)
{
    return [=](auto param){return binary_Function(a(param), b(param));};
}

int main()
{
    auto a_star_b (combine(std::logical_and<>{},begins_with_a,ends_with_b));
    std::copy_if(std::istream_iterator<std::string>{std::cin},{},std::ostream_iterator<std::string>{std::cout, ", "},a_star_b);
    std::cout << std::endl;
    return 0;
}

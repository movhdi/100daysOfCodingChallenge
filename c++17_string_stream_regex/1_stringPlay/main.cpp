#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <algorithm>
#include <iterator>
int main()
{
    using std::string_literals::operator""s;
    using std::string_view_literals::operator""sv;
    std::string a{"a"};
    auto b = "b"s;
    std::string_view c{"c"};
    auto d("d"sv);
    std::ostringstream ssr;
    ssr << a << " " << b << " " << c << " " << d;
    std::cout <<ssr.str() << '\n';
    auto cat(ssr.str());
    std::transform(std::begin(cat), std::end(cat), std::begin(cat),::toupper); //weird!
                                                           //Here, ::toupper is used as a function pointer, and
                                                           //it's passed as the unary operation to std::transform.
                                                           //The :: ensures that it's looked up in the global scope,
                                                           //not in any specific namespace.
    std::transform(std::begin(cat), std::end(cat), std::begin(cat),[](unsigned char character){return std::toupper(character);});
    std::copy(std::begin(cat),std::end(cat), std::ostream_iterator<char>{std::cout});
    std::cout << '\n';
    std::cout << cat;
    std::cout << '\n';
    return 0;
}

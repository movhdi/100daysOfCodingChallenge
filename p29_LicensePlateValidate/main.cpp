#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <string>
#include <vector>
#include <string_view>
#include <regex>

bool validate_license_plate_format(std::string_view str)
{
    bool is_valid{};
    std::regex rx(R"([A-Z]{3}-[A-Z]{2} \d{3,4})");
    is_valid = std::regex_match(str.data(),rx,std::regex_constants::match_any);
    return is_valid;
}


std::vector<std::string> extract_license_plate_numbers(std::string str)
{
    std::vector<std::string> result;
    std::regex rx(R"(([A-Z]{3}-[A-Z]{2} \d{3,4}))");
    std::regex_iterator<std::string::iterator> rit ( str.begin(), str.end(), rx);
    std::regex_iterator<std::string::iterator> rend;

    // while (rit!=rend) {
    //     std::cout << rit->str() << std::endl;
    //     if((*rit)[1].matched) result.push_back(rit->str());
    //     ++rit;
    // }
    std::smatch sm;
    while(std::regex_search(str, sm, rx,std::regex_constants::match_any))
    {
        std::cout << sm.str(0) << std::endl;
        result.push_back(sm.str(0));
        str = sm.suffix().str();
    }


    // for(unsigned int i = 0 ; i < sm.size() ; i++)
    // {
    //     std::cout <<"match " << i << "(" << sm[i] << ")";
    //     std::cout << "at position " << sm.position(i) << std::endl;
    // }
    return result;
}


int main()
{
    assert(validate_license_plate_format("ABC-DE 123"));
    assert(validate_license_plate_format("ABC-DE 1234"));
    assert(!validate_license_plate_format("ABC-DE 12345"));
    assert(!validate_license_plate_format("abc-de 1234"));

    std::vector<std::string> expected {"AAA-AA 123", "ABC-DE 1234", "XYZ-WW 0001"};
    std::string text("AAA-AA 123qwe-ty 1234 ABC-DE 123456..XYZ-WW 0001");
    assert(expected == extract_license_plate_numbers(text));
}

// int main()
// {
//     std::vector<std::string> expected {
//     "AAA-AA 123", "ABC-DE 1234", "XYZ-WW 0001"};.

//     std::string text("AAA-AA 123qwe-ty 1234 ABC-DE 123456..XYZ-WW 0001");
//     assert(expected == extract_license_plate_numbers(text));
// }

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
int main()
{
    assert(validate_license_plate_format("ABC-DE 123"));
    assert(validate_license_plate_format("ABC-DE 1234"));
    assert(!validate_license_plate_format("ABC-DE 12345"));
    assert(!validate_license_plate_format("abc-de 1234"));
}

// int main()
// {
//     std::vector<std::string> expected {
//     "AAA-AA 123", "ABC-DE 1234", "XYZ-WW 0001"};.

//     std::string text("AAA-AA 123qwe-ty 1234 ABC-DE 123456..XYZ-WW 0001");
//     assert(expected == extract_license_plate_numbers(text));
// }

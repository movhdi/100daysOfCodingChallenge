#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::transform(std::begin(vec), std::end(vec), std::ostream_iterator<int>{std::cout, ", "}, [](int i) -> int {
        return i * i;
    });
    std::cout << '\n';
    auto int_to_string([](int i) { return std::to_string(i); });
    auto int_to_string2([](int i) {
        std::stringstream ss;
        ss << i << "^2 = " << i * i << '\n';
        return ss.str();
    });
    std::vector<std::string> vec2;
    std::transform(std::begin(vec), std::end(vec), std::ostream_iterator<std::string>{std::cout}, int_to_string2);
    std::transform(std::begin(vec), std::end(vec), std::back_inserter<std::vector<std::string>>(vec2), int_to_string2);
    std::cout << std::endl;
    std::copy(std::begin(vec2), std::end(vec2), std::ostream_iterator<std::string>{std::cout});
    std::cout << std::endl;
    return 0;
}

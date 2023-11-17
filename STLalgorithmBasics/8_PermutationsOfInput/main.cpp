#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


int main()
{
    std::vector<std::string> data{
        std::istream_iterator<std::string>{std::cin},
        {}}; // construct by range the end of the range could also be: std::istream_iterator<std::string>()
    std::sort(std::begin(data), std::end(data));
    while (std::next_permutation(std::begin(data), std::end(data)))
    {
        std::copy(std::begin(data), std::end(data), std::ostream_iterator<std::string>{std::cout, ", "});
        std::cout << std::endl;
    }
    return 0;
}

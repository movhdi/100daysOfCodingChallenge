#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

std::vector<std::string> filter_numbers(std::vector<std::string> const &nums, std::string const code)
{
    std::vector<std::string> result;
    std::copy_if(std::begin(nums), std::end(nums), std::back_inserter(result), [&code](std::string const & str){
        auto charCount = std::accumulate(std::begin(str), std::end(str), 0ull, [&code](int count, const char & ch){
            if (std::isalnum(ch))
            {
                return ++count;
            }else
            {
                return count;
            }
        });
        if (charCount == 12)
        {
            if (auto pos = str.find_first_of('+'); pos == static_cast<std::string::size_type>(0))
            {
                if (str.substr(1,2) == code)
                {
                    return true;
                }
            }else if(pos == std::string::npos)
            {
                if (str.substr(0,2) == code)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    });
    return result;
}

int main()
{
    std::vector<std::string> numbers{
        "+40744909080",
        "44 7520 112233",
        "+44 7555 123456",
        "40 7200 123456",
        "7555 123456"
    };
    auto result = filter_numbers(numbers, "44");

    for (auto const &number : result)
    {
        std::cout << number << std::endl;
    }
    
}
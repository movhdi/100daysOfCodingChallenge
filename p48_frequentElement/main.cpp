#include <functional>
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <optional>

template <typename T>
std::vector<std::pair<T, int>> mostFrequentElement(std::vector<T> const &vec)
{
    std::map<T, int> elementsNumbers;
    for (auto const &elem : vec)
    {
        ++elementsNumbers[elem];
    }

    auto resultIt = std::max_element(std::begin(elementsNumbers), std::end(elementsNumbers),
                                     [](std::pair<T, int> const &p1, std::pair<T, int> const &p2)
                                     { return p1.second < p2.second; });
    auto maxFrequency = (*resultIt).second;
    std::vector<std::pair<T, int>> retVal;
    std::copy_if(std::begin(elementsNumbers), std::end(elementsNumbers), std::back_inserter(retVal), [&maxFrequency](std::pair<T, int> const &p){
        return p.second == maxFrequency;
    });

    return retVal;
}

int main()
{
    std::vector<int> vector{1, 1, 1, 2, 3, 4, 4, 5, 5, 5, 6, 7, 8, 8, 10};
    auto maxElement = mostFrequentElement(vector);
    for (auto &it : maxElement)
    {
        std::cout << "{" << it.first << ", " << it.second << "}" << std::endl;
    }
    return 0;
}
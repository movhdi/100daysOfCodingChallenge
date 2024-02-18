#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <tuple>

template<typename T>
auto pairwiseAlgo(T con)
{
    // pseudocode:
    // for (iterator = first ; std::next(iterator) = con.end() ; iterator+= 2 )
    // auto pair = std::make_pair(iterator.get(), std::next(iterator).get())
    using pairType =  std::pair<typename T::value_type, typename T::value_type>;
    std::vector<pairType> result;
    for (auto it = std::begin(con); it != std::end(con); it+=2)
    {
        if (std::next(it) != std::end(con))
        {
            auto pair = std::make_pair(*it, *(it+1));
            result.emplace_back(pair);
        }else
        {
            break;
        }
    }
    return result;
}

int main()
{
    std::vector<int> vec{1, 1, 4, 8, 5, 3, 6};
    auto result = pairwiseAlgo(vec);
    for (auto const &it : result)
    {
        std::cout << "{" << it.first << "," << it.second << "}" << std::endl;
    }

    return 0;
}

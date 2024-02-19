#include <iostream>
#include <vector>

template<typename It1, typename It2, typename Oit>
auto zipElement(It1 it1, It1 endit1, It2 it2, It2 endit2,  Oit backinserteriterator)
{
    while (it1 != endit1 && it2 != endit2)
    {
        ++backinserteriterator = {*it1++,*it2++};
    }
}

template<typename T, typename U>
auto zip(std::vector<T> v1, std::vector<U> v2)
{
    std::vector<std::pair<T,U>> result;
    zipElement(std::begin(v1), std::end(v1), std::begin(v2), std::end(v2), std::back_inserter(result));

    return result;
}

int main()
{
    std::vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> v2 {1, 1, 3, 5, 8, 13, 21};
    auto result = zip(v1,v2);
    for (auto const & p : result)
    {
        std::cout << '{' << p.first << ',' << p.second << '}' << std::endl;
    }
}
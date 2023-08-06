#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <array>
#include <cassert>
#include <list>
#include <algorithm>


template <typename C, typename... Args>
bool contains_any(C& container, Args&&... args)
{
    return (... || (std::find(container.begin(), container.end(),args) != container.end()));
}

template <typename C, typename... Args>
bool contains_all(C& container, Args&&... args)
{
    return (... && (std::find(container.begin(), container.end(),args) != container.end()));
}

template <typename C, typename... Args>
bool contains_none(C& container, Args&&... args)
{
    return !(... || (std::find(container.begin(), container.end(),args) != container.end()));
}

int main()
{
    std::vector<int> v {1,2,3,4,5,6};
    assert(contains_any(v,3,5));
    
    std::array<int, 6> a{{1,2,3,4,5,6}};
    assert(contains_all(a,1,3,5,6));

    std::list<int> l {1,2,3,4,5,6};
    assert(!contains_none(l, 0,6));
    
    return 0;
}
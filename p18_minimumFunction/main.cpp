#include <iostream>
#include <cstdlib>

template <typename T>

T minimum(T const a, T const b)
{
    if(a < b)
    {
        return a;
    }else
    {
        return b;
    }
}

template <typename T1, typename... T>
T1 minimum(T1 a, T... args)
{
    return minimum(a,minimum(args...));
}

template <class compare, typename T>
T minimumc(compare comp, T const a, T const b)
{
    return comp(a,b) ? a : b;
}

template <class compare, typename T1 , typename... T>
T1 minimumc(compare comp, T1 a, T... args)
{
    return minimumc(comp, a, minimumc(comp,args...));
}
int main()
{
    auto x = minimum(5,6,9,4,9999);
    std::cout << x << std::endl;
    auto y = minimumc(std::less<>(), 3,2,10000,9999);
    std::cout << y << std::endl;
    return 0;
}

/* Moral of the story
    This excercise was a little bit hard for me, because I had no experience with recursion adn variadic funcitons
*/
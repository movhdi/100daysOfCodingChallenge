#include <functional>
#include <iostream>
#include <string>

template <typename T, typename... TS>
auto concat(T t, TS... ts)
{
    if constexpr (sizeof...(ts) > 0)
    /*
        In C++, constexpr is used to indicate that an expression or a block of code can be evaluated at compile time.
        In this particular code, the usage of constexpr is essential for conditional compilation based on
        the number of arguments in the parameter pack ts.

        Here's why it's necessary:

        1) Compile-Time Branching: The primary purpose of using if constexpr in this code is to enable compile-time
        branching. The code needs to decide at compile time whether to execute the first block or the second block
        based on the number of arguments in ts.

        2) Recursion Control: In the first block, when there are more than 0 arguments in ts, the code recursively
        calls concat with the rest of the arguments, excluding the first one. This recursion continues until ts
        becomes empty. Without constexpr, the compiler wouldn't know which block to execute and wouldn't be able
        to control the recursion.

        3) Optimization: constexpr allows the compiler to optimize the code for performance. When the recursion is deep
        and ts contains a large number of arguments, the use of constexpr helps the compiler generate efficient code
        by evaluating it at compile time. This can result in faster execution.
    */
    {
        return [=](auto... parameter) { return t(concat(ts...)(parameter...)); };
    }
    else
    {
        return t;
    }
}
int main()
{
    auto twice = [](int i) { return 2 * i; };
    auto thrice = [](int i) { return 3 * i; };
    auto combine(concat(twice, thrice, std::plus<int>{}));
    std::cout << combine(2,3) << std::endl;
    return 0;
}

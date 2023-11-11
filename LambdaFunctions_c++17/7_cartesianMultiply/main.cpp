#include <iostream>

void print(int a, int b)
{
    std::cout << "(" << a
              << ", "
              << b << ")";
}


int main()
{
    // first we implement call cart
    // for that we creat a function object that is named call_cart
    // this function accepts a parameter f which is print function
    // then it takes a parameter pack and runs f on all of the pairs
    // we use std::initilizer_list{((void)function(),0)...}
    constexpr auto call_cart([=](auto fn, auto x, auto... rest) constexpr {
        (void)std::initializer_list<int>{
            ((x < rest) ? fn(x, rest) : (void)0,0 )...
            // if constexpr (x < rest)
            // {
            //     (void)fn(x, rest);
            // }
            // else
            // {
            //     (void)0;
            // }...
            // the above mentioned code in comment is not possible to be used, because it is an statement not
            // an expression, and it is not allowed to use statement in an initializer list.
        };
    });

    constexpr auto cartesian([=](auto... xs) constexpr {
        return [=](auto f) { (void)std::initializer_list<int>{((void)call_cart(f, xs, xs...),0)...}; };
    });

    constexpr auto print_cart(cartesian(1,2,3));
    print_cart(print);
    return 0;
}

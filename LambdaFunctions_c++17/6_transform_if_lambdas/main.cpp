#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

template <typename T>
T transform_if(T t, auto if_function, auto unaryOp)
{
    T temp, result;
    std::copy_if(std::begin(t), std::end(t), std::back_inserter(temp), if_function);
    std::transform(std::begin(temp), std::end(temp), std::back_inserter(result), unaryOp);
    return result;
}

template <typename T>
auto map(T fn)
{
    return [=](auto reduce_fn) { return [=](auto accu, auto input) { return reduce_fn(accu, fn(input)); }; };
}
template <typename T>
auto filter(T predicate)
{
    return [=](auto reduce_fn) {
        return [=](auto accu, auto input) {
            if (predicate(input))
            {
                return reduce_fn(accu, input);
            }
            else
            {
                return accu;
            }
        };
    };
}

int main()
{
    std::istream_iterator<int> inputIt{std::cin};
    std::istream_iterator<int> end_it;
    auto even([](int num) { return num % 2 == 0; });
    auto twice([](int num1) { return num1 * 2; });
    auto copy_and_advance([](auto it, auto input) {
        *it = input;
        return ++it;
    });

    std::accumulate(inputIt,
                    end_it,
                    std::ostream_iterator<int>{std::cout, ", "},
                    filter(even)(map(twice)(copy_and_advance)));
    std::cout << std::endl;
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it : transform_if(v, even, twice))
    {
        std::cout << it << ", ";
    }
    std::cout << std::endl;
    return 0;
}

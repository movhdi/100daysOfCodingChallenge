#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

static void print(const std::vector<int> &v)
{
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>{std::cout, ", "});
    std::cout << std::endl;
}
int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::random_device rd;
    std::mt19937 gm(rd());
    std::cout << "Is vector defined in the code sorted? : " << std::is_sorted(std::begin(vec), std::end(vec))
              << std::endl;
    print(vec);
    std::shuffle(std::begin(vec), std::end(vec), gm);
    print(vec);
    std::sort(std::begin(vec), std::end(vec));
    std::cout << "Is sorted? : " << std::is_sorted(std::begin(vec), std::end(vec)) << std::endl;
    print(vec);
    std::shuffle(std::begin(vec), std::end(vec), gm);
    print(vec);
    std::partition(std::begin(vec), std::end(vec), [](int i){return i <=  5;});
    print(vec);
    std::shuffle(std::begin(vec),std::end(vec), gm);
    auto middle(std::next(std::begin(vec), static_cast<int>(vec.size() / 2)));
    std::partial_sort(std::begin(vec),middle, std::end(vec));
    print(vec);
    struct mystruct
    {
        int a;
        int b;
    };
    std::vector<mystruct> vec2{{1,151}, {56, 5}, {10, 70}};
    std::sort(std::begin(vec2), std::end(vec2), [](mystruct &alpha, mystruct &beta){return alpha.b < beta.b;});
    for (const auto &[a, b] : vec2)
    {
        std::cout << "(" << a << ", " << b << ")" << ", ";
    }
    std::cout << std::endl;
    return 0;
}

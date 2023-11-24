#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

void print(const std::vector<int> &v)
{
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<int> {std::cout, ", "});
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6};
    print(vec);
    {
        const auto new_end(std::remove(std::begin(vec), std::end(vec), 2));
        vec.erase(new_end);
    }
    print(vec);
    {
        auto is_odd_number([](int i){return i % 2 == 0;});
        const auto new_end(std::remove_if(std::begin(vec), std::end(vec), is_odd_number));
    }
    print(vec);
    std::replace(std::begin(vec),std::end(vec),4,123);
    print(vec);
    int i {1};
    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(vec);
    std::vector<int> vec2;
    std::vector<int> vec3;
    auto odd_number([](int i){return i % 2 != 0;});
    auto even_number([](int i){return i % 2 == 0;});
    std::remove_copy_if(std::begin(vec), std::end(vec), std::back_inserter(vec2), odd_number);

    return 0;
}

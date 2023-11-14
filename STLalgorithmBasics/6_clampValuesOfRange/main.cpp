#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

auto norm(int min, int max, int newmax)
{
    return [=](int value) {
        double diff = max - min;
        return (value - min) / diff * newmax;
    };
}
auto clampVal(int min, int max)
{
    return [=](int val) -> int { return std::clamp(val, min, max); };
}

int main()
{
    std::vector<int> v{0, 1000, 5, 250, 300, 800, 900, 321};
    const auto [first, last] = std::minmax_element(std::begin(v), std::end(v));
    std::vector<int> normalized;
    normalized.reserve(v.size());
    std::transform(std::begin(v), std::end(v), std::back_inserter(normalized), norm(*first, *last, 255));
    std::copy(std::begin(normalized), std::end(normalized), std::ostream_iterator<int>{std::cout, ", "});
    std::cout << '\n';
    std::transform(std::begin(v), std::end(v), std::begin(normalized), clampVal(0, 250));
    std::copy(std::begin(normalized), std::end(normalized), std::ostream_iterator<int>{std::cout, ", "});
    std::cout << '\n';
    return 0;
}

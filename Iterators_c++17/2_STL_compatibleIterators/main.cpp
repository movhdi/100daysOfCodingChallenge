#include <algorithm>
#include <iostream>

class numIterator
{
    int i;

public:
    explicit numIterator(int position = 0) : i{position}
    {
    }

    int operator*() const
    {
        return i;
    }
    bool operator!=(const numIterator &other) const
    {
        return i != other.i;
    }
    bool operator==(const numIterator &other) const
    {
        return !(*this != other);
    }
    numIterator &operator++()
    {
        ++i;
        return *this;
    }
};
namespace std
{
template <>
struct iterator_traits<numIterator>
{
    using iterator_category = forward_iterator_tag;
    using value_type = int;
};
} // namespace std

class numRange
{
    int a;
    int b;

public:
    numRange(int from, int to) : a{from}, b{to}
    {
    }

    numIterator begin() const
    {
        return numIterator(a);
    }
    numIterator end() const
    {
        return numIterator(b);
    }
};

int main()
{
    numRange r{100, 110};
    auto [min_it, max_it] = std::minmax_element(std::begin(r), std::end(r));
    std::cout << *min_it << " - " << *max_it << std::endl;
    return 0;
}

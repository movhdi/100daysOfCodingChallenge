#include <iostream>

class numIterator
{
    int i;

public:
    explicit numIterator(int position) : i{position}
    {
    }

    int operator*() const { return i; }
    numIterator &operator++()
    {
        ++i;
        return *this;
    }
    bool operator!=(const numIterator &other) const
    {
        return i != other.i;
    }
};

class numRange
{
    int a;
    int b;

public:
    numRange(int from, int to)
        : a{from}, b{to}
    {
    }
    numIterator begin() const { return numIterator{a}; }
    numIterator end() const { return numIterator{b}; }
};

int main()
{
    for (const auto & i : numRange{100, 110})
    {
        std::cout << i << ", ";
    }
    std::cout << '\n';
    return 0;
}

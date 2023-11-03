#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

class zipIterator
{
private:
    using it_type = std::vector<double>::iterator;
    it_type it1;
    it_type it2;

public:
    zipIterator(it_type a, it_type b);
    ~zipIterator();
    zipIterator &operator++()
    {
        ++it1;
        ++it2;
        return *this;
    }
    bool operator!=(zipIterator const &other) const
    {
        return it1 != other.it1 && it2 != other.it2;
    }
    bool operator==(zipIterator const &other) const
    {
        return !(*this != other); // return !operator!=(other)
    }
    std::pair<double, double> operator*() const
    {
        return {*it1, *it2};
    }
};

zipIterator::zipIterator(it_type a, it_type b)
{
    it1 = a;
    it2 = b;
}

zipIterator::~zipIterator()
{
}

// making iterator compatible with STL
namespace std
{
template <>
struct iterator_traits<zipIterator>
{
    using iterator_category = forward_iterator_tag;
    using value_type = std::pair<double, double>;
    using difference_type = long int; // ?
};
} // namespace std

class zipper
{
private:
    using vecType = std::vector<double>;
    vecType &vec1;
    vecType &vec2;

public:
    zipper(vecType &a, vecType &b);
    ~zipper();
    zipIterator begin() const
    {
        zipIterator beginIt{vec1.begin(), vec2.begin()};
        return beginIt;
    }
    zipIterator end() const
    {
        return {vec1.end(), vec2.end()};
    }
};

zipper::zipper(vecType &a, vecType &b) : vec1{a}, vec2{b}
{
} // You should initialize the references in the constructor initializer list.

zipper::~zipper()
{
}

int main()
{
    std::vector<double> v1{1.0, 2.0, 3.0};
    std::vector<double> v2{4.0, 5.0, 6.0};
    zipper zip(v1, v2);
    const auto add_product([](double rslt, const auto &p) { return rslt + p.first * p.second; });
    const auto result = std::accumulate(zip.begin(), zip.end(), 0.0, add_product);
    std::cout << "The result is: " << result << std::endl;
    return 0;
}

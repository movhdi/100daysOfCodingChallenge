#include <iostream>

// Objective: we need a ++ operator in which fibonaci gets done
// Algorithm of Fibonaci: a temp for memorizing last b, adding a to the b, storing old sum in b
class fibit
{
private:
    size_t i{0};
    size_t a{0};
    size_t b{1};

public:
    fibit() = default; // explicitly requesting a default constructor from the compiler with pre defined initialization
    explicit fibit(size_t _i) : i{_i}
    {
    }
    ~fibit()
    {
    }
    size_t operator*() const
    {
        return b;
    }
    fibit &operator++()
    {
        const auto old_b{b};
        b = b + a;
        a = old_b;
        ++i;
        return *this;
    }
    bool operator!=(const fibit &other)
    {
        return i != other.i;
    }
};

class fib_range
{
private:
    size_t end_it;

public:
    fib_range(size_t end_it_);
    ~fib_range();
    fibit begin() const
    {
        return fibit{};
    }
    fibit end() const
    {
        return fibit{end_it};
    }
};

fib_range::fib_range(size_t end_it_)
{
    this->end_it = end_it_;
}

fib_range::~fib_range()
{
}

int main()
{
    /*
        Consider that we write the following code:

        for (auto x : range) { code_block; }

        The compiler will evaluate it to the following:

        {
            auto __begin = std::begin(range);
            auto __end = std::end(range);
            for ( ; __begin != __end; ++__begin)
            {
                auto x = *__begin;
                code_block
            }
        }
    */
    for (const auto i : fib_range{10})
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    return 0;
}

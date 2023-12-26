#include <iostream>
#include <optional>

std::optional<int> read_int()
{
    int i;
    if(std::cin >> i)
    {
        return i;
    }
    return {};
}

std::optional<int> operator+(std::optional<int> a, std::optional<int> b)
{
    if(!a.has_value() || !b.has_value())
    {
        return {};
    }
    return *a + *b;
}

std::optional<int> operator+(std::optional<int> a, int b)
{
    if (!a)
    {
        return {};
    }
    return *a + b;
}

int main()
{
    std::cout << "Please Enter Two integer:\n";
    auto a {read_int()};
    auto b {read_int()};
    auto sum(a + b + 10);
    if (sum)
    {
        std::cout << *a << " + " << *b << " + 10 = " << *sum << std::endl;
    }
    else
    {
        std::cout << "Sorry the input was something else than two numbers \n";
    }

    return 0;
}

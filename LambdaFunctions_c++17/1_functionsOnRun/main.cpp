#include <iostream>
#include <string>

int main()
{
    int j{0};
    const auto incrementer = [&j]() { return ++j; };
    incrementer();
    incrementer();
    incrementer();
    std::cout << j << std::endl;
    const auto plus = [](auto k, auto i) { return k + i; };
    const auto plus_ten = [=](int jk) { return plus(jk, 10); };
    std::cout << plus_ten(5) << std::endl;
    auto myFunction = [](int a, int b) -> int { return a + b; };
    std::cout << myFunction(1, 2) << std::endl;
    const auto counter([count = 0]() mutable {
        return ++count;
    }); // mutable means this function can modify captured values by copy (=) and not by reference
    std::cout << [](int m, int n) { return m + n; }(1, 3) << std::endl;
    std::cout << plus(static_cast<std::string>("mahdi "), "movahedi") << std::endl;
    return 0;
}

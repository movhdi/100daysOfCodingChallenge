#include <algorithm>
#include <execution> // sudo apt install libtbb-dev //  should be added to settings.json "C_Cpp_Runner.linkerArgs": ["-ltbb"]
#include <iostream>
#include <random>
#include <vector>

static bool odd(int i)
{
    return i % 2 != 0;
}

int main()
{
    std::vector<int> v(50000000);
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist(0, 100000);
    auto rand_num([=]() mutable { return dist(gen); });
    std::generate(std::execution::par, std::begin(v), std::end(v), rand_num);
    std::sort(std::execution::par, std::begin(v), std::end(v));
    std::reverse(std::execution::par, std::begin(v), std::end(v));
    auto odds_number(std::count_if(std::execution::par, std::begin(v), std::end(v), odd));
    std::cout << (static_cast<double>(odds_number) * static_cast<double>(100.0) / static_cast<double>(v.size()))
              << "% of numbers are odd!\n";
    return 0;
}

#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iostream>

int main()
{
    const size_t sig_size{100};
    std::vector<double> as(sig_size); // a for analog signal
    std::vector<int> ds(sig_size);    // d for digital signal
    auto sine_generator([n{0}]() mutable
                        { return 5.0 * sin(n++ * 2 * M_PI / 100); });
    std::generate(std::begin(as), std::end(as), sine_generator);
    std::copy(std::begin(as), std::end(as), std::begin(ds));
    std::copy(std::begin(as), std::end(as), std::ostream_iterator<double>{std::cout, " "});
    std::cout << '\n';
    std::copy(std::begin(ds), std::end(ds), std::ostream_iterator<double>{std::cout, " "});
    std::cout << '\n';
    std::cout << "second:\n";
    std::cout << std::inner_product(
                     std::begin(as), std::end(as), std::begin(ds), 0.0, [](double a, double b)
                     { return a + b; },
                     [](double a, double b)
                     { return pow((a - b), 2); })
              << std::endl;
    return 0;
}
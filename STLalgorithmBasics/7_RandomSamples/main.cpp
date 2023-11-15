#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <map>
#include <iomanip>


int main()
{
    const size_t data_points{100000};
    const size_t sample_points{100};
    const int mean {10};
    const size_t dev{5};
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{mean, dev};
    std::vector<int> v;
    v.reserve(data_points);
    std::generate_n(std::back_inserter(v),data_points, [&](){return d(gen);});
    std::vector<int> samples;
    samples.reserve(sample_points);
    std::sample(std::begin(v), std::end(v),std::back_inserter(samples),sample_points, std::mt19937(std::random_device{}()));
    std::map<int, size_t> hist;
    for (int i : samples)
    {
        ++hist[i];
    }

    for (const auto &[value, occurence] : hist)
    {
        std::cout << std::setw(2) << value << " " << std::string(occurence, '*') << std::endl;
    }

    return 0;
}

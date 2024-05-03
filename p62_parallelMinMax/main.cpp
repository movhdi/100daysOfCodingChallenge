#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <array>
#include <functional>
#include <utility>
#include <parallelAlg.hpp>

template <typename FwdIt>
std::pair<FwdIt, FwdIt> paralProto(FwdIt first, FwdIt last)
{
    FwdIt itmin = first;
    FwdIt itmax = last;
    return std::make_pair(itmin, itmax);
}

int main()
{
    std::vector<int> unsortedData(50010);

    // making random numbers to sort
    std::random_device rd;                                      // to generate seed data fed into mt19937 rand. eng.
    std::mt19937 reng;                                          // rand. eng. mt19937
    std::uniform_int_distribution<int> uniformDist(0, 1000000); // dist. for generating random numbers in the range of [0,1000000]
    std::array<int, std::mt19937::state_size> seedData;
    std::generate(std::begin(seedData), std::end(seedData), std::ref(rd));
    std::seed_seq seedSeq(std::begin(seedData), std::end(seedData));
    reng.seed(seedSeq);

    //testing the generated numbers
    std::generate(unsortedData.begin(), unsortedData.end(), [&uniformDist, &reng]()
                  { return uniformDist(reng); });

    // std::copy(unsortedData.begin(), unsortedData.end(), std::ostream_iterator<int>{std::cout, ", "});
    std::cout << std::endl;

    auto result = parallelMinMax(unsortedData.begin(), unsortedData.end());
    std::cout <<"Minimum is: " << result.first << std::endl << "Maximum is: "<< result.second << std::endl;
    // showing in the output

    std::cout  << std::endl;
    return 0;
}
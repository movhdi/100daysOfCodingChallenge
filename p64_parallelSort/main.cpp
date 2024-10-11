#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <random>
#include <iterator>
#include <future>
#include <chrono>

int main()
{
    std::vector<unsigned int> unsorted_data(50005);
    
    // generating random numbers
    // 1. generating the fresh seed value
    std::random_device rd;
    std::mt19937 RandomEngine;
    std::array<unsigned int, std::mt19937::state_size> seed_value;
    std::generate(std::begin(seed_value), std::end(seed_value), [&rd](){
        return rd();
    });
    std::seed_seq seq(std::begin(seed_value), std::end(seed_value));
    RandomEngine.seed(seq);
    std::uniform_int_distribution<int> udist(0,10000000);
    std::generate(unsorted_data.begin(), unsorted_data.end(), [&RandomEngine, &udist](){
        return udist(RandomEngine);
    });
    return 0;
}
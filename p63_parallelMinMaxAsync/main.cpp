#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <random>
#include <iterator>
#include <future>
#include <chrono>


template <typename It>
auto parallel_minmax_base(It firstElement, It lastElement)
{
    auto future = std::async(std::launch::async, std::minmax_element<It>, firstElement, lastElement);
    return future;
}

// parallel minmax using async function
template <typename It>
auto parallel_minmax_async(It firstElement, It lastElement)
{
    typename It::value_type local_min{0xFFFFFFFF};
    typename It::value_type local_max{};

    auto distance = std::distance(firstElement, lastElement);
    if ( distance < 10000)
    {
        auto [minElemIt, maxElemIt] =  std::minmax_element(firstElement, lastElement);
        return std::make_pair(*minElemIt, *maxElemIt);
    }

    std::vector<decltype(parallel_minmax_base(firstElement, lastElement))> futurePool;
    
    auto temp_last = firstElement;
    while (firstElement != lastElement)
    {
        distance =  std::distance(firstElement, lastElement);
        if (distance >= 10000)
        {
            temp_last = std::next(firstElement, 10000);
        }
        else
        {
            temp_last = lastElement;
        }
        futurePool.emplace_back(parallel_minmax_base(firstElement, temp_last));
        firstElement = temp_last;
    }
    for (auto & handle : futurePool)
    {
        auto [minElemIt, maxElemIt] = handle.get();
        
        if (*minElemIt <= local_min)
        {
            local_min = *minElemIt;
        }
        if (*maxElemIt >= local_max)
        {
            local_max = *maxElemIt;
        }
        
    }
    return std::make_pair(local_min, local_max);
}

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

    
    // 2. findign min and max of the generated data
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto future_i = parallel_minmax_base(std::begin(unsorted_data), std::end(unsorted_data));
    auto [minIt, maxIt] = future_i.get();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "\nmin is: " << *minIt << ", max is: " << *maxIt << std::endl;
    std::cout << duration.count() << std::endl;


    start = high_resolution_clock::now();
    auto result = parallel_minmax_async(std::begin(unsorted_data), std::end(unsorted_data));
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout <<"Min is: " <<  result.first << " max is: " << result.second << std::endl; 
    std::cout << duration.count() << std::endl;

    return 0;
}
#include <parallelAlg.hpp>
#include <vector>
#include <thread>
#include <algorithm>
#include <mutex>
#include <iostream>

template std::pair<int, int> parallelMinMax(typename std::vector<int>::iterator first, typename std::vector<int>::iterator last);

template <typename FwdIt>
std::pair<typename std::iterator_traits<FwdIt>::value_type, typename std::iterator_traits<FwdIt>::value_type> parallelMinMax(FwdIt first, FwdIt last)
{
    // container for storing found local extremum
    // std::vector<typename std::iterator_traits<FwdIt>::value_type> MinMaxElems;
    std::vector<typename std::iterator_traits<FwdIt>::value_type> MinMaxElems;

    auto count = std::distance(first, last);
    std::cout << count << std::endl;
    auto coresNumber = std::thread::hardware_concurrency();
    std::cout << coresNumber << std::endl;
    // making mutex for protecting MinMaxElems from being concurrently manipulated
    std::mutex vectorPopulatingMutex;

    if (count < 10000)
    {
        auto [minit, maxit] = std::minmax_element(first, last);
        return std::make_pair(*minit, *maxit);
    }
    else
    {
        auto rangeDistanceForEachProcess = count / coresNumber;
        std::cout << rangeDistanceForEachProcess << std::endl;
        std::vector<std::thread> threads(coresNumber);
        auto last_temp = first;
        for (size_t i = 0; i < coresNumber; ++i)
        {
            last_temp = std::next(first, rangeDistanceForEachProcess);

            if (std::distance(last_temp, last) <= rangeDistanceForEachProcess)
            {
                last_temp = last;
            }
            threads.emplace_back([i,first, last_temp, &vectorPopulatingMutex, &MinMaxElems](){
                    auto [minElemIt, maxElemIt] = std::minmax_element(first, last_temp);
                    {
                        std::lock_guard<std::mutex> lk(vectorPopulatingMutex);
                        MinMaxElems.emplace_back(*minElemIt);
                        MinMaxElems.emplace_back(*maxElemIt);
                        std::cout << "distance: " << std::distance(first, last_temp) << std::endl;
                        std::cout << "this thread id [" << i << "] : " << std::this_thread::get_id() << std::endl;
                    }
            });
            first = last_temp;
        }
        for (auto &th : threads)
        {
            if (th.joinable())
            {
                th.join();
            }
        }
        std::copy(MinMaxElems.begin(), MinMaxElems.end(), std::ostream_iterator<int>{std::cout, ", "}); std::cout << std::endl << std::endl;
        std::sort(MinMaxElems.begin(), MinMaxElems.end());
        std::copy(MinMaxElems.begin(), MinMaxElems.end(), std::ostream_iterator<int>{std::cout, ", "}); std::cout << std::endl << std::endl;
        return std::make_pair(*MinMaxElems.begin(), *(MinMaxElems.end()-1));
    }
}

#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <iterator>

// signature for transform algorithm
/*
ForwardIt2 transform(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2, UnaryOp unary_op);
*/

template <typename ForwardIt1, typename ForwardIt2, typename UnaryOp>
ForwardIt2 parallel_transform(int concurrencyLevel, ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2, UnaryOp&& unary_op)
{
    auto distance = std::distance(first1, last1);
    if (distance <= 10000)
    {
        std::transform(first1, last1, first2, std::forward<UnaryOp>(unary_op));
    }
    else
    {
        auto portion = distance / concurrencyLevel;
        std::vector<std::thread> thread_pool;
        auto begin = first1;
        auto end = last1;
        auto first2_temp = first2;
        for (size_t i = 0; i < concurrencyLevel ; i++)
        {
            auto last1_temp = std::next(begin, portion);
            if (std::distance(last1_temp, end) < portion)
            {
                last1_temp = end;
            }
            std::thread th([begin, last1_temp, first2_temp, &unary_op](){std::transform(begin, last1_temp, first2_temp, std::forward<UnaryOp>(unary_op));});
            thread_pool.emplace_back(std::move(th));
            first2_temp = std::next(first2_temp, portion);
            begin = last1_temp;
        }
        for (auto &th : thread_pool)
        {
            th.join();
        }
    }
}


int main()
{
    auto cores = std::thread::hardware_concurrency();
    size_t singleCoreQuant = 10000;
    size_t ParallelQuantity = 50006;
    std::vector<int> vec1(ParallelQuantity);
    std::vector<int> vec2(vec1.size());
    std::generate(std::begin(vec1), std::end(vec1), [](){static int i{}; return i++;});
    auto t1 = std::chrono::system_clock::now();
    parallel_transform(cores, std::begin(vec1), std::end(vec1), std::begin(vec2), [](int& i){return i*2;});
    auto t2 = std::chrono::system_clock::now();
    auto tParallel = t2 - t1;
    // std::copy(std::begin(vec2), std::end(vec2), std::ostream_iterator<int>{std::cout, ", "});
    std::vector<int> vec1Prime(singleCoreQuant);
    std::vector<int> vec2Prime(vec1Prime.size());
    std::generate(std::begin(vec1Prime), std::end(vec1Prime), [](){static int i{}; return i++;});
    t1 = std::chrono::system_clock::now();
    parallel_transform(cores, std::begin(vec1Prime), std::end(vec1Prime), std::begin(vec2Prime), [](int& i){return i*2;});
    t2 = std::chrono::system_clock::now();
    auto tSingleCore = t2 - t1;
    std::cout << "Execution time for parallel processing of " << ParallelQuantity << " data is " << tParallel.count() << std::endl;
    std::cout << "Execution time for parallel processing of " << singleCoreQuant << " data is " << tParallel.count() << std::endl;
    return 0;
}

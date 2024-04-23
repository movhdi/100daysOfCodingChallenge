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
    if (distance < 10000)
    {
        std::transform(first1, last1, first2, std::ref(unary_op));
    }
    else
    {
        auto portion = distance / concurrencyLevel;
        std::vector<std::thread> thread_pool;
        for (size_t i = 0; i < concurrencyLevel; i++)
        {
            auto last1_temp = std::next(first1, portion);
            auto first2_temp = std::next(first2, portion);
            std::thread th([first1, last1_temp, first2_temp, &unary_op](){std::transform(first1, last1_temp, first2_temp, unary_op);});
            thread_pool.emplace_back(std::move(th));
            first1 = last1_temp;
            first2 = first2_temp;
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
    std::vector<int> vec1(1000);
    std::vector<int> vec2(vec1.size());
    std::generate(std::begin(vec1), std::end(vec1), [](){static int i{}; return i++;});
    parallel_transform(cores, std::begin(vec1), std::end(vec1), std::begin(vec2), [](int& i){return i*2;});
    std::copy(std::begin(vec2), std::end(vec2), std::ostream_iterator<int>{std::cout, ", "});
    int i = 101;
    int j = 20;
    std::cout << std::endl;
    return 0;
}

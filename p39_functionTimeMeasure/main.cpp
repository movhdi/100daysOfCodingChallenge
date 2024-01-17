#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <utility>
#include <thread>
#include <functional>

template<typename T1 = std::chrono::milliseconds,
         typename T2 = std::chrono::high_resolution_clock>
class perf_timer
{
private:
    /* data */
public:
    perf_timer(/* args */) {}
    ~perf_timer() {}
    template<typename F, typename ... Args>
    static T1 duration(F&& f, Args ... args)
    {
        auto start = T2::now();
        std::invoke(std::forward<F> (f), std::forward<Args>(args)...);
        auto end = T2::now();
        return std::chrono::duration_cast<T1>(end - start);
    }
};
void f()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void g()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
}
int main()
{
    auto t1 = perf_timer<std::chrono::milliseconds>::duration(f);
    auto t2 = perf_timer<std::chrono::microseconds>::duration(g);
    std::cout << t1.count() << '\n' << t2.count();
}

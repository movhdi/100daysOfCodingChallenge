#include <iostream>
#include <thread>

// -lpthread in linked arguments needed

using std::chrono_literals::operator""ms;
using std::chrono_literals::operator""s;

static void thread_with_param(int i)
{
    std::this_thread::sleep_for(1ms * i);
    std::cout << "Hello from thread " << i <<'\n';
    std::this_thread::sleep_for(1s * i);
    std::cout << "bye from thread " << i << '\n';
}

int main()
{
    std::cout << std::thread::hardware_concurrency() << " concurrent threads are supported.\n";
    std::thread t1{thread_with_param, 1};
    std::thread t2{thread_with_param, 2};
    std::thread t3{thread_with_param, 3};
    t1.join();
    t2.join();
    t3.detach();
    std::cout << "Threads join.\n";
    return 0;
}

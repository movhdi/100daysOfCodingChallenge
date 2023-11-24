#include <iostream>
#include <chrono>
#include <thread>


int main()
{
    using std::chrono_literals::operator""s;
    using std::chrono_literals::operator""ms;
    std::cout << "Going to sleep for 5 seconds"
                 " and 30 milli seconds.\n";
    std::this_thread::sleep_for(5s + 300ms);
    std::cout << "Going to sleep for another 3 seconds.\n";
    std::this_thread::sleep_until(std::chrono::high_resolution_clock::now() + 3s);
    std::cout << "that's it\n";
    return 0;
}

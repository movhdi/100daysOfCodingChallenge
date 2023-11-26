#include <mutex>
#include <thread>
#include <iostream>
#include <vector>

std::once_flag callflag;

static void onceprint()
{
    std::cout << '!';
}


static void print (size_t x)
{
    std::call_once(callflag, onceprint);
    std::cout << x;
}

int main()
{
    std::vector<std::thread> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.emplace_back(print, i);
    }
    for (auto &t : v)
    {
        t.join();
    }
    std::cout << '\n';

}

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <thread>

// the program does not work properly unless :
// -pthread should be used in compiler arguments, but why?

std::shared_mutex shared_mut;
using shrd_lock = std::shared_lock<std::shared_mutex>;
using uniq_lock = std::unique_lock<std::shared_mutex>;


static void print_exclusive()
{
    uniq_lock l {shared_mut, std::defer_lock};
    if (l.try_lock())
    {
        std::cout << "Got exclusive lock\n";
    }
    else
    {
        std::cout << "Unable to lock exclusively\n";
    }
}

static void exclusive_throw()
{
    uniq_lock l {shared_mut};
    throw 123;
}

int main()
{
    {
        shrd_lock sl1 {shared_mut};
        std::cout << "shared lock once\n";
        {
            shrd_lock sl2{shared_mut};
            std::cout << "shared lock twice!\n";
            print_exclusive();
        }
        std::cout << "shared lock once again!\n";
        print_exclusive();
    }
    std::cout << "lock is free\n";
    try
    {
        exclusive_throw();
    }
    catch(int e)
    {
        std::cout << "Got exception " <<e << '\n';
    }
    print_exclusive();
    return 0;
}

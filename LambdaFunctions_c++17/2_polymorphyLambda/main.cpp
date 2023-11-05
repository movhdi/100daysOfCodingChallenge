#include <iostream>
#include <functional>
#include <deque>
#include <list>
#include <vector>


static auto consumer(auto &container)
{
    return [&](auto value){container.push_back(value);};
}

static void printContainer(const auto &container)
{
    for(const auto it: container)
    {
        std::cout << it << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    std::deque<int> deq;
    std::vector<int> vec;
    std::list<int> lst;
    const std::vector<std::function<void(int)>> consumers{consumer(deq),consumer(vec),consumer(lst)};
    for (int i = 0; i < 10; i++)
    {
        for (auto consumer : consumers)
        {
            consumer(i);
        }
    }
    printContainer(deq);
    printContainer(vec);
    printContainer(lst);


    return 0;
}

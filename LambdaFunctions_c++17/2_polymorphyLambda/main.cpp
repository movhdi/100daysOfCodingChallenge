#include <iostream>
#include <functional>
#include <deque>
#include <list>
#include <vector>


static auto consumer(auto &container)
{
    return [&](auto value){container.pushback(value);};
}

int main()
{

    return 0;
}
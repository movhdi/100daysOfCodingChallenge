#include <iostream>
#include <queue>
#include <string>
#include <tuple>

int main()
{
    typedef std::pair<int, std::string> itemtype;
    std::priority_queue<itemtype> q;
    std::initializer_list<itemtype> il = {{1, "dijsh washing"},
                                          {0, "watching TV"},
                                          {2, "Home works"},
                                          {0, "Read comics"}};
    for (const auto &item : il)
    {
        q.push(item);
    }
    while (!q.empty())
    {
        std::cout << q.top().first << ": " << q.top().second << std::endl;
        q.pop();
    }
    std::cout << std::endl;
    return 0;
}

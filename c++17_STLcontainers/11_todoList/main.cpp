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
    /*
    I asked chatGPT about the default '<' operator in a std::pair<int, string> type, it said:
    For std::pair<int, std::string>, the < operator (less than operator) is available by default,
    and it will be used for comparison. The basis of comparison for this std::pair type is straightforward:
    it first compares the int part of the pair, and if the int values are equal,
    it then compares the std::string part lexicographically.
    */
    while (!q.empty())
    {
        std::cout << q.top().first << ": " << q.top().second << std::endl;
        q.pop();
    }
    std::cout << std::endl;
    return 0;
}

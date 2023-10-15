#include <algorithm>
#include <iostream>
#include <vector>
template <typename T>
void quick_remove_at(std::vector<T> &con, size_t i)
{
    if (i < con.size())
    {
        con[i] = std::move(con.back());
        con.pop_back();
    }
}

template <typename T>
void quick_remove_at(std::vector<T> &con, typename std::vector<T>::iterator it)
{
    if (it != con.end())
    {
        *it = std::move(con.back());
        con.pop_back();
    }
}
int main()
{
    std::vector<int> con{965, 656556, 4520, 878, 332};
    std::vector<int>::const_iterator ci;
    for (auto it : con)
    {
        std::cout << it << ", ";
    }
    std::cout <<std::endl;
    quick_remove_at(con, 2);
    for (auto it : con)
    {
        std::cout << it << ", ";
    }
    std::cout << std::endl;
    quick_remove_at(con, std::find(con.begin(), con.end(), 332));
    for (auto it : con)
    {
        std::cout << it << ", ";
    }
    std::cout << std::endl;
    return 0;
}

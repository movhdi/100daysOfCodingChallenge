#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    int x = 10;
    int k = 2;
    int &y = k;
    std::vector<std::reference_wrapper<int>> a;
    a.push_back(y);
    std::reference_wrapper<int> z(x);
    std::cout << "y is ref to k(2) :"<< y << std::endl;
    y = x;
    std::cout <<"y is ref to x(10): "<< y << std::endl;
    x = 8;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
    std::cout << k << std::endl;

    return 0;
}

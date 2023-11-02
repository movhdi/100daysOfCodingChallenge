#include <iostream>
#include <vector>


int main()
{
    std::vector<int> v{1,2,3,4,5};
    v.shrink_to_fit();
    const auto it = v.begin();
    std::cout << *it << std::endl;
    v.push_back(123);
    std::cout << *it << std::endl;
    return 0;
}

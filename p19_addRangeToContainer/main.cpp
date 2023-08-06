#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

template <typename C, typename... Args>
void addToContainer(C& container, Args&&... args)
{
    (container.push_back(args),...); // it could be a recursive function like the last example
    // But here Fold expressions was used 
    // the above line expands like: container.push_back(a1),(container.push_back(a2),(container.push_back(a3), container.push_back(a4)))
    // It means multiple calls of push_back method
}



int main()
{
    std::vector<int> arr({1,2,3,4,5});
    std::copy(std::begin(arr),std::end(arr), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    addToContainer(arr, 6,7,8);
    std::copy(std::begin(arr),std::end(arr), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
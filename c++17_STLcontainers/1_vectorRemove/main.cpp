#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> con{1, 3, 2, 5, 6, 2, 8, 4};
    const auto odd([](int x) {
        if (x % 2 != 0)
        {
            return true;
        }
    });
    std::cout << "capacity of vector container before remove: " << con.capacity() << std::endl;
    std::cout << "size of vector container before remove: " << con.size() << std::endl;
    const auto new_end = std::remove(con.begin(),con.end(),2);
    std::cout << "capacity of vector container after remove: " << con.capacity() << std::endl;
    std::cout << "size of vector container after remove: " << con.size() << std::endl;

    con.erase(new_end, con.end());
    std::cout << "capacity of vector container after erase: " << con.capacity() << std::endl;
    std::cout << "size of vector container after erase: " << con.size() << std::endl;

    for (const auto it : con)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
    con.shrink_to_fit();
    std::cout << "capacity of vector container after shrink: " << con.capacity() << std::endl;
    std::cout << "size of vector container after shrink: " << con.size() << std::endl;
    return 0;
}

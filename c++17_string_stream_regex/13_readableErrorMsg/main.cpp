#include <iostream>
#include <fstream>
#include <system_error>
#include <cstring>

int main()
{
    std::ifstream f;
    f.exceptions(f.failbit | f.badbit);
    try
    {
        f.open("non_existant.txt");
        int i;
        f >> i;
        std::cout << "Integer has value: " << i << std::endl;
    }
    catch(std::ios::failure &e)
    {
        std::cerr << "Caught error: ";
        if (errno)
        {
            std::cerr << strerror(errno) << std::endl;
        }else
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}
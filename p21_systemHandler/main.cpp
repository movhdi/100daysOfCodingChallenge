#include <iostream>



template <typename traits>
class unique_handle
{
    using pointer = typename traits::pointer;
    pointer hassan_gholi;
public:
    unique_handle(unique_handle const &) = delete;

};

int main()
{

    return 0;
}
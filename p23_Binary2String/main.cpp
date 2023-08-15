#include <iostream>
#include <vector>
#include <mutex>
#include <iterator>
#include <algorithm>
#include <array>
#include <cassert>
#include <sstream>
#include <iomanip>

template <typename Iter>
std::string bytes_to_hexstr(Iter begin, Iter end, bool const uppercase_flag = false)
{
    std::ostringstream oss;
    if(uppercase_flag)
    {
        oss.setf(std::ios_base::uppercase);
    }

    for(;begin != end ; ++begin)
    {
        oss.fill('0');
        oss << std::setw(2) << std::hex <<std::right <</*std::setfill('0') <<*/  static_cast<int>(*begin);
    }
    return oss.str();
}


template <typename C>
std::string bytes_to_hexstr(C const & container, bool const uppercase_flag = false)
{
    return bytes_to_hexstr(std::cbegin(container), std::cend(container), uppercase_flag);
}


int main()
{
    std::vector<unsigned char> vec{0xBA, 0xAD, 0xF0, 0x0D};
    std::array<unsigned char, 6> arr{1,2,3,4,5,6};
    unsigned char buf[5] = {0x11, 0x22, 0x33, 0x44, 0x55};
    // std::cout << bytes_to_hexstr(vec) << '\n';
    assert(bytes_to_hexstr(vec, true) == "BAADF00D");
    assert(bytes_to_hexstr(arr, true) == "010203040506");
    assert(bytes_to_hexstr(buf,true) == "1122334455");
    assert(bytes_to_hexstr(vec) == "baadf00d");
    assert(bytes_to_hexstr(arr) == "010203040506");
    assert(bytes_to_hexstr(buf) == "1122334455");
    return 0;
}

/*
    Morals of the story
    At first I wrote a copy of main function from the book.
    in the second bytes_to_hexstr() function I used
    container.begin()
    in order to pass the iterator to the first element of the container.
    Since a simple array (here buf) was existing the compiler threw error. Becaue simple c array does not support iterators.
    I could have used cbegin() and cend() function instead of begin() and end() member functions.
    I changed and it worked.
*/
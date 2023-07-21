#include <sstream>
#include <string>
#include <iostream> 
#include <bitset>
#include <array>
#include <algorithm>

class IPv4{
public:
    u_int32_t ipv4;
    std::array<unsigned char, 4> data;
    // first constructor
    constexpr IPv4(): ipv4{0},data{{0}}
    {
    }

    // second constructor
    constexpr IPv4(unsigned char a, unsigned char b,
                   unsigned char c, unsigned char d):
        ipv4{static_cast<uint32_t> ( (unsigned int)d | (unsigned int)c << 8 | (unsigned int)b << 16 | (unsigned int)a << 24)},
        data{{d,c,b,a}}
    {
    }
    
    // third constructor
    IPv4(uint32_t a)
    {
        this->data[3] = static_cast<unsigned char>((a >> 24) & (0xFF));
        this->data[2] = static_cast<unsigned char>((a >> 16) & (0xFF));
        this->data[1] = static_cast<unsigned char>((a >>  8) & (0xFF));
        this->data[0] = static_cast<unsigned char>( a        & (0xFF));
        this->ipv4 = a;
    }

    // Copy constructor
    IPv4(IPv4 const & other) noexcept
    {
        ipv4 = other.ipv4;
        data = other.data;
    }
    
    // Assignment operator overloading
    IPv4& operator=(IPv4 const & other) noexcept
    {
        this->ipv4 = other.ipv4;
        this->data = other.data;
        return *this;
    }
    
    friend bool operator==(const IPv4& rhs, const IPv4& lhs)
    {
        return lhs.data == rhs.data;
    }

    friend bool operator!=(const IPv4& rhs, const IPv4& lhs)
    {
        return lhs.data != rhs.data;
    }

    friend bool operator<(const IPv4& lhs, const IPv4& rhs)
    {
        return lhs.ipv4 < rhs.ipv4;
    }

    friend bool operator>(const IPv4& lhs, const IPv4& rhs)
    {
        return !(lhs<rhs);
    }

    friend bool operator<=(const IPv4& lhs, const IPv4& rhs)
    {
        return !(rhs<lhs);
    }
    friend bool operator>=(const IPv4& lhs, const IPv4& rhs)
    {
        return !(lhs<rhs);
    }

    IPv4& operator++()
    {
        *this = IPv4(1 + this->ipv4);
        return *this;
    }

    IPv4& operator++(int)
    {
        IPv4 result((*this).ipv4);
        ++result;
        *this = result;
        return *this;
    }

    std::string to_string() 
    {
        std::stringstream sstr;
        sstr << *this;
        return sstr.str();
    }

    friend std::istream& operator>>(std::istream& is,IPv4& IPv4_input)
    {
        char d1,d2,d3;
        uint32_t b1,b2,b3,b4;
        is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
        if(d1 == '.' && d2 == '.' && d3 == '.')
        {
            if(std::max({b1,b2,b3,b4}) < 256)
            {
                IPv4_input.ipv4 = b4 | (b3 << 8) | (b2 << 16) | (b1 << 24);
                IPv4_input.data = {static_cast<unsigned char> (b4),
                                   static_cast<unsigned char> (b3),
                                   static_cast<unsigned char> (b2),
                                   static_cast<unsigned char> (b1)};
            }else
            {
                is.setstate(std::ios::failbit);
            }
        }else
        {
            is.setstate(std::ios::failbit);
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const IPv4&  IPv4_output)
    {
        return os << "My Method: "
                  << ((IPv4_output.ipv4 & ((unsigned int) 0xFF << 24)) >> 24) << '.' 
                  << ((IPv4_output.ipv4 & ((unsigned int) 0xFF << 16)) >> 16) << '.' 
                  << ((IPv4_output.ipv4 & ((unsigned int) 0xFF <<  8)) >>  8) << '.' 
                  << (IPv4_output.ipv4 & (unsigned int) 0xFF) << std::endl
                  << "Book's Method: "
                  << static_cast<uint32_t>(IPv4_output.data[3]) << '.'
                  << static_cast<uint32_t>(IPv4_output.data[2]) << '.'
                  << static_cast<uint32_t>(IPv4_output.data[1]) << '.'
                  << static_cast<uint32_t>(IPv4_output.data[0]) << std::endl;
    }
};


int main()
{
    IPv4 ip(127,0,0,0);
    IPv4 ip2(127,0,3,230);
    if(ip < ip2)
    {
        std::cout << "ip < ip2 test passed\n";
    }else
    {
        std::cout << "\nip < ip2 test failed\n";
    }
    for(int i =0; i <300 ; i++)
    {
        std::cout << ++ip  << std::endl << ++ip << std::endl;
    }

    for(IPv4 i = ip; i <= ip2 ; ++i)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

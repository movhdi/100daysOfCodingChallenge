#include <iostream> 
#include <bitset>


class IPv4{
public:
    u_int32_t ipv4{0};

};

    std::istream& operator>>(std::istream& is,IPv4& IPv4_input)
    {
        char d1,d2,d3;
        uint32_t b1,b2,b3,b4;
        is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
        if(d1 == '.' && d2 == '.' && d3 == '.')
        {
            IPv4_input.ipv4 = b4 | (b3 << 8) | (b2 << 16) | (b1 << 24);
        }
        return is;
    }

    std::ostream& operator<<(std::ostream& os, IPv4& IPv4_output)
    {
        return os << ((IPv4_output.ipv4 & (0xFF << 24u)) >> 24) << '.' << ((IPv4_output.ipv4 & (0xFF << 16)) >> 16) << '.' << ((IPv4_output.ipv4 & (0xFF << 8)) >> 8)<< '.' << (IPv4_output.ipv4 & (0xFF)) << std::endl;
    }

int main()
{
    IPv4 example;
    std::cout << "Enter IP Address\n";
    std::cin >> example;
    std::cout << '\n' << "The IP is: " << example;

    return 0;
}
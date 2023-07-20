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
    IPv4(): ipv4{0},data{{0}}
    {
    }

    // second constructor
    IPv4(unsigned char a, unsigned char b,
         unsigned char c, unsigned char d)
    {
        this->data = {d,c,b,a};
        this->ipv4 = 0;
    }
    
    // Assignment operator overloading
    IPv4& operator=(IPv4 const & other)
    {
        this->data = other.data;
        this->ipv4 = other.ipv4;
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
    IPv4 ip(192,168,0,1);
    std::cout << "ip defined by constructor:\n" << ip << std::endl;
    std::cout << "Enter IP Address\n";
    std::cin >> ip;
    if(!std::cin.fail())
    {
        std::cout << '\n' << "The IP is: \n" << ip;
    }else
    {
        std::cout << "Invalid Input\n";
        return 0;
    }
    
    return 0;
}


/*  Morale of the story:
    Morale 1 
    {
        A copy constructor is used to initialize a previously uninitialized object from some other object's data.

        A(const A& rhs) : data_(rhs.data_) {}
        For example:

        A aa;
        A a = aa;  //copy constructor
        An assignment operator is used to replace the data of a previously initialized object with some other object's data.

        A& operator=(const A& rhs) {data_ = rhs.data_; return *this;}
        For example:

        A aa;
        A a;
        a = aa;  // assignment operator
    }

    Morale 2
    {
        I first defined 
        std::string to_string() const
        Behind the scene it means:
        std::string to_string(const IPv4* this)
        
        On the other hand I had defined << operator overloading without const for IPv4 :

        friend std::ostream& operator<<(std::ostream& os, IPv4&  IPv4_output)

        Since to_string() function would call << operator , there was the conflict of passing IPv4 as const into 
        to_string() function and after that passing it again to << operator without const. 

        this inconsistency threw compile error. The solution was either ommiting const from to_string() function, or 
        adding const for IPv4 in the arguments of << operator. 

    }
*/
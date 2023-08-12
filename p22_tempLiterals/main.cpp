#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iterator>

// Requirements:
// An enumeration of supported temperature scales called scale .
// A class template to represent a temperature value, parameterized with the scale,
// called quantity .

// Comparison operators == , != , < , > , <= , and >= that compare two quantities of the
// same time.

// Arithmetic operators + and - that add and subtract values of the same quantity
// type. Additionally, we could implement member operators += and -+ .

// A function template to convert temperatures from one scale to another, called
// temperature_cast . This function does not perform the conversion itself but
// uses type traits to do that.

// Literal operators ""_deg , ""_f , and ""_k for creating user-defined temperature
// literals.
#define epsilon 0.001f

bool is_equal(double const a , double const b)
{
    if((a - b < epsilon) || (b - a < epsilon))
    {
        return true;
    }else
    {
        return false;
    }
}

namespace tmprtur
{
    enum class scale {celcius, fahrenheit, kelvin};
    template <scale S>
    class temperature_
    {
        double amount;
    public:
        constexpr explicit temperature_(double const value):amount(value){};
        explicit operator double() const {return amount;}
        double get_amount() const
        {
            return amount;
        }

    };
    template <scale S>
    bool operator==(temperature_<S> const & lhs, temperature_<S> const & rhs)
    {
        if(is_equal(lhs.amount, rhs.amount))
        {
            return true;
        }else
        {
            return false;
        }
    }

    template <scale S>
    bool operator!=(temperature_<S> const & lhs, temperature_<S> const & rhs)
    {
        return !(lhs == rhs);
    }

    template<scale S>
    bool operator<(temperature_<S> const & lhs, temperature_<S> const & rhs)
    {
        if(lhs.amount < rhs.amount)
        {
            return true;
        }else
        {
            return false;
        }
    }

    template <scale S>
    bool operator>(temperature_<S> const & lhs, temperature_<S> const & rhs)
    {
        if(lhs.amount > rhs.amount)
        {
            return true;
        }else
        {
            return false;
        }
    }

    template <scale S>
    bool operator<=(temperature_<S> const & lhs, temperature_<S> const & rhs)
    {
        return !(lhs>rhs);
    }

    template <scale S>
    bool operator>=(temperature_<S> const & lhs, temperature_<S> const & rhs)
    {
        return !(lhs<rhs);
    }

    template <scale S>
    temperature_<S> operator+(temperature_<S> const & lhs, temperature_<S> const & rhs)
    {
        return temperature_<S> (lhs.amount + rhs.amount);
    }

    template <scale S>
    temperature_<S> operator-(temperature_<S> const & lhs, temperature_<S> const & rhs)
    {
        return temperature_<S> (lhs.amount - rhs.amount);
    }

    template <scale S>
    temperature_<S>& operator++(temperature_<S> const & lhs)
    {
        lhs.amount = lhs.amount +1;
        return (lhs);
    }

    template<scale S, scale R>
    struct conversion
    {
        static double convert(double const tempe)  = delete;
    };

    template <>
    struct conversion<scale::celcius,scale::fahrenheit>
    {
        static double convert(double const tempe) 
        {
            return (5.0f/9.0f)*(tempe-32);
        }
    };
    template<>
    struct conversion<scale::fahrenheit,scale::celcius>
    {
        static double convert(double const tempe) 
        {
            return (9.0f/5.0f)*tempe+32;
        }
    };

    template <scale S, scale R>
    temperature_<S> temperature_cast(temperature_<R> const other)
    {
        return temperature_<S> (conversion<S,R>::convert(other.get_amount()));
    }

    namespace temperature_scale_literals
    {
        temperature_<scale::celcius> operator "" _deg(long double const amount)
        {
            return temperature_<scale::celcius> {static_cast<double> (amount)};
        }

        temperature_<scale::fahrenheit> operator "" _f(long double const amount)
        {
            return temperature_<scale::fahrenheit> {static_cast<double> (amount)};
        }

        temperature_<scale::kelvin> operator "" _k(long double const amount)
        {
            return temperature_<scale::kelvin> {static_cast<double> (amount)};
        }
    }
}
namespace temperature_scale_literals
{

}

int main()
{
    using namespace tmprtur;
    using namespace tmprtur::temperature_scale_literals;
    auto T1{ 37.9_deg };
    auto T2{ 79.0_f };

    auto tf = temperature_cast<scale::fahrenheit>(T1);
    auto tc = temperature_cast<scale::celcius>(T2);
    return 0;
}


/*  Moral of the story:
    when I started writing this code, I did not have an insight why convert member function in conversion struct
    is defined with static specifier.
    without static specifier the compilers throws an error inside temperature_cast<> function.
    The error says it is not possible to call convert function without an object of the class conversion.
    It is said in geeksforgeeks.org::
    
    Static members of a class are not associated with the objects of the class.
    Just like a static variable once declared is allocated with memory that can’t be changed every object points to the same memory.

    Static Member Function in a class is the function that is declared as static
    because of which function attains certain properties as defined below:

    - A static member function is independent of any object of the class. 
    - A static member function can be called even if no objects of the class exist.
    - A static member function can also be accessed using the class name through the scope resolution operator.
    - A static member function can access static data members and static member functions inside or outside of the class.
    - Static member functions have a scope inside the class and cannot access the current object pointer.
    - You can also use a static member function to determine how many objects of the class have been created.
    
    
    The reason we need Static member function:
    - Static members are frequently used to store information that is shared by all objects in a class. 
    - For instance, you may keep track of the quantity of newly generated objects of a specific class type
        using a static data member as a counter. This static data member can be increased each time an object
        is generated to keep track of the overall number of objects.
*/
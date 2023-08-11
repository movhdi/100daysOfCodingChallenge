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
    template<scale S, scale R>
    struct conversion
    {
        double convert(double const tempe) const = delete;
    };

    template <>
    struct conversion<scale::celcius,scale::fahrenheit>
    {
        double convert(double const tempe) const
        {
            return (5.0f/9.0f)*(tempe-32);
        }
    };
    template<>
    struct conversion<scale::fahrenheit,scale::celcius>
    {
        double convert(double const tempe) const
        {
            return (9.0f/5.0f)*tempe+32;
        }
    };

    template<scale S, scale R>
    temperature_<S> temperature_cast(temperature_<R> const other)
    {
        conversion<S,R> conv;
        return temperature_<S> (conv.convert(other.get_amount()));
    }
}

namespace temperature_scale_literals
{

}

int main()
{
    using namespace tmprtur;
    using namespace temperature_scale_literals;
    auto T1{ 37.9_deg };
    auto T2{ 79.0_f };

    auto tf = temperature_cast<scale::fahrenheit>(T1);
    auto tc = temperature_cast<scale::celcius>(T2);
    return 0;
}
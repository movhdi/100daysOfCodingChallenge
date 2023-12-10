#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


struct city
{
    std::string name;
    size_t population;
    double longitude;
    double latitude;
};

std::istream &operator>>(std::istream &is, city &c)
{
    is >> std::ws;
    std::getline(is, c.name);
    is >> c.population >> c.longitude >> c.latitude;
    return is;
}


int main()
{
    std::vector<city> l;
    std::copy(std::istream_iterator<city>{std::cin}, {}, std::back_inserter(l));
    for (const auto &[name, pop, lon, lat] : l)
    {
        std::cout << std::left << std::setw(15) << name << '\n'
                  << "Population: " << pop << '\n'
                  << "Longitude: " << lon << '\n'
                  << "Latitude: " << lat << std::endl;
    }

    return 0;
}

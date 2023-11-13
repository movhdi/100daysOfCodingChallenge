#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

struct city
{
    std::string name;
    unsigned population;
};

bool operator==(const city &lhs, const city &rhs)
{
    return lhs.name == rhs.name && lhs.population == rhs.population;
}
std::ostream &operator<<(std::ostream &os, const city city_object)
{
    return os << "{city name: " << city_object.name << ", city population: " << city_object.population << "}";
}

template <typename c>
static auto opt_print(const c &container)
{
    return [end_it(container.end())](const auto &item) {
        if (item != end_it)
        {
            std::cout << *item << '\n';
        }
        else
        {
            std::cout << "<end>" << '\n';
        }
    };
}

int main()
{
    const std::vector<city> c{{"Aachen", 246000}, {"Berlin", 3502000}, {"Braunschweig", 251000}, {"Cologne", 1060000}};
    auto print_city(opt_print(c));
    {
        auto found_cologne(std::find(std::begin(c), std::end(c), city{"Cologne", 1060000}));
        print_city(found_cologne);
    }
    {
        auto found_cologne(std::find_if(std::begin(c), std::end(c), [](const city &object) {
            if (object.name == "Cologne")
            {
                return true;
            }
            else
            {
                return false;
            }
        }));
        print_city(found_cologne);
    }

    {
        auto population_large([](unsigned i) { return [=](city candid) { return candid.population > i; }; });
        auto found_large(std::find_if(std::begin(c), std::end(c), population_large(2000000)));
        print_city(found_large);
    }
    return 0;
}

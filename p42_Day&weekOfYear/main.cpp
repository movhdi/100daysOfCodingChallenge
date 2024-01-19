#include "date/date.h"
#include "date/iso_week.h"
#include "date/tz.h"
#include <chrono>
#include <iostream>


auto week_of_year(int const y, unsigned const int m, unsigned const int d)
{
    auto dt = date::sys_days{date::year{y}/ date::month{m}/ date::day{d}};
    auto date = iso_week::year_weeknum_weekday{dt};
    return static_cast<unsigned int> (date.weeknum());
}

auto day_of_year(int const y, unsigned const int m, unsigned const int d)
{
    auto dt = date::sys_days{date::year{y}/ date::month{m}/ date::day{d}};
    return (dt - date::sys_days{date::year{y}/ date::month{1}/ date::day{0}}).count();
}

int main()
{
    auto week = week_of_year(2024,1, 18);
    auto day = day_of_year(2024,1,18);
    std::cout << week << std::endl << day << '\n';
}

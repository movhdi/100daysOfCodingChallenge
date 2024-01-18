#include "date/date.h"
#include "date/iso_week.h"
#include "date/tz.h"
#include <chrono>
#include <iostream>


auto day_of_week(int y, unsigned int m, unsigned int d)
{
    auto dt = date::sys_days{date::year{y}/ date::month{m}/ date::day{d}};
    auto date = iso_week::year_weeknum_weekday{dt};
    return static_cast<unsigned int> (date.weekday());
}

int main()
{
    auto day = day_of_week(2024,1, 18);
    std::cout << day << std::endl;
}

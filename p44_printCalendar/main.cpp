#include <date/iso_week.h>
#include "date/tz.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


auto week_day(const int y, const unsigned int m, const unsigned int d)
{
    auto dt = date::year_month_day{date::year{y},date::month{m}, date::day{d}};
    auto day = iso_week::year_weeknum_weekday(dt).weekday();
    return day;
}

void print_calendar(int const year, unsigned int const month)
{
    // first step: determin weekday of the first day of the month
    auto weekday = week_day(year, month, 1);
    // second step: determin last day of the month
    auto lastday = date::year_month_day_last(date::year{year}, date::month_day_last{date::month{month}});
    // printing the calendar
    std::cout << "Mon Tue Wed Thu Fri Sat Sun" << std::endl;

    unsigned int index{1};
    for (unsigned int i = 1; i < static_cast<unsigned int> (weekday); i++, index++)
    {
        std::cout  << "    ";
    }

    for (unsigned int i = 1 ; i <= (unsigned int) lastday.day(); i++,index++)
    {
        std::cout  << std::right << std::setfill(' ') << std::setw(3) << i << ' ' ;
        if (index == 7)
        {
            std::cout << std::endl;
            index = 0;
        }
    }
    std::cout << std::endl;
}
int main()
{
    // auto dt = date::year_month_day{date::year{2024},date::month{01}, date::day{01}};
    // auto wd = date::year_month_weekday(dt);
    // auto lastDay = date::year_month_day_last(date::year{2024}, date::month_day_last{date::month{03}}).day();
    // std::cout << lastDay << std::endl;
    for (unsigned int i = 1; i <= 12; i++)
    {
        print_calendar(2024,i);
    }

}

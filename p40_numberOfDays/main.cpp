#include "date/date.h"
#include "date/tz.h"
#include <chrono>
#include <functional>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <thread>
#include <utility>
#include <vector>

inline int number_of_days(int const y1,
                          unsigned int const m1,
                          unsigned int const d1,
                          int const y2,
                          unsigned int const m2,
                          unsigned int const d2)
{
    return (date::sys_days{date::year{y1} / date::month{m1} / date::day{d1}} -
            date::sys_days{date::year{y2} / date::month{m2} / date::day{d2}}).count();
}
inline int number_of_days(date::sys_days const &d1, date::sys_days const &d2)
{
    return (d1 - d2).count();
}

int main()
{
    auto diff = number_of_days(2024,1,12 , 2024, 1,1);
    std::cout << diff << '\n';
    using date::literals::operator""_y;
    using date::literals::jan;
    auto diff2 = number_of_days(2024_y/jan/12, 2024_y/jan/1);
    std::cout << diff2 << '\n';
}

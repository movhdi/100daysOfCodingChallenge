#include <iomanip>
#include <iostream>
#include <chrono>
using namespace std;

ostream& operator<<(ostream &os, const chrono::time_point<chrono::system_clock> &time) // deleting const makes unable to build
{
    const auto tt(chrono::system_clock::to_time_t(time));
    const auto loct(localtime(&tt));
    return os << put_time(loct, "%c");
}
using days = std::chrono::duration<int64_t, std::ratio_multiply<std::ratio<3600>, std::ratio<24>>>;

constexpr days operator""_days(unsigned long long h)
{
    return days{h};
}

using namespace std::chrono_literals;
int main()
{
    auto now(std::chrono::system_clock::now());
    std::cout << "The current date and time is : " << now << std::endl;
    std::chrono::hours hours_12h{12};
    std::cout << "in 12 hours it will be : " << (now + hours_12h) << std::endl;
    std::cout << "12 hours and 15 minutes ago, it was " << (now - 12h - 15min) << '\n' << "1 week ago, it was " << (now - 7_days) << '\n';

    return 0;
}

#include <iostream>
#include <ratio>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <optional>


using seconds = std::chrono::duration<double>;
using milliseconds = std::chrono::duration<double, std::ratio_multiply<std::chrono::seconds::period, std::milli>>;
using microseconds = std::chrono::duration<double, std::ratio_multiply<std::chrono::seconds::period, std::micro>>;

std::pair<std::string, seconds> get_input()
{
    std::string s;
    const auto tic = std::chrono::steady_clock::now();
    if (!(std::cin >> s))
    {
        return {{},{}};
    }
    const auto toc = std::chrono::steady_clock::now();
    return {s, toc - tic};
}

int main()
{
    while (true)
    {
        std::cout << " Please type the word \"C++\" as fast as you can.\n";
        const auto &[user_input, diff] = get_input();
        if (user_input == "")
        {
            break;
        }
        if (user_input == "C++17")
        {
            std::cout << "Bravo, you did it in: \n"
                      << std::fixed << std::setprecision(2)
                      << std::setw(12) << diff.count()
                      << " seconds."
                      << std::setw(12) << milliseconds(diff).count()
                      << " milliseconds"
                      << std::setw(12) << microseconds(diff).count()
                      << " microseconds" << std::endl;
                      break;
        }
        else
        {
            std::cout << "sorry, your input does not match. You may try again.\n";
        }
    }
}

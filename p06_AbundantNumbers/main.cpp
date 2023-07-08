#include <iostream>
#include <vector>
#include <map>
#include <mutex>
#include <cmath>

// and so on

bool is_abundant(int32_t num)
{
    int32_t sum = 1;
    for(int i = 2; i <= std::sqrt(num); i++)
    {
        if(num % i == 0)
        {
            sum += i;
            if(i != (num/i))
            {
                sum += (num/i);
            }            
        }
    }

    if(sum > num)
    {
        std::cout << "The number : " << num << " is abundant!\n";
        std::cout << "The abundance is : " << sum - num<< "\n\n";
        return true;
    }
    return false;
}

int main()
{
    int32_t limit_value;
    std::cout << "Enter a number to list all abundant numbers up to that number:\n";
    std::cin >> limit_value;

    for(int i = 12 ; i <= limit_value ; i++)
    {
        is_abundant(i);
    }

    return 0;
}
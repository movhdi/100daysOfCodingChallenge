#include <iostream>
#include <mutex>
#include <map>
#include <cmath>

std::pair<bool, int32_t> is_amicable(int32_t number)
{
    bool is_amicable{false};
    int32_t sum{0},sum1{0};
    
    // std::cout << "\nproper divisors of " << number << ": ";
    for(int32_t i = 1; i < number ; i++)
    {
        if(number % i == 0)
        {
            sum += i;
            // std::cout << i << ", ";
        }
    }
    // std::cout << "\nThe sum of divisors is: "<< sum <<std::endl;
    // std::cout << "\nproper divisors of " << sum << ": ";
    for( int32_t i = 1; i < sum ; i++)
    {
        if(sum % i == 0)
        {
            sum1 += i;
            // std::cout << i << ", ";
        }
    }
    // std::cout << "\nThe sum of divisors is: "<< sum1 <<std::endl;
    if(sum1 == number && sum != number)
    {
        is_amicable = true;
        std::cout << "Pair of (" << number << ", " << sum << ") are amicable numbers.\n";
    }
    return std::make_pair(is_amicable, sum);
}

int main(int argc, char * argv[])
{
    std::cout << "Input the limit value\n";
    int32_t limit_value{0};

    std::cin >> limit_value;
    
    for(int32_t i = 1; i <= limit_value; i++)
    {
        std::pair<bool, int32_t> result{is_amicable(i)};
        if(result.first)
        {
            i = result.second + 1;
        }
    }
    
    (void)argc;
    (void)argv;
    return 0;
}
#include <iostream>
#include <mutex>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iterator>
#include <algorithm>

std::vector<unsigned long long> factors(unsigned long long num)
{
    std::vector<unsigned long long> factors;
    // collecting factor 2 
    while (num % 2 == 0)
    {
        factors.push_back(2);
        num = num/2;
    }
    // collecting factors 3 and beyond
    for (unsigned long long i = 3; i <= (unsigned long long)std::sqrt(num); i += 2)
    {
        while(num % i == 0)
        {
            factors.push_back(i);
            num = num/i;
        }
    }

    if(num > 2)
    {
        factors.push_back(num);
    }
    return factors;
}



int main(int argc , char * argv[])
{
    unsigned long long num;
    std::cout << "Printing the prime factors of a number upto you limit,\nPlease Enter the limit value:\n\n";
    std::cin >> num;
    auto result_factors = factors(num);

    for(auto it : result_factors)
    {
        std::cout << it << ", ";
    }
    std::cout << std::endl << std::endl;

    std::copy(result_factors.begin(),result_factors.end(),std::ostream_iterator<unsigned long long>(std::cout, ", "));
    std::cout << "\n";
    (void) argc;
    (void) argv;
    return 0;
}
#include <iostream>
#include <cmath>
#include <mutex>
#include <map>

int find_gcd(int32_t num1, int32_t num2)
{
    int32_t gcd{0};
    // Using Euclid's algorithm
    while(num1 != num2)
    {
        if(num1 > num2)
        {
            num1 = num1 - num2;
        }else{
            num2 = num2 - num1;
        }
    }
    return num1;
}

bool test_gcd()
{
    std::map<std::pair<int32_t,int32_t> , int32_t> gcd_pairs{{{18,48},6},
                                                             {{100,5},5},
                                                             {{13,11},1}};
    bool result;
    for(auto it : gcd_pairs)
    {
        if(find_gcd(it.first.first,it.first.second) != it.second)
        {
            std::cout << "\ntest: calculating gcd of "<< it.first.first << " and " << it.first.second;
            std::cout << "\nthe result is : " << find_gcd(it.first.first,it.first.second) << std::endl;
            result = false;
        }
    }
    return result;
}

int main()
{
    int32_t first_number{0}, second_number{0};
    std::cout << "Enter two numbers" << std::endl;
    std::cin >> first_number;
    std::cin >> second_number;
    std::cout << "The common divisor is : " << find_gcd(first_number,second_number) << std::endl;


    if(test_gcd())
    {
        std::cout << "\nAll the tests passed successfully!\n";
    }

    return 0;
}
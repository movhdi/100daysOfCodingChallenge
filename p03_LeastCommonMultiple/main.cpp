#include <iostream>
#include <cmath>
#include <mutex>
#include <map>


/**
 * @brief finding the greatest common divisor using Euclid's algorithm
 * 
 * @param num1 
 * @param num2 
 * @return int 
 */
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
/**
 * @brief calculating least common multiplier using greatest common divisor
 * 
 * @param num1 
 * @param num2 
 * @return int, the result
 */
int find_lcm(int32_t num1, int32_t num2)
{
    return (num1 * num2)/find_gcd(num1,num2);
}
/**
 * @brief This is the test function for the implemented solution
 * 
 * @return true if all tests are passed
 * @return false if any of the tests fails
 */
bool test_gcd()
{
    std::map<std::pair<int32_t,int32_t> , int32_t> gcd_pairs{{{6,4},12},
                                                             {{100,5},100},
                                                             {{13,11}, 11*13}};
    bool result;
    for(auto it : gcd_pairs)
    {
        if(find_lcm(it.first.first,it.first.second) != it.second)
        {
            std::cout << "\ntest: calculating gcd of "<< it.first.first << " and " << it.first.second;
            std::cout << "\nthe result is : " << find_lcm(it.first.first,it.first.second) << std::endl;
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
    std::cout << "The least common multiplier is : " << find_lcm(first_number,second_number) << std::endl;


    if(test_gcd())
    {
        std::cout << "\nAll the tests passed successfully!\n";
    }

    return 0;
}
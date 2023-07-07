#include <iostream>
#include <map>
#include <vector>


/**
 * @brief checks if passed number is prime
 * 
 * @param limit 
 * @return true means the number is prime
 * @return false means the number is not prime
 */
bool is_prime(int32_t limit)
{
    int32_t i = 0;
    if(limit == 2)
    {
        return true;
    }
    for(i = 2; i <= limit/2 +1; i++)
    {
        if(limit % i == 0)
        {
            return false;
        }
    }
    return true;
}
int32_t biggestPrimeNumber(int32_t number)
{
    if(number == 3)
    {
        return 2;
    }
    
    while(!is_prime(number))
    {
        number--;
    }
    return number;
}

void test_primeNumber()
{
    std::vector<std::pair<int32_t,int32_t>> test_specimen{{3, 2}, {4, 3}, {6, 5}, {8, 7}, {12, 11}, {14, 13}, {46, 43}, {60, 59}, {96, 89}, {100,97}};
    for(auto it : test_specimen)
    {
        if(biggestPrimeNumber(it.first) == it.second)
        {
            std::cout << "Test for " << it.first << " Passed!\n";
        }else
        {
            std::cout << "Test for " << it.first << " Failed!\n";
        }
    }
}

int main()
{
    int32_t number; 
    std::cout << "Enter the number : \n";
    std::cin >> number;
    test_primeNumber();
    std::cout << "the largest prime number less than recieved : " << biggestPrimeNumber(number) << std::endl;

    return 0;
}
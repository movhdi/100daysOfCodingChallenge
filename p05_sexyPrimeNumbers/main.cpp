#include <iostream>
#include <map>
#include <vector>



#define NO_PRINT false
#define PRINT true
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


/**
 * @brief This function finds the biggest prime number up to a given value
 * 
 * @param number 
 * @return int32_t 
 */
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

/**
 * @brief prints sexy prime pairs up to a limit
 * 
 * @param number the given limit from the user
 */
std::vector<std::pair<int32_t,int32_t>> printSexyPrime(int32_t number, bool print_grant)
{
    std::vector<std::pair<int32_t,int32_t>> sexyPrimeList;
    for(int i = 2; i <= number-6 ; i++)
    {
        if(is_prime(i) && is_prime(i+6))
        {
            if(print_grant)
            {
                std::cout << "The pair (" << i << ',' << i+6 << ") is a SEXY prime pair!\n";
            }
            sexyPrimeList.push_back(std::make_pair(i,i+6));
        }
    }
    return sexyPrimeList;
}


/**
 * @brief this function tests the application
 * 
 */
void test_primeNumber()
{
    std::vector<std::pair<int32_t,int32_t>> test_specimen{{5, 11}, {7, 13}, {11, 17}, {13, 19}, {17, 23}, {23, 29}, {31, 37}, {37, 43}, {41, 47}, {47,53},{53,59}};
    if(printSexyPrime(63,NO_PRINT) == test_specimen)
    {
        std::cout << "\nAll tests passed!\n";
    }


}

int main()
{
    int32_t number; 
    std::cout << "Enter the number : \n";
    std::cin >> number;
    printSexyPrime(number,PRINT);
    test_primeNumber();
    return 0;
}
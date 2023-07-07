#include <iostream>
#include <string>


int main(int argc, char * argv[])
{
    int64_t limit_value;
    int64_t sum = 0;
    std::cout << "Enter the limit value : " ;
    std::cin >> limit_value;

    for(int i = 1 ; i <= limit_value; i = i+2)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    
    std::cout << "\nSum of divisible to 3 or 5 numbers is : " << sum << std::endl;
    (void)argc;
    (void)argv;
    return 0;
}
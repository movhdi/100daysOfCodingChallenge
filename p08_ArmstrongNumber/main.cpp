#include <iostream>
#include <mutex>
#include <map>
/**
 * @brief This function prints Armstrong numbers up to but not including 1000 
 * 
 * @param num 
 */
void print_Armstrongs_upto1000(int32_t num)
{
    char a{0},b{0},c{0};
    
    for(a = 1; a <= 9; a++)
    {
        for(b = 0; b <= 9; b++)
        {
            for(c = 0; c <= 9; c++)
            {
                if((a*100 + b*10 + c) == num)
                {
                    if(num == ((a*a*a) + (b*b*b) + (c*c*c)))
                    {
                        std::cout << num << " is an Armstrong number\n";
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[])
{
    std::cout << "Printing Armstrong numbers up to 1000\n\n";
    for(int32_t i = 0; i <1000 ; i++)
    {
        print_Armstrongs_upto1000(i);
    }

    (void) argc;
    (void) argv;
    return 0;
}
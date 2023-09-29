#include <iomanip>
#include <streambuf>
#include <string>
#include <assert.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>


unsigned int number_of_digits(unsigned int const i)
{
    return i > 0 ? (unsigned int)log10((double)i) + 1 : 1;
}


/*                                    n!         / n \
   binomial coeff formula is :   ------------ = |     |
                                  a! * (n-a)!    \ a /
*/
// But I will use gamma function no bother implementing recursive functions or using arrays
int binomialCoeff(size_t n, size_t a)
{
    return static_cast<int> (std::tgamma(n+1)/std::tgamma(a+1)/std::tgamma(n-a+1));
}

void printPascal(size_t row)
{
    for (size_t i = 0; i < row; i++)
    {
        std::cout << std::string((row - i - 1) * (row / 2), ' ');
        for (size_t j = 0; j <= i; j++)
        {
            auto y = binomialCoeff(i,j);
            // std::cout << y ;
            auto maxlen = number_of_digits((unsigned int)y) - 1;
            std::cout << y << std::string(row - 1 - maxlen - row % 2, ' ');
        }
        std::cout << std::endl;
    }
}
int main()
{
    printPascal(13);
    return 0;
}

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <bitset>
/**
 * @brief Encoder from binary form into gray code form
 * 
 * @param num 
 * @return unsigned int 
 */
unsigned int to_gray_code(unsigned int num)
{
    num ^= num >> 1;
    std::cout << std::bitset<4>(num) << '\n';
    return num;
}
/**
 * @brief Decoder from gray code form into binary form
 * 
 * @param num 
 * @return unsigned int 
 */
unsigned int to_binary(unsigned int num)
{
    unsigned int binary_result{0};
    while(num != 0)
    {
        binary_result = (binary_result ^ num);
        num >>= 1;
    }
    std::cout << std::bitset<4>(binary_result) << '\n';
    return binary_result;
}

int main(int argc , char * argv[])
{
    unsigned int garray[8];
    std::cout << "\nEncoding the binary form array into gray code form and printing it:\n";
    for(unsigned int i =0; i <= 7; i++)
    {
        garray[i] = to_gray_code(i);
    }
    std::cout << "\nDecoding the gray code array into binary form and printing it:\n";
    for(unsigned int i = 0; i <= 7; i++)
    {
        to_binary(garray[i]);
    }

    (void) argc;
    (void) argv;
    return 0;
}
#include <iostream>
#include <string>

// Validating ISBN
// it should be 10 digits
// the sum of 10*first digit + 9*second digit + 8* third digit + ... + 1*last digit should be divisible by 11
bool validate_ISBN(std::int64_t number)
{
    bool is_valid = false;
    std::int16_t sum = 0;
    for(int i = 0; i < 10 ; i++)
    {
        sum += (1+i)*(std::to_string(number).c_str()[i] - '0');
    }
    if(std::to_string(number).length() != 10)
    {
        return is_valid;
    }else if(sum % 11 != 0)
    {
        return is_valid;
    }else
    {
        is_valid = true;
        return is_valid;
    }
}


int main(int argc, char * argv[])
{
    std::int64_t num;
    std::cout << "enter an ISBN number\n";
    std::cin >> num;
    if(validate_ISBN(num))
    {
        std::cout << "ISBN is valid" << std::endl;
    }else
    {
        std::cout << "ISBN is invalid" << std::endl;
    }
}
#include <iostream>
#include <map>
#include <vector>
#include <mutex>
#include <set>


int roman_to_int(const std::string& numeric_literal, std::map<char, int>& roman_digits)
{
    int total{0};
    long unsigned int i{0};
    i = numeric_literal.size();
    for(long unsigned int j = 0 ; j < i ; j++)
    {
        if(roman_digits.find(numeric_literal[j])->second >= roman_digits.find(numeric_literal[j+1])->second)
        {
            total += roman_digits.find(numeric_literal[j])->second;
        }else
        {
            total = total - roman_digits.find(numeric_literal[j])->second;
        }
    }
    return total;
}

bool sanity_check(const std::string& s, std::map<char, int>& roman_digits)
{
    long unsigned int i{0};
    i = s.size();
    for(long unsigned int j = 0; j < i ; j++)
    {
        if(!roman_digits.count(s[j]))
        {
            std::cout << "Invalid Input Numeral" << "\n\n";
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    std::cout << "Enter Roman numeral:\n\n";
    std::string numeric_literal;
    std::cin >> numeric_literal;
    std::map<char, int> roman_digits{{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
    
    if(!sanity_check(numeric_literal,roman_digits))
    {
        return 0;
    }
    
    std::cout << "Equivalent is: " << roman_to_int(numeric_literal,roman_digits) << std::endl;

    (void) argv;
    (void) argc;
    return 0;
}
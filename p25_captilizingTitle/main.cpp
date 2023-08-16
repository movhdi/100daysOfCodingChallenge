#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

std::string capitalize_title(std::string const & expression)
{
    std::ostringstream result;
    auto it = expression.begin();
    for(; it != expression.end(); it++)
    {
        if(*(it-1) == ' ' || *(it-1) == '.' || *(it-1) == ',' || it == expression.begin())
        {
            // result.setf(std::ios_base::uppercase);
            result << static_cast<char> (std::toupper(*it));
        }
        else
        {
            result << static_cast<char> (std::tolower(*it));
        }
    }
    return result.str();
}
int main()
{
    // using namespace std::string_literals;
    std::cout << capitalize_title("the c++ challenger") << std::endl;
    std::cout << capitalize_title("THIS IS an ExamplE, should wORk!") << std::endl;

    assert("The C++ Challenger" ==  capitalize_title("the c++ challenger"));
    assert("This Is An Example, Should Work!" == capitalize_title("THIS IS an ExamplE, should wORk!"));
    return 0;
}
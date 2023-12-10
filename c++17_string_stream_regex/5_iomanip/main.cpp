#include <iostream>
#include <iomanip>
#include <locale>


void print_aligned_demo(int value,size_t width, char c = ' ')
{
    std::cout << "================'\n";
    std::cout << std::setfill(c);
    std::cout << std::left << std::setw(width) << value << '\n';
    std::cout << std::right << std::setw(width) << value << '\n';
    std::cout << std::internal << std::setw(width) << value << '\n';
}

int main()
{
    print_aligned_demo(123456, 15);
    print_aligned_demo(123456, 15, '_');
    std::cout << std::hex << std::showbase;
    print_aligned_demo(0x123abc, 15);
    std::cout << std::oct ;
    print_aligned_demo(0123456, 15);
    std::cout << "a hex number with uppercase letters:" <<std::hex << std::uppercase <<0x123abc << '\n';
    std::cout << "a number: " << 100 << '\n';
    std::cout << std::dec << "oops! now in decimal again: " << 100 << '\n';
    std::cout << "doubles: " << 12.3 << ", " << 12.0 << ", " << std::showpoint << 12.0 << '\n';
    std::cout << "Scientific double: " << std::scientific << 123000000000.123 << '\n'
              << "fixed         double: " << std::fixed <<   123000000000.123 << '\n';
    std::cout << "Very precise double: " << std::setprecision(10) << 0.000000001 << '\n'
              << "less precise double: " << std::setprecision(1) << 0.000000001 << '\n';
    return 0;
}

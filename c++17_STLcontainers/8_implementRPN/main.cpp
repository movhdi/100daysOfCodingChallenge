#include <cassert>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <vector>

// objective: RPN parser
// we need to read a string from a stream
// we need to parse it one by one, here is where istring_stream comes into play
// we need to use std::stack in order to save operands and operators
// we need helper functions for taking values out of stack
// we will implement rpn parser and evaluator as a separate function
// here we go:

template <typename T>
double RPN_evaluator(T it, T end = {})
{
    // preparations: (1) Stack
    std::stack<double> val_stack;
    // preparations: (2) Helper function to pop from the stack
    auto pop_stack([&]() {
        auto r(val_stack.top());
        val_stack.pop();
        return r;
    });
    // map of operations consisting of two double values and a function pointer
    std::map<std::string, double (*)(double a, double b)> ops{
        {"+", [](double a, double b) { return a + b; }},
        {"-", [](double a, double b) { return a - b; }},
        {"*", [](double a, double b) { return a * b; }},
        {"/", [](double a, double b) { return a / b; }},
        {"^", [](double a, double b) { return std::pow(a, b); }},
        {"%", [](double a, double b) { return std::fmod(a, b); }}};

    for (; it != end; it++)
    {
        std::stringstream ss{*it};
        if (double val; ss >> val)
        {
            val_stack.push(val);
        }
        else
        {
            const auto l(pop_stack());
            const auto r(pop_stack());
            try
            {
                const auto op(ops.at(*it));
                const double &result(op(l, r));
                val_stack.push(result);
            }
            catch (const std::out_of_range &)
            {
                // std::cerr << e.what() << '\n';
                throw std::invalid_argument(*it);
            }
        }
    }
    return val_stack.top();
}


int main()
{
    try
    {
        std::cout << RPN_evaluator<std::istream_iterator<std::string>>(std::istream_iterator<std::string>{std::cin}, {})
                  << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Invalid operator: " << e.what() << '\n';
    }
    std::cout << "Using stringstream: " << std::endl;
    std::stringstream ss{"3 2 1 + * 2 /"};
    std::cout << RPN_evaluator(std::istream_iterator<std::string>(ss), {}) << '\n';

    std::vector<std::string> vec{"3", "2", "1", "+", "*", "2", "/"};
    std::cout << "Using vector as input: " << std::endl;
    std::cout << RPN_evaluator(vec.begin(), vec.end()) << std::endl;
    return 0;
}

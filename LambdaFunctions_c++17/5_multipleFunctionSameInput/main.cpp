#include <iostream>

/*
'f(x)' calls the function 'f' with argument 'x'. This is where the operation is applied to a single element.

'(void)' is used to discard the result of the expression, ensuring that the operation is executed but its
result is not used. It's a way to suppress any potential "unused variable" warnings.

', 0' combines the results of each operation. The , (comma operator) discards the result of the left expression
'((void)f(x))' and evaluates the right expression '(0)'. This effectively counts the number of elements in
the parameter pack, which can be useful in certain scenarios.

Here's a step-by-step explanation of how the expression '((void)f(x), 0)' expands:

Let's say you have a parameter pack xs with values 1, 2, and 3. You want to apply the f function to each of these values
and combine the results using the ', 0' fold expression.

((void)f(1), 0) is evaluated. It applies f to 1, discards the result, and returns 0.
((0, (void)f(2)), 0) is evaluated. It applies f to 2, discards the result, and returns 0.
The comma operator groups the expressions.
(((0, (void)f(3)), 0) is evaluated. It applies f to 3, discards the result, and returns 0.
The comma operator groups the expressions.

*/

static auto multicall(auto ...functions)
{
    return [=](auto parameter) { (void)std::initializer_list<int>{((void)functions(parameter), 0)...}; };
}

static auto for_each(auto f, auto ...xs)
{
    (void)std::initializer_list<int>{((void)f(xs), 0)...};
}

static auto brace_print(char a, char b)
{
    return [=](auto x){std::cout << a << x << b << ", ";};
}

int main()
{
    auto f (brace_print('(',')'));
    auto g (brace_print('[',']'));
    auto h (brace_print('{','}'));
    auto nl ([](auto){std::cout << std::endl;});
    auto call_fgh(multicall(f,g,h,nl));
    for_each(call_fgh,1,2,3);
    return 0;
}

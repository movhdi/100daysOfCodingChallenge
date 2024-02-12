#include <iostream>
#include <algorithm>

void print_permutations(std::string str)
{
    std::sort(std::begin(str), std::end(str));
    do
    {
        std::cout << str << std::endl;
    } while (std::next_permutation(std::begin(str), std::end(str)));
}

void print_permutations_recursive(std::string str, std::string perm)
{
    if (str == "") // as any other recursion, firstly the stopping condition
    {
        std::cout << perm << std::endl;
    }
    else
    {
        for (size_t i = 0; i < str.size(); ++i)
        {
            print_permutations_recursive(str.substr(1), perm + str[0]); // the main recursion!
            std::rotate(std::begin(str), std::begin(str) + 1, std::end(str)); // preparing input for the next recursion
        }
    }
}

int main()
{
    std::cout << "non-recursive version" <<std::endl;
    print_permutations("main");

    std::cout << "recursive version" <<std::endl;
    print_permutations_recursive("main", "");
}

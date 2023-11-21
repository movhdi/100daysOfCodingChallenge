#include <iostream>

int main()
{
    std::cout << "Please input two numbers:\n";
    int x;
    double y;
    if (std::cin >> x >> y)
    {
        std::cout << "You entered: " << x << ", " << y << '\n';
    }
    else
    {
        std::cout << "Things did not go well with input";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    std::cout << "now please enter some comma-separated names:\n";
    for (std::string s;std::getline(std::cin >> std::ws,s,',');)
    {
        if (s.empty())
        {
            break;
        }
        std::cout << "names: \"" << s << "\"\n";
    }
    return 0;
}

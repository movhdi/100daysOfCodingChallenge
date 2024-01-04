#include <any>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>

using int_list = std::list<int>;

void print_anything(const std::any &a)
{
    if (!a.has_value())
    {
        std::cout << "Nothing\n";
    }
    else if (a.type() == typeid(std::string))
    {
        std::cout << "It is a string: " << std::quoted(std::any_cast<std::string>(a)) << std::endl;
    }
    else if (a.type() == typeid(int))
    {
        std::cout << "It is an integer: " << std::any_cast<int>(a) << std::endl;
    }
    else if (a.type() == typeid(int_list))
    {
        const int_list& temp = std::any_cast<const int_list&> (a);
        std::copy(std::begin(temp),
                  std::end(temp),
                  std::ostream_iterator<int>{std::cout, ", "});
        std::cout << std::endl;
    }
}

int main()
{
    using std::string_literals::operator""s;
    print_anything({});
    print_anything("abc"s);
    print_anything(123);
    print_anything(int_list{1, 2, 3});
    print_anything(std::any(std::in_place_type_t<int_list>{},{1,2,3}));
    return 0;
}

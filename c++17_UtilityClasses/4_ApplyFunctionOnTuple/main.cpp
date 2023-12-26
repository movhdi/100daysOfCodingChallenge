#include <iostream>
#include <tuple>
#include <iomanip>
#include <functional>
#include <string>
#include <list>

static void print_student(size_t id, const std::string &name, double gpa)
{
    std::cout << "Student " << name << ", ID: " << ", GPA: " <<gpa << std::endl;
}

int main()
{
    using student = std::tuple<size_t, std::string, double>;
    using std::string_literals::operator""s;
    student john = {123, "John Doe"s, 3.7};
    {
        const auto &[id, name, gpa] = john;
        print_student(id, name, gpa);
    }
    std::cout << "------\n";
    std::initializer_list<student> arguments_for_print = {
        std::make_tuple(234, "Mahdi Movahedi"s, 3.9),
        std::make_tuple(278, "Eleanor Arroway"s,3.7),
        std::make_tuple(300, "Elon Musk"s, 4)
    };

    for (auto &[id, name, gpa] : arguments_for_print)
    {
        print_student(id, name, gpa);
    }
    std::cout << "-----\n";
    std::apply(print_student, john);
    std::cout << "-----\n";
    for (const auto &arg : arguments_for_print)
    {
        std::apply(print_student, arg);
    }
    std::cout << '\n';
}

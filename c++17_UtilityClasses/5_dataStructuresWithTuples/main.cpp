#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <string>
#include <tuple>
#include <utility>

template <typename T, typename... Ts>
void print_args(std::ostream &os, const T &v, const Ts &...vs)
{
    os << v;
    // using pack expansion
    // (void)std::initializer_list<int>{((os << "," << vs), 0)...};

    // using fold expression
    ((os << "," << vs),...);
}

template <typename... Ts>
std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t)
{
    auto print_to_os([&os](const auto &...xs) { print_args(os, xs...); });
    os << "(";
    std::apply(print_to_os, t);
    return os << ")";
}

template <typename T = double>
auto sum_min_max_avg(std::initializer_list<T> il)
{
    const auto begin_it = std::begin(il);
    const auto end_it = std::end(il);
    const auto sum = std::accumulate(begin_it, end_it, 0);

    return std::make_tuple(sum,
                           *std::min_element(begin_it, end_it),
                           *std::max_element(begin_it, end_it),
                           sum / il.size());
}

template<typename A, typename B>
auto zip(const A& a, const B& b)
{
    auto z([](auto ... xs){
        return [xs...](auto ... ys){
            return std::tuple_cat(std::make_tuple(xs,ys)...);
        };
    });
    return std::apply(std::apply(z,a),b);
}

int main()
{
    auto student_desc(std::make_tuple("ID", "Name", "GPA"));
    auto student(std::make_tuple(123456, "John Doe", 3.7));
    std::cout << student_desc << '\n' << student << '\n';

    std::cout << std::tuple_cat(student_desc, student) << '\n';

    auto zipped(zip(student_desc, student));
    std::cout << zipped << '\n';
    auto numbers = {0.0, 1.0, 2.0, 3.0, 4.0};
    std::cout << zip(std::make_tuple("Sum", "Minimum", "Maximum", "Average"), sum_min_max_avg(numbers)) << '\n';
}

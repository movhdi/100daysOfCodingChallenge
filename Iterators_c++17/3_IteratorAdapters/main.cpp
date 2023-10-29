#include <deque>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

int main()
{
    std::deque<int> v;
    std::istream_iterator<int> begin_it{std::cin};
    std::istream_iterator<int> end_it;
    std::copy(begin_it, end_it, std::back_inserter(v));
    std::istringstream sstr{"1234 456 789"};
    auto deque_middle_iterator(std::next(std::begin(v), static_cast<int>(v.size() / 2)));
    // objective: copy parsed integers from input string stream to the deque middle position
    std::copy(std::istream_iterator<int>{sstr}, {}, std::insert_iterator<std::deque<int>>(v, deque_middle_iterator));
    std::initializer_list<int> il{-1, -2, -3};
    std::front_insert_iterator<std::deque<int>> fii(v);
    std::copy(std::begin(il), std::end(il), fii);
    for (const auto &it : v)
    {
        std::cout << it << ", ";
    }
    std::cout << std::endl;
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>{std::cout, ", "});
    std::cout << std::endl;
    return 0;
}

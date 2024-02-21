#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <iterator>

struct book
{
    int id;
    std::string title; 
    std::string author;
};

template <typename T>
auto select(std::vector<book> vec, std::function<T(book const &)> pred)
{
    std::vector<T> result;
    std::transform(std::begin(vec), std::end(vec), std::back_inserter(result), pred);    
    return result;
}

int main()
{
    std::vector<book> books {
        {101, "Fundamentals of Power Electronics", "Robert Erickson"},
        {102, "Op Amps for everyone", "Texas Instrument"},
        {103, "C++ Concurrency in Action", "Anthony Williams"}
    };
    auto result = select<std::string>(books, [](book const & b){return b.title;});
    std::copy(std::begin(result), std::end(result), std::ostream_iterator<std::string>{std::cout, "\n"});
}
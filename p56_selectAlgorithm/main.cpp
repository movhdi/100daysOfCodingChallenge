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
/*
                                                                              // -------------------making type from the result of callable (F&) Typr, calling (T const &) Type ---------------//
                                                                                                      //---------F &----------------//-----------------T const &--------------//
template <typename T,typename A, typename F, typename R = typename std::decay<typename std::result_of<typename std::decay<F>::type&(typename std::vector<T, A>::const_reference)>::type>::type>
std::vector<R> select(std::vector<T,A> const & vec, F&& f)
{
    std::vector<R> result;
    std::transform(std::cbegin(vec), std::cend(vec), std::back_inserter(result), std::forward<F>(f));    
    return result;
}

*/

// My own minimalistic simple R type deduction  
template<typename T, typename F, typename R = std::decay_t<std::result_of_t<F(T const &)>>>
std::vector<R> select(std::vector<T> const & vec, F&& f)
{
    std::vector<R> result;
    std::transform(std::cbegin(vec), std::cend(vec), std::back_inserter(result), std::forward<F>(f));    
    return result;
}

int main()
{
    std::vector<book> books {
        {101, "Fundamentals of Power Electronics", "Robert Erickson"},
        {102, "Op Amps for everyone", "Texas Instrument"},
        {103, "C++ Concurrency in Action", "Anthony Williams"}
    };
    auto result = select(books, [](book const & b){return b.title;});
    std::copy(std::begin(result), std::end(result), std::ostream_iterator<std::string>{std::cout, "\n"});
}
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>


double truncated_mean(std::vector<int> ratings, double const percent)
{
    std::sort(std::begin(ratings), std::end(ratings));
    auto deletionNumber = static_cast<size_t> (ratings.size() * percent);
    auto first = std::begin(ratings);
    ratings.erase(first, std::next(first,deletionNumber));
    auto last = std::end(ratings);
    ratings.erase(std::prev(last, deletionNumber), last);
    auto sum = std::accumulate(std::begin(ratings), std::end(ratings), 0);
    return sum / static_cast<double> (ratings.size());
}


struct movie
{
    int id;
    std::string name;
    std::vector<int> ratings;
};

void print_movie_ratings(std::vector<movie> movies)
{
    for (auto & item : movies)
    {
        std::cout << item.name << " : "
                  << std::fixed << std::setprecision(1) << truncated_mean(item.ratings, 0.05f) << std::endl;
    }

}
int main()
{
    std::vector<movie> movies
    {
        {101, "Pulp Fiction", {10, 9, 10, 9, 9, 8, 7, 10, 5, 9, 9, 8}},
        {102, "Django Unchained", {10, 5, 7, 8, 9, 8, 9, 10, 10, 5, 9, 8, 10}},
        {103, "Interstellar", {10, 10, 10, 9, 3, 8, 8, 9, 6, 4, 7, 10}}
    };
    print_movie_ratings(movies);
}

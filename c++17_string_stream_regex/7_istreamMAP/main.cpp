#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>

struct meme
{
    std::string description;
    size_t year;
};


std::istream& operator>>(std::istream &is, meme &m)
{
    return is >> std::quoted(m.description) >> m.year;
}

std::istream& operator>>(std::istream &is, std::pair<std::string, meme> &p)
{
    return is >> std::quoted(p.first) >> p.second; // first is key, second is meme type! so we need overload for meme!
}



int main()
{
    std::map<std::string, meme> m;
    std::copy(std::istream_iterator<std::pair<std::string, meme>>{std::cin}, {}, std::inserter(m,std::end(m)));
    auto maxlength([](size_t oldmax, const auto &b){return std::max(oldmax, b.first.length());});
    auto width{std::accumulate(std::begin(m), std::end(m), 0u, maxlength)};
    for (const auto &[meme_name, meme_desc] : m)
    {
        const auto&[desc, year] = meme_desc;
        std::cout <<  std::left << std::setw(static_cast<int> (width))
                  << meme_name << ": " << desc << ", " << year << std::endl;
    }

    return 0;
}

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>

std::string filter_ws(const std::string &s)
{
    std::string whitespace{"\n\t\r "};
    const auto start_idx(s.find_first_not_of(whitespace));
    const auto end_idx(s.find_last_not_of(whitespace));
    if (start_idx == std::string::npos)
    {
        return {};
    }
    return s.substr(start_idx, end_idx); // at this moment I think it return a single word only
}

std::multimap<size_t, std::string> get_sentence_length(const std::string &content)
{
    std::multimap<size_t, std::string> ret;
    const auto it_end(std::end(content));
    auto it1(std::begin(content));
    auto it2(std::find(it1, it_end, '.'));
    while (it1 != it2 && std::distance(it1, it2) > 0)
    {
        std::string s{filter_ws(
           {it1, it2})}; // iterators from std::string point to individual characters so {it1, it2} gives a substring
        if (s.length() > 0)
        {
            const auto words(std::count(s.begin(), s.end(), ' ') + 1);
            ret.emplace(std::pair<size_t, std::string>(words, std::move(s)));
        }

        it1 = std::next(it2 + 1);
        it2 = std::find(it1, it_end, '.');
    }
    return ret;
}


int main()
{
    std::cin >> std::noskipws;
    std::string content{std::istream_iterator<char>{std::cin},{}};
    for (const auto &[words, sentences] : get_sentence_length(content))
    {
        std::cout << words <<"words: " << sentences << std::endl;
    }


    return 0;
}

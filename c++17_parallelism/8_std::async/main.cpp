#include <algorithm>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <string>


static std::map<char, size_t> histogram(const std::string& s)
{
    std::map<char, size_t> histo;
    for (const auto &ch : s)
    {
        histo[ch]++;
    }
    return histo;
}

static std::string sorted(std::string s)
{
    std::sort(std::begin(s), std::end(s));
    return s;
}

static bool is_vowel(char c)
{
    std::string vowel("aeuio");
    return std::end(vowel) != std::find(std::begin(vowel),std::end(vowel), c);
}
static size_t vowels(const std::string &s)
{
    return std::count_if(std::begin(s), std::end(s), is_vowel);
}


int main()
{
    std::cin.unsetf(std::ios::skipws);
    std::string input(std::istream_iterator<char>{std::cin}/*first iterator*/, {} /*last iterator*/);
    input.pop_back();
    auto hist (std::async(std::launch::async, histogram, input));
    auto sorted_str (std::async(std::launch::async, sorted, input));
    auto vowels_count (std::async(std::launch::async, vowels, input));

    for (auto &[c, count] : hist.get())
    {
        std::cout << c << ": " << count << '\n';
    }
    std::cout << "Sorted string: " << sorted_str.get() << '\n';
    std::cout << "Vowels count: " << vowels_count.get() << '\n';
}

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>


std::string filter_punctuation(const std::string &s)
{
    std::string filter{".,;: "};
    const auto idx_start(s.find_first_not_of(filter));
    const auto idx_end(s.find_last_not_of(filter));
    return s.substr(idx_start, idx_end - idx_start + 1);
}

int main()
{
    std::map<std::string, size_t> words;
    int max_word_length{0};

    std::string s;
    while (std::cin >> s)
    {
        const auto filtered(filter_punctuation(s));
        max_word_length = std::max<int>(max_word_length, filtered.length());
        ++words[filtered];
    }
    std::vector<std::pair<std::string, size_t>> word_counts;
    word_counts.reserve(words.size());
    // std::move(words.begin(), words.end(), std::back_inserter(word_counts)); // or

    std::back_insert_iterator<std::vector<std::pair<std::string, size_t>>> outputIteratorforVector(
        word_counts); // this part could be eliminated but I tend to put for the sake of clarity
    std::move(words.begin(), words.end(), outputIteratorforVector);
    std::function customCompare = [](std::pair<std::string, size_t> &a, std::pair<std::string, size_t> &b) {
        return a.second > b.second;
    };
    std::sort(word_counts.begin(), word_counts.end(), customCompare);

    std::cout << "# " << std::setw(max_word_length) << "<WORD>" <<" #COUNT" << '\n';
    for (const auto &[word, count] : word_counts)
    {
        std::cout << std::setw(max_word_length+2) << word << " #" << count << '\n';
    }

    return 0;
}

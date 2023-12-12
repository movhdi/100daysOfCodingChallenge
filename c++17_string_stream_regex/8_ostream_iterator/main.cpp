#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct bork
{
    size_t borks;
    std::string data;
    bork(size_t i): borks(i) {}
    void print(std::ostream& os) const
    {
        std::fill_n(std::ostream_iterator<std::string>{os, " "}, borks, "borks!" );
        std::cout << '\n';
    }
};

std::ostream& operator<<(std::ostream &os, const bork &b)
{
    b.print(os);
    return os;
}

int main()
{
    const std::vector<int> v{1, 2, 3, 4, 5, 6};
    std::ostream_iterator<int> oit{std::cout};
    for (const auto &it : v)
    {
        *oit = it;
    }
    std::cout << '\n';

    std::ostream_iterator<int> oit_comma{std::cout , ", "};
    for (const auto &it : v)
    {
        *oit_comma = it;
    }

    std::cout << '\n';
    std::copy(std::begin(v), std::end(v), oit);
    std::cout << '\n';
    std::copy(std::begin(v), std::end(v), oit_comma);
    std::cout << '\n';
    auto word_num([](int i)->std::string{
        std::unordered_map<int, std::string> m {{1,"one"}, {2,"two"}, {3, "three"}, {4, "four"}, {5, "five"}};
        const auto match(m.find(i));
        if (match == std::end(m))
        {
            return "Unknown digit";
        }
        return m[i];
    });
    std::transform(std::begin(v), std::end(v), std::ostream_iterator<std::string>{std::cout, ", "}, word_num);
    std::cout << '\n';
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<bork>{std::cout});
    return 0;
}

/*
Moral of the story:

// Here is a simplified version of std::copy()

template <class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt d_first) {
    while (first != last) {
        *d_first = *first;
        ++first;
        ++d_first;
    }
    return d_first;
}

// Pseudocode for std::copy
template <class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt d_first) {
    while (first != last) {
        // Implicit conversion happens here
        bork temp(*first);  // Convert int to bork using bork's constructor

        // Write the bork object to the output stream
        *d_first = temp;

        // Move to the next element in the source range
        ++first;

        // Move to the next position in the output stream
        ++d_first;
    }
    return d_first;
}

*/

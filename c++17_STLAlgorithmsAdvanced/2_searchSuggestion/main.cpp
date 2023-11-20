#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
class trie
{
private:
    std::map<T, trie> tries;

public:
    // trie(/* args */);
    // ~trie();
    // insert function
    template <typename It>
    void insert(It it, It end_it)
    {
        // terminating condition
        if (it == end_it)
        {
            return;
        }
        tries[*it].insert(std::next(it), end_it);
    }
    template <typename C>
    void insert(C &container)
    {
        insert(std::begin(container), std::end(container));
    }
    void insert(const std::initializer_list<T> &il)
    {
        insert(std::begin(il), std::end(il));
    }
    // print function
    void print(std::list<T> l) const
    {
        // terminating condition first: if we reach end of tries (map of maps) we are at leaf node so we can print it
        if (tries.empty())
        {
            std::copy(std::begin(l), std::end(l), std::ostream_iterator<T>{std::cout, " "});
            std::cout << std::endl;
        }
        // now implementing the recursion
        for (const auto &node : tries)
        {
            l.push_back(node.first);
            node.second.print(l);
            l.pop_back();
        }
    }
    void print() const
    {
        std::list<T> l;
        print(l);
    }
    // subtrie function
    template <typename It>
    std::optional<std::reference_wrapper<const trie>> subtrie(It it, It end_it)
    {
        // first of all : terminating condition, we should terminate the recursion if we are at the leaf node
        if (it == end_it)
        {
            return ref(*this);
        }
        const auto found(tries.find(*it));
        // terminating condition if no match exists
        if (found == std::end(tries))
        {
            return {};
        }
        // finally the recursion itself
        return (*found).second.subtrie(std::next(it), end_it);
    }
    template <typename C>
    std::optional<std::reference_wrapper<const trie>> subtrie(const C &container)
    {
        return subtrie(std::begin(container), std::end(container));
    }
};

static void prompt()
{
    std::cout << "next input please:" << '\n';
}

int main()
{
    trie<std::string> t;
    std::fstream infile("database.txt");

    for (std::string line; std::getline(infile, line);)
    {
        std::stringstream ssr{line};
        t.insert(std::istream_iterator<std::string>{ssr}, {}); //
    }

    prompt();
    for(std::string line; std::getline(std::cin, line);)
    {
        std::stringstream ssr{line};
        if(auto st(t.subtrie(std::istream_iterator<std::string>{ssr}, {})); st)
        {
            std::cout << "Your suggestions are as follows:\n";
            st->get().print();
        }
        else
        {
            std::cout << "No suggestion found!\n";
        }
        std::cout << "---------------\n";
        prompt();
    }
    return 0;
}

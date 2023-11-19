#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
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
    template <typename It>
    void insert(It it, It end)
    {
        if (it == end) // this if statement is the terminating condition
        {
            return;
        }
        tries[*it].insert(std::next(it), end); // here we access the map at the intended key (here a word in our initializer_list)
    }
    template <typename C>
    void insert(const C &container)
    {
        insert(std::begin(container), std::end(container));
    }
    void insert(const std::initializer_list<T> &il)
    {
        insert(std::begin(il), std::end(il));
    }
    void print(std::vector<T> &v) const
    {
        if (tries.empty()) // this is the terminating condition
        {
            std::copy(
                std::begin(v),
                std::end(v),
                std::ostream_iterator<T>{std::cout,
                                         ", "});
            std::cout << std::endl;
        }
        for (const auto &node : tries)
        {
            v.push_back(node.first); // this is where all data in the lifetime of recursion is recorded
            node.second.print(v);
            v.pop_back(); // this empties the vector on the way back to first recursive calling function instance
        }
    }
    void print() const
    {
        std::vector<T> v;
        print(v);
    }
    template <typename It>
    std::optional<std::reference_wrapper<const trie>> subtrie(It it, It end) const
    {
        if(it  == end)
        {
            return ref (*this);
        } // as any other recursion, this is the terminating condition
        auto found (tries.find(*it));
        if (found == std::end(tries))
        {
            return {};
        }
        return found->second.subtrie(std::next(it),end);
    }
    template <typename C>
    auto subtrie(const C &container)
    {
        return subtrie(std::begin(container), std::end(container));
    }
};

int main(int argc, char *argv[])
{
    trie<std::string> t;
    t.insert({"hi", "how", "are", "you!"});
    t.insert({"hi", "i", "am", "great", "thanks"});
    t.insert({"what", "are", "you", "doing"});
    t.insert({"i", "am", "watching", "a", "movie"});
    std::cout << "recorder sentences:\n";
    t.print();
    std::cout << "\npossible suggestions after \"hi\":\n";
    if (auto st(t.subtrie(std::initializer_list<std::string>{"hi"}));st)
    {
        st->get().print();
    }

    (void)argc;
    (void)argv;
    return 0;
}

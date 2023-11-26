#include <iostream>
#include <mutex>
#include <sstream>
#include <thread>
#include <vector>

struct pcout : public std::stringstream
{
    static inline std::mutex cout_mutex; // The static keyword ensures that there is only one instance of this mutex
                                         // shared among all instances of pcout.
                                         // The inline does not have serious effect in this context!
    ~pcout()
    {
        std::lock_guard<std::mutex> l{cout_mutex};
        std::cout << rdbuf();
        std::cout.flush();
    }
};

static void print_cout(int id)
{
    try
    {
        std::cout << "cout hello from " << id << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

static void print_pcout(int id)
{
    try
    {
        pcout{} << "pcout hello from " << id << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    std::vector<std::thread> v;
    for (size_t i = 0; i < 10; ++i)
    {
        v.emplace_back(print_cout, i);
    }
    for (auto &t : v)
    {
        t.join();
    }
    std::cout << "================\n";
    for (size_t i = 0; i < 10; ++i)
    {
        v.emplace_back(print_pcout, i);
    }
    for (auto &t : v)
    {
        t.join();
    }
    return 0;
}

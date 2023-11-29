#include <chrono>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <queue>
#include <sstream>
#include <thread>
#include <vector>


struct pcout : public std::stringstream
{
    static inline std::mutex mu; // this mutex has been difined to synchronise shared use of std::cout only
    ~pcout()
    {
        std::lock_guard<std::mutex> l{mu};
        std::cout << rdbuf();
    }
};

using std::chrono_literals::operator""ms;
using std::chrono_literals::operator""s;
std::queue<size_t> q;
std::mutex q_mutex;
bool production_stopped{false};

std::condition_variable go_produce;
std::condition_variable go_consume;

static void producer(size_t id, size_t items, size_t stock)
{
    for (size_t i = 0; i < items; i++)
    {
        std::unique_lock<std::mutex> l{q_mutex};
        go_produce.wait(l, [&]() { return q.size() < stock; });
        q.push(id * 100 + i);
        pcout{} << "   producer " << id << "--> item " << std::setw(3) << q.back() << '\n';
        go_consume.notify_all();
        std::this_thread::sleep_for(90ms);
    }
    pcout{} << "EXIT: Producer " << id << '\n';
}

/*
The purpose of releasing the lock during the wait is to allow other threads to make progress on shared resources.
If the lock were not released, other threads would be blocked from acquiring the lock, potentially leading to deadlock
situations where threads are waiting indefinitely for resources held by other threads.
*/
static void consumer(size_t id)
{
    while (!production_stopped || !q.empty())
    {
        std::unique_lock<std::mutex> l{q_mutex};
        if (go_consume.wait_for(l,1s, [](){return !q.empty();}))
        {
            pcout{} <<"          item " << std::setw(3) << q.front() <<"--> consumer " << id << std::endl;
            q.pop();
            go_produce.notify_all();
            std::this_thread::sleep_for(100ms);
        }
    }
    pcout{} << "EXIT: consumer " << id << '\n';
}

int main()
{
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;
    for (size_t i = 0; i < 3; i++)
    {
        producers.emplace_back(producer, i, 10, 4);
    }
    for (size_t i = 0; i < 5; i++)
    {
        consumers.emplace_back(consumer, i);
    }
    for (auto &t : producers)
    {
        t.join();
    }
    production_stopped = true;
    for (auto &t : consumers)
    {
        t.join();
    }
}

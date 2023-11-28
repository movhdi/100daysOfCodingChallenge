#include <iostream>
#include <queue>
#include <thread>
#include <condition_variable>
#include <tuple>

using std::chrono_literals::operator""ms;

std::queue<size_t> que;
std::mutex mut;
std::condition_variable cv;
bool finished {false};

static void producer(size_t items)
{
    for (size_t i = 0; i < items; i++)
    {
        std::this_thread::sleep_for(100ms);
        {
            std::lock_guard<std::mutex> l{mut};
            que.push(i);
        }
        cv.notify_all(); // This function wakes the consumer up
    }
    {
        std::lock_guard<std::mutex> l{mut};
        finished = true;
    }
    cv.notify_all();
}

static void consumer()
{
    while (!finished)
    {
        std::unique_lock<std::mutex> l{mut};
        cv.wait(l,[](){return !que.empty() || finished;}); // The cv.wait call unlocks the lock and waits until
                                                           // the condition described by the predicate function holds.
                                                           // Predicate tells if the producer thread is still alive and
                                                           // if there is anything to consume in the queue
        while (!que.empty())
        {
            std::cout <<"Got " << que.front() << "from queue.\n";
            que.pop();
        }
    }
}


int main()
{
    std::thread t1(producer, 10);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    std::cout<< "finished.\n";
}

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <iterator>
#include <chrono>
#include <algorithm>

template <class T>
class double_buffer
{
    typedef T           value_type;
    typedef T&          reference;
    typedef T const &   const_reference;
    typedef T*          pointer;
private:
    std::vector<T> rdbuff;
    std::vector<T> wrbuff;
    mutable std::mutex mt; // The point is that, even in a const object, the mutex must be able to be locked/unlocked.
                           // So even in a const object, the mutex must be non-const. Hence, it must be declared mutable.
public:
    double_buffer(/* args */) = delete;
    double_buffer(size_t buffer_size) : rdbuff(buffer_size), wrbuff(buffer_size) {}

    template <typename Output>
    void read(Output& it) const
    {
        std::unique_lock<std::mutex> lg(mt);
        std::copy(std::begin(rdbuff), std::end(rdbuff), it);
    }

    void write(T const * const ptr, size_t size)
    {
        std::unique_lock<std::mutex> lg(mt);
        auto length = std::min(size, wrbuff.size());
        // for (size_t i = 0; i < length; i++, ++ptr)
        // {
        //     wrbuff.insert(std::end(wrbuff),*ptr);
        // }
        std::copy(ptr, ptr + length, wrbuff.begin());
        wrbuff.swap(rdbuff);
    }

    ~double_buffer(){}
};


template <typename T>
void print_buffer(double_buffer<T> const & buff)
{
    std::ostream_iterator<T> oit(std::cout, " ");
    buff.read(oit);
    std::cout << std::endl;
}


int main()
{
    double_buffer<int> buf(10);

    std::thread t ([&buf](){
        for (int i = 0; i < 1000; i+=10)
        {
            int data[] ={ i, i+1, i+2, i+3, i+4,
                          i+5, i+6, i+7, i+8, i+9};
            buf.write(data, 10);
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(100ms);
        }
    });

    auto start =std::chrono::system_clock::now();
    do
    {
        print_buffer(buf);
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(150ms);
    } while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start).count() < 12);
    t.join();
}

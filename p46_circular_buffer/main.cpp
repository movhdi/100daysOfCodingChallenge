#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
class circular_buffer
{
private:
std::vector<T> data;
    size_t stored_count{} ;
    size_t buffer_size;
public:
    circular_buffer() = delete;
    explicit circular_buffer(size_t size) noexcept : buffer_size(size)
    {
        data.resize(buffer_size);
    }
    void push(const T& t) noexcept
    {
        // pseudocode :
        // if the size limit is not reached
        // insert the element
        // otherwise
        // pop one element from the back
        // shift all of the elements 
        // insert the element
        try
        {
            if (stored_count < data.size())
            {
                data.emplace(std::begin(data), t);
                data.resize(buffer_size);
                ++stored_count;
            }
            else
            {
                data.erase(data.end() - 1);
                data.emplace(std::begin(data), t);
                data.resize(buffer_size);
            }   
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    T pop() noexcept
    {
        T temp = data[stored_count - 1];
        data.erase(data.begin() + static_cast<int>(stored_count-1));
        --stored_count;
        data.resize(buffer_size);
        return temp;
    }
    void print() const
    {
        std::copy(std::begin(data), std::end(data), std::ostream_iterator<T>{std::cout, ", "});
        std::cout << std::endl;
    }
    ~circular_buffer() noexcept
    {}
};


int main()
{
    circular_buffer<int> cbuf(5);
    cbuf.push(1);
    cbuf.push(2);
    cbuf.push(3);
    cbuf.print();
    auto item = cbuf.pop();
    cbuf.print();
    cbuf.push(4);
    cbuf.push(5);
    cbuf.push(6);
    cbuf.print();
    cbuf.push(7);
    cbuf.print();
    cbuf.push(8);
    cbuf.print();

    item = cbuf.pop();
    std::cout << std::endl << item << '\n';
    cbuf.print();
    item = cbuf.pop();
    std::cout << std::endl << item << '\n';
    cbuf.print();
    item = cbuf.pop();
    std::cout << std::endl << item << '\n';
    cbuf.print();
    item = cbuf.pop();
    std::cout << std::endl << item << '\n';
    cbuf.print();
    item = cbuf.pop();
    std::cout << std::endl << item << '\n';
    cbuf.print();
    cbuf.push(9);
    cbuf.print();
}
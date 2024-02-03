#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
class circular_buffer;
template <class T>
class circular_buffer_iterator
{
    // these definitions are needed to make it possible for STL algorithms use our iterator class gracefully
    using self_type = circular_buffer_iterator;
    using value_type = typename std::vector<T>::value_type;
    using reference = typename std::vector<T>::reference;
    using const_reference = typename std::vector<T>::const_reference;
    using pointer =  typename std::vector<T>::pointer;
    using difference_type =  typename std::vector<T>::ptrdiff_t;
    using iterator_category = std::random_access_iterator_tag;
private:
    circular_buffer<T> const & buffer_;
    size_t _index;
    bool last_;
public:
    circular_buffer_iterator(circular_buffer<T> const & buf, size_t const pos, bool const last) {}

    // operator++()
    circular_buffer_iterator& operator++()
    {
        if (last_)
        {
            throw std::out_of_range("Iterator  cannot be incremented past the end of range.");
        }
        _index = ++_index % buffer_.container_size;
        last_ = _index == ((buffer_.head + 1) % buffer_.container_size); // ???
        return *this;
    }

    // operator++(int)
    circular_buffer_iterator& operator++(int) // this is a dummy parameter passed as trick to make postincrement
    {
        auto tmp = *this; // the return value should be the current object before increment!!
        ++*this;
        return tmp;
    }

    // operator*()
    T operator*() const
    {
        return buffer_.data[_index];
    }

    // operator->()
    const_reference operator->() const // cppreference.org: The overload of operator -> must either return a raw pointer, or return an object
                   // (by reference or by value) for which operator -> is in turn overloaded.
    {
        return buffer_.data[_index];
    }
    // operator==()
    bool operator==(const self_type &other)
    {
        return _index == other._index && last_ == other.last_;
    }
    // operator!=()
    bool operator!=(self_type const &other)
    {
        return !(*this == other);
    }

    ~circular_buffer_iterator() {}
};

template <class T>
class circular_buffer
{
    typedef circular_buffer_iterator<T> const_iterator;
    circular_buffer() = delete;

public:
    explicit circular_buffer(size_t size) noexcept : container_size(size), data(container_size)
    {
    }
    void push(const T &t) noexcept
    {
        // making efficient push method
        // pseudo code :
        // we use random access [] operator
        // increase head by 1
        // if head is equal to container_size start from 0
        // insert the new element in the head(th) place of the vector
        // if logical size of buffer is less than container size, increase it by 1
        head = (head + 1) % container_size;
        data[head] = t;
        if (buffer_size < container_size)
        {
            ++buffer_size;
        }
    }

    T pop() noexcept
    {
        // we need to find the oldest (nth older) element
        // pseudo code :
        // decrease logical size of buffer by 1
        // return the element at position: [container_size - (Buffer_size - head)] % container_size
        --buffer_size;
        return data[(container_size + head - buffer_size ) % container_size];
    }

    // begin() method
    circular_buffer_iterator<T> begin()
    {

    }

    // end() method
    circular_buffer_iterator<T> end()
    {

    }

    void print() const
    {
        std::copy(std::begin(data), std::end(data), std::ostream_iterator<T>{std::cout, ", "});
        std::cout << std::endl;
    }
    ~circular_buffer() noexcept
    {
    }
private:
    size_t container_size;
    std::vector<T> data;
    size_t total_stored_count{};
    size_t buffer_size{};
    size_t head = -1;
    friend class circular_buffer_iterator<T>; // making the iterator class a friend, so that we can use private methods
                                              // of this class there also
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
    std::cout << std::endl
              << item << '\n';
    cbuf.print();
    item = cbuf.pop();
    std::cout << std::endl
              << item << '\n';
    cbuf.print();
    item = cbuf.pop();
    std::cout << std::endl
              << item << '\n';
    cbuf.print();
    item = cbuf.pop();
    std::cout << std::endl
              << item << '\n';
    cbuf.print();
    item = cbuf.pop();
    std::cout << std::endl
              << item << '\n';
    cbuf.print();
    cbuf.push(9);
    cbuf.print();
}

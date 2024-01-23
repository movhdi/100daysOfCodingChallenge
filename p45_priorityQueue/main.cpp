#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <cassert>



template <typename T, typename compare = std::less<T>> // a min heap is implemented!
class priority_queue
{
private:
    std::vector<T> data;
    compare comparer;
public:
    // empty
    bool empty() const
    {
        return data.empty();
    }
    // pop
    void pop(void)
    {
        if (!this->empty())
        {
            std::pop_heap(std::begin(data), std::end(data), comparer);
            data.pop_back();
        }
    }
    // push
    void push(const T t)
    {
        data.push_back(t);
        std::push_heap(std::begin(data), std::end(data), comparer);
    }
    // top
    const T& top(void) const
    {
        return data.front();
    }
    // swap
    void swap(priority_queue& other)
    {
        this->data.swap(other->data);
        std::swap(comparer) = other->comparer;
    }
    // size
    typename std::vector<T>::size_type size() const
    {
        return data.size();
    }

    priority_queue()
    {}
    ~priority_queue() noexcept
    {
    }
};


int main()
{
    priority_queue<int> q;
    for (int i : {1, 5, 3, 1, 13, 21, 8})
    {
        q.push(i);
    }
    assert(!q.empty());
    assert(q.size() == 7);

    while (!q.empty())
    {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

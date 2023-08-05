#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <stdexcept>


// Things you need inorder to use std::move
// 1. a 
template <class T, size_t R, size_t C>
class array2d
{
    typedef T                   value_type;
    typedef value_type*         iterator;
    typedef value_type const *  const_iterator;
    std::vector<T> arr;
public:
    array2d():arr(R*C){}
    explicit array2d(std::initializer_list<T> list)
    {
        if(list.size() == R*C)
        {
            arr = list;
        }else 
        {
            throw std::out_of_range("The array entered is out of range!");
        }
    }

    array2d(array2d&& other)
    {
        this->arr = other.arr;
    }
    
    size_t size(size_t const rank)
    {
        if(rank == 1)
        {
            return R;
        }else if(rank == 2)
        {
            return C;
        }
        throw std::out_of_range("Rank is out of range!");
    }

    constexpr T& operator()(size_t row, size_t col)
    {
        return arr.at((row-1)*C+col-1);
    }

    // constexpr T const & operator() (size_t const r, size_t const c) const
    // {
    //     return arr[r*C + c];
    // }
    
    void fill(T i)
    {
        for(auto& it : this->arr)
        {
            it = i;
        }
    }

    void swap(array2d& other) noexcept
    {
        this->arr.swap(other.arr);
    }
};

int main()
{
    // element access
    array2d<int, 2,3> a({1,2,3,
                        4,5,6});
    // std::cout << a(2,3) << std::endl;
    for(size_t i = 1; i <= a.size(1); i++)
    {
        for(size_t j = 1; j <= a.size(2); j++)
        {
            a(i,j) *= 2;
        }
    }

    std::cout << "Printing a defind as {1,2,3,4,5,6}:\n";
    for(size_t i = 1; i <= a.size(1); i++)
    {
        for(size_t j = 1; j <= a.size(2); j++)
        {
            std::cout << a(i,j) << ", ";
        }
        std::cout << std::endl;
    }
    // iterating 
    // std::copy(std::begin(a),std::end(a),std::ostream_iterator<int>(std::cout, " "));

    // filling
    array2d<int,2,3> b;
    b.fill(1);
    std::cout << "Result of using fill(int i) method:\n";

    for(size_t i = 1; i <= b.size(1); i++)
    {
        for(size_t j = 1; j <= b.size(2); j++)
        {
            std::cout << b(i,j) << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // swapping
    a.swap(b);

    // moving
    array2d<int, 2, 3> c(std::move(b));
    std::cout << "Result of using std::move():\n";
    for(size_t i = 1; i <= c.size(1); i++)
    {
        for(size_t j = 1; j <= c.size(2); j++)
        {
            std::cout << c(i,j) << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "Printing a after using swap method on b.swap(a):\n";
    for(size_t i = 1; i <= a.size(1); i++)
    {
        for(size_t j = 1; j <= a.size(2); j++)
        {
            std::cout << a(i,j) << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}


/*  Morals of the story
    1.  for the function fill, I first used the for loop like this:
        for(auto it : this->arr)
        {
            it = i;
        }
        I tried it using either it or *it, neither one worked. I searched and found out the true way of coding this is:
        for(auto& it : this->arr)
        {
            it = i;
        }
        It worked.
    2.  
*/
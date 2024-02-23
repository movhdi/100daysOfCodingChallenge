#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

/*
 ALGORITHM:

 partitioning produces a division into two consecutive non empty sub-ranges, in_such_a_way_that :
 no element of the first sub-range is greater than any element of the second sub-range.

 After applying this partition, quicksort then _recursively_ sorts the sub-ranges, possibly after
 excluding from them an element at the point of division that is at this point known to be already in its final location.

 1. If the range has fewer than two elements, return immediately as there is nothing to do. Possibly for other very short
    lengths a special-purpose sorting method is applied and the remainder of these steps skipped.

 2. Otherwise pick a value, called a pivot, that occurs in the range
    (the precise manner of choosing depends on the partition routine, and can involve randomness).

 3. Partition the range: reorder its elements, while determining a point of division, so that all elements
    with values less than the pivot come before the division, while all elements with values greater than
    the pivot come after it; elements that are equal to the pivot can go either way. Since at least one instance
    of the pivot is present, most partition routines ensure that the value that ends up at the point of division
    is equal to the pivot, and is now in its final position (but termination of quicksort does not depend on this,
    as long as sub-ranges strictly smaller than the original are produced).

 4. Recursively apply the quicksort to the sub-range up to the point of division and to the sub-range after it, 
    possibly excluding from both ranges the element equal to the pivot at the point of division. 
    (If the partition produces a possibly larger sub-range near the boundary where all elements are known to be
    equal to the pivot, these can be excluded as well.)
*/

/*
 Pseudo-code:

    quicksort(A, lo, hi)
    {
        if(lo >= hi || lo < 0)
        {
            return;
        }
        auto p = partition(A, lo, hi);
        quicksort(A, lo, p-1);
        quicksort(A, p+1, hi);
    }

    partition(A, lo, hi)
    {
        auto pivot = A[hi];
        auto i = lo -1;
        for(auto j = lo; j <= hi-1; ++j)
        {
            if (A[j] <= pivot)
            {
                ++i;
                swap(A[i], A[j]);
            }
        }
        ++i;
        swap(A[i], A[j]);
        return i;
    }
*/
template<typename It>
auto partition(It & lo, It & hi)
{
    auto pivot = *hi; 
    auto i = lo - 1;
    for (auto j = lo; j <= hi-1; ++j)
    {
        if (*j <= pivot)
        {
            ++i;
            std::iter_swap(i, j);
        }
    }
    ++i;
    std::iter_swap(i, hi);
    return i;
}

template <typename Con, typename It>
void quicksort(Con & c, It lo, It hi)
{
    if(lo >= hi || lo < std::begin(c))
    {
        return;
    }
    auto p = partition(lo, hi);
    quicksort(c, lo , p-1);
    quicksort(c, p+1, hi);
}

int main()
{
    std::vector<int> v{100, 24, 74, 21, 14, 85, 60, 40,1,33, 57, 49, 69};
    quicksort(v, std::begin(v), std::end(v)-1);
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>{std::cout, ", "});
    std::cout << std::endl;
    return 0;
}
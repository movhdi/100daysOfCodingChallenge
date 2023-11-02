#include <iostream>
#include <iterator>
#include <list>

int main()
{
    using namespace std;
    list<int> lst{1, 2, 3, 4, 5};
    copy(rbegin(lst), rend(lst), ostream_iterator<int>{cout, ", "});
    cout << '\n';
    // if a container does not support handy rend and rbegin member functions, we will be using make_reverse_iterator
    copy(make_reverse_iterator(lst.end()), make_reverse_iterator(lst.begin()), ostream_iterator<int>{cout, ", "});
    std::cout << endl;
    return 0;
}

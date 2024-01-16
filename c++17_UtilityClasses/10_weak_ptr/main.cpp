#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <memory>

class Foo
{
public:
    std::string data;
    Foo(std::string d) : data(d)
    {}
    ~Foo()
    {
        std::cout << "DTOR from Foo called!" << data << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const Foo &foo)
{
    os << foo.data;
    return os;
}


template <typename T = std::weak_ptr<Foo>>
void weak_ptr_info(const std::weak_ptr<T> &p)
{
    std::cout << "----------" << std::boolalpha
              << "\nexpired:   " << p.expired()
              << "\nuse_count: " << p.use_count()
              << "\ncontent:   " ;
    if (const auto sp(p.lock()); sp) // why const?
    {
        std::cout << *sp << std::endl;
    }else
    {
        std::cout << "<null>\n";
    }
}

int main()
{
    std::weak_ptr<Foo> weak_foo;
    weak_ptr_info(weak_foo);
    {
        auto shared_foo (std::make_shared<Foo> ("1334"));
        weak_foo = shared_foo;
        weak_ptr_info(weak_foo);
    }
    weak_ptr_info(weak_foo); // no DTOR for weak_ptr ever gets called
}

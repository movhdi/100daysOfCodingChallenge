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
    Foo(std::string d) : data(std::move(d))
    {
        std::cout << "CTOR from Foo called!\n";
    }
    ~Foo()
    {
        std::cout << "DTOR from Foo called!\n";
    }
};

void f(std::shared_ptr<Foo> sp)
{
    std::cout <<"f: use counter at " << sp.use_count() << std::endl;
}

int main()
{
    std::shared_ptr<Foo> fa;
    {
        std::cout << "inner scope begin\n";
        std::shared_ptr<Foo> f1{new Foo{"foo"}};
        auto f2 = std::make_shared<Foo> (("bar"));
        std::cout << "f1's use counter at " << f1.use_count() << std::endl;
        fa = f1;
        std::cout << "f1's use counter at " << f1.use_count() << std::endl;
    }
    std::cout << "back to outer scope\n";
    std::cout << fa.use_count() << '\n';
    std::cout << "first f() call\n";
    f(fa);
    std::cout << "second f() call\n";
    f(std::move(fa));
}

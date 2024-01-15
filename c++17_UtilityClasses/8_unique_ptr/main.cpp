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
    Foo(std::string name) : data(std::move(name))
    {
        std::cout << "CTOR from Foo called!\n";
    }
    ~Foo()
    {
        std::cout << "DTOR from Foo called!\n";
    }
};

void process_item(std::unique_ptr<Foo> p)
{
    if(!p)
    {
        return;
    }
    std::cout << "processing " << p->data << std::endl;
}


int main()
{
    {
        std::unique_ptr<Foo> p1{new Foo{"Foo"}};
        auto p2 = std::make_unique<Foo>("bar");
    }
    process_item(std::make_unique<Foo>("foo1"));
    auto p1 (std::make_unique<Foo> ("foo2"));
    auto p2 (std::make_unique<Foo> ("foo3"));
    process_item(std::move(p1));
    std::cout << "End of main()\n";
}

#include <iostream>
#include <string>
#include <memory>

class Foo
{
    std::string data;
    Foo(std::string d) : data(d)
    {
        std::cout << "CTOR " << data << '\n';
    }
    ~Foo()
    {
        std::cout << "DTOR " << data << std::endl;
    }
public:
    static Foo* create_foo(std::string s)
    {
        return new Foo(std::move(s));
    }
    static void destroy_foo(Foo *p)
    {
        delete p;
    }
    std::string get_data() const
    {
        return data;
    }
};

std::ostream& operator<<(std::ostream& os, const Foo &foo)
{
    os << foo.get_data();
    return os;
}

static std::shared_ptr<Foo> make_shared_foo(std::string s)
{
    return {Foo::create_foo(std::move(s)), Foo::destroy_foo/*does not have () since it is pointer to function*/};
}

static std::unique_ptr<Foo, void(*)(Foo*)> make_unique_foo(std::string s)
{
    return {Foo::create_foo(std::move(s)), Foo::destroy_foo};
}

int main()
{
    auto ps(make_shared_foo("Hello world!"));
    auto pu(make_unique_foo("Hello unique world!"));
}

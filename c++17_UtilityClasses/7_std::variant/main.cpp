#include <algorithm>
#include <any>
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <variant>

class cat
{
    std::string name;

public:
    cat(std::string n) : name{n}
    {
    }
    void meow() const
    {
        std::cout << name << " says meow!\n";
    }
};

class dog
{
    std::string name;

public:
    dog(std::string n) : name{n}
    {
    }
    void woof() const
    {
        std::cout << name << " says woof!\n";
    }
};

using animal = std::variant<cat, dog>;

template <typename T>
bool is_type(const animal &a)
{
    return std::holds_alternative<T>(a);
}

struct animal_voice
{
    void operator()(const dog &d) const
    {
        d.woof();
    }
    void operator()(const cat &c) const
    {
        c.meow();
    }
};


int main()
{
    std::list<animal> l{cat{"Tuba"}, dog{"balu"}, cat{"bobby"}};
    for (const animal &a : l)
    {
        switch (a.index())
        {
        case 0:
            std::get<cat>(a).meow();
            break;
        case 1:
            std::get<dog>(a).woof();
            break;
        }
    }
    std::cout << "---------\n";
    for (const animal &a : l)
    {
        if (const auto d (std::get_if<dog>(&a)); d)
        {
            d->woof();
        }
        else if (const auto c(std::get_if<cat>(&a)); c)
        {
            c->meow();
        }
    }
    std::cout << "---------\n";
    for (const animal &a : l)
    {
        std::visit(animal_voice{}, a);
    }
    std::cout << "---------\n";
    std::cout << "There are " << std::count_if(std::begin(l), std::end(l), is_type<cat>) << " cats and "
              << std::count_if(std::begin(l), std::end(l), is_type<dog>) << " dogs in the list.\n";
}

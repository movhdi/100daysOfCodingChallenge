#include <algorithm>
#include <iostream>
#include <iterator>

class cstring_iterator_sentinel
{
private:
    /* data */
public:
    cstring_iterator_sentinel(/* args */);
    ~cstring_iterator_sentinel();
};

cstring_iterator_sentinel::cstring_iterator_sentinel(/* args */)
{
}

cstring_iterator_sentinel::~cstring_iterator_sentinel()
{
}

class cstring_iterator
{
private:
    const char *s{nullptr};

public:
    cstring_iterator(const char *str);
    ~cstring_iterator();
    char operator*() const
    {
        return *s;
    }
    cstring_iterator &operator++()
    {
        ++s;
        return *this;
    }
    bool operator!=(const cstring_iterator_sentinel) const
    {
        return s != nullptr && *s != '\0';
    }
};

cstring_iterator::cstring_iterator(const char *str)
{
    s = str;
}

cstring_iterator::~cstring_iterator()
{
}

class cstringRange
{
private:
    const char *s{nullptr};

public:
    cstringRange(const char *str);
    ~cstringRange();
    cstring_iterator begin() const
    {
        return cstring_iterator(s);
    }
    cstring_iterator_sentinel end() const
    {
        return {};
    }
};

cstringRange::cstringRange(const char *str)
{
    s = str;
}

cstringRange::~cstringRange()
{
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Please input one parameter" << std::endl;
        return 1;
    }
    for (const auto c : cstringRange{argv[1]})
    {
        std::cout << c;
    }
    std::cout << std::endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>

static constexpr char tolow(char c)
{
    switch (c)
    {
    case 'A'...'Z':
        return c - 'A' + 'a';
        break;

    default:
        return c;
        break;
    }
}

// std::basic_string class accepts three template parameters  : 1 underlying charType, 2 character trait class,3 Allocator type
class lc_traits : public  std::char_traits<char>
{
private:
    /* data */
public:
    static constexpr void assign(char_type &r, const char_type &a)
    {
        r = tolow(a);
    }
    static char_type* copy(char_type *dest, const char_type *src, std::size_t count)
    {
        std::transform(src, src + count, dest, tolow);
        return dest;
    }
};

class ci_traits : public std::char_traits<char>
{
private:
    /* data */
public:
    static constexpr bool eq(char_type r, char_type s)
    {
        return tolow(r) == tolow(s);
    }
    static constexpr bool lt(char_type r, char_type s)
    {
        return tolow(r) < tolow(s);
    }
    static constexpr int compare( const char_type* s1, const char_type* s2,
                    std::size_t count )
    {
        for (;count; ++s1, ++s2, --count)
        {
            const char_type diff(tolow(*s1) - tolow(*s2));
            if (diff < 0)
            {
                return -1;
            }
            if (diff > 0)
            {
                return 1;
            }
        }
        return 0;
    }

    static constexpr const char_type* find( const char_type* ptr, std::size_t count, const char_type& ch )
    {
        const char_type find_c(tolow(ch));
        for (;count != 0;++ptr, --count)
        {
            if (find_c == tolow(*ptr))
            {
                return ptr;
            }
        }
        return nullptr;
    }
};

using lc_string = std::basic_string<char, lc_traits>;
using ci_string = std::basic_string<char, ci_traits>;

std::ostream& operator<<(std::ostream &os, const lc_string &lcs)
{
    return os.write(lcs.data(), lcs.size());
}

std::ostream& operator<<(std::ostream &os, const ci_string &cis)
{
    return os.write(cis.data(), cis.size());
}

int main()
{
    std::cout << "    string: "
              << std::string{"Foo Bar Baz"} << '\n'
              << "lc string: "
              << lc_string{"Foo Bar Baz"} << '\n'
              << "Cis string: "
              << ci_string{"Foo Bar Baz"} << '\n';

    ci_string lc{"MaGiC PaSsWoRd!"};
    ci_string cs{"magic password!"};
    if (lc == cs)
    {
        std::cout << "Passwords Match: \"" << lc << "\" == " << "\"" << cs << "\"\n";
    }
    return 0;
}

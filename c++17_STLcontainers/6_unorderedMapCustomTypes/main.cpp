#include <iostream>
#include <unordered_map>

// #define std_hash_used

struct coord
{
    size_t x;
    size_t y;
};

bool operator==(const coord &lhs, const coord &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

#ifdef std_hash_used
template <>
struct std::hash<coord>
{
    using argument_type = coord;
    using result_type = size_t;

    result_type operator()(const argument_type &c) const
    {
        return static_cast<result_type>(c.x) + static_cast<result_type>(c.y);
    }
};
#else
template <typename T>
struct myhash
{
    using result_type = size_t;
    result_type operator()(const T &c) const
    {
        return static_cast<result_type>(c.x) + static_cast<result_type>(c.y);
    }
};
#endif

int main()
{
#ifdef std_hash_used
    std::unordered_map<coord, int> m{{{0, 0}, 1}, {{0, 1}, 2}, {{2, 1}, 3}};
#else
    std::unordered_map<coord, int, myhash<coord>> m{{{0, 0}, 1}, {{0, 1}, 2}, {{2, 1}, 3}};
#endif
    for (const auto &[key, value] : m)
    {
        std::cout << "{(" << key.x << ", " << key.y << "): " << value << "} ";
    }
    std::cout << std::endl;
    return 0;
}

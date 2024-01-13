#include <algorithm>
#include <array>
#include <exception>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <sstream>
#include <string>
#include <vector>

enum class sex_type
{
    female,
    male
};


class social_number_generator
{
private:
protected:
    social_number_generator(int const min, int const max)
    {
        ud = std::uniform_int_distribution<>(min, max);
        std::random_device rd;
        auto seed_data = std::array<int, std::mt19937::state_size>{};
        std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
        std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
        eng.seed(seq);
    }
    virtual int sex_digit(sex_type const sex) = 0;
    virtual int next_random(unsigned int year, unsigned int month, unsigned int day) = 0;
    virtual int modulu_value() = 0;

public:
    std::string generate(sex_type sex, unsigned int const year, unsigned int const month, unsigned int day)
    {
        std::stringstream ss;
        ss << sex_digit(sex);
        ss << year << month << day;
        ss << next_random(year, month, day);
        auto number = ss.str();
        auto index = number.length();
        auto sum = std::accumulate(std::begin(number), std::end(number), 0, [&index](int const s, char const c) {
            return s + index-- * (c - '0'); // converts numbers stored as char in string to int mutiplies with index
        });
        auto rest = sum % modulu_value();
        ss << modulu_value() - rest;
        return ss.str();
    }
    virtual ~social_number_generator()
    {
    }

protected:
    std::map<unsigned, int> cache;
    std::mt19937 eng;
    std::uniform_int_distribution<> ud;
};

class southeria_social_number_generator : public social_number_generator
{
private:
    /* data */
public:
    southeria_social_number_generator() : social_number_generator(1000, 9999)
    {
    }
    virtual ~southeria_social_number_generator()
    {
    }

protected:
    virtual int sex_digit(sex_type const sex) override
    {
        if (sex == sex_type::female)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    virtual int next_random(unsigned int year, unsigned int month, unsigned int day) override
    {
        auto key = 10000 * year + 100 * month + day;
        while (true) // we are going to have a cache inorder to avoid euqal social numbers
        {
            auto number = ud(eng);
            auto pos = cache.find(number);
            if (pos == std::end(cache))
            {
                cache[key] = number;
                return number;
            }
        }
    }
    virtual int modulu_value() override
    {
        return 11;
    }
};

class northeria_social_number_generator : public social_number_generator
{
private:
    /* data */
public:
    northeria_social_number_generator() : social_number_generator(10000, 99999)
    {
    }
    virtual ~northeria_social_number_generator()
    {
    }

protected:
    virtual int sex_digit(sex_type const sex) override
    {
        if (sex == sex_type::female)
        {
            return 9;
        }
        else
        {
            return 7;
        }
    }
    virtual int next_random(unsigned int year, unsigned int month, unsigned int day) override
    {
        auto key = 10000 * year + 100 * month + day;
        while (true)
        {
            auto number = ud(eng);
            auto pos = cache.find(number);
            if (pos == std::end(cache))
            {
                cache[key] = number;
                return number;
            }
        }
    }
    virtual int modulu_value() override
    {
        return 11;
    }
};


class social_number_generator_factory
{
private:
    std::map<std::string, std::unique_ptr<social_number_generator>> inner;

public:
    social_number_generator_factory()
    {
        inner["northeria"] = std::make_unique<northeria_social_number_generator>();
        inner["southeria"] = std::make_unique<southeria_social_number_generator>();
    }
    virtual ~social_number_generator_factory()
    {
    }
    std::unique_ptr<social_number_generator>& get_generator(
        std::string_view country) // I had written this line as std::unique_ptr<social ...>
                                  // and returned with std::move(), it did not give any output! I do not know why
    {
        auto it = inner.find(country.data());
        if (!(it == std::end(inner)))
        {
            return it->second;
        }
        throw std::runtime_error("Invalid Country");
    }
};

int main()
{
    social_number_generator_factory factory;
    std::vector<std::string> vec;
    vec.emplace_back(factory.get_generator("northeria")->generate(sex_type::female, 2017, 12, 25));
    vec.emplace_back(factory.get_generator("northeria")->generate(sex_type::female, 2017, 12, 25));
    vec.emplace_back(factory.get_generator("northeria")->generate(sex_type::male, 2017, 12, 25));

    vec.emplace_back(factory.get_generator("southeria")->generate(sex_type::female, 2017, 12, 25));
    vec.emplace_back(factory.get_generator("southeria")->generate(sex_type::female, 2017, 12, 25));
    vec.emplace_back(factory.get_generator("southeria")->generate(sex_type::male, 2017, 12, 25));
    std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<std::string>{std::cout, ", "});
    return 0;
}

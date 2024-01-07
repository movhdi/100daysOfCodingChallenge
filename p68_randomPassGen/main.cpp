#include <string>
#include <memory>
#include <exception>
#include <vector>
#include <random>
#include <array>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iostream>


class password_generator
{
private:
    /* data */
public:
    virtual std::string generate() = 0;
    virtual std::string allowed_chars() const = 0;
    virtual size_t length() const = 0;
    virtual void add(std::unique_ptr<password_generator> gen) = 0;
    virtual ~password_generator() {}
};

class basic_password_generator : public password_generator
{
private:
    size_t len;
public:
    basic_password_generator(const size_t a) : len(a) {}
    virtual size_t length() const override final
    {
        return len;
    }
    virtual std::string generate() override
    {
        throw std::runtime_error("Not implemented!");
    }
    virtual void add(std::unique_ptr<password_generator> gen) override
    {
        throw std::runtime_error("Not implemented!");
    }
};

class digit_generator : public basic_password_generator
{
private:
public:
    digit_generator(const size_t len) : basic_password_generator(len) {}
    virtual std::string allowed_chars() const override
    {
        return "0123456789";
    }
};

class symbol_generator : public basic_password_generator
{
private:
public:
    symbol_generator(size_t const len) : basic_password_generator(len) {}
    virtual std::string allowed_chars() const override
    {
        return "!@#$%^&*(){}[]?<>";
    }
};

class upper_letter_generator : public basic_password_generator
{
private:
public:
    upper_letter_generator(const size_t len) : basic_password_generator(len) {}
    virtual std::string allowed_chars() const override
    {
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
};

class lower_letter_generator : public basic_password_generator
{
private:
public:
    lower_letter_generator(const size_t len) : basic_password_generator(len) {}
    virtual std::string allowed_chars() const override
    {
        return "abcdefghijklmnopqrstuvwxyz";
    }
};

class composite_password_generator : public password_generator
{
    virtual std::string allowed_chars() const override
    {
        throw std::runtime_error("not implemented");
    }
    virtual size_t length() const override
    {
        throw std::runtime_error("not implemented");
    }
private:
    std::vector<std::unique_ptr<password_generator>> generators;
    std::random_device rd;
    std::mt19937 eng;
public:
    composite_password_generator()
    {
        std::array<int, std::mt19937::state_size> seed_set;
        std::generate(std::begin(seed_set), std::end(seed_set), std::ref(rd)); // we should use std::ref() because
                                                                               // random_device is not copyable
        std::seed_seq seq(seed_set.begin(), seed_set.end());
        eng.seed(seq);
    }
    // objective is to
    virtual std::string generate() override
    {
        std::string password;
        for (auto &generator : generators)
        {
            std::string chars = generator->allowed_chars();
            std::uniform_int_distribution ud(0,static_cast<int> (chars.length()-1));
            for (size_t i = 0; i < generator->length(); i++)
            {
                password += chars[ud(eng)];
            }
        }
        std::shuffle(std::begin(password),std::end(password), eng);
        return password;
    }
    virtual void add(std::unique_ptr<password_generator> gen) override
    {
        generators.push_back(std::move(gen));
    }
};

int main()
{
    composite_password_generator generator;
    generator.add(std::make_unique<symbol_generator>(2));
    generator.add(std::make_unique<digit_generator>(3));
    generator.add(std::make_unique<upper_letter_generator>(4));
    generator.add(std::make_unique<lower_letter_generator>(6));
    std::cout << generator.generate() << std::endl;

    return 0;
}

#include <assert.h>
#include <cassert>
#include <cctype>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>

class password_validator // this is the component interface
{
private:
    /* data */
public:
    password_validator(/* args */)
    {
    }
    ~password_validator()
    {
    }
    virtual bool validate(std::string_view a) = 0;
};


class length_validator : public password_validator // this is concrete component
{
private:
    unsigned int length;

public:
    length_validator(unsigned int a) : length(a)
    {
    }
    ~length_validator()
    {
    }
    virtual bool validate(std::string_view a) override
    {
        return a.length() >= length;
    }
};


class password_validator_decorator : public password_validator // this is decorator
{
private:
    std::unique_ptr<password_validator> inner;

public:
    password_validator_decorator(std::unique_ptr<password_validator> pv) : inner(std::move(pv))
    {
    }
    ~password_validator_decorator()
    {
    }
    virtual bool validate(std::string_view a) override
    {
        return inner->validate(a);
    }
};

class digit_validator_decorator : public password_validator_decorator // this is concrete decorator
{
private:
    /* data */
public:
    digit_validator_decorator(std::unique_ptr<password_validator> pv) : password_validator_decorator(std::move(pv))
    {
    }
    ~digit_validator_decorator()
    {
    }
    virtual bool validate(std::string_view password) override
    {
        if (!password_validator_decorator::validate(password))
        {
            return false;
        }
        return !(password.find_first_of("0123456789") == std::string::npos);
    }
};

class symbol_validator_decorator : public password_validator_decorator // this is concrete decorator
{
private:
    /* data */
public:
    symbol_validator_decorator(std::unique_ptr<password_validator> pv) : password_validator_decorator(std::move(pv))
    {
    }
    ~symbol_validator_decorator()
    {
    }
    virtual bool validate(std::string_view password) override
    {
        if (!password_validator_decorator::validate(password))
        {
            return false;
        }
        return !(password.find_first_of("!@#$%^&*(){}[]?<>") == std::string::npos);
    }
};

// aim of this class is to validate a password has both lower case and upper case
class case_validator_decorator : public password_validator_decorator // this is concrete decorator
{
private:
public:
    case_validator_decorator(std::unique_ptr<password_validator> pv) : password_validator_decorator(std::move(pv))
    {
    }
    ~case_validator_decorator()
    {
    }
    virtual bool validate(std::string_view password) override
    {
        bool has_lower{false};
        bool has_upper{false};
        for (size_t i{}; i < password.length() && !(has_lower && has_upper); i++)
        {
            if (!password_validator_decorator::validate(password)) // I can not get what is going on here
            {
                return false;
            }

            if (std::isupper(static_cast<unsigned char>(password[i])))
            {
                has_upper = true;
            }
            else if (std::islower(static_cast<unsigned char>(password[i])))
            {
                has_lower = true;
            }
        }
        return has_lower && has_upper;
    }
};

int main()
{
    std::string password{"KjhLnv#nDf@!s"};
    std::unique_ptr<length_validator> lv =
        std::make_unique<length_validator>(8); // we first make the concrete component,
                                               //just like we first make icecream then we add choclate etc.
    std::cout << std::boolalpha << lv->validate((password).c_str()) << std::endl;
    auto lv2 = std::make_unique<digit_validator_decorator>(std::make_unique<length_validator>(8));
    std::cout << std::boolalpha << lv2->validate((password + "1321").c_str())
              << std::endl; // const char* implicitly is converted to std::string_view
                            // c_str() returns const char*
    assert(lv->validate((password).c_str()));
    assert(!lv2->validate((password).c_str()));
    auto lv3 = std::make_unique<symbol_validator_decorator>(std::make_unique<case_validator_decorator>(
        std::make_unique<digit_validator_decorator>(std::make_unique<length_validator>(7))));
    assert(lv3->validate("qwqwsE@1"));
    return 0;
}

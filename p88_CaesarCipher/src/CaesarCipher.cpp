#include <CaesarCipher.hpp>
#include <iostream>


namespace cryptography {

std::string CaesarCipher::encrypt(std::string str)
{
    std::string result;
    for (const auto &ch : str)
    {
        if ('A' <= ch &&  ch <= 'Z')
        {
            result += (ch - 64 + 3) > 26 ? static_cast<char>(((ch - 64 + 3) % 26) + 64) : static_cast<char>(ch + 3);
        }
        else
        {
            result += ch;
        }
    }
    return result;
}

std::string CaesarCipher::decrypt(std::string str)
{
    std::string result;
    for (const auto &ch : str)
    {
        if ('A' <= ch && ch <= 'Z')
        {
            result += (ch - 64 - 3) < 0 ? ((ch - 64 - 3) % 26) + 64 : ch - 3;
        }
        else
        {
            result += ch;
        }
    }
    return result;
}

} // cryptography

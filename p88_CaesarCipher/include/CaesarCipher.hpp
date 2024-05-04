#ifndef CAESARCIPHER_HPP
#define CAESARCIPHER_HPP

#include <string>

namespace cryptography {

class CaesarCipher
{
private:
    /* data */
public:
    CaesarCipher(/* args */){}
    CaesarCipher(CaesarCipher& copyItem) = delete;
    std::string encrypt(std::string str);
    std::string decrypt(std::string);
    ~CaesarCipher(){}
};

} // encryption


#endif
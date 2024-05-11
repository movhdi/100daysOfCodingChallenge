#ifndef CAESARCIPHER_HPP
#define CAESARCIPHER_HPP

#include <string>
#include <CipherBase.hpp>
#include <iostream>
#include <cstring>

namespace cryptography {

class CaesarCipher : public CipherBase
{
private:
    void set_cipher_config(const cipherConfig& cipher_config) override;

public:
    explicit CaesarCipher(const cipherConfig& cipher_config);
    friend class VigenerCipher;
    
    virtual std::string encrypt(std::string str) override;
    virtual std::string decrypt(std::string str) override;

    cipherConfig get_cipher_config() override;
    virtual ~CaesarCipher(){
        debug("Caesar DTOR called")
        // debug("Caesar destructor called!")
        }
};

} // cryptography


#endif

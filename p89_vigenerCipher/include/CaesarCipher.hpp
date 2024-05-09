#ifndef CAESARCIPHER_HPP
#define CAESARCIPHER_HPP

#include <string>
#include <CipherBase.hpp>
#include <iostream>
#include <cstring>

#ifdef DEBUG
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define debug(x) std::cout <<"["<< __FILENAME__ <<"] " << "=> " <<"["<<__func__<<"] "<<(x) << std::endl;
#else
#define __FILENAME__
#define debug(x) 
#endif

namespace cryptography {

class CaesarCipher : public CipherBase
{
private:
    void set_cipher_config(const cipherConfig& cipher_config) override;

public:
    explicit CaesarCipher(const cipherConfig& cipher_config);
    
    virtual std::string encrypt(std::string str) override;
    virtual std::string decrypt(std::string str) override;

    cipherConfig get_cipher_config() override;
    ~CaesarCipher(){
        // debug("Caesar destructor called!")
        }
};

} // cryptography


#endif

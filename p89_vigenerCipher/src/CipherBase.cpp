#include <CipherBase.hpp>
#include <exception>
#include <string>
#include <cstring>
#include <iostream>


namespace cryptography {

CipherBase::CipherBase() {
    // debug("CipherBase CTOR called")
    try
    {
        /* code */
        // this->set_cipher_config_base(cipher_config);
    }
    catch(const std::exception& e)
    {
        std::cerr <<"From cipherbase ctor: "<< e.what() << '\n';
    }
    set_cipher_config_base(cipher_config);
}

CipherBase::CipherBase(const cipherConfig& cipher_config) {
    this->cipher_config = cipher_config;
}

void CipherBase::set_cipher_config_base(const cipherConfig& cipher_config)
{
    try
    {
        /* code */
        this->cipher_config = cipher_config;
        debug(cipher_config.shiftCount)
    }
    catch(const std::exception& e)
    {
        std::cerr <<"From set cipher config base: "<< e.what() << '\n';
    }
}

cipherConfig CipherBase::get_cipher_config_base() {
    return this->cipher_config;
}

CipherBase::~CipherBase() {
    // debug("CipherBase DTOR called")
}

} // cryptography
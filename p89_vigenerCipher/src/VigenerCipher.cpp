#include <VigenerCipher.hpp>
#include <iostream>
#include <CaesarCipher.hpp>
#include <memory>

namespace cryptography {

VigenerCipher::VigenerCipher(const cipherConfig& cipher_config) : CipherBase()
{
    debug(cipher_config.shiftCount)
    set_cipher_config(cipher_config);
    caesarEngine = std::make_unique<CaesarCipher>(cipher_config);
}

void VigenerCipher::set_cipher_config(const cipherConfig& cipher_config) {
    set_cipher_config_base(cipher_config);
}

std::string VigenerCipher::encrypt(std::string str) {
    std::string result;
    for (size_t i{}; i < str.size(); ++i) {
        this->cipher_config.shiftCount =
            this->cipher_config.vigener_key[i % this->cipher_config.vigener_key.size()] - 'A';
        this->caesarEngine->set_cipher_config(this->cipher_config);
        std::cout << "shift     \n";
        debug(this->cipher_config.shiftCount) 
        debug(caesarEngine->get_cipher_config().shiftCount)
        std::cout << "size      \n";
        debug(this->cipher_config.vigener_key.size())  
        debug(caesarEngine->get_cipher_config().shiftCount)
        result += caesarEngine->encrypt(std::string(1,str[i]));
        std::cout << result << std::endl;
    }
    return result;
}

cipherConfig VigenerCipher::get_cipher_config() {
  return get_cipher_config_base();
}

std::string VigenerCipher::decrypt(std::string str)
{   
    std::string result;
    for (size_t i{}; i < str.size(); ++i) {
        this->cipher_config.shiftCount =
            this->cipher_config.vigener_key[i % cipher_config.vigener_key.size()] - 'A';
        this->caesarEngine->set_cipher_config(cipher_config);
        debug(this->cipher_config.shiftCount)
        debug(this->cipher_config.vigener_key.size())
        result += caesarEngine->decrypt(std::string(1,str[i]));
    }
    return result;
}


} // cryptography

#include <VigenerCipher.hpp>
#include <iostream>
#include <CaesarCipher.hpp>
#include <memory>

namespace cryptography {

VigenerCipher::VigenerCipher(const cipherConfig& cipher_config) : CipherBase(cipher_config)
{
    debug(this->cipher_config.shiftCount)
    this->set_cipher_config(cipher_config);
    this->caesarEngine = std::make_unique<CaesarCipher>(cipher_config);
}

void VigenerCipher::set_cipher_config(const cipherConfig& cipehr_config) {
    set_cipher_config_base(cipher_config);
}

std::string VigenerCipher::encrypt(std::string str) {
    std::string result;
    for (size_t i{}; i < str.size(); ++i) {
        this->cipher_config.shiftCount =
            this->cipher_config.vigener_key[i % this->cipher_config.vigener_key.size()] -
            'A';
        debug(this->cipher_config.shiftCount)
        debug(this->cipher_config.vigener_key.size())
        result += caesarEngine->encrypt(std::to_string(str[i]));
    }
    return result;
}

cipherConfig VigenerCipher::get_cipher_config() {
  return get_cipher_config_base();
}

std::string VigenerCipher::decrypt(std::string str)
{   
    const auto vigenereTable = this->VigenerTableBuilder();
    std::string result;
        for (size_t i{}; i < str.size(); ++i) {
        this->cipher_config.shiftCount =
            this->cipher_config.vigener_key[i % this->cipher_config.vigener_key.size()] - 'A';
        debug(this->cipher_config.shiftCount)
        debug(this->cipher_config.vigener_key.size())
        result += caesarEngine->decrypt(std::to_string(str[i]));
    }
    return result;
}

std::string VigenerCipher::VigenerTableBuilder()
{
    std::string result;
    result.reserve(26*26);
    // CaesarCipher caesarEng(cipherTemporary);
    for (size_t i = 0; i < 26; i++)
    {
        this->cipher_config.shiftCount = i;
        result+=caesarEngine->encrypt("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    }
    return result;
}

} // cryptography

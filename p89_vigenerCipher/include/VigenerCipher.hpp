#ifndef VIGENERCIPHER_HPP
#define VIGENERCIPHER_HPP

#include <string>
#include <CipherBase.hpp>
#include <CaesarCipher.hpp>
#include <memory>


namespace cryptography
{

class VigenerCipher : public CipherBase
{
protected:
    std::unique_ptr<CaesarCipher> caesarEngine;
    void set_cipher_config(const cipherConfig& cipehr_config) override;
public:
    VigenerCipher(const cipherConfig& cipher_config);
    
    std::string encrypt(std::string strv) override;
    std::string decrypt(std::string str) override;

    cipherConfig get_cipher_config() override;

    std::string VigenerTableBuilder();
    ~VigenerCipher(){
        // debug("vigener DTOR called")
    }
};

} // cryptography

#endif

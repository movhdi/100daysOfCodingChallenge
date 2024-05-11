#ifndef CIPHERBASE_HPP
#define CIPHERBASE_HPP

#include <string>
#include <iomanip>
#include <optional>

#ifdef DEBUG
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define debug(x) std::cout <<"["<< __FILENAME__ <<"] " << "=> " <<"["<<__func__<<"] "<<(x) << std::endl;
#else
#define __FILENAME__
#define debug(x) 
#endif

namespace cryptography { 

struct cipherConfig
{
    size_t shiftCount;
    std::string vigener_key;
};

class CipherBase
{
protected:
    cipherConfig cipher_config; // FIXME: should be shared_ptr
public:
    explicit CipherBase();
    // explicit CipherBase(const cipherConfig& cipher_config);
    
    virtual cipherConfig get_cipher_config() = 0;
    virtual std::string encrypt(std::string str) = 0;
    virtual std::string decrypt(std::string str) = 0;

    virtual void set_cipher_config(const cipherConfig& cipher_config) = 0;
    void set_cipher_config_base(const cipherConfig& cipher_config);
    
    cipherConfig get_cipher_config_base();

    virtual ~CipherBase();
};

} // cryptography
#endif
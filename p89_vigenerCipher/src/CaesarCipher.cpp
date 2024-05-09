#include <CaesarCipher.hpp>
#include <iostream>
#include <utility>


namespace cryptography {

CaesarCipher::CaesarCipher(const cipherConfig &cipher_config) : CipherBase(cipher_config) {
    debug("CaesarCipher CTOR called");
    debug(cipher_config.shiftCount);
    try
    {
      /* code */
    }
    catch(const std::exception& e)
    {
      std::cerr << "From caesarcipher ctor: " << e.what() << '\n';
    }
      this->set_cipher_config(std::forward<const cipherConfig&>(cipher_config));
}

void CaesarCipher::set_cipher_config(const cipherConfig &cipehr_config) {
    debug(cipher_config.shiftCount)
  set_cipher_config_base(std::move(cipher_config));
}

cipherConfig CaesarCipher::get_cipher_config() {
  return get_cipher_config_base();
}

std::string CaesarCipher::encrypt(std::string str) {
  std::string result;
  for (const auto &ch : str) {
    if ('A' <= ch && ch <= 'Z') {
      result +=
          (ch - 64 + cipher_config.shiftCount) > 26
              ? static_cast<char>(
                    ((ch - 64 + cipher_config.shiftCount) % 26) + 64)
              : static_cast<char>(ch + cipher_config.shiftCount);
    } else {
      result += ch;
    }
  }
  return result;
}

std::string CaesarCipher::decrypt(std::string str) {
  std::string result;
  for (const auto &ch : str) {
    if ('A' <= ch && ch <= 'Z') {
      result += (ch - 64 - cipher_config.shiftCount) < 0
                    ? ((ch - 64 - cipher_config.shiftCount) % 26) + 64
                    : ch - cipher_config.shiftCount;
    } else {
      result += ch;
    }
  }
  return result;
}

} // cryptography

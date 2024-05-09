#include <cstring>
#include <VigenerCipher.hpp>
#include <CaesarCipher.hpp>
#include <assert.h>
#include <cassert>
#include <iostream>
#include <optional>
#include <memory>


#ifdef DEBUG
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define debug(x) std::cout <<"["<< __FILENAME__ <<"] " << "=> " <<"["<<__func__<<"] "<<(x) << std::endl;
#else
#define __FILENAME__
#define debug(x) 
#endif

int main() {
  // caesar cipher exercise
    cryptography::cipherConfig caesar_cipher_config{3, "ABC"};
    // debug <<"config generated successfully" << std::endl;
    debug("config generated successfully")
    std::unique_ptr<cryptography::CaesarCipher> caesarEngine = std::make_unique<cryptography::CaesarCipher>(caesar_cipher_config);
    cryptography::CaesarCipher caEng2(caesar_cipher_config);
    // debug << "caesar cipher engine generated successfully" << std::endl;
    

    auto config = caesarEngine->get_cipher_config();
    debug(config.shiftCount);

    std::cout << caesarEngine->encrypt("MAHDI iS A GOODMAN!") << std::endl;
    assert("MAHDI iS A GOODMAN!" ==
         caesarEngine->decrypt(caesarEngine->encrypt("MAHDI iS A GOODMAN!")));

  // vigenere cipher exercise
    cryptography::cipherConfig vigenre_cipher_config{.shiftCount = 1,
      .vigener_key = "SAMPLE"};

    std::string vigenerePlainText = "THECPPCHALLENGER";

    cryptography::VigenerCipher vignerEngine(vigenre_cipher_config);
    std::cout << vignerEngine.encrypt(vigenerePlainText) << std::endl;
  return 0;
}
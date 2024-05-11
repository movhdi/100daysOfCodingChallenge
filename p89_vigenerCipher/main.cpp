#include <cstring>
#include <CaesarCipher.hpp>
#include <VigenerCipher.hpp>
#include <assert.h>
#include <cassert>
#include <iostream>
#include <optional>
#include <memory>

int main() {
  // caesar cipher exercise
    {
      cryptography::cipherConfig caesar_cipher_config{3, "ABC"};
      std::unique_ptr<cryptography::CipherBase> caesarEngine = std::make_unique<cryptography::CaesarCipher>(caesar_cipher_config);      
      auto config = caesarEngine->get_cipher_config();
      debug(config.shiftCount);
      std::cout << caesarEngine->encrypt("MAHDI iS A GOODMAN") << std::endl;
      std::cout << caesarEngine->decrypt("PDKGL iV D JRRGPDQ!") << std::endl;
      assert("MAHDI iS A GOODMAN!" ==
          caesarEngine->decrypt(caesarEngine->encrypt("MAHDI iS A GOODMAN!")));
    }

    std::cout << "\n\n\n\n";
  // vigenere cipher exercise
    cryptography::cipherConfig vigenre_cipher_config{.shiftCount = 10,
      .vigener_key = "SAMPLE"};
                                   //SAMPLESAMPLESAMP
    std::string vigenerePlainText = "THECPPCHALLENGEr";

    std::unique_ptr<cryptography::CipherBase> vignerEngine = std::make_unique<cryptography::VigenerCipher>(vigenre_cipher_config);
    std::cout << vignerEngine->encrypt(vigenerePlainText) << std::endl;
                                      //SAMPLESAMPLESAMP
    std::cout << vignerEngine->decrypt("LHQRATUHMAWIFGQr") << std::endl;
        
  return 0;
}
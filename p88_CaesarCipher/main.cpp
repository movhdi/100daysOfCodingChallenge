#include <iostream>
#include <CaesarCipher.hpp>
#include <assert.h>
#include <cassert>


int main()
{
    cryptography::CaesarCipher caesarEngine;
    assert("MAHDI iS A GOODMAN!" == caesarEngine.decrypt(caesarEngine.encrypt("MAHDI iS A GOODMAN!")));
    return 0;
}
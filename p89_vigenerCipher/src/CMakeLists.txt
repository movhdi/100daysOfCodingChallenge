
set(CMAKE_CXX_STANDARD 17)

add_library(cryptoLib)

target_sources(cryptoLib PRIVATE CipherBase.cpp VigenerCipher.cpp CaesarCipher.cpp)

target_include_directories(cryptoLib PUBLIC ${CMAKE_SOURCE_DIR}/include)
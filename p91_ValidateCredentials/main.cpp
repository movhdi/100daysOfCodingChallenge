#include <iostream>
#include <vector>
#include <mutex>
#include <chrono>
#include <cryptlib.h>
#include <sha.h>
#include <hex.h>
#include <files.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <termios.h>
#include <unistd.h>


struct user
{
    int id;
    std::string username;
    std::string password;
    std::string firstname;
    std::string lastname;
};


int main()
{
    std::vector<user> users = 
    {
        {1, "johnsmith", "bcab83bab4669183e86f2546653232dc8e8730be063db892152167dbdb786041", "John", "Smith"}, // password: Meco@123
        {2, "jackbrown", "737a3443c81dc31195e1acb8d1b7a4b46e66b92ddf1dd86b2b69029feeb8c459", "Jack", "Brown"} // password: Mapna@123
    };
    std::ostringstream oss;
    CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(oss));

    std::cout << "Username: ";
    std::string username;
    std::cin >> username; 
    std::cout << "Password: ";
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~ECHO;
    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
    std::string password;
    std::cin >> password;
    std::cout << std::endl;
    std::string digest;
    CryptoPP::SHA256 hash;


    hash.Update((const byte*)password.data(), password.size());
    digest.resize(hash.DigestSize());
    hash.Final((byte *)&digest[0]);
    std::cout << "Digest: ";
    CryptoPP::StringSource(digest, true, new CryptoPP::Redirector(encoder));

    digest = oss.str();
    std::transform(digest.begin(), digest.end(), digest.begin(), [](unsigned char ch){return std::tolower(ch);});
    
    if (std::find_if(users.begin(), users.end(), [&username, &digest](user &u){
        return u.username == username && u.password == digest;
    }) != users.end())
    {
        std::cout << "login was successful!" << std::endl;
    }
    else
    {
        std::cout << "login unsuccessful!" << std::endl;
    }
    
    std::cout << std::endl;
    return 0;
}
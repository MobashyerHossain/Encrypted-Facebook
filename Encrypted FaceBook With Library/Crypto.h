#ifndef CRYPTO_H
#define CRYPTO_H
#include <iostream>
using namespace std;

class Crypto
{
    public:
        Crypto();
        virtual ~Crypto();

        //For Encrypting a given Text
        string Encrypted(string e);

        //For Decrypting a given Text
        string Decrypted(string d);

        //For Encrypting a File Name
        string FileNameEncrypt(string f);
    protected:
    private:
};

#endif // CRYPTO_H

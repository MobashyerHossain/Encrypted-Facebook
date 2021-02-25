#include "Crypto.h"
#include <stdlib.h>
#include <sstream>
#include <iostream>
using namespace std;

Crypto::Crypto()
{
    //ctor
}

Crypto::~Crypto()
{
    //dtor
}

string Crypto::Encrypted(string e)
{
    string text = "dhfhbfi" + e + "lkjifuhf";
    string rev(text.rbegin(), text.rend());
    string encrypt;
    for(int i=0 ; i<rev.length() ; i++)
    {
        int key;
        if(i%2 == 0){
            key = (int) rev.at(i);
            key = key + 9;
        }
        else{
            key = (int) rev.at(i);
            key = key - 9;
        }
        encrypt += (char)key;
    }
    return encrypt;
}

string Crypto::Decrypted(string d)
{
    string decrypt;
    for(int i=0 ; i<d.length() ; i++)
    {
        int key;
        if(i%2 == 0){
            key = (int) d.at(i);
            key = key - 9;
        }
        else{
            key = (int) d.at(i);
            key = key + 9;
        }
        decrypt += (char)key;
    }
    string rev(decrypt.rbegin(), decrypt.rend());
    decrypt = rev.substr(7,d.length()-15);
    return decrypt;
}

string Crypto::FileNameEncrypt(string f)
{
    string filename;
    ostringstream name;
    int x = f.length()/2;
    for(int i=x ; i>=0 ; i--)
    {
        int key = (int)f.at(i);
        name << (key * (i+5));
    }

    for(int i=f.length()-1 ; i>x ; i--)
    {
        int key = (int)f.at(i);
        name << (key * (i+3));
    }

    filename = name.str();
    if(filename.length() > 150){
        filename = filename.substr(0,150);
    }

    return name.str();
}

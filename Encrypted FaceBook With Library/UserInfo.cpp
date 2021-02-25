#include "UserInfo.h"
#include "Crypto.h"
#include <iostream>
using namespace std;

UserInfo::UserInfo()
{

}

UserInfo::UserInfo(string n, string e, string p, string g, string d, string pn)
{
    name = n;
    email = e;
    password = p;
    gender = g;
    dob = d;
    phoneNo = pn;
}

UserInfo::~UserInfo()
{

}


void UserInfo::setName(string n)
{
    name = n;
}

string UserInfo::getName()
{
    return name;
}

void UserInfo::setPassword(string p)
{
    password = p;
}

string UserInfo::getPassword()
{
    return password;
}

void UserInfo::setEmail(string e)
{
    email = e;
}

string UserInfo::getEmail()
{
    return email;
}

void UserInfo::setGender(string g)
{
    gender = g;
}

string UserInfo::getGender()
{
    return gender;
}

void UserInfo::setDateOfBirth(string d)
{
    dob = d;
}

string UserInfo::getDateOfBirth()
{
    return dob;
}

void UserInfo::setPhoneNumber(string pn)
{
    phoneNo = pn;
}

string UserInfo::getPhoneNumber()
{
    return phoneNo;
}


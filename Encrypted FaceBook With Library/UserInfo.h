#ifndef USERINFO_H
#define USERINFO_H
#include <iostream>
using namespace std;

class UserInfo
{
    public:
        UserInfo();
        UserInfo(string n, string e, string p, string g, string d, string pn);
        virtual ~UserInfo();

        //For Setting and Getting User's Name
        void setName(string n);
        string getName();

        //For Setting and Getting User's Email
        void setEmail(string e);
        string getEmail();

        //For Setting and Getting User's Password
        void setPassword(string p);
        string getPassword();

        //For Setting and Getting User's Gender
        void setGender(string g);
        string getGender();

        //For Setting and Getting User's Date of Birth
        void setDateOfBirth(string d);
        string getDateOfBirth();

        //For Setting and Getting User's Phone Number
        void setPhoneNumber(string pn);
        string getPhoneNumber();

    protected:
    private:
        string name;
        string email;
        string password;
        string gender;
        string dob;
        string phoneNo;
};

#endif // USERINFO_H

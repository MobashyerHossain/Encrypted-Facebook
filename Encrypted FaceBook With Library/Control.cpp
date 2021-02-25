#include "Control.h"
#include "UserInfo.h"
#include "Crypto.h"
#include "Storage.h"
#include "Options.h"
#include "Library.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

// Global variable declaration
Storage S;

// Applies Title in every window before Sign In
void Title();

// Sign In window
void SignIn(bool x);

// Sign Up window
void SignUp();

// Sign Up Welcome banner
void Welcome(string x);

Control::Control()
{
    //Welcome("");
    SignIn(false);
}

Control::~Control()
{
    //dtor
}

// This function loads the title for all new windows
void Title()
{
    for(int i=0 ; i<50 ; i++){
        cout << "\n\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\tLoading";
        for(int j=0 ; j<i ; j++){
            cout << "." ;
        }
        system("CLS");
    }

    cout << "\t\t\t\t\t\t" << ">>>>>>> " << "KMHJ SOCIAL" << " <<<<<<<" << endl;
    cout << "\t\t\t\t\t\t\t" << "***********" << endl;
}

// This function buffers the following message for 5 seconds
//                WELCOME To KMHJ SOCIAL
//                **********************
//                 Mr. / Ms.  User Name
// User name varies from user to user
// as well as Mr. and Ms. based on gender
void Welcome(string x)
{
    string w = "WELCOME To KMHJ SOCIAL", q, r, l;
    int a;

    if(x.length() > w.length()){
        a = w.length();
        string m;
        for(int i=a ; i<x.length() ; i++){
            if(i%2 == 0){
                m += " ";
            }
            else{
                w += " ";
            }
        }
        w = m+w;
    }
    else{
        a = x.length();
        string m;
        for(int i=a ; i<w.length() ; i++){
            if(i%2 == 0){
                m += " ";
            }
            else{
                x += " ";
            }
        }
        x = m+x;
    }

    for(int i=0 ; i<x.length() ; i++){
        q += w[i];
        r += "*";
        l += x[i];
        for(int j=0 ; j<20 ; j++){
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\t\t\t" << q << endl;
            cout << "\t\t\t\t\t\t" << r << endl;
            cout << "\t\t\t\t\t\t" << l << endl;
            system("CLS");
        }
        system("CLS");
    }

    for(int j=0 ; j<100 ; j++){
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\t\t\t" << q << endl;
        cout << "\t\t\t\t\t\t" << r << endl;
        cout << "\t\t\t\t\t\t" << l << endl;
        system("CLS");
    }
}

// This Function Creates a New Window called Sign In
// Here Users email and password is taken to be compared
// with existing user's information so that they can log
// in to their Account
void SignIn(bool x)
{
    Title();
    cout << "\t\t\t\t\t\t\t" << "| Sign In |" << endl << endl;
    if(x){
        cout << "\n\n" << "\t\t\t\t\t" << "Either Email or Password is Invalid!!!" << "\n\n";
        cout << "\t\t\t\t\t" << "Enter \"Library\" to visit KMHJ LIBRARY" << endl;
        cout << "\t\t\t\t\t\t" << "Enter \"New\" to Sign Up" << "\n\n";
    }
    else{
        cout << "\n\n\n\n" << "\t\t\t\t\t" << "Enter \"Library\" to visit KMHJ LIBRARY" << endl;
        cout << "\t\t\t\t\t\t" << "Enter \"New\" to Sign Up" << "\n\n";
    }
    string e, p;

    cout << "\t\t\t\t\t" << "Email\t : ";
    cin >> e;
    if(strcmpi(e.c_str(),"new")== 0){
        SignUp();
        return;
    }
    else if(strcmpi(e.c_str(),"library")== 0){
        Library L;
        return;
    }

    cout << "\t\t\t\t\t" << "Password : ";
    cin >> p;
    if(strcmpi(p.c_str(),"new")== 0){
        SignUp();
        return;
    }
    else if(strcmpi(p.c_str(),"library")== 0){
        Library L;
        return;
    }

    if(S.verifyUserData(e,p)){
        Options O(S.retrieveUserData(e));
        return;
    }
    else{
        SignIn(true);
    }
}

// This Function Creates a New Window called Sign Up
// Here new User's can submit their information for
// which will be saved in an external file
void SignUp()
{
    Title();
    cout << "\t\t\t\t\t\t\t" << "| Sign Up |" << endl << endl;
    cout << "\n\n\n\n" << "\t\t\t\t\t\t" << "Enter \"Back\" to Sign In" << "\n\n";

    string name, email, pass1, pass2, gender, dob, phone;
    bool pCheck = false, eCheck = false;

    cout << "\t\t\t\t" << "Name\t\t : ";
    getline(cin,name);
    getline(cin,name);
    if(strcmpi(name.c_str(),"back")== 0){
        SignIn(false);
        return;
    }

    while(!eCheck){
        cout << "\t\t\t\t" << "Email\t\t : ";
        getline(cin,email);
        if(strcmpi(email.c_str(),"back")== 0){
            SignIn(false);
            return;
        }

        if(S.checkEmail(email)){
            cout << "\t\t\t\t\t\t" << "Email already in use!!!" << endl;
        }
        else{
            eCheck = true;
        }
    }

    while(!pCheck){
        cout << "\t\t\t\t" << "Password\t : ";
        getline(cin,pass1);
        if(strcmpi(pass1.c_str(),"back")== 0){
            SignIn(false);
            return;
        }

        cout << "\t\t\t\t" << "Confirm Password : ";
        getline(cin,pass2);
        if(strcmpi(pass2.c_str(),"back")== 0){
            SignIn(false);
            return;
        }

        if(pass1.compare(pass2) != 0){
            cout << "\t\t\t\t\t\t" << "Confirm your Password!!!" << endl;
        }

        else if(pass1.length() < 6 ){
            cout << "\t\t\t\t\t" << "Must be at least 6 Characters long!!!" << endl;
        }

        else{
            pCheck = true;
        }
    }

    cout << "\t\t\t\t" << "Gender\t\t : ";
    getline(cin,gender);
    if(strcmpi(gender.c_str(),"back")== 0){
        SignIn(false);
        return;
    }

    cout << "\t\t\t\t" << "Date of Birth\t : ";
    getline(cin,dob);
    if(strcmpi(dob.c_str(),"back")== 0){
        SignIn(false);
        return;
    }

    cout << "\t\t\t\t" << "Phone No.\t : ";
    getline(cin,phone);
    if(strcmpi(phone.c_str(),"back")== 0){
        SignIn(false);
        return;
    }

    gender[0] = toupper(gender[0]);
    UserInfo info(name, email, pass1, gender, dob, phone);
    S.storeUserData(info);
    S.addUserToList(info);
    if(gender.compare("male") == 0 || gender.compare("Male") == 0){
        name = "Mr. " + name;
    }
    else if(gender.compare("female") == 0 || gender.compare("Female") == 0){
        name = "Ms. " + name;
    }
    Welcome(name);
    SignIn(false);
}

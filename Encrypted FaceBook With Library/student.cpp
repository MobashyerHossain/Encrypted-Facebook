#include "student.h"
#include "book.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

student::student()
{
    //ctor
}

student::~student()
{
    //dtor
}

void student::create_student()
{
    system("CLS");
    cout<<"\nNEW STUDENT ENTRY...\n";
    cout<<"\nEnter The admission no. ";
    cin>>admno;
    cin.ignore();
    cout<<"\n\nEnter The Name of The Student ";
    gets(name);
    token=0;
    stbno[0]='/0';
    cout<<"\n\nStudent Record Created..";
}

void student::show_student()
{
    cout<<"\nAdmission no. : "<<admno;
    cout<<"\nStudent Name : ";
    puts(name);
    cout<<"\nNo of Book issued : "<<token;
    if(token==1)
    cout<<"\nBook No "<<stbno;
}

void student::modify_student()
{
    cout<<"\nAdmission no. : "<<admno;
    cout<<"\nModify Student Name : ";
    cin.ignore();
    gets(name);
}

char* student::retadmno()
{
    return admno;
}

char* student::retstbno()
{
    return stbno;
}

int student::rettoken()
{
    return token;
}

void student::addtoken()
{
    token=1;
}

void student::resettoken()
{
    token=0;
}

void student::getstbno(char t[])
{
    strcpy(stbno,t);
}

void student::report()
{
    cout<<admno<< "\t\t" <<name<< "\t\t" <<token<<endl;
}


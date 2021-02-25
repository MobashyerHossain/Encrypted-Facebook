#include "book.h"
#include "student.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

book::book()
{
    //ctor
}

book::~book()
{
    //dtor
}

void book::create_book()
{
    cout<<"\nNEW BOOK ENTRY...\n";
    cout<<"\nEnter The book no.";
    cin>>bno;
    cin.ignore();
    cout<<"\n\nEnter The Name of The Book ";
    gets(bname);
    cout<<"\n\nEnter The Author's Name ";
    gets(aname);
    cout<<"\n\n\nBook Created..";
}

void book::show_book()
{
    cout<<"\nBook no. : "<<bno;
    cout<<"\nBook Name : ";
    puts(bname);
    cout<<"Author Name : ";
    puts(aname);
}

void book::modify_book()
{
    cout<<"\nBook no. : "<<bno;
    cout<<"\nModify Book Name : ";
    cin.ignore();
    gets(bname);
    cout<<"\nModify Author's Name of Book : ";
    gets(aname);
}

char* book::retbno()
{
    return bno;
}

void book::report()
{
    cout<<bno<< "\t\t" <<bname<< "\t\t\t" <<aname<<endl;
}


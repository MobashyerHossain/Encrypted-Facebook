#include "Library.h"
#include "book.h"
#include "student.h"
#include "Control.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

string f1name = "Data\\Library\\Book.dat";
string f2name = "Data\\Library\\Student.dat";
string f3name = "Data\\Library\\Temp.dat";
fstream fp,fp1;
book bk;
student st;

void main_main();
void admin_menu();
void write_book();
void write_student();
void display_spb(char n[]);
void display_sps(char n[]);
void modify_book();
void modify_student();
void delete_book();
void delete_student();
void display_allb();
void display_alls();
void book_issue();
void book_deposit();

Library::Library()
{
    main_main();
}

Library::~Library()
{
    //dtor
}

void main_main()
{
    char ch;

	do
	{
	system("CLS");
        cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
        cout<<"\t\t\t\t\t\t\t************";
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. BOOK ISSUE";
		cout<<"\n\n\t02. BOOK DEPOSIT";
	  	cout<<"\n\n\t03. ADMINISTRATOR MENU";
	  	cout<<"\n\n\t04. KMHJ SOCIAL";
	  	cout<<"\n\n\tPlease Select Your Option (1-4) ";
	  	ch=getche();
	  	switch(ch)
	  	{
			case '1':
			    {
			        book_issue();
                    break;
			    }
		  	case '2':
		  	    {
		  	        book_deposit();
                    break;
		  	    }
		  	case '3':
		  	    {
		  	        admin_menu();
                    break;
		  	    }
		  	case '4':
		  	    {
		  	        Control C;
                    break;
		  	    }
		  	default :
		  	    {
		  	        Control C;
                    break;
		  	    }
		}
    }while(1);
}

void admin_menu()
{
    system("CLS");
	int ch2;
	cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
	cout<<"\n\n\n\tADMINISTRATOR MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
	cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.CREATE BOOK ";
	cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
	cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
	cout<<"\n\n\t9.MODIFY BOOK ";
	cout<<"\n\n\t10.DELETE BOOK ";
	cout<<"\n\n\t11.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-11) ";
	cin>>ch2;
	switch(ch2)
	{
    		case 1: //clrscr();
	    		write_student();break;
    		case 2: display_alls();break;
    		case 3:
	       		char num[6];
//	       		clrscr();
	       		cout<<"\n\n\tPlease Enter The Admission No. ";
	       		cin>>num;
	       		display_sps(num);
	       		break;
      		case 4: modify_student();break;
      		case 5: delete_student();break;
		case 6: //clrscr();
			write_book();break;
		case 7: display_allb();break;
		case 8: {
	       		char num[6];
	       		//clrscr();
	       		cout<<"\n\n\tPlease Enter The book No. ";
	       		cin>>num;
	       		display_spb(num);
	       		break;
			}
      		case 9: modify_book();break;
      		case 10: delete_book();break;
     		case 11: return;
      		default:cout<<"\a";
   	}
   	admin_menu();
}

void write_book()
{
    char ch;
	fp.open(f1name.c_str(),ios::out|ios::app);
	do
	{
		system("CLS");
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void write_student()
{
    char ch;
	fp.open(f2name.c_str(),ios::out|ios::app);
	do
	{
		st.create_student();
		fp.write((char*)&st,sizeof(student));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void display_spb(char n[])
{
    system("CLS");
    cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
    cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp.open(f1name.c_str(),ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
		 	flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nBook does not exist";
	getch();
}

void display_sps(char n[])
{
    system("CLS");
    cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
	fp.open(f2name.c_str(),ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if((strcmpi(st.retadmno(),n)==0))
		{
			st.show_student();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
    		cout<<"\n\nStudent does not exist";
 	getch();
}

void modify_book()
{
    char n[6];
	int found=0;
	system("CLS");
	cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
	cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
	cout<<"\n\n\tEnter The book no. of The book";
	cin>>n;
	fp.open(f1name.c_str(),ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
			cout<<"\nEnter The New Details of book"<<endl;
			bk.modify_book();
			int pos=-1*sizeof(bk);
		    	fp.seekp(pos,ios::cur);
		    	fp.write((char*)&bk,sizeof(book));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}

    	fp.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
}

void modify_student()
{
    char n[6];
	int found=0;
	system("CLS");
	cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
	cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The admission no. of The student";
	cin>>n;
	fp.open(f2name.c_str(),ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),n)==0)
		{
			st.show_student();
			cout<<"\nEnter The New Details of student"<<endl;
			st.modify_student();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}

void delete_book()
{
    char n[6];
	system("CLS");
	cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	fp.open(f1name.c_str(),ios::in|ios::out);
	fstream fp2;
	fp2.open(f3name.c_str(),ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)!=0)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
	}

	fp2.close();
    fp.close();
    remove(f1name.c_str());
    rename(f3name.c_str(),f1name.c_str());
    cout<<"\n\n\tRecord Deleted ..";
    getch();
}

void delete_student()
{
    char n[6];
	int flag=0;
	//clrscr();
	cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
    cout<<"\n\n\n\tDELETE STUDENT...";
    cout<<"\n\nEnter The admission no. of the Student You Want To Delete : ";
    cin>>n;
    fp.open(f2name.c_str(),ios::in|ios::out);
    fstream fp2;
    fp2.open(f3name.c_str(),ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.retadmno(),n)!=0)
	     		fp2.write((char*)&st,sizeof(student));
		else
	   		flag=1;
	}

	fp2.close();
    fp.close();
    remove(f2name.c_str());
    rename(f3name.c_str(),f2name.c_str());
    if(flag==1)
        cout<<"\n\n\tRecord Deleted ..";
    else
        cout<<"\n\nRecord not found";
    getch();
}

void display_allb()
{
    system("CLS");
	fp.open(f1name.c_str(),ios::in);
	if(!fp)
	{
	    cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
	    cout<<"\t\t\t\t\t\t\t************";
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }

    cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"=========================================================================\n";
	cout<<"Book Number\t\t" << "Book Name\t\t" << "Author\n";
	cout<<"=========================================================================\n";

	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
     	fp.close();
     	getch();
}

void display_alls()
{
    system("CLS");
    fp.open(f2name.c_str(),ios::in);
    if(!fp)
    {
        cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
        cout<<"\t\t\t\t\t\t\t************";
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }

    cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
	cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"==================================================================\n";
	cout<<"Admission No.\t\t" << "Name\t\t" << "Book Issued\n";
	cout<<"==================================================================\n";

	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}

	fp.close();
	getch();
}

void book_issue()
{
    char sn[6],bn[6];
	int found=0,flag=0;
    system("CLS");
    cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
	cout<<"\n\nBOOK ISSUE ...";
	cout<<"\n\n\tEnter The student's admission no.";
	cin>>sn;
	fp.open(f2name.c_str(),ios::in|ios::out);
    fp1.open(f1name.c_str(),ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
		if(strcmpi(st.retadmno(),sn)==0)
		{
			found=1;
			if(st.rettoken()==0)
			{
                cout<<"\n\n\tEnter the book no. ";
				cin>>bn;
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
				{
			   		if(strcmpi(bk.retbno(),bn)==0)
					{
						bk.show_book();
						flag=1;
						st.addtoken();
						st.getstbno(bk.retbno());
                        int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\t Book issued successfully\n\nPlease Note: ";
						cout<<"Write current date in backside of book and submit ";
						cout<<"within 15 days fine Tk 1 for each day after 15 days period";
					}
                }
		  		if(flag==0)
                    cout<<"Book no does not exist";
			}
	    		else
                    cout<<"You have not returned the last book ";

		}
	}
    if(found==0)
    cout<<"Student record not exist...";
	getch();
  	fp.close();
  	fp1.close();
}

void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    system("CLS");
    cout<<"\t\t\t\t\t\t\tKMHJ LIBRARY\n";
    cout<<"\t\t\t\t\t\t\t************";
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The students admission no.";
    cin>>sn;
    fp.open(f2name.c_str(),ios::in|ios::out);
    fp1.open(f1name.c_str(),ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
	    if(strcmpi(st.retadmno(),sn)==0)
	    {
		    found=1;
		    if(st.rettoken()==1){
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                    if(strcmpi(bk.retbno(),st.retstbno())==0)
                    {
                        bk.show_book();
                        flag=1;
                        cout<<"\n\nBook deposited in no. of days";
                        cin>>day;
                        if(day>15)
                        {
                            fine=(day-15)*1;
                            cout<<"\n\nFine has to deposited Tk. "<<fine;
                        }
                        st.resettoken();
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t Book deposited successfully";
                    }
                }
                if(flag==0)
                cout<<"Book no does not exist";
            }
            else
                cout<<"No book is issued..please check!!";
		}
    }
    if(found==0)
	cout<<"Student record not exist...";
	getch();
    fp.close();
    fp1.close();
}

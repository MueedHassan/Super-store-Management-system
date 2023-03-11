#include<iostream>
#include<conio.h>
#include <string.h>
#include<fstream>
using namespace std;
void changepassword()
{
	string ex_usrnm;
	string ex_pswrd;	
	
	string usrnm;
	string pswrd;
		ifstream infile("pass.bin");
	infile>>ex_usrnm>>ex_pswrd;

	cout<<"\nENTER YOUR EXISTING USERNAME\n";
	cin>>usrnm;
	
	cout<<"\nENTER YOUR EXISTING PASSWORD\n";
	cin>>pswrd;
	if(usrnm==ex_usrnm&&pswrd==ex_pswrd)
	{
		string new_usrnm,new_pswrd;
		system("cls");
		cout<<"AUTHENTICATION COMPLETED! PLEASE PRESS ANY BUTTON TO CONTINUE!\n";
		getch();
		system("cls");
		psc:
		cout<<"\nENTER A NEW USERNAME\n";
		cin>>new_usrnm;
		if(ex_usrnm==new_usrnm)
		{
			cout<<"\nYOU ARE USING THE PREVIOUS USERNAME! PLEASE TRY AGAIN!";
			goto psc;
		}
		cout<<"\nENTER A NEW PASSWORD\n";
		cin>>new_pswrd;
		if(ex_pswrd==new_pswrd)
		{
			cout<<"\nYOU ARE USING THE PREVIOUS PASSWORD! PLEASE TRY AGAIN!";
			goto psc;
		}
		
		
		ofstream out("pass.bin");
		out<<new_usrnm<<' '<<new_pswrd;
		system("cls");
		cout<<"\n\n\n\t\t\tPASSWORD HAS BEEN CHANGED!";
		
	}
	
	
		

}

class abc
{
		int income;
	int profit;
	
	
	int fincome;
	int fprofit;
	
	public:
		void xbc()
		{
				ifstream infile("accounts.txt");
	infile>>income>>profit;

	infile.close();
	fincome=income+2500;
	fprofit=profit+400;
	
	
	ofstream outfile("accounts.txt");
	outfile<<fincome<<' '<<fprofit;
	outfile.close();
	
		}
};



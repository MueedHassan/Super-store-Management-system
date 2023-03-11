#include"product.h"
#include"inputdata.h"
#include"newpassword.h"
#include"account.h"
int main()
{product p;//object of class product
Billing b;//object of billing class
employee e2;//ADMIN KA OBJECT
abc x;
int trys=0;//password try limit
	system("COLOR c1"); 
cout<<"\n\n\n\n\n\n\n\t\t\t\t*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*";
cout<<"\n\t\t\t\t$\t\t \tWELCOME TO\t\t      $";
cout<<"\n\t\t\t\t*    NATIONAL     SUPERSTORE     MANAGEMENT  SYSTEM   *";
cout<<"\n\t\t\t\t$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$";
cout<<"\n\n\n\n\n Press any key to continue......\n";
	getch();
	system("cls");
cout<<"\n\n\t\t----------------------------------------------------------------------------------";
cout<<"\n\t\t\t\t       NATIONAL     SUPERSTORE     MANAGEMENT  SYSTEM         ";
cout<<"\n\t\t----------------------------------------------------------------------------------";
cow://Copy-On-Write
string ex_usrnm;
	string ex_pswrd;

	ifstream infile("pass.bin");
	infile>>ex_usrnm>>ex_pswrd;
	char Username[15];
	char Password[15];
//string Username,Password;
	char ch;
int i=0;

	    cyc:
		cout<<"\n\n\n\n\t\t\t\tEnter your Username and Password :)";
		cout<<"\n\n\n\t\t\t\t\tUSERNAME:";
		cin>>Username;
		cout<<"\n\n\t\t\t\t\tPASSWORD:";
		
do{ 
        Password[i]=getch(); 
        if(Password[i]!='\r'){ 
            printf("*"); 
        } 
        i++; 
    }while(Password[i-1]!='\r'); 
    Password[i-1]='\0';             // to print star




		if (Username==ex_usrnm&&Password==ex_pswrd) 
		{
			cout<<"\n\n\n\t\t\t\t\t...Login Successfull...";
			system("cls");
			cycle:
				system("COLOR f6");
				system("cls");
				begin:
			cout<<"\n\n\t\t\tPRESS 1 IF YOU WANT TO ENTER NEW PRODUCT\n\n\t\t\tPRESS 2 IF YOU WANT TO SEE DATA OF A PRODUCT\n\n\t\t\tPRESS 3 IF YOU WANT TO SEE THE WHOLE STOCK\n\n\t\t\tPRESS 4 IF YOU WANT TO DELETE A PRODUCT\n\n\t\t\tPRESS 5 IF YOU WANT TO GENERATE A BILL\n\n\t\t\tPRESS 6 IF YOU WANT TO ACCESS ADMINISTRATOR SIDE\n\n\t\t\tPRESS 0 TO CHANGE PASSWORD\n\n";
			int choice;
			cin>>choice;
			if(choice==1)
			{
				system("cls");
			cout<<"ENTER THE NUMBER OF NEW PRODUCTS YOU WANT TO ENTER\n";
				int no_new=0;
	cin>>no_new;
	system("cls");
	for(int i=0;i<no_new;i++)
	{

		A::addtoFile();
		cout<<"\n-------------------------------------\n\n";

	}	
	goto begin;
			}
			else if(choice==2)
			{dab:
				cout<<"\nPRESS 1 TO SEARCH BY NAME\nPRESS 2 TO SEARCH BY RETAIL PRICE\nPRESS 3 TO SEARCH BY CATEGORY\nPRESS 4 TO SEARCH BY NUMBERS OF PRODUCT LEFT\n";
				int alpha=0;
				cin>>alpha;
				if(alpha==1)
				{
					system("cls");
					p.product_by_name()	;	
				}
				else if(alpha==2)
				{
					system("cls");
					p.product_by_sellingprice();
				}
				else if(alpha==3)
				{
					system("cls");
					p.product_by_category();
				}
				else if(alpha==4)
				{
					system("cls");
					p.product_by_number();
				}
				else
				{
					cout<<"\nERROR! PRESS ANY BUTTON TO GO AGAIN.......!\n";
					getch();
				goto dab;	
				}		
		
			}
			else if(choice==3)
			{
			p.whole_stock();
			goto begin;	
			}
			else if(choice==4)
			{
			p.deleteRecords();
			goto begin;	
			}
			else if(choice==5)
			{
			b.putfile();
			x.xbc();	
		b.updateaccounts();
			b.getbill();
			goto begin;	
			}
				else if(choice==6)
			{
				system("cls");
				cout<<"PRESS 1 IF YOU WANT TO ENTER DATA\nPRESS 2 IF YOU DONT WANT TO ENTER DATA";
				int fart;
				cin>>fart;
				if(fart==1)
				{
					system("cls");
					e2.data_file();
					e2.info();
				}
			else
			{
					accounts a1;
				}	

 			
 		
 
			goto begin;	
			}
			else if(choice==0)
			{
				cout<<"\nARE YOU SURE YOU WANT TO CHANGE PASSWORD!\n 1:YES \n 2:NO";
				int boole;
				cin>>boole;
				if(boole==1)
				{
					changepassword();
					cout<<" PLEASE LOGIN AGAIN!";
					getch();
					goto cow;
				}
				else
				{
					goto begin;
				}
			}
			else
			{
			cout<<"\nERROR! PRESS ANY BUTTON TO GO AGAIN.......!\n";
					getch();
				goto begin;	
			}
		}
		else
		{
			if(trys<2)
			{
				cout<<"\n\t\t\t\n\t\t\tPassword in incorrect:( Try Again :)";
				getch();
				trys++;
				goto cyc;
			}
			else
			{
			for(int i=0;i<100;i++)
	{
	system("cls");
	cout<<"\n\t\t\t\n\n\n\t\n\n\n\t\n\n\n\n\n\n\n\n\t\t   !!!!! MULTIPLE LOGIN ATTEMPTS DETECTED, RESTART THE PROGRAM AND LOGIN AGAIN !!!!!";
	system("color 1F");

	system("color 3F");
	
			}
		
		}
	}

}



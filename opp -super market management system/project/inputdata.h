#include<iostream>
#include<conio.h>
#include <string.h>
#include<fstream>
using namespace std;
class A 
{		int sno;
		char name[200];
		int no_of_products;
		int buying_price;
		int retail_price;
		char expiry_date[200] ;
		char category[200] ;
		char sub_category[200];
	
//	A()
//	{
//		
//	}

public:
	
	static void addtoFile()
	{
		A forWrite;
		fflush(stdin);
		cout<<"Enter the serial number of the product";
		cin>>forWrite.sno;
		fflush(stdin);
		cout<<"Enter item name: ";
		cin.getline(forWrite.name,30);
		fflush(stdin);
		cout<<"Enter quantity: ";
		cin>>forWrite.no_of_products;
		here:
		cout<<"Enter buying price: ";
		cin>>forWrite.buying_price;
		cout<<"Enter retail price: ";
		cin>>forWrite.retail_price;
		fflush(stdin);
		if (forWrite.retail_price<forWrite.buying_price)
			{
				cout<<"ERROR! YOUR SELLING PRICE IS LESS THAN WHAT YOU BOUGHT THE PRODUCT FOR!\n           PRESS ANY KEY TO ENTER THE PRICES AGAIN";
				getch();
				goto here;
			}
			
			else if(forWrite.retail_price>forWrite.buying_price)
			{
				goto there;
			}
			else if (forWrite.retail_price=forWrite.buying_price)
			{
				error:
				cout<<"YOUR SELLING PRICE = YOUR BUYING PRICE,YOU ARE NOT MAKING A PROFIT\nARE YOU SURE YOU WANT TO CONTINUE OR ENTER PRICE AGAIN\nPRESS 1 TO CONTINUE\nPRESS 2 TO RE-ENTER THE PRICES";
				int yes_no;
				cin>>yes_no;
				if(yes_no==1)
				{
					goto there;
				}
				else if (yes_no==2)
				{
					goto here;
				}
				else 
				{
					goto error;
				}
			}
			there:
		cout<<"Enter expiry date: ";
		cin.getline(forWrite.expiry_date,30);
		fflush(stdin);
		cout<<"Enter category: ";
		cin.getline(forWrite.category,30);
		fflush(stdin);
		cout<<"Enter sub category: ";
		cin.getline(forWrite.sub_category,30);
		fflush(stdin);
		
		ifstream fin;
		ofstream fout;
		
		fin.open("product.txt");
		
		if(!fin)
		{
			fout.open("product.txt",ios::app);
			
			if(!fout)
			{
				cout<<"\nError reading file!";
				return;
			}
			else
			{
				fout.write((char*)&forWrite,sizeof(A));
				fout.close();
				cout<<"Item added successfully!";
				return;
			}
		}
		
		fout.open("temp.txt",ios::app);
		
		A forReadWrite;
		
		bool isPresent = false;
		
		while((fin.read((char*)&forReadWrite,sizeof(A))))
		{
			if(strcmp(forReadWrite.name,forWrite.name) == 0)
			{
				forReadWrite.retail_price = forWrite.retail_price; 
				forReadWrite.buying_price = forWrite.buying_price;
				forReadWrite.no_of_products += forWrite.no_of_products;
				isPresent = true;
			}
			
			fout.write((char*)&forReadWrite,sizeof(A));
		}
		
		if(isPresent == false)
		{
			fout.write((char*)&forWrite,sizeof(A));
		}
		
		fout.close();
		fin.close();
		
		remove("product.txt");
		rename("temp.txt","product.txt");
		
		cout<<"\nItem added successfully!";
		
	}
	
	
};

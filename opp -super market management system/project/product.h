#include<iostream>
#include<conio.h>
#include <string.h>
#include<fstream>
using namespace std;
class product
{	public:
		//protected:
		int sno;	
		char name[200];
		int no_of_products;
		int retailingprice;
		int sellingprice;
		char expiry_date[200] ;
		char category[200] ;
		char sub_category[200];
		
	
		
	void datafile()
	{
		
		fstream f;
		f.open("product.txt",ios::app);
	
		f.write((char*)this,sizeof(*this));
		
		f.close();
		
	
		
	}

	void print()
	{
		cout<<"\nSERIAL NUMBER:"<<sno
			<<"\nName: "<<name
		    <<"\nNumber of products"<<no_of_products
			<<"\nBuying Price: "<<retailingprice
			<<"\nRetail Price: "<<sellingprice
			<<"\nExpiry Date: "<<expiry_date
			<<"\nCategory: "<<category
			<<"\nSub Category: "<<sub_category;
		cout<<"\n\n\t\t----------------------------------------------------------------------------------";
	}
	void whole_stock()
	{
			product p;
		fstream f;
		f.open("product.txt",ios::in);
	
		while(f.read((char *)&p,sizeof(p)))
		{		
	 		p.print();//it print the things read from the file
		}
		
		}
		
	void product_by_name()
	{
		product p;
		fstream f;
		f.open("product.txt",ios::in);//opens the file
		string names;
			cout<<"ENTER THE NAME OF THE PRODUCT YOU WANT TO SEARCH\n";
		cin>>names;
		while(f.read((char *)&p,sizeof(p)))
		{
	  				if(names==p.name)//entered name than it  check with each name of the product in the file
		{
			p.print();
		}
		
		}
		
		f.close();//file closes

	}
	
		void product_by_sellingprice()
	{
			product p;
		fstream f;
		f.open("product.txt",ios::in);
		float price;
		cout<<"ENTER THE RETAIL PRICE OF THE PRODUCT YOU WANT TO SEARCH\n";
		cin>>price;
		while(f.read((char *)&p,sizeof(p)))
		{
	  				if(price==p.sellingprice)
		{
			p.print();
		}
		
		}
		
		f.close();

	}
	
	void product_by_category()///**
	{
			product p;
		fstream f;
		f.open("product.txt",ios::in);
		string cate;
			cout<<"ENTER THE CATEGORY OF THE PRODUCT YOU WANT TO SEARCH\n";
		cin>>cate;
		while(f.read((char *)&p,sizeof(p)))
		{
	  				if(cate==p.category)
		{
			p.print();
		}
		
		}
		
		f.close();

	}
	
			void product_by_number()
	{
			product p;
		fstream f;
		f.open("product.txt",ios::in);
		int number;;
		cout<<"ENTER THE NUMBER OF THE PRODUCT YOU WANT TO SEARCH\n";
		cin>>number;
		while(f.read((char *)&p,sizeof(p)))
		{
	  				if(number==p.no_of_products)
		{
			p.print();
		}
		
		}
		
		f.close();

	}
	
	// delete ka function
	
	void deleteRecords()
	{
            bool flag=false;
            fstream Delete("product.txt",ios::in );
            product obj;
			string nname;
            if(!Delete){
                cout<<"No Records found or Error in opening file!"<<endl;
                system("pause");
                system("cls");
        	}
            fstream Copy("Temp.txt",ios::out );
            if(!Copy){
            	cout<<"Error in opening file"<<endl;
            	exit(1);
            }
            
            cout<<"ENTER THE NAME OF PRODUCT YOU WANT TO DELETE:";
			cin>>nname;
            Delete.seekg(0, ios::beg);//*

            while(Delete.read(reinterpret_cast<char*> (&obj), sizeof(obj))){
                
                if(nname!=obj.name)//(strcmp(nname,obj.getCode())!=0 )
				{
                    Copy.write(reinterpret_cast<char*> (&obj), sizeof(obj));
                } 
				else if(nname==obj.name)//(strcmp(nname,obj.getCode())==0)
				{
                    flag=true;
                }
            }

            Copy.close();
            Delete.close();
            if(flag!=true){
                remove("Temp.txt");
                cout<<endl<<"No records matched your inputted product name\n"<<endl<<endl;
                system("pause");
                system("cls");
            } else{
                remove("product.txt");
                rename("Temp.txt","product.txt");
                cout<<endl<<"PRODUCT: "<<nname<<" has been successfully removed\n\n\n";
                system("pause");
                system("cls");
            }
        }
};



//billing class

class Billing {
public:	char name[20];
	int pno[100];
	int quantity[100];
	int totalproduct;
	int totalprice;
	
	public:
		int totalincome ()
	{
		Billing b;
		fstream f;
		int tincome=0;
		f.open("bill.txt",ios::in|ios::out);
		f.seekg(0);
		while(!f.eof())
		{
			f.read(reinterpret_cast<char *>(&b),sizeof(b));
			tincome=tincome+b.totalprice;
		}
		cout<<"total income untill now ="<<tincome<<endl;
		return tincome;
	}
	int profit()
	{
		int i=0;
		Billing b;
		product p;
		int tprofit=0;
		fstream fb;
		fstream fp;
			
			fb.open("bill.txt",ios::in);
			fp.open("product.txt",ios::in);
			fb.seekg(0);
			fp.seekg(0);
			while(!fb.eof())
			{
			
			fb.read(reinterpret_cast<char *>(&b),sizeof(b));
			
				for(i=0;i<b.totalproduct;i++)
			{
				while(!fp.eof())
			{
			fp.read(reinterpret_cast<char *>(&p),sizeof(p));
			if(b.pno[i]==p.sno)
			{
				tprofit+=(p.sellingprice-p.retailingprice)*b.quantity[i];
				break;
		    }
		    
		}
		
	}
}
cout<<tprofit<<endl;
return tprofit;



}
void updateaccounts(){
//	Billing b;
//	int totalincome;
//	int totalprofit;
//	ofstream outfile;
//	outfile.open("accounts.txt");
//	totalincome=b.totalincome();
//	totalprofit=b.profit();
//	outfile<<totalincome<<' '<<totalprofit;
//	outfile.close();
cout<<"ACCOUNT FILE HAS BEEN UPDATED!!!";
}
		void billing()
		{
			
			int i;
			int q;
			int no;
			char ch;
			cout<<"enter the name of costumer"<<endl;
			cin>>name;
			product p;
			fstream f;
			f.open("product.txt",ios::in);
		
			do
			{
		    f.seekg(0);
			cout<<"enter the sno of the product "<<endl;
			cin>>no;
			cout<<"enter the quantity of product"<<endl;
			cin>>q;
			while(!f.eof())
			{
			f.read(reinterpret_cast<char *>(&p),sizeof(p));
				if(no==p.sno)
				{
					pno[i]=p.sno;
					quantity[i]=q;
					i++;
					cout<<p.name<<"\t"<<p.sellingprice<<endl;
					totalprice=totalprice+(p.sellingprice*q);
					totalproduct++;
					break;
				}
			}
		
			cin>>ch;
		}while(ch!='n');
		f.close();
		}
		void putfile()
		{
			Billing b;
			fstream fp;
			fp.open("bill.txt",ios::app);
			b.billing();
			fp.write((char *)&b,sizeof(b));
			fp.close();
		}
			void getbill()
		{
			int i;
			char name[20];
			product p;
			Billing b;
			fstream f;
			fstream fp;
			fp.open("bill.txt",ios::in);
			f.open("product.txt",ios::in);
			cout<<"enter the name of costumer of which the bill is to be display"<<endl;
			cin>>name;
			cout<<"name"<<"\t"<<"quantity"<<"\t"<<"price"<<endl;
			fp.seekg(0);
		while (!fp.eof())
		{
		
			fp.read(reinterpret_cast<char *>(&b),sizeof(b));
			if (strcmp(name,b.name)==0)
			{
				
			
					for(i=0;i<b.totalproduct;i++)
					{
					
				while (!f.eof())
				{
					
					f.read(reinterpret_cast<char *>(&p),sizeof(p));
						if(b.pno[i]==p.sno)
						{
							cout<<p.name<<"\t"<<"\t"<<b.quantity[i]<<"\t"<<p.sellingprice<<endl;
							
			                break;
						}
				}
				}
						break;
				}
				
				
			
			}
			cout<<"total bill ="<<b.totalprice<<endl;
		}
	
	
};



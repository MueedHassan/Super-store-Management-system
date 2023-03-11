#include<iostream>
#include<conio.h>
#include <string.h>
#include<fstream>
using namespace std;
class employee{
	public:
	char name[50];
	long long int no;
	int salary;
	char post[50];
	int total_salary;
	employee()
	{
		total_salary=0;
	}

	
	void data()
	{
		cout << "enter employee name " <<endl;
		cin>> name;
	    cout << "enter phone number" << endl;
		cin>> no ;
		fflush(stdin);
		cout << "enter the designation of the employee" << endl;
		fflush(stdin);
		cin >> post;
		cout << "enter the salary of the employee" << endl;
		cin >> salary;
		cout << "\t\t\t\t\t///////////////////"<<endl;
	}
	void data_file()
	{
		employee e1;
		fstream fe;
		fe.open("employee.txt",ios::app);
		e1.data();
		fe.write((char *)&e1,sizeof (e1));
		fe.close();  
		
	}
	void print()
	{
	cout << " name of the employee is  " << name<<endl;
	cout<< " salary is " << salary<<endl;
	cout << " number is 0"<< no<<endl;
	cout << " position is " << post<<endl;
	cout << "\n\t\t\t\t***************************************\n";
	}
	
	void info()
	{
		employee e1;
		//fstream fe;
		fstream fp;
		fp.open("employee.txt",ios::in);
//		string names;
//		cout<< "enter the name of employee"<<endl;
//		cin >> names;
//		while (fp.read((char *)&e1,sizeof(e1))!=NULL)
//		{
//			e1.print();
//		}
		 while (fp.read((char *)&e1,sizeof(e1))!=NULL)
		 {
		 
		 
			 total_salary=total_salary+e1.salary;		 	
		 }
	cout << total_salary;
	
		fp.close();
		
		
	ofstream outfile("total.txt");
	outfile <<"total salary of the employees is " <<total_salary	 ;	 
	
}
	
};

class accounts : public employee {
	public:
		int ch;
		char i [400];
		accounts()
		{
			back:
				cout <<"\n\n\t\t\tPRESS ANY KEY TO CONTINUE \n\n" ;
				getch();
				system("cls");
			cout << "\n\t\t\tif you want to see employees total salary press 1"<<endl;
			cout << "\n\t\t\tif you want to see employees data press 2"<<endl;
			cout << "\n\t\t\tif you want to see total profit press 3"<<endl;
			cout << "\n\t\t\tif you want to pay salaries to employes press 4"<<endl;
			cout << "\n\t\t\tif you want to see total income press 5" << endl;
		//	cout << "if you want to see total profit after expenses press 6"<<endl;
			cout << "\n\t\t\tif you want to pay rent press 6"<<endl;
			cout << "\n\t\t\tif you want to exit press 7"<< endl;
			cin >> ch;
		
	
	
	switch(ch)
	{
		case 1:
			{
			
				ifstream open("total.txt");
				 open.getline(i,40);
			//open>>i;
				 cout <<"\ntotal salaries is "<< i<< endl;
				 break;
			}
			case 2:
				{
					fstream fe;
					employee e1;
					fe.open("employee.txt",ios::in) ;
					while (fe.read((char *)&e1, sizeof(e1) )!=NULL )
					{
						e1.print();
					}
					break;
				}
				case 3:
					{
						ifstream f("accounts.txt");
						int a,b;
						while (f>>a>>b)
						{
							cout << "\ntotal profit from is " << b;
						}
						break;
					}
					case 4:
						{
							ifstream ft("total.txt");
							int a,b;
							while (ft>>a)
							{
								b=a;  // b is the total salaries of employes
							//	cout << "\n" <<a<<endl;
							}
							ifstream fa("accounts.txt");
							int c,d,e,f;
							while (fa>>c>>d)
							{
								e=c;  // e is the total sale 
								f=d;  // f is the total profit by the products
							//	cout << d;
							}
							int g;
//							if (d>b)
//							{
							
							g=d-b;
							//cout << "toal profit after expenses is " << g;
							ofstream fna("accounts.txt");
							fna << e;
							fna << "   " << g;
							cout << "\nsalaries paid to employess!!!!!";//}
//							else 
//							cout <<"INSUFFICIENT AMOUNT OF BALANCE"<<endl;
							break;
							
						}
						case 5:
							{
								ifstream fn("accounts.txt");
								int i,j;
								while (fn>>i>>j)
								{
									cout <<"total sale is " << i;
								}
								break;
							}
							case 6:
								{
									int rent;
									cout <<"\nenter the rent "<<endl;
									cin >> rent;
									ifstream fn("accounts.txt");
								int i,j,k;
								while (fn>>i>>j)
								{
									k=i;  // k is equal to remaining profit or profit by products
//										cout <<"\ntotal profit after expenses is " << l;
								}
								int o;
								if (j>rent)
								{
								
									o=j-rent;
									ofstream op("accounts.txt");
									op << k;
									op << " " << o;
									cout << "\nRENT PAID SUCCESSFULLY!!!!!" << endl;
								}
								else 
								cout <<"INSUFFICIENT AMOUNT OF BALANCE"<<endl;
									break;
									
//									
//                                    int l,m,n;
//									ifstream fr("account.txt");
//									//int l,m,n;
//								 fr>>l>>m;
//								 cout <<"\ntotal profit after expenses is " << l;
////									while(fr>>l>>m)
////									{
////									//	n=l;  // n is equal to remaining profit or profit by products
////										cout <<"\ntotal profit after expenses is " << l;
////									}
////									"   " << o; 
									
								}
								case 7:
									{
										exit(1);
									}
							default:
								cout <<"\ninvalid input";
					
				
				
				
	}
	
goto back;	
}
	
	
};

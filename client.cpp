#include <iostream>
#include <string>

using namespace std;


int main()
{
	bool cont=true;
	char choice;
	
	do
	{	
		system("cls");
		cout<<"Team Spanky: Foodie Extravaganza"<<endl<<endl;
		
		cout<<"<1>	View Restaurants and Menus"<<endl;
		cout<<"<2>	Plan a Trip"<<endl;
		cout<<"<3>	Edit Restaurants and Menus"<<endl;
		cout<<"<Q>	Quit"<<endl;
		cout<<"Enter choice option: ";
		cin>>choice;
		cin.clear();
		
		switch (choice)
		{
			case '1':
				{	
					cout<<"View"<<endl;
					//viewData();
					break;
				}
			case '2':
				{
					cout<<"Plan"<<endl;
					//planTrip();
					break;
				}
			case '3':
				{
					cout<<"login"<<endl;
					//if (loggedIN())
					//	adminEdit();
					//else
					//	cout<<"Login Error. Please try again."<<endl;
					break;
				}
			case 'q':
				{	
					cout<<"quit"<<endl;
					cont=false;
					break;
				}
			case 'Q':
				{
					cout<<"quit"<<endl;
					cont=false;
					break;
				}
		}
		
		system("pause");
	}while (cont==true);
}

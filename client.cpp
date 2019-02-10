#include <iostream>
#include <string>

using namespace std;

//Sub Menus of Main
void viewData();
void planTrip();
void adminEdit();

//Error Checks
int IntInput(string inMsg,    //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed
float FloatInput(string inMsg,  //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed
double DoubleInput(string inMsg,  //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed
char YNCharInput(string inMsg);

string ADMIN_PASSWORD="YourMom!";

int main()
{
	bool cont=true;
	string passwordTest;
	char choice;
	
	do
	{	
		system("cls");
		cout<<"Team Spanky: Foodie Extravaganza"<<endl;
		cout<<"Main Menu"<<endl<<endl;
		
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
					viewData();
					break;
				}
				
			case '2':
				{
					planTrip();
					break;
				}
				
			case '3':
				{
					cin.ignore(50,'\n');
					cout<<"Enter Password: ";
					getline(cin, passwordTest);
					
					if (passwordTest.compare(ADMIN_PASSWORD)==0)
						adminEdit();
					else
					{
						cout<<"Password incorrect. Nice try mofo"<<endl;
						system("pause");
					}
					break;
				}
				
			case 'q':
				{	
					cout<<"quit"<<endl;
					cont=false;
					system("pause");
					break;
				}
			case 'Q':
				{
					cout<<"quit"<<endl;
					cont=false;
					system("pause");
					break;
				}
		}
		
		
	}while (cont==true);
}


void viewData()
{
	bool cont=true;
	char choice;
	
	do
	{
		system("cls");
		cout<<"Team Spanky: Foodie Extravaganza"<<endl;
		cout<<"View Restaurants"<<endl<<endl;
		
		//<x> (insert name of restaurant)
		
		//cin choice of restaurant to view menu and distances from all other restaurants
		cin>>choice;
		cin.clear();
		
		
		//Switch on choice. corresponds to what restaurant to view the data of.
			//transfers to a screen showing the restaurant's menu and distances to all other restaurants.
			
		cont=false;
		
		system("pause");
		
	}while (cont==true);
}

void planTrip()
{
	bool cont=true;
	char choice;
	
	do
	{
		system("cls");
		cout<<"Team Spanky: Foodie Extravaganza"<<endl;
		cout<<"Plan a Trip"<<endl<<endl;
		
		cout<<"<1> Plan your own trip"<<endl;
		cout<<"<2> Take the shortest route"<<endl;
		cout<<"<3> Take a random routue"<<endl;
		cout<<"<q> Return to main"<<endl;
		cin>>choice;
		cin.clear();
		
		
		switch (choice)
		{
			case '1':
				{
					cout<<"Plan trip function"<<endl;
					break;
				}
			
			case '2':
				{
					cout<<"Shoetest route function"<<endl;
					break;
				}
				
			case '3':
				{
					cout<<"Random trip function"<<endl;
					break;
				}

			case 'q':
				{
					cont=false;
					break;
				}
			case 'Q':
				{
					cont=false;
					break;
				}
		}
		
		system("pause");
		
	}while (cont==true);
}

void adminEdit()
{
	bool cont=true;
	char choice;
	
	do
	{
		system("cls");
		cout<<"Team Spanky: Foodie Extravaganza"<<endl;
		cout<<"Administrative Changes"<<endl<<endl;
		
		cout<<"<1> Add a restaurant"<<endl;
		cout<<"<2> Delete a restaurant"<<endl;
		cout<<"<3> Edit a restaurant's information"<<endl;
		cout<<"<q> Return to main"<<endl;
		cin>>choice;
		cin.clear();
		
		
		switch (choice)
		{
			case '1':
				{
					cout<<"Add restaurant function"<<endl;
					break;
				}
			
			case '2':
				{
					cout<<"Delete restaurant function"<<endl;
					break;
				}
				
			case '3':
				{
					cout<<"Edit restaurant function"<<endl;
					break;
				}

			case 'q':
				{
					cont=false;
					break;
				}
			case 'Q':
				{
					cont=false;
					break;
				}
		}
		
		system("pause");
		
	}while (cont==true);
}




int IntInput(string inMsg,    //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed
{
	int  integer; //input by user to be checked
	bool valid;   //LCV for validated input
	do
	{
		valid = true;
		cout << inMsg;
		cin  >> integer;
		cin.ignore(10000, '\n');

		if (cin.fail() || integer < MIN || integer > MAX)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			valid = false;
			cout << "Invalid input, please try " << MIN << '-' << MAX << endl;
		}
	} while (!valid);
	return integer;
}



float FloatInput(string inMsg,  //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed
{
	float floater; //input by user to be checked
	bool valid;    //LCV for validated input
	do
	{
		valid = true;
		cout << inMsg;
		cin >> floater;
		cin.ignore(10000000, '\n');


		if (cin.fail() || floater < MIN || floater > MAX)
		{
			cin.clear();
			cin.ignore(10000000, '\n');
			valid = false;
			cout << "Invalid input, please try " << MIN << '-' << MAX << endl;
			//system("pause");
			//system("cls");
		}
	} while (!valid);
	return floater;
}



double DoubleInput(string inMsg,  //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed
{
	double dbl; //input by user to be checked
	bool valid;    //LCV for validated input
	do
	{
		valid = true;
		cout << inMsg;
		cin >> dbl;
		cin.ignore(10000000, '\n');


		if (cin.fail() || dbl < MIN || dbl > MAX)
		{
			cin.clear();
			cin.ignore(10000000, '\n');
			valid = false;
			cout << "Invalid input, please try " << MIN << '-' << MAX << endl;
			//system("pause");
			//system("cls");
		}
	} while (!valid);
	return dbl;
}


char YNCharInput(string inMsg) //input message
{
	char  character; //input by user to be checked
	bool valid;   //LCV for validated input
	do
	{
		valid = true;
		cout << inMsg;
//		character = getch();
		character = tolower(character);

		if (character != 'y' && character != 'n')
		{
			cin.clear();
			cin.ignore(10000, '\n');
			valid = false;
			cout << "Invalid input, please try y/n." << endl;
		}
	} while (!valid);
	return character;
}

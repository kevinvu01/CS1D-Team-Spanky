#include "cartType.h"
#include <queue>

using namespace std;

const string TXTFILE = "data.txt\0";


bool load(vector <cartType *> &);
bool save(vector <cartType *> &);

//Sub Menus of Main
void viewData(vector <cartType *> &pool);
void planTrip(vector <cartType *> &);
void executeTrip(queue <cartType *> &);
void adminEdit(vector <cartType *> &);

void addRestaurant(vector <cartType *> &);

//Error Checks
int IntInput(string inMsg,    //menu prompt
	const int MIN, //minimum value allowed
	const int MAX); //maximum value allowed
float FloatInput(string inMsg,  //menu prompt
	const int MIN, //minimum value allowed
	const int MAX); //maximum value allowed
double DoubleInput(string inMsg,  //menu prompt
	const int MIN, //minimum value allowed
	const int MAX); //maximum value allowed
char YNCharInput(string inMsg);

const string ADMIN_PASSWORD = "CS1Dproject";

int main()
{
	string passwordTest;
	int choice = 0;
	vector <cartType *> pool;
	
	if(load(pool))
	{
	do
	{	
		cout<<"Team Spanky: Foodie Extravaganza"<<endl;
		cout<<"Main Menu"<<endl<<endl;
		
		cout<<"<1>	View Restaurants and Menus"<<endl;
		cout<<"<2>	Plan a Trip"<<endl;
		cout<<"<3>	Edit Restaurants and Menus"<<endl;
		cout<<"<0>	Quit"<<endl;
		
		choice = IntInput("Enter choice: ", 0, 3);
		
		switch (choice)
		{
			case 1:
				{	
					viewData(pool);
					break;
				}
				
			case 2:
				{
					planTrip(pool);
					break;
				}
				
			case 3:
				{
					cout << "Enter Password: ";
					getline(cin, passwordTest);
					
					if (passwordTest.compare(ADMIN_PASSWORD)==0)
						adminEdit(pool);
					else
					{
						cout << "Password incorrect." << endl;
					}
					break;
				}
			case 0:
					break;
			default : cout << "ERROR\n";
		}
	}while (choice != 0);
	}
	else
		cout << "Data not loaded.\n";
	
	if(save(pool))
	{
		cout << "Happy eating.\n";
		
		for(int i = 0; i < pool.size(); i++)
		{
			delete pool[i];
		}
	}
	else
		cout << "Error saving data.\n";
}

void addRestaurant(vector <cartType *> &pool)
{
	cartType *temp = new cartType;
	double tempD;
	string tempS, tempN;
	int tempI,    tempRN;
	distPair      tempP;
	menuItemType *tempM;
	vector       <menuItemType> menu;
	distPair map[NUM_RESTAURANTS];


	
	cout << "Enter the name of the restaurant: ";
	getline(cin, tempN);
	
	cout << "The restaurant number for " << tempN << " will be " << pool.size() + 1 << endl;
	//pool.length will be as such
	
	cout << "Menu items for " << tempN << ": " << endl;
	int j = IntInput("Enter the number of menu items: ", 1, 10);
	
	for(int i = 0; i < j; i++)
	{
		cout << "Enter name of menu item " << i << ": ";
		getline(cin, tempS);
		tempD = IntInput("Enter price: $", 0, 10000.00);
		tempM = new menuItemType(tempS, tempD, 0);
		menu.push_back(*tempM);
	}
	
	for(int i = 0; i < 8; i++)
	{
		//tempP = new distPair;
		cout << "Enter the restaurant number and distance to said restaurant\n    # ";
		cin  >> tempP.code;
		cout << "dist: ";
		cin  >> tempP.value;
		cin.ignore(1000, '\n');
		
		map[i] = (tempP);
	}
		
	cout << "Enter distance to Saddleback: ";
	cin  >> tempD;
	cin.ignore(1000, '\n');
	
	distanceType tempDistType(map, 8, tempD);
	vector<menuItemType> cart(4);

	
}

bool load(vector <cartType *> &pool)
{
	bool success = false;
	
	cartType *temp;
	ifstream oofda;
	oofda.open("CS1D Spring 2019 Fast Food Project.txt\0");
	while(!oofda.eof())
	{
		temp = new cartType;
		oofda >> *temp;
		pool.push_back(temp);
	}
	
	if(!oofda.eof())
		cout << "Error: more data to be loaded," << endl;
	else if(pool.size() == 0)
		cout << "Error: no data was loaded.\n";
	else if(oofda.eof())
		success = true;
	else
		cout << "Other error.\n";
	
	oofda.close();

/*
	oofda.open("CS1D Spring 2019 New Fast Food Project.txt\0");
	while(!oofda.eof())
	{
		temp = new cartType;
		oofda >> *temp;
		pool.push_back(temp);
	}
	
	if(!oofda.eof())
		cout << "Error: more data to be loaded," << endl;
	else if(pool.size() == 0)
		cout << "Error: no data was loaded.\n";
	else if(oofda.eof())
		success = true;
	else
		cout << "Other error.\n";
	
	oofda.close();
	*/
	return success;
}

bool save(vector <cartType *> &pool)
{
	bool success = false;
	ofstream oofda;
	oofda.open(TXTFILE);

	for(int i = 0; i < pool.size(); i++)
	{
		oofda << *pool[i];
	}
	
	oofda.close();
	success = true;
	
	return success;
}

void viewData(vector<cartType *> &pool)
{
	int choice = 0;
	int i;
	
	do
	{
		i = 1;
		cout<<"Team Spanky: Foodie Extravaganza"<<endl;
		cout<<"View Restaurants"<<endl<<endl;
		
		for(int i = pool.size() - 1; i >= 0; i--)
			cout << '<' << i << "> " << pool[i]->getName() << endl;
		
		cout << "<-1> Return\n";
		choice = IntInput("Your choice: ", -1, pool.size() - 1);
		
		if(choice > -1)
		{
			pool[choice]->printMenu();
			cout << "Distance to Saddleback: " << pool[choice]->getDistToSC() << endl;
		}
	}while (choice != -1);
}

void planTrip(vector <cartType *> &allR)
{
	vector <cartType *> tripPool(allR);
	queue  <cartType *> trip;

	int choice = 0;
	int num	   = 0;
	bool exist = false;
	cartType * shortest = new cartType;
	
	do
	{
		num   = 0;
		exist = false;
		distanceType::totalDist = 0;
		cout<<"Team Spanky: Foodie Extravaganza"<<endl;
		cout<<"Plan a Trip"<<endl<<endl;
		
		cout<<"<1> Plan trip to initial 10 restaurants from Saddleback"<<endl;
		cout<<"<2> Plan trip starting at Dominos"<<endl;
		cout<<"<3> Plan custom trip"<<endl;
		cout<<"<0> Return to main"<<endl;
		choice = IntInput("Your choice: ", 0, 3);
		
		switch (choice)
		{
			case 1:
				{
					cout << "Trip to initial 10 restaurants starting at Saddleback" << endl;
					*shortest = *tripPool[0];
					for(int i = 1; i < tripPool.size(); i++)
					{
						if(shortest->getDistToSC() > tripPool[i]->getDistToSC() && tripPool[i]->getName() != "Empty")
							*shortest = *tripPool[i];
					}
					//cout << shortest->getName() << endl;
					tripping(*shortest, tripPool, trip, 10);
					executeTrip(trip);
					cout << "The total distance for the trip was: " << distanceType::totalDist << endl;
					break;
				}
			case 2:
				{
					cout << "Trip starting at Dominos" << endl;
					num = IntInput("Enter the number of restaurants to visit: ", 1, tripPool.size());
					
						*shortest = *tripPool[2];
						tripping(*shortest, tripPool, trip, num);
						executeTrip(trip);
					break;
				}
			case 3:
				{
					
					cout << "Custom trip function"    << endl;
					
					break;
				}
			case 0:	 break;
			default: cout << "error";
		}
	}while(choice != 0);
	
	//delete shortest;
}

void executeTrip(queue <cartType *> &trip)
{
	cartType *temp;
	do{
		temp = trip.front();
		trip.pop();
		
		temp->addToCart();
	}while(!trip.empty());
}

void adminEdit(vector <cartType *> &pool)
{
	int choice = 0;
	
	do
	{
		cout << "Team Spanky: Foodie Extravaganza" << endl;
		cout << "Administrative Changes" << endl   << endl;
		
		cout << "<1> Add a restaurant"   << endl;
		cout << "<2> Delete a restaurant"<< endl;
		cout << "<3> Edit a restaurant's information" << endl;
		cout << "<0> Return to main"     << endl;
		choice = IntInput("Your choice: ", 0, 3);
		
		switch (choice)
		{
			case 1:
				{
					cout << "Add restaurant function" << endl;
					break;
				}
			
			case 2:
				{
					cout<<"Delete restaurant function"<<endl;
					break;
				}
				
			case 3:
				{
					cout<<"Edit restaurant function"<<endl;
					break;
				}

			case 0: break;
			default: cout << "error";
		}		
	}while (choice != 0);
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
		}
	}while(!valid);
	return floater;
}

char YNCharInput(string inMsg) //input message
{
	char  character; //input by user to be checked
	bool valid;   //LCV for validated input
	do
	{
		valid = true;
		cout << inMsg;
		cin.get(character);
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

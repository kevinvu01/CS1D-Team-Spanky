#include "cartType.h"
#include <queue>

using namespace std;

const string TXTFILE = "data.txt\0";


bool load(vector <cartType *> &);
bool save(vector <cartType *> &);

//Sub Menus of Main
void viewData(vector <cartType *> &pool);
void printRestaurants(vector <cartType *> &pool);
void planTrip(vector <cartType *> &);
void executeTrip(queue <cartType *> &);
void adminEdit(vector <cartType *> &);
void addRestaurant(vector <cartType *> &);
// void foundShortest();

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
	if(pool.size() < NUM_RESTAURANTS){
		
	cout << "ADD RESTAURANT\n";
	int choice = IntInput("<0> Manually\n<1> Via file\n->", 0, 1);
	if(choice == 0){
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
		
		for(int i = 0; i < pool.size(); i++)
		{
			//tempP = new distPair;
			cout << "Enter the distance in miles to restaurant #" << i + 1 << ": ";
			tempP.value = DoubleInput("", .001, 1000);
			pool[i]->appendNewDist(tempP.value);
			map[i] = (tempP);
		}
		map[pool.size()].value = 0.0;
			
		tempD = DoubleInput("Enter distance to Saddleback: ", 0, 1000);
		
		distanceType tempDistType(map, 8, tempD);
		vector<menuItemType> cart(4);

		cartType *temp = new cartType(menu, tempDistType, cart, pool.size(), tempN, 0, 0);
		pool.push_back(temp);
	}
	else
	{
		string temp;
		bool success = false;
		cartType *tempR;
		ifstream oofda;
		cout << "Enter the name of the file to upload: ";
		getline(cin, temp);
		
		oofda.open(temp.c_str());
		if(oofda.fail())
			cout << "The file does not exist.\n";
		else
		{
		while(!oofda.eof())
		{
			tempR = new cartType;
			oofda >> *tempR;
			pool.push_back(tempR);
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
		}
	}
	}//end if there is room for more restaurants to add
	else
		cout << "Cannot add restaurant. Database is full.\n";
}

bool load(vector <cartType *> &pool)
{
	bool success = false;
	
	cartType *temp;
	ifstream oofda;
	oofda.open("CS1D Spring 2019 Fast Food Project.txt\0");
	while(!oofda.eof() && pool.size() < NUM_RESTAURANTS)
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
		
		printRestaurants(pool);
		
		cout << "<-1> Return\n";
		choice = IntInput("Your choice: ", -1, pool.size() - 1);
		
		if(choice > -1)
		{
			pool[choice]->printMenu();
			cout << "Distance to Saddleback: " << pool[choice]->getDistToSC() << endl;
		}
	}while (choice != -1);
}

void printRestaurants(vector <cartType *> &pool)
{
	for(int i = 0; i < pool.size(); i++)
		cout << '<' << i << "> " << pool[i]->getName() << endl;
}

void planTrip(vector <cartType *> &allR)
{
	vector <cartType *> tripPool;
	queue  <cartType *> trip;

	int choice = 0;
	int choice2 = 0;
	int num	   = 0;
	int c      = 0;
	bool exist = false;
	cartType * shortest = new cartType;;
	
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
					tripPool = allR;
					cout << "Trip to initial 10 restaurants starting at Saddleback" << endl;
					*shortest = *tripPool[0];
					for(int i = 1; i < tripPool.size(); i++)
					{
						if(shortest->getDistToSC() > tripPool[i]->getDistToSC() && tripPool[i]->getName() != "Empty")
						{
							c = i;
							*shortest = *tripPool[i];
						}
					}
					
					distanceType::totalDist += shortest->getDistToSC();
					tripPool.erase(tripPool.begin() + c);
					tripping(*shortest, tripPool, trip, 9);
					executeTrip(trip);
					cout << "The total distance for the trip was: " << distanceType::totalDist << endl;
					break;
				}
			case 2:
				{
					tripPool = allR;
					cout << "Trip starting at Dominos" << endl;
					num = IntInput("Enter the number of restaurants to visit: ", 1, tripPool.size());
					*shortest = *tripPool[2];
				
					distanceType::totalDist += shortest->getDistToSC();
					tripping(*shortest, tripPool, trip, num - 1);
					
					executeTrip(trip);
					cout << "The total distance for the trip was: " << distanceType::totalDist << endl;
					break;
				}
			case 3:
				{
					cout << "Custom trip. Enter " << allR.size() << " to commence trip." << endl;
					do{
						for(c = 0; c < allR.size(); c++)
							cout << '<' << c << "> " << allR[c]->getName() << endl;
						choice2 = IntInput("Choose your restaurants:", 0, allR.size());
				
						if(choice2 < allR.size())
							tripPool.push_back(allR[choice2]);
						
					}while(choice2 != allR.size());
					
					cout << tripPool[0]->getName() << endl;
					*shortest = *tripPool[0];
					c = 0;
					for(int i = 1; i < tripPool.size(); i++)
					{
						cout << tripPool[i]->getName() << endl;
						if(shortest->getDistToSC() > tripPool[i]->getDistToSC() && tripPool[i]->getName() != "Empty")
						{
							*shortest = *tripPool[i];
							c = i;
						}
					}

					tripping(*shortest, tripPool, trip, tripPool.size() - 1);
					distanceType::totalDist += shortest->getDistToSC();

					executeTrip(trip);
					cout << "The total distance for the trip was: " << distanceType::totalDist << endl;
					break;
				}
			case 0:	 break;
			default: cout << "error";
		}
	}while(choice != 0);
}

void executeTrip(queue <cartType *> &trip)
{
	cartType *temp;
	do{
		temp = trip.front();
		trip.pop();
		
		temp->addToCart();
	}while(!(trip.empty()));
}

void adminEdit(vector <cartType *> &pool)
{
	int choice = 0;
	int choice2 = 0;
	
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
					cout << "Add restaurant:" << endl;
					addRestaurant(pool);
					break;
				}
			
			case 2:
				{
					cout<<"Delete restaurant function"<<endl;
					printRestaurants(pool);
					choice2 = IntInput("Choocse restaurant to delete: ", 0, pool.size());

					pool.erase(pool.begin() + choice2);
					cout << "Erased.\n";
					break;
				}
				
			case 3:
				{
					cout<<"Edit restaurant function"<<endl;
					printRestaurants(pool);
					choice2 = IntInput("Choocse restaurant to edit: ", 0, pool.size() - 1);
					pool[choice2]->updateInfo();
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

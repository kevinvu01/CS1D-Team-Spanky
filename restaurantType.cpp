#include "restaurantType.h"
#include "cartType.h"


restaurantType::restaurantType()
			:cart(),
			 map(), 
			 menu()
{
	name          = "Empty";
	revenue       = 0;
	restaurantNum = 0;
}

restaurantType::restaurantType(const vector<menuItemType> & ml, const distanceType& dm, const vector<menuItemType> &c, int restCode, string n, double rev)
			:cart(c),
			 map(dm), 
			 menu(ml)
{
	name          = n;
	revenue       = rev;
	restaurantNum = restCode;
	cleanMenus();
}

restaurantType::restaurantType(const restaurantType & other)
{
	copy(other);
	cleanMenus();
}

restaurantType::~restaurantType()
{
	menu.clear();
	cart.clear();
} 

const restaurantType & restaurantType::operator=(const restaurantType &other)
{
	return copy(other);
}

restaurantType& restaurantType::copy(const restaurantType&other)
{
	restaurantType temp;
	temp.name          = other.name;
	temp.restaurantNum = other.restaurantNum;
	temp.revenue       = other.revenue;
	
	temp.menu = other.menu;
	temp.cart = other.cart;
	temp.map  = other.map;
	
	cleanMenus();
	
	return temp;
}
	
void restaurantType::printMenu() 
{
	int i = 1;
	
	cout << name << endl
		 << "Food Menu\n";
		 
	for(int i = 0; i < menu.size(); i++)
	{
		cout << '<' << i << "> ";
		menu[i].print();
	}
}

void restaurantType::updateInfo()
{
	int    choice    = 0;
	int    choice2   = 0;	
	string tempName  = "";
	double tempPrice = 0;
	
	do{
		cout << getName() << endl
			 << "<0> Done\n"
			 << "<1> Change restaurant name\n"
			 << "<2> Change the price of a menu item\n"
			 << "<3> Remove menu item from restaurant\n"
			 << "<4> Add menu item to restaurant\n";
			 
		choice = IntInput("Your choice: ", 0, 4);
		
		switch(choice)
		{
			case 1: cout << "\nOld name: " << name << "\nNew name: ";
					getline(cin, name);
					break;
			case 2: do{
						printMenu();
						cout << "<" << menu.size() << "> Done\n";
						
						choice2   = IntInput("Choose which menu item to alter the price of: ", 0, menu.size());
						tempPrice = DoubleInput("New Price: ", 0, 10000);
						
						menu[choice2 - 1].changePrice(tempPrice);
					}while(choice2 != 0);
					break;
			case 3: do{
						printMenu();
						cout << "<" << menu.size() << "> Done\n";
						
						choice2 = IntInput("Choose which menu item to wish to exterminate: ", 0, menu.size());
						
						vector<menuItemType>::iterator it = menu.begin();
						while(!(*it == menu[choice2 - 1]))
							++it;
						
						if(!(it == menu.end()))
						{
							menu.erase(it);
							cout << "Erased.\n";
						}
						else
							cout << "ERROR DELETING\n";
						
					}while(choice2 != 0);
					break;
			case 4: 
					if(menu.size() < 8){
					tempName = "n/a";
					choice = 0;
					cout << "Enter name of the menu item: ";
					getline(cin, tempName);
											
					tempPrice = DoubleInput("Enter the price of the menu item: ", 0, 10000);
											
					cout << endl << tempName << endl << tempPrice << endl;
					choice = IntInput("<0> Save item\n<1> Discard\n", 0, 1);
					
					if(choice == 0)
					{
						menuItemType temp(tempName, tempPrice, 0);
						menu.push_back(temp);
						cout << "Saved.\n";
					}
					break;
					}
					else
					{
						cout << "Menu is full.\n";
						break;
					}
			default: tempName = "n/a";
					break;
		}; //end switch 
		
		cleanMenus();
	}while(choice != 0);
	
}

void restaurantType::appendNewDist(double d)
{
	map.appendDist(d);
}


void restaurantType::setName(string n) 
{
	name = n;
}

double restaurantType::getRevenue() const
{
	return revenue;
}

string restaurantType::getName() const
{
	return name;
}

int restaurantType::getCode() const
{
	return restaurantNum;
}

double restaurantType::getDistToSC() 
{
	return map.getDistToSC();
}

void restaurantType::cleanMenus()
{
	vector<menuItemType>::iterator it = menu.begin();
	
	while(it != menu.end())
	{
		if((*it).getName() == "")
			menu.erase(it);
		
		++it;
	}
	
	menu.shrink_to_fit();
}

void tripping(cartType &resty, vector<cartType *> &pool, queue <cartType *> &trip, int n)
{
	cartType *temp = new cartType;
	*temp = resty;
	trip.push(temp);

	if(n == 0)
		return;

	distPair lowest = resty.map.distanceList[0];
	
	int i;
	for(i = 1; i < pool.size(); i++)
	{
		if(resty.map.distanceList[i].value < lowest.value && resty.map.distanceList[i].value != 0 && resty.map.distanceList[i].value )
			lowest = resty.map.distanceList[i];
	}
	distanceType::totalDist += lowest.value;
	pool.erase(pool.begin() + (lowest.code - 1));
	tripping(*pool[lowest.code], pool, trip, (n - 1));
}

ofstream& operator<<(ofstream& os, cartType& resty)
{
	resty.cleanMenus();
	distPair *temp;
	
	os << "Name of Fast Food restaurant: " << resty.name << endl;
	os << "Fast Food restaurant number "   << resty.restaurantNum << endl;
	os << "Distance (miles) to other Fast Food restaurants - " << resty.map.numRestaurants << endl;
	
	for(int i = 1; i <= resty.map.numRestaurants; i++)
	{
		os << resty.map.distanceList[i].code << ' ' << resty.map.distanceList[i].value << endl;
	}
	
	os << resty.map.distToSC << " miles to Saddleback College " << endl;
	os << resty.menu.size()  << " menu items" << endl;
	
	for(int i = 0; i < resty.menu.size(); i++)
	{
		os << resty.menu[i].name  << endl;
		os << resty.menu[i].price << endl;
	}
	
	os << endl;
	
	return os;
}

ifstream& operator>>(ifstream& is, cartType& resty)
{
	

	distPair tempP;
	menuItemType tempM;
	int tempI = 0;
	string tempS;
	double tempD = 0;
	int hash = 0;
	
	if(!is.eof())
	{
		is.ignore(100, ':');
		getline(is, tempS);
		if(tempS.find_first_of(' ') == 0)
			tempS = tempS.substr(1, tempS.length());
		resty.name = tempS;
		is.ignore(100, 'b');
		is.ignore(100, ' ');
		is >> tempI;
		resty.restaurantNum = tempI;
		
		is.ignore(100, '\n');
		is.ignore(100, '-');
		is >> tempI;
		resty.map.numRestaurants = tempI;
		is.ignore(100, '\n');
		
		
		//linkedListIterator <distPair> it = resty.map.distanceList.begin();
		
		for(int i = 0; i < resty.map.numRestaurants; i++)
		{
			is >> tempP.code >> tempP.value; 
			resty.map.distanceList[tempP.code] = tempP;
		}
		is.ignore(100, '\n');
		is >> tempD;
		resty.map.distToSC = tempD;
		is.ignore(100, '\n');
		
		is >> tempI;
		is.ignore(100, '\n');
		
		for(int i = 0; i < tempI; i++)
		{
			getline(is, tempM.name);
			is >> tempM.price;
			is.ignore(100, '\n');
			resty.menu.push_back(tempM);
		}
		is.ignore(100, '\n');
		//is.ignore(100, '\n');
	}
	
	//delete tempP;
	return is;
}


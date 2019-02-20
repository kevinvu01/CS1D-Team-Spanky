#include "restaurantType.h"

restaurantType::restaurantType()
				:cart()
				:map() 
				:menu()
{
	name          = "Empty";
	revenue       = 0;
	restaurantNum = 0;
}

restaurantType::restaurantType(const list<menuItemType> & ml, const distanceType& dm, const cartType& c, int restCode, string n, double rev)
				:cart(c)
				:map(dm) 
				:menu(ml)
{
	name          = n;
	revenue       = rev;
	restaurantNum = restCode;
}

restaurantType::~restaurantType()
{
	menu.clear();
} 

const restaurantType& restaurantType::copy(const restaurantType&other)
{
	restaurantType temp;
	temp.name          = other.name;
	temp.restaurantNum = other.restaurantNum;
	temp.revenue       = other.revenue;
	
	temp.menu = other.menu;
	temp.cart = other.cart;
	temp.map  = other.map;
	
	return temp;
}
	
void restaurantType::printMenu()
{
	int i = 1;
	
	cout << name << endl
		 << "Food Menu\n";
		 
	for(list<menuItemType>::iterator it = menu.begin(); it != menu.end())
	{
		cout << '<' << i << "> ";
		it->print();
		i++;
	}
}

void restaurantType::printCart()
{
	cout << name << endl;
	cart.printContents();
	cout << setprecision(2) << fixed 
		 << "Total: $" << cart.getTotal() << endl;
}

void restaurantType::updateInfo()
{
	int choice = 0;
	int choice2 = 0;	
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
						cout << "<0> Done\n";
						printMenu();
						
						choice2   = IntInput("Choose which menu item to alter the price of: ", 0, menu.size());
						tempPrice = DoubleInput("New Price: ", 0, 10000);
						
						menu[choice2 - 1].changePrice(tempPrice);
					}while(choice2 != 0);
					break;
			case 3: do{
						cout << "<0> Done\n"; 
						printMenu();
						
						choice2 = IntInput("Choose which menu item to wish to exterminate: ", 0, menu.size());
												
						menu[choice2 - 1].erase();
						cout << "Erased.\n";
					}while(choice2 != 0);
					break;
			case 4: string tempName = "";
					choice = 0;
					cout << "Enter name of the menu item: ";
					getline(cin, tempName);
											
					tempPrice = DoubleInput("Enter the price of the menu item: ", 0, 10000);
											
					cout << endl << tempName << endl << tempPrice << endl;
					choice = IntInput("<0> Save item\n<1> Discard\n", 0, 1);
					
					if(choice == 0)
					{
						menuItemType temp(tempName, tempPrice);
						menu.push_back(temp);
						cout << "Saved.\n";
					}
					break;
			default: break;
		}; //end switch 
	}while(choice != 0);
}

void restaurantType::updateRenevue()
{
	renenue += cart.getTotal();
}

void restaurantType::setName(string n)
{
	name = n;
}

double restaurantType::getRenevue()
{
	return revenue;
}

string restaurantType::getName()
{
	return name;
}

double restaurantType::getDistToSC()
{
	return map.getDistToSC();
}

//optional manual add
void AddRestaurant()
{
	string tempName;
}

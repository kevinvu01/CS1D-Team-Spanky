#include "cartType.h"

cartType::cartType()
		: cart()
{
	total = 0;
}

cartType::cartType(vector <menuItemType> c, double tot)
		: cart(c)
{
	total = tot;
}

const cartType& cartType::operator=(const cartType& other)
{
	total = other.total;
	cart = other.cart;
	
	return *this;
}

void cartType::printContents()
{
	cout << "Your cart:\n";
	
	for(int i = 1; i <= cart.size(); i++)
	{
		cout << "<" << i << "> ";
		cart[i].print();
	}
}
	
void cartType::selectionMenu()
{
	int choice = 0;
	
	do{
		cout << "<0> Back\n";
		printContents();
		cout << "<" << cart.size() << "> Checkout\n";
		
		choice = IntInput("Choose whch to delete: ", 0, cart.size());
		
		if(choice > 0 && choice != cart.aize())
			cart.erase(choice);
		else if(choice == cart.size())
			checkout();
		else 
			return;
	}while(choice != 0);
}

void cartType::checkout()
{
	int choice = 0;
	
	for(vector<menuItemType>::iterator it = cart.begin(); it != cart.end(); ++it)
		total += it->getPrice();
	
	cout << "Checkout\n";
	cout << "Your total is: " << total;
	cout << "<0> Purchase\n"
		 << "<1> Back\n- ";
		
	choice = IntInput("", 0, 1);
	if(choice == 0)
	{
		updateRevenue();
		total = 0;
		cout << "Your order has been placed.\n";
	}
	else 
		cout << "Discarded.\n";
}

double cartType::getTotal()
{
	return total;
}

//input error checking function
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

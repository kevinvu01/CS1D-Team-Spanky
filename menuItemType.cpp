#include "menuItemType.h"
	
menuItemType::menuItemType()
{
	name  = "";
	price = 0;
	qty	  = 0;
}
menuItemType::menuItemType(string n, double p, int q)
{
	name  = n;
	price = p;
	qty   = q;
}

menuItemType::menuItemType(const menuItemType & other)
{
	name  = other.name;
	price = other.price;
	qty	  = other.qty;
}
 
const menuItemType& menuItemType::operator=(const menuItemType& other)
{
	if(this != &other)
	{
		name  = other.name;
		price = other.price;
		qty	  = other.qty;
	}
	
	return *this;
}

bool menuItemType::operator==(const menuItemType& other)
{
	bool equal = false;
	
	if(name == other.name)
		equal = true;
	
	return equal;
}

bool menuItemType::operator!=(const menuItemType& other)
{
	bool unequal = false;
	
	if(name != other.name)
		unequal = true;
	
	return unequal;
}

double menuItemType::getPrice()
{
	return price;
}

int menuItemType::getQty()
{
	return qty;
}

string menuItemType::getName()
{
	return name;
}

void menuItemType::print()
{
	const short COL = 20;
	
	cout << setprecision(2)   << fixed;
	cout << left << setw(COL) << name << "$" << price << endl;
	cout.unsetf(ios::fixed);
}

void menuItemType::changePrice(double newPrice)
{
	price = newPrice;
}

void menuItemType::setQty(int x)
{
	qty = x;
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

#include "menuItemType.h"
	
menuItemType::menuItemType()
{
	name = "";
	price = 0;
}
menuItemType::menuItemType(string n, double p)
{
	name = n;
	price = p;
}

menuItemType::menuItemType(const menuItemType & other)
{
	name = other.name;
	price = other.price;
}
 
const menuItemType& menuItemType::operator=(const menuItemType& other)
{
	if(this != &other)
	{
		name = other.name;
		price = other.price;
	}
	
	return *this;
}

void menuItemType::print()
{
	const short COL = 20;
	
	cout << setprecision(2) << fixed;
	cout << left << setw(COL) << name << "$" << price << endl;
	cout.unsetf(ios::fixed);
}

void menuItemType::changePrice(double newPrice)
{
	price = newPrice;
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

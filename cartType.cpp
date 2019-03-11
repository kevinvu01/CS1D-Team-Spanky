#include "cartType.h"

cartType::cartType()
		: restaurantType()
{
	total = 0;
}

cartType::cartType(vector <menuItemType> c, const distanceType& d, const vector<menuItemType> & m, int restCode, string name, double rev, double tot)
		: restaurantType(c, d, m, restCode, name, rev)
{
	total = tot;
}

const cartType& cartType::operator=(const cartType& other)
{
	menu = other.menu;
	cart = other.cart;
	map  = other.map;
	name = other.name;
	restaurantNum = other.restaurantNum;
	revenue = other.revenue;
	total = other.total;
	
	return *this;
}

cartType::cartType(const cartType& other)
		: restaurantType(other)
{
	total = other.total;
}
	
	
void cartType::updateRevenue()
{
	revenue += total;
}

void cartType::printCart()
{
	cout << name << endl;
	cout << "Your cart:\n";
	
	for(int i = 1; i <= cart.size(); i++)
	{
		cout << "<" << i << "> ";
		cart[i - 1].print();
	}

	cout << setprecision(2) << fixed 
		 << "Total: $" << total << endl;
}

void cartType::selectionMenu()
{
	int choice = 0;
	vector<menuItemType>::iterator it = cart.begin();
	
	do{
		printCart();
		cout << "<" << cart.size() << "> Checkout\n";
		cout << "<0> Back\n";
		
		choice = IntInput("Choose which to delete: ", 0, cart.size());
		
		if(choice > 0 && choice != cart.size())
		{
			it = cart.begin();
			while(!(*it == menu[choice - 1]))
				++it;

			cart.erase(it);
		}
		if(choice == cart.size())
			checkout();
	}while(choice != 0);
}

void cartType::addToCart()
{
	int choice = 0;
	int qty    = 0;
	menuItemType temp;
	vector<menuItemType>::iterator it = menu.begin();
	
	do{
		printMenu();
		cout << "<" << menu.size() + 1 << "> View Cart\n";
		cout << "<" << menu.size() + 2 << "> Delete Items in Cart\n";

		cout << "<0> Back\n";

		choice = IntInput("Chooce which item to add to your cart: ", 0, menu.size() + 2);
		
		if(choice < menu.size() && choice != 0)
			qty = IntInput("Enter quantity: ", 1, 100);
		
		if(choice > 0 && choice != menu.size() + 1)
		{			
			cart.push_back(menu[choice - 1]);
		}
		if(choice == menu.size() + 1)
			checkout();
		if(choice == menu.size() + 2)
		{
			choice = IntInput("Choose which item to delete: ", 1, menu.size());
			it = cart.begin();
			while(!(*it == menu[choice - 1]) && it != cart.end())
				++it;

			cart.erase(it);
		}
	}while(choice != 0);
}

void cartType::checkout()
{
	int choice = 0;
	
	for(int i = 0; i < cart.size(); i++)
		total += cart[i].getPrice() * cart[i].getQty();
	
	cout << "Checkout\n";
	printCart();
	cout << "Your total is: " << total << endl ;
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


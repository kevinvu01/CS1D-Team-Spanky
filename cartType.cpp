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
	total   = other.total;
	
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
	
	for(int i = 0; i < cart.size(); i++)
	{
		cout << "Qty: " << cart[i].getQty() << " : ";
		cart[i].print();
	}

	cout << setprecision(2) << fixed 
		 << "Subtotal: $"   << total << endl;
}

/*
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
*/

void cartType::addToCart()
{
	int choice = 0;
	int qty    = 0;
	menuItemType *temp;
	vector<menuItemType>::iterator it = menu.begin();
	
	do{
		printMenu();
		cout << "<" << menu.size() 	   << "> Checkout\n";
		cout << "<" << menu.size() + 1 << "> View Cart\n";
		cout << "<" << menu.size() + 2 << "> Next Restaurant\n";


		choice = IntInput("Chooce which item to add to your cart: ", 0, menu.size() + 2);
		
		if(choice < menu.size())
		{
			qty  = IntInput("Enter quantity: ", 1, 100);
			temp = new menuItemType(menu[choice].getName(), menu[choice].getPrice(), qty);
			cart.push_back(*temp);
			total += qty * menu[choice].getPrice();
		}
		
		if(choice == menu.size())		
			checkout();
		if(choice == menu.size() + 1)
			printCart();
	}while(choice != menu.size() + 2);
	cout << "DONE" << getName() << endl;
}

/*		if(choice == menu.size() + 2)
		{
			choice = IntInput("Choose which item to delete: ", 1, menu.size());
			it = cart.begin();
			while(!(*it == menu[choice - 1]) && it != cart.end())
				++it;

			cart.erase(it);
		}
*/

void cartType::checkout()
{
	int choice = 0;
	
	cout << "Checkout\n";
	printCart();
	cout << "Your total is: " << total << endl ;
	cout << "<0> Purchase\n"
		 << "<1> Discard\n";
		
	choice = IntInput("Your choice: ", 0, 1);
	if(choice == 0)
	{
		updateRevenue();
		total = 0;
		cout << "Your order has been placed.\n";
	}
	else 
	{
		for(int i = 0; i < cart.size(); i++)
			cart.erase(cart.begin());
		
		cout << "Discarded.\n";
	}
}

double cartType::getTotal()
{
	return total;
}


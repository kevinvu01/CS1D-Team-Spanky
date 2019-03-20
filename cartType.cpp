#include "cartType.h"

cartType::cartType()
		: restaurantType()
{
	total = 0;
}

cartType::cartType(vector <menuItemType> m, const distanceType& d, const vector<menuItemType> & c, int restCode, string name, double rev, double tot)
		: restaurantType(m, d, c, restCode, name, rev)
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

void cartType::checkout()
{
	int choice = 0;
	
	cout << "Checkout\n";
	printCart();
	total += total * .06;
	cout << setprecision(2) << fixed;
	cout << "Your total is: $" << total << endl ;
	cout << "<0> Purchase\n"
		 << "<1> Discard\n";
		
	choice = IntInput("Your choice: ", 0, 1);
	if(choice == 0)
	{
		updateRevenue();
		total = 0;
		cart.erase(cart.begin(), cart.end());
		cout << "Your order has been placed.\n";
	}
	else 
	{
		cart.erase(cart.begin(), cart.end());
		total = 0;
		cout << "Discarded.\n";
	}
}

double cartType::getTotal()
{
	return total;
}


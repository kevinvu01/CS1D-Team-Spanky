#include "cartType.h"

using namespace std;

int main()
{
	string tempS, tempN;
	
	cout << "Enter the name of the restaurant: ";
	getline(cin, tempN);
	
	double tempD;
	menuItemType *tempM;
	
	restaurantType default1;
	vector<menuItemType> menu(4);
	for(int i = 0; i < 4; i++)
	{
		cout << "Enter name of menu item: ";
		getline(cin, tempS);
		cout << "Enter price: $";
		cin  >> tempD;
		cin.ignore(2000, '\n');
		tempM = new menuItemType(tempS, tempD);
		menu.push_back(*tempM);
	}
	
	int tempI = 0;
	distPair *tempP;
	orderedLinkedList<distPair> map;
	
	for(int i = 0; i < 8; i++)
	{
		tempP = new distPair;
		cout << "Enter the restaurant number and distance to said restaurant\n    # ";
		cin  >> tempP->code;
		cout << "dist: ";
		cin  >> tempP->value;
		cin.ignore(1000, '\n');
		
		map.insert(*tempP);
	}
		
	cout << "Enter distance to Saddleback: ";
	cin  >> tempD;
	cin.ignore(1000, '\n');
	
	distanceType tempDistType(map, 8, tempD);
	vector<menuItemType> cart(4);

	cartType MCD(menu, tempDistType, cart, 1, tempN, 0, 10);
	
	MCD.getName();
	cout << "MENU\n";
	MCD.printMenu();
	cout << "selMenu:\n";
	MCD.selectionMenu();
	cout << "Cart\n";
	MCD.printCart();
	cout << "rev\n";
	MCD.getRevenue();
	cout << "update info\n";
	MCD.updateInfo();
	
	return 0;
}
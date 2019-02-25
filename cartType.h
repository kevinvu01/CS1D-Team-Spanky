
#ifndef H_CARTTYPE
#define H_CARTTYPE

#include "menuItemType.h"
#include "restaurantType.h"
#include <iostream>  
#include <iomanip>
#include <string>

using namespace std;

class cartType: public restaurantType
{
	using restaurantType::cart;
	using restaurantType::revenue;
public: 
  cartType();
  cartType(vector <menuItemType>, const distanceType&, const vector<menuItemType> &, int restCode, string name, double rev, double tot);
  
  const cartType& operator=(const cartType &);
  
  double getTotal();
  
  //printCart - prints the items of the cart with numbers
  //Postcondition - outputs to screen the cart with heading and numbers
  void printCart();
  
  void selectionMenu();
  void checkout();
  void updateRevenue();
private:
  double total;
};

int IntInput(string inMsg,    //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed

#endif

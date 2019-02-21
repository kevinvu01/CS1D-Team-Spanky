
#ifndef H_cartType
#define H_cartType

#include "menuItemType.h"
#include "restaurantType.h"
#include <iostream>  
#include <iomanip>
#include <string>


using namespace std;

class cartType: public restaurantType
{
	using restaurantType::cart;
public: 
  cartType();
  cartType(vector <menuItemType>, double);
  
  const cartType& operator=(const cartType &);
  
  double getTotal();
  void printContents();
  void selectionMenu(const restaurantType &);
  void checkout(const restaurantType &);
  
private:
  double total;
};

int IntInput(string inMsg,    //menu prompt
	const int MIN, //minimum value allowed
	const int MAX) //maximum value allowed

#endif


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
	//friend void tripping(cartType &resty, vector<cartType *> &pool, queue <cartType *> &trip, int n);
	using restaurantType::cart;
	using restaurantType::revenue;
public: 
  //default constructor
  cartType();
  
  //copy constructor
  cartType(const cartType&);
  
  //specific constructor to set all restaurantType variables and data structures and the cart total
  cartType(vector <menuItemType>, const distanceType&, const vector<menuItemType> &, int restCode, string name, double rev, double tot);
  
  //overloaded  assignment operator
  const cartType& operator=(const cartType &);
  
  //getter for the total
  double getTotal();
  
  //printCart - prints the items of the cart with numbers
  //Postcondition - outputs to screen the cart with heading and numbers
  void printCart();
    
  //checkout
  //description - takes in the cart and calculates the total, updates the renevue, and returns, or returns with no changes
  //preconditions - cart should have items in it
  //postconditions - the revenue is updated if purchase is complete
  void checkout();
  
  //addToCart
  //description: displays the full menu list of the restaurant and adds a user defined qty of that item to the cart, return, or view cart
  //preconditions: data for restaurant needs to be populated. ONly adds to that restaurants cart <during a trip>
  //postconditions: cart is updated and user either exits by going to the cart view or returns to previous menu
  void addToCart();
private:
  void updateRevenue(); //adds the total of the cart to the total revenue of the restaurant
  double total;
};


#endif

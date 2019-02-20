//TEAM SPANKY - PROJECT 01 - RESTAURANTTYPE HEADER FILE

//NOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTEDNOT TESTED
#ifndef H_RESTAURANTTYPE
#define H_RESTAURANTTYPE

#include "distanceType.h"
#include "menuItemType.h"
#include "cartType.h"
#include <list>
#include <iostream>
#include <string>

using namespace std;

class restaurantType{
	//overloaded file stream insertion operator used for saving to the data file upon program termination
	//Postcondition: prints out the restaurant data in same format is was uploaded
	friend ofstream& operator<<(ofstream&, const restaurantType&); 
	
	//overloaded file stream extraction operator used for reading from the data file upon program execution
	//Postcondition: reads in the restaurant data in format given in the project file from canvas
	friend ifstream& operator>>(ifstream&, restaurantType&); 
	
public: 
  //default constructor
  restaurantType();
  
  //constructor setting all members to the parameters using the member initialization list and three primitive parameters
  restaurantType(const list<menuItemType> &, const distanceType&, const cartType&, int restCode, string name, double rev);
  
  //copy constructor
  restaurantType(const restaurantType&);
  
  //destructor
  ~restaurantType();
    
  //printMenu - prints the items of the menu with numbers
  //Postcondition - outputs to screen the menu with heading
  void printMenu() const;
  
  //printCart - prints the items of the cart with numbers
  //Postcondition - outputs to screen the cart with heading and numbers
  void printCart() const;
  
  //getDistToSC - returns the distance to saddlebcak as lone distance
  double getDistToSC() const;
  
  //getName - returns the name of the restaurant
  string getName() const;
  
  //getRevenue - returns the total rnevue of the restaurant
  double getRevenue() const;
  
  //setName - sets the name ofthe restaurant to the parameter
  void setName(string);
  
  //updateInfo - provides the ability to select different aspects of the
  //			 restaurant and modify it
  //Postconditions: returns nothing but can modify through user input 
  //				the name of the restaurant, the price of menu item,
  //				add a menu item to the LL, and/or delete a menu item
  void updateInfo();
  
  //updateRevenue - adds the custumers cart total to the total renevue
  //Preconditions: MUST only be called after a purchase is complete on a trip
  //Postconditions: the current total in the cart is added to the revenue
  void updateRevenue();
  
private:
  list <menuItemType> menu;   //LL of menu items
  distanceType map;			  //object that contains an ordered linked list of distance/restaurantNumber
							  //    pairs and a static running total of distance for a trip
  cartType     cart;		  //object that contains a vector of menuItems 
  int          restaurantNum; //the code for which restaurant it is(used for computing distances)
  string       name;		  //name of restaurant
  double       revenue;		  //total renevue of the restaurant
  
  //deep copy function
  const restaurantType& copy(const restaurantType &other);
};

//optional manual add function  
void AddRestaurant();

#endif

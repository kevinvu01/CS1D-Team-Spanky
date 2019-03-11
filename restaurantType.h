//TEAM SPANKY - PROJECT 01 - RESTAURANTTYPE HEADER FILE

#ifndef H_RESTAURANTTYPE
#define H_RESTAURANTTYPE

#include "distanceType.h"
#include "menuItemType.h"
//#include "cartType.h"
#include <vector>
#include <queue>
#include <list>
#include <iostream>
#include <string>

using namespace std;
class cartType;
class restaurantType{
	//overloaded file stream insertion operator used for saving to the data file upon program termination
	//Postcondition: prints out the restaurant data in same format is was uploaded
	friend ofstream& operator<<(ofstream&, cartType&); 
	
	//overloaded file stream extraction operator used for reading from the data file upon program execution
	//Postcondition: reads in the restaurant data in format given in the project file from canvas
	friend ifstream& operator>>(ifstream&, cartType&); 
	
	friend void tripping(cartType &resty, vector <cartType *> &pool, queue <cartType *> trip, int n);

public: 
  //default constructor
  restaurantType();
  
  //constructor setting all members to the parameters using the member initialization list and three primitive parameters
  restaurantType(const vector<menuItemType> &, const distanceType&, const vector<menuItemType> &, int restCode, string name, double rev);
  
  //copy constructor
  restaurantType(const restaurantType&);
  
  //destructor
  ~restaurantType();
  
  //overloaded assignment operator
  const restaurantType& operator=(const restaurantType &);
    
  //printMenu - prints the items of the menu with numbers
  //Postcondition - outputs to screen the menu with heading
  void printMenu();
  
  //getDistToSC - returns the distance to saddlebcak as lone distance
  double getDistToSC();
  
  //getName - returns the name of the restaurant and its number respectively
  string getName() const;
  int    getCode() const;
  
  //getRevenue - returns the total rnevue of the restaurant
  double getRevenue() const;
  
  //setName - sets the name ofthe restaurant to the parameter
  void setName(string);
  	
	// recursive function to p3.	Provide the capability to visit the initial 10 fast food restaurants starting at Saddleback
 // void tripping(cartType &resty, vector <cartType *> &pool, queue <cartType *> trip, int n);

  //updateInfo - provides the ability to select different aspects of the
  //			 restaurant and modify it
  //Postconditions: returns nothing but can modify through user input 
  //				the name of the restaurant, the price of menu item,
  //				add a menu item to the LL, and/or delete a menu item
  void updateInfo();
protected:
  vector <menuItemType> menu; //vector of menu items
  vector <menuItemType> cart; //vector that contains menuItems 
  distanceType map;			  //object that contains an ordered linked list of distance/restaurantNumber
							  //    pairs and a static running total of distance for a trip
  int          restaurantNum; //the code for which restaurant it is(used for computing distances)
  string       name;		  //name of restaurant
  double       revenue;		  //total renevue of the restaurant
  //int 		   dominosNum;
  
  //deep copy function
  restaurantType& copy(const restaurantType &other);  
  
  //helper to clean the vector menu of empty nodes
  void cleanMenus();
};

//optional manual add function  
void AddRestaurant();
#endif

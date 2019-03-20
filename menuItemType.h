#ifndef H_menuItemType
#define H_menuItemType

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class cartType;

class menuItemType
{
	//overloaded file stream insertion operator used for saving to the data file upon program termination
	//Postcondition: prints out the restaurant data in same format is was uploaded
	friend ofstream& operator<<(ofstream&, cartType&); 
	
	//overloaded file stream extraction operator used for reading from the data file upon program execution
	//Postcondition: reads in the restaurant data in format given in the project file from canvas
	friend ifstream& operator>>(ifstream&, cartType&); 
public: 
  //default constructor
  menuItemType();
  
  //constructor for name and price
  menuItemType(string, double, int);
  
  //copy constructor
  menuItemType(const menuItemType &);
  
  //overloaded assigment operator
  const menuItemType& operator=(const menuItemType& other);
  
  //overloaded equality operators based upon name
  bool operator==(const menuItemType& other);
  bool operator!=(const menuItemType& other);

  //changePrice - setter
  //precondition: parameter (the new price) should be positive
  //postcondition: price is changed to the new price
  void changePrice(double);
  void setQty(int);
  
  //print
  //postcondition: the menu item is printed to screen as its name followed by $ price 
  void print();
  
  //getter to return the price and quantity
  double getPrice();
  int	 getQty();
  string getName();
private:
  string name;
  double price;
  int 	 qty;
};

//input validators
int IntInput(string inMsg,    //menu prompt
	const int MIN, //minimum value allowed
	const int MAX); //maximum value allowed
double DoubleInput(string inMsg,  //menu prompt
	const int MIN, //minimum value allowed
	const int MAX); //maximum value allowed

#endif

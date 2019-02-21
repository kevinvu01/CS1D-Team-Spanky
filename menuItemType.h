#ifndef H_menuItemType
#define H_menuItemType

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class menuItemType{
public: 
  menuItemType();
  menuItemType(string, double);
  menuItemType(const menuItemType &);
  
  const menuItemType& operator=(const menuItemType& other);
  
  void changePrice(double);
  void print();
private:
  string name;
  double price;
};

//input validators
int IntInput(string inMsg,    //menu prompt
	const int MIN, //minimum value allowed
	const int MAX); //maximum value allowed
double DoubleInput(string inMsg,  //menu prompt
	const int MIN, //minimum value allowed
	const int MAX); //maximum value allowed

#endif

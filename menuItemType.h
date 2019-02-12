#ifndef H_menuItemType
#define H_menuItemType

#include <iostream>
#include <string>

using namespace std;

class menuItemType{
public: 
  menuItemType();
  menuItemType(const menuItemType &);
  
  void print();
private:
  string name;
  double price;
};


#endif

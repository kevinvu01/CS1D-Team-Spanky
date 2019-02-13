#ifndef H_cartType
#define H_cartType

#include "menuItemType.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cartType{
public: 
  void printContents();
  void selectionMenu();
private:
  double total;
  vector <menuItemType> cart;
};


#endif

#ifndef H_RESTAURANTTYPE
#define H_RESTAURANTTYPE

#include "DLinkedList.h"
#include <iostream>

#include <string>

using namespace std;

class restaurantType{
public: 
  restaurantType();
  void save();
  void inFile();
  void printMenu();
  double getDistance();
  string getName();
  void printCart();
private:
  DLinkedList <MenuItemType> menu;
  DistanceType map;
  CartType cart;
};


#endif

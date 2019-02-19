#include "menuItemType.h"

menuItemType::menuItemType(){

}

menuItemType::menuItemType(menuItemType &) const{

}

void menuItemType::setName(string x){
name = x;
}

string menuItemType::getName(){
  return name;
}

void menuItemType:: print(){

}

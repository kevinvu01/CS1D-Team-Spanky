#ifndef H_tripType
#define H_tripType

#include <iostream>
using namespace std;


class tripType{
public: 
  void print();
  void setDistance(double distance);
  double getDistance();
  
  
private:
  double distance;
  

};



#endif

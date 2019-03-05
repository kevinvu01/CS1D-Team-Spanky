//TEAM SPANKY - PROJECT 01 - DISTANCETYPE HEADER FILE

#ifndef H_distanceType
#define H_distanceType

#include <iostream>
#include <string>
#include <fstream>
#include "orderedLinkedList.h"

using namespace std;
class cartType;
class restaurantType;
//each pair is the distance in miles to another restaurant and the restaurant's number/code
struct distPair
{
	int    code;
	double value;
	
	//default constructor
	distPair();
	
	//overloaded relational operators
	bool operator>=(const distPair& other);
	bool operator!=(const distPair& other);
	bool operator==(const distPair& other);

};

class distanceType
{
	//overloaded file stream insertion operator used for saving to the data file upon program termination
	//Postcondition: prints out the restaurant data in same format is was uploaded
	friend ofstream& operator<<(ofstream&, cartType&); 
	//overloaded file stream extraction operator used for reading from the data file upon program execution
	//Postcondition: reads in the restaurant data in format given in the project file from canvas
	friend ifstream& operator>>(ifstream&, cartType&); 

public:  
	//default constructor
	distanceType();
	
	//manual constructor 
	distanceType(const orderedLinkedList<distPair> &, int numberOfRestaurants, double distanceToSaddleback);
	
	//copy constructor
	distanceType(const distanceType&);
	
	//destructor
	~distanceType();
	
	//overloaded assignment operator
	const distanceType& operator=(const distanceType& other);
	
	//overloaded relational operators
	bool operator>=(const distanceType& other);
	bool operator!=(const distanceType& other);
	bool operator==(const distanceType& other);
	
	//basic setter and getter
	void   setDistToSC(double);
	double getDistToSC();
	
	//returns the total distance
	void printTotalDist();
		
	//public static (global variable for all dstanceTypes) to keep running total for trip distance
	static double totalDist;
private:
	orderedLinkedList <distPair> distanceList; 
	int numRestaurants;
	double distToSC;
};


#endif

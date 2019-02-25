#include "distanceType.h"

//DISTANCEPAIR CONSTRUCTOR and things
distPair::distPair()
{
	code = 0;
	value = 0;
}

bool distPair::operator>=(const distPair& other)
{
	bool greater = false;
	
	if(value >= other.value)
		greater = true;
	
	return greater;
}

bool distPair::operator!=(const distPair& other)
{
	bool inequality = false;
	
	if(value != other.value)
		inequality = true;
	
	return inequality;
}

bool distPair::operator==(const distPair& other)
{
	bool equality = false;
	
	if(value == other.value)
		equality = true;
	
	return equality;
}

//static initialization...oofda
double distanceType::totalDist = 0;


//DISTANCETYPE MEMBER FUNCTIONS>>>


distanceType::distanceType()
			:distanceList()
{
	numRestaurants = 12;
	distToSC       = 0;
}

distanceType::distanceType(const orderedLinkedList<distPair> &other, int num, double d)
			:distanceList(other)
{
	numRestaurants = num;
	distToSC       = d;
}
	
distanceType::distanceType(const distanceType& other)
			: distanceList(other.distanceList)
{
	numRestaurants = other.numRestaurants;
	distToSC = other.distToSC;
	//distanceList = other.distanceList;
}

distanceType::~distanceType()
{
	distanceList.destroyList();
}

const distanceType& distanceType::operator=(const distanceType& other)
{
	numRestaurants = other.numRestaurants;
	distToSC       = other.distToSC;
	distanceList   = other.distanceList;
}

	
double distanceType::getDistToSC()
{
	return distToSC;
}

void distanceType::setDistToSC(double newDist)
{
	distToSC = newDist;
}

void distanceType::printTotalDist()
{
	cout << "Total Distance: " << totalDist << endl;
}

void distanceType::save()
{
	ofstream fout;
	fout.open("data.txt\0");
	
	//fout << stuff
	
	fout.close();
}


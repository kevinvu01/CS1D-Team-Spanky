#include "distanceType.h"


//DISTANCEPAIR CONSTRUCTOR and things
distPair::distPair()
{
	code  = 0;
	value = 0;
}

distPair::distPair(int c, double v)
{
	code  = c;
	value = v;
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
	//distanceList   = {{0, 0}};
	numRestaurants = 12;
	distToSC       = 0;
}

distanceType::distanceType(distPair other[], int num, double d)
{
	for(int i = 0; i < NUM_RESTAURANTS; i++)
		distanceList[i]   = other[i];
	numRestaurants = num;
	distToSC       = d;
}
	
distanceType::distanceType(const distanceType& other)
{
	for(int i = 0; i < NUM_RESTAURANTS; i++)
		distanceList[i]   = other.distanceList[i];
	numRestaurants = other.numRestaurants;
	distToSC       = other.distToSC;
}

/*
distanceType::~distanceType()
{
	distanceList.destroyList();
}
*/
const distanceType& distanceType::operator=(const distanceType& other)
{
	numRestaurants = other.numRestaurants;
	distToSC       = other.distToSC;
	for(int i = 0; i < NUM_RESTAURANTS; i++)
		distanceList[i]   = other.distanceList[i];
}

void distanceType::appendDist(double d)
{
	distanceList[numRestaurants].code = numRestaurants + 1;
	distanceList[numRestaurants].value = d;
	numRestaurants++;
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



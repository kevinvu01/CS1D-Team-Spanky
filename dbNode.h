#ifndef H_Node
#define H_Node  
 
#include <iostream>
#include <cassert>

using namespace std; 

//Definition of the node

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *next;
	nodeType<Type> *back;
};

#endif
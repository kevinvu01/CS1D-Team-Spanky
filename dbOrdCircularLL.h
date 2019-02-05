#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H  
 
#include <iostream>
#include <cassert>

using namespace std; 

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *next;
	nodeType<Type> *back;
};

template <class Type>
class CLLiterator
{
public:
   CLLiterator();
     //Default constructor
     //Postcondition: current = nullptr;

   CLLiterator(nodeType<Type> *ptr);
     //Constructor with a parameter.
     //Postcondition: current = ptr;

   Type operator*();
     //Function to overload the dereferencing operator *.
     //Postcondition: Returns the info contained in the node.

   CLLiterator<Type> operator++();    
     //Overload the pre-increment operator.
     //Postcondition: The iterator is advanced to the next 
     //               node.
	 
	CLLiterator<Type> operator--();    
     //Overload the pre-decrement operator.
     //Postcondition: The iterator is taken to the previous 
     //               node.

   bool operator==(const CLLiterator<Type>& right) const; 
     //Overload the equality operator.
     //Postcondition: Returns true if this iterator is equal to 
     //               the iterator specified by right, 
     //               otherwise it returns the value false.

   bool operator!=(const CLLiterator<Type>& right) const; 
     //Overload the not equal to operator.
     //Postcondition: Returns true if this iterator is not  
     //               equal to the iterator specified by  
     //               right; otherwise it returns the value 
     //               false.

private:
   nodeType<Type> *current; //pointer to point to the current 
                            //node in the linked list
};

//*********************************************************************
// 					DEFINITIONS - CLLiterator
//*********************************************************************

template <class Type>
CLLiterator<Type>::CLLiterator()
{
    current = NULL;
}

template <class Type>
CLLiterator<Type>::CLLiterator(nodeType<Type> *ptr)
{
    current = ptr;
}

template <class Type>
Type CLLiterator<Type>::operator*()
{
    return current->info;
}

template <class Type>
CLLiterator<Type> CLLiterator<Type>::operator++()   
{
    current = current->next;

    return *this;
}

template <class Type>
CLLiterator<Type> CLLiterator<Type>::operator--()   
{
    current = current->back;

    return *this;
}
template <class Type>
bool CLLiterator<Type>::operator==
               (const CLLiterator<Type>& right) const
{
    return (current == right.current);
}

template <class Type>
bool CLLiterator<Type>::operator!=
                 (const CLLiterator<Type>& right) const
{    return (current != right.current);
}


template <class Type>
class dbOrdCircularLL
{	
public:
	//overloading the assignment operator
	const dbOrdCircularLL<Type>& operator=(const dbOrdCircularLL<Type> & circularLinkedList);

	//initializing the list
	//Postcondition: first->link = first;
	void initializeList();
	
	//function to see if list is empty
	//Postcondition: true is returned if list is empty, else false
	bool isEmpty();
	
	//function to destroy the list
	//Postcondition: first = NULL
	void destroy();
	
	//function to output the information contained in all nodes
	void print() const;
	
	//function to output the information contained in all nodes reverse
	void reversePrint() const;
	
	//function that inserts a node into the list, keeping it ordered
	//Postcondition: count is incremented and list is still ordered
	void insert(const <Type> &);
	
	//FUnction to return the number of nodes on the list
	int length() const;
	
	// Function to return an iterator at the beginning of list
	// Precondition: list must not be empty and the must exist
	// Postcondition: if the list is empty, prgram terminates, else	
	//				  the iterator is returned at start of list
	const CLLiterator<Type> & begin();
	
	// FUnction to search list for given item 
	// Postcondition: returns true if the item is in the list, otherwise false
	bool search(const Type&);
	
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing deleteItem
	// is deleted from the list; first points
	// to the first node of the new list, last
	// points to the first node of the new list,
	// and count is decremented by 1; otherwise
	// an appropriate message is printed.
	void deleteNode(const Type& deleteItem);
	
	//constructors:
	dbOrdCircularLL(); //default
	dbOrdCircularLL(const dbOrdCircularLL<Type>& other); //copy
	
	//destructor
	~dbOrdCircularLL(); 

protected:
	int count;
	nodeType<Type> *cursor;
	
private: 
	// function to make a copy of other
	// postcondition: A copy of other is createdd and assigned to this list
	void copyList(const dbOrdCircularLL<Type>& other);
};

//**************************************************************************
//							DEFINITIONS - dbOrdCircularLL
//**************************************************************************

//constructors
template <class Type>
dbOrdCircularLL<Type>::dbOrdCircularLL()
{
	cursor->next = cursor;
	cursor->back = cursor;
	count = 0;
}

template <class Type>
dbOrdCircularLL<Type>::dbOrdCircularLL(const dbOrdCircularLL<Type>& other)
{
	copyList(other);
}

//destructor
template <class Type>
dbOrdCircularLL<Type>::~dbOrdCircularLL()
{
	destroy();
}

template <class Type>
void dbOrdCircularLL<Type>::initializeList()
{
	destroy();
	
	cursor->next = cursor;
	cursor->back = cursor;
	count = 0;
}

template <class Type>
const dbOrdCircularLL<Type>& dbOrdCircularLL<Type>::operator=(const dbOrdCircularLL<Type>& other)
{
	if(this != &other)
		copyList(other);
	
	return *this;
}

template <class Type>
bool dbOrdCircularLL<Type>::isEmpty()
{
	bool empty = true;
	
	if(count != 0)
		empty = false;
	
	return empty;
}

template <class Type>
void dbOrdCircularLL<Type>::destroy()
{
	nodeType<Type> *temp;
	
	while(cursor->next != cursor)
	{
		temp = cursor;
		cursor = cursor->next;
		delete temp;
	}
	
	count = 0;
	cursor = NULL;
}

template <class Type>
void dbOrdCircularLL<Type>::print() const
{
	nodeType<Type> *current; //pointer to traverse the list
	
	current = cursor;
	
	for(int i = 0; i < count; i++)
	{
		cout << current->info << endl;
		current = current->next;
	}
}

template <class Type>
void dbOrdCircularLL<Type>::reversePrint() const
{
	nodeType<Type> *current; //pointer to traverse the list
	
	current = cursor->back;
	
	for(int i = 0; i < count; i++)
	{
		cout << current->info << endl;
		current = current->back;
	}
}

template <class Type>
void dbOrdCircularLL<Type>::insert(const <Type> & newItem) 
{
	nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode;  //pointer to create a node
	
	bool found;
	
	newNode = new nodeType<Type>; //create the node
    newNode->info = newItem;    //store newItem in the node
    newNode->next = NULL;		//set the link fields of the node
    newNode->back = NULL;       //to NULL
	
	if(cursor->next == cursor)
	{
		cursor = newNode;
		cursor->next = cursor;
		cursor->back = cursor;
		count = 1;
	}
	else
	{
		current = cursor;
		found = false;
		
		do{
			if(current->info >= newItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->next;
			}
		
		}while(!found && current != cursor);
		
		if(current == cursor)
		{
			newNode->next = cursor;
			newNode->back = cursor->back;
			cursor = newNode;
			count++;
		}
		else
		{
			trailCurrent->next = newNode;
			newNode->next = current;
			newNode->back = current->back;
			
			count++;
		}
	}
}

template <class Type>
void dbOrdCircularLL<Type>::delete(const <Type> & deleteItem) 
{
	nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (cursor->next == cursor) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = cursor;
        found = false;

        do{
			if(current->info >= newItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->next;
			}
		
		}while(!found && current != cursor);

        if (current == cursor)   //Case 4
            cout << "The item to be deleted is not in the " 
                 << "list." << endl;
        else
            if (current->info == deleteItem) //the item to be 
                                   //deleted is in the list
            {
                if (cursor == current)       //Case 2
                {
                    cursor = cursor->next;
/******************************************************************/
					if(cursor->next == cursor)
						destroy();
					
                    if (cursor->next == current)
					{
						cursor->next = cursor;
						cursor->back = cursor;
					}

                    delete current;
                }
                else                         //Case 3
                {
                    trailCurrent->next = current->next;

                    if (current == tail)
                        tail = trailCurrent;

                    delete current;
                }
                count--;
            }
            else                            //Case 4
                cout << "The item to be deleted is not in the "
                     << "list." << endl;
    }
}//end deleteNode
#endif
#ifndef H_StackType
#define H_StackType

#include <iostream>
#include "node.h"

using namespace std;

template<class Type>
class linkedStackType
{
public:
    const linkedStackType<Type>& operator=
                                (const linkedStackType<Type>&);
        //overload the assignment operator
    void initializeStack();
	  //Initialize the stack to an empty state.
	  //Post condition: Stack elements are removed; top = NULL
    bool isEmptyStack();
	  //Function returns true if the stack is empty;
	  //otherwise, it returns false
    bool isFullStack();
	  //Function returns true if the stack is full;
	  //otherwise, it returns false
    void push(const Type& newItem);
	  //Add the newItem to the stack.
	  //Pre condition: stack exists and is not full
	  //Post condition: stack is changed and the newItem
	  //     is added to the top of stack. top points to
 	  //     the updated stack
    void pop(Type& poppedElement);
	  //Remove the top element of the stack.
	  //Pre condition: Stack exists and is not empty
	  //Post condition: stack is changed and the top
	  //    element is removed from the stack. The top
  	  //    element of the stack is saved in poppedElement
    void destroyStack();
	  //Remove all elements of the stack, leaving the
  	  //stack in an empty state.
 	  //Post condition: top = NULL
    linkedStackType();
   	  //default constructor
  	  //Post condition: top = NULL
    linkedStackType(const linkedStackType<Type>& otherStack);
  	  //copy constructor
    ~linkedStackType();
	  //destructor
	  //All elements of the stack are removed from the stack

private:
    nodeType<Type> *top; // pointer to the stack
};


template<class Type> //default constructor
linkedStackType<Type>::linkedStackType()
{
	top = NULL;
}

template<class Type>
void linkedStackType<Type>::destroyStack()
{
	nodeType<Type> *temp; //pointer to delete the node

	while(top != NULL)  //while there are elements in the stack
	{
	   temp = top;      //set temp to point to the current node
	   top = top->next; //advance top to the next node
	   delete temp;     //deallocate memory occupied by temp
	}
}// end destroyStack



template<class Type>
void linkedStackType<Type>:: initializeStack()
{
    destroyStack();
}

template<class Type>
bool linkedStackType<Type>::isEmptyStack()
{
	return(top == NULL);
}

template<class Type>
bool linkedStackType<Type>:: isFullStack()
{
   return 0;
}

template<class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the node
	newNode->info = newElement;   //store newElement in the node
	newNode->next = top;          //insert newNode before top
	top = newNode;            //set top to point to the top node
} //end push


template<class Type>
void linkedStackType<Type>::pop(Type& poppedElement)
{
   nodeType<Type> *temp;		//pointer to deallocate memory

   poppedElement = top->info;	//copy the top element into
 			     				//poppedElement
  // cout << "Popped item is " << poppedElement << endl;
   temp = top;					//set temp to point to the top node
   top = top->next;				//advance top to the next node
   delete temp;					//delete the top node
}//end pop



template<class Type>   //copy constructor
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack)
{
	nodeType<Type> *newNode, *current, *last;

	if(otherStack.top == NULL)
   		top = NULL;
	else
	{
		current = otherStack.top;	//set current to point to the
									//stack to be copied

			//copy the top element of the stack
		top = new nodeType<Type>;   //create the node
		top->info = current->info;  //copy the info
		top->next = NULL;     	    //set the link field of the
 									//node to null
		last = top;                 //set last to point to the node
		current = current->next;    //set current to point to the
             						//next node

			//copy the remaining stack
		while(current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->next = NULL;
			last->next = newNode;
			last = newNode;
			current = current->next;
		}//end while
	}//end else
}//end copy constructor


template<class Type> //destructor
linkedStackType<Type>::~linkedStackType()
{
	nodeType<Type> *temp;

	while(top != NULL)     //while there are elements in the stack
	{
		temp = top;        //set temp to point to the current node
		top = top ->next;  //advance first to the next node
		delete temp;       //deallocate the memory occupied by temp
	}//end while
}//end destructor

template<class Type>   //overloading the assignment operator
const linkedStackType<Type>& linkedStackType<Type>::operator=
    			  (const linkedStackType<Type>& otherStack)
{
	nodeType<Type> *newNode, *current, *last;

	if(this != &otherStack) //avoid self-copy
	{
		if(top != NULL)  //if the stack is not empty, destroy it
			destroyStack();

		if(otherStack.top == NULL)
			top = NULL;
		else
		{
   			current = otherStack.top;	//set current to point to
										//the stack to be copied

  				//copy the top element of otherStack
			top = new nodeType<Type>;	//create the node
			top->info = current->info;	//copy the info
			top->next = NULL;			//set the link field of the
										//node to null
			last = top;           		//make last point to the node
			current = current->next;	//make current point to
     									//the next node

				//copy the remaining elements of the stack
			while(current != NULL)
			{
				newNode = new nodeType<Type>;
				newNode->info = current->info;
				newNode->next = NULL;
				last->next = newNode;
				last = newNode;
				current = current->next;
			}//end while
		}//end else
	}//end if

	return *this;
}//end operator=
#endif

 #ifndef H_StackType
#define H_StackType

template <class Type>
class stackType
{
public:
    bool isEmptyStack();
	  //Function returns true if the stack is empty;
	  //otherwise, it returns false.
    bool isFullStack();
  	  //Function returns true if the stack is full;
	  //otherwise, it returns false.
    void destroyStack();
	  //Remove all elements from the stack
	  //Post: top = 0
    void push(const Type& newItem);
	  //Add the newItem to the stack
	  //Post: stack is changed and the newItem
	  //     is added to the top of stack
    void pop(Type& poppedItem);
	  //Remove the top element of the stack
	  //Post: Stack is changed and the top element
	  //     is removed from the stack. The top element
	  //     of the stack is saved in poppedItem.
    stackType(int stackSize = 100);
	  //constructor
	  //Create an array of size stackSize to hold the
	  // stack elements. The default stack size is 100
	  //Post: The variable list contains the base
	  //     address of the array, top = 0 and
	  //     maxStackSize = stackSize
    stackType(const stackType<Type>& otherStack);
	  //copy constructor
    ~stackType();
	  //destructor
	  //Remove all elements from the stack
	  //Post: The array (list) holding the stack
	  //     elements is deleted

private:
    int maxStackSize;	//variable to store the maximum stack size
    int top;			//variable to point to the top of the stack
    Type *list; 	   //pointer to the array that holds
 						//the stack elements
};

#include <iostream>
using namespace std;

template<class Type>
void stackType<Type>::destroyStack()
{
	top = 0;
}//end destroyStack

template<class Type>
bool stackType<Type>::isEmptyStack()
{
	return(top == 0);
}//end isEmptyStack

template<class Type>
bool stackType<Type>::isFullStack()
{
	return(top == maxStackSize);
} //end isFullStack

template<class Type>
stackType<Type>::stackType(int stackSize)
{
	if(stackSize <= 0)
	{
		cout<<"Size of the array to hold the stack must "
          <<"be positive."<<endl;
		cout<<"Creating an array of size 100."<<endl;

		maxStackSize = 100;
	}
	else
		maxStackSize = stackSize;	//set the stack size to
   				     				//the value specified by
 				     				//the parameter stackSize
	top = 0;						//set top to 0
	list = new Type[maxStackSize];	//create the array to
  									//hold the stack elements
}//end constructor


template<class Type>
stackType<Type>::~stackType() //destructor
{
   delete [] list; //deallocate memory occupied by the array
}//end destructor

template<class Type>
void stackType<Type>::push(const Type& newItem)
{
	list[top] = newItem; //add newItem at the top of the stack
	top++;   // increment the top
}//end push

template<class Type>
void stackType<Type>::pop(Type& poppedItem)
{
	top--;                      //decrement the top
	poppedItem = list[top];     //copy the top element of
								//the stack into poppedItem
	cout << "Popped item is " << poppedItem << endl;
}//end pop

#endif

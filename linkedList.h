#ifndef H_LinkedListType
#define H_LinkedListType  
 
#include <iostream>
#include <cassert>
#include "node.h"

using namespace std; 

template <class Type>
class linkedListIterator
{
public:
   linkedListIterator();
     //Default constructor
     //Postcondition: current = nullptr;

   linkedListIterator(nodeType<Type> *ptr);
     //Constructor with a parameter.
     //Postcondition: current = ptr;

   Type operator*();
     //Function to overload the dereferencing operator *.
     //Postcondition: Returns the info contained in the node.

   linkedListIterator<Type> operator++();    
     //Overload the pre-increment operator.
     //Postcondition: The iterator is advanced to the next 
     //               node.

   bool operator==(const linkedListIterator<Type>& right) const; 
     //Overload the equality operator.
     //Postcondition: Returns true if this iterator is equal to 
     //               the iterator specified by right, 
     //               otherwise it returns the value false.

   bool operator!=(const linkedListIterator<Type>& right) const; 
     //Overload the not equal to operator.
     //Postcondition: Returns true if this iterator is not  
     //               equal to the iterator specified by  
     //               right; otherwise it returns the value 
     //               false.

private:
   nodeType<Type> *current; //pointer to point to the current 
                            //node in the linked list
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = NULL;
}

template <class Type>
linkedListIterator<Type>::
                  linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()   
{
    current = current->next;

    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==
               (const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=
                 (const linkedListIterator<Type>& right) const
{    return (current != right.current);
}


//*****************  class linkedListType   ****************

template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=
                         (const linkedListType<Type>&);  
      //Overload the assignment operator.

    void initializeList(); 
      //Initialize the list to an empty state.
      //Postcondition: head = NULL, tail = NULL, count = 0;

    bool isEmptyList() const;
      //Function to determine whether the list is empty. 
      //Postcondition: Returns true if the list is empty,
      //               otherwise it returns false.

    void print() const;
      //Function to output the data contained in each node.
      //Postcondition: none

    int length() const;
      //Function to return the number of nodes in the list.
      //Postcondition: The value of count is returned.

    void destroyList();
      //Function to delete all the nodes from the list.
      //Postcondition: head = NULL, tail = NULL, count = 0;

    Type front() const; 
      //Function to return the head element of the list.
      //Precondition: The list must exist and must not be 
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the head 
      //               element of the list is returned.

    Type back() const; 
      //Function to return the tail element of the list.
      //Precondition: The list must exist and must not be 
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the tail  
      //               element of the list is returned.

    virtual bool search(const Type& searchItem) const = 0;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

    virtual void insertFirst(const Type& newItem) = 0;
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               tail points to the tail node in the list, 
      //               and count is incremented by 1.

    virtual void insertLast(const Type& newItem) = 0;
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               tail points to the tail node in the list,
      //               and count is incremented by 1.

    virtual void deleteNode(const Type& deleteItem) = 0;
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, tail
      //               points to the tail node of the updated 
      //               list, and count is decremented by 1.

    linkedListIterator<Type> begin();
      //Function to return an iterator at the begining of the 
      //linked list.
      //Postcondition: Returns an iterator such that current is
      //               set to first.

    linkedListIterator<Type> end();
      //Function to return an iterator one element past the 
      //tail element of the linked list. 
      //Postcondition: Returns an iterator such that current is
      //               set to NULL.

    linkedListType(); 
      //default constructor
      //Initializes the list to an empty state.
      //Postcondition: first = NULL, tail = NULL, count = 0; 

    linkedListType(const linkedListType<Type>& otherList); 
      //copy constructor

    ~linkedListType();   
      //destructor
      //Deletes all the nodes from the list.
      //Postcondition: The list object is destroyed. 

protected:
    int count;   //variable to store the number of 
                 //elements in the list
    nodeType<Type> *head; //pointer to the first node of the list
    nodeType<Type> *tail;  //pointer to the tail node of the list

private: 
    void copyList(const linkedListType<Type>& otherList); 
      //Function to make a copy of otherList.
      //Postcondition: A copy of otherList is created and
      //               assigned to this list.
};


template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return(head == NULL);
}

template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (head != NULL)   //while there are nodes in the list
    {
        temp = head;        //set temp to the current node
        head = head->next; //advance head to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    tail = NULL; //initialize tail to NULL; head has already
                 //been set to NULL by the while loop
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current; //pointer to traverse the list

    current = head;    //set current so that it points to 
                        //the head node
    while (current != NULL) //while more data to print
    {
        cout << current->info << " ";
        current = current->next;
    }
}//end print

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}  //end length

template <class Type>
Type linkedListType<Type>::front() const
{   
    assert(head != NULL);

    return head->info; //return the info of the head node	
}//end front

template <class Type>
Type linkedListType<Type>::back() const
{   
    assert(tail != NULL);

    return tail->info; //return the info of the tail node	
}//end back

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(head);

    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);

    return temp;
}

template <class Type>
void linkedListType<Type>::copyList
                   (const linkedListType<Type>& otherList) 
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list

    if (head != NULL) //if the list is nonempty, make it empty
       destroyList();

    if (otherList.head == NULL) //otherList is empty
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    else
    {
        current = otherList.head; //current points to the 
                                   //list to be copied
        count = otherList.count;

            //copy the head node
        head = new nodeType<Type>;  //create the node

        head->info = current->info; //copy the info
        head->next = NULL;        //set the next field of 
                                   //the node to NULL
        tail = head;              //make tail point to the
                                   //head node
        current = current->next;     //make current point to
                                     //the next node

           //copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType<Type>;  //create a node
            newNode->info = current->info; //copy the info
            newNode->next = NULL;       //set the next of 
                                        //newNode to NULL
            tail->next = newNode;  //attach newNode after tail
            tail = newNode;        //make tail point to
                                   //the actual tail node
            current = current->next;   //make current point 
                                       //to the next node
        }//end while
    }//end else
}//end copyList

template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
   destroyList();
}//end destructor

template <class Type>
linkedListType<Type>::linkedListType
                      (const linkedListType<Type>& otherList)
{
   	head = NULL;
    copyList(otherList);
}//end copy constructor

         //overload the assignment operator
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
                      (const linkedListType<Type>& otherList)
{ 
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else

     return *this; 
}

#endif

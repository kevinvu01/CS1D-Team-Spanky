#ifndef H_QueueAsArray
#define H_QueueAsArray

#include <iostream>

using namespace std;

template<class Type>
class queueType
{
public:
    const queueType<Type>& operator=(const queueType<Type>&);
              // overload the assignment operator
	void initializeQueue();
	void destroyQueue();
	int isEmptyQueue();
	int isFullQueue();
	void addQueue(Type queueElement);
	void deQueue(Type& deqElement);

	queueType(int queueSize = 100);
	queueType(const queueType<Type>& otherQueue);
		// copy constructor
	~queueType();
		//destructor

private:
	int maxQueueSize;
	int count;
	int front;
 	int rear;
	Type *list;  //pointer to the array that holds the queue elements
};

template<class Type>
void queueType<Type>::initializeQueue()
{
	front = 0;
    rear = maxQueueSize - 1;
	count = 0;
}

template<class Type>
void queueType<Type>::destroyQueue()
{
	front = 0;
    rear = maxQueueSize - 1;
	count = 0;
}

template<class Type>
int queueType<Type>::isEmptyQueue()
{
   return(count == 0);
}

template<class Type>
int queueType<Type>::isFullQueue()
{
   return(count == maxQueueSize);
}

template<class Type>
void queueType<Type>::addQueue(Type newElement)
{
   rear = (rear + 1) % maxQueueSize; // use mod operator to advance rear
					     //because array is circular
   count++;
   list[rear] = newElement;
}

template<class Type>
void queueType<Type>::deQueue(Type& deqElement)
{
   deqElement = list[front];

   count--;
   front = (front + 1) % maxQueueSize; // use mod operator to advance 									   // rear because the array is circular

}


template<class Type>
queueType<Type>::queueType(int queueSize)   //constructor
{
	if(queueSize <= 0)
	{
		cout<<"Size of the array to hold the queue must "
			<<"be positive."<<endl;
		cout<<"Creating an array of size 100."<<endl;

		maxQueueSize = 100;
	}
	else
   		maxQueueSize = queueSize;  //set maxQueueSize to queueSize

	front = 0; 	   //initialize front
	rear = maxQueueSize - 1; 	   //initiaize rear
	count = 0;
	list = new Type[maxQueueSize];  //create the array to
				     //hold queue elements
}

template<class Type>
queueType<Type>::~queueType()   //destructor
{
   delete [] list;
}

template<class Type>
const queueType<Type>& queueType<Type>::operator=
	                   (const queueType<Type>& otherQueue)
{
	cout<<"Write the definition of the function "
		<<"to overload the assignment operator"<<endl;
}


#endif

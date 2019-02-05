#ifndef H_DLinkedList
#define H_DLinkedList

using namespace std;

template <class Type>
struct nodeType2
{
	Type info;
	nodeType2<Type> *next;
	nodeType2<Type> *prev;
};


template <class Type>
class DLinkedList 				// doubly linked list
{
	public:
    DLinkedList();				// constructor
    ~DLinkedList();				// destructor
    bool empty() const;				// is list empty?
    const Type& front() const;			// get front element
    const Type& back() const;			// get back element
    void addFront(const Type& e);		// add to front of list
    void addBack(const Type& e);		// add to back of list
    void removeFront();				// remove from front
    void removeBack();				// remove from back
  private:					// local type definitions
    nodeType2<Type> * header;				// list sentinels
    nodeType2<Type> * trailer;
  protected:					// local utilities
    void add(nodeType2<Type> *v, const Type&);		// insert new node before v
    void remove(nodeType2<Type> *v);			// remove node v
 };

template <class Type>
DLinkedList<Type>::DLinkedList() 
{			// constructor
    header = new nodeType2<Type>;				// create sentinels
    trailer = new nodeType2<Type>;
    header->next = trailer;			// have them point to each other
    trailer->prev = header;
}
  
template <class Type>
DLinkedList<Type>::~DLinkedList() 
{			// destructor
	while (!empty()) 
		removeFront();		// remove all but sentinels
	delete header;				// remove the sentinels
	delete trailer;
}

template <class Type>
bool DLinkedList<Type>::empty() const		// is list empty?
{
	return (header->next == trailer); 
}

template <class Type>
  const Type& DLinkedList<Type>::front() const	// get front element
    { return header->next->info; }

template <class Type>
  const Type& DLinkedList<Type>::back() const		// get back element
    { return trailer->prev->info; }

template <class Type>
  void DLinkedList<Type>::add(nodeType2<Type>* v, const Type& e) {
    nodeType2<Type>* u = new nodeType2<Type>;  
	u->info = e;		// create a new node for e
    u->next = v;				// link u in between v
    u->prev = v->prev;				// ...and v->prev
    v->prev->next = v->prev = u;
  }

template <class Type>
  void DLinkedList<Type>::addFront(const Type& e)	// add to front of list
    { add(header->next, e); }
  
  template <class Type>
  void DLinkedList<Type>::addBack(const Type& e)	// add to back of list
    { add(trailer, e); }

template <class Type>
  void DLinkedList<Type>::remove(nodeType2<Type>* v) {		// remove node v
    nodeType2<Type>* u = v->prev;				// predecessor
    nodeType2<Type>* w = v->next;				// successor
    u->next = w;				// unlink v from list
    w->prev = u;
    delete v;
  }

template <class Type>
  void DLinkedList<Type>::removeFront()		// remove from font
    { remove(header->next); }
  
  template <class Type>
  void DLinkedList<Type>::removeBack()		// remove from back
    { remove(trailer->prev); }

#endif
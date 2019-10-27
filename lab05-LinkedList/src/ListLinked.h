//--------------------------------------------------------------------
//
//  Laboratory 5                                          ListLinked.h
//
//  Class declaration for the linked implementation of the List ADT
//
//--------------------------------------------------------------------

#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType>
class List {
  public:
    List(int ignored = 0)
  {
    	// create an empty list
    	head = 0; // this creates an empty list
    	cursor = 0; // they use 0 instead of C's NULL
    	size = 0;
  }

    List(const List& other) // this one will copy an existing linked list -- do later.
    {
    	cout<<"running copy constructor"<<endl;
    	head = 0; // this creates an empty list
    	cursor = 0; // they use 0 instead of C's NULL
    	size = 0;

    	// create a new node and assign it to head

    	ListNode *ptr = other.head;
    	ListNode *temp2 = new ListNode(ptr->dataItem, 0); // allocate the first node

    	cursor = temp2;
    	head = cursor;
    	ptr=ptr->next;
    	size++;

    	for(; ptr!=0; ptr=ptr->next)
    	{
    		temp2 = new ListNode(ptr->dataItem, 0); // allocate another node
    		cursor->next = temp2;
    		cursor = temp2;
    		size++;
    	}

    }
    List& operator=(const List& other)
    {
    	// so first I would have to clear the list
    	clear();

    	// now I want to equate the two lists
    	ListNode *ptr = other.head;
    	ListNode *temp2 = new ListNode(ptr->dataItem, 0); // allocate the first node

    	cursor = temp2;
    	head = cursor;
    	ptr=ptr->next;
    	size++;

    	for(; ptr!=0; ptr=ptr->next)
    	{
    		temp2 = new ListNode(ptr->dataItem, 0); // allocate another node
    		cursor->next = temp2;
    		cursor = temp2;
    		size++;
    	}

    	return *this; // dereference the this pointer to return the actual object

    }

    ~List() // this will be more complicated. I'll have to go through the entire list and remove all the nodes created.
    {
    	cout<<"\nobject destroyed\n"<<flush;
    	clear(); // technically the operation is the same as calling out clear
    }

    void insert(const DataType& newDataItem) ;
    void remove() ;
    void replace(const DataType& newDataItem) ;
    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void gotoBeginning() ;
    void gotoEnd() ;
    bool gotoNext() ;
    bool gotoPrior() ;

    DataType getCursor() const ;

    // Programming exercise 2
    void moveToBeginning () ;

    // Programming exercise 3
    void insertBefore(const DataType& newDataItem) ;
    
    void showStructure() const;

  private:

    class ListNode
	{
      public:
	ListNode(const DataType& nodeData, ListNode* nextPtr);
	DataType dataItem;
	ListNode* next;
    };

    ListNode* head;
    ListNode* cursor;

    // add two size variables for convenience
    int size;
    static const int CAPACITY = 7; // using the word static allows to initialize it inside the clss
};

#endif

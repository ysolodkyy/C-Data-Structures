//--------------------------------------------------------------------
//
//  Laboratory 6                                          StackArray.h
// 
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType>
{

  public:

	// constructors
    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE)
  {
    	top = 0;
    	head = 0;
    	size = 0;
  }

    StackLinked(const StackLinked& other);

    // assignment operator overloaded
    StackLinked& operator=(const StackLinked& other)
    {
    	clear();

    	// now I want to equate the two lists
    	StackLinked *ptr = other.head;
    	StackLinked *temp2 = new StackLinked(ptr->dataItem, 0); // allocate the first node

    	top = temp2;
    	head = top;
    	ptr=ptr->next;
    	size++;

    	for(; ptr!=0; ptr=ptr->next)
    	{
    		temp2 = new StackLinked(ptr->dataItem, 0); // allocate another node
    		top->next = temp2;
    		top = temp2;
    		size++;
    	}

    	return *this; // dereference the this pointer to return the actual object

    }

    // destructor
    ~StackLinked()
    {
    	cout<<"object Destroyed"<<endl;

    	clear();
    }

    void push(const DataType& newDataItem) ;
    DataType pop() ;

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:

    class StackNode
	{
      public:
	StackNode(const DataType& nodeData, StackNode* nextPtr)
      {
		dataItem = nodeData;
		next = nextPtr;
      }

	DataType dataItem;
	StackNode* next;
    };

    StackNode* top, *head;
    int size;
};

#endif		//#ifndef STACKARRAY_H


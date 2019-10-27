//--------------------------------------------------------------------
//
//  Laboratory 6                                         StackLinked.h
// 
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackArray : public Stack<DataType> {
public:

	// constructors
	StackArray(int maxNumber = Stack<DataType>::MAX_STACK_SIZE)
{
		maxSize = maxNumber;
		top = -1;
		dataItems = new DataType[maxSize]; // create an actual array that will store data
}


	StackArray(const StackArray& other)
	{
		maxSize = other.maxNumber;
		top = -1;
		dataItems = new DataType[other.maxSize]; // create an actual array that will store data

		while(top < other.top)
		{
			++top;
			dataItems[top] = other.dataItems[top];
		}
	}

	// assignment operator overloaded
	StackArray& operator=(const StackArray& other)
	// I am assuming this implies deep copy
	{
		delete [] dataItems; // clear previously allocated memory

		maxSize = other.maxNumber;
		top = -1;
		dataItems = new DataType[other.maxSize]; // create an actual array that will store data

		while(top < other.top)
		{
			++top;
			dataItems[top] = other.dataItems[top];
		}

		return *this; // is this
	}
	// destructor
	~StackArray()
	{
		cout<<"object destroyed"<<endl;

		delete []dataItems; // free array memory
	}

	void push(const DataType& newDataItem) ;
	DataType pop() ;

	void clear();

	bool isEmpty() const;
	bool isFull() const;

	void showStructure() const;

private:
	int maxSize;
	int top;
	DataType* dataItems;
};

#endif		//#ifndef STACKARRAY_H

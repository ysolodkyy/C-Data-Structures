

#include <stdexcept>
#include <iostream>

#include "StackLinked.h"
using namespace std;

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem)
{
	if(isFull())
	{
		cout<<"list is FULL"<<endl;
	}
	else if(isEmpty())
	{
		StackNode *ptr = new StackNode(newDataItem, 0);
		head = ptr;
		top = ptr;
		size++;
	}
	else
	{
		StackNode *ptr = new StackNode(newDataItem, 0);
		top->next = ptr;
		top = ptr;
		size++;
	}
}


template <typename DataType>
DataType StackLinked<DataType>::pop()
{
	if(!isEmpty())
	{
		StackNode *ptr = head;

		if(ptr == top)
		{
			DataType data = top->dataItem; // it might be cleaner to use data = top->dataItem
			delete ptr;
			size--;

			head = 0;
			top = 0;

			return data;
		}

		else
		{
			while(ptr->next != top)
			{
				ptr = ptr->next;
			}
			DataType data = top->dataItem; // // it might be cleaner to use data = top->dataItem
			delete top;
			size--;

			top = ptr; // reassign top to point to the previous node
			top->next = 0;

			return data;
		}
		// remember that pointer->variable modifies the actual variable at the memoroy location the pointer is pointing at. so this variable can be pointer at by a billion pointers.
	}
	else
	{
		cout<<"stack is empty"<<endl;
	}
}

template <typename DataType>
void StackLinked<DataType>::clear()
{
	// need to free memory for each node
	if(isEmpty())
	{
		cout<< "\nthe list is empty"<<flush;
	}
	else
	{
		top = head;
		while(top->next !=0)
		{
			top = top ->next;
			delete head;
			size--;
			head = top;
		}
		delete head; // delete the last node
		size--;
		// should I set the pointers to null now?
		top = 0;
		head = 0;

		cout<<"size = "<<size<<endl; // it had better be 0
	}

}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
	return (head == 0 && size == 0);
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
	return (size == this->MAX_STACK_SIZE);
}


template <typename DataType>
void StackLinked<DataType>::showStructure() const

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
	if( isEmpty() )
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		cout<<"size= "<<size<<endl;
		cout << "Top\t";

		for (StackNode* temp = head; temp != 0; temp = temp->next) {
			if( temp == top ) {
				cout << "[" << temp->dataItem << "]\t";
			}
			else {
				cout << temp->dataItem << "\t";
			}
		}
		cout << "Bottom" << endl;
	}

}

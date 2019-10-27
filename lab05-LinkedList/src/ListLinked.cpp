
#include "ListLinked.h"
#include <stdexcept>
#include <iostream>

using namespace std;



template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr) // need to create a constructor for the ListNode class -- doing it here for practice
{ // for ListNode, we only need to initialize the data in the node. no memory allocation needed.
	dataItem = nodeData;
	next = nextPtr;
}
template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem)  // same as insert after really
{
	if(isFull())
	{
		cout<< "\nthe list is full"<<flush;
	}
	// here I have to create a new node
	else if(isEmpty())
	{
		head = new ListNode(newDataItem,0); // allocate memory for a single node
		cursor = head; // set the cursor pointing at the first element in the node
		size = 1;
	}

	else
	{
		// so I was right!
		ListNode* temp = new ListNode(newDataItem,0);
		size ++;
		temp->next = cursor->next; // this could go into the constructor instead of the zero: ListNode* temp = new ListNode(newDataItem,cursor->next);
		cursor->next = temp;
		cursor = cursor->next; // equivalent to cursor = temp;

	}
}

template <typename DataType>
void List<DataType>::remove()
{

	ListNode* temp = head;

	if(head == cursor)
	{
		head = temp->next;
		cursor = temp->next; // if this is a single node left, the two pointers will point to null
		delete temp; // free memory
		size--;
	}
	else
	{
		while(temp->next != cursor)
		{
			temp = temp->next;
		}
		temp->next = cursor->next;

		delete cursor; // free memory allocated to the node
		size --;

		if(temp->next !=0)
		{
			cursor = temp->next;
		}
		else
		{
			cursor = head;
		}
	}
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem)
{
	if(isEmpty())
	{
		cout<< "\nthe list is empty"<<flush;
	}
	// here I have to create a new node
	else
	{
		cursor->dataItem = newDataItem; // simply assign the new value to the data item
	}
}

template <typename DataType>
void List<DataType>::clear()
{
	// need to free memory for each node
	if(isEmpty())
	{
		cout<< "\nthe list is empty"<<flush;
	}
	else
	{
		cursor = head;
		while(cursor->next !=0)
		{
			cursor = cursor ->next;
			delete head;
			size--;
			head = cursor;
		}
		delete head; // delete the last node
		size--;
		//  set the pointers to null now
		cursor = 0;
		head = 0;

		cout<<"size = "<<size<<endl; // it had better be 0
	}

}

template <typename DataType>
bool List<DataType>::isEmpty() const
{
	return (head == 0);
}

template <typename DataType>
bool List<DataType>::isFull() const
{
	return (size==CAPACITY);
}

template <typename DataType>
void List<DataType>::gotoBeginning()
{
	if(isEmpty())
	{
		cout<< "\nthe list is empty"<<flush;
	}
	else
	{
		cursor = head; // simply assign the cursor to head
	}
}

template <typename DataType>
void List<DataType>::gotoEnd()
{
	while(cursor->next!=0) // prevent the cursor from running off the list
	{
		cursor = cursor->next; // simply move the cursor to the next.
	}
}

template <typename DataType>
bool List<DataType>::gotoNext()
{
	if(cursor->next!=0) // prevent the cursor from running off the list
	{
		cursor = cursor->next; // simply move the cursor to the next.

		return true;
	}
	else
	{
		cout<<"\nreached the end"<<flush; // optinal message
		return false;
	}
}

template <typename DataType>
bool List<DataType>::gotoPrior()
{
	if(isEmpty())
	{
		return false;
	}
	else if(cursor == head)
	{
		return false; // do nothing
	}
	else
	{
		ListNode* temp = head;
		while(temp->next != cursor)
		{
			temp = temp->next;
		}
		cursor = temp;
		return true;
	}

}

template <typename DataType>
DataType List<DataType>::getCursor() const
{
	return cursor->dataItem;
}

// Programming exercise 2
template <typename DataType>
void List<DataType>::moveToBeginning ()
{
	// mode data at cursor to beginning -- easy
	ListNode *temp = head; // remember that temp's scope is this method only

	while(temp->next !=cursor)
	{
		temp = temp->next;
	}

	temp->next = cursor->next;
	cursor->next = head;
	head = cursor;

}

// Programming exercise 3
template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem)
{
	// there are two ways to do it. with two temps is the straight forward way. and with a single temp is more tricky
	if(isEmpty())
	{
		insert(newDataItem);
	}

	else if(cursor ==head)
	{
		ListNode* temp = new ListNode(newDataItem,cursor); // create a temp pointer pointing at a newly created node whose ->next = cursor.
		cursor = temp;
		head = temp;
	}
	else
	{
		ListNode* temp = new ListNode(newDataItem,cursor); // create a temp pointer pointing at a newly created node whose ->next = cursor.

		// here I repurpose the cursor as another temp
		cursor = head;
		while(cursor->next !=temp->next)
		{
			cursor = cursor->next;
		}
		cursor->next = temp;
		// point the cursor to the newly created node, as it is intended
		cursor = temp;
	}
}

template <typename DataType>
void List<DataType>::showStructure() const

// Outputs the items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
	if ( isEmpty() )
	{
		cout << "Empty list" << endl;
	}
	else
	{
		for (ListNode* temp = head; temp != cursor; temp = temp->next) {
			if (temp == cursor) {
				cout << "[";
			}

			// Assumes that dataItem can be printed via << because
			// is is either primitive or operator<< is overloaded.
			cout << temp->dataItem;

			if (temp == cursor) {
				cout << "]";
			}
			cout << " ";
		}
		cout << endl;
	}
}


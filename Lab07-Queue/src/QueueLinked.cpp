

#include <stdexcept>
#include <iostream>

#include "QueueLinked.h"
using namespace std;

// insert at the front
// pop at the back

template <typename DataType>
void QueueLinked < DataType>::enqueue(const DataType& newDataItem)
{
	if(isFull())
	{
		cout<<"\nthe queue is full"<<endl;
	}
	else if(isEmpty())
	{
		front = new QueueNode(newDataItem, 0);
		back = front;
		size++;
	}
	else
	{
		QueueNode* temp = new QueueNode(newDataItem, 0);
		front->next = temp;
		front = temp;
		size++;
	}
 }
template <typename DataType>
DataType QueueLinked < DataType>::dequeue()
{
if(isEmpty())
{
	cout<<"\nqueue is empty"<<endl;
}
else if(back==front)
{
	DataType data = back->dataItem; // get the data
	delete back; // free memory
	size--;
	// set both pointers to NULL
	back = 0;
	front = 0;

	return data;
}
else
{
	DataType data = back->dataItem; // get the data
	QueueNode* temp = back; // assign temp pointer to back
	back = back->next; // update the back pointer
	delete temp; // delete memory temp is pointing to
	size--;
	return data;
}
}

template <typename DataType>
void QueueLinked < DataType>:: clear()
{
	front = back;
	while(front !=0)
	{
		front = front->next; // move front to next node
		delete back; // free memory pointed at by back
		size--; // decrement size
		back=front; // move back to next node
	}

	if(size!=0)
	{
		cout<<"size!=0 "<<endl;
	}
}

template <typename DataType>
bool QueueLinked < DataType>:: isEmpty() const
{
    return (front==0 && back ==0);
}

template <typename DataType>
bool QueueLinked < DataType>:: isFull() const
{
	return (size == this->MAX_QUEUE_SIZE); // how did I know to use the "this->" pointer here?
}


template <typename DataType>
void QueueLinked < DataType>:: showStructure () const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
	QueueNode *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = back ; p != 0 ; p = p->next )
	{
	    if( p == front )
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}

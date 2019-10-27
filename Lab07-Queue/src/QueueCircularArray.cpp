



#include <stdexcept>
#include <iostream>

using namespace std;

#include "QueueCircularArray.h"



template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem)
// this should work temporarily as a inefficient queue
{
	if(isFull())
	{
		cout << "Queue is full"<<endl;
	}
	else
	{
		if(front == -1)
			front = 0;

		back = (back + 1) % maxSize;
		dataItems[back] = newDataItem;
	}

}

template <typename DataType>
DataType QueueArray<DataType>::dequeue()
{
	if(isEmpty())
	{
		cout<<"\nQueue Empty"<<endl;
	}
	else
	{
		DataType data = dataItems[front];

		if(back == front)
		{
			front = -1;
			back = -1;
		}
		else
		{
			front = (front + 1)%maxSize;
		}

		return data;
	}
}

template <typename DataType>
void QueueArray<DataType>::clear()
{
	front = -1;
	back = -1;
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const
{
	return (front == -1 && back == -1);
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const
{
	if(back == maxSize-1 && front == 0)
	{
		return true;
	}
	else if (back + 1 == front)
	{
		return true;
	}

	else
	{
		return false;
	}
}

// EXERCISES:

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem)
{
	if(isFull())
	{
		cout<<"the queue is full"<<endl;
	}
	else
	{

		if(front==0)
		{
			front = maxSize-1;
		}
		else
		{
			front--;
		}
		//front = (maxSize+(--front))%maxSize; // single line index update, not as explicit
		dataItems[front] = newDataItem;
	}
}

template <typename DataType>
DataType QueueArray<DataType>::getRear()
{
	DataType data = dataItems[back];

	if(back == front)
	{
		front = -1;
		back = -1;
	}
	else
	{
		back = (maxSize+(--back))%maxSize;
//		if(back==0)
//		{
//			back = maxSize-1;
//		}
//		else
//		{
//			back--;
//		}
		return data;
	}
}

template <typename DataType>
int QueueArray<DataType>::getLength() const
{
	if(isEmpty())
		return 0;
	else if(front>back)
		return back + (maxSize-front)%maxSize + 1;
	else
		return back - front + 1;
}

/////////////////

template <typename DataType>
void QueueArray<DataType>::showStructure() const
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
	int j;   // Loop counter

	if ( front == -1 )
		cout << "Empty queue" << endl;
	else
	{
		cout << "Front = " << front << "  Back = " << back << endl;
		for ( j = 0 ; j < maxSize ; j++ )
			cout << j << "\t";
		cout << endl;
		if ( back >= front )
			for ( j = 0 ; j < maxSize ; j++ )
				if ( ( j >= front ) && ( j <= back ) )
					cout << dataItems[j] << "\t";
				else
					cout << " \t";
		else
			for ( j = 0 ; j < maxSize ; j++ )
				if ( ( j >= front ) || ( j <= back ) )
					cout << dataItems[j] << "\t";
				else
					cout << " \t";
		cout << endl;
	}
}


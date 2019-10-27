



#include <stdexcept>
#include <iostream>

using namespace std;

#include "QueueLinearArray.h"

//using the shift function to shift the non-circular array queue for demonstration purposes - Not as efficient as a circular queue
template <typename DataType>
bool QueueArray<DataType>::shift()
// it would be better to declare it as a friend function
{
	if(back > 0 /*&& front ==  maxSize-1*/) 
	{
		for(int i = 0; i <= front - back; i++)
		{
			dataItems[i] = dataItems[i+back];
		}
		front = front - back;
		back = 0;

		return true;
	}
	else
	{
		return false;
	}
}


template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) 

{
	if(isFull())
	{
		cout<<"\nQueue Full"<<endl;
	}
	else if(isEmpty())
	{
		back = 0;
		front = 0;

		dataItems[front] = newDataItem;
	}

	else if(front < maxSize-1)
	{
		dataItems[++front] = newDataItem;
	}
	else
	{	// will this recursive approach make it work better?
		shift();
		enqueue(newDataItem);
	}
}

template <typename DataType>
DataType QueueArray<DataType>::dequeue() 
{
	if(isEmpty())
	{
		cout<<"\nQueue Empty"<<endl;
	}

	else if(back == front)
	{
		int temp = back;
		back = -1;
		front = -1;

		return dataItems[temp];
	}
	else
	{
		shift();
		return dataItems[back++];;
	}

}

template <typename DataType>
void QueueArray<DataType>::clear()
{
	back = -1;
	front = -1;
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const
{
	return (back == -1 && front == -1);
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const
{
	return (back == 0 && front == maxSize-1);
}

// EXERCISES:

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) 
{

}

template <typename DataType>
DataType QueueArray<DataType>::getRear() 
{

}

template <typename DataType>
int QueueArray<DataType>::getLength() const
{
	return front - back;
}

/////////////////

template <typename DataType>
void QueueArray<DataType>::showStructure() const
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
	if ( front == -1 )
		cout << "Empty queue" << endl;
	else
	{
		cout << "Front = " << front << "  Back = " << back << endl;
		for (int j = back ; j <= front ; j++ )
			cout<<"["<<dataItems[j] << "]"<<flush;
	}
}

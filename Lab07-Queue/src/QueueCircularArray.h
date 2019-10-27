// QueueArray.h

#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Queue.h"

template <typename DataType>
class QueueArray : public Queue<DataType>
{
  public:
	// constructors
	QueueArray(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE)
  {
		// initialize variables
		maxSize = maxNumber;
		front = -1;
		back = -1;

		dataItems = new DataType[maxSize]; // allocate memory

		cout<<"Array Queue CAP: "<<maxSize<<endl;
  }

    QueueArray(const QueueArray& other);


    QueueArray& operator=(const QueueArray& other);
    // destructor
    ~QueueArray()
    {
    	cout<<"object destroyed"<<endl;
    	delete [] dataItems;
    }

    void enqueue(const DataType& newDataItem) ;
    DataType dequeue() ;

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void putFront(const DataType& newDataItem) ;
    DataType getRear() ;
    int getLength() const;

    void showStructure() const;


  private:
    int maxSize;
    int front; // lease recent
    int back; // most recent
    DataType* dataItems;
};

#endif

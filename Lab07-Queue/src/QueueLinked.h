// QueueLinked.h

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Queue.h"

template <typename DataType>
class QueueLinked : public Queue<DataType>
{
  public:
    QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE) // why are they passing max queue size if I should be inheriting this from the base class.
  {
    	// set both pointers to NUL
    	front = 0;
    	back = 0;
    	size = 0;
  }
    QueueLinked(const QueueLinked& other);

    // assignment operator overloaded
    QueueLinked& operator=(const QueueLinked& other);

    // destructor
    ~QueueLinked()
    {
    	cout<<"object destroyed"<<endl;
    	//call out the clear function because it does the same thing
    	clear();
    }

    void enqueue(const DataType& newDataItem) ;
    DataType dequeue() ;

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    // Programming Exercise 2
    void putFront(const DataType& newDataItem) ;
    DataType getRear() ;
    // Programming Exercise 3
    int getLength() const;

    void showStructure() const;

  private:
    class QueueNode
	{
      public:
	QueueNode(const DataType& nodeData, QueueNode* nextPtr)
      {
		dataItem = nodeData;
		next = nextPtr;
      }

	DataType dataItem;
	QueueNode* next;
    };

    QueueNode* front;
    QueueNode* back;

    int size;
};

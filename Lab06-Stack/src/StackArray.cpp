

#include "StackArray.h"

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem)
{
	if(isFull())
	{
		cout<<"the stack is full!"<<endl;
	}
	else
	{
		dataItems[++top] = newDataItem;
	}
}

template <typename DataType>
DataType StackArray<DataType>::pop()
{
	if(isEmpty())
	{
		cout<<"the stack is empty"<<flush;
	}
	else
	{
		return dataItems[top--];
	}
}

template <typename DataType>
void StackArray<DataType>::clear()
{
	top = -1;
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
	return (top == -1);
}

template <typename DataType>
bool StackArray<DataType>::isFull() const
{
	return(top == maxSize-1);
}

/////////

template <typename DataType>
void StackArray<DataType>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}

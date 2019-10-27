
#include "ListArray.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// this is my implementation of class methods

// remember that this is an Array Based List so we have an index



// Overloaded assignment operator -- not done yet!


// Destructor
template < typename DataType >
List<DataType>::~List ()
{
	cout<<"object destroyed"<<endl;

	delete [] dataItems; // should be ok.
	// delete allocated space of size MAX_list_SIZ#
}

// List manipulation operations
template < typename DataType >
void List<DataType>::insert ( const DataType& newDataItem ) throw ( logic_error )  // Insert after cursor
{
	// because this is not a FIFO or LIFO, this list behaves differently:

	if(isEmpty())
	{
		cursor = 0;
		size = 1;
		dataItems[cursor] = newDataItem;
	}

	else
	{
		if(size < maxSize) //if(size ==maxSize) we're already at capacity, and can't add more data
		{
			size++;
			cursor = size-1; // get to the end of the list
			dataItems[cursor] = newDataItem;

		}
		else
			throw ("Error: List is full --can't add more");

	}
}

template < typename DataType >
void List<DataType>::remove () throw ( logic_error )         // Remove data item
{
	if(this->isEmpty())
	{
		throw ("Error: list is empty-- can't remove"); // cant remove anything from an empty
	}
	else if(cursor == 0 && size == 1) // if we only have a single element in the list
	{
		cursor = -1;
		size = 0;
	}
	else
	{
		for (int i = cursor; i < size; i++)
		{
			dataItems[i] = dataItems[i+1];
		}
		if(cursor == size-1)
		{
			cursor--;
			size--;
		}
		else
		{
			size--;
		}
	}

}

template < typename DataType >
void List<DataType>::replace ( const DataType& newDataItem ) throw ( logic_error )// Replace data item marked by the cursor -- so we don't have to search at all

{
	if(this->isEmpty ())
	{
		throw ("Error: list is empty -- can't replace");
	}
	else
	{
		dataItems[cursor] = newDataItem;
	}
}
template < typename DataType >

void List<DataType>::clear ()                               // Clear list
{
	//-- technically I should just set the cursor to -1, and set size to 0?
	cursor = -1;
	size = 0;
}
// List status operations

template < typename DataType >
bool List<DataType>::isEmpty () const                    // List is empty
{
	// -- ie is the cursor = -1?
	if(cursor == -1 && size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

template < typename DataType >
bool List<DataType>::isFull () const                     // List is full
{
	if(size == maxSize)
	{
		return true;
	}
	else
	{
		return false;
	}

}

// List iteration operations --- I think the cursos must be less or equal to 'size' for all these methods below.
template < typename DataType >
void List<DataType>::gotoBeginning () throw ( logic_error )                    // Go to beginning
{
	if(isEmpty ()== true)
	{
		throw ("Error: list is empty -- can't go to the beginnig");
	}
	else
	{
		cursor = 0; // I am not sure I like this setup
	}
}
template < typename DataType >
void List<DataType>::gotoEnd () throw ( logic_error )                          // Go to end -
{
	if(isEmpty ()== true)
	{
		throw ("Error: list is empty -- can't go to the end");
	}
	else
	{
		cursor =size-1; // I am not sure I like this setup
	}
}


template < typename DataType >
bool List<DataType>::gotoNext () throw ( logic_error )                         // Go to next data item - increment the cursor? but the cursor must be
{
	if(isFull ()== true)
	{
		//throw ("Error: list is full -- can't go to the end");
		return false;
	}
	else if (cursor+1 == size)
	{
		//throw ("Error: list has no next element");
		return false;
	}
	else
	{
		cursor++; // decrement the cursor
		return true;
	}
}
template < typename DataType >
bool List<DataType>::gotoPrior () throw ( logic_error )                       // Go to prior data item -
{
	if(isEmpty ()== true)
	{
		//throw ("Error: list is empty -- can't go to the beginning");
		return false;
	}
	else if (cursor == 0)
	{
		//throw ("Error: list has no prior element");
		return false;
	}
	else
	{
		cursor--; // decrement the cursor
		return true;
	}
}

template < typename DataType >
DataType List<DataType>::getCursor () const throw ( logic_error )     // Return data item
{
	if(isEmpty ())
	{
		throw ("Error: list is empty -- can't go return a data item");
	}
	else
	{
		return dataItems[cursor];
	}
}

// Output the list structure -- used in testing/debugging
template < typename DataType >
void List<DataType>::showStructure () const
{
	if(isEmpty ())
	{
		throw logic_error("Error: list is empty -- can't show structure");
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout<<dataItems[i]<<" "<<flush;
		}
	}
}

// In-lab operations
template < typename DataType >
void List<DataType>::moveToNth ( int n ) throw ( logic_error )                 // Move data item to pos. n
{
	/*
	this function takes the data at the current cursor position, removes it and copies it to Nth position. SO
	(1) copy data from the current cursor position to temp
	(2) delete teh current position data, shifting everything
	(3) move the data to Nth position
	 */
	if(size >=n+1)
	{
		DataType temp = this->getCursor(); // get existing data

		// now shift the data
		if(cursor < n)
		{
			for (int i = cursor; i<n; i++)
			{
				dataItems[i] = dataItems[i+1];
			}
		}
		else
		{
			for (int i = cursor; i>n; i--)
			{
				dataItems[i] = dataItems[i-1];
			}
		}

		dataItems[n] = temp;
	}
	else
	{
		throw ("Error: n is out of range");
	}

}

template < typename DataType >
bool List<DataType>::find ( const DataType& searchDataItem ) throw ( logic_error )     // Find data item
{
	int flag = -1;

	if(isEmpty () == true)
	{
		cout<< "find Error: list is empty -- can't search structure";

		return false;
	}
	else
	{
		for (int i = cursor; i < size; i++)
		{
			if(dataItems[i] == searchDataItem)
			{
				flag = i;
				break; //-- using break makes this find the first instance. without break it will give the last instance, if any.
			}
		}
		// cout<<"flag = "<<flag<<endl;

		if(flag != -1) // the value has been found.
		{
			cursor = flag; // this leaves the cursor either at the location of the Search Target or end of list
			return true;
		}

		else
		{
			cursor = size-1; // remember that indexing starts with 0;
			return false;
		}

	}
}


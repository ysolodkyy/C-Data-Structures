//--------------------------------------------------------------------
//
//  Laboratory 3                                           ListArray.h
//  **Instructor's Solution**
//  Class declaration for the array implementation of the List ADT
//
//--------------------------------------------------------------------

#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <iostream>


using namespace std;

template < typename DataType >
class List
{
public:

	static const int MAX_LIST_SIZE = 10;   // Default maximum list size -- using static const allows to initialize the value inside the class

	// Constructors
	List ( int maxNumber = MAX_LIST_SIZE )	// Default constructor
	// this creates an empty array with allocated memory
	{
		maxSize = maxNumber;
		size = 0;
		cursor = -1;
		dataItems =  new DataType[maxSize]; // assign memory on the stack.

	}
	List ( const List& source )		// Copy constructor
	{
		//note we don't use '->' for source because it is passed by reference, so no dereferencing needed

		this->maxSize = source.maxSize; // make sure the arrays are the same capacity
		this->size = source.size;             // Actual number of data item in the list
		this->cursor = -1;

		// start copying
		dataItems =  new DataType[source.size]; // assign memory first

		// now do the copying -- there is no escaping the actual copying as we d'nt want to reference anything -- this is known as deep copy

		for (cursor = 0; cursor < source.size; cursor++) // copy the data using the pointer as an array
		{
			this->dataItems[cursor] = source.dataItems[cursor]; // HERE I NEED TO PAY ATTENTION TO THE ORDER IN WHICH I increment the cursor
		}
	}
	// Overloaded assignment operator
	List& operator= ( const List& source )
	{
		// I don't need to delete anything because all arrays are of fixed size!
		// so I don't need to reallocate anything either.

		this -> size = source.size;
		this -> cursor = -1;
		// now copy: // again we want a deep copy in this case, I think;

		for (this -> cursor = 0; this -> cursor < this->size; (this ->cursor)++) // copy the data using the pointer as an array
		{
			this->dataItems[this -> cursor] = source.dataItems[this -> cursor]; // HERE I NEED TO PAY ATTENTION TO THE ORDER IN WHICH I increment the cursor
		}

		return *this; // because the object is actually a variable rather than an address, we need to dereference the "this" pointer.

	}

	// Destructor
	virtual ~List ();
	// List manipulation operations
	virtual void insert ( const DataType& newDataItem ) throw ( logic_error ); // Insert after cursor

	void remove () throw ( logic_error );        // Remove data item

	virtual void replace ( const DataType& newDataItem ) throw ( logic_error );// Replace data item

	void clear ();                               // Clear list

	// List status operations
	bool isEmpty () const;                    // List is empty
	bool isFull () const;                     // List is full

	// List iteration operations
	void gotoBeginning ()   throw ( logic_error );                   // Go to beginning

	void gotoEnd ()    throw ( logic_error );                        // Go to end

	bool gotoNext ()  throw ( logic_error );                        // Go to next data item
	bool gotoPrior () throw ( logic_error );  // Go to prior data item

	DataType getCursor () const throw ( logic_error );   // Return data item

	// Output the list structure -- used in testing/debugging
	virtual void showStructure () const;

	// In-lab operations
	void moveToNth ( int n )                  // Move data item to pos. n
	throw ( logic_error );
	bool find ( const DataType& searchDataItem )     // Find data item
	throw ( logic_error );


protected:

	// Data members
	int maxSize,
	size,             // Actual number of data item in the list
	cursor;           // Cursor array index
	DataType *dataItems;  // Array containing the list data item
};

#endif


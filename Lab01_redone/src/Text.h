//--------------------------------------------------------------------
//
//  Laboratory 1                                            Text.h
//
//  Class declaration for the array implementation of the Text ADT
//
//--------------------------------------------------------------------

#ifndef TEXT_H
#define TEXT_H

#include <stdexcept>
#include <iostream>
#include <cstring>

using namespace std;

class Text
{
public:

	// Constructors and operator=
	Text ( const char *charSeq = "" )              // Initialize using char*
{
		bufferSize = strlen(charSeq)+1;
		buffer = new char[bufferSize];

		for (int i = 0; i< bufferSize; i++)
		{
			buffer[i] = charSeq[i];
		}

}

	Text ( const Text &other )                      // Copy constructor
	{

		this -> bufferSize = other.bufferSize; // get the appropriate buffer size
		this -> buffer = new char[this->bufferSize];

		for (int i = 0; i< this->bufferSize; i++)
		{
			this->buffer[i] = other.buffer[i];
		}

	}



	void operator = ( const Text &other );           // Assignment

	// Destructor
	~Text ()
	{
		cout<<"\nobject destroyed"<<endl;
		delete [] buffer;
	}

	// Text operations
	int getLength () const;                          // # characters
	char operator [] ( int n ) const;                // Subscript
	void clear ();                                   // Clear string

	// Output the string structure -- used in testing/debugging
	void showStructure () const;

	//--------------------------------------------------------------------
	// In-lab operations
	// toUpper/toLower operations (Programming Exercise 2)
	Text toUpper( ) const;                           // Create upper-case copy
	Text toLower( ) const;                           // Create lower-case copy

	// Relational operations (Programming Exercise 3)
	bool operator == ( const Text& other ) const;
	bool operator <  ( const Text& other ) const;
	bool operator >  ( const Text& other ) const;

	//private:

	// Data members:

	int bufferSize;   // Size of the string buffer
	char *buffer;     // Text buffer containing a null-terminated sequence of characters


};

#endif


#include"Text.h"
#include <cstring>

// Member functions:


int Text::getLength () const                          // # characters
{

	// return the number of characters excluding the delimiter.
	int i = 0;

	while(*(buffer+i) !='\0')
	{
		i++;
	}

	return i;
}

char Text::operator [] ( int n ) const              // Subscript _ return buffer[n] for 0<n<length(), else return '\0'
{
	if(n <= getLength())
	{
		return buffer[n];
	}
	else
	{
		return '\0';
	}
}

void Text::clear ()                                   // Clear string
{
	delete [] buffer; // free the memory assigned to the buffer.
	bufferSize = 1;
	buffer = new char[bufferSize];

	*buffer = '\0'; // assign the null value to the only element in the array

}

// Output the string structure -- used in testing/debugging
void Text::showStructure () const
// this essentiallly the print() method
{
	for (int i = 0; i<bufferSize; i++)
	{

		cout<< *(buffer+i); // using pointer arithmetics to access buffer elements.
	}
}

//--------------------------------------------------------------------

void Text::operator = ( const Text &other )         // Assignment
{

	if (this != &other)
	{
		delete [] this->buffer; // free the memory allocated to this buffer.
		// allocate new memory of appropriate size

		this -> bufferSize = other.bufferSize;
		this->buffer = new char[this->bufferSize];

		// now copy the

		for (int i = 0; i< this->bufferSize; i++)
		{
			this->buffer[i] = other.buffer[i];
		}
	}
}

//--------------------------------------------------------------------
// In-lab operations
// toUpper/toLower operations (Programming Exercise 2)
Text Text::toUpper( ) const                           // Create upper-case copy
{
	char upper[bufferSize];


	for (int i = 0; i < bufferSize; i++)
	{
		if(buffer[i] >64 && buffer[i]< 91)
		{
			upper[i] = buffer[i];
		}
		else if(buffer[i] > 96 && buffer[i]< 123)
		{
			upper[i] = buffer[i]-32;
		}

		else
			upper[i] = buffer[i];
	}

	Text temp(upper);

	return temp;
}

Text Text::toLower( ) const                           // Create lower-case copy
{
	char upper[bufferSize];


	for (int i = 0; i < bufferSize; i++)
	{
		if(buffer[i] >64 && buffer[i]< 91)
		{
			upper[i] = buffer[i] + 32;
		}
		else if(buffer[i] > 96 && buffer[i]< 123)
		{
			upper[i] = buffer[i];
		}

		else
			upper[i] = buffer[i];
	}

	Text temp(upper);

	return temp;
}

// Relational operations (Programming Exercise 3)
bool Text::operator == ( const Text& other ) const
		{
	if(this->getLength() == other.getLength())
	{
		for (int i = 0; i < getLength(); i++)
		{
			if (this->buffer[i] != other.buffer[i] )
			{
				return false; // false if not all elements are the same
			}
		}
		return true; // must be true if all elements are the same
	}
	else
	{
		return false; // false if not the same size
	}
		}

bool Text::operator <  ( const Text& other ) const
{
	// they said it is ok to use a built in function for this

	int res = strcmp(this->buffer, other.buffer);

	if(res < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Text::operator >  ( const Text& other ) const
{
	int res = strcmp(this->buffer, other.buffer);

	if(res > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}



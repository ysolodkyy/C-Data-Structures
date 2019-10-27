//--------------------------------------------------------------------
//
//  Laboratory 3, In-lab Exercise 1                     test3dna.cpp
//
//  Test program for the countbases function
//
//--------------------------------------------------------------------

// Reads a DNA sequence from the keyboard, calls function countBases
// countBases (which uses a list to represent a DNA sequence), and
// outputs the number of times that each base (A, G, C and T) occurs
// in the sequence.

#include <iostream>
#include "ListArray.cpp"

using namespace std;

//--------------------------------------------------------------------
//
//  Function prototype


void countBases ( List<char> &dnaSequence,
		int &aCount,
		int &cCount,
		int &tCount,
		int &gCount              );

//--------------------------------------------------------------------


int main ()
{
	List<char> dnaSequence(25);   // DNA sequence (25 bases max.)
	char base;              // DNA base
	int aCount,             // Number of A's in the sequence
	cCount,             // Number of C's in the sequence
	tCount,             // Number of T's in the sequence
	gCount;             // Number of G's in the sequence

	// Read the DNA sequence from the keyboard.

	cout << endl << "Enter a DNA sequence: ";
	cin.get(base);
	while ( base != '\n' )
	{
		dnaSequence.insert(base);
		cin.get(base);
	}

	// Display the sequence.

	cout << "Sequence: ";

	if( dnaSequence.isEmpty() )
		cout << "list is empty" << endl;
	else
	{
		dnaSequence.gotoBeginning();
		do
		{
			cout << dnaSequence.getCursor() << " ";
		} while ( dnaSequence.gotoNext() );
		cout << endl;
	}

	// Count the number of times that each base occurs.

	countBases(dnaSequence,aCount,cCount,tCount,gCount);

	// Output the totals.

	cout << "Number of A's : " << aCount << endl;
	cout << "Number of C's : " << cCount << endl;
	cout << "Number of T's : " << tCount << endl;
	cout << "Number of G's : " << gCount << endl;

}

//--------------------------------------------------------------------
//=========================================

void countBases ( List<char> &dnaSequence,int &aCount,int &cCount,int &tCount,int &gCount)
{
	cout<<"inside the count bases function"<<endl;

	int baseCounts[4] = {0}; // this will store the counts of each base,initialized to 0;
	char bases[] = {'A', 'C', 'T','G'};

	for(int k = 0; k<4; k++)
	{
	dnaSequence.gotoBeginning(); // need to go to beginning because after insert() the cursor remains at the end

	while(dnaSequence.find(bases[k]))
	{
		baseCounts[k]++;
		if(!dnaSequence.gotoNext()) // increment the cursor inside the if() statement. if can't go next, we're at the end of the sequence, so
		{
			//  switch cursor to the beginning, and break
			dnaSequence.gotoBeginning();
			break;
		}
		}
	}
	aCount = baseCounts[0];             // Number of A's in the sequence
	cCount = baseCounts[1];             // Number of C's in the sequence
	tCount = baseCounts[2];             // Number of T's in the sequence
	gCount = baseCounts[3];             // Number of G's in the sequence

}



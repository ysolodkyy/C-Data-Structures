//--------------------------------------------------------------------
//
//  Laboratory 7, Programming Exercise 1                   storesim.cs
//
//  Program implementation shell.
//
//--------------------------------------------------------------------

// Simulates the flow of customers through a line in a store.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// Use which ever implementation is currently configured.
#if LAB7_TEST1
#   include "QueueLinked.cpp"
#else
#   include "QueueCircularArray.cpp"
#endif

using namespace std;

int main ()
{
#if LAB7_TEST1
	QueueLinked<int> custQ;      // Line (queue) of customers containing the
#else
	QueueArray<int> custQ;       // Line (queue) of customers containing the
#endif 				 //   time that each customer arrived and
	//   joined the line

	int simLength,               // Length of simulation (minutes)
	minute,                  // Current minute
	timeArrived,             // Time dequeued customer arrived
	waitTime,                // How long dequeued customer waited
	totalServed = 0,         // Total customers served
	totalWait   = 0,         // Total waiting time all customers combined
	maxWait     = 0,         // Longest wait
	numArrivals = 0;         // Number of new arrivals

	int totalArrivals = 0, wait = 0;

	// Seed the random number generator. Equally instructive to run the
	// simulation with the generator seeded and not seeded.
	srand( time(NULL) );

	cout << endl << "Enter the length of time to run the simulator : ";
	cin >> simLength;

	minute = 0;


	while(minute++ <= simLength)
	{
		numArrivals = rand() %3;

		cout<<"minute: "<<minute<< ". numArrivals = "<<numArrivals<<endl;
		if(numArrivals == 1)
		{
			custQ.enqueue(minute);
			totalArrivals = totalArrivals + 1;

		}
		else if(numArrivals == 2)
		{
			custQ.enqueue(minute);
			custQ.enqueue(minute);
			totalArrivals = totalArrivals + 2;
		}

		if(custQ.isEmpty()==false)
		{
			wait = minute - custQ.dequeue();
			if(maxWait < wait)
			{
				maxWait = wait;
			}
			totalWait = totalWait + wait;
			totalServed++;

		}
	}

	// Print out simulation results
	cout << endl;
	cout << "Customers arrived : " << totalArrivals << endl;
	cout << "Customers served : " << totalServed << endl;
	cout << "Average wait     : " << setprecision(2)
        				 << double(totalWait)/totalServed << endl;
	cout << "Longest wait     : " << maxWait << endl;

	return 0;
}

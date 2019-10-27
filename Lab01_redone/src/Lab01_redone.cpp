//============================================================================
// Name        : Lab01_redone.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include "Text.h"

using namespace std;

int main()
{
	//	cout << "!!!LAB 1 REDONE!!!" << endl; // prints !!!Hello World!!!
	//
	//	Text txt1, txt2("barber");
	//
	//	cout<<"\ntxt1.getLength(): "<<txt1.getLength()<<endl;
	//
	//	cout<<"\ntxt1.bufferSize: "<<txt1.bufferSize<<endl;
	//
	//
	//
	//	cout<<"\ntxt2.getLength(): "<<txt2.getLength()<<endl;
	//
	//	cout<<"\ntxt2.showStructure():"<<endl;
	//	txt2.showStructure();
	//
	//	// now use a copy constructor to create another constructor
	//
	//	Text txt3(txt2);
	//
	//	cout<<"\ntxt3.getLength(): "<<txt3.getLength()<<endl;
	//
	//	cout<<"\ntxt3.showStructure():"<<endl;
	//
	//	txt3.showStructure();
	//
	//	cout<<"clear the buffer: "<<endl;
	//
	//	txt2.clear();
	//
	//	cout<<"the buffer cleared "<<endl;
	//
	//	cout<<"\ntxt2.getLength(): "<<txt2.getLength()<<endl;
	//	cout<<"\ntxt2.showStructure():"<<endl;
	//	txt2.showStructure();
	//
	//	cout<<"\ntxt3.getLength(): "<<txt3.getLength()<<endl;
	//
	//	cout<<"\ntxt3.showStructure():"<<endl;
	//
	//	txt3.showStructure();
	//
	//	Text txt4("new text");
	//
	//	txt2 = txt4;
	//
	//	txt4.clear(); // this shouldn't affect txt2.
	//
	//	cout<<"\nafter equality txt2 = txt3;:"<<endl;
	//
	//	cout<<"\ntxt2.getLength(): "<<txt2.getLength()<<endl;
	//	cout<<"\ntxt2.showStructure():"<<endl;
	//	txt2.showStructure();
	//
	//	// test the subscript operator
	//
	//	cout<<"txt3[3]: "<<txt3[3]<<endl;
	//	cout<<"txt3[txt3.getLength()+7]: "<<txt3[txt3.getLength()+7]<<endl;
	//

	//char ch1 = 'A';
	//
	//char ch2 = 's';
	//
	//int num = ch2 - ch1;
	//
	//cout<<num<<endl;
	//
	// char ch3 = ch1 - num;
	//
	// cout<<ch3<<endl;
	//

	char arr[] = {'a','k', 'B', '9', 'm', 'z', 'O'};

	for (int i = 0; i < 4; i++)
	{
		if(arr[i] >64 && arr[i]< 91)
		{
			cout<<arr[i]<<"is capital"<<endl;
		}
		else if(arr[i] > 96 && arr[i]< 123)
		{
			cout<<arr[i]<<"is lower"<<endl;
		}

		else
			cout<<arr[i]<<"not a letter"<<endl;
	}


char upper[7];

// get to_uppers only
	for (int i = 0; i < 7; i++)
		{
			if(arr[i] >64 && arr[i]< 91)
			{
				upper[i] = arr[i]; // cout<<arr[i]<<"is capital"<<endl;
			}
			else if(arr[i] > 96 && arr[i]< 123)
			{
				upper[i] = arr[i]-32; // cout<<arr[i]<<"is lower"<<endl;
			}

			else
				upper[i] = arr[i];  // cout<<arr[i]<<"not a letter"<<endl;
		}

	cout<<"\n lowers: "<<arr<<endl;

	cout<<"\n uppers: "<<upper<<endl;

	Text tst("Nikita");

	tst.toUpper().showStructure();

	Text tst2("CHICAGO");

	tst2.toLower().showStructure();


	return 0;

}

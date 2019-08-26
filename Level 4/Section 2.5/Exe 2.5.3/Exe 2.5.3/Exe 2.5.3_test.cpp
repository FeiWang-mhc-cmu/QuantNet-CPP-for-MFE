//Fei - 2.5.3
//Test file for creating array class


#include "Array.hpp"
#include <iostream>
using namespace std;

void main()
{
	//Create a default array
	Array array;
	
	//Check whether the size is the default size of 10
	cout << "The default array size is "<< array.Size() << endl;

	//Print out each object of the array
	//Since only default constructor gets called, all the objects are (0,0)
	cout << "\nElements of the array are as followed:" << endl;

	for (int i=0; i<10; i++){
		cout << array[i] << endl;
	}
	


	//Ask the user for the size of the array
	cout << "\nPlease enter the size of the array: ";
	int n;
	cin >> n;		//read the input

	//Reset the array
	Array ar1(n);

	//Print out the array size again
	cout << "The array size of ar1 is "<< ar1.Size() << endl;

	//Print out each object of the array
	cout << "Elements of ar1 are as followed:" << endl;

	for (int i=0; i<n; i++){
		cout << ar1[i] << endl;
	}
	

	//Create a new array that copies the reset array
	Array ar2;
	ar2 = ar1;
	cout << "\nCreate ar2 that copies ar1" << endl;

	//Select an element to set
	cout << "\nPlease enter the ith index of ar2 to set as Point(7, 8): ";
	int i;
	cin >> i;

	//Set index i (i.e. i+1 element) of ar2 to a new Point (7,8)
	ar2.SetElement(i, Point(7,8));

	//Select an element to get
	cout << "\nPlease enter the jth index of the ar2 to get: ";
	int j;
	cin >> j;
	
	//Get index j (i.e. j+1 element) of ar2
	cout << "\nThe selected element of ar2 is " << ar2.GetElement(j) << endl;

	
	//Print out each object of ar2
	cout << "Elements of ar2 are as followed:" << endl;

	for (int i=0; i<n; i++){
		cout << ar2[i] << endl;
	}


	//Assign array to ar2
	array = ar2;
	cout << "\nNow assign array to ar2" << endl;

	//Set index 3 (i.e. 4th) element of array and print out
	array[3] = Point(3,4);
	cout << "\nThe third index of array now is " << array[3] << endl;

	//Create a constant Array ar3
	const Array ar3(8);
	cout << "\nNow create a constant Array ar3 with 8 elements" << endl;

	//ar3[3] = Point(3,4);		//result in error as we cannot set element for const type
	cout << "The fifth element of ar3 is " << ar3[5] << endl;		//but we can still get element

	
}

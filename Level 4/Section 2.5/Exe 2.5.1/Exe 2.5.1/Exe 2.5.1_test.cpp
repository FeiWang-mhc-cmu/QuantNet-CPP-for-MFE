//Fei - 2.5.1
//Test file for Dynamically creating objects


#include "Circle.hpp"
#include <iostream>
using namespace std;

void main()
{
	//default constructor is called
	Point* pt1 = new Point();

	//constructor with coordinates
	Point* pt2= new Point(1.5, 6.8);

	//copy constructor and assign
	Point* pt3 = new Point(*pt2);

	//print out three points
	cout << *pt1 << *pt2 << *pt3 << endl;

	//call Distance() function using dereference of pt2
	cout << (*pt2).Distance() << endl;			//distance with origin
	cout << (*pt2).Distance(*pt3) << endl;		//distance with pt3 (i.e. same as pt2) --> 0

	delete pt1;
	delete pt2;
	delete pt3;

	//ask the user for the size of the array
	cout << "Please enter the size of the array: ";
	int n;
	cin >> n;		//read the input

	//create an array using the entered size on the stack
	//will result in complier error as it does not have the size at compile time
	//int Array[n] = {}; 

	//create an array using the entered size on the heap
	Point * array;
	array = new Point[n];
	
	//print out each object of the array
	//since only default constructor gets called, all the objects are (0,0)
	for (int i=0; i<n; i++){
		cout << array[i] << endl;
	}

	//try using other constructor for the objects created in the array
	//it directly uses the parameter constructor
	//if we set the first object to be (3,4), for n>=2, the second to the last object should be (0,0)
	//it results in complier error as only default constructor can be called
	
	/*
	array = new Point[n]{Point(3,4)};  
	
	for (int i=0; i<n; i++){
		cout << array[i] << endl;
	}
	*/



	delete [] array;

}

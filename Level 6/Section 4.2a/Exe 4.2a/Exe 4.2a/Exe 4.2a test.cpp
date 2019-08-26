//Fei-exe 4.2a
//test file for templated array class

#include "Array.hpp"	
#include "ArrayException.hpp"
#include <iostream>
using namespace std;
#include <stdlib.h>

int main(){
	using namespace fayewang::Containers;
	using namespace fayewang::CAD;

	try
	{
	//Get an input for the size of array
	cout << "Please enter the size of the array of points: " << endl;
	int size;
	cin >> size;

	//Create an array of points
	Array<Point> points(size);

	//Set the nth index as Point(2,3)
	cout << "Please change the nth index of the array into Point(2,3): " << endl;
	int n;
	cin >> n;
	points.SetElement(n, Point(2,3));

	//Print out the nth index --> should be Point(2,3)
	cout << "The nth index of the array is " << points[n] << endl;

	//Print out the ith index
	//all points other than n should be Point(0,0)
	//if out of bound should return error message
	cout << "Please select the ith index of the array: " << endl;
	int i;
	cin >> i;
	cout << "The ith index of the array is " << points.GetElement(i) << endl;

	return 0;
	}


	catch(ArrayException& err)
	{
		//all out of bound from SetElement/GetElement/Index operator
		//should return the OOBE GetMessage() printout
		cout << err.GetMessage() << endl;
		
	}

	catch(...)
	{
		cout << "An unhandled exception has occured" << endl;
	}

}

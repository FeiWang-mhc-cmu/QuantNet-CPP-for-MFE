//Fei-exe 4.2b.3
//test file for point array (concrete inheritance)

#include "Array.hpp"	
#include "PointArray.hpp"
#include "ArrayException.hpp"
#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>

int main(){
	using namespace fayewang::Containers;
	using namespace fayewang::CAD;

	try{
	//create two default arrays of point type
	PointArray dar1;
	PointArray dar2;

	//default array should have size 10
	cout << dar1.Size() << endl;

	//test assignment operator --> no error
	dar1 = dar2;

	//create an array of size 3 with point type 
	PointArray ar(3);
	ar[0] = Point(1,2);
	ar[1] = Point(3,4);
	ar[2] = Point(5,6);

	//manually calculate the total length between points
	//length between the first two points
	double a = Point(1,2).Distance((Point(3,4)));
	//length between 2nd and 3rd points
	double b = Point(3,4).Distance((Point(5,6)));
	//total length
	double c = a+b;
	cout << c << endl;

	//test for length function
	cout << ar.Length() << endl;		//same answer!

	//test for length error situation
	//create an array of point type with one element
	PointArray ar1(1);
	cout << ar1.Length() << endl;		//error message displayed!

	}

	catch(int err)
	{
		if (err ==-1)
			cout << "Array size has to be two or more to calculate length!" << endl;
	}

	catch(...)
	{
		cout << "An unhandled exception has occured" << endl;
	}


}

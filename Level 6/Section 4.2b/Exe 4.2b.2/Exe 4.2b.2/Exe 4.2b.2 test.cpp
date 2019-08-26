//Fei-exe 4.2b.2
//test file for numeric array (generic inheritance)

#include "Array.hpp"	
#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>

int main(){
	using namespace fayewang::Containers;
	using namespace fayewang::CAD;

	try{
	//Create a numeric array with default settings
	NumericArray<int> ar1;

	//Set each element of ar1 by loop
	for (int i=0; i<ar1.Size(); i++)
		ar1.SetElement(i, i);
	
	//ar1 should be {0,1,2,3,4,5,6,7,8,9}
	for (int i=0; i<10; i++)
		cout << ar1.GetElement(i) << " ";
	
	cout << endl;

	//Test for scale operator
	NumericArray<int> ar2 = ar1*2;

	//ar2 should be {0,2,4,6,8,10,12,14,16,18}
	for (int i=0; i<ar2.Size(); i++)
		cout << ar2.GetElement(i) << " ";

	cout << endl;

	//Test for addition operator
	NumericArray<int> ar3 = ar1+ar2;

	//ar3 should be {0,3,6,9,12,15,18,21,24,27}
	for (int i=0; i<ar3.Size(); i++)
		cout << ar3.GetElement(i) << " ";

	cout << endl;

	//Test for error situation for addition operator
	NumericArray<int> ar4(15);
	//NumericArray<int> ar5 = ar1+ar4;		//error message displayed!

	//Test for dot product function
	//set two arrays of size 3
	NumericArray<int> ar5(3);
	ar5[0] = 1;
	ar5[1] = 2;
	ar5[2] = 3;

	NumericArray<int> ar6(3);
	ar6[0] = 4;
	ar6[1] = 5;
	ar6[2] = 6;
	
	//dot product should be (1*4+2*5+3*6=4+10+18=32)
	cout << "The dot product is " << ar5.DotProd(ar6) << endl;

	//Test for error situation for dot product
	//cout << ar5.DotProd(ar1) << endl;		//error message displayed!

	/*
	The assumptions we made about the type is that we only consider integer type.
	It should also work for other numeric types, such as double/long/float 
	Let's test whether it would work for Point objects
	The scale and addition operators should work as the ones in Point class, but not dot product
	*/

	//create an array of point type
	NumericArray<Point> ar7(2);
	ar7[0] = Point(1,2);
	ar7[1] = Point(3,4);

	//test for scale operator
	NumericArray<Point> ar8 = ar7*2;
	//ar8 becomes Point(2,4) and Point(6,8) -> the same as the scale operator in Point class
	for (int i=0; i<ar8.Size(); i++)
		cout << ar8.GetElement(i) << " ";

	cout << endl;

	//Test for addition operator
	NumericArray<Point> ar9 = ar7+ar8;

	//ar9 becomes Point(3, 6) Point(9, 12)
	for (int i=0; i<ar9.Size(); i++)
		cout << ar9.GetElement(i) << " ";

	cout << endl;

	//Test for doc product
	//dot product between two points won't work because there is no multiplication overloaded in Point class
	//it would only make sense if we want to treat the two points as vectors and want to find the directional growth of one vector to another 
	//cout << "The dot product is " << ar8.DotProd(ar9) << endl;

	}

	catch(ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}

	catch(...)
	{
		cout << "An unhandled exception has occured" << endl;
	}


}

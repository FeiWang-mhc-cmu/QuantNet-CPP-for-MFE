//Fei-exe 4.2b.1
//test file for static variable for array default size

#include "Array.hpp"	
#include "ArrayException.hpp"
#include <iostream>
using namespace std;
#include <stdlib.h>

int main(){
	using namespace fayewang::Containers;
	using namespace fayewang::CAD;

	//create two arrays of integer type
	Array<int> intArray1;
	Array<int> intArray2;
	
	//create an array of double type
	Array<double> doubleArray;
 
	//print out the default size of these arrays
	//all of them should be of d_size = 10
	cout<<intArray1.DefaultSize()<<endl;
	cout<<intArray2.DefaultSize()<<endl;
	cout<<doubleArray.DefaultSize()<<endl;
 
	//set the default size of integer array to 15 now
	//since default size is a static variable, it will be shared across all objects of this integer type
	intArray1.DefaultSize(15);
 
	cout<<intArray1.DefaultSize()<<endl;	//changed to 15
	cout<<intArray2.DefaultSize()<<endl;	//changed to 15
	cout<<doubleArray.DefaultSize()<<endl;	//stayed at 10 as it is a double type


}

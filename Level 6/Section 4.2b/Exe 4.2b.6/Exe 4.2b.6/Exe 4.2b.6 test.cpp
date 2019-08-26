//Fei-exe 4.2b.6
//test file for value template arguments


#include "Array.hpp"	
#include "Stack.hpp"
#include "ArrayException.hpp"
#include "StackException.hpp"
#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>

int main(){
	using namespace fayewang::Containers;
	using namespace fayewang::CAD;

	try{
	//create a stack with Point type
	Stack<Point, 10> sta0;

	//test for copy constructor --> no error for stacks of the same size
	Stack<Point, 10> sta1 = sta0;

	//test for assignment operator --> no error for stacks of the same size
	sta1 = sta0;

	//create another stack with diff size
	Stack<Point, 20> sta2;

	//test for copy and assignment operator
	//result in error!
	//sta1 = sta2;
	
	}

	catch(StackException& err)
	{
		cout << err.GetMessage() << endl;
	}

	catch(...)
	{
		cout << "An unhandled exception has occured" << endl;
	}


	
	
}

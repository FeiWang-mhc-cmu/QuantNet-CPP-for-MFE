//Fei-exe 4.2b.5
//test file for //layering exceptions


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
	//create a default stack with Point type
	Stack<Point> sta0;

	//test for copy constructor --> no error
	Stack<Point> sta1 = sta0;

	//test for assignment operator --> no error
	sta1 = sta0;

	//create a stack of size 2 with int type
	Stack<int> sta2(2); 
	
	//get current index --> default should be 0
	cout << sta2.GetCurrentIndex() << endl;

	//push two times will fill the stack
	sta2.Push(3);
	sta2.Push(5);

	//get current index --> should be increased to 2 now
	cout << sta2.GetCurrentIndex() << endl;

	//push again will lead to error "Index 2 is out of bound"
	//i.e. 3rd element is out of bound, m_current is not changed
	sta2.Push(8);
	
	}

	catch(StackException& err)
	{
		cout << err.GetMessage() << endl;
	}

	catch(...)
	{
		cout << "An unhandled exception has occured" << endl;
	}


	try{
	//create a stack of size 1 with Point type
	Stack<int> sta3(1); 
	
	//get current index --> should be 0
	cout << sta3.GetCurrentIndex() << endl;

	//push once to fill the stack
	sta3.Push(3);

	//get current index --> should be 1
	cout << sta3.GetCurrentIndex() << endl;

	//pop once to get 3
	cout << sta3.Pop() << endl;

	//get current index --> should be 0
	cout << sta3.GetCurrentIndex() << endl;

	//pop one more time to get error message
	//"index -1 is out of bound" (i.e. -1 is the input in GetElement(m_current-1))
	//but m_current will remain at 0
	cout << sta3.Pop() << endl;
	
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

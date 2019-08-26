//Fei-Exe 5.1.3
//Header file for Stackclass
//Boost libraries-Variant//Boost libraries-smart pointers

//use conditional compilation to make sure there is no multiple inclusion of the header file
#ifndef STACK_HPP
#define STACK_HPP

#include<iostream>
using namespace std;
#include<string>
#include<sstream>
#include "Point.hpp"
#include "Array.hpp"

namespace fayewang
{
	namespace Containers
	{
		template <typename T, int size> class Stack
		{
		private:
			Array<T> m_arr;					//data member of an Array
			int m_current;					//data member of current index

		public:
			//constructors
			Stack();									//default constructor
			Stack(const Stack<T, size>& sta);			//copy constructor

			//destructor
			virtual ~Stack();

			//assignment operator
			Stack<T, size>& operator = (const Stack<T, size>& source);

			//store element at the current position in the embedded array
			//increment the current position afterwards
			void Push(T input);

			//decrements the current position and then returns the element at that position
			T Pop();

			//get current index
			int GetCurrentIndex();
		};
	}

}



//cpp has to be included for template classes to work
//so by including cpp at the bottom of header file
//we ensure readability and code hiding as how we include header as usual

#ifndef Stack_CPP		// Must be the same name as in source file #define
#include "Stack.cpp"
#endif

#endif


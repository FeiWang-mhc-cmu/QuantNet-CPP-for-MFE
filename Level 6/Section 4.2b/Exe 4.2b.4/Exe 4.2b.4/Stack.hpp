//Fei-Exe 4.2b.4
//Header file for Stackclass
//stack class (composition)

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
		template <typename T> class Stack
		{
		private:
			Array<T> m_arr;			//data member of an Array
			int m_current;			//data member of current index
									//m_current == 0 means empty array

		public:
			//constructors
			Stack();							//default constructor
			Stack(int new_size);				//set constructor	
			Stack(const Stack<T>& sta);			//copy constructor

			//destructor
			virtual ~Stack();

			//assignment operator
			Stack<T>& operator = (const Stack<T>& source);

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


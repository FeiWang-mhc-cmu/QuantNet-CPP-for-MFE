//Fei-Exe 4.2a
//Header file for Array class
//templated array class

//use conditional compilation to make sure there is no multiple inclusion of the header file
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>
using namespace std;
#include<string>
#include<sstream>
#include "Point.hpp"

namespace fayewang
{
	namespace Containers
	{
		template <typename T> class Array
		{
		private:
			T* m_data;			//data member for a dynamic C array of T objects
			int m_size;			//data member for the size of the array

		public:
			//constructors
			Array();							//default constructor
			Array(int new_size);				//set constructor	
			Array(const Array<T>& arr);			//copy constructor

			//destructor
			virtual ~Array();

			//assignment operator
			Array<T>& operator = (const Array<T>& source);

			//size function
			int Size() const;

			//set an element
			void SetElement(int index, const T& pt);

			//get an element
			T& GetElement(int index) const;

			//square bracket operator
			T& operator[] (int index);

			//constant square bracket operator
			const T& operator[] (int index) const;
		};
	}

}

//cpp has to be included for template classes to work
//so by including cpp at the bottom of header file
//we ensure readability and code hiding as how we include header as usual

#ifndef Array_CPP		// Must be the same name as in source file #define
#include "Array.cpp"
#endif

#endif


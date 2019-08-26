//Fei- exe 4.2b.4
//Source file for NumericArray class derived from Array
//stack class (composition)

//use conditional compilation to make sure there is no multiple inclusion of the header file
#ifndef NumericARRAY_HPP
#define NumericARRAY_HPP

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
		template <typename T> class NumericArray: public Array<T>
		{
		public:
			//constructors
			NumericArray();							//default constructor
			NumericArray(int new_size);				//set constructor	
			NumericArray(const NumericArray<T>& arr);			//copy constructor

			//destructor
			virtual ~NumericArray();

			//assignment operator
			NumericArray<T>& operator = (const NumericArray<T>& source);

			//adding operators	
			NumericArray<T> operator * (double factor) const; // Scale the element by a factor
	
			NumericArray<T> operator + (const NumericArray<T>& narray) const; // Add two numeric arrays

			//calculate dot product
			T DotProd(NumericArray<T>& source); 
		};
	}

}

//cpp has to be included for template classes to work
//so by including cpp at the bottom of header file
//we ensure readability and code hiding as how we include header as usual

#ifndef NumericArray_CPP		// Must be the same name as in source file #define
#include "NumericArray.cpp"
#endif


#endif
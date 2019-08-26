//Fei- exe 5.1.3
//Source file for NumericArray class derived from Array
//Boost libraries-Variant

//use conditional compilation to make sure there is no multiple inclusion
#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "Array.hpp"
#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include<sstream>
#include <cmath>
#include<iostream>
using namespace std;

namespace fayewang
{
	namespace Containers
	{
		//Default constructor
		template <typename T>
		NumericArray<T>::NumericArray(): Array<T>() {}

		//Reset constructor
		template <typename T>
		NumericArray<T>::NumericArray(int new_size): Array<T>(new_size) {}

		//Copy constructor
		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& arr): Array<T>(arr) {}

		//Destructor
		template <typename T>
		NumericArray<T>::~NumericArray() {}
				
		//Assignment operator
		template <typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
		{
			// Avoid doing assign to myself
			if (this == &source)
				return *this;

			//assign the source to Array<T>
			Array<T>::operator = (source);
				return *this
		}

		
		// Scale the element by a factor
		template <typename T>
		NumericArray<T> NumericArray<T>::operator * (double factor) const
		{
			//get the size of array
			int size = Array<T>::Size();

			//initialize a new NumericArray object
			NumericArray<T> scaled(size);

			//scale each element of array by loop
			for (int i=0; i<size; i++)
			{
				scaled[i] = Array<T>::GetElement(i)*factor;
			}

			return scaled;
		}
		
		
		// Add two numeric arrays
		template <typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& narray) const
		{
			//get the size of arrays
			int size1 = Array<T>::Size();
			int size2 = narray.Size();

			//check if two arrays have the same size
			if (size1 != size2)
				throw NotSameSize();
			
			//initialize a new NumericArray object with the same size as LHS/RHS
			NumericArray<T> NewA(size1); 

			//summation by loop
			for (int i=0; i<size1; i++)
				NewA[i] = Array<T>::GetElement(i) + narray[i];

			return NewA;
		}

		
		//Calculate dot product
		template <typename T>
		T NumericArray<T>::DotProd(NumericArray<T>& source)
		{
			//intialize product to be 0
			T product = 0;

			//get the size of arrays
			int size1 = Array<T>::Size();
			int size2 = source.Size();

			//check if two arrays have the same size
			if (size1 != size2)
				throw NotSameSize();

			//add dot product by loop
			for (int i=0; i<size1; i++)
				product += Array<T>::GetElement(i) * source[i];

			return product;

		}
		
		

	}

}


#endif
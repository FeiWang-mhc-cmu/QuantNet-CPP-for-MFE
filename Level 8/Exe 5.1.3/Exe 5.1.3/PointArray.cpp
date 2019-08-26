//Fei- exe 5.1.3
//Source file for PointArray class derived from Array
//Boost libraries-Variant

//use conditional compilation to make sure there is no multiple inclusion
#ifndef PointArray_CPP
#define PointArray_CPP

#include "Array.hpp"
#include "PointArray.hpp"
#include "ArrayException.hpp"
#include<sstream>
#include <cmath>
#include<iostream>
using namespace std;

namespace fayewang
{
	namespace Containers
	{
		using namespace CAD;

		//Default constructor
		PointArray::PointArray(): Array<Point>() {}

		//Reset constructor
		PointArray::PointArray(int new_size): Array<Point>(new_size) {}

		//Copy constructor
		PointArray::PointArray(const PointArray& arr): Array<Point>(arr) {}

		//Destructor
		PointArray::~PointArray() {}
				
		//Assignment operator
		PointArray& PointArray::operator = (const PointArray& source)
		{
			// Avoid doing assign to myself
			if (this == &source)
				return *this;

			//assign the source to Array<Point>
			Array<Point>::operator = (source);
				return *this;
		}

		//function that returns the total length between the points in the array
		double PointArray::Length() const
		{
			//initialize length to be 0
			double len=0;

			//get the size of array
			int size = Array<Point>::Size();

			//size size has to be two or more
			if (size <=1)
				throw -1;

			//sum the distance between two points by loop
			for (int i=1; i<size; i++){
				//get the current point element
				Point A = Array<Point>::GetElement(i);
				
				//get the previous point element
				Point B = Array<Point>::GetElement(i-1);

				//sum the distances between points
				len += A.Distance(B);
			}

			return len;
		}

		
		

	}

}


#endif
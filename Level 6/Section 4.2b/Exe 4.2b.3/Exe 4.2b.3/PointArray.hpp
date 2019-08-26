//Fei- exe 4.2b.3
//Source file for PointArray class derived from Array
//point array (concrete inheritance)

//use conditional compilation to make sure there is no multiple inclusion of the header file
#ifndef PointARRAY_HPP
#define PointARRAY_HPP

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
		class PointArray: public Array<CAD::Point>
		{
		public:
			//constructors
			PointArray();							//default constructor
			PointArray(int new_size);				//set constructor	
			PointArray(const PointArray& arr);			//copy constructor

			//destructor
			virtual ~PointArray();

			//assignment operator
			PointArray& operator = (const PointArray& source);

			//function that returns the total length between the points in the array
			double Length() const;

		};
	}

}



#endif
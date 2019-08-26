//Fei-Exe 2.6.1
//Header file for Array class
//Namespace

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
		class Array
		{
		private:
			CAD::Point* m_data;		//data member for a dynamic C array of Point objects
			int m_size;			//data member for the size of the array

		public:
			//constructors
			Array();							//default constructor
			Array(int new_size);				//set constructor	
			Array(const Array& arr);			//copy constructor

			//destructor
			~Array();

			//assignment operator
			Array& operator = (const Array& source);

			//size function
			int Size() const;

			//set an element
			void SetElement(int index, const CAD::Point& pt);

			//get an element
			CAD::Point& GetElement(int index) const;

			//square bracket operator
			CAD::Point& operator[] (int index);

			//constant square bracket operator
			const CAD::Point& operator[] (int index) const;
		};
	}

}


#endif


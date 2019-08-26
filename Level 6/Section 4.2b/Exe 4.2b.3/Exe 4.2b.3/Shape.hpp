//Fei-exe 4.2b.3
//Header file for Shape base class
//point array (concrete inheritance)


#ifndef SHAPE_HPP
#define SHAPE_HPP

#include<iostream>
using namespace std;
#include<string>
#include<sstream>
#include<stdlib.h>

namespace fayewang
{
	namespace CAD
	{
		class Shape
		{
		private:
			int m_id;		//id number

		public:
			//default constructor, initializes id using a random number
			Shape();							
	
			//copy constructor, copies the id member
			Shape(const Shape& id);				
	
			//destructor
			virtual ~Shape();

			//assignment operator, copies the id member
			Shape& operator = (const Shape& source);

			//return string description
			virtual string ToString() const;

			//retrieve the id of the shape
			int ID() const;

			//print some text 
			virtual void Draw() const = 0;

			//call ToString() function and send the result to the cout object
			void Print() const; 
		};
	}
}

#endif
//Fei - 4.2b.3
//Create a composition Circle class based on Line and Point classes
//point array (concrete inheritance)

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Line.hpp"
#include <iostream>
using namespace std;

namespace fayewang
{
	namespace CAD
	{
		class Circle: public Shape
		{
		private:
		
			Point centerPt;	
			double m_radius;	

		public:

			// Constructors
			Circle();									// Circle with radius 0 and centers at origin
			Circle(const Point& p1, const double& r1);	// Circle with radius l1 and centers at p1
			Circle(const Circle& c); 					// Copy constructor

			// Destructor
			virtual ~Circle();							

			// Accesssing functions
			const Point& CenterPoint() const;							
			double Radius() const;								

			// Modifiers
			void CenterPoint(const Point& pt);			// Set center point
			void Radius(const double& r);				// Set radius

			//get diameter of the circle
			double Diameter() const;
	
			//get area of the circle
			double Area() const;

			//get circumference of the circle
			double Circumference() const;

			//return string description of the line
			string ToString() const;
 
			//assignment operator
			Circle& operator = (const Circle& source);

			//Send to ostream
			friend ostream& operator << (ostream& os, const Circle& c);

			//print some text 
			void Draw() const;
		};
	}

}


#endif



//Fei - 2.4.1
//Create a composition Circle class based on Line and Point classes
//adding operators


#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Line.hpp"
#include <iostream>
using namespace std;

class Circle
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
	~Circle();							

	// Accesssing functions
	const Point& CenterPoint() const;							
	double Radius() const;								

	// Modifiers
	void CenterPoint(const Point& pt);			// Set center point
	void Radius(const double& r);					// Set radius

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
};

#endif



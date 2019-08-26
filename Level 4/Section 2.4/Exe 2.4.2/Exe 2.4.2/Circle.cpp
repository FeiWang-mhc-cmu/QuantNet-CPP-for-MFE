//Fei - 2.4.2
//Implement the composition Circle class
//ostream operator

#define _USE_MATH_DEFINES
#include "Circle.hpp"
#include <iostream>
using namespace std;
#include <cmath>


//default constructor for a circle with radius of 0 and centers at origin
Circle::Circle()
{
	centerPt = Point();
	m_radius = 0;
}

//constructor with a circle with radius l1 and centers at p1
Circle::Circle(const Point& p1, const double& r1)
{
	centerPt = Point(p1);
	m_radius = r1;
}

//copy constructor of any circle c
Circle::Circle(const Circle& c)
{
	centerPt = c.CenterPoint();
	m_radius = c.Radius();
}
				
//destructor
Circle::~Circle(){}


//Getters
const Point& Circle::CenterPoint() const
{
	return centerPt;
}
double Circle::Radius() const
{
	return m_radius;
}

//Setters
void Circle::CenterPoint(const Point& pt)
{
	centerPt=pt;
}

void Circle::Radius(const double& r)
{
	m_radius=r;
}

//diameter of the circle
double Circle::Diameter() const
{
	return m_radius*2;
}

	
//area of the circle
double Circle::Area() const
{
	return M_PI*pow(m_radius, 2);
}


//circumference of the circle
double Circle::Circumference() const
{
	return 2*M_PI*m_radius;
}


//return string description of the line
string Circle::ToString() const 
{
		//declare output string stream 
		stringstream circle;	

		//set the display of circle output
		circle << "The circle is centered at " << centerPt.ToString() << " with radius of " << m_radius << endl;

		//return the string
		return circle.str();

	}

//assignment operator
Circle& Circle::operator = (const Circle& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	centerPt = source.centerPt;
	m_radius = source.m_radius;

	return *this;
}

//send to ostream
ostream& operator << (ostream& os, const Circle& c)
{
	os << c.ToString();
	return os;
}
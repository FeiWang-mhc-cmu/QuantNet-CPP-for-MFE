//Fei-exe 2.4.4
//Implement for constructors for the Point class
//freinds

#include "Point.hpp"
#include<sstream>
#include <cmath>
#include<iostream>
using namespace std;

//default constructor
Point::Point() : m_x(0), m_y(0) 
{
	//cout << "Default constructor is called" << endl;
}

//set newx and newy
Point::Point(double newx, double newy): m_x(newx), m_y(newy)
{
	//cout << "Reset constructor is called" << endl;
}

//make a copy constructor
Point::Point(const Point& p): m_x(p.m_x), m_y(p.m_y)
{
	//cout << "Copy constructor is called" << endl;
}

//conversion operator
Point::Point(double n): m_x(n), m_y(n) {}

//destructor
Point::~Point(){
	//cout << "Desctructor is called" << endl;
}

//Selectors
//access the x value
double Point::X() const {
	return m_x;
}
//access the y value
double Point::Y() const {
	return m_y;
}

//Modifiers
//set the x value
void Point::X(double newx){
	m_x = newx;
}
//set the y value
void Point::Y(double newy){
	m_y = newy;
}

//string description of the point
string Point::ToString() const {
		//declare output string stream pt
		std::stringstream pt;	

		//set the display of point output
		pt << "Point(" << m_x << ", " << m_y << ")";

		//return the string
		return pt.str();

	}

//calculate the dist to the origin (0,0)
double Point::Distance() const {
	//create a variable to denote distance between two points
	double dist=0;

	//based on Pythagoras theorem, distance to the origin is just the square root of
	//sum of squares of x and y coordiates
	dist = sqrt(pow((m_x-0), 2.0) + pow((m_y-0), 2.0));
	return dist;
}

//calculate the distance between two points
double Point::Distance(const Point& p) const {	
	//create variables to calculate the difference between coordinate values of two points
	double disx, disy, dist;
	disx = m_x - p.m_x;
	disy = m_y - p.m_y;

	//based on Pythagoras theorem, distance btw two points is the square root of
	//sum of squares of x and y coordiate differences
	dist = sqrt(pow(disx, 2.0) + pow(disy, 2.0));
	return dist;
}


// Negate the coordinates.
Point Point::operator - () const
{
	return Point(-m_x, -m_y);
} 

// Scale the coordinates.
Point Point::operator * (double factor) const
{
	return Point(m_x*factor, m_y*factor);
}
	
// Add coordinates.
Point Point::operator + (const Point& p) const
{
	return Point(m_x+p.m_x, m_y+p.m_y);
}
				
// Equally compare operator.
bool Point::operator == (const Point& p) const
{
	if (m_x == p.m_x && m_y == p.m_y)
		return 1;
	else
		return 0;
}

// Assignment operator.
Point& Point::operator = (const Point& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	m_x = source.m_x;
	m_y = source.m_y;

	return *this;
}


// Scale the coordinates & assign.
Point& Point::operator *= (double factor)
{
	Point temp = (*this)*factor;
	*this = temp;

	return *this;
}

//send to ostream
//friend function that can access the private of Point class
ostream& operator << (ostream& os, const Point& p)
{
	os << "Point(" << p.m_x << ", " << p.m_y << ")" << endl;
	return os;
}




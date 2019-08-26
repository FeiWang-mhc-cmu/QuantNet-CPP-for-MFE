//Fei-exe 4.2b.6
//Implement for constructors for the Point class
//value template arguments


#include "Point.hpp"
#include<sstream>
#include <cmath>
#include<iostream>
using namespace std;

namespace fayewang
{
	namespace CAD
	{
		//default constructor
		Point::Point(): Shape(), m_x(0), m_y(0)
		{
			//cout << "Default point constructor is called" << endl;
		}

		//set newx and newy
		Point::Point(double newx, double newy): Shape(), m_x(newx), m_y(newy)
		{
			//cout << "Reset point constructor is called" << endl;
		}

		//make a copy constructor
		Point::Point(const Point& p): Shape(p), m_x(p.m_x), m_y(p.m_y)
		{
			//cout << "Point copy constructor is called" << endl;
		}

		//conversion operator
		Point::Point(double n): Shape(), m_x(n), m_y(n) {
			//cout << "Point conversion constructor is called" << endl;
		}

		//destructor
		Point::~Point(){
			//cout << "Point desctructor is called" << endl;
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
		std::string Point::ToString() const {
				//cout << "Point ToString() is called." << endl;
			
				//declare output string stream pt
				std::stringstream pt;

				//call the string description of Shape class
				std::string s = Shape::ToString();

				//set the display of point output with Shape description
				pt << "Point(" << m_x << ", " << m_y << ") (" << s << ")";

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
			return (m_x == p.m_x && m_y == p.m_y);
		}

		// Assignment operator.
		Point& Point::operator = (const Point& source)
		{
			// Avoid doing assign to myself
			if (this == &source)
				return *this;

			Shape::operator = (source);

			m_x = source.m_x;
			m_y = source.m_y;

			//cout << "Point assignment operator is called." << endl;

			return *this;
		}


		// Scale the coordinates & assign.
		Point& Point::operator *= (double factor)
		{
			m_x *= factor;
			m_y *= factor;

			return *this;
		}

		//send to ostream
		//friend function that can access the private of Point class
		ostream& operator << (ostream& os, const Point& p)
		{
			os << "Point(" << p.m_x << ", " << p.m_y << ")";
			return os;
		}

		//print some text 
		void Point::Draw() const {	
			cout << "Point Draw() is called" << endl;
		}
	}
}


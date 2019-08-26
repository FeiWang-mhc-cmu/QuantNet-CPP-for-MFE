//Fei-Exe 2.4.3
//Header file for Point class
//conversion operator

//use conditional compilation to make sure there is no multiple inclusion of the header file
#ifndef POINT_HPP
#define POINT_HPP

#include<iostream>
using namespace std;
#include<string>
#include<sstream>

class Point
{
//data members not accessible to clients
private:
	double m_x;		//X value of point
	double m_y;		//Y value of point

//member functions accessible to clients
public:
	//constructors
	Point();							//default constructor
	Point(double newx, double newy);	//set constructor	
	Point(const Point& pt);				//copy constructor
	
	//conversion constructor
	//Point(double n);					//without explicit
	explicit Point(double n);			//declare explicit constructor

	//destructor
	~Point();

	//selectors
	double X() const;					// The x-coordinate
	double Y() const;					// The y-coordinate

	//modifiers
	void X(double newX);			// The x-coordinate
	void Y(double newY);			// The y-coordinate


	//return string description
	string ToString() const;

	//calculate the distance to the origin (0,0)
	double Distance() const;

	//calculate the distance between two points
	double Distance(const Point& p) const;


	//adding operators
	Point operator - () const; // Negate the coordinates.
	
	Point operator * (double factor) const; // Scale the coordinates.
	
	Point operator + (const Point& p) const; // Add coordinates.
	
	bool operator == (const Point& p) const; // Equally compare operator.

	Point& operator = (const Point& source); // Assignment operator.

	Point& operator *= (double factor); // Scale the coordinates & assign.


};


#endif

//Send to ostream
ostream& operator << (ostream& os, const Point& p);
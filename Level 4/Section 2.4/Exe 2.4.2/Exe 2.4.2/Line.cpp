//Fei - 2.4.2
//Implement the composition Line class based on two Point objects
//ostream operators


#include "Line.hpp"
#include <iostream>
using namespace std;
#include <cmath>

//default constructor with both points at origin
Line::Line(): startPoint(0,0), endPoint(0,0)
{
	//cout << "default line constructor is called\n" << endl;
}

//constructor with a start- and end- point
Line::Line(const Point& p1, const Point& p2): 
	startPoint(p1), endPoint(p2)
{
	//cout << "reset line constructor is called\n" << endl;
}

//copy constructor of any line l
Line::Line(const Line& l):
	startPoint(l.startPoint), endPoint(l.endPoint)
{
	//cout << "copy line constructor is called\n" << endl;
}
				
//destructor
Line::~Line()
{
	//cout << "line destructor is called\n" << endl;
}


//Getters
const Point& Line::start() const
{
	return startPoint;
}
const Point& Line::end() const
{
	return endPoint;
}

//Setters
void Line::start(const Point& pt)
{
	startPoint=pt;
}

void Line::end(const Point& pt)
{
	endPoint=pt;
}


//return string description of the line
string Line::ToString() const 
{
		//declare output string stream line
		stringstream l;	

		//set the display of line output
		l << "A line formed between " << startPoint.ToString() << " and " << endPoint.ToString() << endl;

		//return the string
		return l.str();

	}

//length of the line
double Line::Length() const
{
	return startPoint.Distance(endPoint);
}


//assignment operator
Line& Line::operator = (const Line& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	startPoint = source.startPoint;
	endPoint = source.endPoint;

	return *this;
}

//send to ostream
ostream& operator << (ostream& os, const Line& l)
{
	os << l.ToString();
	return os;
}
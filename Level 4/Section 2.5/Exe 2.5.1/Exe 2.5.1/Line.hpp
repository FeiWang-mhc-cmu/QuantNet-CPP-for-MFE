//Fei - 2.5.1
//Create a composition Line class based on two Point objects
//Dynamically creating objects


#ifndef Line_HPP
#define Line_HPP

#include "Point.hpp"
#include <iostream>
using namespace std;

class Line 
{
private:
		
		Point startPoint;	
		Point endPoint;	

public:

	// Constructors
	Line();									// Line with both end Points at the origin
	Line(const Point& p1, const Point& p2);	// Line with end Points [p1, p2]
	Line(const Line& l); 					// Copy constructor

	// Destructor
	~Line();							

	// Accesssing functions
	const Point& start() const;							
	const Point& end() const;								

	// Modifiers
	void start(const Point& pt);			// Set Point pt1
	void end(const Point& pt);				// Set Point pt2

	//return string description of the line
	string ToString() const;

	//returns the length of the line
	double Length() const; 

	//assignment operator
	Line& operator = (const Line& source);

	//send to ostream
	//friend function
	friend ostream& operator << (ostream& os, const Line& l);
};

#endif



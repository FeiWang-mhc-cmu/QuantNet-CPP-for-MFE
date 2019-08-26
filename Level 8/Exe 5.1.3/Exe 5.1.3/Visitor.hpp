//Fei - exe 5.1.3
//Source file for Visitor for Shape types
//Boost libraries - Variant

#ifndef VISITOR_HPP
#define VISITOR_HPP

#include <boost/variant/static_visitor.hpp>
#include "Circle.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace fayewang::CAD;


class Visitor: public boost::static_visitor<void>
{
private:
	double m_dx;	//x-coordinate
	double m_dy;	//y-coordinate

public:
	//Sefault constructor
	Visitor();

	//Set constructor
	Visitor(double newX, double newY);

	//Copy constructor
	Visitor(const Visitor& source);

	//Destructor 
	~Visitor();

	//Assignment operator
	Visitor& operator = (const Visitor& source);

	//Visit a point
	void operator() (Point& p) const;

	//Visit a Line
	void operator() (Line& l) const;

	//Visit a Circle
	void operator() (Circle& c) const;


}
;

#endif
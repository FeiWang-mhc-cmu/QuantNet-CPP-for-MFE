//Fei - exe 5.1.3
//Source file for Visitor for Shape types
//Boost libraries - Variant

#ifndef VISITOR_CPP
#define VISITOR_CPP

#include "Visitor.hpp"

//Sefault constructor
Visitor::Visitor(): m_dx(0), m_dy(0) {}

//Set constructor
Visitor::Visitor(double newX, double newY):
	m_dx(newX), m_dy(newY) {}

//Copy constructor
Visitor::Visitor(const Visitor& source)
{
	m_dx = source.m_dx;
	m_dy = source.m_dy;
}

//Destructor 
Visitor::~Visitor(){}

//Assignment operator
Visitor& Visitor::operator = (const Visitor& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	Visitor::operator=(source);

	m_dx = source.m_dx;
	m_dy = source.m_dy;

	return *this;
}


//Visit a point
void Visitor::operator() (Point& p) const
{
	p.X(p.X()+m_dx);
	p.Y(p.Y()+m_dy);
}


//Visit a Line
void Visitor::operator() (Line& l) const
{
	//Change the start point
	Point startpt = l.start();
	startpt.X(startpt.X()+m_dx);
	startpt.Y(startpt.Y()+m_dy);
	l.start(startpt);

	//Change the end point
	Point endpt = l.end();
	endpt.X(endpt.X()+m_dx);
	endpt.Y(endpt.Y()+m_dy);
	l.end(endpt);
}

//Visit a Circle
void Visitor::operator() (Circle& c) const
{
	//Change the center point
	Point ctpt = c.CenterPoint();
	ctpt.X(ctpt.X()+m_dx);
	ctpt.Y(ctpt.Y()+m_dy);
	c.CenterPoint(ctpt);

	//Change radius
	c.Radius(m_dx);

}


#endif
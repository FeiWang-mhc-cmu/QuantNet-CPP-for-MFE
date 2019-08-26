//Fei - 4.2b.3
//Implement the composition Line class based on two Point objects
//point array (concrete inheritance)

#include "Line.hpp"
#include <iostream>
using namespace std;
#include <cmath>

namespace fayewang
{
	namespace CAD
	{
		//default constructor with both points at origin
		Line::Line(): Shape(), startPoint(0,0), endPoint(0,0)
		{
			//cout << "default line constructor is called\n" << endl;
		}

		//constructor with a start- and end- point
		Line::Line(const Point& p1, const Point& p2): 
			Shape(), startPoint(p1), endPoint(p2)
		{
			//cout << "reset line constructor is called\n" << endl;
		}

		//copy constructor of any line l
		Line::Line(const Line& l):
			Shape(l), startPoint(l.startPoint), endPoint(l.endPoint)
		{
			//cout << "copy line constructor is called\n" << endl;
		}
				
		//destructor
		Line::~Line()
		{
			//cout << "Line destructor is called\n" << endl;
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
				//cout << "Line ToString() is called." << endl;	

				//declare output string stream line
				stringstream l;	

				//call the string description of Shape class
				std::string s = Shape::ToString();

				//set the display of line output with Shape description
				l << "A line (" << s << ") formed between " << startPoint.ToString() << " and " << endPoint.ToString() << endl;

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

			Shape::operator= (source);

			startPoint = source.startPoint;
			endPoint = source.endPoint;

			cout << "line assignment operator is called." << endl;

			return *this;
		}

		//send to ostream
		//friend function that can access the private of Line class
		ostream& operator << (ostream& os, const Line& l)
		{
			os << "A line formed between " << l.startPoint << " and " << l.endPoint << endl;

			return os;
		}

		//print some text 
		void Line::Draw() const {	
			cout << "Line Draw() is called" << endl;
		}
	}

}


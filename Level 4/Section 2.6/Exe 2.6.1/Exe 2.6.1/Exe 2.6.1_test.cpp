//Fei - 2.6.1
//Test file for Namespace


#include "Array.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

void main()
{
	//full namespace for Point class
	fayewang::CAD::Point pt(3,4);
	cout << pt << endl;		//test
	
	//using declaration for using a single class(Line)
	using fayewang::CAD::Line;
	Line l;
	cout << l << endl;		//test

	//using derective for a complete namespace(Containers)
	using namespace fayewang::Containers;
	
	//using the Circle class by creating a alias
	namespace fCAD = fayewang::CAD;
	fCAD::Circle c;
	cout << c << endl;		//test
}

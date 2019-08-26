//Fei - 2.4.4
//test file for freind function

#include "Circle.hpp"
#include <iostream>
using namespace std;

void main()
{
	//create a new point, line and circle
	Point p(3.0, 8.0);
	Line l(p, Point());
	Circle c(p, 6.5);


	//p, l, and c can be printed out directly through friend functions
	cout << p << endl;
	cout << l << endl;
	cout << c << endl;

}
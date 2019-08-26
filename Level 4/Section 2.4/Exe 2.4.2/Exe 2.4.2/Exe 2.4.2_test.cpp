//Fei - 2.4.2
//Test file for Point/Line/Circle class
//ostream << operator

#include "Circle.hpp"
#include <iostream>
using namespace std;

void main()
{
	//create a point, a line, and a circle
	Point p1(18,9);
	Line l1(p1, Point());
	Circle c1(p1, 5);

	//test ostream << operator
	cout << p1 << endl;		//should print out p1 (18, 9)
	cout << l1 << endl;		//should print out l1 btw Point(18,9) snd (0,0)
	cout << c1 << endl;		//should print out c1 centered at Point(18,9) with radius 5

}
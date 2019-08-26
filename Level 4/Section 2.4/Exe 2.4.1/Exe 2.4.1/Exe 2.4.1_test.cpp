//Fei - 2.4.1
//Test file for Point/Line/Circle class
//adding operators 

#include "Circle.hpp"
#include <iostream>
using namespace std;

void main()
{
	//create two points
	Point p1(6,3);
	Point p2(1,3);

	//negate the coordinates
	Point p3 = -p1;		//p3 should be (-6,-3)
	cout << p3.ToString() << endl;

	//scale the coordinates
	Point p4 = p2*5;		//p4 should be (1*5, 3*5)=(5,15)
	cout << p4.ToString() << endl;

	//add coordinates
	Point p5 = p3+p4;		//p5 should be (-6+5, -3+15)=(-1,12) 
	cout << p5.ToString() << endl;

	//test equivalence operator; true return 1, false return 0
	//p1 and p2 are not equivalent so it should return 0
	cout << "Are " << p1.ToString() << " and " << p2.ToString() << " equal?: " << (p1==p2) << endl;
	
	Point p6(1,3);		//create a new point that has the same coordinates of p2, it should return 1
	cout << "Are " << p2.ToString() << " and " << p6.ToString() << " equal?: " << (p2==p6) << endl;

	//assignment operator
	p2 = p3;		//p2 should be the same as p3 --> (-6,-3)
	cout << p2.ToString() << endl;

	//scale and assing 
	p1 *= 3;		//p1 should be (6*3, 3*3)=(18, 9)
	cout << p1.ToString() << endl;

	
	
	//create two lines
	Line l1(p1, p2);
	Line l2(p5, p6);
	
	//print out l1 and l2
	cout << l1.ToString() << endl;
	cout << l2.ToString() << endl;

	//assingment operator for line
	l2 = l1;
	cout << l2.ToString() << endl;		//l2 should be the same as l1



	//create two circles
	Circle c1(p1, 3);
	Circle c2(p5, 7);
	
	//print out c1 and c2
	cout << c1.ToString() << endl;
	cout << c2.ToString() << endl;

	//assingment operator for line
	c2 = c1;
	cout << c2.ToString() << endl;		//c2 should be the same as c1

}
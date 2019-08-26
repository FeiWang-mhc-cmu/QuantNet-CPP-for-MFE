//Fei - 2.4.3
//Constructors as conversion operator

#include "Point.hpp"
#include <iostream>
using namespace std;

void main()
{
	//create a new point
	Point p(1.0, 1.0);

	/*
	//conversion constructor used implicitly
	//Point(double n) implicitly coverts 1.0 into a temporary Point object (1.0,1.0)
	//since p == (1.0, 1.0), return Equal!
	
	if (p == 1.0) cout<<"Equal!"<<endl;
	else cout<<"Not equal"<<endl;

	//conversion constructor used explicitly
	//since p is a Point object and 1.0 is a double, they have different operand types
	//results in a complier error
	
	if (p == 1.0) cout<<"Equal!"<<endl;
	else cout<<"Not equal"<<endl;
	*/


	//(Point)1.0 is used explicitly as a cast of 1.0 to Point, i.e. (1.0, 1.0)
	Point pt1 = (Point)1.0;
	cout << "pt1 is " << pt1 << endl;
	
	//should return Equal!
	if (p == pt1) cout<<"Equal!"<<endl;
	else cout<<"Not equal"<<endl;

	
	//Point(1.0) creates a new point of (1.0, 1.0)
	Point pt2 = Point(1.0);
	cout << "pt2 is " << pt1 << endl;
	
	//should return Equal!
	if (p == pt2) cout<<"Equal!"<<endl;
	else cout<<"Not equal"<<endl;


	//The explicit operator parameter number changed to 5.0, should return Not equal
	if (p == (Point)5.0) cout<<"Equal!"<<endl;
	else cout<<"Not equal"<<endl;
}

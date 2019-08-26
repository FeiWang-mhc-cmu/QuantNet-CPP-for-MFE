//Fei-exe 5.1.1
//test file for boost libraries-smart pointers

#include "Array.hpp"	
#include "Circle.hpp"
#include <iostream>
#include <string>
#include <boost\shared_ptr.hpp>

using namespace std;
using namespace fayewang::Containers;
using namespace fayewang::CAD;

// Typedef for a shared pointer to shape and
// a typedef for an array with shapes stored as shared pointers.
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

int main(){
	//Initialize different shapes
	ShapePtr pt(new Point(1,2));
	ShapePtr l(new Line(Point(3,4), Point(5,6)));
	ShapePtr cir(new Circle(Point(7,8), 9));

	//Print the counts of shapes
	cout << "Reference count of Point: " << pt.use_count() << endl;		//1
	cout << "Reference count of Line: " << l.use_count() << endl;		//1
	cout << "Reference count of Circle: " << cir.use_count() << endl;	//1

	cout << endl;

	//Start of the scope
	{
		//Create and initialize an ShapeArray object
		ShapeArray arr(6);

		//Fill the array with shapes created
		arr[0] = pt;
		arr[1] = pt;
		arr[2] = pt;
		arr[3] = l;
		arr[4] = l;
		arr[5] = cir;

		//Print the array
		for(int i=0; i<6; i++)
		{
			cout << arr[i] -> ToString() << endl; 
		}

		//Print the counts of shapes
		cout << "Reference count of Point: " << pt.use_count() << endl;		//1+3=4
		cout << "Reference count of Line: " << l.use_count() << endl;		//1+2=3
		cout << "Reference count of Circle: " << cir.use_count() << endl;	//1+1=2
	}//end of scope

	cout << endl;

	//Shapes should be automatically deleted when out of scope --> counts of shapes return to 1
	cout << "Reference count of Point: " << pt.use_count() << endl;			//1
	cout << "Reference count of Line: " << l.use_count() << endl;			//1
	cout << "Reference count of Circle: " << cir.use_count() << endl;		//1
	
	
}

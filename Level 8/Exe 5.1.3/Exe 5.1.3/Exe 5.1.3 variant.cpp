//Fei-exe 5.1.3
//test file for boost libraries-variant

#include "Circle.hpp"
#include "Visitor.hpp"
#include <iostream>
#include <string>
#include <boost/variant.hpp>

using namespace std;
using boost::variant;
using namespace fayewang::CAD;

//Typedef for a ShapeType variant
//contain a Point, Line, or Circle
typedef variant<Point, Line, Circle> ShapeType;


//Create a function that returns the variant
ShapeType ReturnVar()
{
	//Ask the user for Shape type
	cout << "Please select the Shape type to create (1. Point 2.Line 3.Circle): " << endl;
	int i;
	cin >> i;

	//Use switch to get the Shape type
	switch(i)
	{
	case 1: cout << "You choose a default Point" << endl;
		return Point(); break;
	case 2: cout << "You choose a default Line" << endl;
		return Line(); break;
	case 3: cout << "You choose a default Circle" << endl;
		return Circle(); break;
	default: cout << "Invalid input!" << endl;
		break;
	}


}


int main(){
	//Call the function that returns the variant and print the result
	ShapeType MyVar = ReturnVar();
	cout << MyVar << endl;

	//Test if the variant is a Line
	Line l;

	try
	{
		l = boost::get<Line>(MyVar);
	}

	catch(boost::bad_get& err)
	{
		//Print error message if it's not a Line
		//"Error: boost::bad_get: failed value get using boost::get"
		cout << "Error: " << err.what() << endl;		
	}

	catch(...)
	{
		cout << "An unhandled exception has occured" << endl;
	}

	cout << endl;

	//Create an instance of Visitor
	Visitor visitor(3,4);
	
	//Move the Shape
	boost::apply_visitor(visitor, MyVar);

	//Print the Shape to check if the visitor changes the coordinates
	//Should print "Point(3,4)" if choose Point (1)
	//Or "A line formed between Point(3, 4) and Point(3, 4)" if choose Line (2)
	//Or "The circle is centered at Point(3, 4) with radius of 3" if choose Circle (3)
	cout << "The Shape after move is: " << MyVar << endl;

}

//Fei-Exe 2.5.3
//Header file for Array class
//Creating array class

//use conditional compilation to make sure there is no multiple inclusion of the header file
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>
using namespace std;
#include<string>
#include<sstream>
#include "Point.hpp"

class Array
{
private:
	Point* m_data;		//data member for a dynamic C array of Point objects
	int m_size;			//data member for the size of the array

public:
	//constructors
	Array();							//default constructor
	Array(int new_size);				//set constructor	
	Array(const Array& arr);			//copy constructor

	//destructor
	~Array();

	//assignment operator
	Array& operator = (const Array& source);

	//size function
	int Size() const;

	//set an element
	void SetElement(int index, const Point& pt);

	//get an element
	Point& GetElement(int index) const;

	//square bracket operator
	Point& operator[] (int index);

	//constant square bracket operator
	const Point& operator[] (int index) const;
};


#endif


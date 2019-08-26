//Fei-exe 2.5.3
//Implement for constructors for the Array class
//Creating array class

#include "Array.hpp"
#include<sstream>
#include <cmath>
#include<iostream>
using namespace std;

//Default constructor
Array::Array()
{
	//cout << "Default constructor is called" << endl;
	m_size = 10;
	m_data = new Point[m_size];
}

//Reset constructor
Array::Array(int new_size)
{
	//cout << "Reset constructor is called" << endl;
	m_size = new_size;
	m_data = new Point[new_size];
}

//Copy constructor
Array::Array(const Array& arr)
{
	//cout << "Copy constructor is called" << endl;

	m_size = arr.m_size;
	m_data = new Point[arr.m_size];

	for (int i = 0; i< m_size; i++)
	{
		m_data[i] = arr.m_data[i];
	}
}

//Destructor
Array::~Array()
{
	//cout << "Deconstructor is called" << endl;
	delete [] m_data;
}
				
//Assignment operator
Array& Array::operator = (const Array& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	m_size = source.m_size;
	delete [] m_data;						//delete the old C array

	Point* new_data;
	new_data = new Point[source.m_size];	//allocate new memory 
	for (int i = 0; i < m_size; i++)
	{
		new_data[i] = source.m_data[i];
	}

	m_data = new_data;

	return *this;
}

//Return the size of the array
int Array::Size() const
{
	return m_size;
}

//Set an element 
void Array::SetElement(int index, const Point& pt)
{
	//check if out of bound
	if (index <= (m_size-1) && index >= 0)
	{
		m_data[index] = pt;
	}
}

//Get an element
Point& Array::GetElement(int index) const
{
	//check if out of bound
	if (index <= (m_size-1) && index >= 0)
	{
		return m_data[index];
	}
	else
	{
		cout << "Index out of bound! Return the first element." << endl;
		return m_data[0];
	}

}

//square bracket operator
//for non constant objects to set and get elements of array
Point& Array::operator[] (int index)
{
	//check if out of bound
	if (index <= (m_size-1) && index >= 0)
	{
		return m_data[index];
	}
	else
	{
		cout << "Index out of bound! Return the first element." << endl;
		return m_data[0];
	}
}

//constant square bracket operator
//const return type means that the return value should not be changed
//const function means that the private members of the class inside the function should not be changed
//i.e. this [] operator will be used by constant objects to only "get" elements of array
const Point& Array::operator[] (int index) const
{
	//check if out of bound
	if (index <= (m_size-1) && index >= 0)
	{
		return m_data[index];
	}
	else
	{
		cout << "Index out of bound! Return the first element." << endl;
		return m_data[0];
	}
}




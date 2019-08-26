//Fei-exe 4.2b.5
//Source file for Shape base class
//layering exceptions

#include "Shape.hpp"
#include<sstream>
#include <cmath>
#include<iostream>
using namespace std;
#include<cstdlib>


namespace fayewang
{
	namespace CAD
	{
		//default constructor, initializes id using a random number
		Shape::Shape(): m_id(rand()) {}							
	
		//copy constructor, copies the id member
		Shape::Shape(const Shape& id): m_id(id.m_id) {}

		//destructor
		Shape::~Shape() {
			//cout << "Shape destructor is called." << endl;
		}

		//assignment operator, copies the id member
		Shape& Shape::operator = (const Shape& source){
			// Avoid doing assign to myself
			if (this == &source)
				return *this;

			m_id = source.m_id;

			//cout << "Shape assignment operator is called." << endl;

			return *this;
		}


		//return string description
		std::string Shape::ToString() const {
				//cout << "Shape ToString() is called." << endl;

				//declare output string stream sp
				std::stringstream sp;	

				//set the display of point output
				sp << "ID: " << m_id;

				//return the string
				return sp.str();

			}

		//retrieve the id of the shape
		int Shape::ID() const {
			return m_id;
		}

		//call ToString() function and send the result to the cout object
		void Shape::Print() const {
			cout << ToString() << endl;
		}

	}
}
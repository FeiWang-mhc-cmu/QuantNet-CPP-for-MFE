//Fei-exe 4.2a
//ArrayException classes implementation file
//templated array class

#include "ArrayException.hpp"
#include<iostream>
using namespace std;
#include<string>
#include<sstream>

namespace fayewang
{
	namespace Containers
	{
		//OutofBoundException class

		//constructor that indicates the erroneous array index
		//and store it in a data member
		OutOfBoundsException::OutOfBoundsException(int index): m_index(index) {}

		//override GetMessage() function
		std::string OutOfBoundsException::GetMessage() {
			//declare output string stream s
			std::stringstream s;	

			//set the display of point output
			s << "Index " << m_index << " is out of bound";

			//return the string
			return s.str();
		}

	}
}


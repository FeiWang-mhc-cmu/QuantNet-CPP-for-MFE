//Fei-exe 5.1.1
//StackException classes implementation file
//Boost libraries-smart pointers

#include "StackException.hpp"
#include<iostream>
using namespace std;
#include<string>
#include<sstream>

namespace fayewang
{
	namespace Containers
	{
		//SFE override GetMessage() function
		std::string StackFullException::GetMessage() 
		{
			//declare output string stream s
			std::stringstream s;	

			//set the display of point output
			s << "Stack is full!";

			//return the string
			return s.str();
		}

	
		//SEE override GetMessage() function
		std::string StackEmptyException::GetMessage() 
		{
			//declare output string stream s
			std::stringstream s;	

			//set the display of point output
			s << "Stack is empty!";

			//return the string
			return s.str();
		}

	}
}


//Fei-exe 4.2b.6
//StackException classes implementation file
//value template arguments

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


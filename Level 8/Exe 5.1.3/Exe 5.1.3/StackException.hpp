//Fei-exe 5.1.3
//StackException classes header file
//Boost libraries-Variant

//use conditional compilation to make sure there is no multiple inclusion of the header file
#ifndef STACKEXCEPTION_HPP
#define STACKEXCEPTION_HPP

#include<iostream>
using namespace std;
#include<string>
#include<sstream>

namespace fayewang
{
	namespace Containers
	{
		class StackException 
		{
		public:
			//create an abstract GetMessage() function that returns a string
			virtual std::string GetMessage()=0; 
		};

		class StackFullException: public StackException
		{
		public:
			//override GetMessage() function
			std::string GetMessage();
		};

		class StackEmptyException: public StackException
		{
		public:
			//override GetMessage() function
			std::string GetMessage();
		};
	
	}
}


#endif
